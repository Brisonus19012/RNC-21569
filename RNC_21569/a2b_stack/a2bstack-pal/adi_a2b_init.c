/*******************************************************************************
Copyright (c) 2014 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
******************************************************************************

   Name       : adi_a2b_init.c
   
   Description: This file contains functions which initializes host/target processor  
                       
                 
   Functions  : adi_a2b_SystemInit()
                 

   Prepared &
   Reviewed by: Automotive Software and Systems team, 
                IPDC, Analog Devices,  Bangalore, India
                
   @version: $Revision: 3626 $
   @date: $Date: 2015-10-05 14:04:13 +0530 (Mon, 05 Oct 2015) $
               
******************************************************************************/
/*! \addtogroup Target_Dependent Target Dependent
 *  @{
 */

/*! \addtogroup System_Init System Init
 *  @{
 */

/*============= I N C L U D E S =============*/

#include "adi_a2b_datatypes.h"
#include "adi_a2b_sys.h"
#include "adi_a2b_sportdriver.h"
#include <services/spu/adi_spu.h>


#if A2B_PRINT_FOR_DEBUG
#include <stdio.h>
#endif
/*============= D E F I N E S =============*/

static int SPU_init(void);

/*============= D A T A =============*/

uint8 aSysMemBuf[ADI_A2B_SYS_MEMSIZE_BYTES];

static ADI_SPU_HANDLE      ghSpu;                         /* SPU handle */
uint8_t                    SpuMemory[ADI_SPU_MEMORY_SIZE];/* Memory required for the SPU operation */

#define SPORT_0A_SPU  			        13
#define SPORT_4A_SPU  			        21
#define SPORT_0A_DMA_SPU  			    49
#define SPORT_4A_DMA_SPU  			    57

/*============= C O D E =============*/
/*
** Function Prototype section
*/
/*
** Function Definition section
*/

/*
 * Prepares SPU configuration.
 *
 * Parameters
 *  None
 *
 * Returns
 *  None
 *
 */
int SPU_init(void)
{
    if(adi_spu_Init(0, SpuMemory, NULL, NULL, &ghSpu) != ADI_SPU_SUCCESS)
    {
    	printf("Failed to initialize SPU service\n");
		return 1;
    }

    /* Make SPORT 0A to generate secure transactions */
	if(adi_spu_EnableMasterSecure(ghSpu, SPORT_0A_SPU, true) != ADI_SPU_SUCCESS)
	{
		printf("Failed to enable Master secure for SPORT0A\n");
		return 1;
	}

	/* Make SPORT 4A to generate secure transactions */
	if(adi_spu_EnableMasterSecure(ghSpu, SPORT_4A_SPU, true) != ADI_SPU_SUCCESS)
	{
		printf("Failed to enable Master secure for SPORT4A\n");
		return 1;
	}

    /* Make SPORT 0A DMA to generate secure transactions */
    if(adi_spu_EnableMasterSecure(ghSpu, SPORT_0A_DMA_SPU, true) != ADI_SPU_SUCCESS)
    {
    	printf("Failed to enable Master secure for SPORT0A\n");
		return 1;
    }

    /* Make SPORT 4A DMA to generate secure transactions */
    if(adi_spu_EnableMasterSecure(ghSpu, SPORT_4A_DMA_SPU, true) != ADI_SPU_SUCCESS)
    {
    	printf("Failed to enable Master secure for SPORT4A\n");
		return 1;
    }

    return 0;

}

 
/********************************************************************************/
/*!
@brief This function does the system initialization. Sets Core and system clock

@param [in] none
   
    
@return     ADI_A2B_RESULT
            - ADI_A2B_FAILURE : Failure(If any of the peripheral initialization fails)
            - ADI_A2B_SUCEESS : Success    
    
*/
/***********************************************************************************/
//ADI_MEM_A2B_CODE_CRIT
a2b_HResult adi_a2b_SystemInit(void)
{
    ADI_A2B_RESULT      eResult = ADI_A2B_SUCCESS;
    ADI_A2B_SYS_CONFIG  oA2bSysConfig;
    ADI_A2B_SYS_RESULT	eSysResult;
    int                 sResult;

    adi_a2b_InitPCGForAD24xx(16u);

	oA2bSysConfig.bProcMaster = true;

	eSysResult = adi_a2b_sys_Init(aSysMemBuf, ADI_A2B_SYS_MEMSIZE_BYTES, &oA2bSysConfig);
	if(eSysResult != ADI_A2B_SYS_SUCCESS)
	{
		eResult = ADI_A2B_FAILURE;
	}

	sResult = SPU_init();
	if(sResult != 0)
	{
		eResult = ADI_A2B_FAILURE;
	}

    return eResult;        
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

