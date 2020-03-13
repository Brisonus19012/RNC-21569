/*******************************************************************************
 Copyright (c) 2017 - Analog Devices Inc. All Rights Reserved.
 This software is proprietary & confidential to Analog Devices, Inc.
 and its licensors.
 *******************************************************************************

 Name       : a2bapp.c

 Description: This file is responsible for handling all the a2b network functions
 like discovery , interrupt and  fault handling.
 Functions  : main()
 a2b_setup()
 a2b_fault_monitor()
 a2bapp_ProcessSuperBcf()
 a2bapp_onInterrupt()
 a2bapp_onDiscoveryComplete()
 a2bapp_onPowerFault()
 a2bapp_pluginsLoad()
 a2bapp_pluginsUnload()


 Prepared &
 Reviewed by: Automotive Software and Systems team,
 IPDC, Analog Devices,  Bangalore, India

 @version: $Revision: 3626 $
 @date: $Date: 2016-11-027 14:04:13 +0530 $

 ******************************************************************************/

/*! \addtogroup Application_Reference Application Reference
 *  @{
 */

/** @defgroup Application_Reference
 *
 * This module has reference implementation for A2B Stack usage
 *
 */

/*! \addtogroup Application_Reference
 *  @{
 */



/*============= I N C L U D E S =============*/

#include <sys/platform.h>
#include "a2bstack-protobuf/inc/adi_a2b_busconfig.h"
#include "a2bapp_defs.h"
#include "a2bapp.h"
#include <errno.h>
#include <string.h>
#include "a2bstack/inc/a2b/pluginapi.h"
#include "a2bstack/inc/a2b/msgtypes.h"
#include "a2bstack/inc/a2b/regdefs.h"
#include "a2bstack/inc/a2b/ecb.h"
#include "a2bstack/src/timer_priv.h"
#include "platform/a2b/conf.h"
#include "adi_a2b_externs.h"
#include <assert.h>
#include <stdio.h>

/*============= D E F I N E S =============*/

#if defined(A2B_BCF_FROM_SOC_EEPROM) && !defined(A2B_FEATURE_EEPROM_PROCESSING)
#error "A2B_FEATURE_EEPROM_PROCESSING should also be enabled to use A2B_BCF_FROM_SOC_EEPROM feature"
#endif

#if defined(A2B_BCF_FROM_SOC_EEPROM) && defined(ADI_SIGMASTUDIO_BCF)
#error "A2B_BCF_FROM_SOC_EEPROM & ADI_SIGMASTUDIO_BCF features are mutually exclusive. Define only one to proceed further"
#endif

/*! Array of pointers to store App context */
a2b_App_t *gpApp_Info[A2B_CONF_MAX_NUM_MASTER_NODES];

/*============= D A T A =============*/

#ifdef ENABLE_SUPERBCF
static a2b_UInt32 nCurrBCFIndex = 0, nDiscTryCnt = 0;
#endif

/*============= C O D E =============*/

#ifdef ENABLE_SUPERBCF
static a2b_Int32 getCurrentSuperBCFIndex(a2b_App_t *pApp_Info, a2b_Int32 nRetryCount);
static a2b_Int32 a2b_ProcessSuperBcf(a2b_App_t *pApp_Info);
#endif

static a2b_Int32 a2b_init(a2b_App_t *pApp_Info);
static a2b_Int32 a2b_load(a2b_App_t *pApp_Info);
static a2b_Int32 a2b_start(a2b_App_t *pApp_Info);
static a2b_Int32 a2b_discover(a2b_App_t *pApp_Info);
static a2b_Int32 a2b_sendDiscoveryMessage(a2b_App_t *pApp_Info);
static a2b_Int32 a2b_setupPwrDiag(a2b_App_t *pApp_Info);
static void a2b_appCtxReset(a2b_App_t *pApp_Info);

static void a2bapp_onInterrupt(struct a2b_Msg* msg, a2b_Handle userData);
static void a2bapp_onDiscoveryComplete(struct a2b_Msg* msg, a2b_Bool isCancelled);
static void a2bapp_onPowerFault(struct a2b_Msg *msg, a2b_Handle userData);

a2b_UInt32 a2b_fault_monitor(a2b_App_t *pApp_Info);
static void a2b_app_handle_becovf(void* pParam);
static a2b_HResult a2b_AppDetectBusDrop(a2b_App_t *pApp_Info);
static a2b_HResult a2b_AppReadReg(struct a2b_StackContext* ctx, a2b_Int16 nodeAddr, a2b_UInt8 reg, a2b_UInt8* value);

#ifndef ADI_SIGMASTUDIO_BCF
static a2b_Bool a2b_loadBdd ( const a2b_Char* bddPath, bdd_Network* bdd);
#endif

#ifdef __ADSPBF7xx__
static void a2bapp_initTdmSettings(A2B_ECB* ecb, const bdd_Network* bdd);
#endif  /* __ADSPBF7xx__ */
#ifdef ENABLE_INTRRUPT_PROCESS
static a2b_HResult a2b_processIntrpt(a2b_App_t *pApp_Info);
#endif



#ifdef ENABLE_INTRRUPT_PROCESS
static void a2b_IntrptCallbk(a2b_App_t *pApp_Info)
{
	pApp_Info->bIntrptLatch = 1u;
}
#endif
/*!****************************************************************************
 *
 *  \b               a2b_init
 *
 *  This function initializes the elements of the application context structure.
 *
 *  \param           [in]    pApp_Info   Pointer to a2b_App_t instance
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          0 on Success
 *					 1 on Failure
 ******************************************************************************/
static a2b_Int32 a2b_init(a2b_App_t *pApp_Info)
{
	uint32_t nResult = 0;

	if (pApp_Info != NULL)
	{

		a2b_appCtxReset(pApp_Info);
		A2B_APP_DBG_LOG("Reset context done \n\r");

		/* Initialize the A2B Software Stack and Environment Control Block (ECB) */
		//a2b_systemInitialize(A2B_NULL, &pApp_Info->ecb);
		//A2B_APP_DBG_LOG("System Init done \n\r");

		/* Initialize the Platform Abstraction Layer (PAL) */
		a2b_palInit(&pApp_Info->pal, &pApp_Info->ecb);
		A2B_APP_DBG_LOG("PAL Init done \n\r");

#ifdef ENABLE_INTRRUPT_PROCESS
		adi_a2b_EnablePinInterrupt(0, &a2b_IntrptCallbk);
#endif
	}

	return nResult;
}

/*!****************************************************************************
 *
 *  \b               a2b_appCtxReset
 *
 *  This function initializes the elements of the application context structure.
 *
 *  \param           [in]    pApp_Info   Pointer to a2b_App_t instance
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          0 on Success
 *					 1 on Failure
 ******************************************************************************/
