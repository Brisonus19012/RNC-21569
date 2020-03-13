/*******************************************************************************
Copyright (c) 2014 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
******************************************************************************
* @file: adi_a2b_driverprototypes.h
* @brief: This file contains all the abstracted driver prototypes 
* @version: $Revision: 3599 $
* @date: $Date: 2015-09-18 18:20:21 +0530 (Fri, 18 Sep 2015) $
* Developed by: Automotive Software and Systems team, Bangalore, India
*****************************************************************************/

/*! \addtogroup PAL_BF PAL_BF
* @{
*/

#ifndef _ADI_A2B_DRIVERPROTOPTYPES_H_
#define _ADI_A2B_DRIVERPROTOPTYPES_H_

/*============= I N C L U D E S =============*/
#include "a2bstack/inc/a2b/pal.h"
#include "adi_a2b_twidriver.h"
/*============= D E F I N E S =============*/

/*============= E X T E R N A L S ============*/

/*============= D A T A T Y P E S=============*/

/** 
 @}
*/

/*======= P U B L I C P R O T O T Y P E S ========*/


/* Timer */
uint32_t adi_a2b_TimerOpen(uint32_t nTimerNo,void* pUserArgument);
uint32_t adi_a2b_TimerStop(uint32_t nTimerNo);
uint32_t adi_a2b_TimerClose(uint32_t nTimerNo);
uint32_t adi_a2b_TimerStart(uint32_t nTimerNo, uint32_t nTime);
void  adi_a2b_Delay(uint32_t nTime);

/* TWI / I2C */
a2b_Handle adi_a2b_TwiOpen(A2B_ECB* ecb, void* pUserArgument);
uint32_t adi_a2b_TwiClose(a2b_Handle hA2bTwiHandle);
uint32_t adi_a2b_TwiRead(a2b_Handle A2bTwiHandle, uint16_t nDeviceAddress, uint16_t nRead, uint8_t* pData);
uint32_t adi_a2b_TwiWrite(a2b_Handle hA2bTwiHandle, uint16_t nDeviceAddress, uint16_t nWrite, uint8_t* wBuf);
uint32_t adi_a2b_TwiWriteRead(a2b_Handle hA2bTwiHandle, uint16_t nDeviceAddress,
		uint16_t nWrite, uint8_t* wBuf,
		uint16_t nRead, uint8_t* rBuf);
uint32_t adi_a2b_TwiRead8(uint8_t nTWIDeviceNo, uint8_t nDeviceAddress, uint8_t nRegAddress, uint8_t* pData);
uint32_t adi_a2b_TwiWrite8(uint8_t nTWIDeviceNo, uint8_t nDeviceAddress, uint8_t nRegAddress,uint8_t nData);
uint32_t adi_a2b_TwiUpdateRate(a2b_Handle hA2bTwiHandle , uint8_t bRate);
                
uint32_t adi_a2b_TwiGenericWrite(a2b_Handle hA2bTwiHandle, uint8_t nDeviceAddress, uint32_t pRegBuff[] ,uint32_t paConfigDataBuff[]);
uint32_t adi_a2b_TwiGenericRead(a2b_Handle hA2bTwiHandle, uint8_t nDeviceAddress, uint32_t pRegBuf[] , uint32_t paConfigData[]);
uint32_t adi_a2b_TwiGenericBlockWrite(a2b_Handle hA2bTwiHandle, uint8_t nDeviceAddress, ADI_A2B_TWI_ADDR_CONFIG sRegConfig ,ADI_A2B_TWI_DATA_CONFIG sDataConfig);
uint32_t adi_a2b_TwiGenericBlockRead(a2b_Handle hA2bTwiHandle, uint8_t nDeviceAddress, ADI_A2B_TWI_ADDR_CONFIG sRegConfig ,ADI_A2B_TWI_DATA_CONFIG sDataConfig);


/*============= D A T A =============*/

#endif /* _ADI_A2B_EXTERNS_H_ */
/*
*
* EOF: $URL$
*
*/


