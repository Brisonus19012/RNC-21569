/*******************************************************************************
Copyright (c) 2014 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
******************************************************************************
 * @file:    adi_a2b_codecInit.c
 * @brief:   This is the HAL implementation of SPORT, SPI, PCG, ADAU1979 ADC, ADAU1962A DAC and GPIO
 * @version: $Revision: 6209 $
 * @date:    $Date: 2015-01-07 11:53:06 +0530 (Wed, 07 Jan 2015) $
 * Developed by: Automotive Software and Systems team, Bangalore, India
*****************************************************************************/
/*! \addtogroup ADI_A2B_CODECINIT
 *  @{
 */

/*============= I N C L U D E S =============*/

#include "adi_a2b_hal.h"         /*!< ADI HAL include file */
#include <stdio.h>
#ifndef _TESSY_

/*-------------- G P I O --------------*/
#include <services/gpio/adi_gpio.h>                 /*!< ADI GPIO definitions include file */

#else
#include <stddef.h>
#include "tessy_defines.h"
#endif

/*============= D E F I N E S =============*/

#if !(defined (_TESSY_) || defined (_TESSY_COMPILER_DEPENDENT_))
#define CHECK_RESULT_HAL(hDevice, nExpectedValue, nObtainedValue, nErrorMessage)    \
    do                                                                              \
    {                                                                               \
        if((nObtainedValue) != (nExpectedValue))                                    \
        {                                                                           \
            (hDevice) = NULL;                                                       \
        }                                                                           \
    } while (0)  /* do-while-zero needed for Misra Rule 19.4 */
#else
#define CHECK_RESULT_HAL(hDevice, nExpectedValue, nObtainedValue, nErrorMessage)
#endif	/* _TESSY_ */

/*-------------- G P I O --------------*/

static uint32_t aHalGpioPort[] = {
                            (uint32_t)ADI_GPIO_PORT_A,
                            (uint32_t)ADI_GPIO_PORT_B,
                            (uint32_t)ADI_GPIO_PORT_C,
                          };


static uint32_t aHalGpioPin[] = {
                            ADI_GPIO_PIN_0,
                            ADI_GPIO_PIN_1,
                            ADI_GPIO_PIN_2,
                            ADI_GPIO_PIN_3,
                            ADI_GPIO_PIN_4,
                            ADI_GPIO_PIN_5,
                            ADI_GPIO_PIN_6,
                            ADI_GPIO_PIN_7,
                            ADI_GPIO_PIN_8,
                            ADI_GPIO_PIN_9,
                            ADI_GPIO_PIN_10,
                            ADI_GPIO_PIN_11,
                            ADI_GPIO_PIN_12,
                            ADI_GPIO_PIN_13,
                            ADI_GPIO_PIN_14,
                            ADI_GPIO_PIN_15
                         };


/*-------------- G P I O --------------*/

/********************************************************************************************
    @brief      Sets the given GPIO pin(s) to an input or output direction.
    @param      ePort       The GPIO port.
    @param      ePin        The pin(s) to set as input or output.
    @param      eDirection  The direction to set.
    @return     Return code of ADI_A2B_HAL_GPIO_STATUS type.
                    - #ADI_A2B_HAL_GPIO_STATUS_SUCCESS   : The API call succeeded.
                    - #ADI_A2B_HAL_GPIO_STATUS_FAILED    : The API call failed.

    <b> Global Variables Used: <b>
                None

   @note        This API has to be individually called for each pin to set the direction.
 *********************************************************************************************/

ADI_A2B_HAL_GPIO_STATUS adi_a2b_hal_gpio_SetDirection(ADI_A2B_HAL_GPIO_PORT        ePort,
                                                      ADI_A2B_HAL_GPIO_PIN         ePin,
                                                      ADI_A2B_HAL_GPIO_DIRECTION   eDirection)
{
    ADI_GPIO_RESULT     eGpioResult=ADI_GPIO_FAILURE;
    ADI_GPIO_DIRECTION  eGpioDirection=ADI_GPIO_DIRECTION_OUTPUT;

    switch(eDirection)
    {
        case ADI_A2B_HAL_GPIO_DIRECTION_INPUT:
            eGpioDirection = ADI_GPIO_DIRECTION_INPUT;
            break;
        case ADI_A2B_HAL_GPIO_DIRECTION_OUTPUT:
            eGpioDirection = ADI_GPIO_DIRECTION_OUTPUT;
            break;
        default :
            break;
    }

    eGpioResult = adi_gpio_SetDirection((ADI_GPIO_PORT)aHalGpioPort[ePort], (uint32_t)aHalGpioPin[ePin],eGpioDirection);

    return ((eGpioResult != ADI_GPIO_SUCCESS) ? ADI_A2B_HAL_GPIO_STATUS_FAILED : ADI_A2B_HAL_GPIO_STATUS_SUCCESS);
}

