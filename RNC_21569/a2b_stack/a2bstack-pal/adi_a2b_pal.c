/*******************************************************************************
Copyright (c) 2017 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
*******************************************************************************

   Name       : adi_a2b_pal.c
   
   Description: This file is responsible for handling all TWI related functions.        
                 
   Functions  : a2b_I2cInit()
                a2b_I2cOpenFunc()
                a2b_I2cCloseFunc()
                a2b_I2cReadFunc()
                a2b_I2cWriteFunc()
                a2b_I2cWriteReadFunc()
                a2b_I2cShutdownFunc()
               
                 
   Prepared &
   Reviewed by: Automotive Software and Systems team, 
                IPDC, Analog Devices,  Bangalore, India
                
   @version: $Revision: 3626 $
   @date: $Date: 2015-10-05 14:04:13 +0530 (Mon, 05 Oct 2015) $
               
******************************************************************************/
/*! \addtogroup Target_Dependent Target Dependent
 *  @{
 */

/** @defgroup PAL
 *
 * This module handles all the pal CB wrappers for the underlying target
 * platform
 *
 */

/*! \addtogroup PAL
 *  @{
 */


/*============= I N C L U D E S =============*/

#include "platform/a2b/ctypes.h"
#include <string.h>
#include <sys/platform.h>
#include <stdio.h>
#include <errno.h>
#include "adi_a2b_datatypes.h"
#include "adi_a2b_framework.h"
#include "adi_a2b_externs.h"
#include "adi_a2b_twidriver.h"
#include "adi_a2b_timer.h"
#include "adi_a2b_driverprototypes.h"
#include "a2bplugin-slave/inc/a2bplugin-slave/adi_a2b_periconfig.h"
#include "a2bstack/inc/a2b/stack.h"
#include "a2bstack/inc/a2b/util.h"
#include "platform/a2b/conf.h"
#include "a2bstack/inc/a2b/i2c.h"
#include "a2bapp_sc58x.h"
#include "adi_a2b_pal.h"
#include "adi_a2b_sys.h"
#include "adi_a2b_audiorouting.h"
#include "adi_a2b_sportdriver.h"

/*============= D E F I N E S =============*/

/*! Maximum number application sub buffers */
#define A2B_MAX_APPBUFFER			(4u)

/*! Use on board codec for audio */
#define A2B_USE_CODEC				(1u)

/*! Bi directional SPORT to be used to communicate with AD2410 */
#define A2B_AD24xx_RXSPORT			(0u)
#define A2B_AD24xx_TXSPORT			(3u)

/*! Bi directional SPORT to be used to communicate with AD2410 */
#define A2B_CODEC_RXSPORT				(1u)
#define A2B_CODEC_TXSPORT				(4u)

/*============= D A T A =============*/

static a2b_PalEcb* pTimerEcb;

/*!\var adi_twi_hDevice
 TWI driver handle */
ADI_TWI_HANDLE adi_twi_hDevice;

/*!\var oTWITimer
 Timer object for TWI */
static ADI_A2B_TIMER_HANDLER oTWITimer;

/*!\var nBufferProcessCount
 Number of processed buffers  */
static volatile a2b_UInt8 nBufferProcessCount = 0;

/*!\var nExpectedCallbackCount
 Total number of expected callbacks */
static a2b_UInt8 nExpectedCallbackCount = 0;

static a2b_Bool bA2BSportOpen=false;


/*=============================================================================
 *				Audio
 */

typedef struct
{
	ADI_A2B_SCOMM_HANDLER oAudioCommHandler;
	ADI_SPORT_PERI_CONFIG oAD24xxRxSportConfig;
	ADI_SPORT_PERI_CONFIG oCodecRxSportConfig;
	ADI_SPORT_PERI_CONFIG oAD24xxTxSportConfig;
	ADI_SPORT_PERI_CONFIG oCodecTxSportConfig;
}adi_a2b_audio;

adi_a2b_audio goA2bAudio;

/*! Upstream data processing buffer   */
static a2b_UInt32 ganUpstreamProcessBuffer[A2B_MAX_APPBUFFER][MAX_NUM_INPUT_ANALOG_CHANNELS][SPORT_BUFFER_SIZE];
/*! ADC data processing buffer   */
static a2b_UInt32 ganADCProcessBuffer[A2B_MAX_APPBUFFER][MAX_NUM_INPUT_ANALOG_CHANNELS][SPORT_BUFFER_SIZE];

/*============= C O D E =============*/
/*
** Function Prototype section
*/

static ADI_SPORT_RESULT adi_a2b_EnableAudioHost(void);

static a2b_UInt8 adi_a2b_TwiWriteComplete(a2b_UInt8 nTWIDeviceNo);
static a2b_UInt8 adi_a2b_TwiReadComplete(a2b_UInt8 nTWIDeviceNo);
static a2b_UInt32 adi_a2b_HandleError(a2b_UInt8 nTWIDeviceNo ,  a2b_UInt8 bComplete );

static void adi_a2b_TimerCallback(ADI_A2B_TIMER_HANDLER_PTR pTimerHandle);

static void adi_a2b_TWICallbackFunction(void* pCBParam, a2b_UInt32 Event, void* pArg);
static void adi_a2b_TWITimeoutHandler(ADI_A2B_TIMER_HANDLER_PTR pTWITimerHandlePtr);

static void adi_a2b_DACTxCallback(void* pCommHandle, a2b_UInt32* pTxBufferPtr, a2b_UInt32 nChannel);
static void adi_a2b_ADCRxCallback(void* pCommHandle, a2b_UInt32* pRxBufferPtr, a2b_UInt32 nChannel);
static void adi_a2b_DownStreamTxCallback(void* pCommHandle, a2b_UInt32* pTxBufferPtr, a2b_UInt32 nChannel);
static void adi_a2b_UpstreamRxCallback(void* pCommHandle, a2b_UInt32 pRxBufferPtr[], a2b_UInt32 nChannel);

static void adi_a2b_upstreamToDwnRouting(ADI_A2B_SCOMM_HANDLER* pAudioRoutingHandle, a2b_UInt32 anDwnstreamBuffer[], a2b_UInt32 anUpstreamBuffer[][SPORT_BUFFER_SIZE], a2b_UInt32 nChannel );
#if A2B_USE_CODEC
static void adi_a2b_ADCToDwnRouting(ADI_A2B_SCOMM_HANDLER* pAudioRoutingHandle, a2b_UInt32 anDwnstreamBuffer[], a2b_UInt32 anADCBuffer[][SPORT_BUFFER_SIZE], a2b_UInt32 nChannel );
static void adi_a2b_UpstreamToDACRouting(ADI_A2B_SCOMM_HANDLER* pAudioRoutingHandle, a2b_UInt32 anDACBuffer[], a2b_UInt32 anUpstreamBuffer[][SPORT_BUFFER_SIZE], a2b_UInt32 nChannel );
static void adi_a2b_ADCToDACRouting(ADI_A2B_SCOMM_HANDLER* pAudioRoutingHandle, a2b_UInt32 anDACBuffer[], a2b_UInt32 anADCBuffer[][SPORT_BUFFER_SIZE], a2b_UInt32 nChannel);
#endif
static void adi_a2b_DeInterleaveCopy( a2b_UInt32 anDesbuffer[][SPORT_BUFFER_SIZE], a2b_UInt32 anSrcBuffer[], a2b_UInt32 nChannel );
/*
** Function Definition section
*/

