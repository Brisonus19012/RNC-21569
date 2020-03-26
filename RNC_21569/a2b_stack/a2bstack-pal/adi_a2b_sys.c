/*******************************************************************************
Copyright (c) 2014 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
******************************************************************************
 * @file:    adi_a2b_sys.c
 * @brief:   System component APIs are defined in this file
 * @version: $Revision: 6145 $
 * @date:    $Date: 2014-12-18 15:15:45 +0530 (Thu, 18 Dec 2014) $
 * Developed by: Automotive Software and Systems team, Bangalore, India
*****************************************************************************/
/*! \addtogroup ADI_A2B_SYS
 *  @{
 */

/*============= I N C L U D E S =============*/

#include "adi_a2b_sys.h"
#include <sys/adi_core.h>
#include "ADAU_1962Common.h"
#include "adi_a2b_pal.h"
#include <drivers/twi/adi_twi.h>

/*============= D E F I N E S =============*/

extern void ConfigSoftSwitches_ADC_DAC(void);
extern void ConfigSoftSwitches_ADAU_Reset(void);

int ADAU_1962_init(void);
void Switch_Configurator(void);

static int ADAU_1962_Pllinit(void);
static void Write_TWI_8bit_Reg(unsigned char Reg_ID, unsigned char Tx_Data);
static unsigned char Read_TWI_8bit_Reg(unsigned char Reg_ID);

static ADI_A2B_SYS_RESULT CODEC_Init(void);
static ADI_PWR_RESULT CheckClock(ADI_A2B_SYS_POWER_CONFIG *pSysPowerConfig);


/*============= C O D E =============*/

/*
** Function Prototype section
** (static-scoped functions)
*/


#define PORT_CODEC_RESET    (ADI_A2B_HAL_GPIO_PORT_A)            /*!< Port used for resetting the ADC and DAC. This is
                                                                     a hard wired port number for CODEC resetting. */
#define PIN_CODEC_RESET     (ADI_A2B_HAL_GPIO_PIN_3)            /*!< Pin used for resetting the ADC and DAC. This
                                                                     is a hard wired pin number for CODEC resetting. */
#ifndef _TESSY_
#define WAIT_CLOCK_CYCLES(n)      \
        do                        \
        {                         \
			do                    \
			{                     \
            (n)--;                \
			}while((n)>0);        \
        }while(0)
#else	/* _TESSY_ */
#define WAIT_CLOCK_CYCLES(n)      \
			do                    \
			{                     \
            (n)--;                \
			}while((n)>0);
#endif	/* _TESSY_ */

#define CODEC_RESET_DELAY    (100000U)

/*============= D A T A =============*/

struct Config_Table
{
	short Reg_Add;
	char  Value;
};

char Config_read_DAC[28];

/* Dev buffer for configuring ADC-DAC through TWI*/
static uint8_t devBuffer[BUFFER_SIZE];

struct Config_Table Config_array_DAC[28] = {
		   	    {     ADAU1962_PDN_CTRL_1,		0x00},
		   	    {     ADAU1962_PDN_CTRL_2,	    0xff},
		   	    {     ADAU1962_PDN_CTRL_3,	    0x0f},
		   	    {     ADAU1962_DAC_CTRL0,		0x19},  /* TDM8,48khz */
		   	    {     ADAU1962_DAC_CTRL1,		0x22},  /* DLRCLK/DBCLK as Slave,latch data in DBCLK falling edge */
		   	    {     ADAU1962_DAC_CTRL2,		0x00},
		   	    {     ADAU1962_DAC_MUTE1,	    0x0},
		   	    {     ADAU1962_DAC_MUTE2,	    0x00},
		   	    {     ADAU1962_MSTR_VOL,		0x00},
			    {     ADAU1962_DAC1_VOL,	    0x00},
			    {     ADAU1962_DAC2_VOL,		0x00},
				{     ADAU1962_DAC3_VOL,		0x00},
				{     ADAU1962_DAC4_VOL,		0x00},
				{     ADAU1962_DAC5_VOL,		0x00},
				{     ADAU1962_DAC6_VOL,		0x00},
				{     ADAU1962_DAC7_VOL,		0x00},
				{     ADAU1962_DAC8_VOL,	    0x00},
				{     ADAU1962_DAC9_VOL,		0x00},
				{     ADAU1962_DAC10_VOL,		0x00},
				{     ADAU1962_DAC11_VOL,		0x00},
				{     ADAU1962_DAC12_VOL,		0x00},
				{     ADAU1962_PAD_STRGTH,		0x00},
				{     ADAU1962_DAC_PWR1,		0xaa},
				{     ADAU1962_DAC_PWR2,		0xaa},
				{     ADAU1962_DAC_PWR3,		0xaa},
				{     ADAU1962_PDN_CTRL_2,	    0x00},
				{     ADAU1962_PDN_CTRL_3,	    0x00},
				{     ADAU1962_DAC_CTRL0,		0x18}

};


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
 * Function Definition section
 */

