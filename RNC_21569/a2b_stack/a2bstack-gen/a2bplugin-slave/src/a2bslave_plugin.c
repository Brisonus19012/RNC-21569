/*=============================================================================
 *
 * Project: a2bstack
 *
 * Copyright (c) 2015 - Analog Devices Inc. All Rights Reserved.
 * This software is subject to the terms and conditions of the license set 
 * forth in the project LICENSE file. Downloading, reproducing, distributing or 
 * otherwise using the software constitutes acceptance of the license. The 
 * software may not be used except as expressly authorized under the license.
 *
 *=============================================================================
 *
 * \file:   plugin.c
 * \author: Mentor Graphics, Embedded Software Division
 * \brief:  The implementation of a simple A2B stack slave plugin.
 *
 *=============================================================================
 */

/*======================= I N C L U D E S =========================*/

#include "a2bplugin-slave/inc/a2bplugin-slave/plugin.h"
#include "plugin_priv.h"
#include "a2bstack/inc/a2b/pluginapi.h"
#include "a2bstack/inc/a2b/error.h"
#include "platform/a2b/conf.h"
#include "a2bstack/inc/a2b/defs.h"
#include "a2bstack/inc/a2b/util.h"
#include "a2bstack/inc/a2b/msg.h"
#include "a2bstack/inc/a2b/msgrtr.h"
#include "a2bstack/inc/a2b/trace.h"
#include "a2bstack/inc/a2b/interrupt.h"
#include "a2bstack/inc/a2b/i2c.h"
#include "a2bstack/inc/a2b/timer.h"
#include "a2bstack/inc/a2b/regdefs.h"
#include "a2bstack/inc/a2b/seqchart.h"
#include "verinfo.h"


/*======================= D E F I N E S ===========================*/

/* The amount of time (msec) used to simulate the time it would
 * take to initialize or de-initialize an attached peripheral.
 */
#define A2B_SLAVE_SIMULATED_DELAY   			(1000u)


/* Define the vendor identifier stored in the unit test's BDD */
#define A2B_UTEST_BDD_SLAVE_NODE_VENDOR_ID		(0xADu)


/*======================= L O C A L  P R O T O T Y P E S  =========*/
static a2b_Plugin* a2b_pluginFind(a2b_Handle  hnd);
static void a2b_onSimulatedPeriphAccess(struct a2b_Timer* timer,
    a2b_Handle          userData);
static void a2b_onDtcMsgFree(struct a2b_Msg* msg);
static void a2b_emitSlaveDtc(a2b_Plugin* plugin,
    a2b_UInt8   intrSrc, a2b_UInt8   intrType);
static a2b_Handle a2b_pluginOpen(struct a2b_StackContext* ctx,
    const a2b_NodeSignature*   nodeSig);
static a2b_HResult a2b_pluginClose(a2b_Handle  hnd);
static a2b_Int32 a2b_pluginExecute(struct a2b_Msg*  msg,
    a2b_Handle  pluginHnd, struct a2b_StackContext*  ctx);
static void a2b_pluginInterrupt(struct a2b_StackContext*  ctx,
a2b_Handle  hnd, a2b_UInt8  intrSrc, a2b_UInt8  intrType);

/*======================= D A T A  ================================*/

static a2b_Plugin gsPlugins[A2B_CONF_MAX_NUM_SLAVE_NODES * A2B_CONF_MAX_NUM_MASTER_NODES ];

/*======================= C O D E =================================*/


/*!****************************************************************************
*
*  \b              a2b_pluginFind
*
*  Retrieve the plugin based on its handle.
*
*  \param          [in]    hnd    
*
*  \pre            None
*
*  \post           None
*
*  \return         Returns A2B_NULL if the plugin with a matching handle
*                  cannot be found.
*
******************************************************************************/
static a2b_Plugin*
a2b_pluginFind
    (
    a2b_Handle  hnd
    )
{
    a2b_UInt32 idx;
    a2b_Plugin* plugin = A2B_NULL;
    for ( idx = 0u; idx < (a2b_UInt32)A2B_ARRAY_SIZE(gsPlugins); ++idx )
    {
        if ( hnd == (a2b_Handle)&gsPlugins[idx] )
        {
            if ( gsPlugins[idx].inUse )
            {
                plugin = &gsPlugins[idx];
            }
            break;
        }
    }

    return plugin;

} /* a2b_pluginFind */


