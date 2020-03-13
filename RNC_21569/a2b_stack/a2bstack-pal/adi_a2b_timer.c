/*******************************************************************************
Copyright (c) 2014 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
*******************************************************************************

   Name       : adi_a2b_timer.c
   
   Description: This file is responsible for handling timer related functions.        
                 
   Functions  :  adi_a2b_TimerOpen()
                 adi_a2b_TimerStart()
                 adi_a2b_TimerStop()
                 adi_a2b_TimerCallbackFunction()
                 adi_a2b_TimerClose()
                 void  adi_a2b_Delay()
                 

   Prepared &
   Reviewed by: Automotive Software and Systems team, 
                IPDC, Analog Devices,  Bangalore, India
                
   @version: $Revision: 3344 $
   @date: $Date: 2015-07-29 08:44:17 +0530 (Wed, 29 Jul 2015) $
               
******************************************************************************/
/*! \addtogroup Target_Dependent Target Dependent
 *  @{
 */

/** @defgroup Timer
 *
 * This module controls timer configuration.Framework uses timer during discovery, I2C transaction and error signal indication.
 * All the interface functions needs to be re-implemented for different processor.
 */

/*! \addtogroup Timer
 *  @{
 */


/*============= I N C L U D E S =============*/

#include "adi_a2b_datatypes.h"
#include "adi_a2b_framework.h"
#include "adi_a2b_timer.h"
#include "adi_a2b_driverprototypes.h"

#include <services/tmr/adi_tmr.h>
#include <services/pwr/adi_pwr.h>
#include "adi_a2b_sys.h"

/*============= D E F I N E S =============*/

/*! System clock for timer */
#define A2B_TIMER_SCLK			(250000000u)

/*! Core clock in Hz for dealy */
#define A2B_TIMER_CCLK			(400000000u)

/*============= D A T A =============*/

/*! Timer handle */
static ADI_TMR_HANDLE   ghTimer[A2B_MAX_TIMERS];

/*============= C O D E =============*/
typedef void (*TIMER_INT_HANDLER_PTR)(void);
/*
** Function Prototype section
*/
static void adi_a2b_TimerCallbackFunction(void* DeviceHandle, uint32_t Event, void* pArg);

/******************************************************************************/
/*!
@brief  This function Initializes timer driver. 

@param [in] nTimerNo        Timer identification number.

@param [in] pUserArgument   User argument for call-back

@return         Return code
                - 0: Success
                - 1: Failure 

*/    
/******************************************************************************/
ADI_MEM_A2B_CODE_NO_CRIT
uint32_t adi_a2b_TimerOpen(uint32_t nTimerNo,void* pUserArgument)
{
    /* Memory required for opening the timer */
    static uint8_t TimerMemory[A2B_MAX_TIMERS][ADI_TMR_MEMORY];
    /* Return value - assume we're going to be successful */
    ADI_TMR_RESULT eTmrResult   =   ADI_TMR_SUCCESS;

    eTmrResult = adi_tmr_Open (
					nTimerNo,
					TimerMemory[nTimerNo],
					ADI_TMR_MEMORY,
					(ADI_CALLBACK)&adi_a2b_TimerCallbackFunction,
					pUserArgument,
					&(ghTimer[nTimerNo])
                    );

    eTmrResult = adi_tmr_SetMode(
                    ghTimer[nTimerNo],
					ADI_TMR_MODE_CONTINUOUS_PWMOUT);
    
    eTmrResult = adi_tmr_SetIRQMode(
                    ghTimer[nTimerNo],
                    ADI_TMR_IRQMODE_PERIOD);

    eTmrResult = adi_tmr_EnableGracefulStop(
		             ghTimer[nTimerNo],
		             false);

    eTmrResult = adi_tmr_SetClkInSource(ghTimer[nTimerNo],ADI_TMR_CLKIN_SYSCLK);

    return ((uint32_t)eTmrResult);
}