static void a2b_appCtxReset(a2b_App_t *pApp_Info)
{
	uint8_t nIndex;
	/* Input flags */
	a2b_Bool	bDebug;
#ifdef A2B_FEATURE_SEQ_CHART
	a2b_Char* seqFile;
#endif

	/* take back up */
	nIndex = pApp_Info->ecb.palEcb.nChainIndex;
	bDebug = pApp_Info->bDebug;
#ifdef A2B_FEATURE_SEQ_CHART
	seqFile = pApp_Info->seqFile;
#endif	/* A2B_FEATURE_SEQ_CHART */

	/* Clear out the Application's context container */
	memset(pApp_Info, 0, sizeof(a2b_App_t));

	/* Restore inputs */
	pApp_Info->ecb.palEcb.nChainIndex = nIndex;
	pApp_Info->bDebug 	=  bDebug;
#ifdef A2B_FEATURE_SEQ_CHART
	pApp_Info->seqFile 	=  seqFile;
#endif	/* A2B_FEATURE_SEQ_CHART */

	/* Store the Pointers */
	gpApp_Info[nIndex] = pApp_Info;

}
#ifdef ENABLE_SUPERBCF
/*!****************************************************************************
 *
 *  \b               getCurrentSuperBCFIndex
 *
 *  This function returns the current BCF index in a super BCF file to be used
 *  during discovery based on the current retry count.
 *
 *  \param           [in]    nRetryCount   discovery iteration count
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          0 on Success
 *					 1 on Failure
 ******************************************************************************/
static a2b_Int32 getCurrentSuperBCFIndex(a2b_App_t *pApp_Info, a2b_Int32 nRetryCount)
{
	int nCurrBCFIndex = 0;

	if( (pApp_Info->nDefaultBCDIndex == 0xFF) || (pApp_Info->nDefaultBCDIndex == pApp_Info->nNumBCD))
	{
		pApp_Info->nDefaultBCDIndex = pApp_Info->nNumBCD - 1u;
	}
	if (nRetryCount >= pApp_Info->nNumBCD)
	{
		nCurrBCFIndex = pApp_Info->nDefaultBCDIndex;
	}
	else
	{
		nCurrBCFIndex = ((nRetryCount + pApp_Info->nDefaultBCDIndex + 1) % pApp_Info->nNumBCD);
	}

	return nCurrBCFIndex;

}
#endif
/*!****************************************************************************
 *
 *  \b               a2b_load
 *
 *  This function loads network configuration into the Stack context
 *
 *  \param           [in]    pApp_Info   Pointer to a2b_App_t instance
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          0 on Success
 *					 1 on Failure
 ******************************************************************************/
static a2b_Int32 a2b_load(a2b_App_t *pApp_Info)
{
	uint32_t nResult = 0;
	int nSuperBcfIndex;
	a2b_UInt8* panTempBuff;
	/*
	 * Decode the network configuration and store it into the bdd element of
	 * the Application context.
	 */
#ifdef 	ADI_SIGMASTUDIO_BCF

	A2B_APP_LOG("\n\rUsing SigmaStudio BCF File\n\r");

#ifdef ADI_A2B_BCF_COMPRESSED

#ifndef ENABLE_SUPERBCF
	/* Parse compressed BDD */
	adi_a2b_ComprBcfParse_bdd(&sCmprBusDescription, &pApp_Info->bdd, pApp_Info->ecb.palEcb.nChainIndex);
	/* Parse compressed BCF to store peripheral info */
	adi_a2b_ParsePeriCfgFrComBCF(&sCmprBusDescription, &pApp_Info->aPeriNetworkTable, pApp_Info->ecb.palEcb.nChainIndex);
	pApp_Info->pTargetProperties = &sCmprBusDescription.sTargetProperties;

#else
	/* using BCF adi_a2b_busconfig.c */
	pApp_Info->nNumBCD = sCmprSuperBCD.nNumBCD;
	pApp_Info->nDefaultBCDIndex = sCmprSuperBCD.nDefaultBCDIndex;
	nSuperBcfIndex = getCurrentSuperBCFIndex(pApp_Info,nDiscTryCnt);
	/* Parse compressed BDD */
	adi_a2b_ComprBcfParse_bdd(sCmprSuperBCD.apBusDescription[nSuperBcfIndex], &pApp_Info->bdd, pApp_Info->ecb.palEcb.nChainIndex);
	/* Parse compressed BCF to store peripheral info */
	adi_a2b_ParsePeriCfgFrComBCF(sCmprSuperBCD.apBusDescription[nSuperBcfIndex], &pApp_Info->aPeriNetworkTable, pApp_Info->ecb.palEcb.nChainIndex);

	pApp_Info->pTargetProperties = &sCmprSuperBCD.apBusDescription[nSuperBcfIndex]->sTargetProperties;
#endif

#else /* ADI_A2B_BCF_COMPRESSED */

#ifndef ENABLE_SUPERBCF
	/* using BCF adi_a2b_busconfig.c */
	pApp_Info->pBusDescription = &sBusDescription;
	pApp_Info->pTargetProperties = &sBusDescription.sTargetProperties;

#else
	pApp_Info->nNumBCD = sSuperBCD.nNumBCD;
	pApp_Info->nDefaultBCDIndex = sSuperBCD.nDefaultBCDIndex;
	nSuperBcfIndex = getCurrentSuperBCFIndex(pApp_Info,nDiscTryCnt);
	/* using BCF adi_a2b_busconfig.c */
	pApp_Info->pBusDescription = sSuperBCD.apBusDescription[nSuperBcfIndex];
	pApp_Info->pTargetProperties = &pApp_Info->pBusDescription->sTargetProperties;

#endif

	/* Parse BCf and store in BDD */
	a2b_bcfParse_bdd(pApp_Info->pBusDescription, &pApp_Info->bdd, pApp_Info->ecb.palEcb.nChainIndex);

	/* Parse BCF to store peripheral info */
	adi_a2b_ParsePeriCfgTable(pApp_Info->pBusDescription, &pApp_Info->aPeriNetworkTable[0], pApp_Info->ecb.palEcb.nChainIndex);

	A2B_APP_DBG_LOG("BCF parse done \n\r");

#endif

	/* assign the peripheral configuration table (including audio host) */
	pApp_Info->ecb.palEcb.pAudioHostDeviceConfig = &pApp_Info->aPeriNetworkTable[0u];


#elif defined(A2B_BCF_FROM_SOC_EEPROM)

	/* Requesting for a I2C handle so as to access SOC EEPROM device.
	 * Once the data from EEPROM is read we will close this instance of I2C handle as it will be re-opened during a2b_stackAlloc
	 * */
	a2b_pal_I2cInit(&pApp_Info->ecb);

	a2b_pal_I2cOpenFunc(pApp_Info->ecb.baseEcb.i2cAddrFmt, pApp_Info->ecb.baseEcb.i2cBusSpeed, &pApp_Info->ecb);

	/* Assuming the max size of I2C burst read */
	panTempBuff = malloc( 4096 );

	/* Create A2B Target properties */
	pApp_Info->pTargetProperties = malloc(sizeof(ADI_A2B_NETWORK_CONFIG));
	memset(pApp_Info->pTargetProperties, 0, sizeof(ADI_A2B_NETWORK_CONFIG));

	/* Populate BDD from local EEPROM */
	(void)a2b_get_bddFromEEPROM(&pApp_Info->ecb, &pApp_Info->bdd, panTempBuff, pApp_Info->anEeepromPeriCfgInfo, pApp_Info->pTargetProperties);
	/* Find the pointer where audio host config info is stored */
	pApp_Info->ecb.palEcb.pEepromAudioHostConfig = &pApp_Info->anEeepromPeriCfgInfo[0];

	/* Closing the I2C handle */
	a2b_pal_I2cCloseFunc(pApp_Info->ecb.palEcb.i2chnd);

#else
	/* From Third party tools */

#endif

#ifdef __ADSPBF71x__
	/* Clock for ADSP-BF7xx SPORT's is generated by SigmaDSP part. SPORT's should be enabled before starting discovery, so that A2B chip is clocked.
	 * Call to below function copies the TDM settings from BDD to palecb so that SPORT's configuration is done during PAL audio init function.
	 * */
	a2bapp_initTdmSettings(&pApp_Info->ecb, &pApp_Info->bdd);
#endif  /* __ADSPBF7xx__ */
#ifdef A2B_FEATURE_TRACE
	pApp_Info->ecb.baseEcb.traceLvl = A2B_CONF_DEFAULT_TRACE_LVL;
	pApp_Info->ecb.baseEcb.traceUrl = A2B_CONF_DEFAULT_TRACE_CHAN_URL;
#endif

	/*
	 * Initialize vendor, product, and version information in the ECB.
	 */
	a2b_bddPalInit(&pApp_Info->ecb, &pApp_Info->bdd);
	A2B_APP_DBG_LOG("BDD PAL Init done \n\r");

	/*
	 * Allocate a heap for the Stack. This step may be optional if the
	 * stack was configured to utilize an external memory management system
	 * by not defining A2B_FEATURE_MEMORY_MANAGER in features.h
	 */
	pApp_Info->ecb.baseEcb.heap = malloc(pApp_Info->ecb.baseEcb.heapSize);
	A2B_APP_DBG_LOG("Allocate Heap done \n\r");

	/*
	 * Perform the final allocation of the stack based off of the
	 * specifics of this network configuration.
	 */
	pApp_Info->ctx = a2b_stackAlloc(&pApp_Info->pal, &pApp_Info->ecb);
	A2B_APP_DBG_LOG("Allocate Stack done \n\r");

	/* No context, means failure */
	if (pApp_Info->ctx == 0)
	{
		nResult = 1;
	}

	return nResult;
}
/*!****************************************************************************
 *
 *  \b               a2b_start
 *
 *  This function involves instructing the Stack to begin polling for interrupts,
 *  enabling sequence charts and debugging output, and hooking in application
 *  level call-backs.
 *
 *  \param           [in]    pApp_Info   Pointer to a2b_App_t instance
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          0 on Success
 *					 1 on Failure
 ******************************************************************************/
