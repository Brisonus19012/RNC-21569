/*********************************************************************************
Copyright(c) 2019 Analog Devices, Inc. All Rights Reserved.
This software is proprietary and confidential. By using this software you agree
to the terms of the associated Analog Devices License Agreement.
*********************************************************************************/

/*****************************************************************************
 * RNC_21569.h
 *****************************************************************************/

#ifndef __RNC_21569_H__
#define __RNC_21569_H__

#include <cdef21569.h>
#include <services/pwr/adi_pwr.h>
#include <a2bapp.h>
#include <a2bapp_sc58x.h>
#include <adi_a2b_externs.h>
#include <assert.h>
#include <drivers/twi/adi_twi.h>
#include <services/gpio/adi_gpio.h>
#include <services/pcg/adi_pcg.h>
#include "adi_a2b_pal.h"

/* Add your custom header content here */


#define SAMPLE_RATE   			        (48000u)       /* DAC sample rate */

#define REFERENCE_FREQ 				    (2000u)
#define SAMPLES_PER_PERIOD 			    (SAMPLE_RATE) / (REFERENCE_FREQ)
#define SAMPLE_SIZE 				    (4u)

#define RxNUM_CHANNELS				    (16u)
#define TxNUM_CHANNELS				    (8u)

/* Macro to set buffer size */
#define A2B_BUFFER_SIZE 	            (SAMPLES_PER_PERIOD * RxNUM_CHANNELS)
#define DAC_BUFFER_SIZE 	            (SAMPLES_PER_PERIOD * TxNUM_CHANNELS)

#define SPORT_DEVICE_4A 			    4u			/* SPORT device number */
#define SPORT_DEVICE_0A 			    0u			/* SPORT device number */


//#define TARGETADDR_1979    			(0x11u)     /* hardware address of adau1979 ADC */


#define DMA_NUM_DESC 				    2u

#define SUCCESS                         0
#define FAILED                          -1


#define CHECK_RESULT(eResult) \
        if(eResult != 0)\
		{\
			return (1);\
        }

#define REPORT_ERROR        	       printf
#define DEBUG_INFORMATION              printf

#endif /* __SPORT_TDM_MODE_H__ */
