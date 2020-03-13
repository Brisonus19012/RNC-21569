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


int int_SP4ABuffer1[DAC_BUFFER_SIZE];
int int_SP4ABuffer2[DAC_BUFFER_SIZE];
int int_SP0ABuffer1[A2B_BUFFER_SIZE];
int int_SP0ABuffer2[A2B_BUFFER_SIZE];



extern void ConfigSoftSwitches_ADC_DAC(void);

extern void ConfigSoftSwitches_ADAU_Reset(void);


/* Destination SPORT PDMA Lists */
ADI_PDMA_DESC_LIST iDESC_LIST_1_SP4A;
ADI_PDMA_DESC_LIST iDESC_LIST_2_SP4A;

/* Source SPORT PDMA Lists */
ADI_PDMA_DESC_LIST iSRC_LIST_1_SP0A;
ADI_PDMA_DESC_LIST iSRC_LIST_2_SP0A;


/* Prepares descriptors for SPORT DMA */
static void PrepareDescriptors (void);

/* Count to track the number of callBacks for SPORT transfer */
volatile uint8_t CallbackCount = 0;
uint8_t InputReady = 0;

//volatile uint32_t TestCallbackCount = 0;

/* Memory required for SPORT */
static uint8_t SPORTMemory4A[ADI_SPORT_MEMORY_SIZE];
static uint8_t SPORTMemory0A[ADI_SPORT_MEMORY_SIZE];

/* SPORT Handle */
static ADI_SPORT_HANDLE hSPORTDev4ATx;//TX
static ADI_SPORT_HANDLE hSPORTDev0ARx;//RX

/* Global SPORT Array Handle */
static ADI_SPORT_HANDLE SportTxDai1Array[1]= {NULL};
static ADI_SPORT_HANDLE SportRxDai1Array[1]= {NULL};

/*GLobal sport group handle */
static ADI_GLOBAL_SPORT_HANDLE hDai1Group0Tx;
static ADI_GLOBAL_SPORT_HANDLE hDai1Group1Rx;


void Switch_Configurator(void);

static int Sport_Init(void);
static int Sport_Stop(void);
static void PrepareDescriptors (void);



static void SPORTCallback(void *pAppHandle, uint32_t nEvent, void *pArg)
{
	ADI_SPORT_RESULT eResult;
    /* CASEOF (event type) */
    switch (nEvent)
    {
        /* CASE (buffer processed) */
        case ADI_SPORT_EVENT_BUFFER_PROCESSED:
        		//TestCallbackCount += 1;
        		CallbackCount +=1;
        		InputReady = 1;

        		break;
        default:
        	 break;
    }
    /* return */
}

/*
 * Prepares descriptors for Memory DMA copy.
 *
 * Parameters
 *  None
 *
 * Returns
 *  None
 *
 */

static void PrepareDescriptors (void)
{

	iDESC_LIST_1_SP4A.pStartAddr	= (int *)int_SP4ABuffer1;
	iDESC_LIST_1_SP4A.Config		= ENUM_DMA_CFG_XCNT_INT ;
	iDESC_LIST_1_SP4A.XCount		= DAC_BUFFER_SIZE;
	iDESC_LIST_1_SP4A.XModify		= 8;
	iDESC_LIST_1_SP4A.YCount		= 0;
	iDESC_LIST_1_SP4A.YModify		= 0;
	iDESC_LIST_1_SP4A.pNxtDscp		= &iDESC_LIST_2_SP4A;

	iDESC_LIST_2_SP4A.pStartAddr	= (int *)int_SP4ABuffer2;
	iDESC_LIST_2_SP4A.Config		= ENUM_DMA_CFG_XCNT_INT ;
	iDESC_LIST_2_SP4A.XCount		= DAC_BUFFER_SIZE;
	iDESC_LIST_2_SP4A.XModify		= 8;
	iDESC_LIST_2_SP4A.YCount		= 0;
	iDESC_LIST_2_SP4A.YModify		= 0;
	iDESC_LIST_2_SP4A.pNxtDscp		= &iDESC_LIST_1_SP4A;

	iSRC_LIST_1_SP0A.pStartAddr		=(int *)int_SP0ABuffer1;
	iSRC_LIST_1_SP0A.Config			= ENUM_DMA_CFG_XCNT_INT ;
	iSRC_LIST_1_SP0A.XCount			= A2B_BUFFER_SIZE;
	iSRC_LIST_1_SP0A.XModify		= 16;
	iSRC_LIST_1_SP0A.YCount			= 0;
	iSRC_LIST_1_SP0A.YModify		= 0;
	iSRC_LIST_1_SP0A.pNxtDscp		= &iSRC_LIST_2_SP0A;

	iSRC_LIST_2_SP0A.pStartAddr		=(int *)int_SP0ABuffer2;
	iSRC_LIST_2_SP0A.Config			= ENUM_DMA_CFG_XCNT_INT;
	iSRC_LIST_2_SP0A.XCount			= A2B_BUFFER_SIZE;
	iSRC_LIST_2_SP0A.XModify		= 16;
	iSRC_LIST_2_SP0A.YCount			= 0;
	iSRC_LIST_2_SP0A.YModify		= 0;
	iSRC_LIST_2_SP0A.pNxtDscp		= &iSRC_LIST_1_SP0A;
}

