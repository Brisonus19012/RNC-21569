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


#define SUCCESS                         0
#define FAILED                          -1

extern uint8_t InputReady;

#define REPORT_ERROR        	       printf
#define DEBUG_INFORMATION              printf

#endif /* __SPORT_TDM_MODE_H__ */
