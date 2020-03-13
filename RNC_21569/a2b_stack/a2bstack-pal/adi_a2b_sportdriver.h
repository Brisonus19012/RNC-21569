/*******************************************************************************
Copyright (c) 2015 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
******************************************************************************
* @file: adi_a2b_sportdriver.h
* @brief: This file contains declarations required by SPORT driver file.
* @version: $Revision: 2599 $
* @date: $Date: 2014-10-31 12:26:45 +0530 (Fri, 31 Oct 2014) $
* Developed by: Automotive Software and Systems team, Bangalore, India
*****************************************************************************/

/*! \addtogroup SPORT
* @{
*/

/*! \addtogroup SPORT_Configuration SPORT Configuration
* @{
*/
#ifndef __ADI_A2B_SPORT_H__
#define __ADI_A2B_SPORT_H__

/*============= I N C L U D E S =============*/ 
#include <drivers/sport/adi_sport.h>            /*!< ADI SPORT(Serial Port) Device driver definitions include file */
#include "adi_a2b_hal.h"
/*============== D E F I N E S ===============*/ 
/*! The DIV factor for CLKD */
#define DIVCLKD 2
/*! The DIV factor for CLKA */
#define DIVCLKA 8
/*! The DIV factor for Frame Synch */
#define DIVFSA  512


#define SPORT_TCB_SIZE			                        (4U)        /* TCB Buf Size */
#define CHAIN_POINTER_OFFSET	                        (0U)        /* Offset for CP Register in TCB */
#define INTERNAL_COUNT_OFFSET	                        (1U)        /* Offset for Count Register in TCB */
#define INTERNAL_MOD_OFFSET		                        (2U)        /* Offset for Modifier Register in TCB */
#define INTEXT_INDEX_OFFSET		                        (3U)        /* Offset for Index Register in TCB */

#define ENUM_SPORT_PAIR_0_1		                        (0U)        /* Enum value for SPORT 0 and 1 */
#define ENUM_SPORT_PAIR_2_3		                        (2U)        /* Enum value for SPORT 2 and 3 */
#define ENUM_SPORT_PAIR_4_5		                        (4U)        /* Enum value for SPORT 4 and 5 */
#define ENUM_SPORT_PAIR_6_7		                        (6U)        /* Enum value for SPORT 6 and 7 */

#define SPORT_BUFFER_SIZE		                        (24U)		 /* Number of SPORT i/o samples per channel */

#define NUM_INPUT_SPORT_BUFFERS			                (4U)         /*!< Number of input SPORT Buffers */
#define NUM_OUTPUT_SPORT_BUFFERS		                (4U)         /*!< Number of output SPORT Buffers */

#define MAX_NUM_CHANNELS					            (16U)        /*!< Max num Channels */


#define ENUM_SPORT_SUCCESS					             (0U)        /*!< Enumeration for SPORT operation Success */
#define ENUM_SPORT_FAILED					             (1U)        /*!< Enumeration for SPORT operation Failure */

#define NUM_SPORT_DEVICES					             (4U)        /*!< Number of SPORT Devices */

#define ADI_A2B_HAL_SPORT_CONFIGDATA_WORDLEN_8           (7U)        /*!< Word Length of 8 bytes                       */
#define ADI_A2B_HAL_SPORT_CONFIGDATA_WORDLEN_16          (15U)       /*!< Word Length of 16 bytes                      */
#define ADI_A2B_HAL_SPORT_CONFIGDATA_WORDLEN_24          (23U)       /*!< Word Length of 24 bytes                      */
#define ADI_A2B_HAL_SPORT_CONFIGDATA_WORDLEN_32          (31U)       /*!< Word Length of 32 bytes                      */
#define ADI_A2B_HAL_SPORT_CONFIGDATA_LSB_FIRST           (true)      /*!< LSB first (Little endian)                    */
#define ADI_A2B_HAL_SPORT_CONFIGDATA_MSB_FIRST           (false)     /*!< MSB first (Big endian)                       */
#define ADI_A2B_HAL_SPORT_CONFIGDATA_EN_DMA_PACK         (true)      /*!< Enable DMA packing (from 16bit To 32bit)     */
#define ADI_A2B_HAL_SPORT_CONFIGDATA_DIS_DMA_PACK        (false)     /*!< Disable DMA packing                          */
#define ADI_A2B_HAL_SPORT_CONFIGDATA_EN_RJ               (true)      /*!< Enable Right Justified mode.                 */
#define ADI_A2B_HAL_SPORT_CONFIGDATA_DIS_RJ              (false)     /*!< Disble Right Justified mode.                 */

