/*******************************************************************************
Copyright (c) 2014-2015 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
******************************************************************************
 * @file:    adi_a2b_hal.h
 * @brief:   HAL for SPORT, SPI, PCG, ADAU1979 ADC, ADAU1962A DAC and GPIO include file.
 * @version: $Revision: 6206 $
 * @date:    $Date: 2015-01-06 14:39:19 +0530 (Tue, 06 Jan 2015) $
 * Developed by: Automotive Software and Systems team, Bangalore, India
*****************************************************************************/
/*! \addtogroup ADI_A2B_HAL
 *  @{
 */

#ifndef _ADI_A2B_HAL_H_
#define _ADI_A2B_HAL_H_

/*============= I N C L U D E S =============*/

#include <adi_types.h>                  /*!< ADI Type definitions include file */
#ifndef _TESSY_
#include <services/int/adi_int.h>
#else
#include "tessy_defines.h"
#endif

/*-------------- P O W E R --------------*/
#include <services/pwr/adi_pwr.h>      /*!< ADI POWER definitions include file */

/*-------------- A D A U 1 9 7 9 --------------*/
//#include <drivers/adc/adau1979/adi_adau1979.h>      /*!< ADI ADAU1979 ADC definitions include file */

/*-------------- A D A U 1 9 6 2 A --------------*/
//#include <drivers/dac/adau1962a/adi_adau1962a.h>    /*!< ADI ADAU1962A DAC definitions include file */

/*-------------- G P I O --------------*/
#include <services/gpio/adi_gpio.h>                 /*!< ADI GPIO definitions include file */

/*-------------- S P D I F Rx--------------*/
#include <drivers/spdif/adi_spdif_rx.h>             /*!< ADI S/PDIF Rx definitions include file */

/*-------------- A S R C --------------*/
#include <drivers/asrc/adi_asrc.h>                  /*!< ADI ASRC definitions include file */

/*============== D E F I N E S ===============*/
#define ADI_A2B_HAL_SPORT_MEM_SIZE           (ADI_SPORT_DMA_MEMORY_SIZE)

/*-------------- S P I --------------*/

/*-------------- P C G --------------*/

/*-------------- A D A U 1 9 7 9 --------------*/
//#define ADI_A2B_HAL_ADAU1979_MEMORY_SIZE     (ADI_ADAU1979_MEMORY_SIZE + ADI_TWI_MEMORY_SIZE)

/*-------------- A D A U 1 9 6 2 A --------------*/
//#define ADI_A2B_HAL_ADAU1962A_MEMORY_SIZE    (ADI_ADAU1962A_MEMORY_SIZE + ADI_TWI_MEMORY_SIZE)

/*-------------- G P I O --------------*/

/*-------------- S P D I F Rx--------------*/
#define ADI_A2B_HAL_SPDIF_RX_MEMORY_SIZE     (ADI_SPDIF_RX_MEMORY_SIZE)

/*-------------- A S R C --------------*/
#define ADI_A2B_HAL_ASRC_MEMORY_SIZE         (ADI_ASRC_MEMORY_SIZE)
/*-------------- S P O R T --------------*/

#define E_ADI_A2B_HAL_SPORT_STATUS_SUCCESS       (0U)  /*!< Enumeration definition for HAL SPORT success status        */
#define E_ADI_A2B_HAL_SPORT_STATUS_FAILED        (-1)  /*!< Enumeration definition for HAL SPORT error status          */

#define E_ADI_A2B_HAL_SPORT_0    (0U)                  /*!< Enumeration definition for SPORT 0 device                  */
#define E_ADI_A2B_HAL_SPORT_1    (1U)                  /*!< Enumeration definition for SPORT 1 device                  */
#define E_ADI_A2B_HAL_SPORT_2    (2U)                  /*!< Enumeration definition for SPORT 2 device                  */
#define E_ADI_A2B_HAL_SPORT_3    (3U)                  /*!< Enumeration definition for SPORT 3 device                  */

#define E_ADI_HALF_SPORT_A      (0U)                  /*!< First Half SPORT                                           */
#define E_ADI_HALF_SPORT_B      (1U)                  /*!< Second Half SPORT                                          */

#define E_ADI_A2B_HAL_SPORT_DIR_RX      (1U)           /*!< Sport in Rx mode                                           */
#define E_ADI_A2B_HAL_SPORT_DIR_TX      (2U)           /*!< Sport in Tx mode                                           */

#define ADI_A2B_HAL_SPORT_EVENT_RX_BUFFER_PROCESSED (64U)    /* SPORT receive buffer processed interrupt               */
#define ADI_A2B_HAL_SPORT_EVENT_TX_BUFFER_PROCESSED (128U)   /* SPORT transmit buffer processed interrupt              */

/*-------------- S P I --------------*/
#if 0
/*-------------- P C G --------------*/


#define ADI_A2B_HAL_DISABLE_FS_PHASE     (0U)          /*!< Definition for disabling the PCG frame sync phase          */
#define ADI_A2B_HAL_ENABLE_FS_PHASE      (1U)          /*!< Definition for enabling the PCG frame sync phase           */

#define ADI_A2B_HAL_PW_SYNC_NO_INIT      (0U)          /*!< Definition for disabling pulse width initilization         */
#define ADI_A2B_HAL_PW_SYNC_INIT         (1U)          /*!< Definition for enabling pulse width initilization          */

#define ADI_A2B_HAL_DISABLE_EXT_CLK      (0U)          /*!< Definition for disabling external clock input for PCG      */
#define ADI_A2B_HAL_ENABLE_EXT_CLK       (1U)          /*!< Definition for enabling external clock input for PCG       */

#define ADI_A2B_HAL_PCG_PW2_FSC          (4U)          /*!< Definition for setting the number of input clock
                                                           periods for which the frame sync output is high for PCG    */

#define E_ADI_A2B_HAL_PCG_CLK_FS_ENABLE          (0U)  /*!< Enum def for EN both CLK and FS output from PCG            */
#define E_ADI_A2B_HAL_PCG_CLK_ENABLE_FS_DISABLE  (1U)  /*!< Enum def for EN CLK and DIS FS output from PCG             */
#define E_ADI_A2B_HAL_PCG_CLK_DISABLE_FS_ENABLE  (2U)  /*!< Enum def for DIS clock and EN FS output from PCG           */

#define ADI_A2B_HAL_PCG_EXT_CLKIN_FREQ_24576000HZ (24576000U) /*!< Def for external clock input of 24.576 MHz for PCG  */

#define E_PCG_A             (0U)                        /*!< Enumeration definition for PCG A                         */
#define E_PCG_B             (1U)                        /*!< Enumeration definition for PCG B                         */
#define E_PCG_C             (2U)                        /*!< Enumeration definition for PCG C                         */
#define E_PCG_D             (3U)                        /*!< Enumeration definition for PCG D                         */

