/*******************************************************************************
Copyright (c) 2015 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
*******************************************************************************

   Name       : adi_a2b_sportdriver.c

   Description: This file is responsible for handling timer related functions.

                 adi_a2b_InputSerialPortEnable()
   Functions  :  adi_a2b_SerialPortOpen()
                 adi_sport_Close()
                 adi_RxSPORT_ISR()
                 adi_TxSPORT_ISR()
                 adi_a2b_SerialPortConfigure()
                 adi_a2b_OutputSerialPortEnable()


   Prepared &
   Reviewed by: Automotive Software and Systems team,
                IPDC, Analog Devices,  Bangalore, India

   @version: $Revision: 2257 $
   @date: $Date: 2014-07-17 21:28:09 +0530 (Thu, 17 Jul 2014) $

******************************************************************************/
/*! \addtogroup Target_Dependent Target Dependent
 *  @{
 */

/** @defgroup SPORT
 *
 * This module controls the SPORTs configuration for Transmit and Receive. The
 * framework will use the SPORTs to transfer audio data from and to Codec and
 * AD2410.
 */

/*! \addtogroup SPORT
 *  @{
 */

/*============= I N C L U D E S =============*/ 

#include <sys/platform.h>
#include <stdio.h>
#include "adi_a2b_datatypes.h"
#include "adi_a2b_sportdriver.h"
#include <services/int/adi_int.h>  /* Interrupt Handler API header. */
#include "adi_a2b_driverprototypes.h"
#include "adi_a2b_sys.h"
/*============= D E F I N E S =============*/
/*#define A2B_LOOP_BACKTEST*/

#define SDMODIFY (1U)                    /* Setting the Modify to 1*/
#define CLKDIV   (2U)
#define FSDIV    (512U)
#define A2B_I2S_WAVE
#define PHASE_LOW (1U<<20U)
/*#define PULSE_MODE_PCG*/
#define ADI_A2B_HAL_SPORT_MEM_SIZE           (ADI_SPORT_MEMORY_SIZE)
/*============== DATA ===============*/
ADI_MEM_A2B_DATA_CRIT_NO_CACHE
ADI_A2B_DATA_MEM_ALIGN4
static ADI_SPORT_BUFF_INFO oSportBuffInfo[NUM_SPORT_DEVICES];
ADI_MEM_A2B_DATA_CRIT_NO_CACHE
static ADI_SPORT_HANDLE hSPORT[NUM_SPORT_DEVICES]; 

/*============= C O D E =============*/ 

/*
** Function Prototype section
** (static-scoped functions)
*/

/*
** Function Definition section
*/