/*!****************************************************************************
*
*  \b              a2b_palInit
*
*  <b> API Details: </b><br>
*  Initializes the Platform Abstraction Layer (PAL) structure [function
*  pointers] with defaults for the given platform. These defaults can be
*  over-ridden as needed if necessary.
*                                                                       <br><br>
*  <b> Linux Implementation Details: </b><br>
*  This sets up all the function pointers for core PAL functionality used
*  by the A2B stack.  If A2B_FEATURE_MEMORY_MANAGER is NOT defined then
*  Linux malloc/free is used instead of the stack memory manager.  This
*  also implements some environment variable support for Linux:             <br>
*  - A2B_CONF_TRACE_CHAN_URL                                                <br>
*  - A2B_CONF_TRACE_LEVEL                                                   <br>
*  - A2B_CONF_I2C_DEVICE_PATH                                               <br>
*  - A2B_CONF_PLUGIN_SEARCH_PATTERN                                         <br>
*                                                                           <br>
*  \param          [in]    pal      Pointer to the Platform Abstraction Layer to
*                                   initialize with defaults.
*
*  \param          [in]    ecb      The environment control block (ecb) for
*                                   this platform.
*
*  \pre            None
*
*  \post           The pal function pointer API will be fully
*                  populated with default values.
*
*  \return         None
*
******************************************************************************/
void
a2b_palInit
    (
    struct a2b_StackPal*    pal,
    A2B_ECB*                ecb
    )
{

    if ( A2B_NULL != pal )
    {
        a2b_memset(pal, 0, sizeof(*pal));
        a2b_memset(ecb, 0, sizeof(*ecb));

        /* Do necessary base initialization */
        a2b_stackPalInit(pal, ecb);

#ifndef A2B_FEATURE_MEMORY_MANAGER
        /* Use Linux malloc/free */
        pal->memMgrInit      = a2b_pal_memMgrInit;
        pal->memMgrOpen      = a2b_pal_memMgrOpen;
        pal->memMgrMalloc    = a2b_pal_memMgrMalloc;
        pal->memMgrFree      = a2b_pal_memMgrFree;
        pal->memMgrClose     = a2b_pal_memMgrClose;
        pal->memMgrShutdown  = a2b_pal_memMgrShutdown;
#endif

        pal->timerInit       = a2b_pal_TimerInitFunc;
        pal->timerGetSysTime = a2b_pal_TimerGetSysTimeFunc;
        pal->timerShutdown   = a2b_pal_TimerShutdownFunc;

#if defined(A2B_FEATURE_SEQ_CHART) || defined(A2B_FEATURE_TRACE)
        pal->logInit         = a2b_pal_logInit;
        pal->logOpen         = a2b_pal_logOpen;
        pal->logClose        = a2b_pal_logClose;
        pal->logWrite        = a2b_pal_logWrite;
        pal->logShutdown     = a2b_pal_logShutdown;
#endif

        pal->i2cInit         = a2b_pal_I2cInit;
        pal->i2cOpen         = a2b_pal_I2cOpenFunc;
        pal->i2cClose        = a2b_pal_I2cCloseFunc;
        pal->i2cRead         = a2b_pal_I2cReadFunc;
        pal->i2cWrite        = a2b_pal_I2cWriteFunc;
        pal->i2cWriteRead    = a2b_pal_I2cWriteReadFunc;
        pal->i2cShutdown     = a2b_pal_I2cShutdownFunc;

        pal->audioInit       = a2b_pal_AudioInitFunc;
        pal->audioOpen       = a2b_pal_AudioOpenFunc;
        pal->audioClose      = a2b_pal_AudioCloseFunc;
        pal->audioConfig     = a2b_pal_AudioConfigFunc;
        pal->audioShutdown   = a2b_pal_AudioShutdownFunc;

        pal->pluginsLoad     = a2bapp_pluginsLoad;
        pal->pluginsUnload   = a2bapp_pluginsUnload;

        pal->getVersion      = a2b_pal_infoGetVersion;
        pal->getBuild        = a2b_pal_infoGetBuild;

        if ( A2B_NULL != ecb )
        {
            ecb->baseEcb.i2cAddrFmt    = A2B_I2C_ADDR_FMT_7BIT;
            ecb->baseEcb.i2cBusSpeed   = A2B_I2C_BUS_SPEED_100KHZ;
            ecb->baseEcb.i2cMasterAddr = A2B_CONF_DEFAULT_MASTER_NODE_I2C_ADDR;
        }
    }
} /* a2b_palInit */

/*****************************************************************************/
/*!
@brief  This API initializes I2C subsystem.

@param [in]:ecb  - PAL ECB structure.
  
    
@return Return code
        -1: Failure
        -0: Success
        
\note I2C and TWI terms are used  interchangeably        
  
*/   
/*****************************************************************************/
ADI_MEM_A2B_CODE_NO_CRIT
a2b_UInt32 a2b_pal_I2cInit(A2B_ECB* ecb)
{
    A2B_UNUSED( ecb );

    return A2B_RESULT_SUCCESS;
}

/*****************************************************************************/
/*!
@brief  This API Post Initialization of I2C subsystem and
        returns the handle

@param [in]:fmt  - 7-bit or 10-bit address.
@param [in]:speed  - I2C Bus Speed.
@param [in]:ecb  - PAL ECB structure.

@return Return code
			Handle to the I2C module

*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_NO_CRIT
a2b_Handle a2b_pal_I2cOpenFunc(a2b_I2cAddrFmt fmt,
        a2b_I2cBusSpeed speed, A2B_ECB* ecb)
{
    A2B_UNUSED( fmt );

    a2b_UInt32		nReturnValue = (a2b_UInt32)0;
	ADI_TWI_RESULT eTwiResult = ADI_TWI_SUCCESS;
	a2b_UInt32 	nTWIDeviceNo,nDummy;
	static uint8_t ganTwiDriverMemory[ADI_TWI_MEMORY_SIZE];		 /*!< TWI driver memory */

	nTWIDeviceNo = A2B_TWI_NO;

	/* open the TWI0 driver in master mode */
	eTwiResult = adi_twi_Open(nTWIDeviceNo, ADI_TWI_MASTER, ganTwiDriverMemory, ADI_TWI_MEMORY_SIZE, &adi_twi_hDevice);

	if( speed == A2B_I2C_BUS_SPEED_100KHZ)
	{
		/* Set bit rate of TWI0 to 100 kHz */
		eTwiResult = adi_twi_SetBitRate (adi_twi_hDevice, A2B_TWI_RATE_100);
	}

	else if (speed == A2B_I2C_BUS_SPEED_400KHZ)
	{
		eTwiResult = adi_twi_SetBitRate (adi_twi_hDevice, A2B_TWI_RATE_400);
	}

	/* Set Duty cycle of TWI0 to 50 */
	eTwiResult = adi_twi_SetDutyCycle (adi_twi_hDevice, 50u);

	/* Set the pre-scaler for TWI0 to 10u */
	eTwiResult = adi_twi_SetPrescale (adi_twi_hDevice, 12u);

	eTwiResult = adi_twi_RegisterCallback(adi_twi_hDevice,(ADI_CALLBACK)&adi_a2b_TWICallbackFunction, (void*)0u);

	oTWITimer.nTimerNo = TWI_TIMER;
	nDummy = (a2b_UInt32)&adi_a2b_TWITimeoutHandler;
	oTWITimer.pCallbackhandle = (TIMER_CALL_BACK)nDummy;

	nReturnValue = adi_a2b_TimerOpen(oTWITimer.nTimerNo,(void *)&oTWITimer);
	if(nReturnValue != 0)
	{
		return ((void*)0);
	}

	if(eTwiResult == 0)
	{
		ecb->palEcb.i2chnd = &adi_twi_hDevice;
		return ((void*)&adi_twi_hDevice);
	}
	else
	{
		return ((void*)0);
	}
}

/****************************************************************************/
/*!
    @brief          This function handles TWI timeout event. It sets 'Timeout' flag

    @param [in]     pTWITimerHandlePtr  Pointer to TWI Timer configuration structure

    @return         none
*/
/*******************************************************************************/
static void adi_a2b_TWITimeoutHandler(ADI_A2B_TIMER_HANDLER_PTR pTWITimerHandlePtr)
{


#if TIME_OUT_ENABLE
    pTWITimerHandlePtr->bTimeout = 1u;
#endif
    /* Reset timer0 */
    adi_a2b_TimerStop(pTWITimerHandlePtr->nTimerNo);

}

