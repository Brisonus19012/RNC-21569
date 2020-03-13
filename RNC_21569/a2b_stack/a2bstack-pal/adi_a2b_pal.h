#ifndef _ADI_A2B_PAL_H
#define _ADI_A2B_PAL_H

#include <drivers/twi/adi_twi.h>

#define ADI_A2B_PAL_VER_MAJOR   (0x1U)
#define ADI_A2B_PAL_VER_MINOR   (0x0U)
#define ADI_A2B_PAL_VER_RELEASE (0x10000000U)

#define ADI_A2B_PAL_BUILD_NUM   (0U)

/*!< PCLK for ADSP-21489 */
#define A2B_SYSTEM_CLK				(24.576*16/2)

extern ADI_TWI_HANDLE adi_twi_hDevice;

#endif