/*****************************************************************************/
/*!
@brief             This API opens and clears the respective SPORT Pairs

@param [in]           nSportDeviceNo    The SPORT device pair num
										0 : SPORT0 - Tx, 1: SPORT1 - Rx
										1 : SPORT2 - Tx, 1: SPORT3 - Rx
@param [in]           pConfig           The SPORT configuration structure
@param [in]           pUserArgument     User defined argument to be passed
                                        to the ISR and Callback

@return        Return code
                - 0: Success
                - 1: Failure
*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_CRIT
ADI_SPORT_RESULT adi_a2b_SerialPortOpen(uint8 nSportDeviceNo, ADI_SPORT_PERI_CONFIG *pConfig, void* pUserArgument)
{
	ADI_SPORT_RESULT  eSportResult = ADI_SPORT_SUCCESS;
    ADI_SPORT_MODE	eSportMode = ADI_SPORT_MC_MODE;
    bool bSamplingClkEdge = false, bActiveLowFS = false;;

    if(pConfig->nTDMCh <= 2)
    {
         eSportMode = ADI_SPORT_I2S_MODE;
    }

    oSportBuffInfo[nSportDeviceNo].nSportDevNum = nSportDeviceNo;
    oSportBuffInfo[nSportDeviceNo].oSportConfig = *pConfig;
    oSportBuffInfo[nSportDeviceNo].pUserArgument = pUserArgument;
    oSportBuffInfo[nSportDeviceNo].nSportInterruptCnt = 0;

	eSportResult = adi_sport_Open((uint32_t)pConfig->eSportNum,
											pConfig->eSportHalf,
											pConfig->eDirection,
	                                        eSportMode,
	                                        (&oSportBuffInfo[nSportDeviceNo].aSPORTMem[0]),
	                                        ADI_A2B_HAL_SPORT_MEM_SIZE,
	                                        &hSPORT[nSportDeviceNo]);


	eSportResult = adi_sport_ConfigData(hSPORT[nSportDeviceNo],
	                                        ADI_SPORT_DTYPE_SIGN_FILL,
	                                        ADI_A2B_HAL_SPORT_CONFIGDATA_WORDLEN_32,
	                                        ADI_A2B_HAL_SPORT_CONFIGDATA_MSB_FIRST,
	                                        ADI_A2B_HAL_SPORT_CONFIGDATA_DIS_DMA_PACK,
	                                        ADI_A2B_HAL_SPORT_CONFIGDATA_DIS_RJ);

	/* The API argument "bFallingEdge" must actually be "bRisingEdge" since internally it sets for rising edge
	   when "bFallingEdge" is true. Refer JIRA CCES-11151 issue. */
	if(pConfig->nSamplingRisingClkEdge == 0u)
	{
		bSamplingClkEdge = ADI_A2B_HAL_SPORT_CONFIGCLOCK_FALLING_EDGE;
	}
	else
	{
		bSamplingClkEdge = ADI_A2B_HAL_SPORT_CONFIGCLOCK_RISING_EDGE;
	}

	eSportResult = adi_sport_ConfigClock(hSPORT[nSportDeviceNo],
	                               ADI_A2B_HAL_SPORT_CONFIGCLOCK_CLOCKRATIO,
	                               ADI_A2B_HAL_SPORT_CONFIGCLOCK_EXTERNAL,
	                               bSamplingClkEdge,
	                               ADI_A2B_HAL_SPORT_CONFIGCLOCK_DIS_GATED_CLOCK);

	/* The API argument "bActiveHighFS" is set to false here since the corresponding macro in defSC589 is inverted.
	   Refer JIRA CCES-11151 issue. */
	if(pConfig->bActiveLowFrameSync == 0u)
	{
		bActiveLowFS = ADI_A2B_HAL_SPORT_CONFIGFS_ACTIVEHIGH_FS;
	}
	else
	{
		bActiveLowFS = ADI_A2B_HAL_SPORT_CONFIGFS_ACTIVELOW_FS;
	}

	if(eSportMode == ADI_SPORT_MC_MODE)
	{
	    eSportResult = adi_sport_ConfigFrameSync(hSPORT[nSportDeviceNo],
	                                        ADI_A2B_HAL_SPORT_CONFIGFS_FS_DIVISIOR,
	                                        ADI_A2B_HAL_SPORT_CONFIGFS_FS_REQUIRED,
	                                        ADI_A2B_HAL_SPORT_CONFIGFS_EXTERNAL,
	                                        ADI_A2B_HAL_SPORT_CONFIGFS_DATA_DEPEN_FS,
	                                        bActiveLowFS,
											ADI_A2B_HAL_SPORT_CONFIGFS_EARLY_FS,
	                                        ADI_A2B_HAL_SPORT_CONFIGFS_EDGESENSE_FS);
    }
	else
	{
	    eSportResult = adi_sport_ConfigFrameSync(hSPORT[nSportDeviceNo],
											ADI_A2B_HAL_SPORT_CONFIGFS_FS_DIVISIOR,
											ADI_A2B_HAL_SPORT_CONFIGFS_FS_REQUIRED,
											ADI_A2B_HAL_SPORT_CONFIGFS_EXTERNAL,
											ADI_A2B_HAL_SPORT_CONFIGFS_DATA_DEPEN_FS,
											bActiveLowFS,
											ADI_A2B_HAL_SPORT_CONFIGFS_EARLY_FS,
	                                        ADI_A2B_HAL_SPORT_CONFIGFS_LEVELSENSE_FS);
	}

	if(eSportMode == ADI_SPORT_MC_MODE)
	{
	    eSportResult = adi_sport_ConfigMC(hSPORT[nSportDeviceNo],
	                                       (uint8)pConfig->nMultChDelay,
	                                       (uint8)(pConfig->nTDMCh-1U),
	                                       ADI_A2B_HAL_SPORT_CONFIGMC_WINDOW_SIZE,
	                                       ADI_A2B_HAL_SPORT_CONFIGMC_DIS_DMADATA_PACK);
	}
	/* Select Channels in MultiChannel Mode */
	eSportResult = adi_sport_SelectChannel(hSPORT[nSportDeviceNo],pConfig->nStChnlNo,(uint8)(pConfig->nEndChnlNo));