#define E_PROC_3xx          (300U)                      /*!< Enumeration definition for ADSP-213xx processors series  */
#define E_PROC_4xx          (400U)                      /*!< Enumeration definition for ADSP-214xx processors series  */
#define E_PROC_5xx          (500U)                      /*!< Enumeration definition for ADSP-215xx processors series  */

#define E_ADI_A2B_HAL_PCG_STATUS_SUCCES      (0U)        /*!< Enumeration definition for HAL PCG success status        */
#define E_ADI_A2B_HAL_PCG_STATUS_FAILED      (-1)        /*!< Enumeration definition for HAL PCG error status          */
#endif /* #if 0 */
/*-------------- A D A U 1 9 7 9 --------------*/

#define E_ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_32000HZ  (0U) /*!<  Enum definition for ADAU1979 Sampling rate 32000  HZ    */
#define E_ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_44100HZ  (1U) /*!<  Enum definition for ADAU1979 Sampling rate 44100  HZ    */
#define E_ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_48000HZ  (2U) /*!<  Enum definition for ADAU1979 Sampling rate 48000  HZ    */
#define E_ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_96000HZ  (3U) /*!<  Enum definition for ADAU1979 Sampling rate 96000  HZ    */
#define E_ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_192000HZ (4U) /*!<  Enum definition for ADAU1979 Sampling rate 192000 HZ    */
#define E_ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_NONE     (5U) /*!<  Enum definition for ADAU1979 Sampling rate none         */

#define E_ADI_A2B_HAL_ADAU1979_STATUS_SUCCESS       (0U) /*!<  Enum definition for HAL ADAU1979 success status         */
#define E_ADI_A2B_HAL_ADAU1979_STATUS_FAILED        (-1) /*!<  Enum definition for HAL ADAU1979 error status           */

/*-------------- A D A U 1 9 6 2 A --------------*/

#define E_ADI_A2B_HAL_ADAU1962A_STATUS_SUCCESS       (0U)      /*!< Enum definition for HAL ADAU1962A success status   */
#define E_ADI_A2B_HAL_ADAU1962A_STATUS_FAILED        (-1)      /*!< Enum definition for HAL ADAU1962A error status     */

#define E_ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_32000HZ  (32000U ) /*!< Enum definition for ADAU1962A Sample rate 32   kHz */
#define E_ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_44100HZ  (44100U ) /*!< Enum definition for ADAU1962A Sample rate 44.1 kHz */
#define E_ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_48000HZ  (48000U ) /*!< Enum definition for ADAU1962A Sample rate 48   kHz */
#define E_ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_96000HZ  (96000U ) /*!< Enum definition for ADAU1962A Sample rate 96   kHz */
#define E_ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_192000HZ (192000U) /*!< Enum definition for ADAU1962A Sample rate 192  kHz */
#define E_ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_NONE     (0U     ) /*!< Enum definition for ADAU1962A Sample rate none     */

/*-------------- G P I O --------------*/

#define E_ADI_A2B_HAL_GPIO_PORT_A            (0U)              /*!< Configure GPIO port A. */
#define E_ADI_A2B_HAL_GPIO_PORT_B            (1U)              /*!< Configure GPIO port B. */
#define E_ADI_A2B_HAL_GPIO_PORT_C            (2U)              /*!< Configure GPIO port C. */
#define E_ADI_A2B_HAL_GPIO_PORT_D            (3U)              /*!< Configure GPIO port D. */
#define E_ADI_A2B_HAL_GPIO_PORT_E            (4U)              /*!< Configure GPIO port E. */
#define E_ADI_A2B_HAL_GPIO_PORT_F            (5U)              /*!< Configure GPIO port F. */
#define E_ADI_A2B_HAL_GPIO_PORT_G            (6U)              /*!< Configure GPIO port G. */

#define E_ADI_A2B_HAL_GPIO_PIN_0             (0U)              /*!< Configure GPIO Pin 0   */
#define E_ADI_A2B_HAL_GPIO_PIN_1             (1U)              /*!< Configure GPIO Pin 1   */
#define E_ADI_A2B_HAL_GPIO_PIN_2             (2U)              /*!< Configure GPIO Pin 2   */
#define E_ADI_A2B_HAL_GPIO_PIN_3             (3U)              /*!< Configure GPIO Pin 3   */
#define E_ADI_A2B_HAL_GPIO_PIN_4             (4U)              /*!< Configure GPIO Pin 4   */
#define E_ADI_A2B_HAL_GPIO_PIN_5             (5U)              /*!< Configure GPIO Pin 5   */
#define E_ADI_A2B_HAL_GPIO_PIN_6             (6U)              /*!< Configure GPIO Pin 6   */
#define E_ADI_A2B_HAL_GPIO_PIN_7             (7U)              /*!< Configure GPIO Pin 7   */
#define E_ADI_A2B_HAL_GPIO_PIN_8             (8U)              /*!< Configure GPIO Pin 8   */
#define E_ADI_A2B_HAL_GPIO_PIN_9             (9U)              /*!< Configure GPIO Pin 9   */
#define E_ADI_A2B_HAL_GPIO_PIN_10            (10U)             /*!< Configure GPIO Pin 10  */
#define E_ADI_A2B_HAL_GPIO_PIN_11            (11U)             /*!< Configure GPIO Pin 11  */
#define E_ADI_A2B_HAL_GPIO_PIN_12            (12U)             /*!< Configure GPIO Pin 12  */
#define E_ADI_A2B_HAL_GPIO_PIN_13            (13U)             /*!< Configure GPIO Pin 13  */
#define E_ADI_A2B_HAL_GPIO_PIN_14            (14U)             /*!< Configure GPIO Pin 14  */
#define E_ADI_A2B_HAL_GPIO_PIN_15            (15U)             /*!< Configure GPIO Pin 15  */

#define E_ADI_A2B_HAL_GPIO_DIRECTION_INPUT   (0U)              /*!< Set the GPIO pin to an input.  */
#define E_ADI_A2B_HAL_GPIO_DIRECTION_OUTPUT  (1U)              /*!< Set the GPIO pin to an output. */

#define E_ADI_A2B_HAL_GPIO_STATUS_SUCCESS    (0U)              /*!< The API call succeeded. */
#define E_ADI_A2B_HAL_GPIO_STATUS_FAILED     (-1)              /*!< The API call failed. */

/*-------------- S P D I F Rx--------------*/

#define E_ADI_A2B_HAL_SPDIF_RX_0             (0U)   /*!< Enumeration definition for SPDIF Rx 0 device */
#define E_ADI_A2B_HAL_SPDIF_RX_1             (1U)   /*!< Enumeration definition for SPDIF Rx 1 device */

