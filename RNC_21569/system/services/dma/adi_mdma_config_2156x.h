/*********************************************************************************

Copyright(c) 2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/
/*!
 * @file    adi_mdma_config_2156x.h
 * @brief   Memory DMA Manager configuration macros for ADSP-2156x processor family
 * @version $Revision: 62246 $
 * @date    $Date: 2019-07-18 05:50:49 -0400 (Thu, 18 Jul 2019) $
 * @details
 *			This file contains the static configuration macros for the MDMA service.  
 *
 */
 
/** @defgroup MDMA_Config MDMA Manager Static Configuration
 *  @ingroup  MDMA_Manager
 */
 
#ifndef __ADI_MDMA_CONFIG_2156X_H__
#define __ADI_MDMA_CONFIG_2156X_H__

/** @ingroup MDMA_Config
 *  When this macro is set to 1 (default), the API adi_mdma_Copy1D() uses the most optimum MSIZE value automatically based on the DMA start address 
 *	and count value. The MSIZE value supplied by the user is ignored. Note that bandwidth limit/measure/monitor APIs can't be used with this macro enabled.
 *  So, the static configuration macro ADI_MDMA_CFG_ENABLE_BANDWIDTH_FUNCTIONS should be set to 0 with this macro enabled. 
 */
#define ADI_MDMA_CFG_MSIZE_AUTO							(1u)

/** @ingroup MDMA_Config
 *	By default, when using the API adi_mdma_CopyList(), the DMA done interrupt in list mode is generated after the end of the last work unit in the descriptor 
 *	list irrespective of the bCallbackWhenDone descriptor parameter. However, the configuration macro ADI_MDMA_CFG_LIST_MULTIPLE_CALLBACKS_ENABLE 
 *	can be set to 1 (set to zero by default) to allow generation of interrupt for more than one descriptors as per the configuration of bCallbackWhenDone parameter. 
 *	Note that enabling this macro might result in a race condition for smaller work units and consequently one or more DMA interrupts might be missed. 
 *  It is user's responsibility to take care of such conditions in the application.   
 */
#define ADI_MDMA_CFG_LIST_MULTIPLE_CALLBACKS_ENABLE		(0u)

/** @ingroup MDMA_Config
 *	This macro should be set to use the APIs adi_mdma_BWLimit()/adi_mdma_BWMonitor()/adi_mdma_BWMeasure(). 
 *	This macro should be cleared (default) when ADI_MDMA_CFG_MSIZE_AUTO is set. 
 */
#define ADI_MDMA_CFG_ENABLE_BANDWIDTH_FUNCTIONS			(0u)		

#endif


/*****/

/*@}*/