static a2b_Int32 a2b_start(a2b_App_t *pApp_Info)
{
	uint32_t nResult = 0;

	/* Enable sequence charts */
#ifdef A2B_FEATURE_SEQ_CHART
	if ( A2B_NULL == pApp_Info->seqFile )
	{
		pApp_Info->seqFile = A2B_CONF_DEFAULT_SEQCHART_CHAN_URL;
	}
	if ( A2B_NULL != pApp_Info->seqFile )
	{
		/* Enable sequence charts (if configured) */
		a2b_seqChartStart(pApp_Info->ctx, pApp_Info->seqFile,
				A2B_SEQ_CHART_LEVEL_I2C | A2B_SEQ_CHART_LEVEL_MSGS,
				A2B_SEQ_CHART_OPT_ALL, "Sequence Chart");
	}
#endif

	/* Register for notifications on interrupts */
	pApp_Info->notifyInterrupt = a2b_msgRtrRegisterNotify(pApp_Info->ctx,
	A2B_MSGNOTIFY_INTERRUPT, a2bapp_onInterrupt, pApp_Info, A2B_NULL);

	/* Register for notifications on power faults */
	pApp_Info->notifyPowerFault = a2b_msgRtrRegisterNotify(pApp_Info->ctx,
	A2B_MSGNOTIFY_POWER_FAULT, a2bapp_onPowerFault, pApp_Info, A2B_NULL);

	/* Power diagnostic is set by default. Depending on SigmaStudio
	 * settings we should only allow re-discovery or not from a2bapp_onPowerFault() callback
	 */
	a2b_setupPwrDiag(pApp_Info);

	return nResult;
}
/*!****************************************************************************
 *
 *  \b               a2b_sendDiscoveryMessage
 *
 *  This function sends a message to master plugin instructing it to initiate
 *  A2B network discovery.
 *
 *  \param           [in]    pApp_Info   Pointer to a2b_App_t instance
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          0 on Success
 *					 1 on Failure
 ******************************************************************************/
static a2b_Int32 a2b_sendDiscoveryMessage(a2b_App_t *pApp_Info)
{
	a2b_NetDiscovery *discReq;
	struct a2b_Msg *msg;
	a2b_HResult result = 0;

	/* Create a network discovery request message */
	msg = a2b_msgAlloc(pApp_Info->ctx, A2B_MSG_REQUEST, A2B_MSGREQ_NET_DISCOVERY);

	/* Attach the BDD information to the message */
	discReq = (a2b_NetDiscovery*)a2b_msgGetPayload(msg);
	discReq->req.bdd = &pApp_Info->bdd;

#ifdef ADI_SIGMASTUDIO_BCF

	/* Attach additional peripheral initialization data as generated.*/
	discReq->req.periphPkg = (const a2b_Byte *)&pApp_Info->aPeriNetworkTable[0u];
	discReq->req.pkgLen = sizeof(ADI_A2B_NETWORK_PERICONFIG);

#elif defined(A2B_BCF_FROM_SOC_EEPROM)

	/* Attach additional peripheral initialization data as generated.*/
	discReq->req.periphPkg = (const a2b_Byte *)&pApp_Info->anEeepromPeriCfgInfo[2];
	discReq->req.pkgLen = 2 * A2B_CONF_MAX_NUM_SLAVE_NODES;

#else
	/*
	 * Attach additional peripheral initialization data as generated.
	 * by the Network Configuration Tool. In this case no peripheral
	 * initialization is added.
	 */
	discReq->req.periphPkg = A2B_NULL;
	discReq->req.pkgLen = 0;
#endif

	/* Add this context to the message */
	a2b_msgSetUserData(msg, (a2b_Handle)pApp_Info, A2B_NULL);
	result = a2b_msgRtrSendRequest(msg, A2B_NODEADDR_MASTER, a2bapp_onDiscoveryComplete);

#ifndef ENABLE_INTRRUPT_PROCESS
	a2b_Int32 pollTime = A2BAPP_POLL_PERIOD; //Interrupt polling interval in milliseconds.

	/* Instruct the Stack to begin interrupt polling every 25mS */
	a2b_intrStartIrqPoll(pApp_Info->ctx, pollTime);
#endif
	/* The message router adds its own reference to the submitted message. */
	a2b_msgUnref(msg);

	return result;
}
/*!****************************************************************************
 *
 *  \b               a2b_discover
 *
 *  This function sends a discovery initating message and ticks till completion.
 *  When using Super BCF this will iterate through the BCFs to complete discovery.
 *
 *  \param           [in]    pApp_Info   Pointer to a2b_App_t instance
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          0 on Success
 *					 1 on Failure
 ******************************************************************************/