/*****************************************************************************/
/*!
@brief  This API Reads a bytes of data from an I2C device

@param [in]:hnd  - Handle to the I2C Sub-system.
@param [in]:addr  - Device Address to which I2C communication
                    should happen.
@param [in]:nRead  - Number of bytes to be read.
@param [in]:rBuf  - Pointer to the buffer where read bytes are
                    to be stored.
@return Return code
        -1: Failure
        -0: Success

*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_CRIT
a2b_HResult a2b_pal_I2cReadFunc(a2b_Handle hnd,
        a2b_UInt16 addr, a2b_UInt16 nRead, a2b_Byte* rBuf)
{
    a2b_UInt32 					nReturnValue 	= (a2b_UInt32)0 ;
    ADI_TWI_RESULT 				eTwiResult 	;
    static a2b_UInt8 			nTWIData[4];
    a2b_UInt32 					nWCount    = 0u,nRCount;
    a2b_UInt32                  delay1 = 0xffff;

    nTWIData[nWCount++]=0x0;/*Read from offset 0 always */

    nRCount=nRead;

    eTwiResult = adi_twi_SetHardwareAddress (adi_twi_hDevice, addr);
    if(eTwiResult != 0)
    {
    	return (1);
    }

	/* Support for zero byte addressing */
	if(nWCount > 0u )
   	{
   		nExpectedCallbackCount++;
   		eTwiResult = adi_twi_SubmitTxBuffer(adi_twi_hDevice, (void *)&nTWIData[0U], nWCount, FALSE);
   		if(eTwiResult != 0)
		{
			return (1);
		}
   	}

   	eTwiResult = adi_twi_Enable(adi_twi_hDevice); //write/read i2c device
   	if(eTwiResult != 0)
	{
		return (1);
	}

   	while(delay1--)
	{
		NOP();
	}

   	nExpectedCallbackCount++;
	eTwiResult= adi_twi_SubmitRxBuffer(adi_twi_hDevice, (void *)rBuf, nRCount, FALSE);
	if(eTwiResult != 0)
	{
		return (1);
	}

	eTwiResult = adi_twi_Enable(adi_twi_hDevice); //write/read i2c device
	if(eTwiResult != 0)
	{
		return (1);
	}

	/* Start Timer */
	oTWITimer.bTimeout = (a2b_UInt8)0;
	nReturnValue = adi_a2b_TimerStart(TWI_TIMER,TWI_TIMEOUT_PERIOD*(nRCount + nWCount));

	while ( (!adi_a2b_TwiReadComplete(A2B_TWI_NO) ) && (!oTWITimer.bTimeout))
	{
	 /* Wait till time out or read complete */
	}
	nReturnValue = adi_a2b_TimerStop(TWI_TIMER);

	nReturnValue = adi_a2b_HandleError(A2B_TWI_NO, adi_a2b_TwiReadComplete(A2B_TWI_NO));

	return(nReturnValue);
}

/*****************************************************************************/
/*!
@brief  This API writes a bytes of data to an I2C device

@param [in]:hnd  - Handle to the I2C Sub-system.
@param [in]:addr  - Device Address to which I2C communication
                    should happen.
@param [in]:Write  - Number of bytes to be written.
@param [in]:wBuf  - Pointer to the buffer from where bytes are
                    to be written.
@return Return code
        -1: Failure
        -0: Success


*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_CRIT
a2b_HResult a2b_pal_I2cWriteFunc(a2b_Handle hnd,
        a2b_UInt16 addr, a2b_UInt16 nWrite,
        const a2b_Byte* wBuf)
{
	a2b_UInt32 			nReturnValue 	= (a2b_UInt32)0;
	ADI_TWI_RESULT 		eTwiResult 	;
    a2b_UInt32 			nIndex;
    a2b_UInt32 			nWCount    = 0u;
    static a2b_UInt8 	nTWIData[MAX_NUMBER_TWI_BYTES];

    for(nIndex=0;nIndex < nWrite; nIndex++)
    	nTWIData[nWCount++]=wBuf[nIndex];

    /* Submit buffer*/
      eTwiResult = adi_twi_SetHardwareAddress (adi_twi_hDevice, addr);
      if(eTwiResult != 0)
	  {
		return (1);
	  }

      eTwiResult = adi_twi_SubmitTxBuffer(adi_twi_hDevice, (void *)&nTWIData[0U], nWCount, FALSE );
      if(eTwiResult != 0)
	  {
		return (1);
	  }
      eTwiResult = adi_twi_Enable(adi_twi_hDevice);
      if(eTwiResult != 0)
	  {
		return (1);
	  }

      /* Start the timer */
      oTWITimer.bTimeout = (a2b_UInt8)0;
      nReturnValue = adi_a2b_TimerStart(TWI_TIMER,TWI_TIMEOUT_PERIOD * nWCount);

      while ( (!adi_a2b_TwiWriteComplete(A2B_TWI_NO) ) && (!oTWITimer.bTimeout) )
      {
          /* Wait till time out or write complete */
      }
      nReturnValue = adi_a2b_TimerStop(TWI_TIMER);


      nReturnValue = adi_a2b_HandleError(A2B_TWI_NO , adi_a2b_TwiWriteComplete(A2B_TWI_NO));

      return(nReturnValue);
}

/*****************************************************************************/
/*!
@brief  This API writes a bytes of data to an I2C device

@param [in]:hnd  - Handle to the I2C Sub-system.
@param [in]:addr  - Device Address to which I2C communication
                    should happen.
@param [in]:nWrite  - Number of bytes to be written.
@param [in]:wBuf  - Pointer to the buffer from where bytes are
                    to be written.
@param [in]:nRead  - Number of bytes to be read.
@param [in]:rBuf  - Pointer to the buffer where read bytes are
                    to be stored.
@return Return code
        -1: Failure
        -0: Success

*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_CRIT
a2b_HResult a2b_pal_I2cWriteReadFunc(a2b_Handle hnd,
        a2b_UInt16 addr, a2b_UInt16 nWrite,
        const a2b_Byte* wBuf, a2b_UInt16 nRead,
        a2b_Byte* rBuf)
{
    a2b_UInt32			nReturnValue 	= (a2b_UInt32)0 ;
    ADI_TWI_RESULT 		eTwiResult 	;
    static a2b_UInt8 	nTWIData[8];
    a2b_UInt32 			nWCount = 0u, nRCount, nIndex;
    a2b_UInt32          delay1=0xffff;

	nReturnValue = ((a2b_UInt8)TRUE);

	for(nIndex=0;nIndex < nWrite; nIndex++)
	{
	   nTWIData[nWCount++]=wBuf[nIndex];
	}

	nRCount=nRead;

	eTwiResult = adi_twi_SetHardwareAddress (adi_twi_hDevice, addr);
	if(eTwiResult != 0)
	{
		return (1);
	}

   	/* Support for zero byte addressing */
   	if(nWCount > 0u )
   	{
   		nExpectedCallbackCount++;
   		eTwiResult = adi_twi_SubmitTxBuffer(adi_twi_hDevice, (void *)&nTWIData[0U], nWCount, FALSE);
   		if(eTwiResult != 0)
		{
			return (1);
		}
   	}

   	eTwiResult = adi_twi_Enable(adi_twi_hDevice);
   	if(eTwiResult != 0)
	{
		return (1);
	}

   	while(delay1--)
   	{
   		NOP();
   	}

	nExpectedCallbackCount++;
	eTwiResult= adi_twi_SubmitRxBuffer(adi_twi_hDevice, (void *)rBuf, nRCount, FALSE);
	if(eTwiResult != 0)
	{
		return (1);
	}

   	eTwiResult = adi_twi_Enable(adi_twi_hDevice);
   	if(eTwiResult != 0)
	{
		return (1);
	}

   	/* Start Timer */
   	oTWITimer.bTimeout = (a2b_UInt8)0;
   	nReturnValue = adi_a2b_TimerStart(TWI_TIMER,TWI_TIMEOUT_PERIOD*(nRCount + nWCount));

   	while ( (!adi_a2b_TwiReadComplete(A2B_TWI_NO) ) && (!oTWITimer.bTimeout))
   	{
   	 /* Wait till time out or read complete */
   	}
   	nReturnValue = adi_a2b_TimerStop(TWI_TIMER);

   	nReturnValue = adi_a2b_HandleError(A2B_TWI_NO, adi_a2b_TwiReadComplete(A2B_TWI_NO));

   	return(nReturnValue);
}

/****************************************************************************/
/*!
@brief  This function returns the TWI read completion status

@param [in]     nTWIDeviceNo  TWI device number

@return            Return code
                   - 1: Read is complete
                   - 0: Incomplete

*/
/*****************************************************************************/
static a2b_UInt8 adi_a2b_TwiReadComplete(a2b_UInt8 nTWIDeviceNo)
{
   a2b_UInt8 nReturnValue = 0u;

   if(nBufferProcessCount == nExpectedCallbackCount)
   {
   	nReturnValue = 1u;
   }
   return(nReturnValue);
}

/*****************************************************************************/
/*!
@brief      This function returns TWI write completion status

@param [in]    nTWIDeviceNo    TWI device number

@return        Return code
                    - 1: Write is complete
                    - 0: Incomplete

*/
/*****************************************************************************/
static a2b_UInt8 adi_a2b_TwiWriteComplete(a2b_UInt8 nTWIDeviceNo)
{
    a2b_UInt8 nReturnValue = 0u;

    if(nBufferProcessCount == 1u)
    {
    	nReturnValue = 1u;
    }

    return(nReturnValue);
}

