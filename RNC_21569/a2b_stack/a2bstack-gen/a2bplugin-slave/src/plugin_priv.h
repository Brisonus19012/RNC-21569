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
 * \file:   plugin_priv.h
 * \author: Mentor Graphics, Embedded Software Division
 * \brief:  This is the definition of a A2B master node plugin.
 *
 *=============================================================================
 */

#ifndef A2B_PLUGIN_PRIV_H_
#define A2B_PLUGIN_PRIV_H_

/*======================= I N C L U D E S =========================*/

#include "a2bstack/inc/a2b/macros.h"
#include "platform/a2b/ctypes.h"
#include "a2bstack/inc/a2b/defs.h"
#include "a2bplugin-slave/inc/a2bplugin-slave/adi_a2b_periconfig.h"
/*======================= D E F I N E S ===========================*/

#define A2B_DTC_MAX_NOTIFY_MSGS (8)

/*======================= D A T A T Y P E S =======================*/

A2B_BEGIN_DECLS

/* Forward declarations */
struct a2b_Timer;
struct a2b_Plugin;

typedef struct a2b_DtcMsgItem
{
    a2b_Bool        inUse;
    a2b_DtcInfo     dtc;
} a2b_DtcMsgItem;


typedef struct a2b_Plugin
{
    struct a2b_StackContext*    ctx;
    a2b_NodeSignature           nodeSig;
    a2b_Bool                    inUse;
    struct a2b_Timer*           timer;
    a2b_DtcMsgItem              dtcMsgHeap[A2B_DTC_MAX_NOTIFY_MSGS];
#ifdef ENABLE_PERI_CONFIG_BCF
    ADI_A2B_NODE_PERICONFIG     *pNodePeriDeviceConfig;
#endif
    struct a2b_StackContext*    Mstrctx;
} a2b_Plugin;

/* Forward declarations */
struct a2b_PluginApi;


/*======================= P U B L I C  P R O T O T Y P E S ========*/

A2B_END_DECLS

/*======================= D A T A =================================*/


#endif /* A2B_PLUGIN_PRIV_H_ */