#define E_ADI_A2B_HAL_SPDIF_RX_STATUS_SUCCESS (0U)  /*!< Enumeration definition for HAL SPDIF Rx success status */
#define E_ADI_A2B_HAL_SPDIF_RX_STATUS_FAILED  (-1)  /*!< Enumeration definition for HAL SPDIF Rx error status   */

/*-------------- A S R C --------------*/

#define E_ADI_A2B_HAL_ASRC_BLK_0             (0U)   /*!< ASRC Block 0  */
#define E_ADI_A2B_HAL_ASRC_BLK_1             (1U)   /*!< ASRC Block 1  */

#define E_ADI_A2B_HAL_ASRC_0                 (0U)   /*!< ASRC 0  */
#define E_ADI_A2B_HAL_ASRC_1                 (1U)   /*!< ASRC 1  */
#define E_ADI_A2B_HAL_ASRC_2                 (2U)   /*!< ASRC 2  */
#define E_ADI_A2B_HAL_ASRC_3                 (3U)   /*!< ASRC 3  */

#define E_ADI_A2B_HAL_ASRC_STATUS_SUCCESS    (0U)   /*!< Enumeration definition for HAL ASRC success status */
#define E_ADI_A2B_HAL_ASRC_STATUS_FAILED     (-1)   /*!< Enumeration definition for HAL ASRC error status   */

#define E_ADI_A2B_HAL_ASRC_INPUT_LEFT_JUSTIFIED          (0U)    /*!< Left justified format  */
#define E_ADI_A2B_HAL_ASRC_INPUT_I2S                     (1U)    /*!< I2S format  */
#define E_ADI_A2B_HAL_ASRC_INPUT_TDM                     (2U)    /*!< TDM format  */
#define E_ADI_A2B_HAL_ASRC_INPUT_24BIT_RIGHT_JUSTIFIED   (4U)    /*!< 24 bit right justified format  */
#define E_ADI_A2B_HAL_ASRC_INPUT_20BIT_RIGHT_JUSTIFIED   (5U)    /*!< 20 bit right justified format  */
#define E_ADI_A2B_HAL_ASRC_INPUT_18BIT_RIGHT_JUSTIFIED   (6U)    /*!< 18 bit right justified format  */
#define E_ADI_A2B_HAL_ASRC_INPUT_16BIT_RIGHT_JUSTIFIED   (7U)    /*!< 16 bit right justified format  */
#define E_ADI_A2B_HAL_ASRC_INPUT_NONE                    (8U)    /*!< None  */

#define E_ADI_A2B_HAL_ASRC_OUTPUT_LEFT_JUSTIFIED         (0U)    /*!< Left justified format  */
#define E_ADI_A2B_HAL_ASRC_OUTPUT_I2S                    (1U)    /*!< I2S format  */
#define E_ADI_A2B_HAL_ASRC_OUTPUT_TDM                    (2U)    /*!< TDM format  */
#define E_ADI_A2B_HAL_ASRC_OUTPUT_RIGHT_JUSTIFIED        (3U)    /*!< Right justified format */
#define E_ADI_A2B_HAL_ASRC_OUTPUT_NONE                   (4U)    /*!< None  */

/* Values are derived from ASRC SSDD driver */
#define E_ADI_A2B_HAL_ASRC_WORD_LENGTH_24       (0x00000000)     /*!< 24-bit   */
#define E_ADI_A2B_HAL_ASRC_WORD_LENGTH_20       (0x00001000)     /*!< 20-bit   */
#define E_ADI_A2B_HAL_ASRC_WORD_LENGTH_18       (0x00002000)     /*!< 18-bit   */
#define E_ADI_A2B_HAL_ASRC_WORD_LENGTH_16       (0x00003000)     /*!< 16-bit   */
#define E_ADI_A2B_HAL_ASRC_WORD_LENGTH_NONE     (0x00004000)     /*!< None   */

/*============= E X T E R N A L S ============*/
/*
* External Data section
*/

/*
* External Function Prototypes
*/

/*-------------- S P O R T --------------*/

/*-------------- S P I --------------*/

/*-------------- P C G --------------*/

/*-------------- A D A U 1 9 7 9 --------------*/

/*-------------- A D A U 1 9 6 2 A --------------*/

/*-------------- G P I O --------------*/

/*-------------- S P D I F Rx--------------*/

/*-------------- A S R C --------------*/

/*============= D A T A T Y P E S =============*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*-------------- S P O R T --------------*/

typedef void* ADI_A2B_HAL_SPORT_HANDLE;  /*!< Type define for SPORT HAL handle. */
typedef void *tSPORTCBParam;            /*!< Type define for SPORT CallBack parameter */

/*! \enum ADI_A2B_HAL_SPORT_STATUS
Enumeration for SPORT HAL status.
*/
typedef enum ADI_A2B_HAL_SPORT_STATUS
{
    ADI_A2B_HAL_SPORT_STATUS_SUCCESS  = E_ADI_A2B_HAL_SPORT_STATUS_SUCCESS,     /*!< HAL SPORT Status Success */
    ADI_A2B_HAL_SPORT_STATUS_FAILED   = E_ADI_A2B_HAL_SPORT_STATUS_FAILED       /*!< HAL SPORT Status Error   */
}ADI_A2B_HAL_SPORT_STATUS;

/*! \enum ADI_A2B_HAL_SPORT_DEVICE
Enumeration for SPORT device.
*/
typedef enum ADI_A2B_HAL_SPORT_DEVICE
{
    ADI_A2B_HAL_SPORT_0 = E_ADI_A2B_HAL_SPORT_0,   /*!< SPORT 0  */
    ADI_A2B_HAL_SPORT_1 = E_ADI_A2B_HAL_SPORT_1,   /*!< SPORT 1  */
    ADI_A2B_HAL_SPORT_2 = E_ADI_A2B_HAL_SPORT_2,   /*!< SPORT 2  */
    ADI_A2B_HAL_SPORT_3 = E_ADI_A2B_HAL_SPORT_3,   /*!< SPORT 3  */
}ADI_A2B_HAL_SPORT_DEVICE;

/*! \enum ADI_A2B_HAL_HSPORT_ID
Enumeration for Half SPORT device.
*/
typedef enum ADI_A2B_HAL_HSPORT_ID
{
    ADI_A2B_HAL_HALF_SPORT_A = E_ADI_HALF_SPORT_A, /*!< First Half SPORT */
    ADI_A2B_HAL_HALF_SPORT_B = E_ADI_HALF_SPORT_B  /*!< Second Half SPORT */
}ADI_A2B_HAL_HSPORT_ID;