/****************************************************************************/
/*!
@brief  This function handles error after TWI read/write is complete

@param [in]     nTWIDeviceNo  TWI device number

@return            Return code
                   - 1: Read is complete
                   - 0: Incomplete

*/
/*****************************************************************************/
static a2b_UInt32 adi_a2b_HandleError(a2b_UInt8 nTWIDeviceNo ,  a2b_UInt8 bComplete )
{
    a2b_UInt32 nRet = 0u;
    nExpectedCallbackCount = 0u;
    nBufferProcessCount = 0u;

    if(bComplete == 0u)
    {
#if A2B_PRINT_FOR_DEBUG
        printf(" \n TWI Transaction Failure  ");
        printf(" \n ");
#endif
        /* Return failure */
        nRet = 1u;
    }

    return(nRet);

}

/*****************************************************************************/
/*!
@brief  This API initializes I2C subsystem.

@param [in]:ecb  - PAL ECB structure.


@return Return code
        -1: Failure
        -0: Success

\note I2C and TWI terms are used  interchangeably

*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_NO_CRIT
a2b_UInt32 a2b_pal_I2cShutdownFunc(A2B_ECB* ecb)
{
    A2B_UNUSED( ecb );

    return A2B_RESULT_SUCCESS;
}


/*****************************************************************************/
/*!
@brief  This API Post Initialization of I2C subsystem and
        returns the handle

@param [in]:fmt  - 7-bit or 10-bit address.
@param [in]:speed  - I2C Bus Speed.
@param [in]:ecb  - PAL ECB structure.

@return Return code
			Success or Failure

*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_NO_CRIT
a2b_HResult a2b_pal_I2cCloseFunc(a2b_Handle hnd)
{
	a2b_UInt32		nResult = 0u;
	ADI_TWI_RESULT 	eTwiResult = ADI_TWI_SUCCESS;

	nResult = adi_a2b_TimerClose(TWI_TIMER);
	if(nResult != 0)
	{
		return (1);
	}
	eTwiResult = adi_twi_Close(adi_twi_hDevice);

	return (a2b_UInt32)eTwiResult;
}

/*****************************************************************************/
/*!
@brief  This API initializes Timer subsystem.

@param [in]:ecb  - PAL ECB structure.


@return Return code
        -1: Failure
        -0: Success

\note I2C and TWI terms are used  interchangeably

*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_NO_CRIT
a2b_HResult a2b_pal_TimerInitFunc(A2B_ECB* ecb)
{
	a2b_HResult 	nReturnValue = (a2b_UInt32)0;
    a2b_UInt32  	nDummy;

	pTimerEcb 	= &ecb->palEcb;
    nDummy 		= (a2b_UInt32)&adi_a2b_TimerCallback;

    ecb->palEcb.nCurrTime = 0u;
    ecb->palEcb.oTimerHandler.pCallbackhandle = (TIMER_CALL_BACK)nDummy;
    ecb->palEcb.oTimerHandler.nTimerExpireVal = 1000u;  /* One millisec counter */
    ecb->palEcb.oTimerHandler.nTimerNo = A2B_TIMER_NO;
    nReturnValue = adi_a2b_TimerOpen(ecb->palEcb.oTimerHandler.nTimerNo, &ecb->palEcb.oTimerHandler);
    if(nReturnValue == 0u)
    {
		nReturnValue = adi_a2b_TimerStart(ecb->palEcb.oTimerHandler.nTimerNo,
				ecb->palEcb.oTimerHandler.nTimerExpireVal);
    }
    return nReturnValue;
}

/*****************************************************************************/
/*!
@brief  This API gives the current system time

@return Return : Current time in millisec

\note I2C and TWI terms are used  interchangeably

*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_CRIT
a2b_UInt32 a2b_pal_TimerGetSysTimeFunc()
{
    return pTimerEcb->nCurrTime;
}

/****************************************************************************/
/*!
    @brief          A2B timer(timer1)call back function. It
                    is called from timer driver ISR.

    @param [in]     pTimerHandle    Pointer to Timer configuration structure

    @return         none
*/
/********************************************************************************/
ADI_MEM_A2B_CODE_CRIT
static void adi_a2b_TimerCallback(ADI_A2B_TIMER_HANDLER_PTR pTimerHandle)
{

	adi_a2b_TimerStop(pTimerEcb->oTimerHandler.nTimerNo);
	adi_a2b_TimerStart(pTimerEcb->oTimerHandler.nTimerNo,
			pTimerEcb->oTimerHandler.nTimerExpireVal);
    pTimerEcb->nCurrTime += 1u;
}

/*****************************************************************************/
/*!
@brief  This API shuts the Timer subsystem.

@param [in]:ecb  - PAL ECB structure.


@return Return code
        -1: Failure
        -0: Success

\note I2C and TWI terms are used  interchangeably

*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_NO_CRIT
a2b_HResult a2b_pal_TimerShutdownFunc(A2B_ECB* ecb)
{
	a2b_HResult nReturnValue = (a2b_UInt32)0;

	pTimerEcb = &ecb->palEcb;

	nReturnValue = adi_a2b_TimerStop(pTimerEcb->oTimerHandler.nTimerNo);
    nReturnValue = adi_a2b_TimerClose(pTimerEcb->oTimerHandler.nTimerNo);

	ecb->palEcb.nCurrTime = 0u;
	pTimerEcb->oTimerHandler.pCallbackhandle = NULL;
	pTimerEcb->oTimerHandler.nTimerExpireVal = 0u;  /* One millisec counter */

    return nReturnValue;
}

/*****************************************************************************/
/*!
@brief  This API Initializes the audio sub-system.

@param [in]:ecb  - PAL ECB structure.


@return Return code
        -1: Failure
        -0: Success

\note I2C and TWI terms are used  interchangeably

*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_NO_CRIT
a2b_HResult a2b_pal_AudioInitFunc(A2B_ECB* ecb)
{
	ADI_SPORT_RESULT 		eResult;
	ADI_A2B_SCOMM_HANDLER 	*pAudioCommHandler;
	ADI_SPORT_PERI_CONFIG 	*pCodecRxSportConfig;
	ADI_SPORT_PERI_CONFIG 	*pCodecTxSportConfig;

	a2b_UInt8 nReturn = 0xFFu;
	a2b_UInt8 nIndex;
	ADI_A2B_PERI_DEVICE_CONFIG* psDeviceConfig;
	ADI_A2B_NODE_PERICONFIG *psPeriConfig;
	a2b_UInt8 wBuf[2];
	a2b_UInt8 rBuf[8];
	int aResult;

	psPeriConfig = ecb->palEcb.pAudioHostDeviceConfig;

	/* Configuring the SigmaDSP so that it generates the BCLK.
	 * This BCLK is used as external CLK for ADSP-BF716 SPORT's
	 * */
	for(nIndex  = 0u; nIndex < (a2b_UInt8)psPeriConfig->nNumConfig; nIndex++)
	{//Configuring attach master peripheral ADAU1452 and ADAU1761
		psDeviceConfig = &psPeriConfig->aDeviceConfig[nIndex];
		//nReturn = (a2b_UInt8)adi_a2b_AudioHostConfig(ecb, psDeviceConfig);
	}

	pAudioCommHandler 		= &goA2bAudio.oAudioCommHandler;
	pCodecRxSportConfig		= &goA2bAudio.oCodecRxSportConfig;
	pCodecTxSportConfig		= &goA2bAudio.oCodecTxSportConfig;

	/* Initialization */
	pAudioCommHandler->pRoutingTable 			= gaAudioRoutingtab;
	pAudioCommHandler->nWordLength 				= 32u;
	pAudioCommHandler->nUpstrProcWriteIndex 	= 0u;
	pAudioCommHandler->nADCProcWriteIndex 		= 0u;
	pAudioCommHandler->nUpstrToDwnstrReadIndex 	= 1u;
	pAudioCommHandler->nADCToDwnstrReadIndex 	= 2u;
	pAudioCommHandler->nADCtoDACReadIndex 		= 1u;
	pAudioCommHandler->nUpStrtoDACReadIndex 	= 2u;