/*!****************************************************************************
*
*  \b              a2b_onSimulatedPeriphAccess
*
*  Called by the timer after a period of time to simulate a delay in
*  accessing peripherals over I2C. The callback basically handles replying
*  to the following requests:
*
*       A2B_MSGREQ_PLUGIN_PERIPH_INIT
*       A2B_MSGREQ_PLUGIN_PERIPH_DEINIT
*
*  \param          [in]    timer    The timer instance.
*
*  \param          [in]    userData User data passed to timer services
*                                   when the timer was initialized. Should
*                                   contain the plugin instance.
*
*  \pre            None
*
*  \post           None
*
*  \return         None
*
******************************************************************************/
static void
a2b_onSimulatedPeriphAccess
    (
    struct a2b_Timer*   timer,
    a2b_Handle          userData
    )
{
    a2b_Plugin* plugin = (a2b_Plugin*)userData;
    struct a2b_Msg* msg;
    a2b_PluginInit* initReply;
    a2b_PluginDeinit* deinitReply;

    A2B_UNUSED(timer);

    if ( A2B_NULL != plugin )
    {
        msg = a2b_msgRtrGetExecutingMsg(plugin->ctx, A2B_MSG_MAILBOX);
        if ( A2B_NULL != msg )
        {
            if ( A2B_MSGREQ_PLUGIN_PERIPH_INIT == a2b_msgGetCmd(msg) )
            {
                initReply = (a2b_PluginInit*)a2b_msgGetPayload(msg);
                initReply->resp.status = A2B_RESULT_SUCCESS;
            }
            /* Else A2B_MSGREQ_PLUGIN_PERIPH_DEINIT */
            else
            {
                deinitReply = (a2b_PluginDeinit*)a2b_msgGetPayload(msg);
                deinitReply->resp.status = A2B_RESULT_SUCCESS;
            }
        }

        /* Finalize (and thus) finish the request so we can process
         * the next message in our mailbox.
         */
        a2b_msgRtrExecUpdate(plugin->ctx, A2B_MSG_MAILBOX, A2B_EXEC_COMPLETE);
    }
}


/*!****************************************************************************
*
*  \b              a2b_onDtcMsgFree
*
*  The function is called just prior to the notification message being
*  released back to the heap. This provides the opportunity to free any
*  user data associated with the message. In this case, the DTC structure
*  is freed back to an internal, per-plugin, heap.
*
*  \param          [in]    msg  The notification message being readied to
*                               be freed.
*
*  \pre            None
*
*  \post           None
*
*  \return         None
*
******************************************************************************/
static void
a2b_onDtcMsgFree
    (
    struct a2b_Msg* msg
    )
{
    a2b_Plugin*                 plugin;
    a2b_UInt16                  idx;
    a2b_DtcInfo**               payload;

    if ( A2B_NULL != msg )
    {
        payload = (a2b_DtcInfo**)a2b_msgGetPayload(msg);
        plugin = a2b_msgGetUserData(msg);
        if ( A2B_NULL != plugin )
        {
            for ( idx = 0u; (a2b_UInt16)idx < A2B_ARRAY_SIZE(plugin->dtcMsgHeap); ++idx )
            {
                /* If we found the DTC in our heap */
                if ( *payload == &plugin->dtcMsgHeap[idx].dtc )
                {
                    /* Clear it and return it to the internal heap */
                    (void)a2b_memset(&plugin->dtcMsgHeap[idx], 0,
                            sizeof(plugin->dtcMsgHeap[idx]));
                    break;
                }
            }
        }
    }
}


