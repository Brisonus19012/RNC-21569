/*******************************************************************************
Copyright (c) 2017 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
******************************************************************************
* @file: a2bapp.h
* @brief: This file contains Typedefs,configurable macros, structures for running
*          A2B application
* @version: $Revision: 3888 $
* @date: $Date: 2016-01-17 18:46:38 +0530 (Sun, 17 Jan 2016) $
* Developed by: Automotive Software and Systems team, Bangalore, India
*****************************************************************************/

#ifndef __A2BAPP_H__
#define __A2BAPP_H__

/*! \addtogroup Application_Reference
 *  @{
 */

/*============= I N C L U D E S =============*/
#include <stddef.h>
#include <sys/platform.h>
#include "a2bstack/inc/a2b/pal.h"
#include "platform/a2b/conf.h"
#include "a2bstack/inc/a2b/defs.h"
#include "a2bstack/inc/a2b/util.h"
#include "a2bstack/inc/a2b/msg.h"
#include "a2bstack/inc/a2b/msgrtr.h"
#include "a2bstack/inc/a2b/trace.h"
#include "a2bstack/inc/a2b/stack.h"
#include "a2bstack/inc/a2b/seqchart.h"
#include "a2bstack-protobuf/inc/a2b_bdd_helper.h"
#include "a2bstack/inc/a2b/regdefs.h"
#include "a2bstack/inc/a2b/interrupt.h"
#include "a2bstack/inc/a2b/system.h"
#include "a2bstack/inc/a2b/diag.h"
#include "adi_a2b_framework.h"
#include "a2bplugin-master/inc/a2bplugin-master/plugin.h"
#include "a2bplugin-slave/inc/a2bplugin-slave/plugin.h"
#include "a2bstack/src/timer_priv.h"
#include "a2bstack/src/stackctx.h"
#include "stdlib.h"
#include "stdio.h"
#ifdef A2B_RUN_BIT_ERROR_TEST
#include "a2bapp_bert.h"
#endif

/*============= D E F I N E S =============*/
#ifndef A2BAPP_LINK_STATICALLY
#define A2BAPP_LINK_STATICALLY
#endif

#define A2BAPP_POLL_PERIOD      (1)

#define A2B_DISABLE				(0)
#define A2B_ENABLE				(1)
/*! Bus Drop Check period in seconds */
#define A2B_BUS_DROP_CHK_PERIOD      	(5u)

#define A2B_APP_TMRTOHANDLE_BECOVF_AFTER_INTERVAL	(1000)	/* In milliseconds */
#define A2B_APP_TMRTOHANDLE_BECOVF_REPEAT_INTERVAL	(1000)	/* In milliseconds */


#ifdef A2B_PRINT_CONSOLE
#ifndef A2B_PRINT_DEFINED
#define A2B_APP_LOG(...) do{\
						printf(__VA_ARGS__);\
                        }while(0)
#endif
#else
#define A2B_APP_LOG(...)
#endif


#ifdef A2B_PRINT_CONSOLE
#ifndef A2B_PRINT_DEFINED
#define A2B_APP_DBG_LOG(...) do{\
						if(gpApp_Info[0]->bDebug)\
						printf(__VA_ARGS__);\
                        }while(0)
#endif
#else
#define A2B_APP_DBG_LOG(...)
#endif

/*============= D A T A T Y P E S=============*/

typedef struct {

	/* Input flags */
	a2b_Bool	bDebug;
#ifdef A2B_FEATURE_SEQ_CHART
	a2b_Char* seqFile;
#endif

	/* Objects for storing info populated inside a2bapp.c */
	A2B_ECB ecb;											/*!< App envirnment control block  */   
	a2b_StackPal pal;										/*!< PAL layer  */
	struct a2b_StackContext *ctx;							/*!< Stack context  */  
	bdd_Network bdd;										/*!< BDD Info  */
	ADI_A2B_BCD* pBusDescription;							/*!< Pointer to Bus Description File */
	ADI_A2B_NETWORK_CONFIG* pTargetProperties;				 /*!< Pointer to Bus Description File */
	ADI_A2B_NODE_PERICONFIG  aPeriNetworkTable[A2B_CONF_MAX_NUM_SLAVE_NODES + 1]; 	/*!< Table to get peripheral configuration structure */
	a2b_UInt8 anEeepromPeriCfgInfo[2 * (A2B_CONF_MAX_NUM_SLAVE_NODES + 1)];
	struct a2b_MsgNotifier *notifyInterrupt;				/*!< Interrupt Notifier  */
	struct a2b_MsgNotifier *notifyPowerFault;				/*!< Power Fault message notifier */
	struct a2b_Timer* hTmrToHandleBecovf;					/*!< Timer Handler for Bit-error   */

	/* Processing flags local to a2bapp.c */
	a2b_Bool discoveryDone;									/*!< Discovery Done Status  */
	a2b_Bool bCustomAuthFailed;								/*!< Custom node authentication failure indication */
	a2b_Bool bfaultDone;									/*!< Flag specifying whether fault has occured */
	a2b_Bool bBusDropDetected;								/*!< Flag to detect the Bus drop */
	a2b_Bool bRetry;										/*!< Retry enabled or disabled */
	a2b_UInt32 nDiscTryCnt;									/*!< Count of no of re-discovery attempts  */
	a2b_Bool bBecovfTimerEnable;							/*!< Enable flag for starting timer for resetting bit error count */
	a2b_UInt32 nBecovfRstCnt;
	a2b_UInt8 nNumBCD;
	a2b_UInt8 nDefaultBCDIndex;
	a2b_UInt8 bIntrptLatch;

	/* Output flags */
	a2b_UInt8 nodesDiscovered;								/*!< Number of slave nodes discovered  */
	a2b_Bool discoverySuccessful;							/*!< Disocvery success status */

	const a2b_Char *faultStatus;							/*!< String indicating line fault */
	a2b_Int8 faultNode;										/*!< Node number at which fault occured */
	a2b_UInt8 faultCode;									/*!< Fault code */

#ifdef A2B_RUN_BIT_ERROR_TEST
	ADI_A2B_BERT_HANDLER oBertHandler;
	a2b_UInt8 *pBertConfigBuff;
	a2b_Bool bIsBertStart;
#endif
} a2b_App_t;

/*======= P U B L I C P R O T O T Y P E S ========*/

extern a2b_UInt32 a2b_setup(a2b_App_t *pApp_Info);
extern a2b_UInt32 a2b_fault_monitor(a2b_App_t *pApp_Info);
extern a2b_Int32 a2b_stop(a2b_App_t *pApp_Info);
#endif /* __A2BAPP_H__ */

/**
 @}
*/