static a2b_Int32 a2b_discover(a2b_App_t *pApp_Info)
{
	a2b_HResult result = 0;

	result = a2b_sendDiscoveryMessage(pApp_Info);

	if (result != 0)
	{

		A2B_APP_LOG("Error while sending discovery message \n\r");

		return 1;
	}
	A2B_APP_DBG_LOG("Triggering discovery... \r\n");

	/*
	 * Be sure to transition to the Poll state or call a2b_stackTick() in
	 * a loop here until a2b_onDiscoveryComplete() is called otherwise
	 * discovery will not progress!
	 */
	while (1)
	{
		/* tick keeps all process rolling.. so keep ticking */
		a2b_stackTick(pApp_Info->ctx);

#ifdef ENABLE_INTRRUPT_PROCESS
		a2b_processIntrpt(pApp_Info);
#endif
		if (pApp_Info->discoveryDone)
		{
			if (pApp_Info->discoverySuccessful == true)
			{
				/* A2B Network discovery and initialization is complete.*/
				break;
			}
			else
			{
				/* A2B Network discovery failed */
				pApp_Info->discoveryDone = false;

#ifdef ENABLE_SUPERBCF
				/* here, only upon custom node authentication failure, other configurations are applied.
				 * other failures like line fault can also be considered
				 *
				 */
				if (pApp_Info->bCustomAuthFailed == true)
				{
					nDiscTryCnt++;

					if (nDiscTryCnt == (pApp_Info->nNumBCD))
					{
						break;
					}

					pApp_Info->bCustomAuthFailed = false;

					/* Discovery as failed. Network order is different.. try a different network combination from Super BCF file */
					result = a2b_ProcessSuperBcf(pApp_Info);
					if (result != 0)
					{
						return (0);
					}
				}
#else

				break;
#endif

			}
		}
	}

#ifdef A2B_FEATURE_SEQ_CHART
	if ( A2B_NULL != pApp_Info->seqFile )
	{
		/* Do clean up after discovery is done */
		a2b_seqChartStop(pApp_Info->ctx);
	}
#endif

	return result;
}

#ifdef ENABLE_SUPERBCF
/*!****************************************************************************
 *
 *  \b               a2b_ProcessSuperBcf
 *
 *  This function loads a configuration from Super BCF and intiates a fresh discovery.
 *
 *  \param           [in]    pApp_Info   Pointer to a2b_App_t instance
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          0 on Success
 *					 1 on Failure
 ******************************************************************************/
static int a2b_ProcessSuperBcf(a2b_App_t *pApp_Info)
{
	uint32_t nResult = 0;

	/* stop a2b stack*/
	nResult = a2b_stop(pApp_Info);
	if (nResult != 0)
	{
		assert(nResult == 0);
	}

	/* load new configuration file */
	nResult = a2b_load(pApp_Info);
	if (nResult != 0)
	{
		assert(nResult == 0);
	}

	/* start stack again */
	nResult = a2b_start(pApp_Info);
	if (nResult != 0)
	{
		assert(nResult == 0);
	}

	nResult = a2b_sendDiscoveryMessage(pApp_Info);
	if (nResult != 0)
	{
		assert(nResult == 0);
	}

	return nResult;
}
#endif
/*!****************************************************************************
 *
 *  \b               a2b_setupPwrDiag
 *
 *  This function enables/disables line fault monitoring of the stack based on
 *  settings in the bcf.
 *
 *  \param           [in]    pApp_Info   Pointer to a2b_App_t instance
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          0 on Success
 *					 1 on Failure
 ******************************************************************************/
static a2b_Int32 a2b_setupPwrDiag(a2b_App_t *pApp_Info)
{
	uint32_t nResult = 0;
	struct a2b_Msg *msg;
	a2b_Bool *pIsLineDiagDisabled;

	/* Create a Disable Line Diagnostics request message*/
	msg = a2b_msgAlloc(pApp_Info->ctx, A2B_MSG_REQUEST, A2B_MSGREQ_NET_DISBALE_LINEDIAG);

	/* Attach the Boolean flag to the message , By default line diagnostics enabled */
	pIsLineDiagDisabled = (a2b_Bool*)a2b_msgGetPayload(msg);
	*pIsLineDiagDisabled = A2B_FALSE; /* Set the flag to True, in case app wants to disable */

	a2b_msgRtrSendRequest(msg, A2B_NODEADDR_MASTER, A2B_NULL);
	a2b_msgUnref(msg);
	a2b_ActiveDelay(pApp_Info->ctx, 5u);

	return nResult;
}
/*!****************************************************************************
 *
 *  \b               a2b_stop
 *
 *  This function stops stack, un-registering call-backs, turning off interrupt polling,
 *  disabling sequence charts, and freeing resources associated with the application
 *  context.
 *
 *  \param           [in]    pApp_Info   Pointer to a2b_App_t instance
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          0 on Success
 *					 1 on Failure
 ******************************************************************************/
a2b_Int32 a2b_stop(a2b_App_t *pApp_Info)
{
	uint32_t nResult = 0;

	/* Unregister notifications */
	a2b_msgRtrUnregisterNotify(pApp_Info->notifyInterrupt);
	a2b_msgRtrUnregisterNotify(pApp_Info->notifyPowerFault);

	A2B_APP_DBG_LOG("Unregister notification done \r\n");

	/* Stop interrupt polling */
	a2b_intrStopIrqPoll(pApp_Info->ctx);
	A2B_APP_DBG_LOG("Stop IRQ done... \r\n");

#ifdef A2B_FEATURE_SEQ_CHART
	if ( A2B_NULL != pApp_Info->seqFile )
	{
		/* Stop the sequence chart */
		a2b_seqChartStop(pApp_Info->ctx);
	}
#endif

	/* Free the stack and heap */
	a2b_stackFree(pApp_Info->ctx);

	A2B_APP_DBG_LOG("Free Stack context done \r\n");

	if (pApp_Info->ecb.baseEcb.heap != NULL)
	{
		free(pApp_Info->ecb.baseEcb.heap);
	}

	A2B_APP_DBG_LOG("Free heap done \r\n");

	/* Shut down the Stack */
	a2b_systemShutdown(A2B_NULL, &pApp_Info->ecb);

	return (0);
}

/*!****************************************************************************
 *
 *  \b               a2b_multimasterSetup
 *
 *  Multimaster wrapper for bus set up
 *
 *  \param           pApp_Info		Application Context Info
 *
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          1 on Success
 *					0 on Failure
 ******************************************************************************/
a2b_UInt32 a2b_multimasterSetup(a2b_App_t *pApp_Info)
{
	uint8_t nNumMasters;
	uint8_t nIndex;
	uint32_t nResult = 0;

#if (defined (ADI_SIGMASTUDIO_BCF)) && (!defined(ENABLE_SUPERBCF))
#ifndef ADI_A2B_BCF_COMPRESSED
	nNumMasters = sBusDescription.nNumMasterNode;
#else
	nNumMasters = sCmprBusDescription.nNumMasterNode;
#endif
#else
	/* Currently not supported */
	return 1;
#endif

	for (nIndex = 0; nIndex < nNumMasters; nIndex++)
	{
		A2B_APP_LOG("\n\r Setting Up Network %d... \n\r",nIndex);
		/* Sub network / chain index */
		pApp_Info[nIndex].ecb.palEcb.nChainIndex = nIndex;
		nResult = a2b_setup(&pApp_Info[nIndex]);
	}

	/* Enable audio only if all the chains are discovered */
	if(nResult == 0)
	{
		for (nIndex = 0; nIndex < nNumMasters; nIndex++)
		{
#ifdef A2B_ENABLE_AUDIO_FROM_APP
			adi_a2b_EnableAudioHost(nIndex, true);
#endif
		}
	}

	return nResult;

}

/*!****************************************************************************
 *
 *  \b               a2b_setup
 *
 *  This function allocates the stack context and initiates discovery on the network
 *  If SuperBCF is enabled it also tries out the BCFs in order for successful discovery.
 *  This function should be called from outside the stack callback context.
 *
 *  \param           pApp_Info		Application Context Info
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          1 on Success
 *					0 on Failure
 ******************************************************************************/