/*!****************************************************************************
*
*  \b              a2b_emitSlaveDtc
*
*  The function emits a DTC notification to interested listeners.
*
*  \param          [in]    plugin   The slave plugin instance.
*
*  \param          [in]    intrSrc  The node address of the interrupt source.
*
*  \param          [in]    intrType Interrupt type (A2B_ENUM_INTTYPE_*)
*
*  \pre            None
*
*  \post           None
*
*  \return         None
*
******************************************************************************/
static void
a2b_emitSlaveDtc
    (
    a2b_Plugin* plugin,
    a2b_UInt8   intrSrc,
    a2b_UInt8   intrType
    )
{
    struct a2b_Msg* dtcMsg;
    a2b_UInt16 idx;
    a2b_DtcMsgItem* dtcItem = A2B_NULL;
    a2b_DtcInfo** payload;
    a2b_HResult result;

    /* Perhaps a peripheral attached to this slave node
     * generated an interrupt received over the AD2410 GPIO
     * pin. We'll attempt to notify the application of this event by
     * creating a fake diagnostic trouble code (DTC).
     */

    /* Find a free container to hold the DTC information */
    for ( idx = 0u; idx < (a2b_UInt16)A2B_ARRAY_SIZE(plugin->dtcMsgHeap); ++idx )
    {
        if ( !plugin->dtcMsgHeap[idx].inUse )
        {
            dtcItem = &plugin->dtcMsgHeap[idx];
            dtcItem->inUse = A2B_TRUE;
            /* Just make up some fake data */
            dtcItem->dtc.mode = (a2b_Byte)(intrSrc % 7u);
            dtcItem->dtc.pid = (a2b_Byte)
                                    (idx % A2B_ARRAY_SIZE(plugin->dtcMsgHeap));
            dtcItem->dtc.buf[0] = intrSrc;
            dtcItem->dtc.buf[1] = intrType;
            dtcItem->dtc.nBytes = 2u;
            break;
        }
    }


    if ( A2B_NULL == dtcItem )
    {
        A2B_TRACE0((plugin->ctx,
                    (A2B_TRC_DOM_PLUGIN | A2B_TRC_LVL_ERROR),
                    "a2b_emitSlaveDtc: "
                    "failed to allocate DTC item from heap"));
    }
    else
    {
        /* Now allocate an actual notification message */
        dtcMsg = a2b_msgAlloc(plugin->ctx,
                                A2B_MSG_NOTIFY,
                                A2B_MSGNOTIFY_DTC);

        if ( A2B_NULL == dtcMsg )
        {
            A2B_TRACE0((plugin->ctx, (A2B_TRC_DOM_PLUGIN | A2B_TRC_LVL_ERROR),
                    "a2b_emitSlaveDtc: failed to allocate DTC message"));
            /* Return the DTC to the heap */
            (void)a2b_memset(dtcItem, 0, sizeof(*dtcItem));
        }
        else
        {
            /* Track when this notification is freed so we can return the
             * DTC structure to our internal heap
             */
            a2b_msgSetUserData(dtcMsg, plugin, &a2b_onDtcMsgFree);

            payload = (a2b_DtcInfo**)a2b_msgGetPayload(dtcMsg);
            *payload = &dtcItem->dtc;
            /* Make best effort delivery of notification */
            result = a2b_msgRtrNotify(dtcMsg);
            if ( A2B_FAILED(result) )
            {
                A2B_TRACE1((plugin->ctx,
                        (A2B_TRC_DOM_PLUGIN | A2B_TRC_LVL_ERROR),
                        "a2b_emitSlaveDtc: "
                        "failed to emit slave DTC notification: 0x%lX",
                        &result));
                /* Return the DTC to the heap */
                (void)a2b_memset(dtcItem, 0, sizeof(*dtcItem));
            }

            /* We no longer need this message */
            (void)a2b_msgUnref(dtcMsg);
        }
    }
}