/*! \enum tDirection
Enumeration for Direction of the SPORT operation.
*/
typedef enum tDirection
{
  ADI_A2B_HAL_SPORT_DIR_RX = E_ADI_A2B_HAL_SPORT_DIR_RX,       /*!< Sport in Rx mode */
  ADI_A2B_HAL_SPORT_DIR_TX = E_ADI_A2B_HAL_SPORT_DIR_TX        /*!< Sport in Tx mode */
}tDirection;

/*! \struct ADI_A2B_HAL_SPORT_DEV_CONFIG
HAL configuration structure for Half Sport.
*/
typedef struct ADI_A2B_HAL_SPORT_DEV_CONFIG
{
    ADI_A2B_HAL_SPORT_DEVICE eSportNum;          /*!< SPORT Device number                    */
    ADI_A2B_HAL_HSPORT_ID    eSportHalf;         /*!< Half SPORT ID                          */
    uint8_t                  nTDMCh;             /*!< TDM Channels per HSPORT                */
    tDirection               eDirection;         /*!< Tx or Rx direction for HSPORT          */
    uint32_t                 nStChnlNo;          /*!< HSPORT starting multichannel number    */
    uint32_t                 nEndChnlNo;         /*!< HSPORT ending multichannel number      */
    ADI_CALLBACK             pfSPORTCallBack;    /*!< Pointer to HSPORT call back function   */
    tSPORTCBParam            pSPORTCBParam;      /*!< Pointer to HSPORT call back parameter  */
}ADI_A2B_HAL_SPORT_DEV_CONFIG;


/*-------------- S P I --------------*/
#if 0
typedef void (*SPIISR)(int32_t iid, void *handlerArg);  /*!< Type define for SPI ISR Function pointer */

typedef void* ADI_A2B_HAL_SPI_HANDLE;    /*!< Type definition for SPI HAL Handle */

/*! \enum ADI_A2B_HAL_SPI_STATUS
Enumeration for SPI HAL status
*/
typedef enum ADI_A2B_HAL_SPI_STATUS
{
    ADI_A2B_HAL_SPI_STATUS_SUCCESS,      /*!< HAL SPI status success */
    ADI_A2B_HAL_SPI_STATUS_FAILED         /*!< HAL SPI status error   */
}ADI_A2B_HAL_SPI_STATUS;

/*! \enum ADI_A2B_HAL_SPI_DEVICE
Enumeration for SPI HAL device id
*/
typedef enum ADI_A2B_HAL_SPI_DEVICE
{
    ADI_A2B_HAL_SPI_DEV1,                /*!< HAL SPI device number 1    */
    ADI_A2B_HAL_SPI_DEV2                 /*!< HAL SPI device number 2    */
}ADI_A2B_HAL_SPI_DEVICE;

/*! \struct ADI_A2B_HAL_SPI_DEVCONFIG
SPI HAL device configuration structure
*/
typedef struct ADI_A2B_HAL_SPI_DEVCONFIG
{
    uint32_t nPhase;        /*!< SPI clock phase */
    uint32_t nPolarity;     /*!< SPI clock polarity */
    bool     nLSBFirst;     /*!< Bit order */
    SPIISR   pfSPIISRRx;    /*!< SPI interrupt service routine */
    SPIISR   pfSPIISRTx;    /*!< SPI interrupt service routine */
    uint32_t nWordSz;       /*!< Word size of SPI */

    /* More config items */
    bool     nSPISlaveEn;   /*!< Boolean flag for SPI to be enabled as slave */
}ADI_A2B_HAL_SPI_DEVCONFIG;


/*-------------- P C G --------------*/

/*! \enum tPROC
Processor type enumeration
*/
typedef enum tPROC
{
    PROC_3xx = E_PROC_3xx,      /*!< ADI ADSP-213xx processors series */
    PROC_4xx = E_PROC_4xx,      /*!< ADI ADSP-214xx processors series */
    PROC_5xx = E_PROC_5xx       /*!< ADI ADSP-215xx processors series */
}tPROC;

#if  defined(__214xx__)

#define CLKIN 25000000

typedef enum tPCGUnit
{
    PCG_A = E_PCG_A,
    PCG_B = E_PCG_B,
    PCG_C = E_PCG_C,
    PCG_D = E_PCG_D
}tPCGUnit;

#elif defined(__ADSP215xx__)

#define CLKIN 24576000u     /*!< Definition for external clock input of 24.576 MHz for PCG */

/*! \enum tPCGUnit
PCG unit enumertaions
*/
typedef enum tPCGUnit
{
    PCG_A = E_PCG_A,        /*!< PCG A */
    PCG_B = E_PCG_B,        /*!< PCG B */
    PCG_C = E_PCG_C,        /*!< PCG C */
    PCG_D = E_PCG_D         /*!< PCG D */
}tPCGUnit;


#elif defined(__2136x__)

#define CLKIN 25000000

typedef enum tPCGUnit
{
    PCG_A = E_PCG_A,
    PCG_B = E_PCG_B
}tPCGUnit;

#endif    /* #if  defined(__214xx__) */

typedef void* ADI_A2B_HAL_PCG_HANDLE;        /*!< Type definition for PCG HAL Handle */

/*! \enum ADI_A2B_HAL_PCG_STATUS
Enumeration for PCG HAL status
*/
typedef enum ADI_A2B_HAL_PCG_STATUS
{
    ADI_A2B_HAL_PCG_STATUS_SUCCESS   = E_ADI_A2B_HAL_PCG_STATUS_SUCCES,         /*!< HAL PCG status success */
    ADI_A2B_HAL_PCG_STATUS_FAILED    = E_ADI_A2B_HAL_PCG_STATUS_FAILED          /*!< HAL PCG status error   */
}ADI_A2B_HAL_PCG_STATUS;

/*! \enum ADI_A2B_HAL_PCG_DEVICE
Enumeration for PCG HAL device id
*/
typedef enum ADI_A2B_HAL_PCG_DEVICE
{
    ADI_A2B_HAL_PCG_DEV_A = E_PCG_A,         /*!< HAL PCG device number A    */
    ADI_A2B_HAL_PCG_DEV_B = E_PCG_B,         /*!< HAL PCG device number B    */
    ADI_A2B_HAL_PCG_DEV_C = E_PCG_C,         /*!< HAL PCG device number C    */
    ADI_A2B_HAL_PCG_DEV_D = E_PCG_D,         /*!< HAL PCG device number D    */
}ADI_A2B_HAL_PCG_DEVICE;

