/*********************************************************************************

Copyright(c) 2019 Analog Devices, Inc. All Rights Reserved.

This software is proprietary and confidential.  By using this software you agree
to the terms of the associated Analog Devices License Agreement.

*********************************************************************************/

/*****************************************************************************
 * SPORT_TDM_Mode.c
 *****************************************************************************/

/*=============  I N C L U D E S   =============*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/platform.h>
#include <sys/adi_core.h>
#include "adi_initialize.h"
#include <services/int/adi_int.h>
#include <drivers/sport/adi_sport.h>
#include "math.h"
#include <SRU.h>
#include "RNC_21569.h"



extern void ConfigSoftSwitches_ADC_DAC(void);
extern void ConfigSoftSwitches_ADAU_Reset(void);

void Switch_Configurator(void);
void SRU_Init(void);


/*
 * Prepares Switch configuration.
 *
 * Parameters
 *  None
 *
 * Returns
 *  None
 *
 */
void Switch_Configurator()
{
	int delay11=0xffff;


	/* Software Switch Configuration for Enabling ADC-DAC */
	ConfigSoftSwitches_ADC_DAC();

	while(delay11--)
	{
		asm("nop;");
	}

	/* Software Switch Configuration for Re-Setting ADC-DAC  */
	ConfigSoftSwitches_ADAU_Reset();


	/* wait for Codec to up */
	delay11=0xffff;
	while(delay11--)
	{
		asm("nop;");
	}
}

/*
 * Prepares SRU configuration.
 *
 * Parameters
 *  None
 *
 * Returns
 *  None
 *
 */
void SRU_Init()
{
	*pREG_PADS0_DAI0_IE=0x1fffff;
	*pREG_PADS0_DAI1_IE=0x1ffffe;

    SRU2(HIGH,DAI1_PBEN05_I);        /* DAI1_PBEN05 set as input  */
    SRU2(HIGH,DAI1_PBEN04_I);        /* DAI1_PBEN04 set as input  */
    SRU2(DAI1_PB05_O,SPT4_ACLK_I);  /* DAC clock to SPORT 4A     */
    SRU2(DAI1_PB04_O,SPT4_AFS_I);   /* DAC FS to SPORT 4A        */

    SRU2(SPT4_AD0_O,DAI1_PB01_I);   /* SPORT 4A to DAC           */
    SRU2(HIGH,DAI1_PBEN01_I);       /* DAI1_PBEN01 set as output */

    SRU(DAI0_PB03_O, SPT0_ACLK_I);  /* PCGA to SPORT0 CLK (CLK)  */
	SRU(DAI0_PB04_O, SPT0_AFS_I);   /* PCGA to SPORT1 FS (FS)    */

	SRU(DAI0_PB01_O,SPT0_AD0_I);    /* A2B digital to SPORT 0A  */
    SRU(LOW,DAI0_PBEN01_I);

}


a2b_App_t gApp_Info;

void main(int argc, char *argv[])
{
	/**
	 * Initialize managed drivers and/or services that have been added to
	 * the project.
	 * @return zero on success
	 */
	uint32_t Result=0;

	adi_initComponents();

	/* Begin adding your custom code here */

	Result = adi_pwr_Init(ADI_PWR_CGU0, 25000000);
	if(Result != ADI_PWR_SUCCESS)
	{
		REPORT_ERROR("Failed to initialize Power Service for CGU0\n");
	}

	Switch_Configurator();

	SRU_Init();

	Result = adi_a2b_SystemInit();  // system/platform specific initialization
	if(Result != 0)
	{
		REPORT_ERROR("Failed to initialize system\n");
	}

	Result = a2b_setup(&gApp_Info); // A2B Network Setup. Performs discovery and configuration of A2B nodes and its peripherals
	if (Result)
	{
		assert(Result == 0);        // failed to setup A2B network
	}


	while(1)
	{
		if(InputReady)
		{
			InputReady = 0;
		}
		Result = a2b_fault_monitor(&gApp_Info);// Monitor a2b network for faults and initiate re-discovery if enabled
		if (Result != 0)                       // condition to exit the program
		{
			DEBUG_INFORMATION("Example failed.\n");
			break;
		}
	}

}