#if A2B_USE_CODEC
	/* Opened as pair, bidirectional format */
	pAudioCommHandler->nCodecTDMSize = 8u;

	pCodecRxSportConfig->nMultChDelay  			= 1;
	pCodecRxSportConfig->bActiveLowFrameSync 	= 0;
	pCodecRxSportConfig->nSamplingRisingClkEdge = 0u;
	pCodecRxSportConfig->eSportNum 				= ADI_A2B_HAL_SPORT_1;
	pCodecRxSportConfig->nTDMCh 				= pAudioCommHandler->nCodecTDMSize;
	pCodecRxSportConfig->eDirection 			= ADI_SPORT_DIR_RX;
	pCodecRxSportConfig->pfSPORTCallBack 		= (ADI_A2B_SPORT_CB)&adi_a2b_ADCRxCallback;
	pCodecRxSportConfig->nStChnlNo 				= 0;
	pCodecRxSportConfig->nEndChnlNo 			= 7U;
	pCodecRxSportConfig->eSportHalf 			= ADI_HALF_SPORT_A;

	pCodecTxSportConfig->nMultChDelay  			= 1;
	pCodecTxSportConfig->bActiveLowFrameSync 	= 0;
	pCodecTxSportConfig->nSamplingRisingClkEdge = 0u;
	pCodecTxSportConfig->eSportNum 				= ADI_A2B_HAL_SPORT_0;
	pCodecTxSportConfig->nTDMCh 				= pAudioCommHandler->nCodecTDMSize;
	pCodecTxSportConfig->eDirection 			= ADI_SPORT_DIR_TX;
	pCodecTxSportConfig->pfSPORTCallBack 		= (ADI_A2B_SPORT_CB)&adi_a2b_DACTxCallback;
	pCodecTxSportConfig->nStChnlNo 				= 0;
	pCodecTxSportConfig->nEndChnlNo 			= 7U;
	pCodecTxSportConfig->eSportHalf 			= ADI_HALF_SPORT_A;

    /* Configure Codec SPORT */
    adi_a2b_InitPCGForCodec();

    aResult = ADAU_1962_init();
    if(aResult != 0)
    {
    	eResult = ADI_SPORT_FAILED;
    }

//    eResult = adi_a2b_SerialPortOpen(A2B_CODEC_RXSPORT, pCodecRxSportConfig, (void*)pAudioCommHandler);
//    eResult = adi_a2b_SerialPortOpen(A2B_CODEC_TXSPORT, pCodecTxSportConfig, (void*)pAudioCommHandler);

#endif

	return (a2b_UInt32)eResult;
}



/*****************************************************************************/
/*!
@brief  This API Initializes the audio sub-system.

@param [in]:ecb  - PAL ECB structure.


@return Return code
        -1: Failure
        -0: Success

\note I2C and TWI terms are used  interchangeably

*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_NO_CRIT
a2b_Handle a2b_pal_AudioOpenFunc(void)
{
	return ((a2b_Handle*)&goA2bAudio);
}

/****************************************************************************/
/*!
    @brief          This function configures devices connected to slave node
                    through remote I2C

    @param [in]     pNode                   Pointer to A2B node
    @param [in]     psDeviceConfig          Pointer to peripheral device configuration structure

    @return          Return code
                    - 0: Success
                    - 1: Failure
*/
/********************************************************************************/
int adi_a2b_AudioHostConfig(A2B_ECB* ecb, ADI_A2B_PERI_DEVICE_CONFIG* psDeviceConfig)
{
	A2B_PAL_L1_DATA
    static a2b_UInt8 aDataBuffer[ADI_A2B_MAX_PERI_CONFIG_UNIT_SIZE];
    static a2b_UInt8 aDataWriteReadBuf[4u];

    a2b_UInt32 nReturn = 0u;
    ADI_A2B_PERI_CONFIG_UNIT* pOPUnit;
    a2b_UInt8 nIndex, nIndex1;
    a2b_UInt32 nNumOpUnits;
    a2b_UInt32 nDelayVal;
    a2b_Int16 nodeAddr;

    nNumOpUnits = psDeviceConfig->nNumPeriConfigUnit;

    for(nIndex= 0u ; nIndex < nNumOpUnits ; nIndex++ )
    {
        pOPUnit = &psDeviceConfig->paPeriConfigUnit[nIndex];
        /* Operation code*/
        switch(pOPUnit->eOpCode)
        {
           /* write */
            case 0u:
				adi_a2b_Concat_Addr_Data(&aDataBuffer[0u], pOPUnit->nAddrWidth, pOPUnit->nAddr);
				memcpy(&aDataBuffer[pOPUnit->nAddrWidth], pOPUnit->paConfigData, pOPUnit->nDataCount);

				a2b_pal_I2cWriteFunc(ecb->palEcb.i2chnd, (a2b_UInt16)psDeviceConfig->nDeviceAddress,
						(pOPUnit->nAddrWidth + pOPUnit->nDataCount), &aDataBuffer[0u]);
				break;
            /* read */
            case 1u:
				adi_a2b_Concat_Addr_Data(&aDataWriteReadBuf[0u], pOPUnit->nAddrWidth, pOPUnit->nAddr);
				a2b_pal_I2cWriteReadFunc(ecb->palEcb.i2chnd, (a2b_UInt16)psDeviceConfig->nDeviceAddress,
						pOPUnit->nAddrWidth, &aDataWriteReadBuf[0u],
						pOPUnit->nDataCount, &aDataBuffer[0u]);
				break;
            /* delay */
            case 2u:nDelayVal = 0u;
				for(nIndex1 = 0u; nIndex1 < pOPUnit->nDataCount; nIndex1++)
				{
					nDelayVal = (pOPUnit->paConfigData[nIndex1] << (8u * nIndex1)) | nDelayVal;
				}
				(void)adi_a2b_Delay(nDelayVal);
				break;
            default:
            	break;
        }

        if(nReturn !=0u)
        {
            break;
        }
    }

    return(nReturn);
}

/*****************************************************************************/
/*!
@brief  This API configures the audio sub-system based on the Master
        TDM settigns

@param [in]:ecb  - PAL ECB structure.


@return Return code
        -1: Failure
        -0: Success

\note I2C and TWI terms are used  interchangeably

*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_NO_CRIT
a2b_HResult a2b_pal_AudioConfigFunc(a2b_Handle hnd,
                                a2b_TdmSettings* tdmSettings)
{
	ADI_SPORT_RESULT 		eResult;
	ADI_A2B_SCOMM_HANDLER 	*pAudioCommHandler;
	ADI_SPORT_PERI_CONFIG 	*pAD24xxRxSportConfig;
	ADI_SPORT_PERI_CONFIG 	*pAD24xxTxSportConfig;

	pAudioCommHandler 		= &goA2bAudio.oAudioCommHandler;
	pAD24xxRxSportConfig	= &goA2bAudio.oAD24xxRxSportConfig;
	pAD24xxTxSportConfig	= &goA2bAudio.oAD24xxTxSportConfig;

	if(tdmSettings->tdmMode > MAX_NUM_CHANNELS)
	{
		return (ADI_SPORT_FAILED);
	}

	/* Get TDM size */
	pAudioCommHandler->nAD2410TDMSize = tdmSettings->tdmMode;

    /* Configuration */
	pAD24xxRxSportConfig->nMultChDelay  			= tdmSettings->prevCycle;
	pAD24xxRxSportConfig->bActiveLowFrameSync 		= tdmSettings->fallingEdge;
	pAD24xxRxSportConfig->nSamplingRisingClkEdge 	= 0U;
	pAD24xxRxSportConfig->eSportNum 				= ADI_A2B_HAL_SPORT_0;
	pAD24xxRxSportConfig->eDirection 				= ADI_SPORT_DIR_RX;
	pAD24xxRxSportConfig->nTDMCh 					= pAudioCommHandler->nAD2410TDMSize;
	pAD24xxRxSportConfig->pfSPORTCallBack 			= (ADI_A2B_SPORT_CB)&adi_a2b_UpstreamRxCallback;
	pAD24xxRxSportConfig->nStChnlNo 				= 0;
	pAD24xxRxSportConfig->nEndChnlNo 				= (pAD24xxRxSportConfig->nTDMCh - 1);
	pAD24xxRxSportConfig->eSportHalf 				= ADI_HALF_SPORT_A;

	pAD24xxTxSportConfig->nMultChDelay  			= 1;//tdmSettings->prevCycle;
	pAD24xxTxSportConfig->bActiveLowFrameSync 		= tdmSettings->fallingEdge;
	pAD24xxTxSportConfig->nSamplingRisingClkEdge 	= 0U;
	pAD24xxTxSportConfig->eSportNum 				= ADI_A2B_HAL_SPORT_3;
	pAD24xxTxSportConfig->eDirection 				= ADI_SPORT_DIR_TX;
	pAD24xxTxSportConfig->nTDMCh 					= pAudioCommHandler->nAD2410TDMSize;
	pAD24xxTxSportConfig->pfSPORTCallBack 			= (ADI_A2B_SPORT_CB)&adi_a2b_DownStreamTxCallback;
	pAD24xxTxSportConfig->nStChnlNo 				= 0;
	pAD24xxTxSportConfig->nEndChnlNo 				= (pAD24xxTxSportConfig->nTDMCh - 1);
	pAD24xxTxSportConfig->eSportHalf 				= ADI_HALF_SPORT_A;

	/* Configure AD2410 SPORT */
    adi_a2b_InitPCGForAD24xx(pAudioCommHandler->nAD2410TDMSize);

    if(bA2BSportOpen == false)
    {
   	bA2BSportOpen=true;
 /*   	eResult = adi_a2b_SerialPortOpen(A2B_AD24xx_RXSPORT, pAD24xxRxSportConfig, (void*)pAudioCommHandler);
    	if(eResult != ADI_SPORT_SUCCESS)
    	{
    		bA2BSportOpen=false;
    		return (eResult);
    	}*/
/*
    	eResult = adi_a2b_SerialPortOpen(A2B_AD24xx_TXSPORT, pAD24xxTxSportConfig, (void*)pAudioCommHandler);
    	if(eResult != ADI_SPORT_SUCCESS)
    	{
    		bA2BSportOpen=false;
    		return (eResult);
    	}
*/
    }