/****************************************************************************/
/*!
@brief  This function starts specified timer channel.
        Timer period shall be in micro-seconds

@param [in] nTimerNo    Timer number
@param [in] nTime       Time period in micro-seconds

@return         Return code
                - 0: Success
                - 1: Failure 

*/    
/******************************************************************************/
ADI_MEM_A2B_CODE_CRIT
uint32_t adi_a2b_TimerStart(uint32_t nTimerNo, uint32_t nTime)
{ 
    uint32_t nWidth = 0u,nPeriod = 0u, nReturnValue = 0u;
    uint32_t nSClk = A2B_TIMER_SCLK, nSClk0, nSClk1;
    ADI_TMR_RESULT eTmrResult   =   ADI_TMR_SUCCESS;
    
    /* Calculate  period and width  from system clock */
    nReturnValue = (uint32_t)adi_pwr_GetSystemFreq (ADI_A2B_SYS_POWER_CGUDEV_0, &nSClk, &nSClk0, &nSClk1);

    if(nReturnValue != 0u)
    {
    	nSClk = A2B_TIMER_SCLK;
    }

    /*! In micro seconds  */
    nPeriod = ((nSClk)/1000000u)*nTime;
    nWidth  = (nPeriod/(uint32_t)1u);

    eTmrResult = adi_tmr_SetPeriod(
                    ghTimer[nTimerNo],
                    nPeriod);

    eTmrResult = adi_tmr_SetWidth(
                    ghTimer[nTimerNo],
                    nWidth);


    eTmrResult = adi_tmr_Enable(
                    ghTimer[nTimerNo],
                    true);

    return(eTmrResult);
    
}
/******************************************************************************/
/*!

@brief  This function stops the specified timer channel immediately.

@param [in] nTimerNo    Timer number

@return         Return code
                - 0: Success
                - 1: Failure 

*/ 
/*****************************************************************************/
ADI_MEM_A2B_CODE_CRIT
uint32_t adi_a2b_TimerStop(uint32_t nTimerNo)
{ 
    ADI_TMR_RESULT eTmrResult   =   ADI_TMR_SUCCESS;

    eTmrResult = adi_tmr_Enable(
                    ghTimer[nTimerNo],
                    false);

    return((uint32_t)eTmrResult);
}

/****************************************************************************/
/*!

@brief      This function terminates timer service. Timer shall be reset

@param [in] nTimerNo    Timer number
    
@return         Return code
                - 0: Success
                - 1: Failure 
*/    
/*****************************************************************************/
ADI_MEM_A2B_CODE_NO_CRIT
uint32_t adi_a2b_TimerClose(uint32_t nTimerNo)
{
	/* Return value - assume we're going to be successful */
	ADI_TMR_RESULT eTmrResult   =   ADI_TMR_SUCCESS;

    eTmrResult = adi_tmr_Close(ghTimer[nTimerNo]);

    return((uint32_t)eTmrResult);
}

/********************************************************************************/
/*!
@brief This function implements software delay.

@param [in] nTime Delay in Milli-seconds(ms)

@return    void 
    
*/
/***********************************************************************************/
ADI_MEM_A2B_CODE_CRIT
void  adi_a2b_Delay(uint32_t nTime)
{
    uint32_t nDelayInCycles, nReturnValue;
    uint32_t nCClk = A2B_TIMER_CCLK;

    nReturnValue = (uint32_t)adi_pwr_GetCoreClkFreq (ADI_A2B_SYS_POWER_CGUDEV_0, &nCClk);

    if(nReturnValue != 0u)
    {
    	nCClk = A2B_TIMER_CCLK;
    }
    /* nCount represents the number of execution cycle  */
    nDelayInCycles = (nCClk/(10000u))*nTime;
    
    /* Delay implementation */
    while(nDelayInCycles--)
    {
    }
}



/*! \addtogroup Timer_Internal_Functions Timer Internal Functions
 *  @{
 */
/******************************************************************************/
/*!
@brief  Timer call back function. It is invoked upon timer expire

@param [in] DeviceHandle     Timer  handle
@param [in] Event            Interrupt event
@param [in] pArg             user argument if any
    
@return     none
*/    
/*****************************************************************************/
ADI_MEM_A2B_CODE_CRIT
static void adi_a2b_TimerCallbackFunction(void* DeviceHandle, uint32_t Event, void* pArg)
{
    ADI_A2B_TIMER_HANDLER_PTR pTimerHandle = (ADI_A2B_TIMER_HANDLER_PTR)DeviceHandle ;
  
    /* Set time out */
    if(DeviceHandle != NULL)
    {
        (pTimerHandle->pCallbackhandle)(pTimerHandle);
    }

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