a2b_UInt32 a2b_setup(a2b_App_t *pApp_Info)
{
	uint32_t nResult = 0;
	do
	{

		nResult = a2b_init(pApp_Info);
		if (nResult != 0)
		{
			A2B_APP_LOG("\n\rERROR INIT \n\r");
			break;
		}

		nResult = a2b_load(pApp_Info);

		if (nResult != 0)
		{
			A2B_APP_LOG("ERROR Load \n\r");
			break;
		}

		nResult = a2b_start(pApp_Info);

		if (nResult != 0)
		{
			A2B_APP_LOG("ERROR Start \n\r");
			break;
		}

		nResult = a2b_discover(pApp_Info);

		if (nResult != 0)
		{
			A2B_APP_LOG("ERROR discover \n\r");
			break;
		}

	} while (0);

	/* Check Discovery status */
	if (pApp_Info->discoverySuccessful)
	{
		nResult = 0u;
	}
	else
	{
		nResult = 1u;
	}

	return (nResult);
}

/*!****************************************************************************
 *
 *  \b               a2b_fault_monitor
 *
 *  If line diagnostics is enabled this function checks if a line fault occurred
 *  post discovery and initiates re-discovery for the no of times configured in BCF.
 *
 *  \param            pApp_Info		Application Context Info
 *
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return         0 on Success
 *					1 on Failure
 ******************************************************************************/
a2b_UInt32 a2b_multiMasterFault_monitor(a2b_App_t *pApp_Info)
{
	uint8_t nNumMasters;
	uint8_t nIndex;
	uint32_t nResult = 0;

#if (defined (ADI_SIGMASTUDIO_BCF)) && (!defined(ENABLE_SUPERBCF))
#ifndef ADI_A2B_BCF_COMPRESSED
	nNumMasters = sBusDescription.nNumMasterNode;
#else
	nNumMasters = sCmprBusDescription.nNumMasterNode;
#endif
#else
	/* Currently not supported */
	return 1;
#endif

	for (nIndex = 0; nIndex < nNumMasters; nIndex++)
	{
		nResult = a2b_fault_monitor(&pApp_Info[nIndex]);
	}
	return nResult;

}

/*!****************************************************************************
 *
 *  \b               a2b_fault_monitor
 *
 *  If line diagnostics is enabled this function checks if a line fault occurred
 *  post discovery and initiates re-discovery for the no of times configured in BCF.
 *
 *  \param           pApp_Info		Application Context Info
 *
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          0 on Success
 *					1 on Failure
 ******************************************************************************/
a2b_UInt32 a2b_fault_monitor(a2b_App_t *pApp_Info)
{
	a2b_UInt32 nResult = 0;
	a2b_UInt8 nChainIndex;

	/* ensure the num rediscovery attempt is set to 0 in case auto rediscovery on faults are not enabled */
	if ((pApp_Info->pTargetProperties->bAutoDiscCriticalFault == DISABLED) && (pApp_Info->pTargetProperties->bAutoRediscOnFault == DISABLED))
	{
		pApp_Info->pTargetProperties->nAttemptsCriticalFault = 0;
	}

	/* If line diagnostics enabled and non-zero re-attempts configured */
	if ((pApp_Info->pTargetProperties->bLineDiagnostics == 1) && (pApp_Info->pTargetProperties->nAttemptsCriticalFault != 0))
	{
		/* If fault has occurred  */
		if ((pApp_Info->bRetry == A2B_TRUE) && (pApp_Info->bfaultDone == A2B_TRUE))
		{
			pApp_Info->bRetry = A2B_FALSE;
			nChainIndex = pApp_Info->ecb.palEcb.nChainIndex;

#ifdef A2B_ENABLE_AUDIO_FROM_APP
			adi_a2b_EnableAudioHost(nChainIndex, false);
#endif

			/* delay between re-discovery attempt */
			a2b_ActiveDelay(pApp_Info->ctx, pApp_Info->pTargetProperties->nRediscInterval);

			/* stop a2b stack */
			nResult = a2b_stop(pApp_Info);

			/* Re-discover the network */
			pApp_Info->ecb.palEcb.nChainIndex = nChainIndex;
			nResult = a2b_setup(pApp_Info);

#ifdef A2B_ENABLE_AUDIO_FROM_APP
			if(nResult == 0u)
			{
				/* This will work only when there is no dependency on the other network */
				adi_a2b_EnableAudioHost(nChainIndex, true);
			}
#endif

			pApp_Info->nDiscTryCnt++;

		}
	}

	return (nResult);
}
/*!****************************************************************************
 *
 *  \b               a2bapp_onInterrupt
 *
 *  The handler for A2B interrupt notifications.
 *
 *  \param           [in]    msg         The A2B interrupt notification message.
 *
 *  \param           [in]    userData    User data associated with the
 *                                       notification registration.
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          None
 *
 ******************************************************************************/
static void a2bapp_onInterrupt(struct a2b_Msg* msg, a2b_Handle userData)
{
	a2b_Interrupt* interrupt;

	a2b_App_t *pApp_Info  = (a2b_App_t *)userData;

	if (msg)
	{
		interrupt = a2b_msgGetPayload(msg);

		if (pApp_Info->bDebug)
		{
			if (interrupt)
			{

				A2B_APP_LOG("INTERRUPT: intrType=%u nodeAddr=%d\n\r", interrupt->intrType, interrupt->nodeAddr);
				/* Add your code to handle interrupt */
			}
			else
			{

				A2B_APP_LOG("INTERRUPT: failed to retrieve payload\n\r");
			}
		}
	}
}

/*!****************************************************************************
 *
 *  \b               a2bapp_onDiscoveryComplete
 *
 *  The handler which receives the response to the request to discover the
 *  A2B network.
 *
 *  \param           [in]    msg         The response message to the network
 *                                       discovery request.
 *
 *  \param           [in]    isCancelled An indication of whether the original
 *                                       request was cancelled before it was
 *                                       completed.
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          None
 *
 ******************************************************************************/