//	eResult = adi_a2b_EnableAudioHost();

	return 0;//(a2b_UInt32)eResult;
}

/****************************************************************************/
/*!
    @brief			This function triggers audio data routing

    @return         void

*/
/********************************************************************************/
static ADI_SPORT_RESULT adi_a2b_EnableAudioHost(void)
{
	ADI_SPORT_RESULT eResult;

	/* Start Upstream reception */
//	eResult = adi_a2b_SerialPortEnable(A2B_AD24xx_TXSPORT, true);
	/* Start Downstream transmission */
	eResult = adi_a2b_SerialPortEnable(A2B_AD24xx_RXSPORT, true);

#if A2B_USE_CODEC
	/* Start ADC */
//	eResult = adi_a2b_SerialPortEnable(A2B_CODEC_RXSPORT, true);
	/* Start DAC */
	eResult = adi_a2b_SerialPortEnable(A2B_CODEC_TXSPORT, true);

#endif

	return((a2b_UInt32)eResult);

}

/*****************************************************************************/
/*!
@brief  This API Initializes the audio sub-system.

@param [in]:ecb  - PAL ECB structure.


@return Return code
        -1: Failure
        -0: Success

\note I2C and TWI terms are used  interchangeably

*/
/*****************************************************************************/
//ADI_MEM_A2B_CODE_NO_CRIT
a2b_HResult a2b_pal_AudioCloseFunc(a2b_Handle hnd)
{
	A2B_UNUSED(hnd);
	ADI_SPORT_RESULT eResult;

	adi_a2b_DeInitPCGForCodec();

#if A2B_USE_CODEC
//	eResult = adi_a2b_sport_Close(A2B_CODEC_RXSPORT);
//	eResult = adi_a2b_sport_Close(A2B_CODEC_TXSPORT);
#endif
	if(bA2BSportOpen == true)
	{
		bA2BSportOpen=false;
//		eResult = adi_a2b_sport_Close(A2B_AD24xx_TXSPORT);
//		eResult = adi_a2b_sport_Close(A2B_AD24xx_RXSPORT);
	}

	return ((a2b_UInt32)eResult);
}

/*****************************************************************************/
/*!
@brief  This API Initializes the audio sub-system.

@param [in]:ecb  - PAL ECB structure.


@return Return code
        -1: Failure
        -0: Success

\note I2C and TWI terms are used  interchangeably

*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_NO_CRIT
a2b_HResult a2b_pal_AudioShutdownFunc(A2B_ECB* ecb)
{
	A2B_UNUSED(ecb);
	return A2B_RESULT_SUCCESS;
}

/****************************************************************************/
/*!
    @brief			Callback function for upstream data reception

    @param [in]     pTxBufferPtr    Transmission sub buffer pointer.
    @param [in]     nChannel     	TDM size.

    @return         void

    Note:
*/
/********************************************************************************/
static a2b_UInt32 RXbuffer[24];

static void adi_a2b_UpstreamRxCallback(void* pCommHandle,a2b_UInt32 pRxBufferPtr[], a2b_UInt32 nChannel)
{
	ADI_A2B_SCOMM_HANDLER* pAudioRoutingHandle = (ADI_A2B_SCOMM_HANDLER*)pCommHandle;

	adi_a2b_DeInterleaveCopy(ganUpstreamProcessBuffer[pAudioRoutingHandle->nUpstrProcWriteIndex], pRxBufferPtr, nChannel);

	pAudioRoutingHandle->nUpstrProcWriteIndex = (pAudioRoutingHandle->nUpstrProcWriteIndex + 1u) % A2B_MAX_APPBUFFER;
}

/****************************************************************************/
/*!
    @brief			Callback function

    @param [in]     pTxBufferPtr    Transmission sub buffer pointer.
    @param [in]     nChannel     	TDM size.

    @return         void

    Note:
*/
/********************************************************************************/
static void adi_a2b_DownStreamTxCallback(void* pCommHandle, a2b_UInt32* pTxBufferPtr , a2b_UInt32 nChannel)
{
	ADI_A2B_SCOMM_HANDLER* pAudioRoutingHandle = (ADI_A2B_SCOMM_HANDLER*)pCommHandle;

	adi_a2b_upstreamToDwnRouting(pAudioRoutingHandle, pTxBufferPtr, ganUpstreamProcessBuffer[pAudioRoutingHandle->nUpstrToDwnstrReadIndex], nChannel);

#if A2B_USE_CODEC
//	adi_a2b_ADCToDwnRouting(pAudioRoutingHandle, pTxBufferPtr, ganADCProcessBuffer[pAudioRoutingHandle->nADCToDwnstrReadIndex], nChannel);
#endif
	pAudioRoutingHandle->nUpstrToDwnstrReadIndex = (pAudioRoutingHandle->nUpstrToDwnstrReadIndex + 1u) % A2B_MAX_APPBUFFER;
	pAudioRoutingHandle->nADCToDwnstrReadIndex = (pAudioRoutingHandle->nADCToDwnstrReadIndex + 1u ) % A2B_MAX_APPBUFFER;

}

/****************************************************************************/
/*!
    @brief			Callback function ADC data recpetionC

    @param [in]     pRxBufferPtr    Transmission sub buffer pointer.
    @param [in]     nChannel     	TDM size.

    @return         void

    Note:
*/
/********************************************************************************/
static void adi_a2b_ADCRxCallback(void* pCommHandle, a2b_UInt32* pRxBufferPtr , a2b_UInt32 nChannel)
{
	ADI_A2B_SCOMM_HANDLER* pAudioRoutingHandle = (ADI_A2B_SCOMM_HANDLER*)pCommHandle;

	/* Copy SPORT sub buffer data to application buffer */
	adi_a2b_DeInterleaveCopy(ganADCProcessBuffer[pAudioRoutingHandle->nADCProcWriteIndex], pRxBufferPtr, nChannel);
	pAudioRoutingHandle->nADCProcWriteIndex = (pAudioRoutingHandle->nADCProcWriteIndex + 1u) % A2B_MAX_APPBUFFER;

}

/****************************************************************************/
/*!
    @brief			Callback function for transmission completion to DAC

    @param [in]     pTxBufferPtr    Transmission sub buffer pointer.
    @param [in]     nChannel     	TDM size.

    @return         void

    Note:
*/
/********************************************************************************/
static void adi_a2b_DACTxCallback(void* pCommHandle, a2b_UInt32* pTxBufferPtr, a2b_UInt32 nChannel)
{
	ADI_A2B_SCOMM_HANDLER* pAudioRoutingHandle = (ADI_A2B_SCOMM_HANDLER*)pCommHandle;


#if A2B_USE_CODEC
	/* Upstream to DAC routing */
	adi_a2b_UpstreamToDACRouting(pCommHandle, pTxBufferPtr, ganUpstreamProcessBuffer[pAudioRoutingHandle->nUpStrtoDACReadIndex], nChannel);
	/* ADC data to DAC routing */
//	adi_a2b_ADCToDACRouting(pCommHandle, pTxBufferPtr, ganADCProcessBuffer[pAudioRoutingHandle->nADCtoDACReadIndex], nChannel);
#endif

	/* Index update */
	pAudioRoutingHandle->nADCtoDACReadIndex = (pAudioRoutingHandle->nADCtoDACReadIndex + 1u) % A2B_MAX_APPBUFFER;
	pAudioRoutingHandle->nUpStrtoDACReadIndex = (pAudioRoutingHandle->nUpStrtoDACReadIndex + 1u) % A2B_MAX_APPBUFFER;

}