/*! \struct ADI_A2B_HAL_PCG_DEV_CONFIG
HAL configuration structure for PCG.
*/
typedef struct ADI_A2B_HAL_PCG_DEV_CONFIG
{
    uint32_t    nSamplingFrequency;         /*!< Sampling frequency of the system. */
    uint32_t    nNumChannels;               /*!< Number of input channels. */
    uint32_t    nEnFsPhase;                 /*!< PCG enable clack and frame sync. */
    uint32_t    nInitPwSync;                /*!< PCG initialize the pulse width and clock and frame sync. */
    uint32_t    nEnExtInputClk;             /*!< Enable external clock input for PCG. */
    uint32_t    nExtClk;                    /*!< External clock input value. */
    uint32_t    nPulseWidth2;               /*!< Sets the number of input clock periods for which the frame sync output
                                                 is high for PCG. */
}ADI_A2B_HAL_PCG_DEV_CONFIG;
#endif /* #if 0 */
/*-------------- A D A U 1 9 7 9 --------------*/

typedef void* ADI_A2B_HAL_ADAU1979_HANDLE;   /*!<  HAL ADAU1979 handle       */

typedef enum ADI_A2B_HAL_ADAU1979_STATUS
{
    ADI_A2B_HAL_ADAU1979_STATUS_SUCCESS = E_ADI_A2B_HAL_ADAU1979_STATUS_SUCCESS,  /*!<  HAL ADAU1979 success status     */
    ADI_A2B_HAL_ADAU1979_STATUS_FAILED  = E_ADI_A2B_HAL_ADAU1979_STATUS_FAILED    /*!<  HAL ADAU1979 error status       */
}ADI_A2B_HAL_ADAU1979_STATUS;

typedef enum ADI_A2B_HAL_ADAU1979_SAMPLE_RATE
{
    ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_32000HZ  = E_ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_32000HZ ,  /*!< Sample rate 32   kHz */
    ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_44100HZ  = E_ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_44100HZ ,  /*!< Sample rate 44.1 kHz */
    ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_48000HZ  = E_ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_48000HZ ,  /*!< Sample rate 48   kHz */
    ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_96000HZ  = E_ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_96000HZ ,  /*!< Sample rate 96   kHz */
    ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_192000HZ = E_ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_192000HZ,  /*!< Sample rate 192  kHz */
    ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_NONE     = E_ADI_A2B_HAL_ADAU1979_SAMPLE_RATE_NONE       /*!< Sample rate none     */
}ADI_A2B_HAL_ADAU1979_SAMPLE_RATE;

typedef struct ADI_A2B_HAL_ADAU1979_CONFIG
{
    ADI_A2B_HAL_ADAU1979_SAMPLE_RATE     eSampleRate;    /*!< ADAU1979 sampling rate */
}ADI_A2B_HAL_ADAU1979_CONFIG;

/*-------------- A D A U 1 9 6 2 A --------------*/

typedef void* ADI_A2B_HAL_ADAU1962A_HANDLE;      /*!<  HAL ADAU1962A handle      */

typedef enum ADI_A2B_HAL_ADAU1962A_STATUS
{
    ADI_A2B_HAL_ADAU1962A_STATUS_SUCCESS = E_ADI_A2B_HAL_ADAU1962A_STATUS_SUCCESS , /*!< HAL ADAU1962A success status   */
    ADI_A2B_HAL_ADAU1962A_STATUS_FAILED  = E_ADI_A2B_HAL_ADAU1962A_STATUS_FAILED    /*!< HAL ADAU1962A error status     */
}ADI_A2B_HAL_ADAU1962A_STATUS;

typedef enum ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE
{
    ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_32000HZ  = E_ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_32000HZ , /*!< Sample rate 32   kHz*/
    ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_44100HZ  = E_ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_44100HZ , /*!< Sample rate 44.1 kHz*/
    ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_48000HZ  = E_ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_48000HZ , /*!< Sample rate 48   kHz*/
    ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_96000HZ  = E_ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_96000HZ , /*!< Sample rate 96   kHz*/
    ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_192000HZ = E_ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_192000HZ, /*!< Sample rate 192  kHz*/
    ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_NONE     = E_ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE_NONE      /*!< Sample rate none    */
}ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE;

typedef struct ADI_A2B_HAL_ADAU1962A_CONFIG
{
    ADI_A2B_HAL_ADAU1962A_SAMPLE_RATE    eSampleRate;       /*!< ADAU1962A sampling rate   */
}ADI_A2B_HAL_ADAU1962A_CONFIG;

/*-------------- G P I O --------------*/

/*! \enum ADI_A2B_HAL_GPIO_PORT
The HAL GPIO port enumerations.
*/
typedef enum ADI_A2B_HAL_GPIO_PORT
{
   ADI_A2B_HAL_GPIO_PORT_A  = E_ADI_A2B_HAL_GPIO_PORT_A,        /*!< Configure GPIO port A. */
   ADI_A2B_HAL_GPIO_PORT_B  = E_ADI_A2B_HAL_GPIO_PORT_B,        /*!< Configure GPIO port B. */
   ADI_A2B_HAL_GPIO_PORT_C  = E_ADI_A2B_HAL_GPIO_PORT_C,        /*!< Configure GPIO port C. */
   ADI_A2B_HAL_GPIO_PORT_D  = E_ADI_A2B_HAL_GPIO_PORT_D,        /*!< Configure GPIO port D. */
   ADI_A2B_HAL_GPIO_PORT_E  = E_ADI_A2B_HAL_GPIO_PORT_E,        /*!< Configure GPIO port E. */
   ADI_A2B_HAL_GPIO_PORT_F  = E_ADI_A2B_HAL_GPIO_PORT_F,        /*!< Configure GPIO port F. */
   ADI_A2B_HAL_GPIO_PORT_G  = E_ADI_A2B_HAL_GPIO_PORT_G         /*!< Configure GPIO port G. */
} ADI_A2B_HAL_GPIO_PORT;