static int Sport_Init()
{
    /* SPORT return code */
    ADI_SPORT_RESULT    eResult;

	/* Open the SPORT Device 4A */
	eResult = adi_sport_Open(SPORT_DEVICE_4A,ADI_HALF_SPORT_A,ADI_SPORT_DIR_TX, ADI_SPORT_MC_MODE, SPORTMemory4A,ADI_SPORT_MEMORY_SIZE,&hSPORTDev4ATx);
	CHECK_RESULT(eResult);
	/* Configure the data,clock,frame sync and MCTL of SPORT Device 4A*/
	eResult = adi_sport_ConfigData(hSPORTDev4ATx,ADI_SPORT_DTYPE_SIGN_FILL,31,false,false,false);
	CHECK_RESULT(eResult);
	eResult = adi_sport_ConfigClock(hSPORTDev4ATx,100,false,true,false);
	CHECK_RESULT(eResult);
	eResult = adi_sport_ConfigFrameSync(hSPORTDev4ATx,0,false,false,false,true,false,true);
	CHECK_RESULT(eResult);
	eResult = adi_sport_ConfigMC(hSPORTDev4ATx,1u,7u,0u,true);
	CHECK_RESULT(eResult);
	eResult = adi_sport_SelectChannel(hSPORTDev4ATx,0u,7u);
	CHECK_RESULT(eResult);

	/* Open the SPORT Device 0A*/
	eResult = adi_sport_Open(SPORT_DEVICE_0A,ADI_HALF_SPORT_A,ADI_SPORT_DIR_RX, ADI_SPORT_MC_MODE, SPORTMemory0A,ADI_SPORT_MEMORY_SIZE,&hSPORTDev0ARx);
	CHECK_RESULT(eResult);
	/* Configure the data,clock,frame sync and MCTL of SPORT Device 0A*/
	eResult = adi_sport_ConfigData(hSPORTDev0ARx,ADI_SPORT_DTYPE_SIGN_FILL,31,false,false,false);
	CHECK_RESULT(eResult);
	eResult = adi_sport_ConfigClock(hSPORTDev0ARx,100,false,true,false);
	CHECK_RESULT(eResult);
	eResult = adi_sport_ConfigFrameSync(hSPORTDev0ARx,0,false,false,false,false,false,true);
	CHECK_RESULT(eResult);
	eResult = adi_sport_ConfigMC(hSPORTDev0ARx,0u,15u,0u,false);
	CHECK_RESULT(eResult);
	eResult = adi_sport_SelectChannel(hSPORTDev0ARx,0u,15u);
	CHECK_RESULT(eResult);

    /**************************************************Sport Global Group Array Handle***********************************************************/

	SportTxDai1Array[0]= hSPORTDev4ATx;    /*Tx group*/
    SportRxDai1Array[0]= hSPORTDev0ARx;    /*Rx group*/

	/* Prepare descriptors */
	PrepareDescriptors();

	/* Submit the first buffer for Rx.  */
	eResult = adi_sport_DMATransfer(hSPORTDev0ARx,&iSRC_LIST_1_SP0A,(DMA_NUM_DESC),ADI_PDMA_DESCRIPTOR_LIST, ADI_SPORT_CHANNEL_PRIM);
	CHECK_RESULT(eResult);
	/* Submit the first buffer for Tx.  */
	eResult = adi_sport_DMATransfer(hSPORTDev4ATx,&iDESC_LIST_1_SP4A,(DMA_NUM_DESC),ADI_PDMA_DESCRIPTOR_LIST, ADI_SPORT_CHANNEL_PRIM);
	CHECK_RESULT(eResult);

	/**************************************************Create Global Groups*****************************************************/
	eResult = adi_sport_CreateGlobalGroup(SportTxDai1Array,1u,&hDai1Group0Tx,false,true);
	CHECK_RESULT(eResult);

	eResult = adi_sport_CreateGlobalGroup(SportRxDai1Array,1u,&hDai1Group1Rx,false,true);
	CHECK_RESULT(eResult);

	/* Register Global callback for RX group*/
	eResult = adi_sport_GlobalRegisterCallback(hDai1Group1Rx,SPORTCallback,NULL);
	CHECK_RESULT(eResult);

	/* Global sport enable */
	eResult = adi_sport_GlobalEnable(true);
	CHECK_RESULT(eResult);

	return eResult;

}