/*!****************************************************************************
*
*  \b              a2b_pluginOpen
*
*  Called to see if the plugin handles a specific node.
* 
*  During discovery we scan through the plugins list trying to open each
*  one giving the nodeInfo and nodeAddr of the discovered node. If the
*  plugin can manage this node then a valid (instantiated) handle is
*  returned, else it returns null and the next plugin is tried. Once a
*  non-null handle is returned it is assumed this is the managing plugin.
*  If no plugin handles a node then it's assumed to be a very dumb node.
*
*  \param          [in]    ctx         A2B stack context
*  \param          [in]    nodeSig     node signature (version/product/etc)
*
*  \pre            None
*
*  \post           The returned handle will be returned on the close() and
*                  is available on all messages to the plugin, use
*                  msg.a2b_msgGetPluginHdl() to get the handle.
*
*  \return         NULL=error, plugin does NOT handle the nodeSig
*                  NON-NULL=nodeSig handled by this plugin
*
******************************************************************************/
static a2b_Handle
a2b_pluginOpen
    (
    struct a2b_StackContext*    ctx,
    const a2b_NodeSignature*   nodeSig
    )
{
    a2b_Plugin* plugin = A2B_NULL;
    struct a2b_Timer* timer = A2B_NULL;
    a2b_UInt32  idx;
    a2b_Int16 nodeAddr = A2B_NODEADDR_NOTUSED;
    static a2b_Bool   bPluginInit = A2B_FALSE;

    if ( A2B_NULL != nodeSig )
    {
		nodeAddr = nodeSig->nodeAddr;

		A2B_TRACE1((ctx, (A2B_TRC_DOM_PLUGIN | A2B_TRC_LVL_INFO),
								 "a2b_pluginOpen: opening slave plugin for "
								 "nodeAddr = %hd", &nodeAddr));

		if ( !bPluginInit )
		{
			bPluginInit = A2B_TRUE;
			for ( idx = 0u; idx < A2B_ARRAY_SIZE(gsPlugins); ++idx )
			{
				(void)a2b_memset(&gsPlugins[idx], 0, sizeof(gsPlugins[idx]));
			}
		}

		/* We cannot serve as a master plugin */
		if ( nodeAddr == A2B_NODEADDR_MASTER )
		{
			return A2B_NULL;
		}

		/* This dummy slave node should only be instantiated by the BDD
		 * configuration defined for the unit test.
		 */
		if ( nodeSig->bddInfo.vendorId != A2B_UTEST_BDD_SLAVE_NODE_VENDOR_ID )
		{
			return A2B_NULL;
		}

		/*
		 * Typically here we might check to see if this slave plugin can
		 * actually manage this node. This might be done by interrogating
		 * an attached EEPROM to make sure it has the correct vendor and/or
		 * product identifier (and version). If it's a manageable node then
		 * we'll try to allocate a slave plugin *instance* to associate with
		 * the node.
		 */

		if (A2B_NULL != ctx)
		{
			/* Look for an available slave plugin control block */
			for ( idx = 0u; idx < (a2b_UInt32)A2B_ARRAY_SIZE(gsPlugins); ++idx )
			{
				if ( !gsPlugins[idx].inUse )
				{
					timer = a2b_timerAlloc(ctx, A2B_NULL, &gsPlugins[idx]);
					if ( A2B_NULL == timer )
					{
						/* Bail out since we couldn't allocate a timer */
						A2B_TRACE0((ctx, (A2B_TRC_DOM_PLUGIN | A2B_TRC_LVL_ERROR),
							 "a2b_pluginOpen: failed to allocate a "
							 "timer for slave plugin"));
					}
					else
					{
						plugin = &gsPlugins[idx];
						(void)a2b_memset(plugin, 0, sizeof(*plugin));
						plugin->timer   = timer;
						plugin->ctx     = ctx;
						plugin->nodeSig = *nodeSig;
						plugin->inUse   = A2B_TRUE;
					}
					break;
				}
			}
		}
    }
    return plugin;

} /* a2b_pluginOpen */


/*!****************************************************************************
*
*  \b              a2b_pluginClose
*
*  Called to close the plugin
*
*  \param          [in]    hnd    
*
*  \pre            None
*
*  \post           None
*
*  \return         Success or Error
*
******************************************************************************/
static a2b_HResult
a2b_pluginClose
    (
    a2b_Handle  hnd
    )
{
    a2b_Plugin* plugin;
    a2b_HResult status = A2B_MAKE_HRESULT(A2B_SEV_FAILURE, A2B_FAC_PLUGIN, 
                                            A2B_EC_INVALID_PARAMETER);

    plugin = a2b_pluginFind(hnd);
    if ( A2B_NULL != plugin )
    {
        A2B_TRACE1((plugin->ctx, (A2B_TRC_DOM_PLUGIN | A2B_TRC_LVL_INFO),
                                 "a2b_pluginClose: closing slave plugin for "
                                 "nodeAddr = %hd", &plugin->nodeSig.nodeAddr));
        (void)a2b_timerUnref(plugin->timer);
        plugin->ctx         = A2B_NULL;
        plugin->inUse       = A2B_FALSE;

        status = A2B_RESULT_SUCCESS;
    }

    return status;

} /* a2b_pluginClose */