static void a2bapp_onDiscoveryComplete(struct a2b_Msg* msg, a2b_Bool isCancelled)
{
	a2b_NetDiscovery* results;
	a2b_Bool discDone;

	if ( A2B_NULL == msg)
	{

		/* This should *never* happen */
		A2B_APP_LOG("Error: no response message for network discovery\n\r");

	}
	else
	{
		a2b_App_t *pApp_Info = a2b_msgGetUserData(msg);
		pApp_Info->discoveryDone = true;

		if (isCancelled)
		{

			A2B_APP_LOG("Discovery request was cancelled.\n\r");

		}
		else
		{
			results = (a2b_NetDiscovery*)a2b_msgGetPayload(msg);
			if (A2B_SUCCEEDED(results->resp.status))
			{

				A2B_APP_LOG("Discovery succeeded with %d nodes discovered\n\r", results->resp.numNodes);

				pApp_Info->discoverySuccessful = true;
				pApp_Info->nodesDiscovered = results->resp.numNodes;

				/* When line fault monitoring is enabled, Allocate a timer to periodically clear BECNT register to reset the error counter */
				if ((pApp_Info->bBecovfTimerEnable == A2B_FALSE) && (pApp_Info->pTargetProperties->bLineDiagnostics == 1))
				{

					pApp_Info->hTmrToHandleBecovf = a2b_timerAlloc(pApp_Info->ctx, (a2b_TimerFunc)a2b_app_handle_becovf, (a2b_Handle)(pApp_Info));
					pApp_Info->bBecovfTimerEnable = A2B_TRUE;

					a2b_timerSet(pApp_Info->hTmrToHandleBecovf, A2B_APP_TMRTOHANDLE_BECOVF_AFTER_INTERVAL, A2B_APP_TMRTOHANDLE_BECOVF_REPEAT_INTERVAL);
					a2b_timerStart(pApp_Info->hTmrToHandleBecovf);
				}
				/* If power fault was detected earlier clear flags and attempt count */
				if (pApp_Info->bfaultDone == A2B_TRUE)
				{
					pApp_Info->nDiscTryCnt = 0;
					pApp_Info->bfaultDone = A2B_FALSE;

				}
			}
			else
			{

				A2B_APP_LOG("\n\rDiscovery failed!\n\r");

				pApp_Info->discoverySuccessful = false;
				if (((results->resp.status & 0xFFFF) == A2B_EC_CUSTOM_NODE_ID_AUTH) || (results->resp.status & 0xFFFF) == A2B_EC_CUSTOM_NODE_ID_TIMEOUT)
				{
					/* Supplier id authentication failure */
					pApp_Info->faultNode = results->resp.numNodes;
					pApp_Info->bCustomAuthFailed = true;

				}
				if ((results->resp.status & 0xFFFF) == A2B_EC_PERMISSION)
				{
					/* Basic authentication failure */

					pApp_Info->faultNode = results->resp.numNodes;
					pApp_Info->bCustomAuthFailed = true;
					A2B_APP_LOG("Node Authentication failed\n\r");

				}
				/* Retry again if we are re-trying post power fault */
				if ((pApp_Info->bfaultDone == A2B_TRUE) && (pApp_Info->nDiscTryCnt < pApp_Info->pTargetProperties->nAttemptsCriticalFault))
				{
					pApp_Info->bRetry = A2B_TRUE;
				}
				/* If maximum attempts reached clear the post discovery fault flag */
				else if ((pApp_Info->bfaultDone == A2B_TRUE) && (pApp_Info->nDiscTryCnt == pApp_Info->pTargetProperties->nAttemptsCriticalFault))
				{
					pApp_Info->faultNode = results->resp.numNodes;
					pApp_Info->nDiscTryCnt = 0;
					pApp_Info->bfaultDone = A2B_FALSE;

				}
			}
		}

		/* Force the main loop to exit */
		discDone = A2B_TRUE;
	}
}

/*!****************************************************************************
 *
 *  \b               a2bapp_onPowerFault
 *
 *  The handler which receives power fault diagnostic notifications.
 *
 *  \param           [in]    msg         The diagnostic notification.
 *
 *  \param           [in]    userData    Not used
 *
 *
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          None
 *
 ******************************************************************************/
static void a2bapp_onPowerFault(struct a2b_Msg *msg, a2b_Handle userData)
{
	A2B_UNUSED(userData);
	a2b_PowerFault *fault;

	a2b_App_t * pAppInfo = (a2b_App_t*)userData;

	if (pAppInfo->discoveryDone)
	{
		A2B_APP_LOG("\n\r Post Discovery Line fault: ");

	}
	else
	{

		A2B_APP_LOG("\n\r Line fault During Discovery: ");

	}

	if (msg)
	{
		fault = (a2b_PowerFault *)a2b_msgGetPayload(msg);
		if (fault)
		{
			if (A2B_SUCCEEDED(fault->status))
			{
				switch (fault->intrType)
				{
					case A2B_ENUM_INTTYPE_PWRERR_CS_GND:
						pAppInfo->faultStatus = "Cable Shorted to GND";
						pAppInfo->faultCode = A2B_ENUM_INTTYPE_PWRERR_CS_GND;
						/* Add your code to handle fault */

						break;
					case A2B_ENUM_INTTYPE_PWRERR_CS_VBAT:
						pAppInfo->faultStatus = "Cable Shorted to VBat";
						pAppInfo->faultCode = A2B_ENUM_INTTYPE_PWRERR_CS_VBAT;
						/* Add your code to handle fault */

						break;
					case A2B_ENUM_INTTYPE_PWRERR_CS:
						pAppInfo->faultStatus = "Cable Shorted Together";
						pAppInfo->faultCode = A2B_ENUM_INTTYPE_PWRERR_CS;
						/* Add your code to handle fault */

						break;
					case A2B_ENUM_INTTYPE_PWRERR_CDISC:
						pAppInfo->faultStatus = "Cable Disconnected or Open Circuit";
						pAppInfo->faultCode = A2B_ENUM_INTTYPE_PWRERR_CDISC;
						/* Add your code to handle fault */

						break;
					case A2B_ENUM_INTTYPE_PWRERR_CREV:
						pAppInfo->faultStatus = "Cable Reverse Connected or Wrong Port";
						pAppInfo->faultCode = A2B_ENUM_INTTYPE_PWRERR_CREV;
						/* Add your code to handle fault */

						break;
					case A2B_ENUM_INTTYPE_PWRERR_FAULT:
						pAppInfo->faultStatus = "Indeterminate Fault";
						pAppInfo->faultCode = A2B_ENUM_INTTYPE_PWRERR_CREV;
						/* Add your code to handle fault */

						break;
					case A2B_ENUM_INTTYPE_PWRERR_NLS_GND:
						pAppInfo->faultStatus = "Non-Localized Short to GND";
						pAppInfo->faultCode = A2B_ENUM_INTTYPE_PWRERR_NLS_GND;
						/* Add your code to handle fault */

						break;
					case A2B_ENUM_INTTYPE_PWRERR_NLS_VBAT:
						pAppInfo->faultStatus = "Non-Localized Short to VBat";
						pAppInfo->faultCode = A2B_ENUM_INTTYPE_PWRERR_NLS_VBAT;
						/* Add your code to handle fault */

						break;
					case A2B_ENUM_INTTYPE_STRTUP_ERR_RTF:
						pAppInfo->faultStatus = "Startup Error - Return to Factory";
						pAppInfo->faultCode = A2B_ENUM_INTTYPE_STRTUP_ERR_RTF;
						/* Add your code to handle fault */

						break;
					default:
						pAppInfo->faultStatus = "Unknown";
						pAppInfo->faultCode = 0xFF;
						/* Add your code to handle fault */

						break;
				}

				/* Set flags to indicate fault post discovery */
				pAppInfo->bfaultDone = A2B_TRUE;
				pAppInfo->bRetry = A2B_TRUE;

				pAppInfo->faultNode = fault->faultNode;

				if (fault->faultNode < 0)
				{
					A2B_APP_LOG("Fault detected on Master node: ");

				}
				else
				{

					A2B_APP_LOG("Fault detected on Slave node %d: ", fault->faultNode);

				}

				A2B_APP_LOG("%s\n\r", pAppInfo->faultStatus);

			}
			else
			{
				A2B_APP_LOG("\n\r Power diagnostic failure ");
			}
		}
	}

	if (pAppInfo->discoveryDone)
	{
		/* Set flags to indicate fault post discovery */
		/* Possibly a node has dropped off the network.. try finding it out */
		a2b_AppDetectBusDrop(pAppInfo);

		/***********************************************************/
		/* Add your custom post discovery fault and link code here */
		/***********************************************************/

		if (pAppInfo->bBusDropDetected == true)
		{


		}


	}


}