/*! \enum ADI_A2B_HAL_GPIO_PIN
The HAL GPIO pin enumerations.
*/
typedef enum ADI_A2B_HAL_GPIO_PIN
{
   ADI_A2B_HAL_GPIO_PIN_0   = E_ADI_A2B_HAL_GPIO_PIN_0,          /*!< Configure GPIO Pin 0  */
   ADI_A2B_HAL_GPIO_PIN_1   = E_ADI_A2B_HAL_GPIO_PIN_1,          /*!< Configure GPIO Pin 1  */
   ADI_A2B_HAL_GPIO_PIN_2   = E_ADI_A2B_HAL_GPIO_PIN_2,          /*!< Configure GPIO Pin 2  */
   ADI_A2B_HAL_GPIO_PIN_3   = E_ADI_A2B_HAL_GPIO_PIN_3,          /*!< Configure GPIO Pin 3  */
   ADI_A2B_HAL_GPIO_PIN_4   = E_ADI_A2B_HAL_GPIO_PIN_4,          /*!< Configure GPIO Pin 4  */
   ADI_A2B_HAL_GPIO_PIN_5   = E_ADI_A2B_HAL_GPIO_PIN_5,          /*!< Configure GPIO Pin 5  */
   ADI_A2B_HAL_GPIO_PIN_6   = E_ADI_A2B_HAL_GPIO_PIN_6,          /*!< Configure GPIO Pin 6  */
   ADI_A2B_HAL_GPIO_PIN_7   = E_ADI_A2B_HAL_GPIO_PIN_7,          /*!< Configure GPIO Pin 7  */
   ADI_A2B_HAL_GPIO_PIN_8   = E_ADI_A2B_HAL_GPIO_PIN_8,          /*!< Configure GPIO Pin 8  */
   ADI_A2B_HAL_GPIO_PIN_9   = E_ADI_A2B_HAL_GPIO_PIN_9,          /*!< Configure GPIO Pin 9  */
   ADI_A2B_HAL_GPIO_PIN_10  = E_ADI_A2B_HAL_GPIO_PIN_10,         /*!< Configure GPIO Pin 10 */
   ADI_A2B_HAL_GPIO_PIN_11  = E_ADI_A2B_HAL_GPIO_PIN_11,         /*!< Configure GPIO Pin 11 */
   ADI_A2B_HAL_GPIO_PIN_12  = E_ADI_A2B_HAL_GPIO_PIN_12,         /*!< Configure GPIO Pin 12 */
   ADI_A2B_HAL_GPIO_PIN_13  = E_ADI_A2B_HAL_GPIO_PIN_13,         /*!< Configure GPIO Pin 13 */
   ADI_A2B_HAL_GPIO_PIN_14  = E_ADI_A2B_HAL_GPIO_PIN_14,         /*!< Configure GPIO Pin 14 */
   ADI_A2B_HAL_GPIO_PIN_15  = E_ADI_A2B_HAL_GPIO_PIN_15          /*!< Configure GPIO Pin 15 */
} ADI_A2B_HAL_GPIO_PIN;

/*! \enum ADI_A2B_HAL_GPIO_DIRECTION
The HAL GPIO direction enumerations.
*/
typedef enum ADI_A2B_HAL_GPIO_DIRECTION
{
    ADI_A2B_HAL_GPIO_DIRECTION_INPUT     = E_ADI_A2B_HAL_GPIO_DIRECTION_INPUT,  /*!< Set the GPIO pin to an input. */
    ADI_A2B_HAL_GPIO_DIRECTION_OUTPUT    = E_ADI_A2B_HAL_GPIO_DIRECTION_OUTPUT  /*!< Set the GPIO pin to an output. */
} ADI_A2B_HAL_GPIO_DIRECTION;

/*! \enum ADI_A2B_HAL_GPIO_STATUS
Enumeration of result codes generated by HAL GPIO device.
*/
typedef enum ADI_A2B_HAL_GPIO_STATUS
{
    ADI_A2B_HAL_GPIO_STATUS_SUCCESS      = E_ADI_A2B_HAL_GPIO_STATUS_SUCCESS,  /*!< The API call succeeded. */
    ADI_A2B_HAL_GPIO_STATUS_FAILED       = E_ADI_A2B_HAL_GPIO_STATUS_FAILED    /*!< The API call failed. */
} ADI_A2B_HAL_GPIO_STATUS;

/*-------------- S P D I F Rx--------------*/

typedef void* ADI_A2B_HAL_SPDIF_RX_HANDLE;   /*!< Type define for SPDIF Rx HAL handle. */
typedef void *tSPDIFRxCBParam;              /*!< Type define for SPDIF Rx CallBack parameter */

/*! \enum ADI_A2B_HAL_SPDIF_RX_STATUS
Enumeration for SPDIF Rx HAL status.
*/
typedef enum ADI_A2B_HAL_SPDIF_RX_STATUS
{
    ADI_A2B_HAL_SPDIF_RX_STATUS_SUCCESS  = E_ADI_A2B_HAL_SPDIF_RX_STATUS_SUCCESS,     /*!< HAL SPDIF Rx Status Success */
    ADI_A2B_HAL_SPDIF_RX_STATUS_FAILED   = E_ADI_A2B_HAL_SPDIF_RX_STATUS_FAILED       /*!< HAL SPDIF Rx Status Error   */
}ADI_A2B_HAL_SPDIF_RX_STATUS;

/*! \enum ADI_A2B_HAL_SPDIF_RX_DEVICE
Enumeration for SPDIF Rx device.
*/
typedef enum ADI_A2B_HAL_SPDIF_RX_DEVICE
{
    ADI_A2B_HAL_SPDIF_RX_0 = E_ADI_A2B_HAL_SPDIF_RX_0,   /*!< SPDIF Rx 0  */
    ADI_A2B_HAL_SPDIF_RX_1 = E_ADI_A2B_HAL_SPDIF_RX_1    /*!< SPDIF Rx 1  */
}ADI_A2B_HAL_SPDIF_RX_DEVICE;

/*! \struct ADI_A2B_HAL_SPDIF_RX_DEV_CONFIG
HAL configuration structure for SPDIF Receiver.
*/
typedef struct ADI_A2B_HAL_SPDIF_RX_DEV_CONFIG
{
    ADI_A2B_HAL_SPDIF_RX_DEVICE eSpdifRxNum;        /*!< SPDIF Rx Device number */
    void*                       pfSpdifRxCallBack;  /*!< Pointer to SPDIF Rx call back function   */
    tSPDIFRxCBParam             pSpdifRxCBParam;    /*!< Pointer to SPDIF Rx call back parameter  */
}ADI_A2B_HAL_SPDIF_RX_DEV_CONFIG;

/*-------------- A S R C --------------*/

typedef void* ADI_A2B_HAL_ASRC_HANDLE;   /*!< Type define for ASRC HAL handle. */

/*! \enum ADI_A2B_HAL_ASRC_STATUS
Enumeration for ASRC HAL status.
*/
typedef enum ADI_A2B_HAL_ASRC_STATUS
{
    ADI_A2B_HAL_ASRC_STATUS_SUCCESS  = E_ADI_A2B_HAL_ASRC_STATUS_SUCCESS,     /*!< HAL ASRC Status Success */
    ADI_A2B_HAL_ASRC_STATUS_FAILED   = E_ADI_A2B_HAL_ASRC_STATUS_FAILED       /*!< HAL ASRC Status Error   */
}ADI_A2B_HAL_ASRC_STATUS;

