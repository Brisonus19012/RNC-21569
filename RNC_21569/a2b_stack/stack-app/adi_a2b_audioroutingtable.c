/*******************************************************************************
Copyright (c) 2017 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
******************************************************************************
* @file: adi_a2b_audioroutingtable.c
* @brief: This file contains A2B Audio Routing table for the ADSP-SC58x target
* @version: $Revision$
* @date: $Date$
* Developed by: Automotive Software and Systems team, Bangalore, India
*****************************************************************************/

/*! \addtogroup Target_Independent
* @{
*/

/*! \addtogroup Audio_Routing Audio Routing
*  @{
*/


#include "adi_a2b_datatypes.h"
#include "adi_a2b_audiorouting.h"

 /*! Audio Routing table */ 
ADI_A2B_MEM_GRAPH_DATA
uint8 gaAudioRoutingtab[A2B_MAX_CODEC_CHANNELS + MAX_NUMBER_OF_CHANNELS] =
{
A2B_UPSTREAM_CH00/* DAC 0 */,
A2B_UPSTREAM_CH01/* DAC 1 */,
A2B_UPSTREAM_CH02,
A2B_UPSTREAM_CH03,
A2B_UPSTREAM_CH04,
A2B_UPSTREAM_CH05,
A2B_UPSTREAM_CH06,
A2B_UPSTREAM_CH07,
//A2B_ADC_CH00, /* DOWNSTREAM CH 0 */
//A2B_ADC_CH01, /* DOWNSTREAM CH 1 */
//A2B_ADC_CH00, /* DOWNSTREAM CH 2 */
//A2B_ADC_CH01, /* DOWNSTREAM CH 3 */
//A2B_ADC_CH00, /* DOWNSTREAM CH 4 */
//A2B_ADC_CH01, /* DOWNSTREAM CH 5 */
A2B_ADC_CH00, /* DOWNSTREAM CH 6 */
A2B_ADC_CH01, /* DOWNSTREAM CH 7 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 8 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 9 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 10 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 11 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 12 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 13 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 14 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 15 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 16 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 17 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 18 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 19 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 20 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 21 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 22 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 23 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 24 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 25 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 26 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 27 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 28 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 29 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 30 */
A2B_CHANNEL_UNUSED, /* DOWNSTREAM CH 31 */
};
/**
@}
*/
/**
@}
*/