/**********************************************************************************************************
   @brief       Sets the given GPIO pin(s) to a logic high level.
                The logic level of other pins is not changed.
   @param       ePort       The GPIO port.
   @param       ePin        The pin(s) to set to a logic high level.
   @return      Return code of ADI_A2B_HAL_GPIO_STATUS type.
                    - #ADI_A2B_HAL_GPIO_STATUS_SUCCESS   : The API call succeeded.
                    - #ADI_A2B_HAL_GPIO_STATUS_FAILED    : The API call failed.

   <b> Global Variables Used: <b>
                None

  @note         This API has to be individually called for each pin to Set.
************************************************************************************************************/

ADI_A2B_HAL_GPIO_STATUS adi_a2b_hal_gpio_Set(ADI_A2B_HAL_GPIO_PORT ePort, ADI_A2B_HAL_GPIO_PIN ePin)
{
    ADI_GPIO_RESULT eGpioResult;

    eGpioResult = adi_gpio_Set((ADI_GPIO_PORT)aHalGpioPort[ePort], (uint32_t)aHalGpioPin[ePin]);

    return ((eGpioResult != ADI_GPIO_SUCCESS) ? ADI_A2B_HAL_GPIO_STATUS_FAILED : ADI_A2B_HAL_GPIO_STATUS_SUCCESS);
}

/***********************************************************************************************************
   @brief       Sets the given GPIO pin(s) to a logic low level.
                The logic level of other pins is not changed.
   @param       ePort       The GPIO port.
   @param       ePin        The pin(s) to set to a logic low level.
   @return      Return code of ADI_A2B_HAL_GPIO_STATUS type.
                    - #ADI_A2B_HAL_GPIO_STATUS_SUCCESS   : The API call succeeded.
                    - #ADI_A2B_HAL_GPIO_STATUS_FAILED    : The API call failed.

   <b> Global Variables Used: <b>
                None

  @note         This API has to be individually called for each pin to Clear.
************************************************************************************************************/

ADI_A2B_HAL_GPIO_STATUS adi_a2b_hal_gpio_Clear(ADI_A2B_HAL_GPIO_PORT ePort, ADI_A2B_HAL_GPIO_PIN ePin)
{
    ADI_GPIO_RESULT eGpioResult;

    eGpioResult = adi_gpio_Clear((ADI_GPIO_PORT)aHalGpioPort[ePort], (uint32_t)aHalGpioPin[ePin]);

    return ((eGpioResult != ADI_GPIO_SUCCESS) ? ADI_A2B_HAL_GPIO_STATUS_FAILED : ADI_A2B_HAL_GPIO_STATUS_SUCCESS);
}

/***********************************************************************************************************
   @brief       Toggle the logic level of the given GPIO pin(s).
                The logic level of other pins is not changed.
   @param       ePort       The GPIO port.
   @param       ePin        The pin(s) to set to toggle.
   @return      Return code of ADI_A2B_HAL_GPIO_STATUS type.
                    - #ADI_A2B_HAL_GPIO_STATUS_SUCCESS   : The API call succeeded.
                    - #ADI_A2B_HAL_GPIO_STATUS_FAILED    : The API call failed.

   <b> Global Variables Used: <b>
                None

  @note         This API has to be individually called for each pin to Toggle.
************************************************************************************************************/

ADI_A2B_HAL_GPIO_STATUS adi_a2b_hal_gpio_Toggle(ADI_A2B_HAL_GPIO_PORT ePort, ADI_A2B_HAL_GPIO_PIN ePin)
{
    ADI_GPIO_RESULT eGpioResult;

    eGpioResult = adi_gpio_Toggle((ADI_GPIO_PORT)aHalGpioPort[ePort], (uint32_t)aHalGpioPin[ePin]);

    return ((eGpioResult != ADI_GPIO_SUCCESS) ? ADI_A2B_HAL_GPIO_STATUS_FAILED : ADI_A2B_HAL_GPIO_STATUS_SUCCESS);
}