#ifdef A2BAPP_LINK_STATICALLY
/*!****************************************************************************
 *
 *  \b               a2bapp_pluginsLoad
 *
 *  If the application is linked statically to its plugins then this
 *  function overrides the default PAL version of this function which loads
 *  plugins dynamically. Instead this function initializes the plugins that
 *  are statically linked to the application.
 *
 *  \param           [in,out]    plugins     A pointer to an array plugins that
 *                                           this function will allocate and
 *                                           return.
 *
 *  \param           [in,out]    numPlugins  This will be assigned the number
 *                                           of plugins that have been
 *                                           loaded and initialized.
 *
 *  \param           [in]        ecb         The environment control block
 *                                           for the A2B stack.
 *
 *  \pre             None
 *
 *  \post            None
 *
 *  \return          A status code that can be checked with the A2B_SUCCEEDED()
 *                   or A2B_FAILED() macro for success or failure of the
 *                   request.
 *
 ******************************************************************************/
a2b_HResult a2bapp_pluginsLoad(struct a2b_PluginApi** plugins, a2b_UInt16* numPlugins, A2B_ECB* ecb)
{
	struct a2b_PluginApi *appPlugins;
	int i = 0;

	A2B_UNUSED(ecb);
	appPlugins = calloc(gpApp_Info[ecb->palEcb.nChainIndex]->bdd.nodes_count, sizeof(**plugins));

	A2B_MASTER_PLUGIN_INIT(&appPlugins[0]);
	A2B_APP_DBG_LOG("Master plugin load done \r\n");

	for (i = 1; i < (gpApp_Info[ecb->palEcb.nChainIndex]->bdd.nodes_count); i++)
	{
		A2B_SLAVE_PLUGIN_INIT(&appPlugins[i]);
	}

	A2B_APP_DBG_LOG("Slave plugins load done \r\n");

	*plugins = appPlugins;
	*numPlugins = gpApp_Info[ecb->palEcb.nChainIndex]->bdd.nodes_count;

	return 0u;
}

/*!****************************************************************************
 *
 *  \b               a2bapp_pluginsUnload
 *
 *  If the application is linked statically to its plugins then this
 *  function overrides the default PAL version of this function which unloads
 *  plugins dynamically. Instead this function deallocates the plugins that
 *  are statically linked to the application.
 *
 *  \param           [in]        plugins     A pointer to an array plugins that
 *                                           this function will deallocate.
 *
 *  \param           [in]        numPlugins  The number of plugins in the array.
 *
 *  \param           [in]        ecb         The environment control block
 *                                           for the A2B stack.
 *
 *  \pre             None
 *
 *  \post            The plugins are unloaded and destroyed after this call.
 *
 *  \return          A status code that can be checked with the A2B_SUCCEEDED()
 *                   or A2B_FAILED() macro for success or failure of the
 *                   request.
 *
 ******************************************************************************/
a2b_HResult a2bapp_pluginsUnload(struct a2b_PluginApi* plugins, a2b_UInt16 numPlugins, A2B_ECB* ecb)
{
	A2B_UNUSED(numPlugins);
	A2B_UNUSED(ecb);

	free(plugins);
	return 0u;
}
#endif

/*!****************************************************************************
 *
 *  \b               a2b_app_handle_becovf
 *
 *  The routine to periodically reset BECNT and BECOVF registers
 *
 *
 *  \pre             pParam
 *
 *  \post            None
 *
 *  \return          None
 *
 ******************************************************************************/
static void a2b_app_handle_becovf(void* pParam)
{
	a2b_App_t* pApp_Info;
	a2b_Timer* pTimer;

	pTimer = (a2b_Timer*)pParam;
	pApp_Info = (a2b_App_t*)(pTimer->userData);

	if ((pApp_Info->pTargetProperties->bLineDiagnostics) && (pApp_Info->bfaultDone == false))
	{
		/* Reset the BECNT register for every call back of the timer */
		if (a2b_diagWriteReg(pApp_Info->ctx, A2B_NODEADDR_NOTUSED, A2B_REG_BECNT, A2B_REG_BECNT_RESET) != 0)
		{
			/* reset now to force a bus drop check */
			pApp_Info->nBecovfRstCnt = A2B_BUS_DROP_CHK_PERIOD;
		}
		else
		{
			pApp_Info->nBecovfRstCnt++;
		}

		/* Check for bus drop periodically */
		if ((pApp_Info->nBecovfRstCnt % A2B_BUS_DROP_CHK_PERIOD == 0) && (pApp_Info->bBusDropDetected == false))
		{
			pApp_Info->nBecovfRstCnt = 0;
			a2b_AppDetectBusDrop(pApp_Info);
		}
	}
}

/********************************************************************************/
/*!
* \b a2b_AppDetectBusDrop
*
*  This function reads the Vendor Id register of all A2B nodes discovered
* and declares a bus drop at a particular node where the read value is not the expected.
*
* @param [in] pApp_Ctx				Application Context Info
*
* @return	0 on Success
*            1 on Failure
* */
/***********************************************************************************/
static a2b_HResult a2b_AppDetectBusDrop(a2b_App_t *pApp_Info)
{
	a2b_UInt32 i;
	a2b_UInt8 nVal;
	a2b_HResult nRet = 0;
	/* Let us detect bus drop fault */
	for (i = 0; i < pApp_Info->bdd.nodes_count; i++)
	{
		nVal = 0;
		nRet = a2b_AppReadReg(pApp_Info->ctx, (i - 1), A2B_REG_VENDOR, &nVal);
		if (nVal != 0xAD)
		{
			pApp_Info->faultNode = (i - 1);
			pApp_Info->bBusDropDetected = true;

			pApp_Info->bfaultDone = A2B_TRUE;
			pApp_Info->bRetry = A2B_TRUE;

			A2B_APP_LOG("\n\r Bus Drop Detected @ Node: %d", i-1);

			break;
		}
	}
	return (nRet);
}

/********************************************************************************/
/*!
 \b a2b_AppReadReg

 This function  reads a register value of a particular A2B node

 @param [in] ctx				Stack Context
 @param [in] nodeAddr		Application context Information
 @param [in] reg				A2B register address
 @param [out] value			Value

 @return	0 on Success
 1 on Failure
 */
/***********************************************************************************/
static a2b_HResult a2b_AppReadReg(struct a2b_StackContext* ctx, a2b_Int16 nodeAddr, a2b_UInt8 reg, a2b_UInt8* value)
{
	a2b_HResult result = A2B_RESULT_SUCCESS;
	a2b_Byte wBuf[1];
	struct a2b_StackContext* mCtx;

	/* Need a master plugin context to do I2C calls */
	mCtx = (a2b_StackContext*)a2b_stackContextFind(ctx, A2B_NODEADDR_MASTER);
	if ( A2B_NULL == mCtx)
	{
		/* This should *never* happen */
		result = A2B_MAKE_HRESULT(A2B_SEV_FAILURE, A2B_FAC_DIAG, A2B_EC_INTERNAL);
	}
	else
	{
		wBuf[0] = reg;

		if ( A2B_NODEADDR_MASTER == nodeAddr)
		{
			result = a2b_i2cMasterWriteRead(mCtx, 1u, &wBuf[0u], 1u, value);
		}
		/* Else a write/read to a single slave node */
		else
		{
			result = a2b_i2cSlaveWriteRead(mCtx, nodeAddr, 1u, &wBuf[0u], 1u, value);

		}
	}

	return (result);
}
#ifdef ENABLE_INTRRUPT_PROCESS
/********************************************************************************/
/*!
 @brief This function process a2b interrupts

 @param [in] void				Stack Context


 @return	0 on Success
 1 on Failure
 */