/***********************************************************************************/
/*!
    @brief          This function copies upstream data to the downstream in accordance with routing table

    @param [in]     pHandle       			Pointer to serial port structure.
    @param [in]     anDwnstreamBuffer     	Pointer to downstream buffer/Destination.
    @param [in]     anUpstreamBuffer     	Source buffer address/Upstream  .
    @param [in]     nChannel         		TDM size

    @return         Return code
                    - 0: Success
                    - 1: Failure
*/
/***********************************************************************************/
static void adi_a2b_upstreamToDwnRouting(ADI_A2B_SCOMM_HANDLER* pAudioRoutingHandle, a2b_UInt32 anDwnstreamBuffer[], a2b_UInt32 anUpstreamBuffer[][SPORT_BUFFER_SIZE], a2b_UInt32 nChannel )
{
    a2b_UInt16 	nIndex1,nIndex2,nIndex3;
    a2b_UInt8 	nRoutingIndex;

    /* Outer most loop over TX channel */
    for(nIndex1 = 0u ; nIndex1 < nChannel ; nIndex1++)
    {
    	/* Get Routing Index  */
		nRoutingIndex = pAudioRoutingHandle->pRoutingTable[nIndex1 + A2B_MAX_CODEC_CHANNELS];

		if(nRoutingIndex <= (a2b_UInt8)A2B_UPSTREAM_CH31)
		{
			nRoutingIndex -= (a2b_UInt8)A2B_UPSTREAM_CH00;
			nIndex3 = 0u;
			/* Transfer the data from Rx to Tx */
			for(nIndex2 = 0u ; nIndex2 < (a2b_UInt16)SPORT_BUFFER_SIZE * nChannel ; nIndex2 += (a2b_UInt16)nChannel  )
			{
  				anDwnstreamBuffer[nIndex1 + nIndex2] = anUpstreamBuffer[nRoutingIndex][nIndex3++];
			}
		}

    }
}

/****************************************************************************/
/*!
    @brief          This function returns the Version of the A2B Stack Software

    @param [in]     major                   Major Version
    @param [in]     minor                   Minor Version
    @param [in]     release           Release number of Software

    @return          Return code
                    - 0: Success
                    - 1: Failure
*/
/********************************************************************************/

void a2b_pal_infoGetVersion(a2b_UInt32* major,
        a2b_UInt32* minor,
        a2b_UInt32* release)
{
    if ( A2B_NULL != major ) {
        *major = ADI_A2B_PAL_VER_MAJOR;
    }

    if ( A2B_NULL != minor ) {
        *minor = ADI_A2B_PAL_VER_MINOR;
    }

    if ( A2B_NULL != release ) {
        *release = ADI_A2B_PAL_VER_RELEASE;
    }
}

/****************************************************************************/
/*!
    @brief          This function returns the Version of the A2B Stack Software

    @param [in]     major                   Major Version
    @param [in]     minor                   Minor Version
    @param [in]     release           Release number of Software

    @return          Return code
                    - 0: Success
                    - 1: Failure
*/
/********************************************************************************/

void a2b_pal_infoGetBuild(a2b_UInt32* buildNum,
        const a2b_Char** const buildDate,
        const a2b_Char** const buildOwner,
        const a2b_Char** const buildSrcRev,
        const a2b_Char** const buildHost)
{
    if ( A2B_NULL != buildNum ) {
        *buildNum = ADI_A2B_PAL_BUILD_NUM;
    }

    if ( A2B_NULL != buildDate ) {
        *buildDate = __DATE__;
    }

    if ( A2B_NULL != buildOwner ) {
        *buildOwner = A2B_NULL;
    }

    if ( A2B_NULL != buildSrcRev ) {
        *buildSrcRev = A2B_NULL;
    }

    if ( A2B_NULL != buildHost ) {
        *buildHost = A2B_NULL;
    }
}


/*****************************************************************************/
/*!

@brief  Callback function for TWI events. It is invoked upon TWI events

@param [in]     pCBParam       TWI device handle
@param [in]     Event               TWI event
@param [in]     pArg                pointer to user argument


@return:
    void
*/
/*****************************************************************************/
static void adi_a2b_TWICallbackFunction(void* pCBParam, a2b_UInt32 Event, void* pArg)
{
    a2b_UInt32 event = Event;

    switch (event) {
        case ADI_TWI_EVENT_MSTR_XMT_PROCESSED:
        	nBufferProcessCount++;
            break;

        case ADI_TWI_EVENT_MSTR_RCV_PROCESSED:
			nBufferProcessCount++;
			break;

    default:
        break;
    }


}

#if A2B_USE_CODEC
/***********************************************************************************/
/*!
    @brief          This function copies ADC data to downstream

    @param [in]     pAudioRoutingHandle       			Pointer to serial port structure.
    @param [in]     anDwnstreamBuffer     	Pointer to downstream buffer/Destination.
    @param [in]     anUpstreamBuffer     	Source buffer address/Upstream  .
    @param [in]     nChannel         		TDM size

    @return         Return code
                    - 0: Success
                    - 1: Failure
*/
/***********************************************************************************/
static void adi_a2b_ADCToDwnRouting(ADI_A2B_SCOMM_HANDLER* pAudioRoutingHandle, a2b_UInt32 anDwnstreamBuffer[], a2b_UInt32 anADCBuffer[][SPORT_BUFFER_SIZE], a2b_UInt32 nChannel )
{
    a2b_UInt16 	nIndex1, nIndex2, nIndex3;
    a2b_UInt8 	nRoutingIndex;

    /* Outer most loop- Rx to Tx copy */
    for(nIndex1 = 0u ; nIndex1 <nChannel ; nIndex1++)
    {
    	nIndex3 = 0u;
    	/* Get routing table */
    	nRoutingIndex = pAudioRoutingHandle->pRoutingTable[nIndex1 + A2B_MAX_CODEC_CHANNELS];
		if((nRoutingIndex > (a2b_UInt8)A2B_UPSTREAM_CH31) && (nRoutingIndex < (a2b_UInt8)A2B_CHANNEL_UNUSED))
		{
			nRoutingIndex-= (a2b_UInt8)A2B_ADC_CH00;
			/* Transfer the data from Rx to Tx */
			for(nIndex2 = 0u ; nIndex2 < nChannel * SPORT_BUFFER_SIZE ; nIndex2 += (a2b_UInt16)nChannel  )
			{
				anDwnstreamBuffer[ nIndex1 + nIndex2 ]  =  anADCBuffer[nRoutingIndex][nIndex3++ ];
			}
		}

    }

}


/***********************************************************************************/
/*!
    @brief          This function copies upstream data to DAC

    @param [in]     pHandle       Pointer to serial port structure.
    @param [in]     iTxBuffer     Destination buffer address.
    @param [in]     iRxBuffer     Source buffer address  .
    @param [in]     nSize         Size of the buffer .

    @return         Return code
                    - 0: Success
                    - 1: Failure
*/
/***********************************************************************************/
static void adi_a2b_UpstreamToDACRouting(ADI_A2B_SCOMM_HANDLER* pAudioRoutingHandle, a2b_UInt32 anDACBuffer[], a2b_UInt32 anUpstreamBuffer[][SPORT_BUFFER_SIZE], a2b_UInt32 nChannel )
{
    a2b_UInt16 	nIndex1, nIndex2, nIndex3;
    a2b_UInt8 	nRoutingIndex;

    /* Outer most loop */
    for(nIndex1 = 0u ; nIndex1 < nChannel ; nIndex1++)
    {
    	nIndex3 = 0u;
		nRoutingIndex = pAudioRoutingHandle->pRoutingTable[nIndex1];

		if(nRoutingIndex <= (a2b_UInt8)A2B_UPSTREAM_CH31)
		{
			nRoutingIndex -= (a2b_UInt8)A2B_UPSTREAM_CH00;
			/* Transfer the data from Rx to Tx */
			for(nIndex2 = 0u ; nIndex2 < nChannel * SPORT_BUFFER_SIZE ; nIndex2 += (a2b_UInt16)nChannel  )
			{
				anDACBuffer[ nIndex1 + nIndex2 ]  =  anUpstreamBuffer[nRoutingIndex ][nIndex3++];
			}
		}

    }

}