/*!****************************************************************************
*
*  \b              a2b_pluginExecute
*
*  Called when a job needs executing by this plugin.
*
*  \param          [in]    msg          A2B message to process.
*
*  \param          [in]    pluginHnd    The plugin's handle.
*
*  \param          [in]    ctx          The plugin's context.
*
*  \pre            None
*
*  \post           None
*
*  \return         A2B_EXEC_COMPLETE == Execution is now complete
*                  A2B_EXEC_SCHEDULE == Execution is unfinished - schedule again
*                  A2B_EXEC_SUSPEND  == Execution is unfinished - suspend 
*                                       scheduling until a later event
*
******************************************************************************/
static a2b_Int32
a2b_pluginExecute
    (
    struct a2b_Msg*             msg,
    a2b_Handle                  pluginHnd,
    struct a2b_StackContext*    ctx
    )
{
    a2b_Int32                   ret    = A2B_EXEC_COMPLETE;
    a2b_UInt32                  cmd;
    a2b_DtcInfo**               dtcInfo;
    a2b_Plugin*                 plugin = (a2b_Plugin*)pluginHnd;
    a2b_PluginInit*             initMsg;
    a2b_Int16                   nodeAddr= a2b_msgGetDestNodeAddr(msg);
    a2b_HResult 				nRes;
#ifdef ENABLE_PERI_CONFIG_BCF
    ADI_A2B_NODE_PERICONFIG (*pPeriConfig)[];  /* Pointer to an array of configuration */
#endif

#ifndef A2B_FEATURE_TRACE
    A2B_UNUSED(ctx);
#endif
    
    if ( (plugin == A2B_NULL) || (A2B_NULL == msg) )
    {
        A2B_TRACE1((ctx, (A2B_TRC_DOM_PLUGIN | A2B_TRC_LVL_ERROR),
                    "Exit: %s execute(): Internal error",
                    A2B_SLAVE_PLUGIN_NAME));
        return ret;
    }

    cmd    = a2b_msgGetCmd(msg);

    A2B_TRACE2((ctx, (A2B_TRC_DOM_PLUGIN | A2B_TRC_LVL_TRACE1),
                "Enter: %s execute(%ld):", A2B_SLAVE_PLUGIN_NAME, &cmd));

    switch ( cmd )
    {
        case A2B_MSGREQ_PLUGIN_PERIPH_INIT:
            initMsg = (a2b_PluginInit*)a2b_msgGetPayload( msg );
            initMsg->resp.status = A2B_RESULT_SUCCESS;
#ifdef ENABLE_PERI_CONFIG_BCF
            if(initMsg->req.pNodePeriDeviceConfig != A2B_NULL)
            {
            	pPeriConfig = (ADI_A2B_NODE_PERICONFIG (*)[])initMsg->req.pNodePeriDeviceConfig;
            	plugin->pNodePeriDeviceConfig = &((*pPeriConfig)[((a2b_UInt32)nodeAddr + (a2b_UInt32)1)]);

            	nRes = adi_a2b_PeriheralConfig(plugin, plugin->pNodePeriDeviceConfig);
            }
#endif

#if defined(A2B_FEATURE_TRACE) || defined(A2B_FEATURE_SEQ_CHART)
            /*=============================================================== 
             * NOTE: initMsg->req.tdmSettings is NEVER normally non-NULL.
             *       The reason for the check here is because the splugintest
             *       from a2butest-linux has a test where this is NULL.
             ================================================================*/
            if ( initMsg->req.tdmSettings )
            {
                A2B_TRACE2((ctx, (A2B_TRC_DOM_PLUGIN | A2B_TRC_LVL_INFO),
                        "Slave%hd Plugin: "
                        "A2B_MSGREQ_PLUGIN_PERIPH_INIT processed (rate: %hu)",
                        &nodeAddr,
                        &initMsg->req.tdmSettings->networkSampleRate));
                A2B_SEQ_RAW2(ctx,  A2B_SEQ_CHART_LEVEL_DISCOVERY, 
                             "== Slave%hd Plugin: "
                             "A2B_MSGREQ_PLUGIN_PERIPH_INIT "
                             "Processed (rate: %hu) ==",
                             &nodeAddr,
                             &initMsg->req.tdmSettings->networkSampleRate);
            }
#endif
            ret = A2B_EXEC_COMPLETE;
            break;

        case A2B_MSGREQ_PLUGIN_PERIPH_DEINIT:
			A2B_TRACE1((ctx, (A2B_TRC_DOM_PLUGIN | A2B_TRC_LVL_INFO),
            "Slave%hd Plugin: "
            "Process A2B_MSGREQ_PLUGIN_PERIPH_DEINIT",
            &nodeAddr));

            A2B_SEQ_RAW1(ctx,  A2B_SEQ_CHART_LEVEL_DISCOVERY, 
                             "== Slave%hd Plugin: "
                             "Process A2B_MSGREQ_PLUGIN_PERIPH_DEINIT ==",
                             &nodeAddr );

            /* Callback for peripheral access (init/de-init)*/
        	a2b_onSimulatedPeriphAccess(A2B_NULL,plugin);

            ret = A2B_EXEC_SUSPEND;
            break;

        case A2B_MSGREQ_GET_PID:
            dtcInfo = (a2b_DtcInfo**)a2b_msgGetPayload(msg);
            (*dtcInfo)->buf[0] = (a2b_Byte) (A2B_BITM_INTSRC_SLVINT |
                            ((a2b_UInt32)plugin->nodeSig.nodeAddr & A2B_BITM_INTSRC_INODE));
            (*dtcInfo)->buf[1] = A2B_ENUM_INTTYPE_IO0PND;
            (*dtcInfo)->nBytes = 2u;
            break;

        case A2B_MSGREQ_PLUGIN_VERSION:
        	a2b_slave_getVerInfo((struct a2b_PluginVerInfo*)a2b_msgGetPayload(msg));
            break;

        default:
            A2B_TRACE2((ctx, (A2B_TRC_DOM_PLUGIN | A2B_TRC_LVL_WARN),
                        "%s execute(%ld): Unhandled command",
                        A2B_SLAVE_PLUGIN_NAME, &cmd));
            break;
    }

    A2B_TRACE3((plugin->ctx, (A2B_TRC_DOM_PLUGIN | A2B_TRC_LVL_TRACE1),
                "Exit: %s execute(%ld): 0x%lX", A2B_SLAVE_PLUGIN_NAME,
                &cmd, &ret));

    return ret;

} /* a2b_pluginExecute */


