/****************************************************************************
Copyright (c), 2014-2015 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
*****************************************************************************
 * @file:    adi_a2b_sys.h
 * @brief:   Contains structures and API prototypes of SigmaStudio Framework.
 * @version: $Revision$
 * @date:    $Date$
 * Developed by: Automotive Software and Systems team, Bangalore, India
*****************************************************************************/
/*! \addtogroup ADI_A2B_SYS
 *  @{
 */

#ifndef __ADI_A2B_SYS_H__
#define __ADI_A2B_SYS_H__

/*=============  I N C L U D E S   =============*/
#include "adi_a2b_hal.h"
#include "adi_a2b_datatypes.h"
/*==============  D E F I N E S  ===============*/

#define BUFFER_SIZE   				     (8u)
#define TARGETADDR    				     (0x38u)     /* hardware address */
#define TARGETADDR_1962    			     (0x04u)     /* hardware address of adau1962 DAC */

#define REPORT_ERROR        	         printf

#define ADI_A2B_SYS_MEMSIZE_BYTES        (338+2+298+2+48) /*!< Memory required for system component.This is the sum
                                                           of the memory required for ADC,DAC and GPIO. Extra 2 bytes
                                                           are added to word align the address for next unit */

#define E_ADI_A2B_SYS_SUCCESS            (0U)          /*!< Success */
#define E_ADI_A2B_SYS_FAILURE            (-1)          /*!< Failure */
#define E_ADI_A2B_SYS_INSUFFICIENT_MEM   (-2)          /*!< Insufficient memory */
#define E_ADI_A2B_SYS_CORE_SECONDARY     (1U)          /*!< The core has been configured for secondary. The power
                                                           initialization must happen from primary  */
#define E_ADI_A2B_SYS_POWER_CGUDEV_0     (0U)          /*!< CGU device 0*/
#define E_ADI_A2B_SYS_POWER_CGUDEV_1     (1U)          /*!< CGU device 1*/

#define MAX_CGU_DEVICES                  (2U)
#define ADI_A2B_SYS_POWER_CLKIN          (25U  * 1000000U)   /*!< Definition for external input clock frequency (Hz) */

#define E_ADI_A2B_SYS_DAC_SUCCESS        (0U)                /*!< Enumeration definition for DAC success state */
#define E_ADI_A2B_SYS_DAC_FAILED         (-1)                /*!< Enumeration definition for DAC failure state */

/*=============  D A T A    T Y P E S   =============*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*! \enum ADI_A2B_RESULT
    Execution status
 */
typedef enum
{
 /*!  Success */
  ADI_A2B_SUCCESS,
 /*!  Failure */
  ADI_A2B_FAILURE,
 /*!  Undefined */
  ADI_A2B_UNDEFINED

}ADI_A2B_RESULT;



/*! \enum ADI_A2B_SYS_RESULT
Enumeration for sys result.
*/
typedef enum ADI_A2B_SYS_RESULT
{
    ADI_A2B_SYS_SUCCESS             = E_ADI_A2B_SYS_SUCCESS,
    ADI_A2B_SYS_FAILURE             = E_ADI_A2B_SYS_FAILURE,
    ADI_A2B_SYS_INSUFFICIENT_MEM    = E_ADI_A2B_SYS_INSUFFICIENT_MEM,
    ADI_A2B_SYS_CORE_SECONDARY      = E_ADI_A2B_SYS_CORE_SECONDARY
}ADI_A2B_SYS_RESULT;


/*! \enum ADI_A2B_SYS_POWER_CGUDEV
Enumeration for CGU device number.
*/
typedef enum ADI_A2B_SYS_POWER_CGUDEV
{
    ADI_A2B_SYS_POWER_CGUDEV_0  = E_ADI_A2B_SYS_POWER_CGUDEV_0,  /*!< The API call succeeded. */
    ADI_A2B_SYS_POWER_CGUDEV_1  = E_ADI_A2B_SYS_POWER_CGUDEV_1   /*!< The API call failed. */
}ADI_A2B_SYS_POWER_CGUDEV;


/*! \struct ADI_A2B_SYS_POWER_CONFIG
SigmaStudio system POWER config structure.
*/
typedef struct ADI_A2B_SYS_POWER_CONFIG
{
    ADI_A2B_SYS_POWER_CGUDEV eCGUDev;                           /*!< CGU devide to be configured */
    uint32 nCoreClk;                                            /*!< Core clock value in Hz */
    uint32 nSysClk;                                             /*!< System clock value in Hz */
    bool bSetCoreSysClk;					                    /*!< Boolean flag, if true, sets the
																 core and system clocks, else, sets
																 only the peripheral clocks such as
																 S/PDIF */
}ADI_A2B_SYS_POWER_CONFIG;


typedef void* ADI_A2B_SYS_HANDLE;               		        /*!< Type define for system handle */

/*! \struct ADI_A2B_SYS_CONFIG
System configuration structure.
*/
typedef struct ADI_A2B_SYS_CONFIG
{
    bool                   bProcMaster;                         /*!< Boolean flag indicating if this core is the master. */
}ADI_A2B_SYS_CONFIG;



/*=======  P U B L I C   P R O T O T Y P E S  ========*/

ADI_A2B_SYS_RESULT Power_Init(ADI_A2B_SYS_POWER_CONFIG *pSysPowerConfig);
ADI_A2B_SYS_RESULT adi_a2b_sys_Init(void *pMemBlock, uint32_t const  nMemorySize,ADI_A2B_SYS_CONFIG *pSysConfig);

extern int ADAU_1962_init(void);

/* prototype */
//void ConfigSoftSwitches(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */



#endif    /* __ADI_A2B_SYS_H__ */

/*
 *
 * EOF: $URL:  $
 *
*/