/*!
    @brief        This function allocates memory for the sys components and initializes them.
    @param        pMemBlock    Pointer to blocks of memory required for the creation of
                               system component
    @param        pSysConfig   System component configuration structure.
    @return       Return code of ADI_A2B_SYS_RESULT type.
                   - #ADI_A2B_SYS_SUCCESS   : System component initialized successfully
                   - #ADI_A2B_SYS_FAILURE   : System initialization failed
                   - #ADI_A2B_SYS_INSUFFICIENT_MEM : Insufficient memory for initialization of system component
                   - #ADI_A2B_SYS_CORE_SECONDARY : Secondary core configured for system initialization. However system
                                                                          initialization must happen from primary core

    <b> Global Variables Used: <b>
                None

   @note        None.
 */
ADI_A2B_SYS_RESULT adi_a2b_sys_Init(void *pMemBlock, uint32_t const  nMemorySize,ADI_A2B_SYS_CONFIG *pSysConfig)
{

    uint32_t *pMemPtr;
    ADI_A2B_SYS_RESULT eResult;


	Switch_Configurator();

    if(pSysConfig->bProcMaster == true)
    {
        if(nMemorySize < ADI_A2B_SYS_MEMSIZE_BYTES)
        {
            return ADI_A2B_SYS_INSUFFICIENT_MEM;
        }

        eResult = CODEC_Init();   //codec reset

        pMemPtr = (uint32_t*)pMemBlock;


    }
    else
    {
        return ADI_A2B_SYS_CORE_SECONDARY;
    }

    return ADI_A2B_SYS_SUCCESS;
}



/*!
   @brief      This function resets ADC and DAC.
   @param      None
   @return     return code of ADI_A2B_SYS_RESULT type
                   - ADI_A2B_SYS_SUCCESS:  The call to this function is successful.
                   - ADI_A2B_SYS_FAILURE : The call to this function failed.

   <b> Global Variables Used: <b>
                   None.

  @note        None.
*/
static ADI_A2B_SYS_RESULT CODEC_Init(void)
{
    ADI_A2B_HAL_GPIO_STATUS eGpioRetVal;
    uint32_t nDelay;

    eGpioRetVal = adi_a2b_hal_gpio_SetDirection(PORT_CODEC_RESET, PIN_CODEC_RESET, ADI_A2B_HAL_GPIO_DIRECTION_OUTPUT);
    if(eGpioRetVal != ADI_A2B_HAL_GPIO_STATUS_SUCCESS)
    {
        return ADI_A2B_SYS_FAILURE;
    }

    eGpioRetVal = adi_a2b_hal_gpio_Clear(PORT_CODEC_RESET, PIN_CODEC_RESET);
    if(eGpioRetVal != ADI_A2B_HAL_GPIO_STATUS_SUCCESS)
    {
        return ADI_A2B_SYS_FAILURE;
    }

    /* Wait for a duration of 1000 clock cycles */
    nDelay = CODEC_RESET_DELAY;
    WAIT_CLOCK_CYCLES(nDelay);

    eGpioRetVal = adi_a2b_hal_gpio_Set(PORT_CODEC_RESET, PIN_CODEC_RESET);
    if(eGpioRetVal != ADI_A2B_HAL_GPIO_STATUS_SUCCESS)
    {
        return ADI_A2B_SYS_FAILURE;
    }

    /* Wait for a duration of 1000 clock cycles */
    nDelay = CODEC_RESET_DELAY;
    WAIT_CLOCK_CYCLES(nDelay);

    return ADI_A2B_SYS_SUCCESS;
}

/*!
    @brief      This function is used to initialize the various clocks in the system
                including the core and system clocks.
    @param      pSysPowerConfig  Configuration structure for power management.
    @return     return code of ADI_A2B_SYS_POWER_RESULT type.
                    - ADI_A2B_SYS_POWER_SUCCESS  :  The API call is success.
                    - ADI_A2B_SYS_POWER_FAILED   :  The API call is failure.

    <b> Global Variables Used: <b>
                None.

   @note        None.
 */

ADI_A2B_SYS_RESULT Power_Init(ADI_A2B_SYS_POWER_CONFIG *pSysPowerConfig)
{
	ADI_PWR_RESULT  eResult = ADI_PWR_SUCCESS;

    /* Set the clocks for cores and system clock */
    if(pSysPowerConfig->bSetCoreSysClk == true)
    {
		if(((uint32_t)pSysPowerConfig->eCGUDev > MAX_CGU_DEVICES) || (pSysPowerConfig->nCoreClk < pSysPowerConfig->nSysClk))
		{
			eResult = ADI_PWR_FAILURE;
		}

		if(eResult == ADI_PWR_SUCCESS)
		{
			eResult = adi_pwr_Init((uint32_t)pSysPowerConfig->eCGUDev, ADI_A2B_SYS_POWER_CLKIN);
		}

		if(eResult == ADI_PWR_SUCCESS)
		{
			eResult = adi_pwr_SetPowerMode((uint32_t)pSysPowerConfig->eCGUDev, ADI_PWR_MODE_FULL_ON);
		}


		if(eResult == ADI_PWR_SUCCESS)
		{
            eResult = CheckClock(pSysPowerConfig);
		}
    }
    else
    {
//    	eResult = ConfigureClocks(pSysPowerConfig->eCGUDev);
    }

    return ((eResult==ADI_PWR_SUCCESS) ? ADI_A2B_SYS_SUCCESS : ADI_A2B_SYS_FAILURE);
}