/*! \enum ADI_A2B_HAL_ASRC_BLK
Enumeration for ASRC HAL block.
*/
typedef enum ADI_A2B_HAL_ASRC_BLK
{
    ADI_A2B_HAL_ASRC_BLK_0 = E_ADI_A2B_HAL_ASRC_BLK_0,   /*!< ASRC block 0  */
    ADI_A2B_HAL_ASRC_BLK_1 = E_ADI_A2B_HAL_ASRC_BLK_1    /*!< ASRC block 1  */
}ADI_A2B_HAL_ASRC_BLK;

/*! \enum ADI_A2B_HAL_ASRC_DEVICE
Enumeration for ASRC HAL device.
*/
typedef enum ADI_A2B_HAL_ASRC_DEVICE
{
    ADI_A2B_HAL_ASRC_0 = E_ADI_A2B_HAL_ASRC_0,   /*!< ASRC 0  */
    ADI_A2B_HAL_ASRC_1 = E_ADI_A2B_HAL_ASRC_1,   /*!< ASRC 1  */
    ADI_A2B_HAL_ASRC_2 = E_ADI_A2B_HAL_ASRC_2,   /*!< ASRC 2  */
    ADI_A2B_HAL_ASRC_3 = E_ADI_A2B_HAL_ASRC_3    /*!< ASRC 3  */
}ADI_A2B_HAL_ASRC_DEVICE;

/*! \enum ADI_A2B_HAL_ASRC_INPUT_FORMAT
Enumeration for ASRC input format.
*/
typedef enum ADI_A2B_HAL_ASRC_INPUT_FORMAT
{
    ADI_A2B_HAL_ASRC_INPUT_LEFT_JUSTIFIED        = E_ADI_A2B_HAL_ASRC_INPUT_LEFT_JUSTIFIED,
    ADI_A2B_HAL_ASRC_INPUT_I2S                   = E_ADI_A2B_HAL_ASRC_INPUT_I2S,
    ADI_A2B_HAL_ASRC_INPUT_TDM                   = E_ADI_A2B_HAL_ASRC_INPUT_TDM,
    ADI_A2B_HAL_ASRC_INPUT_24BIT_RIGHT_JUSTIFIED = E_ADI_A2B_HAL_ASRC_INPUT_24BIT_RIGHT_JUSTIFIED,
    ADI_A2B_HAL_ASRC_INPUT_20BIT_RIGHT_JUSTIFIED = E_ADI_A2B_HAL_ASRC_INPUT_20BIT_RIGHT_JUSTIFIED,
    ADI_A2B_HAL_ASRC_INPUT_18BIT_RIGHT_JUSTIFIED = E_ADI_A2B_HAL_ASRC_INPUT_18BIT_RIGHT_JUSTIFIED,
    ADI_A2B_HAL_ASRC_INPUT_16BIT_RIGHT_JUSTIFIED = E_ADI_A2B_HAL_ASRC_INPUT_16BIT_RIGHT_JUSTIFIED,
    ADI_A2B_HAL_ASRC_INPUT_NONE                  = E_ADI_A2B_HAL_ASRC_INPUT_NONE
}ADI_A2B_HAL_ASRC_INPUT_FORMAT;

/*! \enum ADI_A2B_HAL_ASRC_OUTPUT_FORMAT
Enumeration for ASRC output format.
*/
typedef enum ADI_A2B_HAL_ASRC_OUTPUT_FORMAT
{
    ADI_A2B_HAL_ASRC_OUTPUT_LEFT_JUSTIFIED       = E_ADI_A2B_HAL_ASRC_OUTPUT_LEFT_JUSTIFIED,
    ADI_A2B_HAL_ASRC_OUTPUT_I2S                  = E_ADI_A2B_HAL_ASRC_OUTPUT_I2S,
    ADI_A2B_HAL_ASRC_OUTPUT_TDM                  = E_ADI_A2B_HAL_ASRC_OUTPUT_TDM,
    ADI_A2B_HAL_ASRC_OUTPUT_RIGHT_JUSTIFIED      = E_ADI_A2B_HAL_ASRC_OUTPUT_RIGHT_JUSTIFIED,
    ADI_A2B_HAL_ASRC_OUTPUT_NONE                 = E_ADI_A2B_HAL_ASRC_OUTPUT_NONE
}ADI_A2B_HAL_ASRC_OUTPUT_FORMAT;

/*! \enum ADI_A2B_HAL_ASRC_WORD_LEN
Enumeration for ASRC word length.
*/
typedef enum ADI_A2B_HAL_ASRC_WORD_LEN
{
    ADI_A2B_HAL_ASRC_WORD_LENGTH_24      = E_ADI_A2B_HAL_ASRC_WORD_LENGTH_24,
    ADI_A2B_HAL_ASRC_WORD_LENGTH_20      = E_ADI_A2B_HAL_ASRC_WORD_LENGTH_20,
    ADI_A2B_HAL_ASRC_WORD_LENGTH_18      = E_ADI_A2B_HAL_ASRC_WORD_LENGTH_18,
    ADI_A2B_HAL_ASRC_WORD_LENGTH_16      = E_ADI_A2B_HAL_ASRC_WORD_LENGTH_16,
    ADI_A2B_HAL_ASRC_WORD_LENGTH_NONE    = E_ADI_A2B_HAL_ASRC_WORD_LENGTH_NONE
}ADI_A2B_HAL_ASRC_WORD_LEN;

/*! \struct ADI_A2B_HAL_ASRC_DEV_CONFIG
HAL configuration structure for ASRC.
*/
typedef struct ADI_A2B_HAL_ASRC_DEV_CONFIG
{
    ADI_A2B_HAL_ASRC_BLK             eAsrcBlkNum;       /*!< ASRC block number  */
    ADI_A2B_HAL_ASRC_DEVICE          eAsrcDeviceNum;    /*!< ASRC device number */
    ADI_A2B_HAL_ASRC_INPUT_FORMAT    eAsrcInputFormat;  /*!< ASRC input format */
    ADI_A2B_HAL_ASRC_OUTPUT_FORMAT   eAsrcOutputFormat; /*!< ASRC output format */
    ADI_A2B_HAL_ASRC_WORD_LEN        eAsrcWordLen;      /*!< ASRC word length */
}ADI_A2B_HAL_ASRC_DEV_CONFIG;


/*======= P U B L I C P R O T O T Y P E S ========*/
/* (globally-scoped functions) */

/*-------------- S P O R T --------------*/

ADI_A2B_HAL_SPORT_HANDLE adi_a2b_hal_sport_Open(uint8_t                                *pMemory,
                                                uint32_t                               nMemSize,
                                                ADI_A2B_HAL_SPORT_DEV_CONFIG           *pConfigSPORT);

