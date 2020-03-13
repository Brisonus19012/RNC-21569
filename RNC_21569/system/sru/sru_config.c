/*
 **
 ** sru_config.c source file generated on ÈýÔÂ 12, 2020 at 08:45:07.	
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

    /* DAI1_PB04_I, DAI1_PB02_I, DAI1_PB03_I, DAI1_PB01_I */
    *pREG_DAI1_PIN0 = (unsigned int) 0x074e0a94;


    return 0;
}