/*!
    @brief     Function to check the set clock values.
    @param     pSysPowerConfig  Configuration structure for power management.se.
    @return    Return code of ADI_PWR_RESULT type.
                    - ADI_PWR_SUCCESS  :  The call to this function is successful.
                    - ADI_PWR_FAILURE  :  The call to this function failed.

    <b> Global Variables Used: <b>
                None.

   @note        None.
*/

static ADI_PWR_RESULT CheckClock(ADI_A2B_SYS_POWER_CONFIG *pSysPowerConfig)
{
    uint32_t    fcclk    = 0U;
    uint32_t    fsysclk  = 0U;
    uint32_t    fsclk0   = 0U;
    uint32_t    fsclk1   = 0U;
	ADI_PWR_RESULT  eResult = ADI_PWR_SUCCESS;

    eResult = adi_pwr_GetCoreClkFreq((uint32_t)pSysPowerConfig->eCGUDev, &fcclk);
	eResult = adi_pwr_GetSystemFreq((uint32_t)pSysPowerConfig->eCGUDev, &fsysclk, &fsclk0, &fsclk1);


	if(eResult == ADI_PWR_SUCCESS)
	{
		if((fcclk < (pSysPowerConfig->nCoreClk-ADI_A2B_SYS_POWER_CLKIN)) ||
		   (fsysclk < (pSysPowerConfig->nSysClk-ADI_A2B_SYS_POWER_CLKIN)))
		{
			eResult = ADI_PWR_FAILURE;
		}
	}

	return eResult;
}



/*****************************************************************************************************************************/

static void Write_TWI_8bit_Reg(unsigned char Reg_ID, unsigned char Tx_Data)
{
	devBuffer[0] = Reg_ID;
	devBuffer[1] = Tx_Data;

	adi_twi_Write(adi_twi_hDevice, devBuffer, 2u, false);
}

static unsigned char Read_TWI_8bit_Reg(unsigned char Reg_ID)
{
	ADI_TWI_RESULT eResult;
	unsigned char  Rx_Data;

	/* write register address */
	devBuffer[0] = Reg_ID;
	eResult = adi_twi_Write(adi_twi_hDevice, devBuffer, 1u, true);
	if( eResult != ADI_TWI_SUCCESS )
	{
		REPORT_ERROR("TWI write failed 0x%08X\n", eResult);
	}

	/* read register value */
	eResult = adi_twi_Read(adi_twi_hDevice, &Rx_Data, 1u, false);
	if(eResult!=ADI_TWI_SUCCESS)
	{
		REPORT_ERROR("TWI Read failed 0x%08X\n", eResult);
	}

	return Rx_Data;
}

static int ADAU_1962_Pllinit(void)
{
	int status,delay1=0xffff;

	ADI_TWI_RESULT eResult;

   	eResult = adi_twi_SetHardwareAddress(adi_twi_hDevice, TARGETADDR_1962);
	if(eResult!=ADI_TWI_SUCCESS)
	{
		REPORT_ERROR("TWI Set Hw address failed 0x%08X\n", eResult);
	}

	Write_TWI_8bit_Reg( ADAU1962_PLL_CTL_CTRL0, 0x41 );
	while(delay1--)
	{
		asm("nop;");
	}

	Write_TWI_8bit_Reg( ADAU1962_PLL_CTL_CTRL0, 0x45 );

	delay1 = 0xffff;
	while(delay1--)
	{
		asm("nop;");
	}

	Write_TWI_8bit_Reg( ADAU1962_PLL_CTL_CTRL1, 0x2a );
	delay1 = 0xffff;
	while(delay1--)
	{
		asm("nop;");
	}

	status = Read_TWI_8bit_Reg(ADAU1962_PLL_CTL_CTRL1);
	while(!((status & 0x4) >> 2))
	{
		status = Read_TWI_8bit_Reg(ADAU1962_PLL_CTL_CTRL1);
	}

	return eResult;
}

int ADAU_1962_init(void)
{
	int i;

	ADAU_1962_Pllinit();
	for(i=0;i<28;i++)
	{
		/* write value */
		Write_TWI_8bit_Reg(Config_array_DAC[i].Reg_Add,Config_array_DAC[i].Value);

		Config_read_DAC[i] = Read_TWI_8bit_Reg(Config_array_DAC[i].Reg_Add);

		if(Config_array_DAC[i].Value != Config_read_DAC[i])
		{
			REPORT_ERROR("\n Configuring ADAU_1962 failed");
			return 1;
		}
	}

	return 0;
}



/*
 *
 * EOF: $URL:  $
 *
*/
