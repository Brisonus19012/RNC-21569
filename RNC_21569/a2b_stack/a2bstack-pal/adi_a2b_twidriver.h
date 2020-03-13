/*******************************************************************************
Copyright (c) 2014 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
******************************************************************************
* @file: adi_a2b_twidriver.h
* @brief: This file contains declarations required by TWI driver file.
* @version: $Revision: 3873 $
* @date: $Date: 2016-01-04 18:36:44 +0530 (Mon, 04 Jan 2016) $
* Developed by: Automotive Software and Systems team, Bangalore, India
*****************************************************************************/

/*! \addtogroup TWI I2C / TWI
* @{
*/

/*! \addtogroup TWI_Configuration TWI Configuration
* @{
*/

#ifndef _ADI_A2B_TWIDRIVER_H_
#define _ADI_A2B_TWIDRIVER_H_

/*============= I N C L U D E S =============*/
#include <drivers/twi/adi_twi.h>
#include "a2bstack/inc/a2b/pal.h"
/*============= D E F I N E S =============*/

/*! Wait period in microsecond seconds for TWI time-out*/
#define TWI_TIMEOUT_PERIOD                	(1600u)

/*! Timer ID used by the TWI */
#define TWI_TIMER                         	(0u) /* FIXED to 0*/

/*! Block size of twi write is limited by this macro  */
#define MAX_NUMBER_TWI_BYTES              	(ADI_A2B_MAX_PERI_CONFIG_UNIT_SIZE) 

/*! Number of TWI devices used */
#define NO_TWI_DEVICES                      (1)

/*! RX callback */
#define TWI_RX_CALLBACK                     (0)

/*! TX callback */
#define TWI_TX_CALLBACK                     (1)

/*! Enable TWI abort on timer expire */
#define TIME_OUT_ENABLE                     (1u)

/*! TWI interface clock rate in KHz */
#define A2B_TWI_RATE_100                        (100u)      /* Use only 100KHz in 1.0 silicon with one level branch.
                                                           For details refer silicon Anamoly list - ID 18000016  */
#define A2B_TWI_RATE_400						(400u)

/*============= D A T A T Y P E S=============*/

/*! \struct ADI_A2B_TWI_ADDR_CONFIG
    TWI Sub address(Register) configuration structure
*/

typedef struct
{
    /*! Register address length/width in bytes(0/1/2/4 sub-address) */
    uint32_t nRegAddrLen;

    /*! Register Value (sub-address)  */
    uint32_t nRegVal;

}ADI_A2B_TWI_ADDR_CONFIG;


/*! \struct ADI_A2B_TWI_DATA_CONFIG
    TWI data configuration structure
*/
typedef struct
{
    /*! Data width in bytes(0/1/2/4)  */
    uint32_t nDataLen;

    /*! Register address length */
    uint32_t nDataCount;

    /*! value  */
    uint32_t* paConfigData;

}ADI_A2B_TWI_DATA_CONFIG;

/*! \struct ADI_A2B_TWI_INFO
    TWI data configuration structure
*/
typedef struct
{
    /*! Driver TWI handle  */
	ADI_TWI_HANDLE adi_twi_hDevice;

    /*! Pointer to ECB struct */
	A2B_ECB       *pEcb;

    /*! TWI Driver Mem  */
    uint8_t ganTwiDriverMemory[ADI_TWI_MEMORY_SIZE];

}ADI_A2B_TWI_INFO;


/*======= P U B L I C P R O T O T Y P E S ========*/

/*============= D A T A =============*/


#endif /* _ADI_A2B_TWIDRIVER_H_ */

/**
 @}
*/

/**
 @}
*/

/*
*
* EOF: $URL$
*
*/