//	eSportResult = adi_sport_EnableDMAMode(hSPORT[nSportDeviceNo],ADI_A2B_HAL_SPORT_ENABLE_DMA);
//	eSportResult = adi_sport_StreamingEnable(hSPORT[nSportDeviceNo],ADI_A2B_HAL_SPORT_ENABLE_STREAMING);

	        switch (pConfig->eDirection)
	        {
	        case ADI_SPORT_DIR_RX:
	        	oSportBuffInfo[nSportDeviceNo].nXCount = SPORT_BUFFER_SIZE;
	        	oSportBuffInfo[nSportDeviceNo].nXModify = pConfig->nTDMCh;
	        	oSportBuffInfo[nSportDeviceNo].nYCount = SPORT_BUFFER_SIZE;
	            oSportBuffInfo[nSportDeviceNo].nXModify = (-SPORT_BUFFER_SIZE *(pConfig->nTDMCh - 1)) + 1;
		        eSportResult = adi_sport_RegisterCallback(hSPORT[nSportDeviceNo],
		        											(ADI_CALLBACK)&adi_RxSPORT_ISR,
		                                                 &(oSportBuffInfo[nSportDeviceNo]));

	        	break;
	        case ADI_SPORT_DIR_TX:
	        	oSportBuffInfo[nSportDeviceNo].nXCount = SPORT_BUFFER_SIZE;
	        	oSportBuffInfo[nSportDeviceNo].nXModify = pConfig->nTDMCh;
	        	oSportBuffInfo[nSportDeviceNo].nYCount = SPORT_BUFFER_SIZE;
	            oSportBuffInfo[nSportDeviceNo].nXModify = (-SPORT_BUFFER_SIZE *(pConfig->nTDMCh - 1)) + 1;
		        eSportResult = adi_sport_RegisterCallback(hSPORT[nSportDeviceNo],
		        		                                   (ADI_CALLBACK)&adi_TxSPORT_ISR,
		        		                                   &(oSportBuffInfo[nSportDeviceNo]));
	        	break;
	        default:
	        	eSportResult = ADI_SPORT_FAILED;
	        }
	        eSportResult = adi_a2b_sport_ProcessBuffer(hSPORT[nSportDeviceNo],
	        				&(oSportBuffInfo[nSportDeviceNo].aSportBuff[0]), SPORT_BUFFER_SIZE * 4U * pConfig->nTDMCh);
	        eSportResult = adi_a2b_sport_ProcessBuffer(hSPORT[nSportDeviceNo],
	        	        	&(oSportBuffInfo[nSportDeviceNo].aSportBuff[pConfig->nTDMCh * SPORT_BUFFER_SIZE]), SPORT_BUFFER_SIZE * 4U * pConfig->nTDMCh);
	return eSportResult;

}