#define ADI_A2B_HAL_SPORT_CONFIGCLOCK_CLOCKRATIO         (0U)        /*!< Ratio between System clock and sport clock
                                                                         fspclk = fsclk/( nClockRatio + 1)            */
#define ADI_A2B_HAL_SPORT_CONFIGCLOCK_INTERNAL           (true)      /*!< Device configured to use Internal clock      */
#define ADI_A2B_HAL_SPORT_CONFIGCLOCK_EXTERNAL           (false)     /*!< Device configured to use external clock      */


#if __CCESVERSION__ == 0x02040000

#define ADI_A2B_HAL_SPORT_CONFIGCLOCK_FALLING_EDGE       (true)      /*!< Fixed on CCES2.4.0   */
#define ADI_A2B_HAL_SPORT_CONFIGCLOCK_RISING_EDGE        (false)     /*!< Fixed in CCES2.4.0   */

#elif ( __CCESVERSION__ == 0x02010000 || __CCESVERSION__ == 0x02030000 || \
		__CCESVERSION__ == 0x02020000 || __CCESVERSION__ == 0x02000000)

#define ADI_A2B_HAL_SPORT_CONFIGCLOCK_FALLING_EDGE       (false)     /*!< This value of should be changed when there's a
                                                                         fix in the SSLDD SPORT driver (CCES-11151)   */
#define ADI_A2B_HAL_SPORT_CONFIGCLOCK_RISING_EDGE        (true)      /*!< This value of should be changed when there's a
                                                                         fix in the SSLDD SPORT driver (CCES-11151)   */
#else

#define ADI_A2B_HAL_SPORT_CONFIGCLOCK_FALLING_EDGE       (true)      /*!< Fixed on CCES 2.4.0   */
#define ADI_A2B_HAL_SPORT_CONFIGCLOCK_RISING_EDGE        (false)     /*!< Fixed in CCES 2.4.0   */

#endif
#define ADI_A2B_HAL_SPORT_CONFIGCLOCK_EN_GATED_CLOCK     (true)      /*!< Enable gated clock mode                      */
#define ADI_A2B_HAL_SPORT_CONFIGCLOCK_DIS_GATED_CLOCK    (false)     /*!< Disable gated clock mode                     */
#define ADI_A2B_HAL_SPORT_CONFIGFS_FS_DIVISIOR           (0U)        /*!< Number of sport clk cycles b/w each frame cnt*/
#define ADI_A2B_HAL_SPORT_CONFIGFS_FS_REQUIRED           (true)      /*!< Device requires a FS for its operation       */
#define ADI_A2B_HAL_SPORT_CONFIGFS_FS_NOTREQUIRED        (false)     /*!< Device not requires a FS for its operation   */
#define ADI_A2B_HAL_SPORT_CONFIGFS_INTERNAL              (true)      /*!< Use internal frame sync                      */
#define ADI_A2B_HAL_SPORT_CONFIGFS_EXTERNAL              (false)     /*!< Use external frame sync                      */
#define ADI_A2B_HAL_SPORT_CONFIGFS_DATA_INDEP_FS         (true)      /*!< Use data-independent frame sync              */
#define ADI_A2B_HAL_SPORT_CONFIGFS_DATA_DEPEN_FS         (false)     /*!< Use data-dependent frame sync                */
#define ADI_A2B_HAL_SPORT_CONFIGFS_ACTIVEHIGH_FS         (false)     /*!< This value should be changed when there's a
                                                                         fix in the SSLDD SPORT driver   (CCES-11151) */