/***********************************************************************************/
static a2b_HResult a2b_processIntrpt(a2b_App_t *pApp_Info)
{
	 a2b_HResult nResult = 0;
	 if(pApp_Info->bIntrptLatch == 1u)
	 {
		 pApp_Info->bIntrptLatch = 0u;
		 nResult = a2b_intrQueryIrq(pApp_Info->ctx);
	 }
	 return nResult;

}
#endif

#ifdef A2B_THIRD_PARTY
/********************************************************************************/
/*!
 @brief 		This function  attempts to load a BDD stored as a binary Protobuf encoded file
 from 'bddPath' and decodes it into the BDD structure. If no BDD path
 is provided then the built-in BDD is decoded.

 @param [in]   bddPath 	The (optional) path to a Protobuf formatted binary BDD file.
 If the default internal BDD should be used then this should be set to A2B_NULL.
 @param [out]  bdd		Pointer to the BDD structure that will be initialized with the decoded
 Protobuf formatted binary BDD.

 @return		A2B_TRUE on Success
 A2B_FALSE on failure
 */
/***********************************************************************************/
static a2b_Bool a2b_loadBdd ( const a2b_Char* bddPath, bdd_Network* bdd)
{
	a2b_Bool bIsError = A2B_FALSE;
	a2b_Byte* a2bNetwork = (a2b_Byte*)gA2bNetwork;
	a2b_UInt32 a2bNetworkLen = gA2bNetworkLen;
	a2b_UInt32 nRead;
	FILE* fp = A2B_NULL;

	if ( A2B_NULL != bddPath )
	{
		if ( !bIsError )
		{

			fp = fopen(bddPath, "r");
			if ( A2B_NULL == fp )
			{
				bIsError = A2B_TRUE;
			}
		}
		if ( !bIsError )
		{
			fseek(fp, 0L, SEEK_END);
			a2bNetworkLen = ftell(fp);
			a2bNetwork = malloc(a2bNetworkLen);
			if ( a2bNetwork == A2B_NULL )
			{
				bIsError = A2B_TRUE;
			}
			fseek(fp, 0L, SEEK_SET);
		}

		if ( !bIsError )
		{
			nRead = fread(a2bNetwork, 1, a2bNetworkLen, fp);
			if ( a2bNetworkLen != nRead )
			{
				bIsError = A2B_TRUE;
			}
		}
	}

	/* If no error so far then try to decode the BDD binary */
	if ( !bIsError )
	{
		if ( !a2b_bddDecode(a2bNetwork, a2bNetworkLen, bdd) )
		{
			bIsError = A2B_TRUE;
		}
	}

	/*
	 * Clean up resources that may have been allocated
	 */
	if ( A2B_NULL != fp )
	{
		fclose(fp);
	}

	/* We we allocated the buffer from the heap then ... */
	if ( a2bNetwork != (a2b_Byte*)gA2bNetwork )
	{
		free(a2bNetwork);
	}

	return !bIsError;
}
#endif

#ifdef __ADSPBF7xx__
/*!****************************************************************************
 *
 *  \b              a2bapp_initTdmSettings
 *
 *  Initialize the TDM Settings from bdd.
 *
 *  \param          [in]    ecb	pointer to ECB structure
 *  \param          [in]    bdd	pointer to BDD network
 *
 *  \pre            None
 *
 *  \post           None
 *
 *  \return         None
 *
 ******************************************************************************/
static void a2bapp_initTdmSettings(A2B_ECB* ecb, const bdd_Network* bdd)
{
	a2b_TdmSettings *pTdmSettings;
	const bdd_Node *pBddNodeObj;
	a2b_UInt32 nReg;

	memset(&ecb->palEcb.oTdmSettings, 0u, sizeof(a2b_TdmSettings));

	pTdmSettings = &ecb->palEcb.oTdmSettings;
	pBddNodeObj = &bdd->nodes[0u];

	/* Only few TDM settings are being populated below as not all are being used to configure the SOC and A2B SPORT's */
	switch (pBddNodeObj->i2cI2sRegs.i2sgcfg & A2B_BITM_I2SGCFG_TDMMODE)
	{
		case A2B_ENUM_I2SGCFG_TDM2:
		pTdmSettings->tdmMode = 2u;
		break;
		case A2B_ENUM_I2SGCFG_TDM4:
		pTdmSettings->tdmMode = 4u;
		break;
		case A2B_ENUM_I2SGCFG_TDM8:
		pTdmSettings->tdmMode = 8u;
		break;
		case A2B_ENUM_I2SGCFG_TDM16:
		pTdmSettings->tdmMode = 16u;
		break;
		case A2B_ENUM_I2SGCFG_TDM32:
		pTdmSettings->tdmMode = 32u;
		break;
		default:
		pTdmSettings->tdmMode = 2u;
		break;
	}

	nReg = pBddNodeObj->i2cI2sRegs.i2sgcfg;
	pTdmSettings->slotSize = (nReg & A2B_BITM_I2SGCFG_TDMSS ) ? 16u : 32u;
	pTdmSettings->halfCycle = (a2b_Bool)(( nReg & A2B_BITM_I2SGCFG_ALT ) == A2B_ENUM_I2SGCFG_ALT_EN );
	pTdmSettings->prevCycle = (a2b_Bool)(( nReg & A2B_BITM_I2SGCFG_EARLY ) == A2B_ENUM_I2SGCFG_EARLY_EN );
	pTdmSettings->fallingEdge = (a2b_Bool)(( nReg & A2B_BITM_I2SGCFG_INV ) == A2B_ENUM_I2SGCFG_INV_EN );

	nReg = pBddNodeObj->i2cI2sRegs.i2scfg;
	pTdmSettings->rx.invertBclk = (a2b_Bool)(( nReg & A2B_BITM_I2SCFG_RXBCLKINV ) == A2B_ENUM_I2SCFG_RXBCLKINV_EN );
	pTdmSettings->rx.interleave = (a2b_Bool)(( nReg & A2B_BITM_I2SCFG_RX2PINTL ) == A2B_ENUM_I2SCFG_RX2PINTL_EN );
	pTdmSettings->rx.pinEnabled = (a2b_UInt8)((nReg & (A2B_BITM_I2SCFG_RX1EN | A2B_BITM_I2SCFG_RX0EN)) >> A2B_BITP_I2SCFG_RX0EN);

	pTdmSettings->tx.invertBclk = (a2b_Bool)(( nReg & A2B_BITM_I2SCFG_TXBCLKINV ) == A2B_ENUM_I2SCFG_TXBCLKINV_EN );
	pTdmSettings->tx.interleave = (a2b_Bool)(( nReg & A2B_BITM_I2SCFG_TX2PINTL ) == A2B_ENUM_I2SCFG_TX2PINTL_EN );
	pTdmSettings->tx.pinEnabled = (a2b_UInt8)((nReg & (A2B_BITM_I2SCFG_TX1EN | A2B_BITM_I2SCFG_TX0EN)) >> A2B_BITP_I2SCFG_TX0EN);
}
#endif  /* __ADSPBF7xx__ */

/**
 @}
*/

/**
 @}
*/


/*
**
** EOF: $URL$
**
*/