/*****************************************************************************/
/*!
@brief             This API Closes the Sport Pair

@param [in]           nSportDeviceNo    The SPORT device pair num
										0 : SPORT0 - Tx, 1: SPORT1 - Rx
										1 : SPORT2 - Tx, 1: SPORT3 - Rx
@param [in]           pConfig           The SPORT configuration structure
@param [in]           pUserArgument     User defined argument to be passed
                                        to the ISR and Callback

@return        Return code
                - 0: Success
                - 1: Failure
*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_CRIT
ADI_SPORT_RESULT adi_a2b_sport_Close(uint8 nSportDeviceNo)
{
	ADI_SPORT_RESULT  eSportResult=ADI_SPORT_FAILED;
	eSportResult = adi_sport_Close(hSPORT[nSportDeviceNo]);

	return eSportResult;
}

/*****************************************************************************/
/*!
@brief             This is the ISR for servicing the SPORT Rx interrupt

@param [in]           nId      Interrupt ID
@param [in]           hSport    Handle to the SPORT device

*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_CRIT
void adi_RxSPORT_ISR(void *pCBParam, uint32 Event, void  *pArg)
{
	uint32 nCurRxBufInd;
	ADI_SPORT_BUFF_INFO *pSportBuffInfo = (ADI_SPORT_BUFF_INFO *)pCBParam;
	uint8 nSportDeviceNo = pSportBuffInfo->nSportDevNum;

	nCurRxBufInd = pSportBuffInfo->nSubBufInd;

#ifndef A2B_LOOP_BACKTEST
	pSportBuffInfo->oSportConfig.pfSPORTCallBack(pSportBuffInfo->pUserArgument,
			&pSportBuffInfo->aSportBuff[nCurRxBufInd * pSportBuffInfo->oSportConfig.nTDMCh * SPORT_BUFFER_SIZE],
			pSportBuffInfo->oSportConfig.nTDMCh);

#endif
	adi_a2b_sport_ProcessBuffer(hSPORT[nSportDeviceNo],
								&(pSportBuffInfo->aSportBuff[pSportBuffInfo->nSubBufInd * pSportBuffInfo->oSportConfig.nTDMCh * SPORT_BUFFER_SIZE]),
			                    SPORT_BUFFER_SIZE * 4U * pSportBuffInfo->oSportConfig.nTDMCh);
	pSportBuffInfo->nSubBufInd = ((pSportBuffInfo->nSubBufInd + 1U) % NUM_INPUT_SPORT_BUFFERS);

	pSportBuffInfo->nSportInterruptCnt++;
}

/*****************************************************************************/
/*!
@brief             This is the ISR for servicing the SPORT Tx interrupt

@param [in]           nId      Interrupt ID
@param [in]           hSport    Handle to the SPORT device

*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_CRIT
void adi_TxSPORT_ISR(void *pCBParam, uint32 Event, void  *pArg)
{
	uint32 nCurTxBufInd;
	ADI_SPORT_BUFF_INFO *pSportBuffInfo = (ADI_SPORT_BUFF_INFO *)pCBParam;
	uint8 nSportDeviceNo = pSportBuffInfo->nSportDevNum;
	nCurTxBufInd = pSportBuffInfo->nSubBufInd;

#ifndef A2B_LOOP_BACKTEST
	pSportBuffInfo->oSportConfig.pfSPORTCallBack(pSportBuffInfo->pUserArgument,
												&pSportBuffInfo->aSportBuff[nCurTxBufInd * pSportBuffInfo->oSportConfig.nTDMCh * SPORT_BUFFER_SIZE],
												pSportBuffInfo->oSportConfig.nTDMCh);

#endif
	adi_a2b_sport_ProcessBuffer(hSPORT[nSportDeviceNo],
				&(pSportBuffInfo->aSportBuff[pSportBuffInfo->nSubBufInd *pSportBuffInfo->oSportConfig.nTDMCh * SPORT_BUFFER_SIZE]),
				SPORT_BUFFER_SIZE * 4U * pSportBuffInfo->oSportConfig.nTDMCh);
	pSportBuffInfo->nSubBufInd = ((pSportBuffInfo->nSubBufInd + 1U) % NUM_OUTPUT_SPORT_BUFFERS);

	pSportBuffInfo->nSportInterruptCnt++;

}


/*****************************************************************************/
/*!
@brief             This API will enable the input SPORT

@param [in]         nSportDeviceNo    The SPORT device pair num
										0 : SPORT0 - Tx, 1: SPORT1 - Rx
										1 : SPORT4 - Tx, 1: SPORT5 - Rx
*/
/*****************************************************************************/
ADI_MEM_A2B_CODE_CRIT
ADI_SPORT_RESULT adi_a2b_SerialPortEnable(uint32 nSportDeviceNo, bool bEnable)
{
    ADI_SPORT_RESULT  eSportResult = ADI_SPORT_FAILED;

    eSportResult = adi_sport_Enable(hSPORT[nSportDeviceNo], bEnable);

    return eSportResult;
}

/*!
   @brief       This API submits the buffer for transmitting/receiving the data.
                This function can be used to submit the buffers for both transmitting and receiving.
   @param       hSPORT        Device handle to SPORT device is obtained when a SPORT device is opened
                                    successfully.
   @param       pBuffer             Pointer to buffer from where data need to be transmitted OR to which received
                                    data need to to be written.
   @param       nBuffSizeInBytes    Size of the data to be transmitted (In bytes)/ received.
   @return      SPORT device status of ADI_A2B_HAL_SPORT_STATUS type.
                    - ADI_A2B_HAL_SPORT_STATUS_SUCCESS   : HAL SPORT Status Success
                    - ADI_A2B_HAL_SPORT_STATUS_FAILED    : HAL SPORT Status Error

   <b> Global Variables Used: <b>
                None

  @note         None.
*/
ADI_MEM_A2B_CODE_CRIT
ADI_SPORT_RESULT adi_a2b_sport_ProcessBuffer(ADI_SPORT_HANDLE hSPORT,
		                                      void  *pBuffer,
                                              uint32_t   nBuffSizeInBytes)
{
    ADI_SPORT_RESULT  eSportResult = ADI_SPORT_FAILED;

    if((hSPORT!=NULL) && (pBuffer!=NULL))
    {
//        eSportResult = adi_sport_SubmitBuffer(hSPORT, pBuffer, nBuffSizeInBytes);
    }
    return eSportResult;
}