#if 0
void verifyRegistersAdau1979(ADI_A2B_HAL_ADAU1979_HANDLE hAdau1979)
{
    uint8_t valRegPwr=0,valRegPllCtl=0,valRegPwrSai=0,valRegSaiCtl1=0;
    uint8_t valRegSaiCtl2=0,valRegChMap1=0,valRegChMap2=0,valRegTemp=0;
    uint8_t valRegGain1=0,valRegGain2=0,valRegGain3=0,valRegGain4=0;
    uint8_t valRegMisCtl=0,valRegClip=0,valRegHPF=0;

    adi_adau1979_ReadRegister((ADI_ADAU1979_HANDLE)hAdau1979,ADI_ADAU1979_REG_M_PWR,&valRegPwr);
    adi_adau1979_ReadRegister((ADI_ADAU1979_HANDLE)hAdau1979,ADI_ADAU1979_REG_PLL_CTL,&valRegPllCtl);
    adi_adau1979_ReadRegister((ADI_ADAU1979_HANDLE)hAdau1979,ADI_ADAU1979_REG_BLK_PWR_SAI,&valRegPwrSai);
    adi_adau1979_ReadRegister((ADI_ADAU1979_HANDLE)hAdau1979,ADI_ADAU1979_REG_SAI_CTL1,&valRegSaiCtl1);
    adi_adau1979_ReadRegister((ADI_ADAU1979_HANDLE)hAdau1979,ADI_ADAU1979_REG_SAI_CTL2,&valRegSaiCtl2);
    adi_adau1979_ReadRegister((ADI_ADAU1979_HANDLE)hAdau1979,ADI_ADAU1979_REG_SAI_CMAP12,&valRegChMap1);
    adi_adau1979_ReadRegister((ADI_ADAU1979_HANDLE)hAdau1979,ADI_ADAU1979_REG_SAI_CMAP34,&valRegChMap2);
    adi_adau1979_ReadRegister((ADI_ADAU1979_HANDLE)hAdau1979,ADI_ADAU1979_REG_SAI_OVRTEMP,&valRegTemp);
    adi_adau1979_ReadRegister((ADI_ADAU1979_HANDLE)hAdau1979,ADI_ADAU1979_REG_POSTADC_GAIN1,&valRegGain1);
    adi_adau1979_ReadRegister((ADI_ADAU1979_HANDLE)hAdau1979,ADI_ADAU1979_REG_POSTADC_GAIN2,&valRegGain2);
    adi_adau1979_ReadRegister((ADI_ADAU1979_HANDLE)hAdau1979,ADI_ADAU1979_REG_POSTADC_GAIN3,&valRegGain3);
    adi_adau1979_ReadRegister((ADI_ADAU1979_HANDLE)hAdau1979,ADI_ADAU1979_REG_POSTADC_GAIN4,&valRegGain4);
    adi_adau1979_ReadRegister((ADI_ADAU1979_HANDLE)hAdau1979,ADI_ADAU1979_REG_MISC_CTL,&valRegMisCtl);
    adi_adau1979_ReadRegister((ADI_ADAU1979_HANDLE)hAdau1979,ADI_ADAU1979_REG_ASC_CLIP,&valRegClip);
    adi_adau1979_ReadRegister((ADI_ADAU1979_HANDLE)hAdau1979,ADI_ADAU1979_REG_DC_HPF_CAL,&valRegHPF);

    printf("ADI_ADAU1979_REG_M_PWR			=0x%x\n",	valRegPwr);
    printf("ADI_ADAU1979_REG_PLL_CTL		=0x%x\n",	valRegPllCtl);
    printf("ADI_ADAU1979_REG_BLK_PWR_SAI	=0x%x\n",	valRegPwrSai);
    printf("ADI_ADAU1979_REG_SAI_CTL1		=0x%x\n",	valRegSaiCtl1);
    printf("ADI_ADAU1979_REG_SAI_CTL2		=0x%x\n",	valRegSaiCtl2);
    printf("ADI_ADAU1979_REG_SAI_CMAP12		=0x%x\n",	valRegChMap1);
    printf("ADI_ADAU1979_REG_SAI_CMAP34		=0x%x\n",	valRegChMap2);
    printf("ADI_ADAU1979_REG_SAI_OVRTEMP	=0x%x\n",	valRegTemp);
    printf("ADI_ADAU1979_REG_POSTADC_GAIN1	=0x%x\n",	valRegGain1);
    printf("ADI_ADAU1979_REG_POSTADC_GAIN2	=0x%x\n",	valRegGain2);
    printf("ADI_ADAU1979_REG_POSTADC_GAIN3	=0x%x\n",	valRegGain3);
    printf("ADI_ADAU1979_REG_POSTADC_GAIN4	=0x%x\n",	valRegGain4);
    printf("ADI_ADAU1979_REG_MISC_CTL		=0x%x\n",	valRegMisCtl);
    printf("ADI_ADAU1979_REG_ASC_CLIP		=0x%x\n",	valRegClip);
    printf("ADI_ADAU1979_REG_DC_HPF_CAL		=0x%x\n",	valRegHPF);
}