ADI_A2B_HAL_SPORT_STATUS adi_a2b_hal_sport_Close(ADI_A2B_HAL_SPORT_HANDLE              hDeviceSport);

ADI_A2B_HAL_SPORT_STATUS adi_a2b_hal_sport_Enable(ADI_A2B_HAL_SPORT_HANDLE             hDeviceSport,
                                                  bool                                 bEnable);

ADI_A2B_HAL_SPORT_STATUS adi_a2b_hal_sport_ProcessBuffer(ADI_A2B_HAL_SPORT_HANDLE      hDeviceSport,
                                                         void                          *pBuffer,
                                                         uint32_t                      nBuffSizeInBytes);

ADI_A2B_HAL_SPORT_STATUS adi_a2b_hal_sport_Process2DBuffer(ADI_A2B_HAL_SPORT_HANDLE    hDeviceSport,
                                                           void                        *pBuffer,
                                                           uint32_t                    nXCount,
                                                           int32_t                     nXModify,
                                                           uint32_t                    nYCount,
                                                           int32_t                     nYModify);

/*-------------- S P I --------------*/
#if 0
ADI_A2B_HAL_SPI_HANDLE adi_a2b_hal_spi_Open(ADI_A2B_HAL_SPI_DEVICE                 eDev,
                                          uint8_t                               *pMem,
                                          ADI_A2B_HAL_SPI_DEVCONFIG              *pSPIConfig);
ADI_A2B_HAL_SPI_STATUS adi_a2b_hal_spi_Enable(ADI_A2B_HAL_SPI_HANDLE pSPIHandle);
ADI_A2B_HAL_SPI_STATUS adi_a2b_hal_spi_EnableTx(ADI_A2B_HAL_SPI_HANDLE pSPIHandle);
ADI_A2B_HAL_SPI_STATUS adi_a2b_hal_spi_DisableTx(ADI_A2B_HAL_SPI_HANDLE pSPIHandle);
ADI_A2B_HAL_SPI_STATUS adi_a2b_hal_spi_EnableRx(ADI_A2B_HAL_SPI_HANDLE pSPIHandle);
ADI_A2B_HAL_SPI_STATUS adi_a2b_hal_spi_ReconfigRxDma(ADI_A2B_HAL_SPI_HANDLE pSPIHandle, uint32_t nRxPayloadCnt);

/*-------------- P C G --------------*/

ADI_A2B_HAL_PCG_HANDLE adi_a2b_hal_pcg_Open(ADI_A2B_HAL_PCG_DEVICE eDev, ADI_A2B_HAL_PCG_DEVCONFIG *pPCGConfig);
ADI_A2B_HAL_PCG_STATUS adi_a2b_hal_pcg_Enable(ADI_A2B_HAL_PCG_HANDLE hDevicePcg);
#endif /* #if 0 */
/*-------------- A D A U 1 9 7 9 --------------*/

ADI_A2B_HAL_ADAU1979_HANDLE adi_a2b_hal_adau1979_Open(uint32_t                          *pMemory,
                                                      uint32_t                          nMemSize,
                                                      ADI_A2B_HAL_ADAU1979_CONFIG       *pADAU1979Config);
ADI_A2B_HAL_ADAU1979_STATUS adi_a2b_hal_adau1979_Enable(ADI_A2B_HAL_ADAU1979_HANDLE     hADAU1979);

/*-------------- A D A U 1 9 6 2 A --------------*/

ADI_A2B_HAL_ADAU1962A_HANDLE adi_a2b_hal_adau1962a_Open(uint32_t                        *pMemory,
                                                        uint32_t                        nMemSize,
                                                        ADI_A2B_HAL_ADAU1962A_CONFIG    *pADAU1962AConfig);
ADI_A2B_HAL_ADAU1962A_STATUS adi_a2b_hal_adau1962a_Enable(ADI_A2B_HAL_ADAU1962A_HANDLE  hADAU1962A);

/*-------------- G P I O --------------*/

ADI_A2B_HAL_GPIO_STATUS adi_a2b_hal_gpio_SetDirection(ADI_A2B_HAL_GPIO_PORT             ePort,
                                                      ADI_A2B_HAL_GPIO_PIN              ePin,
                                                      ADI_A2B_HAL_GPIO_DIRECTION        eDirection);
ADI_A2B_HAL_GPIO_STATUS adi_a2b_hal_gpio_Set   (ADI_A2B_HAL_GPIO_PORT ePort, ADI_A2B_HAL_GPIO_PIN ePin);
ADI_A2B_HAL_GPIO_STATUS adi_a2b_hal_gpio_Clear (ADI_A2B_HAL_GPIO_PORT ePort, ADI_A2B_HAL_GPIO_PIN ePin);
ADI_A2B_HAL_GPIO_STATUS adi_a2b_hal_gpio_Toggle(ADI_A2B_HAL_GPIO_PORT ePort, ADI_A2B_HAL_GPIO_PIN ePin);

/*-------------- S P D I F Rx--------------*/

ADI_A2B_HAL_SPDIF_RX_HANDLE adi_a2b_hal_spdifRx_Open (uint8_t                           *pMemory,
                                                      uint32_t                          nMemSize,
                                                      ADI_A2B_HAL_SPDIF_RX_DEV_CONFIG   *pConfigSpdifRx);

ADI_A2B_HAL_SPDIF_RX_STATUS adi_a2b_hal_spdifRx_Close (ADI_A2B_HAL_SPDIF_RX_HANDLE      hDeviceSpdifRx);

ADI_A2B_HAL_SPDIF_RX_STATUS adi_a2b_hal_spdifRx_Enable(ADI_A2B_HAL_SPDIF_RX_HANDLE      hDeviceSpdifRx,
                                                       bool                             bEnable);

/*-------------- A S R C --------------*/

ADI_A2B_HAL_ASRC_HANDLE adi_a2b_hal_asrc_Open  (uint8_t                                 *pMemory,
                                                uint32_t                                nMemSize,
                                                ADI_A2B_HAL_ASRC_DEV_CONFIG             *pConfigAsrc);

ADI_A2B_HAL_ASRC_STATUS adi_a2b_hal_asrc_Close (ADI_A2B_HAL_ASRC_HANDLE                 hDeviceAsrc);

ADI_A2B_HAL_ASRC_STATUS adi_a2b_hal_asrc_Enable(ADI_A2B_HAL_ASRC_HANDLE                 hDeviceAsrc,
                                                bool                                    bEnable);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _ADI_A2B_HAL_H_ */

/*
 *  @}
 */

/*
 *
 * EOF: $URL: https://ipdc-video-s03.ad.analog.com/svn/ss4sharc/trunk/target/Framework/Source/adi_a2b_hal.h $
 *
*/