/********************************************************************************/
/*!
@brief This function does the PCG initialization for AD2410 BCLK and SYNC

@param [in] none

@return     None

Note: Current configuration - BCLK - 12.288MHz, SYNC -48KHz

*/
/***********************************************************************************/
void adi_a2b_InitPCGForAD24xx(uint16 nTDMSize)
{
	volatile uint32 nCtla0Val ;
	volatile uint32 nCtla1Val ;

	/* TDM 2 */
	if(nTDMSize == 2u)
	{

#ifdef A2B_I2S_WAVE
			nCtla1Val = 8U|(uint32)(4U<<20U);
#else
			nCtla1Val = 8U;
#endif

	}
	else if(nTDMSize == 4u)
	{

#ifdef A2B_I2S_WAVE
		nCtla1Val = 4U |(uint32)(2U<<20U);
#else
		nCtla1Val = 4U;
#endif

	}
	else if(nTDMSize == 8u)
	{

#ifdef A2B_I2S_WAVE
		nCtla1Val = 2u |(uint32)(1U<<20U);
#else
		nCtla1Val = 2u;
#endif

	}
	/* TDM 16 */
	else  /* if(nTDMSize == 16u) Supported only till TDM16 */
	{

		nCtla1Val = (uint32)1u;

	}

	(*(volatile uint32 *)REG_PCG0_CTLA1) = nCtla1Val ;
	nCtla0Val = (uint32)FSDIV|(uint32)(BITM_PCG_CTLA0_CLKEN)|(uint32)(BITM_PCG_CTLA0_FSEN);
	(*(volatile uint32 *)REG_PCG0_CTLA0) = nCtla0Val ;

#ifdef PULSE_MODE_PCG
		(*(volatile uint32 *)PCG_PW)= 2u;
#endif

	/* Delay for AD2410 to Reset */
	adi_a2b_Delay(200u);

}


/********************************************************************************/
/*!
@brief This function does the PCG initialization for AD2410 BCLK and SYNC

@param [in] none

@return     None

Note: Current configuration - BCLK - 12.288MHz, SYNC -48KHz

*/
/***********************************************************************************/
void adi_a2b_DeInitPCGForAD24xx (void)
{
	(*(volatile uint32 *)pREG_PCG0_CTLA0) = 0u ;
	(*(volatile uint32 *)pREG_PCG0_CTLA1) = 0u;
	(*(volatile uint32 *)pREG_PCG0_PW1)= 0x0u;

}


/********************************************************************************/
/*!
@brief This function does the PCG initialization for CODEC 1961 BCLK, MCLK and SYNC

@param [in] none

@return     None

Note: Current configuration - 12.288MHz, SYNC -48K

*/
/***********************************************************************************/

void adi_a2b_InitPCGForCodec(void)
{
  	*pREG_PCG0_CTLB1 |= (uint32)DIVCLKD | (2U<<20U);
	*pREG_PCG0_CTLB0 |= (uint32)DIVFSA | (BITM_PCG_CTLA0_CLKEN) | (uint32)(BITM_PCG_CTLA0_FSEN);

}

/********************************************************************************/
/*!
@brief This function does the PCG initialization for CODEC 1961 BCLK, MCLK and SYNC

@param [in] none

@return     None

Note: Current configuration - 3.072MHz, 12.288MHz, SYNC -48K

*/
/***********************************************************************************/

void adi_a2b_DeInitPCGForCodec(void)
{
	*pREG_PCG0_CTLA0 = 0u;
  	*pREG_PCG0_CTLA1 = 0u;

	*pREG_PCG0_CTLB0 = 0u;
	*pREG_PCG0_CTLB1 = 0u;

}

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

