/*
 **
 ** sru_config.c source file generated on ÈýÔÂ 16, 2020 at 16:56:05.	
 **
 ** Copyright (C) 2014-2020 Analog Devices Inc., All Rights Reserved.
 **
 ** This file is generated automatically based upon the options selected in 
 ** the SRU Configuration editor. Changes to the SRU configuration should
 ** be made by changing the appropriate options rather than editing this file.
 **
 ** Only registers with non-default values are written to this file.
 **
 */
 
#include <stdint.h>
#include <sys/platform.h>

int32_t adi_SRU_Init(void);

/*
 * Initialize the Signal Routing Unit
 */
int32_t adi_SRU_Init(void)
{
    /* DAI0_PB02_I, DAI0_PB01_I, DAI0_PB04_I, DAI0_PB03_I */
    *pREG_DAI0_PIN0 = (unsigned int) 0x074e0a94;

    /* DAI0_PBEN03_I, DAI0_PBEN02_I, DAI0_PBEN01_I, DAI0_PBEN05_I, DAI0_PBEN04_I */
    *pREG_DAI0_PBEN0 = (unsigned int) 0x0e0412ca;

    /* SPT4A_CLK_I, SPT5A_CLK_I, SPT4B_CLK_I, SPT5B_CLK_I, SPT6B_CLK_I, SPT6A_CLK_I */
    *pREG_DAI1_CLK0 = (unsigned int) 0x252630c4;

    /* DAI1_PB04_I, DAI1_PB02_I, DAI1_PB03_I, DAI1_PB01_I */
    *pREG_DAI1_PIN0 = (unsigned int) 0x04df8a94;

    /* DAI1_PB08_I, DAI1_PB06_I, DAI1_PB07_I, DAI1_PB05_I */
    *pREG_DAI1_PIN1 = (unsigned int) 0x04e84ba0;

    /* DAI1_PBEN05_I, DAI1_PBEN01_I, DAI1_PBEN02_I, DAI1_PBEN03_I, DAI1_PBEN04_I */
    *pREG_DAI1_PBEN0 = (unsigned int) 0x082402ca;


    return 0;
}