#define ADI_A2B_HAL_SPORT_CONFIGFS_ACTIVELOW_FS          (true)      /*!< This value should be changed when there's a
                                                                         fix in the SSLDD SPORT driver   (CCES-11151) */
#define ADI_A2B_HAL_SPORT_CONFIGFS_LATE_FS               (true)      /*!< Use late frame sync                          */
#define ADI_A2B_HAL_SPORT_CONFIGFS_EARLY_FS              (false)     /*!< Use Early frame sync                         */
#define ADI_A2B_HAL_SPORT_CONFIGFS_EDGESENSE_FS          (true)      /*!< Framesync is edge sensitive                  */
#define ADI_A2B_HAL_SPORT_CONFIGFS_LEVELSENSE_FS         (false)     /*!< Framesync is level sensitive                 */

#define ADI_A2B_HAL_SPORT_CONFIGMC_FRAME_DELAY           (1U)        /*!< Def for Half SPORT Multicahnnel frame delay  */
#define ADI_A2B_HAL_SPORT_CONFIGMC_WINDOW_SIZE           (0U)        /*!< Def for Half SPORT Multicahnnel window size  */
#define ADI_A2B_HAL_SPORT_CONFIGMC_EN_DMADATA_PACK       (true)      /*!< Def for enabling DAM data pack in MC mode    */
#define ADI_A2B_HAL_SPORT_CONFIGMC_DIS_DMADATA_PACK      (false)     /*!< Def for disabling DAM data pack in MC mode   */

#define ADI_A2B_HAL_SPORT_ENABLE_DMA                     (true)      /*!< Definition for enabling SPORT DMA            */
#define ADI_A2B_HAL_SPORT_DISABLE_DMA                    (false)     /*!< Definition for disabling SPORT DMA           */
#define ADI_A2B_HAL_SPORT_ENABLE_STREAMING               (true)      /*!< Definition for enabling SPORT streaming      */
#define ADI_A2B_HAL_SPORT_DISABLE_STREAMING              (false)     /*!< Definition for disabling SPORT streaming     */

#define ADI_A2B_HAL_SPORT_TDM_CH_2						 (1U)		 /*!< SPORT TDM channels = Actual TDM slots - 1    */
#define ADI_A2B_HAL_SPORT_TDM_CH_8						 (7U)		 /*!< SPORT TDM channels = Actual TDM slots - 1    */

#define MAX_NUM_INPUT_ANALOG_CHANNELS					 (16U)        /*!< Max num Input Channels */
#define MAX_NUM_OUTPUT_ANALOG_CHANNELS	    			 (16U)        /*!< Max num Output Channels */

/*============= D A T A  T Y P E S =============*/ 