/*!****************************************************************************
*
*  \b              a2b_pluginInterrupt
*
*  Called to process an interrupt for the plugin.
*
*  \param          [in]    ctx       A2B stack context
* 
*  \param          [in]    hnd       Plugin handler
*
*  \param          [in]    intrSrc   The source (node address) of the
*                                    interrupt.
* 
*  \param          [in]    intrType  Interrupt type (A2B_ENUM_INTTYPE_*)
*
*  \pre            None
*
*  \post           None
*
*  \return         None
*
*******************************************************************************/
static void
a2b_pluginInterrupt
    (
    struct a2b_StackContext*    ctx,
    a2b_Handle                  hnd,
    a2b_UInt8                   intrSrc,
    a2b_UInt8                   intrType
    )
{
    a2b_Plugin* plugin = a2b_pluginFind(hnd);

    A2B_UNUSED(ctx);

    if ( A2B_NULL != plugin )
    {
        switch ( intrType )
        {
            /* Slave plugins *only* receive GPIO interrupts */
            case A2B_ENUM_INTTYPE_IO0PND:
            case A2B_ENUM_INTTYPE_IO1PND:
            case A2B_ENUM_INTTYPE_IO2PND:
            case A2B_ENUM_INTTYPE_IO3PND:
            case A2B_ENUM_INTTYPE_IO4PND:
            case A2B_ENUM_INTTYPE_IO5PND:
            case A2B_ENUM_INTTYPE_IO6PND:
            case A2B_ENUM_INTTYPE_IO7PND:
                a2b_emitSlaveDtc(plugin, intrSrc, intrType);
                break;

            default:
                break;
        }
    }

} /* a2b_pluginInterrupt */


/*!****************************************************************************
*
*  \b              A2B_SLAVE_PLUGIN_INIT
*
*  Called by PAL to init the slave plugin.
*
*  \param          [in]    api    
*
*  \pre            None
*
*  \post           None
*
*  \return         Returns A2B_TRUE on success, A2B_FALSE otherwise.
*
******************************************************************************/
A2B_DSO_PUBLIC a2b_Bool
A2B_SLAVE_PLUGIN_INIT
    (
    struct a2b_PluginApi*   api
    )
{
    a2b_Bool status = A2B_FALSE;

    if ( A2B_NULL != api )
    {
        api->open      = &a2b_pluginOpen;
        api->close     = &a2b_pluginClose;
        api->execute   = &a2b_pluginExecute;
        api->interrupt = &a2b_pluginInterrupt;

        (void)a2b_strncpy(api->name, A2B_SLAVE_PLUGIN_NAME,
                    (a2b_Size)A2B_ARRAY_SIZE(api->name) - 1u);
        api->name[A2B_ARRAY_SIZE(api->name) - 1u] = '\0';

        status = A2B_TRUE;
    }

    return status;
} /* A2B_PLUGIN_INIT */