static int Sport_Stop(void)
{
    /* SPORT return code */
    ADI_SPORT_RESULT    eResult;

    /*Stop the DMA transfer of Tx sport group */
	eResult = adi_sport_GlobalStopDMATransfer(hDai1Group0Tx);
	CHECK_RESULT(eResult);

	/*Stop the DMA transfer of Rx sport group*/
	eResult = adi_sport_GlobalStopDMATransfer(hDai1Group1Rx);
	CHECK_RESULT(eResult);

	/* Destroy TX sport group */
	eResult = adi_sport_DestroyGlobalGroup(hDai1Group0Tx);
	CHECK_RESULT(eResult);

	/* Destroy RX sport group */
	eResult = adi_sport_DestroyGlobalGroup(hDai1Group1Rx);
	CHECK_RESULT(eResult);

	/* DeRegister Global callback for RX group*/
	eResult = adi_sport_GlobalRegisterCallback(hDai1Group1Rx,NULL,NULL);
	CHECK_RESULT(eResult);

	/* Global sport Disable */
	eResult = adi_sport_GlobalEnable(false);
	CHECK_RESULT(eResult);

	/*Close Sport Device 4B */
	eResult = adi_sport_Close(hSPORTDev0ARx);
	CHECK_RESULT(eResult);
	/*Close Sport Device 4A */
	eResult = adi_sport_Close(hSPORTDev4ATx);
	CHECK_RESULT(eResult);

	return eResult;
}

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

void ProcessBuffers(void)
{

	int  i;

	if(CallbackCount==1)
	{
	   for(i=0;i<24;i++)
	   {
		   /*Copy ADC buffer to DAC buffer */
		   int_SP4ABuffer1[8*i]  =int_SP0ABuffer1[16*i];
		   int_SP4ABuffer1[8*i+1]=int_SP0ABuffer1[16*i+1];
		   int_SP4ABuffer1[8*i+2]=int_SP0ABuffer1[16*i+2];
		   int_SP4ABuffer1[8*i+3]=int_SP0ABuffer1[16*i+3];
		   int_SP4ABuffer1[8*i+4]=int_SP0ABuffer1[16*i+4];
		   int_SP4ABuffer1[8*i+5]=int_SP0ABuffer1[16*i+5];
		   int_SP4ABuffer1[8*i+6]=int_SP0ABuffer1[16*i+6];
		   int_SP4ABuffer1[8*i+7]=int_SP0ABuffer1[16*i+7];

	   }
	}

	if(CallbackCount==2)
	{
		   for(i=0;i<24;i++)
		   {
			   /*Copy ADC buffer to DAC buffer */
			   int_SP4ABuffer2[8*i]  =int_SP0ABuffer2[16*i];
			   int_SP4ABuffer2[8*i+1]=int_SP0ABuffer2[16*i+1];
			   int_SP4ABuffer2[8*i+2]=int_SP0ABuffer2[16*i+2];
			   int_SP4ABuffer2[8*i+3]=int_SP0ABuffer2[16*i+3];
			   int_SP4ABuffer2[8*i+4]=int_SP0ABuffer2[16*i+4];
			   int_SP4ABuffer2[8*i+5]=int_SP0ABuffer2[16*i+5];
			   int_SP4ABuffer2[8*i+6]=int_SP0ABuffer2[16*i+6];
			   int_SP4ABuffer2[8*i+7]=int_SP0ABuffer2[16*i+7];

		   }
		   CallbackCount = 0;
	}

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

	/* Switch Configuration */
//	Switch_Configurator();

	/* SPORT Initialization */
	if (Result==0u)
	{
		Result=Sport_Init();
	}

	while(1)
	{
		if(InputReady)
		{
			InputReady = 0;
			ProcessBuffers();

		}
/*		Result = a2b_fault_monitor(&gApp_Info);// Monitor a2b network for faults and initiate re-discovery if enabled
		if (Result != 0)                       // condition to exit the program
		{
			DEBUG_INFORMATION("Example failed.\n");
			break;
		}*/
	}

}