#ifdef __cplusplus 
extern "C" { 
#endif /* __cplusplus */ 

typedef void* ADI_SPORT_HANDLE;
typedef void (*ADI_A2B_SPORT_CB)(void* pCommHandle, uint32 pBuf[], uint32 nSz);
typedef void *tSPORTCBParam;                                   /*!< Type define for SPORT CallBack parameter */

/*! \struct ADI_SPORT_CONFIG
    SPORT Configuration for a SPORT Pair (Rx and Tx)
*/
typedef struct ADI_SPORT_CONFIG
{
	uint32                   nMultChDelay;                      /*!< Multi Channel FS Delay      */
	uint32                   nTDMChSz;                          /*!< TDM processing size      */
	uint32                   bActiveLowFrameSync;               /*!< Active low frame Sync      */
	uint32                   nSamplingRisingClkEdge;            /*!< Rx sampling Clk Edge Rising - 1      */
    ADI_A2B_HAL_SPORT_DEVICE eSportNum;                         /*!< SPORT Device number                    */
    ADI_SPORT_CHANNEL        eSportHalf;                        /*!< Half SPORT ID                          */
    uint8                    nTDMCh;                            /*!< TDM Channels per HSPORT                */
    ADI_SPORT_DIRECTION      eDirection;                        /*!< Tx or Rx direction for HSPORT          */
    uint32_t                 nStChnlNo;                         /*!< HSPORT starting multichannel number    */
    uint32_t                 nEndChnlNo;                        /*!< HSPORT ending multichannel number      */
	ADI_A2B_SPORT_CB         pfSPORTCallBack;                   /*!< Sport CB Function      */
	tSPORTCBParam            pSPORTCBParam;                     /*!< Pointer to HSPORT call back parameter  */
}ADI_SPORT_PERI_CONFIG;

/*! \struct ADI_SPORT_INFO
    SPORT Internal structure for a SPORT instance of Rx and Tx
*/
typedef struct ADI_SPORT_INFO
{
ADI_A2B_DATA_MEM_ALIGN4
	uint32                    aSportBuff[MAX_NUM_CHANNELS * SPORT_BUFFER_SIZE * NUM_INPUT_SPORT_BUFFERS];
ADI_A2B_DATA_MEM_ALIGN4
    uint8                     aSPORTMem[ADI_SPORT_MEMORY_SIZE];  /*!< Buffer of size "ADI_SPORT_DMA_MEMORY_SIZE" bytes for SPORT device to work on. */
	volatile uint8            nSportInterruptFlg; /*!< Flag to indicate the SPORT interrupt                         */
	volatile uint64_t         nSportInterruptCnt; /*!< Parameter to keep track of SPORT interrupts                  */
	ADI_SPORT_PERI_CONFIG     oSportConfig;       /*!< SPORT configuration structure                                */
	uint8                     nSubBufInd;         /*!< Rx Buffer Index (out of the SPORT Buffers)                   */
	uint8                     nSportDevNum;       /*!< SPORT Device Num                                             */
	uint8                     nXCount;
	uint8                     nXModify;
	uint8                     nYCount;
	uint8                     nYModify;
	void *pUserArgument;                         /*!< Pointer to the user argument                                  */
} ADI_SPORT_BUFF_INFO;
/**
 @}
*/

/**
 @}
*/

/*======= P U B L I C   P R O T O T Y P E S ========*/ 

ADI_SPORT_RESULT adi_a2b_SerialPortOpen(uint8 nSportDeviceNo,ADI_SPORT_PERI_CONFIG *pConfig, void* pUserArgument);
ADI_SPORT_RESULT adi_a2b_SerialPortConfigure(uint8 nSportDeviceNo);
ADI_SPORT_RESULT adi_a2b_OutputSerialPortEnable(uint32 nSportNum);
ADI_SPORT_RESULT adi_a2b_InputSerialPortEnable(uint32 nSportNum);
ADI_SPORT_RESULT adi_a2b_sport_Close(uint8 nSportDeviceNo);
ADI_SPORT_RESULT adi_a2b_SerialPortEnable(uint32 nSportDeviceNo, bool bEnable);
ADI_SPORT_RESULT adi_a2b_sport_ProcessBuffer(ADI_SPORT_HANDLE hSPORT,
		                                      void  *pBuffer,
                                              uint32_t   nBuffSizeInBytes);
void adi_a2b_InitPCGForAD24xx(uint16 nTDMSize);
void adi_a2b_InitPCGForCodec(void);
void adi_a2b_DeInitPCGForCodec(void);
void adi_a2b_DeInitPCGForAD24xx (void);
void adi_RxSPORT_ISR(void *pCBParam, uint32 Event, void  *pArg);
void adi_TxSPORT_ISR(void *pCBParam, uint32 Event, void  *pArg);
#ifdef __cplusplus 
} 
#endif /* __cplusplus */ 

#endif /* __SPORT_H__ */