void verifyRegistersAdau1962a(ADI_A2B_HAL_ADAU1962A_HANDLE hAdau1962a)
{
    uint8_t valReg_pll_clk_ctrl0        = 0;
    uint8_t valReg_pll_clk_ctrl1        = 0;
    uint8_t valReg_pdn_thrmsens_ctrl_1  = 0;
    uint8_t valReg_pdn_ctrl2            = 0;
    uint8_t valReg_pdn_ctrl3            = 0;
    uint8_t valReg_thrm_temp_stat       = 0;
    uint8_t valReg_dac_ctrl0            = 0;
    uint8_t valReg_dac_ctrl1            = 0;
    uint8_t valReg_dac_ctrl2            = 0;
    uint8_t valReg_dac_mute1            = 0;
    uint8_t valReg_dac_mute2            = 0;
    uint8_t valReg_dacmstr_vol          = 0;
    uint8_t valReg_dac1_vol             = 0;
    uint8_t valReg_dac2_vol             = 0;
    uint8_t valReg_dac3_vol             = 0;
    uint8_t valReg_dac4_vol             = 0;
    uint8_t valReg_dac5_vol             = 0;
    uint8_t valReg_dac6_vol             = 0;
    uint8_t valReg_dac7_vol             = 0;
    uint8_t valReg_dac8_vol             = 0;
    uint8_t valReg_dac9_vol             = 0;
    uint8_t valReg_dac10_vol            = 0;
    uint8_t valReg_dac11_vol            = 0;
    uint8_t valReg_dac12_vol            = 0;
    uint8_t valReg_pad_strgth           = 0;
    uint8_t valReg_dac_power1           = 0;
    uint8_t valReg_dac_power2           = 0;
    uint8_t valReg_dac_power3           = 0;

    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_PLL_CLK_CTRL0      ,&valReg_pll_clk_ctrl0      );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_PLL_CLK_CTRL1      ,&valReg_pll_clk_ctrl1      );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_PDN_THRMSENS_CTRL_1,&valReg_pdn_thrmsens_ctrl_1);
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_PDN_CTRL2          ,&valReg_pdn_ctrl2          );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_PDN_CTRL3          ,&valReg_pdn_ctrl3          );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_THRM_TEMP_STAT     ,&valReg_thrm_temp_stat     );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC_CTRL0          ,&valReg_dac_ctrl0          );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC_CTRL1          ,&valReg_dac_ctrl1          );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC_CTRL2          ,&valReg_dac_ctrl2          );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC_MUTE1          ,&valReg_dac_mute1          );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC_MUTE2          ,&valReg_dac_mute2          );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DACMSTR_VOL        ,&valReg_dacmstr_vol        );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC1_VOL           ,&valReg_dac1_vol           );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC2_VOL           ,&valReg_dac2_vol           );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC3_VOL           ,&valReg_dac3_vol           );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC4_VOL           ,&valReg_dac4_vol           );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC5_VOL           ,&valReg_dac5_vol           );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC6_VOL           ,&valReg_dac6_vol           );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC7_VOL           ,&valReg_dac7_vol           );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC8_VOL           ,&valReg_dac8_vol           );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC9_VOL           ,&valReg_dac9_vol           );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC10_VOL          ,&valReg_dac10_vol          );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC11_VOL          ,&valReg_dac11_vol          );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC12_VOL          ,&valReg_dac12_vol          );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_PAD_STRGTH         ,&valReg_pad_strgth         );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC_POWER1         ,&valReg_dac_power1         );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC_POWER2         ,&valReg_dac_power2         );
    adi_adau1962a_ReadRegister((ADI_ADAU1962A_HANDLE)hAdau1962a, ADI_ADAU1962A_REG_DAC_POWER3         ,&valReg_dac_power3         );


    printf("\n ADI_ADAU1962A_REG_PLL_CLK_CTRL0      = 0x%02x",    valReg_pll_clk_ctrl0      );
    printf("\n ADI_ADAU1962A_REG_PLL_CLK_CTRL1      = 0x%02x",    valReg_pll_clk_ctrl1      );
    printf("\n ADI_ADAU1962A_REG_PDN_THRMSENS_CTRL_1= 0x%02x",    valReg_pdn_thrmsens_ctrl_1);
    printf("\n ADI_ADAU1962A_REG_PDN_CTRL2          = 0x%02x",    valReg_pdn_ctrl2          );
    printf("\n ADI_ADAU1962A_REG_PDN_CTRL3          = 0x%02x",    valReg_pdn_ctrl3          );
    printf("\n ADI_ADAU1962A_REG_THRM_TEMP_STAT     = 0x%02x",    valReg_thrm_temp_stat     );
    printf("\n ADI_ADAU1962A_REG_DAC_CTRL0          = 0x%02x",    valReg_dac_ctrl0          );
    printf("\n ADI_ADAU1962A_REG_DAC_CTRL1          = 0x%02x",    valReg_dac_ctrl1          );
    printf("\n ADI_ADAU1962A_REG_DAC_CTRL2          = 0x%02x",    valReg_dac_ctrl2          );
    printf("\n ADI_ADAU1962A_REG_DAC_MUTE1          = 0x%02x",    valReg_dac_mute1          );
    printf("\n ADI_ADAU1962A_REG_DAC_MUTE2          = 0x%02x",    valReg_dac_mute2          );
    printf("\n ADI_ADAU1962A_REG_DACMSTR_VOL        = 0x%02x",    valReg_dacmstr_vol        );
    printf("\n ADI_ADAU1962A_REG_DAC1_VOL           = 0x%02x",    valReg_dac1_vol           );
    printf("\n ADI_ADAU1962A_REG_DAC2_VOL           = 0x%02x",    valReg_dac2_vol           );
    printf("\n ADI_ADAU1962A_REG_DAC3_VOL           = 0x%02x",    valReg_dac3_vol           );
    printf("\n ADI_ADAU1962A_REG_DAC4_VOL           = 0x%02x",    valReg_dac4_vol           );
    printf("\n ADI_ADAU1962A_REG_DAC5_VOL           = 0x%02x",    valReg_dac5_vol           );
    printf("\n ADI_ADAU1962A_REG_DAC6_VOL           = 0x%02x",    valReg_dac6_vol           );
    printf("\n ADI_ADAU1962A_REG_DAC7_VOL           = 0x%02x",    valReg_dac7_vol           );
    printf("\n ADI_ADAU1962A_REG_DAC8_VOL           = 0x%02x",    valReg_dac8_vol           );
    printf("\n ADI_ADAU1962A_REG_DAC9_VOL           = 0x%02x",    valReg_dac9_vol           );
    printf("\n ADI_ADAU1962A_REG_DAC10_VOL          = 0x%02x",    valReg_dac10_vol          );
    printf("\n ADI_ADAU1962A_REG_DAC11_VOL          = 0x%02x",    valReg_dac11_vol          );
    printf("\n ADI_ADAU1962A_REG_DAC12_VOL          = 0x%02x",    valReg_dac12_vol          );
    printf("\n ADI_ADAU1962A_REG_PAD_STRGTH         = 0x%02x",    valReg_pad_strgth         );
    printf("\n ADI_ADAU1962A_REG_DAC_POWER1         = 0x%02x",    valReg_dac_power1         );
    printf("\n ADI_ADAU1962A_REG_DAC_POWER2         = 0x%02x",    valReg_dac_power2         );
    printf("\n ADI_ADAU1962A_REG_DAC_POWER3         = 0x%02x",    valReg_dac_power3         );
}
#endif

/*
 *  @}
 */

/*
 *
 * EOF:
 *
*/