/***********************************************************************************/
/*!
    @brief          This function copies ADC data to DAC

    @param [in]     pHandle       Pointer to serial port structure.
    @param [in]     iTxBuffer     Destination buffer address.
    @param [in]     iRxBuffer     Source buffer address.
    @param [in]     nSize         Size of the buffer.

    @return         Return code
                    - 0: Success
                    - 1: Failure
*/
/***********************************************************************************/
static void adi_a2b_ADCToDACRouting(ADI_A2B_SCOMM_HANDLER* pAudioRoutingHandle, a2b_UInt32 anDACBuffer[], a2b_UInt32 anADCBuffer[][SPORT_BUFFER_SIZE], a2b_UInt32 nChannel)
{
    a2b_UInt16 	nIndex1, nIndex2, nIndex3;
    a2b_UInt8 	nRoutingIndex;

    /* Outer most loop */
    for(nIndex1 = 0u ; nIndex1 < nChannel ; nIndex1++)
    {
    	nIndex3 = 0u;

    	nRoutingIndex = pAudioRoutingHandle->pRoutingTable[nIndex1];

		if((nRoutingIndex > (a2b_UInt8)A2B_UPSTREAM_CH31) && (nRoutingIndex < (a2b_UInt8)A2B_CHANNEL_UNUSED))
		{
	    	nRoutingIndex-= (a2b_UInt8)A2B_ADC_CH00;
			/* Transfer the data from Rx to Tx */
			for(nIndex2 = 0u; nIndex2 < nChannel * SPORT_BUFFER_SIZE; nIndex2 += (a2b_UInt16)nChannel )
			{
				anDACBuffer[ nIndex1 + nIndex2 ]  =  anADCBuffer[nRoutingIndex][nIndex3++];
			}
		}

    }

}
#endif
/***********************************************************************************/
/*!
    @brief          This function deinterleaves multi channel audio and stores to processing buffer


    @param [in]     anDesbuffer     Destination buffer address.
    @param [in]     anADCBuffer     Source buffer address.
    @param [in]     nChannel        Number of TDM channels.

    @return         Return code
                    - 0: Success
                    - 1: Failure
*/
/***********************************************************************************/
static void adi_a2b_DeInterleaveCopy( a2b_UInt32 anDesbuffer[][SPORT_BUFFER_SIZE], a2b_UInt32 anSrcBuffer[], a2b_UInt32 nChannel )
{
    a2b_UInt16 	nIndex1, nIndex2;

    /* Outer most loop */
    for(nIndex1 = 0u ; nIndex1 < nChannel ; nIndex1++)
    {
		/* Transfer the data from SPORT buffer to App buffer */
		for(nIndex2 = 0u; nIndex2 < (a2b_UInt16)SPORT_BUFFER_SIZE; nIndex2++  )
		{
			anDesbuffer[nIndex1 ][nIndex2 ]  =  anSrcBuffer[nIndex1 + nIndex2 * (a2b_UInt16)nChannel];
		}

    }
}

#if defined(A2B_FEATURE_SEQ_CHART) || defined(A2B_FEATURE_TRACE)
/*!****************************************************************************
*
*  \b              a2b_pal_logInit
*
*  <b> API Details: </b><br>
*  This routine is called to do initialization the log subsystem
*  during the stack allocation process.
*
*
*
*  \param          [in]    ecb      The environment control block (ecb) for
*                                   this platform.
*
*  \pre            None
*
*  \post           None
*
*  \return         A status code that can be checked with the A2B_SUCCEEDED()
*                  or A2B_FAILED() for success or failure.
*
******************************************************************************/
a2b_HResult a2b_pal_logInit(A2B_ECB*   ecb)
{
	uint8_t i = 0u;
	for(i=0; i<(A2B_TOTAL_LOG_CH); i++)
	{
		ecb->palEcb.oLogConfig[i].fd = A2B_INVALID_FD;
		ecb->palEcb.oLogConfig[i].inUse = false;
	}
	return A2B_RESULT_SUCCESS;
}

/*!****************************************************************************
*
*  \b              a2b_pal_logShutdown
*
*  <b> API Details: </b><br>
*  This routine is called to shutdown the log subsystem
*  during the stack destroy process.  This routine is called immediately
*  after the a2b_pal_logClose (assuming the close was successful).
*
*
*  \param          [in]    ecb      The environment control block (ecb) for
*                                   this platform.
*
*  \pre            None
*
*  \post           None
*
*  \return         A status code that can be checked with the A2B_SUCCEEDED()
*                  or A2B_FAILED() for success or failure.
*
******************************************************************************/
a2b_HResult a2b_pal_logShutdown(A2B_ECB* ecb)
{
    A2B_UNUSED(ecb);
    return A2B_RESULT_SUCCESS;
} /* pal_logShutdown */


/*!****************************************************************************
*
*  \b              a2b_pal_logOpen
*
*  This routine is called to do post-initialization the log subsystem
*  during the stack allocation process.  This routine is called immediately
*  after the pal_logInit (assuming the init was successful).
*
*
*
*  \param          [in]    ecb      The environment control block (ecb) for
*                                   this platform.
*
*  \pre            None
*
*  \post           None
*
*  \return         A status code that can be checked with the A2B_SUCCEEDED()
*                  or A2B_FAILED() for success or failure.
*
******************************************************************************/
a2b_Handle a2b_pal_logOpen(const a2b_Char* url)
{
	uint8_t i = 0u;
	a2b_HResult nHandle = 0U;

	if ( A2B_NULL != url )
	{
		for(i=0; i<(A2B_TOTAL_LOG_CH); i++)
		{
			if(!pTimerEcb->oLogConfig[i].inUse)
			{
				pTimerEcb->oLogConfig[i].fd = (a2b_UInt32)fopen(url, "w");
				nHandle = (a2b_HResult)&pTimerEcb->oLogConfig[i];
				pTimerEcb->oLogConfig[i].inUse = true;
				break;
			}
		}
	}

	return (a2b_Handle)nHandle;
}

/*!****************************************************************************
*
*  \b              a2b_pal_logClose
*
*  This routine is called to de-initialization the log subsystem
*  during the stack destroy process.
*
*
*
*  \param          [in]    ecb      The environment control block (ecb) for
*                                   this platform.
*
*  \pre            None
*
*  \post           None
*
*  \return         A status code that can be checked with the A2B_SUCCEEDED()
*                  or A2B_FAILED() for success or failure.
*
******************************************************************************/
a2b_HResult a2b_pal_logClose(a2b_Handle  hnd)
{
	uint8_t i = 0u;
	a2b_HResult nResult = 0xFFFFFFFFU;
	A2B_LOG_INFO *pLogInfo;

	if ( A2B_NULL != hnd )
	{
		pLogInfo = (A2B_LOG_INFO *)hnd;

		fclose((FILE*)pLogInfo->fd);
		pLogInfo->fd = A2B_INVALID_FD;
		pLogInfo->inUse = false;
		nResult = A2B_RESULT_SUCCESS;
	}

	return nResult;
}

/*!****************************************************************************
*
*  \b              a2b_pal_logWrite
*
*  <b> API Details: </b><br>
*  This routine writes to a log channel.
*
*
*  \param          [in]    hnd      The handle returned from pal_logOpen
*
*  \param          [in]    msg      NULL terminated string to log
*
*  \pre            None
*
*  \post           None
*
*  \return         A status code that can be checked with the A2B_SUCCEEDED()
*                  or A2B_FAILED() for success or failure.
*
******************************************************************************/
a2b_HResult a2b_pal_logWrite(
    a2b_Handle      hnd,
    const a2b_Char* msg)
{
	a2b_HResult nResult = 0xFFFFFFFFu;
	a2b_UInt32 msg_len = 0u;
	A2B_LOG_INFO *pLogInfo;
	a2b_Char* newline = "\n";

	if ( (A2B_NULL != hnd) && (A2B_NULL != msg) )
	{
		strcat((char *__restrict__)msg, (char *__restrict__)newline);
		pLogInfo = (A2B_LOG_INFO *)hnd;
		msg_len = a2b_strlen(msg) * sizeof(a2b_Char);
		fwrite(msg, 1, msg_len, (FILE *)pLogInfo->fd);
		nResult = A2B_RESULT_SUCCESS;
	}
	return nResult;
}
#endif

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


