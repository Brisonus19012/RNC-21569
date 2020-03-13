/*******************************************************************************
Copyright (c) 2014 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
******************************************************************************
* @file: adi_a2b_config.h
* @brief: This file contains macros and structure definitions used for bus configuration 
* @version: $Revision$
* @date: $Date$
* BCF Version - 1.0.0
* Developed by: Automotive Software and Systems team, Bangalore, India
* THIS IS A SIGMASTUDIO GENERATED FILE AND SHALL NOT BE MODIFIED OUTSIDE OF SIGMASTUDIO
*****************************************************************************/

/*! \addtogroup Target_Independent
* @{
*/

/** @defgroup Audio_Routing
*
* This module has structure definitions to describe SigamStudio exported bus configuration/description file.
* The exported bus configuration is interpreted using the structure \ref ADI_A2B_BCD.
*
*/

/*! \addtogroup Audio_Routing  Audio Routing
* @{
*/

/*============= INCLUDES =============*/

#include "adi_a2b_sportdriver.h"
/*============= D E F I N E S =============*/

#define A2B_CODEC_SPORTTX_NO		(0)
#define A2B_CODEC_SPORTRX_NO		(1)
#define A2B_AD24XX_SPORTTX_NO		(2)
#define A2B_AD24XX_SPORTRX_NO		(3)

#define MAX_NUMBER_OF_CHANNELS		(32u)
#define A2B_MAX_CODEC_CHANNELS		(2u)
#define MAX_A2B_DATAPIPE_I2S_STREAMS (8u)

#define A2B_UPSTREAM_CH00			(0u)
#define A2B_UPSTREAM_CH01			(1u)
#define A2B_UPSTREAM_CH02			(2u)
#define A2B_UPSTREAM_CH03			(3u)
#define A2B_UPSTREAM_CH04			(4u)
#define A2B_UPSTREAM_CH05			(5u)
#define A2B_UPSTREAM_CH06			(6u)
#define A2B_UPSTREAM_CH07			(7u)
#define A2B_UPSTREAM_CH08			(8u)
#define A2B_UPSTREAM_CH09			(9u)
#define A2B_UPSTREAM_CH10			(10u)
#define A2B_UPSTREAM_CH31			(31u)
#define A2B_ADC_CH00				(0xF0)
#define A2B_ADC_CH01				(0xF1)

#define A2B_CHANNEL_UNUSED			(0xFFu)

/*============= D A T A T Y P E S=============*/
extern uint8 gaAudioRoutingtab[A2B_MAX_CODEC_CHANNELS + MAX_NUMBER_OF_CHANNELS];

typedef void (*SCOMM_CALL_BACK)(void* pHandle,void* pDest,void* pSrc,uint32 nSize);


/*! \struct ADI_A2B_SCOMM_HANDLER
    A2B graph/schematic structure
*/
typedef struct
{

    /*! TDM size */
    uint8 nAD2410TDMSize;

    /*! Codec size */
    uint8 nCodecTDMSize;

    /* Word length  */
    uint8 nWordLength;

    /* Routing table */
    uint8* pRoutingTable;

    /*! Audio data word size*/
    SCOMM_CALL_BACK pCallbackhandle;

    volatile uint8 nUpstrProcWriteIndex;
    volatile uint8 nADCProcWriteIndex;

    volatile uint8 nUpstrToDwnstrReadIndex;
    volatile uint8 nADCToDwnstrReadIndex;

    volatile uint8 nADCtoDACReadIndex;
    volatile uint8 nUpStrtoDACReadIndex;


}ADI_A2B_SCOMM_HANDLER,*ADI_A2B_SCOMM_HANDLER_PTR;

/*============= E X T E R N A L S ============*/


/**
 @}
*/
/**
 @}
*/


/*
**
** EOF: adi_a2b_busconfig.h
**
*/
