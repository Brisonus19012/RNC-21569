/*******************************************************************************
Copyright (c) 2020 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
******************************************************************************
* @file: adi_a2b_busconfig.c
* @brief: This file contains A2B Schematic information
* @version: $Revision$
* @date: Monday, March 23, 2020-8:42:47 AM
* BCF Version - 1.0.0
* A2B DLL version- 19.2.0
* A2B Stack DLL version- 19.2.0.0
* SigmaStudio version- 4.03.003.1777
* Developed by: Automotive Software and Systems team, Bangalore, India
* THIS IS A SIGMASTUDIO GENERATED FILE AND SHALL NOT BE MODIFIED OUTSIDE OF SIGMASTUDIO
*****************************************************************************/

/*! \addtogroup Target_Independent
* @{
*/

/*! \addtogroup Bus_Configuration Bus Configuration
* @{
*/

#include "adi_a2b_datatypes.h"
#include "a2bstack-protobuf/inc/adi_a2b_graphdata.h"
#include "a2bstack-protobuf/inc/adi_a2b_busconfig.h"

static ADI_A2B_MASTER_SLAVE_CONFIG sChainConfig0;
static ADI_A2B_MASTER_NCD sMasterNode0;
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode0;
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode1;
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode2;
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode3;
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode4;
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode5;
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode6;
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode7;
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode8;
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode9;
static A2B_PERIPHERAL_DEVICE_CONFIG  Target_PeriConfig0;
static A2B_PERIPHERAL_DEVICE_CONFIG  Target_PeriConfig1;
static A2B_PERIPHERAL_DEVICE_CONFIG  Target_PeriConfig2;
static ADI_A2B_PERI_CONFIG_UNIT  gaPeriCfg_FF_39_Unit[46];
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave0_PeriConfig0;
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave1_PeriConfig0;
static ADI_A2B_PERI_CONFIG_UNIT  gaPeriCfg_1_19_Unit[7];
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave2_PeriConfig0;
static ADI_A2B_PERI_CONFIG_UNIT  gaPeriCfg_2_19_Unit[7];
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave3_PeriConfig0;
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave4_PeriConfig0;
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave5_PeriConfig0;
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave6_PeriConfig0;
static ADI_A2B_PERI_CONFIG_UNIT  gaPeriCfg_6_19_Unit[7];
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave7_PeriConfig0;
static ADI_A2B_PERI_CONFIG_UNIT  gaPeriCfg_7_19_Unit[7];
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave8_PeriConfig0;
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave9_PeriConfig0;


ADI_A2B_MEM_BCF_DATA

/* BUS CONFIGURATION */ 
ADI_A2B_BCD sBusDescription = 
 { 
	/* Number of master nodes/daisy chains in the network */ 
	.nNumMasterNode  = 1u, 
 
	/* Array of Master-slave daisy chains */ 
 	.apNetworkconfig = {  &sChainConfig0, NULL_PTR, NULL_PTR, NULL_PTR }, 

	/* Network control guidance */ 
	.sTargetProperties    = 
 	{ 
		/* Discovery Mode Selection */ 
		.eDiscoveryMode     = A2B_SIMPLE_DISCOVERY,

		/* Delay (in milliseconds) to wait after a software reset and before discovery start*/ 
		.nDiscoveryStartDelay     = 25,

		/*  Enable/Disable  Line diagnostics (Post discovery) */ 
		.bLineDiagnostics   = DISABLED,

		/*  Enable/Disable automatic discovery upon critical faults (during discovery process) */ 
		.bAutoDiscCriticalFault = DISABLED,

		/*  Number of automatic discovery attempts (during discovery process) */ 
		.nAttemptsCriticalFault = 0,

		/* Auto-rediscovery upon post discovery line fault */ 
		.bAutoRediscOnFault = DISABLED,

		/*! Interval (in milliseconds) between re-discovery attempt */ 
		.nRediscInterval = 100,

		/*! Number of peripheral devices connected to Target */
		.nNumPeriDevice = 3,

		/*! Array of peripheral configuration pointers */
 		.apPeriConfig = { 	&Target_PeriConfig0, &Target_PeriConfig1, &Target_PeriConfig2, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR }
 	}, 

 };

 /************************************************* CHAIN 0 DESCRIPTION  ********************************************************************************/

 /* MASTER-SLAVE DAISY CHAIN0 */ 
 
ADI_A2B_MEM_BCF_DATA 
static ADI_A2B_MASTER_SLAVE_CONFIG sChainConfig0= 
 { 
 	/* Pointer to master node */ 
	.pMasterConfig = &sMasterNode0, 
 
	/*! Number of Slave nodes */ 
	.nNumSlaveNode = 10,
 
	/*! Array of slave node pointers */ 
	.apSlaveConfig = { &sChain0_SlaveNode0, &sChain0_SlaveNode1, &sChain0_SlaveNode2, &sChain0_SlaveNode3, &sChain0_SlaveNode4, &sChain0_SlaveNode5, &sChain0_SlaveNode6, &sChain0_SlaveNode7, &sChain0_SlaveNode8, &sChain0_SlaveNode9},

	.sCommonSetting = 
 	{ 
		/*! Master I2C address - 7 bit */ 
		.nMasterI2CAddr = 0x68,

		/*! Bus I2C address - 7 bit */ 
		.nBusI2CAddr = 0x69,

		/*! Enable down stream */ 
		.bEnableDwnstream = ENABLED, 

		/*! Enable down stream */ 
		.bEnableUpstream = ENABLED, 

		/*! Down slot size */ 
		.nDwnSlotSize = A2B_DNSLOT_SIZE_24, 

 		/*! Up slot size  */ 
		.nUpSlotSize = A2B_UPSLOT_SIZE_24 ,

 		/*! Floating point compression for upstream  */ 
		.bUpstreamCompression  = DISABLED,

		/*! Floating point compression for downstream  */  
		.bDwnstreamCompression = DISABLED,

		/*! Reduce Data Rate on A2B Bus   */  
		.bEnableReduceRate = ENABLED,

		/*! System level reduced rate factor   */  
		.nSysRateDivFactor =1,

	} 
 };

 /************************************************* START OF MASTER NODE 0 DESCRIPTION ********************************************************************************/ 

 /*  MASTER NODE DESCRIPTION   */ 

ADI_A2B_MEM_BCF_DATA
static ADI_A2B_MASTER_NCD sMasterNode0= 
{
	/*! Node ID */
	.nNodeID			= 0x0u ,

	/*! Source node ID : '0xFF' indicates Target processor */
	.nSrcNodeID			= 0xFFu ,

	/*! Transceiver part number */
	.ePartNum			= ADI_A2B_AD2425 ,

	.sAuthSettings =
	{
		/*! Vendor ID - ADI */
		.nVendorID			= 0xADu ,

		/*! Silicon version  - ADI */
		.nVersionID			= 0x2u ,

		/*! Product ID - AD24xx */
		.nProductID			= 0x25u ,

		/*! Interface Capability - I2C */
		.nCapability		= 0x1u ,
	},

	.sCustomNodeAuthSettings =
	{
		/*! Enable/Disable Custom Node ID settings */
		.bCustomNodeIdAuth		= DISABLED ,

	},

	.sI2SSettings =
	{
		/*! TDM mode  */
		.nTDMMode			= A2B_TDM20 ,

		/*! TDM channel size  */
		.nTDMChSize			= A2B_32BIT_TDM ,

		/*! SYNC mode - Pulse/50% duty cycle   */
		.nSyncMode			= A2B_ALTERNATE_SYNC ,

		/*! SYNC Polarity- Rising/Falling edge */
		.nSyncPolarity		= RAISING_EDGE ,

		/*! Early frame sync status */
		.bEarlySync			= DISABLED ,

		/*! DTXn change BCLK edge */
		.nBclkTxPolarity	= RAISING_EDGE ,

		/*! DRXn Sampling BCLK edge */
		.nBclkRxPolarity	= FALLING_EDGE ,

		/*! Interleave slots between Tx pins  */
		.bTXInterleave		= DISABLED ,

		/*! Interleave slots between Rx pins  */
		.bRXInterleave		= DISABLED ,

		/*! Transmit Channel offset in TDM - 0 to 63 */
		.nTxOffset			= 0x0u ,

		/*! Receive channel offset in TDM - 0 to 63 */
		.nRxOffset			= 0x0u ,

		/*! Tx Pin TriState before driving TDM slots */
		.bTriStateBeforeTx	= DISABLED ,

		/*! Tx Pin Tristate after driving TDM slots */
		.bTriStateAfterTx	= DISABLED ,

		.sI2SRateConfig =
		{
			/*! Enable RR valid bit in LSB */
			.bRRValidBitLSB	= DISABLED ,

			/*! Enable Valid RR bit in Extra bit */
			.bRRValidBitExtraBit	= DISABLED ,

			/*! Enable Reduced rate strobe in ADR1/IO1 */
			.bRRStrobe	= DISABLED ,

			/*! Strobe direction High or Low */
			.bRRStrobeDirection	= A2B_HIGH ,

		},
	},
	.sConfigCtrlSettings =
	{
		/*! Early acknowledge for I2C read/write */
		.bI2CEarlyAck		= ENABLED ,

		/*! Response cycles  */
		.nRespCycle			= 0x57u ,

		/*! Pass up slots */
		.nPassUpSlots		= 0x12u ,

		/*! Pass down slots */
		.nPassDwnSlots		= 0x0u ,

		/*! Data control for Master */
		.nDatctrl		= 0x3u ,

	},
	.sGPIOSettings =
	{
		.sPinMuxSettings =
		{
			/*! GPIO 1 Pin multiplexing */
			.bGPIO1PinUsage	= A2B_GPIO_1_DISABLE ,

			/*! GPIO 2 Pin multiplexing */
			.bGPIO2PinUsage	= A2B_GPIO_2_DISABLE ,

			/*! GPIO 3 Pin multiplexing */
			.bGPIO3PinUsage	= A2B_GPIO_3_AS_DTX0 ,

			/*! GPIO 4 Pin multiplexing */
			.bGPIO4PinUsage	= A2B_GPIO_4_DISABLE ,

			/*! GPIO 5 Pin multiplexing */
			.bGPIO5PinUsage	= A2B_GPIO_5_AS_DRX0 ,

			/*! GPIO 6 Pin multiplexing */
			.bGPIO6PinUsage	= A2B_GPIO_6_DISABLE ,
			/*! GPIO 7 Pin multiplexing */
			.bGPIO7PinUsage	= A2B_GPIO_7_DISABLE ,

		},
		.sPinIntConfig =
		{
			/*! Enable GPIO 1 Input pin interrupt  */
			.bGPIO1Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 1 Input pin  */
			.bGPIO1IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 2 Input pin interrupt  */
			.bGPIO2Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 2 Input pin  */
			.bGPIO2IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 3 Input pin interrupt  */
			.bGPIO3Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 3 Input pin  */
			.bGPIO3IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 4 Input pin interrupt  */
			.bGPIO4Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 4 Input pin  */
			.bGPIO4IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 5 Input pin interrupt  */
			.bGPIO5Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 5 Input pin  */
			.bGPIO5IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 6 Input pin interrupt  */
			.bGPIO6Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 6 Input pin  */
			.bGPIO6IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 7 Input pin interrupt  */
			.bGPIO7Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 7 Input pin  */
			.bGPIO7IntPolarity	= RAISING_EDGE ,

		},
		.sOutPinVal =
		{
			/*! Data value for GPIO 1 output pin  */
			.bGPIO1Val = A2B_LOW ,

			/*! Data value for GPIO 2 output pin  */
			.bGPIO2Val = A2B_LOW ,

			/*! Data value for GPIO 3 output pin  */
			.bGPIO3Val = A2B_LOW ,

			/*! Data value for GPIO 4 output pin  */
			.bGPIO4Val = A2B_LOW ,

			/*! Data value for GPIO 5 output pin  */
			.bGPIO5Val = A2B_LOW ,

			/*! Data value for GPIO 6 output pin  */
			.bGPIO6Val = A2B_LOW ,

			/*! Data value for GPIO 7 output pin  */
			.bGPIO7Val = A2B_LOW ,

		},

		/*! Digital Pin drive strength */
		.bHighDriveStrength = ENABLED ,

		/*! IRQ Pin Invert */
		.bIRQInv = DISABLED ,

		/*! Enable tristate when inactive */
		.bIRQTriState = DISABLED ,

	},

	.sInterruptSettings =
	{
		/*! Report Header count error  */
		.bReportHDCNTErr		= ENABLED ,

		/*! Report Data decoding error  */
		.bReportDDErr			= ENABLED ,

		/*! Report Data CRC error  */
		.bReportCRCErr			= ENABLED ,

		/*! Report Data Parity error  */
		.bReportDataParityErr	= DISABLED ,

		/*! Report Data Bus Power error  */
		.bReportPwrErr			= ENABLED ,

		/*! Report bit error count overflow error  */
		.bReportErrCntOverFlow	= ENABLED ,

		/*! Report SRF miss error  */
		.bReportSRFMissErr	= ENABLED ,

		/*! Report GPIO  1 Interrupt */
		.bReportGPIO1			= DISABLED ,

		/*! Report GPIO  2 Interrupt */
		.bReportGPIO2			= DISABLED ,

		/*! Report GPIO  3 Interrupt */
		.bReportGPIO3			= DISABLED ,

		/*! Report GPIO  4 Interrupt */
		.bReportGPIO4			= DISABLED ,

		/*! Report GPIO  5 Interrupt */
		.bReportGPIO5			= DISABLED ,

		/*! Report GPIO  6 Interrupt */
		.bReportGPIO6			= DISABLED ,

		/*! Report GPIO  7 Interrupt */
		.bReportGPIO7			= DISABLED ,

		/*! Report I2C failure error  */
		.bReportI2CErr			= ENABLED ,

		/*! Report Discovery Completion */
		.bDiscComplete			= ENABLED ,

		/*! Report Interrupt frame error */
		.bIntFrameCRCErr		= ENABLED ,

		/*! Report Interrupt requests  */
		.bSlaveIntReq			= ENABLED ,

	},

	.sGPIODSettings =
	{
		.sGPIOD1Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},

		.sGPIOD2Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},

		.sGPIOD3Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},

		.sGPIOD4Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},

		.sGPIOD5Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},

		.sGPIOD6Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},

		.sGPIOD7Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},

	},

	.sClkOutSettings =
	{
		/*! Enable Clock1 inversion */
		.bClk1Inv			= DISABLED ,

		/*! Clk1 pre-division */
		.bClk1PreDiv			= A2B_CLKOUT_PREDIV_02,

		/*! Clk1 division */
		.bClk1Div			= A2B_CLKOUT_DIV_2,

		/*! Enable Clock2 inversion */
		.bClk2Inv			= DISABLED ,

		/*! Clk2 pre-division */
		.bClk2PreDiv			= A2B_CLKOUT_PREDIV_02,

		/*! Clk2 division */
		.bClk2Div			= A2B_CLKOUT_DIV_2,

	},

	.sRegSettings =
	{
		/*! Switch control register */
		.nSWCTL		= 0x1u ,

		/*! PDM Control register  */
		.nPDMCTL	= 0x0u ,

		/*! Test mode register */
		.nTESTMODE	= 0x0u ,

		/*! Error control register */
		.nBECCTL	= 0xEFu ,

		/*! Error management register  */
		.nERRMGMT	= 0x0u ,

		/*! I2S test register  */
		.nI2STEST	= 0x0u ,

		/*! Generate error  */
		.nGENERR	= 0x0u ,

		/*! Raise interrupt register */
		.nRAISE		= 0x0u ,

		/*! Bus monitor configuration  */
		.nBMMCFG	= 0x0u ,

	}

};

/************************************************* END OF MASTER NODE 0 DESCRIPTION ********************************************************************************/

 /************************************************* START OF SLAVE NODE 0 DESCRIPTION ********************************************************************************/

/* SLAVE NODE DESCRIPTION */

ADI_A2B_MEM_BCF_DATA
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode0=
{
	/* Node ID  */
	.nNodeID			= 0x0u ,

	/* Source node ID  */
	.nSrcNodeID			= 0x0u ,

	/*! Transceiver part number */
	.ePartNum			= ADI_A2B_AD2427 ,

	/* Auto-configure Node Enabled */
	.bEnableAutoConfig			= DISABLED ,

	.sAuthSettings =
	{
		/*! Vendor ID - ADI */
		.nVendorID			= 0xADu ,

		/*! Silicon version  */
		.nVersionID			= 0x0u ,

		/*! PRODUCT ID -AD2410 */
		.nProductID			= 0x27u ,

		/*! Expected capablity - I2C */
		.nCapability		= 0x1u ,
	},

	.sCustomNodeAuthSettings =
	{
		/*! Enable/Disable Custom Node ID settings */
		.bCustomNodeIdAuth		= DISABLED ,

	},

	.sPDMSettings =
	{
		/*! Number of PDM0 slots  */
		.nNumSlotsPDM0		= A2B_PDM0SLOTS_1 ,

		/*! Number of PDM1 slots  */
		.nNumSlotsPDM1		= A2B_PDM1SLOTS_2 ,

		/*! Use High Pass Filter  */
		.bHPFUse		= ENABLED ,

		/*! PDM rate  */
		.nPDMRate		= A2B_PDM_RATE_SFF ,

		/*! PDM Inverted Version of Alternate Clock */
		.bPDMInvClk		= DISABLED ,

		/*! PDM Alternate Clock */
		.bPDMAltClk		= DISABLED ,

		/*! PDM0 Falling Edge First */
		.bPDM0FallingEdgeFrst		= DISABLED ,

		/*! PDM1 Falling Edge First */
		.bPDM1FallingEdgeFrst		= DISABLED ,

		/*! PDM Destination */
		.ePDMDestination		= A2B_BUS_ONLY ,

	},

	.sConfigCtrlSettings =
	{
		/*! I2C interface frequency */
		.nI2CFrequency		= A2B_I2C_100kHz ,

		/*! Response cycles  */
		.nRespCycle			= 0x57u ,

		/*! Expected super/audio frame rate */
		.nSuperFrameRate	= A2B_SFF_RATE_48_0kHz ,

		/*! Number of broadcast slots */
		.nBroadCastSlots	= 0x0u ,

		/*! Local down slots */
		.nLocalDwnSlotsConsume		= 0x0u ,

		/*! Local Up slots */
		.nLocalUpSlotsContribute		= 0x1u ,

		/*! Pass up slots */
		.nPassUpSlots		= 0x11u ,

		/*! Pass down slots */
		.nPassDwnSlots		= 0x0u ,

		/*! Number of slots for contribution */
		.nSlotsforDwnstrmContribute		= 0x0u ,

		/*! Number of Upslots consumed */
		.nLocalUpSlotsConsume		= 0x0u ,

		/*! Array of downstream  masks */
		.anUpstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED,
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for downstream contribution */
		.nOffsetDwnstrmContribute		= 0x0u ,

		/*! Enable Down slot consume through mask */
		.bUseDwnslotConsumeMasks		= ENABLED ,

		/*! Array of downstream  masks */
		.anDwnstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED,
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for Upstream contribution*/
		.nOffsetUpstrmContribute		= 0x0u ,

	},
	.sGPIOSettings =
	{
		.sPinMuxSettings =
		{
			/*! GPIO 0 Pin multiplexing */
			.bGPIO0PinUsage	= A2B_GPIO_0_DISABLE ,

			/*! GPIO 1 Pin multiplexing */
			.bGPIO1PinUsage	= A2B_GPIO_1_DISABLE ,

			/*! GPIO 2 Pin multiplexing */
			.bGPIO2PinUsage	= A2B_GPIO_2_AS_CLKOUT ,

			/*! GPIO 3 Pin multiplexing */
			.bGPIO3PinUsage	= A2B_GPIO_3_DISABLE ,

			/*! GPIO 4 Pin multiplexing */
			.bGPIO4PinUsage	= A2B_GPIO_4_OUTPUT ,

			/*! GPIO 5 Pin multiplexing */
			.bGPIO5PinUsage	= A2B_GPIO_5_AS_PDM0 ,

			/*! GPIO 6 Pin multiplexing */
			.bGPIO6PinUsage	= A2B_GPIO_6_DISABLE ,

			/*! GPIO 7 Pin multiplexing */
			.bGPIO7PinUsage	= A2B_GPIO_7_DISABLE ,
		},
		.sPinIntConfig =
		{
			/*! Enable GPIO 0 Input pin interrupt  */
			.bGPIO0Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 0 Input pin  */
			.bGPIO0IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 1 Input pin interrupt  */
			.bGPIO1Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 1 Input pin  */
			.bGPIO1IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 2 Input pin interrupt  */
			.bGPIO2Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 2 Input pin  */
			.bGPIO2IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 3 Input pin interrupt  */
			.bGPIO3Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 3 Input pin  */
			.bGPIO3IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 4 Input pin interrupt  */
			.bGPIO4Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 4 Input pin  */
			.bGPIO4IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 5 Input pin interrupt  */
			.bGPIO5Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 5 Input pin  */
			.bGPIO5IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 6 Input pin interrupt  */
			.bGPIO6Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 6 Input pin  */
			.bGPIO6IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 7 Input pin interrupt  */
			.bGPIO7Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 7 Input pin  */
			.bGPIO7IntPolarity	= RAISING_EDGE ,

		},
		.sOutPinVal =
		{
			/*! Data value for GPIO 0 output pin  */
			.bGPIO0Val = A2B_LOW ,

			/*! Data value for GPIO 1 output pin  */
			.bGPIO1Val = A2B_LOW ,

			/*! Data value for GPIO 2 output pin  */
			.bGPIO2Val = A2B_LOW ,

			/*! Data value for GPIO 3 output pin  */
			.bGPIO3Val = A2B_LOW ,

			/*! Data value for GPIO 4 output pin  */
			.bGPIO4Val = A2B_HIGH ,

			/*! Data value for GPIO 5 output pin  */
			.bGPIO5Val = A2B_LOW ,

			/*! Data value for GPIO 6 output pin  */
			.bGPIO6Val = A2B_LOW ,

			/*! Data value for GPIO 7 output pin  */
			.bGPIO7Val = A2B_LOW ,

		},

		/*! Digital Pin drive strength */
		.bHighDriveStrength = DISABLED ,

		/*! IRQ Pin Invert */
		.bIRQInv = DISABLED ,

		/*! Enable tristate when inactive */
		.bIRQTriState = DISABLED ,

	},

	.sInterruptSettings =
	{
		/*! Report Header count error  */
		.bReportHDCNTErr		= ENABLED ,

		/*! Report Data decoding error  */
		.bReportDDErr			= ENABLED ,

		/*! Report Data CRC error  */
		.bReportCRCErr			= ENABLED ,

		/*! Report Data Parity error  */
		.bReportDataParityErr	= DISABLED ,

		/*! Report Data Bus Power error  */
		.bReportPwrErr			= ENABLED ,

		/*! Report bit error count overflow error  */
		.bReportErrCntOverFlow	= ENABLED ,

		/*! Report SRF miss error  */
		.bReportSRFMissErr	= ENABLED ,

		/*! Report SRF crc error  */
		.bReportSRFCrcErr		= DISABLED ,

		/*! Report GPIO  0 Interrupt */
		.bReportGPIO0			= ENABLED ,

		/*! Report GPIO  1 Interrupt */
		.bReportGPIO1			= ENABLED ,

		/*! Report GPIO  2 Interrupt */
		.bReportGPIO2			= ENABLED ,

		/*! Report GPIO  3 Interrupt */
		.bReportGPIO3			= ENABLED ,

		/*! Report GPIO  4 Interrupt */
		.bReportGPIO4			= ENABLED ,

		/*! Report GPIO  5 Interrupt */
		.bReportGPIO5			= ENABLED ,

		/*! Report GPIO  6 Interrupt */
		.bReportGPIO6			= ENABLED ,

		/*! Report GPIO  7 Interrupt */
		.bReportGPIO7			= DISABLED ,

	},

	.sGPIODSettings =
	{
		.sGPIOD0Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD1Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD2Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD3Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD4Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD5Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD6Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD7Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
	},

	.sClkOutSettings =
	{
		/*! Enable Clock1 inversion */
		.bClk1Inv			= DISABLED ,

		/*! Clk1 pre-division */
		.bClk1PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk1 division */
		.bClk1Div			= A2B_CLKOUT_DIV_4,

		/*! Enable Clock2 inversion */
		.bClk2Inv			= DISABLED ,

		/*! Clk2 pre-division */
		.bClk2PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk2 division */
		.bClk2Div			= A2B_CLKOUT_DIV_4,

	},
	.sRegSettings =
	{
		/*! Switch control register */
		.nSWCTL		= 0x1u ,

		/*! Test mode register */
		.nTESTMODE	= 0x0u ,

		/*! Error control register */
		.nBECCTL	= 0xEFu ,

		/*! Error management register  */
		.nERRMGMT	= 0x0u ,

		/*! Generate error  */
		.nGENERR	= 0x0u ,

		/*! Raise interrupt register */
		.nRAISE		= 0x0u ,

		/*! Bus monitor configuration */
		.nBMMCFG		= 0x0u ,

		/*! Clock sustain configuration   */
		.nSUSCFG	= 0x0u ,

		/*!  Mailbox 0 control */
		.nMBOX0CTL		= 0x0u ,

		/*!  Mailbox 1 control */
		.nMBOX1CTL		= 0x0u ,

		/*! PLL Control register  */
		.nPLLCTL	= 0x0u ,

		/*! LVDSA TX Control Register */
		.nTXACTL	= 0x0u ,

		/*! LVDSB TX Control Register */
		.nTXBCTL	= 0x0u ,

		/*! Control Register */
		.nCONTROL	= 0x0u ,

	},

		 /* Number of peripheral devices connected  */
		.nNumPeriDevice = 1,

		 /*Array of peripheral configuration pointers */
		.apPeriConfig = { 	 &sChain0_Slave0_PeriConfig0, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR	}

};

/************************************************* END OF SLAVE NODE 0 DESCRIPTION ********************************************************************************/

/************************************************* START OF SLAVE NODE 1 DESCRIPTION ********************************************************************************/

/* SLAVE NODE DESCRIPTION */

ADI_A2B_MEM_BCF_DATA
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode1=
{
	/* Node ID  */
	.nNodeID			= 0x1u ,

	/* Source node ID  */
	.nSrcNodeID			= 0x0u ,

	/*! Transceiver part number */
	.ePartNum			= ADI_A2B_AD2425 ,

	/* Auto-configure Node Enabled */
	.bEnableAutoConfig			= DISABLED ,

	.sAuthSettings =
	{
		/*! Vendor ID - ADI */
		.nVendorID			= 0xADu ,

		/*! Silicon version  */
		.nVersionID			= 0x2u ,

		/*! PRODUCT ID -AD2410 */
		.nProductID			= 0x25u ,

		/*! Expected capablity - I2C */
		.nCapability		= 0x1u ,
	},

	.sCustomNodeAuthSettings =
	{
		/*! Enable/Disable Custom Node ID settings */
		.bCustomNodeIdAuth		= DISABLED ,

	},

	.sI2SSettings =
	{
		/*! TDM mode  */
		.nTDMMode		= A2B_TDM4 ,

		/*! TDM channel size  */
		.nTDMChSize			= A2B_16BIT_TDM ,

		/*! SYNC mode - Pulse/50% duty cycle   */
		.nSyncMode			= A2B_ALTERNATE_SYNC ,

		/*! SYNC Polarity- Rising/Falling edge */
		.nSyncPolarity		= RAISING_EDGE ,

		/*! Early frame sync status */
		.bEarlySync			= ENABLED ,

		/*! SYNC offset with Super frame */
		.nSyncOffset		= 0x0 ,

		/*! DTXn change BCLK edge */
		.nBclkTxPolarity	= FALLING_EDGE ,

		/*! DRXn sampling BCLK edge */
		.nBclkRxPolarity	= FALLING_EDGE ,

		/*! Interleave slots between Tx pins  */
		.bTXInterleave		= DISABLED ,

		/*! Interleave slots between Rx pins  */
		.bRXInterleave		= DISABLED ,

		.sI2SRateConfig =
		{
			/* Sample rate */
			.nSamplingRate		= A2B_SAMPLERATE_24kHz ,

			/*! Reduce / re-transmit higher frequency samples  */
		.bReduce			= DISABLED ,

			/*! Share A2B bus slots for reduced sampling */
			.bShareBusSlot	= DISABLED ,

			/*! Enable Valid RR bit in Extra bit */
			.bRRValidBitLSB 	= DISABLED ,

			/*! Enable Valid RR bit in Extra Channel */
			.bRRValidBitExtraBit	= DISABLED ,

			/*! Enable Reduced rate strobe in ADR1/IO1 */
			.bRRStrobe	= DISABLED ,

			/*! Strobe direction High or Low */
			.bRRStrobeDirection	= A2B_LOW ,

		},
	},

	.sPDMSettings =
	{
		/*! Number of PDM0 slots  */
		.nNumSlotsPDM0		= A2B_PDM0SLOTS_1 ,

		/*! Number of PDM1 slots  */
		.nNumSlotsPDM1		= A2B_PDM1SLOTS_2 ,

		/*! Use High Pass Filter  */
		.bHPFUse		= ENABLED ,

		/*! PDM rate  */
		.nPDMRate		= A2B_PDM_RATE_SFF ,

	},

	.sConfigCtrlSettings =
	{
		/*! I2C interface frequency */
		.nI2CFrequency		= A2B_I2C_100kHz ,

		/*! Response cycles  */
		.nRespCycle			= 0x53u ,

		/*! Expected super/audio frame rate */
		.nSuperFrameRate	= A2B_SFF_RATE_48_0kHz ,

		/*! Number of broadcast slots */
		.nBroadCastSlots	= 0x0u ,

		/*! Local down slots */
		.nLocalDwnSlotsConsume		= 0x0u ,

		/*! Local Up slots */
		.nLocalUpSlotsContribute		= 0x3u ,

		/*! Pass up slots */
		.nPassUpSlots		= 0xEu ,

		/*! Pass down slots */
		.nPassDwnSlots		= 0x0u ,

		/*! Number of slots for contribution */
		.nSlotsforDwnstrmContribute		= 0x0u ,

		/*! Number of Upslots consumed */
		.nLocalUpSlotsConsume		= 0x3u ,

		/*! Array of downstream  masks */
		.anUpstreamConsumeSlots = { SLOT_0_ENABLED, SLOT_1_ENABLED, SLOT_2_ENABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED,
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for downstream contribution */
		.nOffsetDwnstrmContribute		= 0x0u ,

		/*! Enable Down slot consume through mask */
		.bUseDwnslotConsumeMasks		= ENABLED ,

		/*! Array of downstream  masks */
		.anDwnstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED,
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for Upstream contribution*/
		.nOffsetUpstrmContribute		= 0x0u ,

	},
	.sGPIOSettings =
	{
		.sPinMuxSettings =
		{
			/*! GPIO 0 Pin multiplexing */
			.bGPIO0PinUsage	= A2B_GPIO_0_DISABLE ,

			/*! GPIO 1 Pin multiplexing */
			.bGPIO1PinUsage	= A2B_GPIO_1_AS_CLKOUT ,

			/*! GPIO 2 Pin multiplexing */
			.bGPIO2PinUsage	= A2B_GPIO_2_DISABLE ,

			/*! GPIO 3 Pin multiplexing */
			.bGPIO3PinUsage	= A2B_GPIO_3_DISABLE ,

			/*! GPIO 4 Pin multiplexing */
			.bGPIO4PinUsage	= A2B_GPIO_4_OUTPUT ,

			/*! GPIO 5 Pin multiplexing */
			.bGPIO5PinUsage	= A2B_GPIO_5_AS_DRX0 ,

			/*! GPIO 6 Pin multiplexing */
			.bGPIO6PinUsage	= A2B_GPIO_6_DISABLE ,

			/*! GPIO 7 Pin multiplexing */
			.bGPIO7PinUsage	= A2B_GPIO_7_DISABLE ,
		},
		.sPinIntConfig =
		{
			/*! Enable GPIO 0 Input pin interrupt  */
			.bGPIO0Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 0 Input pin  */
			.bGPIO0IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 1 Input pin interrupt  */
			.bGPIO1Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 1 Input pin  */
			.bGPIO1IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 2 Input pin interrupt  */
			.bGPIO2Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 2 Input pin  */
			.bGPIO2IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 3 Input pin interrupt  */
			.bGPIO3Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 3 Input pin  */
			.bGPIO3IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 4 Input pin interrupt  */
			.bGPIO4Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 4 Input pin  */
			.bGPIO4IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 5 Input pin interrupt  */
			.bGPIO5Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 5 Input pin  */
			.bGPIO5IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 6 Input pin interrupt  */
			.bGPIO6Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 6 Input pin  */
			.bGPIO6IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 7 Input pin interrupt  */
			.bGPIO7Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 7 Input pin  */
			.bGPIO7IntPolarity	= RAISING_EDGE ,

		},
		.sOutPinVal =
		{
			/*! Data value for GPIO 0 output pin  */
			.bGPIO0Val = A2B_LOW ,

			/*! Data value for GPIO 1 output pin  */
			.bGPIO1Val = A2B_LOW ,

			/*! Data value for GPIO 2 output pin  */
			.bGPIO2Val = A2B_LOW ,

			/*! Data value for GPIO 3 output pin  */
			.bGPIO3Val = A2B_LOW ,

			/*! Data value for GPIO 4 output pin  */
			.bGPIO4Val = A2B_HIGH ,

			/*! Data value for GPIO 5 output pin  */
			.bGPIO5Val = A2B_LOW ,

			/*! Data value for GPIO 6 output pin  */
			.bGPIO6Val = A2B_LOW ,

			/*! Data value for GPIO 7 output pin  */
			.bGPIO7Val = A2B_LOW ,

		},

		/*! Digital Pin drive strength */
		.bHighDriveStrength = DISABLED ,

		/*! IRQ Pin Invert */
		.bIRQInv = DISABLED ,

		/*! Enable tristate when inactive */
		.bIRQTriState = DISABLED ,

	},

	.sInterruptSettings =
	{
		/*! Report Header count error  */
		.bReportHDCNTErr		= ENABLED ,

		/*! Report Data decoding error  */
		.bReportDDErr			= ENABLED ,

		/*! Report Data CRC error  */
		.bReportCRCErr			= ENABLED ,

		/*! Report Data Parity error  */
		.bReportDataParityErr	= DISABLED ,

		/*! Report Data Bus Power error  */
		.bReportPwrErr			= ENABLED ,

		/*! Report bit error count overflow error  */
		.bReportErrCntOverFlow	= ENABLED ,

		/*! Report SRF miss error  */
		.bReportSRFMissErr	= ENABLED ,

		/*! Report SRF crc error  */
		.bReportSRFCrcErr		= DISABLED ,

		/*! Report GPIO  0 Interrupt */
		.bReportGPIO0			= ENABLED ,

		/*! Report GPIO  1 Interrupt */
		.bReportGPIO1			= ENABLED ,

		/*! Report GPIO  2 Interrupt */
		.bReportGPIO2			= ENABLED ,

		/*! Report GPIO  3 Interrupt */
		.bReportGPIO3			= ENABLED ,

		/*! Report GPIO  4 Interrupt */
		.bReportGPIO4			= ENABLED ,

		/*! Report GPIO  5 Interrupt */
		.bReportGPIO5			= ENABLED ,

		/*! Report GPIO  6 Interrupt */
		.bReportGPIO6			= ENABLED ,

		/*! Report GPIO  7 Interrupt */
		.bReportGPIO7			= DISABLED ,

	},

	.sGPIODSettings =
	{
		.sGPIOD0Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD1Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD2Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD3Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD4Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD5Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD6Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD7Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
	},

	.sClkOutSettings =
	{
		/*! Enable Clock1 inversion */
		.bClk1Inv			= DISABLED ,

		/*! Clk1 pre-division */
		.bClk1PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk1 division */
		.bClk1Div			= A2B_CLKOUT_DIV_4,

		/*! Enable Clock2 inversion */
		.bClk2Inv			= DISABLED ,

		/*! Clk2 pre-division */
		.bClk2PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk2 division */
		.bClk2Div			= A2B_CLKOUT_DIV_4,

	},
	.sRegSettings =
	{
		/*! Switch control register */
		.nSWCTL		= 0x1u ,

		/*! Test mode register */
		.nTESTMODE	= 0x0u ,

		/*! Error control register */
		.nBECCTL	= 0xEFu ,

		/*! Error management register  */
		.nERRMGMT	= 0x0u ,

		/*! I2S test register  */
		.nI2STEST	= 0x0u ,

		/*! Generate error  */
		.nGENERR	= 0x0u ,

		/*! Raise interrupt register */
		.nRAISE		= 0x0u ,

		/*! Bus monitor configuration */
		.nBMMCFG		= 0x0u ,

		/*! Clock sustain configuration   */
		.nSUSCFG	= 0x0u ,

		/*!  Mailbox 0 control */
		.nMBOX0CTL		= 0x0u ,

		/*!  Mailbox 1 control */
		.nMBOX1CTL		= 0x0u ,

	},

		 /* Number of peripheral devices connected  */
		.nNumPeriDevice = 1,

		 /*Array of peripheral configuration pointers */
		.apPeriConfig = { 	 &sChain0_Slave1_PeriConfig0, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR	}

};

/************************************************* END OF SLAVE NODE 1 DESCRIPTION ********************************************************************************/

/************************************************* START OF SLAVE NODE 2 DESCRIPTION ********************************************************************************/

/* SLAVE NODE DESCRIPTION */ 

ADI_A2B_MEM_BCF_DATA
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode2=
{
	/* Node ID  */
	.nNodeID			= 0x2u ,

	/* Source node ID  */
	.nSrcNodeID			= 0x1u ,

	/*! Transceiver part number */
	.ePartNum			= ADI_A2B_AD2425 ,

	/* Auto-configure Node Enabled */
	.bEnableAutoConfig			= DISABLED ,

	.sAuthSettings =
	{
		/*! Vendor ID - ADI */
		.nVendorID			= 0xADu ,

		/*! Silicon version  */
		.nVersionID			= 0x2u ,

		/*! PRODUCT ID -AD2410 */
		.nProductID			= 0x25u ,

		/*! Expected capablity - I2C */
		.nCapability		= 0x1u ,
	},

	.sCustomNodeAuthSettings =
	{
		/*! Enable/Disable Custom Node ID settings */
		.bCustomNodeIdAuth		= DISABLED ,

	},

	.sI2SSettings =
	{
		/*! TDM mode  */
		.nTDMMode		= A2B_TDM4 ,

		/*! TDM channel size  */
		.nTDMChSize			= A2B_16BIT_TDM ,

		/*! SYNC mode - Pulse/50% duty cycle   */
		.nSyncMode			= A2B_ALTERNATE_SYNC ,

		/*! SYNC Polarity- Rising/Falling edge */
		.nSyncPolarity		= RAISING_EDGE ,

		/*! Early frame sync status */
		.bEarlySync			= ENABLED ,

		/*! SYNC offset with Super frame */
		.nSyncOffset		= 0x0 ,

		/*! DTXn change BCLK edge */
		.nBclkTxPolarity	= FALLING_EDGE ,

		/*! DRXn sampling BCLK edge */
		.nBclkRxPolarity	= FALLING_EDGE ,

		/*! Interleave slots between Tx pins  */
		.bTXInterleave		= DISABLED ,

		/*! Interleave slots between Rx pins  */
		.bRXInterleave		= DISABLED ,

		.sI2SRateConfig =
		{
			/* Sample rate */
			.nSamplingRate		= A2B_SAMPLERATE_24kHz ,

			/*! Reduce / re-transmit higher frequency samples  */
		.bReduce			= DISABLED ,

			/*! Share A2B bus slots for reduced sampling */
			.bShareBusSlot	= DISABLED ,

			/*! Enable Valid RR bit in Extra bit */
			.bRRValidBitLSB 	= DISABLED ,

			/*! Enable Valid RR bit in Extra Channel */
			.bRRValidBitExtraBit	= DISABLED ,

			/*! Enable Reduced rate strobe in ADR1/IO1 */
			.bRRStrobe	= DISABLED ,

			/*! Strobe direction High or Low */
			.bRRStrobeDirection	= A2B_LOW ,

		},
	},

	.sPDMSettings =
	{
		/*! Number of PDM0 slots  */
		.nNumSlotsPDM0		= A2B_PDM0SLOTS_1 ,

		/*! Number of PDM1 slots  */
		.nNumSlotsPDM1		= A2B_PDM1SLOTS_2 ,

		/*! Use High Pass Filter  */
		.bHPFUse		= ENABLED ,

		/*! PDM rate  */
		.nPDMRate		= A2B_PDM_RATE_SFF ,

	},

	.sConfigCtrlSettings =
	{
		/*! I2C interface frequency */
		.nI2CFrequency		= A2B_I2C_100kHz ,

		/*! Response cycles  */
		.nRespCycle			= 0x4Fu ,

		/*! Expected super/audio frame rate */
		.nSuperFrameRate	= A2B_SFF_RATE_48_0kHz ,

		/*! Number of broadcast slots */
		.nBroadCastSlots	= 0x0u ,

		/*! Local down slots */
		.nLocalDwnSlotsConsume		= 0x0u ,

		/*! Local Up slots */
		.nLocalUpSlotsContribute		= 0x3u ,

		/*! Pass up slots */
		.nPassUpSlots		= 0xBu ,

		/*! Pass down slots */
		.nPassDwnSlots		= 0x0u ,

		/*! Number of slots for contribution */
		.nSlotsforDwnstrmContribute		= 0x0u ,

		/*! Number of Upslots consumed */
		.nLocalUpSlotsConsume		= 0x3u ,

		/*! Array of downstream  masks */
		.anUpstreamConsumeSlots = { SLOT_0_ENABLED, SLOT_1_ENABLED, SLOT_2_ENABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED,
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for downstream contribution */
		.nOffsetDwnstrmContribute		= 0x0u ,

		/*! Enable Down slot consume through mask */
		.bUseDwnslotConsumeMasks		= ENABLED ,

		/*! Array of downstream  masks */
		.anDwnstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED,
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for Upstream contribution*/
		.nOffsetUpstrmContribute		= 0x0u ,

	},
	.sGPIOSettings =
	{
		.sPinMuxSettings =
		{
			/*! GPIO 0 Pin multiplexing */
			.bGPIO0PinUsage	= A2B_GPIO_0_DISABLE ,

			/*! GPIO 1 Pin multiplexing */
			.bGPIO1PinUsage	= A2B_GPIO_1_AS_CLKOUT ,

			/*! GPIO 2 Pin multiplexing */
			.bGPIO2PinUsage	= A2B_GPIO_2_DISABLE ,

			/*! GPIO 3 Pin multiplexing */
			.bGPIO3PinUsage	= A2B_GPIO_3_DISABLE ,

			/*! GPIO 4 Pin multiplexing */
			.bGPIO4PinUsage	= A2B_GPIO_4_OUTPUT ,

			/*! GPIO 5 Pin multiplexing */
			.bGPIO5PinUsage	= A2B_GPIO_5_AS_DRX0 ,

			/*! GPIO 6 Pin multiplexing */
			.bGPIO6PinUsage	= A2B_GPIO_6_DISABLE ,

			/*! GPIO 7 Pin multiplexing */
			.bGPIO7PinUsage	= A2B_GPIO_7_DISABLE ,
		},
		.sPinIntConfig =
		{
			/*! Enable GPIO 0 Input pin interrupt  */
			.bGPIO0Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 0 Input pin  */
			.bGPIO0IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 1 Input pin interrupt  */
			.bGPIO1Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 1 Input pin  */
			.bGPIO1IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 2 Input pin interrupt  */
			.bGPIO2Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 2 Input pin  */
			.bGPIO2IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 3 Input pin interrupt  */
			.bGPIO3Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 3 Input pin  */
			.bGPIO3IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 4 Input pin interrupt  */
			.bGPIO4Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 4 Input pin  */
			.bGPIO4IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 5 Input pin interrupt  */
			.bGPIO5Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 5 Input pin  */
			.bGPIO5IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 6 Input pin interrupt  */
			.bGPIO6Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 6 Input pin  */
			.bGPIO6IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 7 Input pin interrupt  */
			.bGPIO7Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 7 Input pin  */
			.bGPIO7IntPolarity	= RAISING_EDGE ,

		},
		.sOutPinVal =
		{
			/*! Data value for GPIO 0 output pin  */
			.bGPIO0Val = A2B_LOW ,

			/*! Data value for GPIO 1 output pin  */
			.bGPIO1Val = A2B_LOW ,

			/*! Data value for GPIO 2 output pin  */
			.bGPIO2Val = A2B_LOW ,

			/*! Data value for GPIO 3 output pin  */
			.bGPIO3Val = A2B_LOW ,

			/*! Data value for GPIO 4 output pin  */
			.bGPIO4Val = A2B_HIGH ,

			/*! Data value for GPIO 5 output pin  */
			.bGPIO5Val = A2B_LOW ,

			/*! Data value for GPIO 6 output pin  */
			.bGPIO6Val = A2B_LOW ,

			/*! Data value for GPIO 7 output pin  */
			.bGPIO7Val = A2B_LOW ,

		},

		/*! Digital Pin drive strength */
		.bHighDriveStrength = DISABLED ,

		/*! IRQ Pin Invert */
		.bIRQInv = DISABLED ,

		/*! Enable tristate when inactive */
		.bIRQTriState = DISABLED ,

	},

	.sInterruptSettings =
	{
		/*! Report Header count error  */
		.bReportHDCNTErr		= ENABLED ,

		/*! Report Data decoding error  */
		.bReportDDErr			= ENABLED ,

		/*! Report Data CRC error  */
		.bReportCRCErr			= ENABLED ,

		/*! Report Data Parity error  */
		.bReportDataParityErr	= DISABLED ,

		/*! Report Data Bus Power error  */
		.bReportPwrErr			= ENABLED ,

		/*! Report bit error count overflow error  */
		.bReportErrCntOverFlow	= ENABLED ,

		/*! Report SRF miss error  */
		.bReportSRFMissErr	= ENABLED ,

		/*! Report SRF crc error  */
		.bReportSRFCrcErr		= DISABLED ,

		/*! Report GPIO  0 Interrupt */
		.bReportGPIO0			= ENABLED ,

		/*! Report GPIO  1 Interrupt */
		.bReportGPIO1			= ENABLED ,

		/*! Report GPIO  2 Interrupt */
		.bReportGPIO2			= ENABLED ,

		/*! Report GPIO  3 Interrupt */
		.bReportGPIO3			= ENABLED ,

		/*! Report GPIO  4 Interrupt */
		.bReportGPIO4			= ENABLED ,

		/*! Report GPIO  5 Interrupt */
		.bReportGPIO5			= ENABLED ,

		/*! Report GPIO  6 Interrupt */
		.bReportGPIO6			= ENABLED ,

		/*! Report GPIO  7 Interrupt */
		.bReportGPIO7			= DISABLED ,

	},

	.sGPIODSettings =
	{
		.sGPIOD0Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD1Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD2Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD3Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD4Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD5Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD6Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD7Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
	},

	.sClkOutSettings =
	{
		/*! Enable Clock1 inversion */
		.bClk1Inv			= DISABLED ,

		/*! Clk1 pre-division */
		.bClk1PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk1 division */
		.bClk1Div			= A2B_CLKOUT_DIV_4,

		/*! Enable Clock2 inversion */
		.bClk2Inv			= DISABLED ,

		/*! Clk2 pre-division */
		.bClk2PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk2 division */
		.bClk2Div			= A2B_CLKOUT_DIV_4,

	},
	.sRegSettings =
	{
		/*! Switch control register */
		.nSWCTL		= 0x1u ,

		/*! Test mode register */
		.nTESTMODE	= 0x0u ,

		/*! Error control register */
		.nBECCTL	= 0xEFu ,

		/*! Error management register  */
		.nERRMGMT	= 0x0u ,

		/*! I2S test register  */
		.nI2STEST	= 0x0u ,

		/*! Generate error  */
		.nGENERR	= 0x0u ,

		/*! Raise interrupt register */
		.nRAISE		= 0x0u ,

		/*! Bus monitor configuration */
		.nBMMCFG		= 0x0u ,

		/*! Clock sustain configuration   */
		.nSUSCFG	= 0x0u ,

		/*!  Mailbox 0 control */
		.nMBOX0CTL		= 0x0u ,

		/*!  Mailbox 1 control */
		.nMBOX1CTL		= 0x0u ,

	},

		 /* Number of peripheral devices connected  */
		.nNumPeriDevice = 1,

		 /*Array of peripheral configuration pointers */
		.apPeriConfig = { 	 &sChain0_Slave2_PeriConfig0, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR	}

};

/************************************************* END OF SLAVE NODE 2 DESCRIPTION ********************************************************************************/

/************************************************* START OF SLAVE NODE 3 DESCRIPTION ********************************************************************************/

/* SLAVE NODE DESCRIPTION */

ADI_A2B_MEM_BCF_DATA
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode3=
{
	/* Node ID  */
	.nNodeID			= 0x3u ,

	/* Source node ID  */
	.nSrcNodeID			= 0x2u ,

	/*! Transceiver part number */
	.ePartNum			= ADI_A2B_AD2427 ,

	/* Auto-configure Node Enabled */
	.bEnableAutoConfig			= DISABLED ,

	.sAuthSettings =
	{
		/*! Vendor ID - ADI */
		.nVendorID			= 0xADu ,

		/*! Silicon version  */
		.nVersionID			= 0x0u ,

		/*! PRODUCT ID -AD2410 */
		.nProductID			= 0x27u ,

		/*! Expected capablity - I2C */
		.nCapability		= 0x1u ,
	},

	.sCustomNodeAuthSettings =
	{
		/*! Enable/Disable Custom Node ID settings */
		.bCustomNodeIdAuth		= DISABLED ,

	},

	.sPDMSettings =
	{
		/*! Number of PDM0 slots  */
		.nNumSlotsPDM0		= A2B_PDM0SLOTS_1 ,

		/*! Number of PDM1 slots  */
		.nNumSlotsPDM1		= A2B_PDM1SLOTS_2 ,

		/*! Use High Pass Filter  */
		.bHPFUse		= ENABLED ,

		/*! PDM rate  */
		.nPDMRate		= A2B_PDM_RATE_SFF ,

		/*! PDM Inverted Version of Alternate Clock */
		.bPDMInvClk		= DISABLED ,

		/*! PDM Alternate Clock */
		.bPDMAltClk		= DISABLED ,

		/*! PDM0 Falling Edge First */
		.bPDM0FallingEdgeFrst		= DISABLED ,

		/*! PDM1 Falling Edge First */
		.bPDM1FallingEdgeFrst		= DISABLED ,

		/*! PDM Destination */
		.ePDMDestination		= A2B_BUS_ONLY ,

	},

	.sConfigCtrlSettings =
	{
		/*! I2C interface frequency */
		.nI2CFrequency		= A2B_I2C_400kHz ,

		/*! Response cycles  */
		.nRespCycle			= 0x4Bu ,

		/*! Expected super/audio frame rate */
		.nSuperFrameRate	= A2B_SFF_RATE_48_0kHz ,

		/*! Number of broadcast slots */
		.nBroadCastSlots	= 0x0u ,

		/*! Local down slots */
		.nLocalDwnSlotsConsume		= 0x0u ,

		/*! Local Up slots */
		.nLocalUpSlotsContribute		= 0x1u ,

		/*! Pass up slots */
		.nPassUpSlots		= 0xAu ,

		/*! Pass down slots */
		.nPassDwnSlots		= 0x0u ,

		/*! Number of slots for contribution */
		.nSlotsforDwnstrmContribute		= 0x0u ,

		/*! Number of Upslots consumed */
		.nLocalUpSlotsConsume		= 0x0u ,

		/*! Array of downstream  masks */ 
		.anUpstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED, 
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED, 
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for downstream contribution */
		.nOffsetDwnstrmContribute		= 0x0u ,

		/*! Enable Down slot consume through mask */
		.bUseDwnslotConsumeMasks		= ENABLED ,

		/*! Array of downstream  masks */ 
		.anDwnstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED, 
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED, 
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for Upstream contribution*/
		.nOffsetUpstrmContribute		= 0x0u ,

	},
	.sGPIOSettings =
	{
		.sPinMuxSettings =
		{
			/*! GPIO 0 Pin multiplexing */
			.bGPIO0PinUsage	= A2B_GPIO_0_DISABLE ,

			/*! GPIO 1 Pin multiplexing */
			.bGPIO1PinUsage	= A2B_GPIO_1_DISABLE ,

			/*! GPIO 2 Pin multiplexing */
			.bGPIO2PinUsage	= A2B_GPIO_2_AS_CLKOUT ,

			/*! GPIO 3 Pin multiplexing */
			.bGPIO3PinUsage	= A2B_GPIO_3_DISABLE ,

			/*! GPIO 4 Pin multiplexing */
			.bGPIO4PinUsage	= A2B_GPIO_4_OUTPUT ,

			/*! GPIO 5 Pin multiplexing */
			.bGPIO5PinUsage	= A2B_GPIO_5_AS_PDM0 ,

			/*! GPIO 6 Pin multiplexing */
			.bGPIO6PinUsage	= A2B_GPIO_6_DISABLE ,

			/*! GPIO 7 Pin multiplexing */
			.bGPIO7PinUsage	= A2B_GPIO_7_DISABLE ,
		},
		.sPinIntConfig =
		{
			/*! Enable GPIO 0 Input pin interrupt  */
			.bGPIO0Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 0 Input pin  */
			.bGPIO0IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 1 Input pin interrupt  */
			.bGPIO1Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 1 Input pin  */
			.bGPIO1IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 2 Input pin interrupt  */
			.bGPIO2Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 2 Input pin  */
			.bGPIO2IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 3 Input pin interrupt  */
			.bGPIO3Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 3 Input pin  */
			.bGPIO3IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 4 Input pin interrupt  */
			.bGPIO4Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 4 Input pin  */
			.bGPIO4IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 5 Input pin interrupt  */
			.bGPIO5Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 5 Input pin  */
			.bGPIO5IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 6 Input pin interrupt  */
			.bGPIO6Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 6 Input pin  */
			.bGPIO6IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 7 Input pin interrupt  */
			.bGPIO7Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 7 Input pin  */
			.bGPIO7IntPolarity	= RAISING_EDGE ,

		},
		.sOutPinVal =
		{
			/*! Data value for GPIO 0 output pin  */
			.bGPIO0Val = A2B_LOW ,

			/*! Data value for GPIO 1 output pin  */
			.bGPIO1Val = A2B_LOW ,

			/*! Data value for GPIO 2 output pin  */
			.bGPIO2Val = A2B_LOW ,

			/*! Data value for GPIO 3 output pin  */
			.bGPIO3Val = A2B_LOW ,

			/*! Data value for GPIO 4 output pin  */
			.bGPIO4Val = A2B_HIGH ,

			/*! Data value for GPIO 5 output pin  */
			.bGPIO5Val = A2B_LOW ,

			/*! Data value for GPIO 6 output pin  */
			.bGPIO6Val = A2B_LOW ,

			/*! Data value for GPIO 7 output pin  */
			.bGPIO7Val = A2B_LOW ,

		},

		/*! Digital Pin drive strength */
		.bHighDriveStrength = DISABLED ,

		/*! IRQ Pin Invert */
		.bIRQInv = DISABLED ,

		/*! Enable tristate when inactive */
		.bIRQTriState = DISABLED ,

	},

	.sInterruptSettings =
	{
		/*! Report Header count error  */
		.bReportHDCNTErr		= ENABLED ,

		/*! Report Data decoding error  */
		.bReportDDErr			= ENABLED ,

		/*! Report Data CRC error  */
		.bReportCRCErr			= ENABLED ,

		/*! Report Data Parity error  */
		.bReportDataParityErr	= DISABLED ,

		/*! Report Data Bus Power error  */
		.bReportPwrErr			= ENABLED ,

		/*! Report bit error count overflow error  */
		.bReportErrCntOverFlow	= ENABLED ,

		/*! Report SRF miss error  */
		.bReportSRFMissErr	= ENABLED ,

		/*! Report SRF crc error  */
		.bReportSRFCrcErr		= DISABLED ,

		/*! Report GPIO  0 Interrupt */
		.bReportGPIO0			= ENABLED ,

		/*! Report GPIO  1 Interrupt */
		.bReportGPIO1			= ENABLED ,

		/*! Report GPIO  2 Interrupt */
		.bReportGPIO2			= ENABLED ,

		/*! Report GPIO  3 Interrupt */
		.bReportGPIO3			= ENABLED ,

		/*! Report GPIO  4 Interrupt */
		.bReportGPIO4			= ENABLED ,

		/*! Report GPIO  5 Interrupt */
		.bReportGPIO5			= ENABLED ,

		/*! Report GPIO  6 Interrupt */
		.bReportGPIO6			= ENABLED ,

		/*! Report GPIO  7 Interrupt */
		.bReportGPIO7			= DISABLED ,

	},

	.sGPIODSettings =
	{
		.sGPIOD0Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD1Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD2Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD3Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD4Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD5Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD6Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD7Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
	},

	.sClkOutSettings =
	{
		/*! Enable Clock1 inversion */
		.bClk1Inv			= DISABLED ,

		/*! Clk1 pre-division */
		.bClk1PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk1 division */
		.bClk1Div			= A2B_CLKOUT_DIV_4,

		/*! Enable Clock2 inversion */
		.bClk2Inv			= DISABLED ,

		/*! Clk2 pre-division */
		.bClk2PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk2 division */
		.bClk2Div			= A2B_CLKOUT_DIV_4,

	},
	.sRegSettings =
	{
		/*! Switch control register */
		.nSWCTL		= 0x1u ,

		/*! Test mode register */
		.nTESTMODE	= 0x0u ,

		/*! Error control register */
		.nBECCTL	= 0xEFu ,

		/*! Error management register  */
		.nERRMGMT	= 0x0u ,

		/*! Generate error  */
		.nGENERR	= 0x0u ,

		/*! Raise interrupt register */
		.nRAISE		= 0x0u ,

		/*! Bus monitor configuration */
		.nBMMCFG		= 0x0u ,

		/*! Clock sustain configuration   */
		.nSUSCFG	= 0x0u ,

		/*!  Mailbox 0 control */
		.nMBOX0CTL		= 0x0u ,

		/*!  Mailbox 1 control */
		.nMBOX1CTL		= 0x0u ,

		/*! PLL Control register  */
		.nPLLCTL	= 0x0u ,

		/*! LVDSA TX Control Register */
		.nTXACTL	= 0x0u ,

		/*! LVDSB TX Control Register */
		.nTXBCTL	= 0x0u ,

		/*! Control Register */
		.nCONTROL	= 0x0u ,

	},

		 /* Number of peripheral devices connected  */
		.nNumPeriDevice = 1,

		 /*Array of peripheral configuration pointers */
		.apPeriConfig = { 	 &sChain0_Slave3_PeriConfig0, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR	}

};

/************************************************* END OF SLAVE NODE 3 DESCRIPTION ********************************************************************************/

/************************************************* START OF SLAVE NODE 4 DESCRIPTION ********************************************************************************/

/* SLAVE NODE DESCRIPTION */

ADI_A2B_MEM_BCF_DATA
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode4=
{
	/* Node ID  */
	.nNodeID			= 0x4u ,

	/* Source node ID  */
	.nSrcNodeID			= 0x3u ,

	/*! Transceiver part number */
	.ePartNum			= ADI_A2B_AD2427 ,

	/* Auto-configure Node Enabled */
	.bEnableAutoConfig			= DISABLED ,

	.sAuthSettings =
	{
		/*! Vendor ID - ADI */
		.nVendorID			= 0xADu ,

		/*! Silicon version  */
		.nVersionID			= 0x0u ,

		/*! PRODUCT ID -AD2410 */
		.nProductID			= 0x27u ,

		/*! Expected capablity - I2C */
		.nCapability		= 0x1u ,
	},

	.sCustomNodeAuthSettings =
	{
		/*! Enable/Disable Custom Node ID settings */
		.bCustomNodeIdAuth		= DISABLED ,

	},

	.sPDMSettings =
	{
		/*! Number of PDM0 slots  */
		.nNumSlotsPDM0		= A2B_PDM0SLOTS_1 ,

		/*! Number of PDM1 slots  */
		.nNumSlotsPDM1		= A2B_PDM1SLOTS_2 ,

		/*! Use High Pass Filter  */
		.bHPFUse		= ENABLED ,

		/*! PDM rate  */
		.nPDMRate		= A2B_PDM_RATE_SFF ,

		/*! PDM Inverted Version of Alternate Clock */
		.bPDMInvClk		= DISABLED ,

		/*! PDM Alternate Clock */
		.bPDMAltClk		= DISABLED ,

		/*! PDM0 Falling Edge First */
		.bPDM0FallingEdgeFrst		= DISABLED ,

		/*! PDM1 Falling Edge First */
		.bPDM1FallingEdgeFrst		= DISABLED ,

		/*! PDM Destination */
		.ePDMDestination		= A2B_BUS_ONLY ,

	},

	.sConfigCtrlSettings =
	{
		/*! I2C interface frequency */
		.nI2CFrequency		= A2B_I2C_400kHz ,

		/*! Response cycles  */
		.nRespCycle			= 0x47u ,

		/*! Expected super/audio frame rate */
		.nSuperFrameRate	= A2B_SFF_RATE_48_0kHz ,

		/*! Number of broadcast slots */
		.nBroadCastSlots	= 0x0u ,

		/*! Local down slots */
		.nLocalDwnSlotsConsume		= 0x0u ,

		/*! Local Up slots */
		.nLocalUpSlotsContribute		= 0x1u ,

		/*! Pass up slots */
		.nPassUpSlots		= 0x9u ,

		/*! Pass down slots */
		.nPassDwnSlots		= 0x0u ,

		/*! Number of slots for contribution */
		.nSlotsforDwnstrmContribute		= 0x0u ,

		/*! Number of Upslots consumed */
		.nLocalUpSlotsConsume		= 0x0u ,

		/*! Array of downstream  masks */
		.anUpstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED,
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for downstream contribution */
		.nOffsetDwnstrmContribute		= 0x0u ,

		/*! Enable Down slot consume through mask */
		.bUseDwnslotConsumeMasks		= ENABLED ,

		/*! Array of downstream  masks */
		.anDwnstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED,
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for Upstream contribution*/
		.nOffsetUpstrmContribute		= 0x0u ,

	},
	.sGPIOSettings =
	{
		.sPinMuxSettings =
		{
			/*! GPIO 0 Pin multiplexing */
			.bGPIO0PinUsage	= A2B_GPIO_0_DISABLE ,

			/*! GPIO 1 Pin multiplexing */
			.bGPIO1PinUsage	= A2B_GPIO_1_DISABLE ,

			/*! GPIO 2 Pin multiplexing */
			.bGPIO2PinUsage	= A2B_GPIO_2_AS_CLKOUT ,

			/*! GPIO 3 Pin multiplexing */
			.bGPIO3PinUsage	= A2B_GPIO_3_DISABLE ,

			/*! GPIO 4 Pin multiplexing */
			.bGPIO4PinUsage	= A2B_GPIO_4_OUTPUT ,

			/*! GPIO 5 Pin multiplexing */
			.bGPIO5PinUsage	= A2B_GPIO_5_AS_PDM0 ,

			/*! GPIO 6 Pin multiplexing */
			.bGPIO6PinUsage	= A2B_GPIO_6_DISABLE ,

			/*! GPIO 7 Pin multiplexing */
			.bGPIO7PinUsage	= A2B_GPIO_7_DISABLE ,
		},
		.sPinIntConfig =
		{
			/*! Enable GPIO 0 Input pin interrupt  */
			.bGPIO0Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 0 Input pin  */
			.bGPIO0IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 1 Input pin interrupt  */
			.bGPIO1Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 1 Input pin  */
			.bGPIO1IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 2 Input pin interrupt  */
			.bGPIO2Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 2 Input pin  */
			.bGPIO2IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 3 Input pin interrupt  */
			.bGPIO3Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 3 Input pin  */
			.bGPIO3IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 4 Input pin interrupt  */
			.bGPIO4Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 4 Input pin  */
			.bGPIO4IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 5 Input pin interrupt  */
			.bGPIO5Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 5 Input pin  */
			.bGPIO5IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 6 Input pin interrupt  */
			.bGPIO6Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 6 Input pin  */
			.bGPIO6IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 7 Input pin interrupt  */
			.bGPIO7Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 7 Input pin  */
			.bGPIO7IntPolarity	= RAISING_EDGE ,

		},
		.sOutPinVal =
		{
			/*! Data value for GPIO 0 output pin  */
			.bGPIO0Val = A2B_LOW ,

			/*! Data value for GPIO 1 output pin  */
			.bGPIO1Val = A2B_LOW ,

			/*! Data value for GPIO 2 output pin  */
			.bGPIO2Val = A2B_LOW ,

			/*! Data value for GPIO 3 output pin  */
			.bGPIO3Val = A2B_LOW ,

			/*! Data value for GPIO 4 output pin  */
			.bGPIO4Val = A2B_HIGH ,

			/*! Data value for GPIO 5 output pin  */
			.bGPIO5Val = A2B_LOW ,

			/*! Data value for GPIO 6 output pin  */
			.bGPIO6Val = A2B_LOW ,

			/*! Data value for GPIO 7 output pin  */
			.bGPIO7Val = A2B_LOW ,

		},

		/*! Digital Pin drive strength */
		.bHighDriveStrength = DISABLED ,

		/*! IRQ Pin Invert */
		.bIRQInv = DISABLED ,

		/*! Enable tristate when inactive */
		.bIRQTriState = DISABLED ,

	},

	.sInterruptSettings =
	{
		/*! Report Header count error  */
		.bReportHDCNTErr		= ENABLED ,

		/*! Report Data decoding error  */
		.bReportDDErr			= ENABLED ,

		/*! Report Data CRC error  */
		.bReportCRCErr			= ENABLED ,

		/*! Report Data Parity error  */
		.bReportDataParityErr	= DISABLED ,

		/*! Report Data Bus Power error  */
		.bReportPwrErr			= ENABLED ,

		/*! Report bit error count overflow error  */
		.bReportErrCntOverFlow	= ENABLED ,

		/*! Report SRF miss error  */
		.bReportSRFMissErr	= ENABLED ,

		/*! Report SRF crc error  */
		.bReportSRFCrcErr		= DISABLED ,

		/*! Report GPIO  0 Interrupt */
		.bReportGPIO0			= ENABLED ,

		/*! Report GPIO  1 Interrupt */
		.bReportGPIO1			= ENABLED ,

		/*! Report GPIO  2 Interrupt */
		.bReportGPIO2			= ENABLED ,

		/*! Report GPIO  3 Interrupt */
		.bReportGPIO3			= ENABLED ,

		/*! Report GPIO  4 Interrupt */
		.bReportGPIO4			= ENABLED ,

		/*! Report GPIO  5 Interrupt */
		.bReportGPIO5			= ENABLED ,

		/*! Report GPIO  6 Interrupt */
		.bReportGPIO6			= ENABLED ,

		/*! Report GPIO  7 Interrupt */
		.bReportGPIO7			= DISABLED ,

	},

	.sGPIODSettings =
	{
		.sGPIOD0Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD1Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD2Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD3Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD4Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD5Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD6Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD7Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
	},

	.sClkOutSettings =
	{
		/*! Enable Clock1 inversion */
		.bClk1Inv			= DISABLED ,

		/*! Clk1 pre-division */
		.bClk1PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk1 division */
		.bClk1Div			= A2B_CLKOUT_DIV_4,

		/*! Enable Clock2 inversion */
		.bClk2Inv			= DISABLED ,

		/*! Clk2 pre-division */
		.bClk2PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk2 division */
		.bClk2Div			= A2B_CLKOUT_DIV_4,

	},
	.sRegSettings =
	{
		/*! Switch control register */
		.nSWCTL		= 0x1u ,

		/*! Test mode register */
		.nTESTMODE	= 0x0u ,

		/*! Error control register */
		.nBECCTL	= 0xEFu ,

		/*! Error management register  */
		.nERRMGMT	= 0x0u ,

		/*! Generate error  */
		.nGENERR	= 0x0u ,

		/*! Raise interrupt register */
		.nRAISE		= 0x0u ,

		/*! Bus monitor configuration */
		.nBMMCFG		= 0x0u ,

		/*! Clock sustain configuration   */
		.nSUSCFG	= 0x0u ,

		/*!  Mailbox 0 control */
		.nMBOX0CTL		= 0x0u ,

		/*!  Mailbox 1 control */
		.nMBOX1CTL		= 0x0u ,

		/*! PLL Control register  */
		.nPLLCTL	= 0x0u ,

		/*! LVDSA TX Control Register */
		.nTXACTL	= 0x0u ,

		/*! LVDSB TX Control Register */
		.nTXBCTL	= 0x0u ,

		/*! Control Register */
		.nCONTROL	= 0x0u ,

	},

		 /* Number of peripheral devices connected  */
		.nNumPeriDevice = 1,

		 /*Array of peripheral configuration pointers */ 
		.apPeriConfig = { 	 &sChain0_Slave4_PeriConfig0, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR	}

};

/************************************************* END OF SLAVE NODE 4 DESCRIPTION ********************************************************************************/
 
/************************************************* START OF SLAVE NODE 5 DESCRIPTION ********************************************************************************/

/* SLAVE NODE DESCRIPTION */ 

ADI_A2B_MEM_BCF_DATA
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode5=
{
	/* Node ID  */
	.nNodeID			= 0x5u ,

	/* Source node ID  */
	.nSrcNodeID			= 0x4u ,

	/*! Transceiver part number */
	.ePartNum			= ADI_A2B_AD2427 ,

	/* Auto-configure Node Enabled */
	.bEnableAutoConfig			= DISABLED ,

	.sAuthSettings =
	{
		/*! Vendor ID - ADI */
		.nVendorID			= 0xADu ,

		/*! Silicon version  */
		.nVersionID			= 0x0u ,

		/*! PRODUCT ID -AD2410 */
		.nProductID			= 0x27u ,

		/*! Expected capablity - I2C */
		.nCapability		= 0x1u ,
	},

	.sCustomNodeAuthSettings =
	{
		/*! Enable/Disable Custom Node ID settings */
		.bCustomNodeIdAuth		= DISABLED ,

	},

	.sPDMSettings =
	{
		/*! Number of PDM0 slots  */
		.nNumSlotsPDM0		= A2B_PDM0SLOTS_1 ,

		/*! Number of PDM1 slots  */
		.nNumSlotsPDM1		= A2B_PDM1SLOTS_2 ,

		/*! Use High Pass Filter  */
		.bHPFUse		= ENABLED ,

		/*! PDM rate  */
		.nPDMRate		= A2B_PDM_RATE_SFF ,

		/*! PDM Inverted Version of Alternate Clock */
		.bPDMInvClk		= DISABLED ,

		/*! PDM Alternate Clock */
		.bPDMAltClk		= DISABLED ,

		/*! PDM0 Falling Edge First */
		.bPDM0FallingEdgeFrst		= DISABLED ,

		/*! PDM1 Falling Edge First */
		.bPDM1FallingEdgeFrst		= DISABLED ,

		/*! PDM Destination */
		.ePDMDestination		= A2B_BUS_ONLY ,

	},

	.sConfigCtrlSettings =
	{
		/*! I2C interface frequency */
		.nI2CFrequency		= A2B_I2C_400kHz ,

		/*! Response cycles  */
		.nRespCycle			= 0x43u ,

		/*! Expected super/audio frame rate */
		.nSuperFrameRate	= A2B_SFF_RATE_48_0kHz ,

		/*! Number of broadcast slots */
		.nBroadCastSlots	= 0x0u ,

		/*! Local down slots */
		.nLocalDwnSlotsConsume		= 0x0u ,

		/*! Local Up slots */
		.nLocalUpSlotsContribute		= 0x1u ,

		/*! Pass up slots */
		.nPassUpSlots		= 0x8u ,

		/*! Pass down slots */
		.nPassDwnSlots		= 0x0u ,

		/*! Number of slots for contribution */
		.nSlotsforDwnstrmContribute		= 0x0u ,

		/*! Number of Upslots consumed */
		.nLocalUpSlotsConsume		= 0x0u ,

		/*! Array of downstream  masks */
		.anUpstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED,
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for downstream contribution */
		.nOffsetDwnstrmContribute		= 0x0u ,

		/*! Enable Down slot consume through mask */
		.bUseDwnslotConsumeMasks		= ENABLED ,

		/*! Array of downstream  masks */
		.anDwnstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED,
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for Upstream contribution*/
		.nOffsetUpstrmContribute		= 0x0u ,

	},
	.sGPIOSettings =
	{
		.sPinMuxSettings =
		{
			/*! GPIO 0 Pin multiplexing */
			.bGPIO0PinUsage	= A2B_GPIO_0_DISABLE ,

			/*! GPIO 1 Pin multiplexing */
			.bGPIO1PinUsage	= A2B_GPIO_1_DISABLE ,

			/*! GPIO 2 Pin multiplexing */
			.bGPIO2PinUsage	= A2B_GPIO_2_AS_CLKOUT ,

			/*! GPIO 3 Pin multiplexing */
			.bGPIO3PinUsage	= A2B_GPIO_3_DISABLE ,

			/*! GPIO 4 Pin multiplexing */
			.bGPIO4PinUsage	= A2B_GPIO_4_OUTPUT ,

			/*! GPIO 5 Pin multiplexing */
			.bGPIO5PinUsage	= A2B_GPIO_5_AS_PDM0 ,

			/*! GPIO 6 Pin multiplexing */
			.bGPIO6PinUsage	= A2B_GPIO_6_DISABLE ,

			/*! GPIO 7 Pin multiplexing */
			.bGPIO7PinUsage	= A2B_GPIO_7_DISABLE ,
		},
		.sPinIntConfig =
		{
			/*! Enable GPIO 0 Input pin interrupt  */
			.bGPIO0Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 0 Input pin  */
			.bGPIO0IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 1 Input pin interrupt  */
			.bGPIO1Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 1 Input pin  */
			.bGPIO1IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 2 Input pin interrupt  */
			.bGPIO2Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 2 Input pin  */
			.bGPIO2IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 3 Input pin interrupt  */
			.bGPIO3Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 3 Input pin  */
			.bGPIO3IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 4 Input pin interrupt  */
			.bGPIO4Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 4 Input pin  */
			.bGPIO4IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 5 Input pin interrupt  */
			.bGPIO5Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 5 Input pin  */
			.bGPIO5IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 6 Input pin interrupt  */
			.bGPIO6Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 6 Input pin  */
			.bGPIO6IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 7 Input pin interrupt  */
			.bGPIO7Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 7 Input pin  */
			.bGPIO7IntPolarity	= RAISING_EDGE ,

		},
		.sOutPinVal =
		{
			/*! Data value for GPIO 0 output pin  */
			.bGPIO0Val = A2B_LOW ,

			/*! Data value for GPIO 1 output pin  */
			.bGPIO1Val = A2B_LOW ,

			/*! Data value for GPIO 2 output pin  */
			.bGPIO2Val = A2B_LOW ,

			/*! Data value for GPIO 3 output pin  */
			.bGPIO3Val = A2B_LOW ,

			/*! Data value for GPIO 4 output pin  */
			.bGPIO4Val = A2B_HIGH ,

			/*! Data value for GPIO 5 output pin  */
			.bGPIO5Val = A2B_LOW ,

			/*! Data value for GPIO 6 output pin  */
			.bGPIO6Val = A2B_LOW ,

			/*! Data value for GPIO 7 output pin  */
			.bGPIO7Val = A2B_LOW ,

		},

		/*! Digital Pin drive strength */
		.bHighDriveStrength = DISABLED ,

		/*! IRQ Pin Invert */
		.bIRQInv = DISABLED ,

		/*! Enable tristate when inactive */
		.bIRQTriState = DISABLED ,

	},

	.sInterruptSettings =
	{
		/*! Report Header count error  */
		.bReportHDCNTErr		= ENABLED ,

		/*! Report Data decoding error  */
		.bReportDDErr			= ENABLED ,

		/*! Report Data CRC error  */
		.bReportCRCErr			= ENABLED ,

		/*! Report Data Parity error  */
		.bReportDataParityErr	= DISABLED ,

		/*! Report Data Bus Power error  */
		.bReportPwrErr			= ENABLED ,

		/*! Report bit error count overflow error  */
		.bReportErrCntOverFlow	= ENABLED ,

		/*! Report SRF miss error  */
		.bReportSRFMissErr	= ENABLED ,

		/*! Report SRF crc error  */
		.bReportSRFCrcErr		= DISABLED ,

		/*! Report GPIO  0 Interrupt */
		.bReportGPIO0			= ENABLED ,

		/*! Report GPIO  1 Interrupt */
		.bReportGPIO1			= ENABLED ,

		/*! Report GPIO  2 Interrupt */
		.bReportGPIO2			= ENABLED ,

		/*! Report GPIO  3 Interrupt */
		.bReportGPIO3			= ENABLED ,

		/*! Report GPIO  4 Interrupt */
		.bReportGPIO4			= ENABLED ,

		/*! Report GPIO  5 Interrupt */
		.bReportGPIO5			= ENABLED ,

		/*! Report GPIO  6 Interrupt */
		.bReportGPIO6			= ENABLED ,

		/*! Report GPIO  7 Interrupt */
		.bReportGPIO7			= DISABLED ,

	},

	.sGPIODSettings =
	{
		.sGPIOD0Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD1Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD2Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD3Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD4Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD5Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD6Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD7Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
	},

	.sClkOutSettings =
	{
		/*! Enable Clock1 inversion */
		.bClk1Inv			= DISABLED ,

		/*! Clk1 pre-division */
		.bClk1PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk1 division */
		.bClk1Div			= A2B_CLKOUT_DIV_4,

		/*! Enable Clock2 inversion */
		.bClk2Inv			= DISABLED ,

		/*! Clk2 pre-division */
		.bClk2PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk2 division */
		.bClk2Div			= A2B_CLKOUT_DIV_4,

	},
	.sRegSettings =
	{
		/*! Switch control register */
		.nSWCTL		= 0x1u ,

		/*! Test mode register */
		.nTESTMODE	= 0x0u ,

		/*! Error control register */
		.nBECCTL	= 0xEFu ,

		/*! Error management register  */
		.nERRMGMT	= 0x0u ,

		/*! Generate error  */
		.nGENERR	= 0x0u ,

		/*! Raise interrupt register */
		.nRAISE		= 0x0u ,

		/*! Bus monitor configuration */
		.nBMMCFG		= 0x0u ,

		/*! Clock sustain configuration   */
		.nSUSCFG	= 0x0u ,

		/*!  Mailbox 0 control */
		.nMBOX0CTL		= 0x0u ,

		/*!  Mailbox 1 control */
		.nMBOX1CTL		= 0x0u ,

		/*! PLL Control register  */
		.nPLLCTL	= 0x0u ,

		/*! LVDSA TX Control Register */
		.nTXACTL	= 0x0u ,

		/*! LVDSB TX Control Register */
		.nTXBCTL	= 0x0u ,

		/*! Control Register */
		.nCONTROL	= 0x0u ,

	},

		 /* Number of peripheral devices connected  */
		.nNumPeriDevice = 1,

		 /*Array of peripheral configuration pointers */
		.apPeriConfig = { 	 &sChain0_Slave5_PeriConfig0, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR	}

};

/************************************************* END OF SLAVE NODE 5 DESCRIPTION ********************************************************************************/

/************************************************* START OF SLAVE NODE 6 DESCRIPTION ********************************************************************************/

/* SLAVE NODE DESCRIPTION */

ADI_A2B_MEM_BCF_DATA
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode6=
{
	/* Node ID  */
	.nNodeID			= 0x6u ,

	/* Source node ID  */
	.nSrcNodeID			= 0x5u ,

	/*! Transceiver part number */
	.ePartNum			= ADI_A2B_AD2425 ,

	/* Auto-configure Node Enabled */
	.bEnableAutoConfig			= DISABLED ,

	.sAuthSettings =
	{
		/*! Vendor ID - ADI */
		.nVendorID			= 0xADu ,

		/*! Silicon version  */
		.nVersionID			= 0x2u ,

		/*! PRODUCT ID -AD2410 */
		.nProductID			= 0x25u ,

		/*! Expected capablity - I2C */
		.nCapability		= 0x1u ,
	},

	.sCustomNodeAuthSettings =
	{
		/*! Enable/Disable Custom Node ID settings */
		.bCustomNodeIdAuth		= DISABLED ,

	},

	.sI2SSettings =
	{
		/*! TDM mode  */
		.nTDMMode		= A2B_TDM4 ,

		/*! TDM channel size  */
		.nTDMChSize			= A2B_16BIT_TDM ,

		/*! SYNC mode - Pulse/50% duty cycle   */
		.nSyncMode			= A2B_ALTERNATE_SYNC ,

		/*! SYNC Polarity- Rising/Falling edge */
		.nSyncPolarity		= RAISING_EDGE ,

		/*! Early frame sync status */
		.bEarlySync			= ENABLED ,

		/*! SYNC offset with Super frame */
		.nSyncOffset		= 0x0 ,

		/*! DTXn change BCLK edge */
		.nBclkTxPolarity	= FALLING_EDGE ,

		/*! DRXn sampling BCLK edge */
		.nBclkRxPolarity	= FALLING_EDGE ,

		/*! Interleave slots between Tx pins  */
		.bTXInterleave		= DISABLED ,

		/*! Interleave slots between Rx pins  */
		.bRXInterleave		= DISABLED ,

		.sI2SRateConfig =
		{
			/* Sample rate */
			.nSamplingRate		= A2B_SAMPLERATE_24kHz ,

			/*! Reduce / re-transmit higher frequency samples  */
		.bReduce			= DISABLED ,

			/*! Share A2B bus slots for reduced sampling */
			.bShareBusSlot	= DISABLED ,

			/*! Enable Valid RR bit in Extra bit */
			.bRRValidBitLSB 	= DISABLED ,

			/*! Enable Valid RR bit in Extra Channel */
			.bRRValidBitExtraBit	= DISABLED ,

			/*! Enable Reduced rate strobe in ADR1/IO1 */
			.bRRStrobe	= DISABLED ,

			/*! Strobe direction High or Low */
			.bRRStrobeDirection	= A2B_LOW ,

		},
	},

	.sPDMSettings =
	{
		/*! Number of PDM0 slots  */
		.nNumSlotsPDM0		= A2B_PDM0SLOTS_1 ,

		/*! Number of PDM1 slots  */
		.nNumSlotsPDM1		= A2B_PDM1SLOTS_2 ,

		/*! Use High Pass Filter  */
		.bHPFUse		= ENABLED ,

		/*! PDM rate  */
		.nPDMRate		= A2B_PDM_RATE_SFF ,

	},

	.sConfigCtrlSettings =
	{
		/*! I2C interface frequency */
		.nI2CFrequency		= A2B_I2C_100kHz ,

		/*! Response cycles  */
		.nRespCycle			= 0x3Fu ,

		/*! Expected super/audio frame rate */
		.nSuperFrameRate	= A2B_SFF_RATE_48_0kHz ,

		/*! Number of broadcast slots */
		.nBroadCastSlots	= 0x0u ,

		/*! Local down slots */
		.nLocalDwnSlotsConsume		= 0x0u ,

		/*! Local Up slots */
		.nLocalUpSlotsContribute		= 0x3u ,

		/*! Pass up slots */
		.nPassUpSlots		= 0x5u ,

		/*! Pass down slots */
		.nPassDwnSlots		= 0x0u ,

		/*! Number of slots for contribution */
		.nSlotsforDwnstrmContribute		= 0x0u ,

		/*! Number of Upslots consumed */
		.nLocalUpSlotsConsume		= 0x0u ,

		/*! Array of downstream  masks */
		.anUpstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED,
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for downstream contribution */
		.nOffsetDwnstrmContribute		= 0x0u ,

		/*! Enable Down slot consume through mask */
		.bUseDwnslotConsumeMasks		= ENABLED ,

		/*! Array of downstream  masks */
		.anDwnstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED,
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for Upstream contribution*/
		.nOffsetUpstrmContribute		= 0x0u ,

	},
	.sGPIOSettings =
	{
		.sPinMuxSettings =
		{
			/*! GPIO 0 Pin multiplexing */
			.bGPIO0PinUsage	= A2B_GPIO_0_DISABLE ,

			/*! GPIO 1 Pin multiplexing */
			.bGPIO1PinUsage	= A2B_GPIO_1_AS_CLKOUT ,

			/*! GPIO 2 Pin multiplexing */
			.bGPIO2PinUsage	= A2B_GPIO_2_DISABLE ,

			/*! GPIO 3 Pin multiplexing */
			.bGPIO3PinUsage	= A2B_GPIO_3_DISABLE ,

			/*! GPIO 4 Pin multiplexing */
			.bGPIO4PinUsage	= A2B_GPIO_4_OUTPUT ,

			/*! GPIO 5 Pin multiplexing */
			.bGPIO5PinUsage	= A2B_GPIO_5_AS_DRX0 ,

			/*! GPIO 6 Pin multiplexing */
			.bGPIO6PinUsage	= A2B_GPIO_6_DISABLE ,

			/*! GPIO 7 Pin multiplexing */
			.bGPIO7PinUsage	= A2B_GPIO_7_DISABLE ,
		},
		.sPinIntConfig =
		{
			/*! Enable GPIO 0 Input pin interrupt  */
			.bGPIO0Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 0 Input pin  */
			.bGPIO0IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 1 Input pin interrupt  */
			.bGPIO1Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 1 Input pin  */
			.bGPIO1IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 2 Input pin interrupt  */
			.bGPIO2Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 2 Input pin  */
			.bGPIO2IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 3 Input pin interrupt  */
			.bGPIO3Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 3 Input pin  */
			.bGPIO3IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 4 Input pin interrupt  */
			.bGPIO4Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 4 Input pin  */
			.bGPIO4IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 5 Input pin interrupt  */
			.bGPIO5Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 5 Input pin  */
			.bGPIO5IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 6 Input pin interrupt  */
			.bGPIO6Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 6 Input pin  */
			.bGPIO6IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 7 Input pin interrupt  */
			.bGPIO7Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 7 Input pin  */
			.bGPIO7IntPolarity	= RAISING_EDGE ,

		},
		.sOutPinVal =
		{
			/*! Data value for GPIO 0 output pin  */
			.bGPIO0Val = A2B_LOW ,

			/*! Data value for GPIO 1 output pin  */
			.bGPIO1Val = A2B_LOW ,

			/*! Data value for GPIO 2 output pin  */
			.bGPIO2Val = A2B_LOW ,

			/*! Data value for GPIO 3 output pin  */
			.bGPIO3Val = A2B_LOW ,

			/*! Data value for GPIO 4 output pin  */
			.bGPIO4Val = A2B_HIGH ,

			/*! Data value for GPIO 5 output pin  */
			.bGPIO5Val = A2B_LOW ,

			/*! Data value for GPIO 6 output pin  */
			.bGPIO6Val = A2B_LOW ,

			/*! Data value for GPIO 7 output pin  */
			.bGPIO7Val = A2B_LOW ,

		},

		/*! Digital Pin drive strength */
		.bHighDriveStrength = DISABLED ,

		/*! IRQ Pin Invert */
		.bIRQInv = DISABLED ,

		/*! Enable tristate when inactive */
		.bIRQTriState = DISABLED ,

	},

	.sInterruptSettings =
	{
		/*! Report Header count error  */
		.bReportHDCNTErr		= ENABLED ,

		/*! Report Data decoding error  */
		.bReportDDErr			= ENABLED ,

		/*! Report Data CRC error  */
		.bReportCRCErr			= ENABLED ,

		/*! Report Data Parity error  */
		.bReportDataParityErr	= DISABLED ,

		/*! Report Data Bus Power error  */
		.bReportPwrErr			= ENABLED ,

		/*! Report bit error count overflow error  */
		.bReportErrCntOverFlow	= ENABLED ,

		/*! Report SRF miss error  */
		.bReportSRFMissErr	= ENABLED ,

		/*! Report SRF crc error  */
		.bReportSRFCrcErr		= DISABLED ,

		/*! Report GPIO  0 Interrupt */
		.bReportGPIO0			= ENABLED ,

		/*! Report GPIO  1 Interrupt */
		.bReportGPIO1			= ENABLED ,

		/*! Report GPIO  2 Interrupt */
		.bReportGPIO2			= ENABLED ,

		/*! Report GPIO  3 Interrupt */
		.bReportGPIO3			= ENABLED ,

		/*! Report GPIO  4 Interrupt */
		.bReportGPIO4			= ENABLED ,

		/*! Report GPIO  5 Interrupt */
		.bReportGPIO5			= ENABLED ,

		/*! Report GPIO  6 Interrupt */
		.bReportGPIO6			= ENABLED ,

		/*! Report GPIO  7 Interrupt */
		.bReportGPIO7			= DISABLED ,

	},

	.sGPIODSettings =
	{
		.sGPIOD0Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD1Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD2Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD3Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD4Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD5Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD6Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD7Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
	},

	.sClkOutSettings =
	{
		/*! Enable Clock1 inversion */
		.bClk1Inv			= DISABLED ,

		/*! Clk1 pre-division */
		.bClk1PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk1 division */
		.bClk1Div			= A2B_CLKOUT_DIV_4,

		/*! Enable Clock2 inversion */
		.bClk2Inv			= DISABLED ,

		/*! Clk2 pre-division */
		.bClk2PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk2 division */
		.bClk2Div			= A2B_CLKOUT_DIV_4,

	},
	.sRegSettings =
	{
		/*! Switch control register */
		.nSWCTL		= 0x1u ,

		/*! Test mode register */
		.nTESTMODE	= 0x0u ,

		/*! Error control register */
		.nBECCTL	= 0xEFu ,

		/*! Error management register  */
		.nERRMGMT	= 0x0u ,

		/*! I2S test register  */
		.nI2STEST	= 0x0u ,

		/*! Generate error  */
		.nGENERR	= 0x0u ,

		/*! Raise interrupt register */
		.nRAISE		= 0x0u ,

		/*! Bus monitor configuration */
		.nBMMCFG		= 0x0u ,

		/*! Clock sustain configuration   */
		.nSUSCFG	= 0x0u ,

		/*!  Mailbox 0 control */
		.nMBOX0CTL		= 0x0u ,

		/*!  Mailbox 1 control */
		.nMBOX1CTL		= 0x0u ,

	},

		 /* Number of peripheral devices connected  */
		.nNumPeriDevice = 1,

		 /*Array of peripheral configuration pointers */
		.apPeriConfig = { 	 &sChain0_Slave6_PeriConfig0, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR	}

};

/************************************************* END OF SLAVE NODE 6 DESCRIPTION ********************************************************************************/

/************************************************* START OF SLAVE NODE 7 DESCRIPTION ********************************************************************************/

/* SLAVE NODE DESCRIPTION */

ADI_A2B_MEM_BCF_DATA
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode7=
{
	/* Node ID  */
	.nNodeID			= 0x7u ,

	/* Source node ID  */
	.nSrcNodeID			= 0x6u ,

	/*! Transceiver part number */
	.ePartNum			= ADI_A2B_AD2425 ,

	/* Auto-configure Node Enabled */
	.bEnableAutoConfig			= DISABLED ,

	.sAuthSettings =
	{
		/*! Vendor ID - ADI */
		.nVendorID			= 0xADu ,

		/*! Silicon version  */
		.nVersionID			= 0x2u ,

		/*! PRODUCT ID -AD2410 */
		.nProductID			= 0x25u ,

		/*! Expected capablity - I2C */
		.nCapability		= 0x1u ,
	},

	.sCustomNodeAuthSettings =
	{
		/*! Enable/Disable Custom Node ID settings */
		.bCustomNodeIdAuth		= DISABLED ,

	},

	.sI2SSettings =
	{
		/*! TDM mode  */
		.nTDMMode		= A2B_TDM4 ,

		/*! TDM channel size  */
		.nTDMChSize			= A2B_16BIT_TDM ,

		/*! SYNC mode - Pulse/50% duty cycle   */
		.nSyncMode			= A2B_ALTERNATE_SYNC ,

		/*! SYNC Polarity- Rising/Falling edge */
		.nSyncPolarity		= RAISING_EDGE ,

		/*! Early frame sync status */
		.bEarlySync			= ENABLED ,

		/*! SYNC offset with Super frame */
		.nSyncOffset		= 0x0 ,

		/*! DTXn change BCLK edge */
		.nBclkTxPolarity	= FALLING_EDGE ,

		/*! DRXn sampling BCLK edge */
		.nBclkRxPolarity	= FALLING_EDGE ,

		/*! Interleave slots between Tx pins  */
		.bTXInterleave		= DISABLED ,

		/*! Interleave slots between Rx pins  */
		.bRXInterleave		= DISABLED ,

		.sI2SRateConfig =
		{
			/* Sample rate */
			.nSamplingRate		= A2B_SAMPLERATE_24kHz ,

			/*! Reduce / re-transmit higher frequency samples  */
		.bReduce			= DISABLED ,

			/*! Share A2B bus slots for reduced sampling */
			.bShareBusSlot	= DISABLED ,

			/*! Enable Valid RR bit in Extra bit */
			.bRRValidBitLSB 	= DISABLED ,

			/*! Enable Valid RR bit in Extra Channel */
			.bRRValidBitExtraBit	= DISABLED ,

			/*! Enable Reduced rate strobe in ADR1/IO1 */
			.bRRStrobe	= DISABLED ,

			/*! Strobe direction High or Low */
			.bRRStrobeDirection	= A2B_LOW ,

		},
	},

	.sPDMSettings =
	{
		/*! Number of PDM0 slots  */
		.nNumSlotsPDM0		= A2B_PDM0SLOTS_1 ,

		/*! Number of PDM1 slots  */
		.nNumSlotsPDM1		= A2B_PDM1SLOTS_2 ,

		/*! Use High Pass Filter  */
		.bHPFUse		= ENABLED ,

		/*! PDM rate  */
		.nPDMRate		= A2B_PDM_RATE_SFF ,

	},

	.sConfigCtrlSettings =
	{
		/*! I2C interface frequency */
		.nI2CFrequency		= A2B_I2C_100kHz ,

		/*! Response cycles  */
		.nRespCycle			= 0x3Bu ,

		/*! Expected super/audio frame rate */
		.nSuperFrameRate	= A2B_SFF_RATE_48_0kHz ,

		/*! Number of broadcast slots */
		.nBroadCastSlots	= 0x0u ,

		/*! Local down slots */
		.nLocalDwnSlotsConsume		= 0x0u ,

		/*! Local Up slots */
		.nLocalUpSlotsContribute		= 0x3u ,

		/*! Pass up slots */
		.nPassUpSlots		= 0x2u ,

		/*! Pass down slots */
		.nPassDwnSlots		= 0x0u ,

		/*! Number of slots for contribution */
		.nSlotsforDwnstrmContribute		= 0x0u ,

		/*! Number of Upslots consumed */
		.nLocalUpSlotsConsume		= 0x3u ,

		/*! Array of downstream  masks */
		.anUpstreamConsumeSlots = { SLOT_0_ENABLED, SLOT_1_ENABLED, SLOT_2_ENABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED,
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for downstream contribution */
		.nOffsetDwnstrmContribute		= 0x0u ,

		/*! Enable Down slot consume through mask */
		.bUseDwnslotConsumeMasks		= ENABLED ,

		/*! Array of downstream  masks */
		.anDwnstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED,
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for Upstream contribution*/
		.nOffsetUpstrmContribute		= 0x0u ,

	},
	.sGPIOSettings =
	{
		.sPinMuxSettings =
		{
			/*! GPIO 0 Pin multiplexing */
			.bGPIO0PinUsage	= A2B_GPIO_0_DISABLE ,

			/*! GPIO 1 Pin multiplexing */
			.bGPIO1PinUsage	= A2B_GPIO_1_AS_CLKOUT ,

			/*! GPIO 2 Pin multiplexing */
			.bGPIO2PinUsage	= A2B_GPIO_2_DISABLE ,

			/*! GPIO 3 Pin multiplexing */
			.bGPIO3PinUsage	= A2B_GPIO_3_DISABLE ,

			/*! GPIO 4 Pin multiplexing */
			.bGPIO4PinUsage	= A2B_GPIO_4_OUTPUT ,

			/*! GPIO 5 Pin multiplexing */
			.bGPIO5PinUsage	= A2B_GPIO_5_AS_DRX0 ,

			/*! GPIO 6 Pin multiplexing */
			.bGPIO6PinUsage	= A2B_GPIO_6_DISABLE ,

			/*! GPIO 7 Pin multiplexing */
			.bGPIO7PinUsage	= A2B_GPIO_7_DISABLE ,
		},
		.sPinIntConfig =
		{
			/*! Enable GPIO 0 Input pin interrupt  */
			.bGPIO0Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 0 Input pin  */
			.bGPIO0IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 1 Input pin interrupt  */
			.bGPIO1Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 1 Input pin  */
			.bGPIO1IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 2 Input pin interrupt  */
			.bGPIO2Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 2 Input pin  */
			.bGPIO2IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 3 Input pin interrupt  */
			.bGPIO3Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 3 Input pin  */
			.bGPIO3IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 4 Input pin interrupt  */
			.bGPIO4Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 4 Input pin  */
			.bGPIO4IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 5 Input pin interrupt  */
			.bGPIO5Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 5 Input pin  */
			.bGPIO5IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 6 Input pin interrupt  */
			.bGPIO6Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 6 Input pin  */
			.bGPIO6IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 7 Input pin interrupt  */
			.bGPIO7Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 7 Input pin  */
			.bGPIO7IntPolarity	= RAISING_EDGE ,

		},
		.sOutPinVal =
		{
			/*! Data value for GPIO 0 output pin  */
			.bGPIO0Val = A2B_LOW ,

			/*! Data value for GPIO 1 output pin  */
			.bGPIO1Val = A2B_LOW ,

			/*! Data value for GPIO 2 output pin  */
			.bGPIO2Val = A2B_LOW ,

			/*! Data value for GPIO 3 output pin  */
			.bGPIO3Val = A2B_LOW ,

			/*! Data value for GPIO 4 output pin  */
			.bGPIO4Val = A2B_HIGH ,

			/*! Data value for GPIO 5 output pin  */
			.bGPIO5Val = A2B_LOW ,

			/*! Data value for GPIO 6 output pin  */
			.bGPIO6Val = A2B_LOW ,

			/*! Data value for GPIO 7 output pin  */
			.bGPIO7Val = A2B_LOW ,

		},

		/*! Digital Pin drive strength */
		.bHighDriveStrength = DISABLED ,

		/*! IRQ Pin Invert */
		.bIRQInv = DISABLED ,

		/*! Enable tristate when inactive */
		.bIRQTriState = DISABLED ,

	},

	.sInterruptSettings =
	{
		/*! Report Header count error  */
		.bReportHDCNTErr		= ENABLED ,

		/*! Report Data decoding error  */
		.bReportDDErr			= ENABLED ,

		/*! Report Data CRC error  */
		.bReportCRCErr			= ENABLED ,

		/*! Report Data Parity error  */
		.bReportDataParityErr	= DISABLED ,

		/*! Report Data Bus Power error  */
		.bReportPwrErr			= ENABLED ,

		/*! Report bit error count overflow error  */
		.bReportErrCntOverFlow	= ENABLED ,

		/*! Report SRF miss error  */
		.bReportSRFMissErr	= ENABLED ,

		/*! Report SRF crc error  */
		.bReportSRFCrcErr		= DISABLED ,

		/*! Report GPIO  0 Interrupt */
		.bReportGPIO0			= ENABLED ,

		/*! Report GPIO  1 Interrupt */
		.bReportGPIO1			= ENABLED ,

		/*! Report GPIO  2 Interrupt */
		.bReportGPIO2			= ENABLED ,

		/*! Report GPIO  3 Interrupt */
		.bReportGPIO3			= ENABLED ,

		/*! Report GPIO  4 Interrupt */
		.bReportGPIO4			= ENABLED ,

		/*! Report GPIO  5 Interrupt */
		.bReportGPIO5			= ENABLED ,

		/*! Report GPIO  6 Interrupt */
		.bReportGPIO6			= ENABLED ,

		/*! Report GPIO  7 Interrupt */
		.bReportGPIO7			= DISABLED ,

	},

	.sGPIODSettings =
	{
		.sGPIOD0Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD1Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD2Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD3Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD4Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD5Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD6Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD7Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
	},

	.sClkOutSettings =
	{
		/*! Enable Clock1 inversion */
		.bClk1Inv			= DISABLED ,

		/*! Clk1 pre-division */
		.bClk1PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk1 division */
		.bClk1Div			= A2B_CLKOUT_DIV_4,

		/*! Enable Clock2 inversion */
		.bClk2Inv			= DISABLED ,

		/*! Clk2 pre-division */
		.bClk2PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk2 division */
		.bClk2Div			= A2B_CLKOUT_DIV_4,

	},
	.sRegSettings =
	{
		/*! Switch control register */
		.nSWCTL		= 0x1u ,

		/*! Test mode register */
		.nTESTMODE	= 0x0u ,

		/*! Error control register */
		.nBECCTL	= 0xEFu ,

		/*! Error management register  */
		.nERRMGMT	= 0x0u ,

		/*! I2S test register  */
		.nI2STEST	= 0x0u ,

		/*! Generate error  */
		.nGENERR	= 0x0u ,

		/*! Raise interrupt register */
		.nRAISE		= 0x0u ,

		/*! Bus monitor configuration */
		.nBMMCFG		= 0x0u ,

		/*! Clock sustain configuration   */
		.nSUSCFG	= 0x0u ,

		/*!  Mailbox 0 control */
		.nMBOX0CTL		= 0x0u ,

		/*!  Mailbox 1 control */
		.nMBOX1CTL		= 0x0u ,

	},

		 /* Number of peripheral devices connected  */
		.nNumPeriDevice = 1,

		 /*Array of peripheral configuration pointers */
		.apPeriConfig = { 	 &sChain0_Slave7_PeriConfig0, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR	}

};

/************************************************* END OF SLAVE NODE 7 DESCRIPTION ********************************************************************************/

/************************************************* START OF SLAVE NODE 8 DESCRIPTION ********************************************************************************/

/* SLAVE NODE DESCRIPTION */

ADI_A2B_MEM_BCF_DATA
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode8=
{
	/* Node ID  */
	.nNodeID			= 0x8u ,

	/* Source node ID  */
	.nSrcNodeID			= 0x7u ,

	/*! Transceiver part number */
	.ePartNum			= ADI_A2B_AD2427 ,

	/* Auto-configure Node Enabled */
	.bEnableAutoConfig			= DISABLED ,

	.sAuthSettings =
	{
		/*! Vendor ID - ADI */
		.nVendorID			= 0xADu ,

		/*! Silicon version  */
		.nVersionID			= 0x0u ,

		/*! PRODUCT ID -AD2410 */
		.nProductID			= 0x27u ,

		/*! Expected capablity - I2C */
		.nCapability		= 0x1u ,
	},

	.sCustomNodeAuthSettings =
	{
		/*! Enable/Disable Custom Node ID settings */
		.bCustomNodeIdAuth		= DISABLED ,

	},

	.sPDMSettings =
	{
		/*! Number of PDM0 slots  */
		.nNumSlotsPDM0		= A2B_PDM0SLOTS_1 ,

		/*! Number of PDM1 slots  */
		.nNumSlotsPDM1		= A2B_PDM1SLOTS_2 ,

		/*! Use High Pass Filter  */
		.bHPFUse		= ENABLED ,

		/*! PDM rate  */
		.nPDMRate		= A2B_PDM_RATE_SFF ,

		/*! PDM Inverted Version of Alternate Clock */
		.bPDMInvClk		= DISABLED ,

		/*! PDM Alternate Clock */
		.bPDMAltClk		= DISABLED ,

		/*! PDM0 Falling Edge First */
		.bPDM0FallingEdgeFrst		= DISABLED ,

		/*! PDM1 Falling Edge First */
		.bPDM1FallingEdgeFrst		= DISABLED ,

		/*! PDM Destination */
		.ePDMDestination		= A2B_BUS_ONLY ,

	},

	.sConfigCtrlSettings =
	{
		/*! I2C interface frequency */
		.nI2CFrequency		= A2B_I2C_400kHz ,

		/*! Response cycles  */
		.nRespCycle			= 0x37u ,

		/*! Expected super/audio frame rate */
		.nSuperFrameRate	= A2B_SFF_RATE_48_0kHz ,

		/*! Number of broadcast slots */
		.nBroadCastSlots	= 0x0u ,

		/*! Local down slots */
		.nLocalDwnSlotsConsume		= 0x0u ,

		/*! Local Up slots */
		.nLocalUpSlotsContribute		= 0x1u ,

		/*! Pass up slots */
		.nPassUpSlots		= 0x1u ,

		/*! Pass down slots */
		.nPassDwnSlots		= 0x0u ,

		/*! Number of slots for contribution */
		.nSlotsforDwnstrmContribute		= 0x0u ,

		/*! Number of Upslots consumed */
		.nLocalUpSlotsConsume		= 0x0u ,

		/*! Array of downstream  masks */
		.anUpstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED,
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for downstream contribution */
		.nOffsetDwnstrmContribute		= 0x0u ,

		/*! Enable Down slot consume through mask */
		.bUseDwnslotConsumeMasks		= ENABLED ,

		/*! Array of downstream  masks */
		.anDwnstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED,
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for Upstream contribution*/
		.nOffsetUpstrmContribute		= 0x0u ,

	},
	.sGPIOSettings =
	{
		.sPinMuxSettings =
		{
			/*! GPIO 0 Pin multiplexing */
			.bGPIO0PinUsage	= A2B_GPIO_0_DISABLE ,

			/*! GPIO 1 Pin multiplexing */
			.bGPIO1PinUsage	= A2B_GPIO_1_DISABLE ,

			/*! GPIO 2 Pin multiplexing */
			.bGPIO2PinUsage	= A2B_GPIO_2_AS_CLKOUT ,

			/*! GPIO 3 Pin multiplexing */
			.bGPIO3PinUsage	= A2B_GPIO_3_DISABLE ,

			/*! GPIO 4 Pin multiplexing */
			.bGPIO4PinUsage	= A2B_GPIO_4_OUTPUT ,

			/*! GPIO 5 Pin multiplexing */
			.bGPIO5PinUsage	= A2B_GPIO_5_AS_PDM0 ,

			/*! GPIO 6 Pin multiplexing */
			.bGPIO6PinUsage	= A2B_GPIO_6_DISABLE ,

			/*! GPIO 7 Pin multiplexing */
			.bGPIO7PinUsage	= A2B_GPIO_7_DISABLE ,
		},
		.sPinIntConfig =
		{
			/*! Enable GPIO 0 Input pin interrupt  */
			.bGPIO0Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 0 Input pin  */
			.bGPIO0IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 1 Input pin interrupt  */
			.bGPIO1Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 1 Input pin  */
			.bGPIO1IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 2 Input pin interrupt  */
			.bGPIO2Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 2 Input pin  */
			.bGPIO2IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 3 Input pin interrupt  */
			.bGPIO3Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 3 Input pin  */
			.bGPIO3IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 4 Input pin interrupt  */
			.bGPIO4Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 4 Input pin  */
			.bGPIO4IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 5 Input pin interrupt  */
			.bGPIO5Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 5 Input pin  */
			.bGPIO5IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 6 Input pin interrupt  */
			.bGPIO6Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 6 Input pin  */
			.bGPIO6IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 7 Input pin interrupt  */
			.bGPIO7Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 7 Input pin  */
			.bGPIO7IntPolarity	= RAISING_EDGE ,

		},
		.sOutPinVal =
		{
			/*! Data value for GPIO 0 output pin  */
			.bGPIO0Val = A2B_LOW ,

			/*! Data value for GPIO 1 output pin  */
			.bGPIO1Val = A2B_LOW ,

			/*! Data value for GPIO 2 output pin  */
			.bGPIO2Val = A2B_LOW ,

			/*! Data value for GPIO 3 output pin  */
			.bGPIO3Val = A2B_LOW ,

			/*! Data value for GPIO 4 output pin  */
			.bGPIO4Val = A2B_HIGH ,

			/*! Data value for GPIO 5 output pin  */
			.bGPIO5Val = A2B_LOW ,

			/*! Data value for GPIO 6 output pin  */
			.bGPIO6Val = A2B_LOW ,

			/*! Data value for GPIO 7 output pin  */
			.bGPIO7Val = A2B_LOW ,

		},

		/*! Digital Pin drive strength */
		.bHighDriveStrength = DISABLED ,

		/*! IRQ Pin Invert */
		.bIRQInv = DISABLED ,

		/*! Enable tristate when inactive */
		.bIRQTriState = DISABLED ,

	},

	.sInterruptSettings =
	{
		/*! Report Header count error  */
		.bReportHDCNTErr		= ENABLED ,

		/*! Report Data decoding error  */
		.bReportDDErr			= ENABLED ,

		/*! Report Data CRC error  */
		.bReportCRCErr			= ENABLED ,

		/*! Report Data Parity error  */
		.bReportDataParityErr	= DISABLED ,

		/*! Report Data Bus Power error  */
		.bReportPwrErr			= ENABLED ,

		/*! Report bit error count overflow error  */
		.bReportErrCntOverFlow	= ENABLED ,

		/*! Report SRF miss error  */
		.bReportSRFMissErr	= ENABLED ,

		/*! Report SRF crc error  */
		.bReportSRFCrcErr		= DISABLED ,

		/*! Report GPIO  0 Interrupt */
		.bReportGPIO0			= ENABLED ,

		/*! Report GPIO  1 Interrupt */
		.bReportGPIO1			= ENABLED ,

		/*! Report GPIO  2 Interrupt */
		.bReportGPIO2			= ENABLED ,

		/*! Report GPIO  3 Interrupt */
		.bReportGPIO3			= ENABLED ,

		/*! Report GPIO  4 Interrupt */
		.bReportGPIO4			= ENABLED ,

		/*! Report GPIO  5 Interrupt */
		.bReportGPIO5			= ENABLED ,

		/*! Report GPIO  6 Interrupt */
		.bReportGPIO6			= ENABLED ,

		/*! Report GPIO  7 Interrupt */
		.bReportGPIO7			= DISABLED ,

	},

	.sGPIODSettings =
	{
		.sGPIOD0Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD1Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD2Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD3Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD4Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD5Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD6Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD7Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
	},

	.sClkOutSettings =
	{
		/*! Enable Clock1 inversion */
		.bClk1Inv			= DISABLED ,

		/*! Clk1 pre-division */
		.bClk1PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk1 division */
		.bClk1Div			= A2B_CLKOUT_DIV_4,

		/*! Enable Clock2 inversion */
		.bClk2Inv			= DISABLED ,

		/*! Clk2 pre-division */
		.bClk2PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk2 division */
		.bClk2Div			= A2B_CLKOUT_DIV_4,

	},
	.sRegSettings =
	{
		/*! Switch control register */
		.nSWCTL		= 0x1u ,

		/*! Test mode register */
		.nTESTMODE	= 0x0u ,

		/*! Error control register */
		.nBECCTL	= 0xEFu ,

		/*! Error management register  */
		.nERRMGMT	= 0x0u ,

		/*! Generate error  */
		.nGENERR	= 0x0u ,

		/*! Raise interrupt register */
		.nRAISE		= 0x0u ,

		/*! Bus monitor configuration */
		.nBMMCFG		= 0x0u ,

		/*! Clock sustain configuration   */
		.nSUSCFG	= 0x0u ,

		/*!  Mailbox 0 control */
		.nMBOX0CTL		= 0x0u ,

		/*!  Mailbox 1 control */
		.nMBOX1CTL		= 0x0u ,

		/*! PLL Control register  */
		.nPLLCTL	= 0x0u ,

		/*! LVDSA TX Control Register */
		.nTXACTL	= 0x0u ,

		/*! LVDSB TX Control Register */
		.nTXBCTL	= 0x0u ,

		/*! Control Register */
		.nCONTROL	= 0x0u ,

	},

		 /* Number of peripheral devices connected  */
		.nNumPeriDevice = 1,

		 /*Array of peripheral configuration pointers */
		.apPeriConfig = { 	 &sChain0_Slave8_PeriConfig0, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR	}

};

/************************************************* END OF SLAVE NODE 8 DESCRIPTION ********************************************************************************/

/************************************************* START OF SLAVE NODE 9 DESCRIPTION ********************************************************************************/

/* SLAVE NODE DESCRIPTION */

ADI_A2B_MEM_BCF_DATA
static ADI_A2B_SLAVE_NCD sChain0_SlaveNode9=
{
	/* Node ID  */
	.nNodeID			= 0x9u ,

	/* Source node ID  */
	.nSrcNodeID			= 0x8u ,

	/*! Transceiver part number */
	.ePartNum			= ADI_A2B_AD2427 ,

	/* Auto-configure Node Enabled */
	.bEnableAutoConfig			= DISABLED ,

	.sAuthSettings =
	{
		/*! Vendor ID - ADI */
		.nVendorID			= 0xADu ,

		/*! Silicon version  */
		.nVersionID			= 0x0u ,

		/*! PRODUCT ID -AD2410 */
		.nProductID			= 0x27u ,

		/*! Expected capablity - I2C */
		.nCapability		= 0x1u ,
	},

	.sCustomNodeAuthSettings =
	{
		/*! Enable/Disable Custom Node ID settings */
		.bCustomNodeIdAuth		= DISABLED ,

	},

	.sPDMSettings =
	{
		/*! Number of PDM0 slots  */
		.nNumSlotsPDM0		= A2B_PDM0SLOTS_1 ,

		/*! Number of PDM1 slots  */
		.nNumSlotsPDM1		= A2B_PDM1SLOTS_2 ,

		/*! Use High Pass Filter  */
		.bHPFUse		= ENABLED ,

		/*! PDM rate  */
		.nPDMRate		= A2B_PDM_RATE_SFF ,

		/*! PDM Inverted Version of Alternate Clock */
		.bPDMInvClk		= DISABLED ,

		/*! PDM Alternate Clock */
		.bPDMAltClk		= DISABLED ,

		/*! PDM0 Falling Edge First */
		.bPDM0FallingEdgeFrst		= DISABLED ,

		/*! PDM1 Falling Edge First */
		.bPDM1FallingEdgeFrst		= DISABLED ,

		/*! PDM Destination */
		.ePDMDestination		= A2B_BUS_ONLY ,

	},

	.sConfigCtrlSettings =
	{
		/*! I2C interface frequency */
		.nI2CFrequency		= A2B_I2C_400kHz ,

		/*! Response cycles  */
		.nRespCycle			= 0x33u ,

		/*! Expected super/audio frame rate */
		.nSuperFrameRate	= A2B_SFF_RATE_48_0kHz ,

		/*! Number of broadcast slots */
		.nBroadCastSlots	= 0x0u ,

		/*! Local down slots */
		.nLocalDwnSlotsConsume		= 0x0u ,

		/*! Local Up slots */
		.nLocalUpSlotsContribute		= 0x1u ,

		/*! Pass up slots */
		.nPassUpSlots		= 0x0u ,

		/*! Pass down slots */
		.nPassDwnSlots		= 0x0u ,

		/*! Number of slots for contribution */
		.nSlotsforDwnstrmContribute		= 0x0u ,

		/*! Number of Upslots consumed */
		.nLocalUpSlotsConsume		= 0x0u ,

		/*! Array of downstream  masks */ 
		.anUpstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED, 
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED, 
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED, 
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for downstream contribution */
		.nOffsetDwnstrmContribute		= 0x0u ,

		/*! Enable Down slot consume through mask */
		.bUseDwnslotConsumeMasks		= ENABLED ,

		/*! Array of downstream  masks */ 
		.anDwnstreamConsumeSlots = { SLOT_0_DISABLED, SLOT_1_DISABLED, SLOT_2_DISABLED, SLOT_3_DISABLED, SLOT_4_DISABLED, SLOT_5_DISABLED, SLOT_6_DISABLED, SLOT_7_DISABLED,
 									 SLOT_8_DISABLED, SLOT_9_DISABLED, SLOT_10_DISABLED, SLOT_11_DISABLED, SLOT_12_DISABLED, SLOT_13_DISABLED, SLOT_14_DISABLED, SLOT_15_DISABLED,
 									 SLOT_16_DISABLED, SLOT_17_DISABLED, SLOT_18_DISABLED, SLOT_19_DISABLED, SLOT_20_DISABLED, SLOT_21_DISABLED, SLOT_22_DISABLED, SLOT_23_DISABLED, 
 									 SLOT_24_DISABLED, SLOT_25_DISABLED, SLOT_26_DISABLED, SLOT_27_DISABLED, SLOT_28_DISABLED, SLOT_29_DISABLED, SLOT_30_DISABLED, SLOT_31_DISABLED},
		/*! Offset from the RX Buffer for Upstream contribution*/
		.nOffsetUpstrmContribute		= 0x0u ,

	},
	.sGPIOSettings =
	{
		.sPinMuxSettings =
		{
			/*! GPIO 0 Pin multiplexing */
			.bGPIO0PinUsage	= A2B_GPIO_0_DISABLE ,

			/*! GPIO 1 Pin multiplexing */
			.bGPIO1PinUsage	= A2B_GPIO_1_DISABLE ,

			/*! GPIO 2 Pin multiplexing */
			.bGPIO2PinUsage	= A2B_GPIO_2_AS_CLKOUT ,

			/*! GPIO 3 Pin multiplexing */
			.bGPIO3PinUsage	= A2B_GPIO_3_DISABLE ,

			/*! GPIO 4 Pin multiplexing */
			.bGPIO4PinUsage	= A2B_GPIO_4_OUTPUT ,

			/*! GPIO 5 Pin multiplexing */
			.bGPIO5PinUsage	= A2B_GPIO_5_AS_PDM0 ,

			/*! GPIO 6 Pin multiplexing */
			.bGPIO6PinUsage	= A2B_GPIO_6_DISABLE ,

			/*! GPIO 7 Pin multiplexing */
			.bGPIO7PinUsage	= A2B_GPIO_7_DISABLE ,
		},
		.sPinIntConfig =
		{
			/*! Enable GPIO 0 Input pin interrupt  */
			.bGPIO0Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 0 Input pin  */
			.bGPIO0IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 1 Input pin interrupt  */
			.bGPIO1Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 1 Input pin  */
			.bGPIO1IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 2 Input pin interrupt  */
			.bGPIO2Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 2 Input pin  */
			.bGPIO2IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 3 Input pin interrupt  */
			.bGPIO3Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 3 Input pin  */
			.bGPIO3IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 4 Input pin interrupt  */
			.bGPIO4Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 4 Input pin  */
			.bGPIO4IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 5 Input pin interrupt  */
			.bGPIO5Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 5 Input pin  */
			.bGPIO5IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 6 Input pin interrupt  */
			.bGPIO6Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 6 Input pin  */
			.bGPIO6IntPolarity	= RAISING_EDGE ,

			/*! Enable GPIO 7 Input pin interrupt  */
			.bGPIO7Interrupt	= DISABLED ,

			/*! Interrupt polarity - GPIO 7 Input pin  */
			.bGPIO7IntPolarity	= RAISING_EDGE ,

		},
		.sOutPinVal =
		{
			/*! Data value for GPIO 0 output pin  */
			.bGPIO0Val = A2B_LOW ,

			/*! Data value for GPIO 1 output pin  */
			.bGPIO1Val = A2B_LOW ,

			/*! Data value for GPIO 2 output pin  */
			.bGPIO2Val = A2B_LOW ,

			/*! Data value for GPIO 3 output pin  */
			.bGPIO3Val = A2B_LOW ,

			/*! Data value for GPIO 4 output pin  */
			.bGPIO4Val = A2B_HIGH ,

			/*! Data value for GPIO 5 output pin  */
			.bGPIO5Val = A2B_LOW ,

			/*! Data value for GPIO 6 output pin  */
			.bGPIO6Val = A2B_LOW ,

			/*! Data value for GPIO 7 output pin  */
			.bGPIO7Val = A2B_LOW ,

		},

		/*! Digital Pin drive strength */
		.bHighDriveStrength = DISABLED ,

		/*! IRQ Pin Invert */
		.bIRQInv = DISABLED ,

		/*! Enable tristate when inactive */
		.bIRQTriState = DISABLED ,

	},

	.sInterruptSettings =
	{
		/*! Report Header count error  */
		.bReportHDCNTErr		= ENABLED ,

		/*! Report Data decoding error  */
		.bReportDDErr			= ENABLED ,

		/*! Report Data CRC error  */
		.bReportCRCErr			= ENABLED ,

		/*! Report Data Parity error  */
		.bReportDataParityErr	= DISABLED ,

		/*! Report Data Bus Power error  */
		.bReportPwrErr			= ENABLED ,

		/*! Report bit error count overflow error  */
		.bReportErrCntOverFlow	= ENABLED ,

		/*! Report SRF miss error  */
		.bReportSRFMissErr	= ENABLED ,

		/*! Report SRF crc error  */
		.bReportSRFCrcErr		= DISABLED ,

		/*! Report GPIO  0 Interrupt */
		.bReportGPIO0			= ENABLED ,

		/*! Report GPIO  1 Interrupt */
		.bReportGPIO1			= ENABLED ,

		/*! Report GPIO  2 Interrupt */
		.bReportGPIO2			= ENABLED ,

		/*! Report GPIO  3 Interrupt */
		.bReportGPIO3			= ENABLED ,

		/*! Report GPIO  4 Interrupt */
		.bReportGPIO4			= ENABLED ,

		/*! Report GPIO  5 Interrupt */
		.bReportGPIO5			= ENABLED ,

		/*! Report GPIO  6 Interrupt */
		.bReportGPIO6			= ENABLED ,

		/*! Report GPIO  7 Interrupt */
		.bReportGPIO7			= DISABLED ,

	},

	.sGPIODSettings =
	{
		.sGPIOD0Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD1Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD2Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD3Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD4Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD5Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD6Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
		.sGPIOD7Config =
		{
			/*! Enable/Disable GPIO over distance   */
			.bGPIODistance	= DISABLED ,

			/*! Enable/Disable  */
			.bGPIOSignalInv	= DISABLED ,

			/*! Bus port masks */ 
			.abBusPortMask = { A2B_MASK_BUSFLAG_0, A2B_MASK_BUSFLAG_1, A2B_MASK_BUSFLAG_2, A2B_MASK_BUSFLAG_3, A2B_MASK_BUSFLAG_4, A2B_MASK_BUSFLAG_5, A2B_MASK_BUSFLAG_6, A2B_MASK_BUSFLAG_7},


		},
	},

	.sClkOutSettings =
	{
		/*! Enable Clock1 inversion */
		.bClk1Inv			= DISABLED ,

		/*! Clk1 pre-division */
		.bClk1PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk1 division */
		.bClk1Div			= A2B_CLKOUT_DIV_4,

		/*! Enable Clock2 inversion */
		.bClk2Inv			= DISABLED ,

		/*! Clk2 pre-division */
		.bClk2PreDiv		= A2B_CLKOUT_PREDIV_02,

		/*! Clk2 division */
		.bClk2Div			= A2B_CLKOUT_DIV_4,

	},
	.sRegSettings =
	{
		/*! Switch control register */
		.nSWCTL		= 0x0u ,

		/*! Test mode register */
		.nTESTMODE	= 0x0u ,

		/*! Error control register */
		.nBECCTL	= 0xEFu ,

		/*! Error management register  */
		.nERRMGMT	= 0x0u ,

		/*! Generate error  */
		.nGENERR	= 0x0u ,

		/*! Raise interrupt register */
		.nRAISE		= 0x0u ,

		/*! Bus monitor configuration */
		.nBMMCFG		= 0x0u ,

		/*! Clock sustain configuration   */
		.nSUSCFG	= 0x0u ,

		/*!  Mailbox 0 control */
		.nMBOX0CTL		= 0x0u ,

		/*!  Mailbox 1 control */
		.nMBOX1CTL		= 0x0u ,

		/*! PLL Control register  */
		.nPLLCTL	= 0x0u ,

		/*! LVDSA TX Control Register */
		.nTXACTL	= 0x0u ,

		/*! LVDSB TX Control Register */
		.nTXBCTL	= 0x0u ,

		/*! Control Register */
		.nCONTROL	= 0x0u ,

	},

		 /* Number of peripheral devices connected  */
		.nNumPeriDevice = 1,

		 /*Array of peripheral configuration pointers */ 
		.apPeriConfig = { 	 &sChain0_Slave9_PeriConfig0, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR, NULL_PTR	}

};

/************************************************* END OF SLAVE NODE 9 DESCRIPTION ********************************************************************************/
 
/************************************************** END OF AD2410 DESCRIPTION ********************************************************************************  */

/************************************************** START OF PERIPHERAL DESCRIPTION ********************************************************************************  */

/************************************************** START OF PERIPHERALS CONNECTED TO TARGET PROCESSOR  ********************************************************************************  */

/* Peripheral - 0*/

ADI_A2B_MEM_BCF_DATA
static A2B_PERIPHERAL_DEVICE_CONFIG  Target_PeriConfig0=
{
 /*! I2C interface status  */ 
	 .bI2CInterfaceUse = ENABLED, 

	/*7 bit I2C address */ 
	.nI2Caddr = 0x38, 

	/* Device type -audio source/sink/host  */ 
	.eDeviceType = A2B_AUDIO_HOST, 

	/* Tx0 Pin in use */
	.bUseTx0 = DISABLED, 

	/* Rx0 Pin in use */
	.bUseRx0 = DISABLED, 

	/* Tx1 Pin in use */
	.bUseTx1 = DISABLED, 

	/* Rx1 Pin in use */
	.bUseRx1 = DISABLED, 

	/* No of Tx0 channels  */ 
	.nChTx0 = 0,

	/* No of Rx0 channels  */ 
	.nChRx0 = 0,

	/* No of Tx1 channels  */ 
	.nChTx1 = 0, 

	/* No of Rx1 channels  */ 
	.nChRx1 = 0, 

	/* Number of configuration units  */ 
	.nNumPeriConfigUnit = 0,

	.paPeriConfigUnit = NULL_PTR
 };

/* Peripheral - 1*/

ADI_A2B_MEM_BCF_DATA
static A2B_PERIPHERAL_DEVICE_CONFIG  Target_PeriConfig1=
{
 /*! I2C interface status  */ 
	 .bI2CInterfaceUse = ENABLED, 

	/*7 bit I2C address */ 
	.nI2Caddr = 0x50, 

	/* Device type -audio source/sink/host  */ 
	.eDeviceType = A2B_GENERIC_I2C_DEVICE, 

	/* Tx0 Pin in use */
	.bUseTx0 = DISABLED, 

	/* Rx0 Pin in use */
	.bUseRx0 = DISABLED, 

	/* Tx1 Pin in use */
	.bUseTx1 = DISABLED, 

	/* Rx1 Pin in use */
	.bUseRx1 = DISABLED, 

	/* No of Tx0 channels  */ 
	.nChTx0 = 0, 

	/* No of Rx0 channels  */ 
	.nChRx0 = 0, 

	/* No of Tx1 channels  */ 
	.nChTx1 = 0, 

	/* No of Rx1 channels  */ 
	.nChRx1 = 0, 

	/* Number of configuration units  */ 
	.nNumPeriConfigUnit = 0, 

	.paPeriConfigUnit = NULL_PTR 
 };

/* Peripheral - 2*/

ADI_A2B_MEM_BCF_DATA
static A2B_PERIPHERAL_DEVICE_CONFIG  Target_PeriConfig2=
{
 /*! I2C interface status  */ 
	 .bI2CInterfaceUse = ENABLED, 

	/*7 bit I2C address */ 
	.nI2Caddr = 0x39, 

	/* Device type -audio source/sink/host  */ 
	.eDeviceType = A2B_GENERIC_I2C_DEVICE, 

	/* Tx0 Pin in use */
	.bUseTx0 = DISABLED, 

	/* Rx0 Pin in use */
	.bUseRx0 = DISABLED, 

	/* Tx1 Pin in use */
	.bUseTx1 = DISABLED, 

	/* Rx1 Pin in use */
	.bUseRx1 = DISABLED, 

	/* No of Tx0 channels  */ 
	.nChTx0 = 0, 

	/* No of Rx0 channels  */ 
	.nChRx0 = 0, 

	/* No of Tx1 channels  */ 
	.nChTx1 = 0, 

	/* No of Rx1 channels  */ 
	.nChRx1 = 0, 

	/* Number of configuration units  */ 
	.nNumPeriConfigUnit = 46, 

	.paPeriConfigUnit =  &gaPeriCfg_FF_39_Unit[0] 
 };

/************************************************** END OF PERIPHERALS CONNECTED TO TARGET PROCESSOR  ********************************************************************************  */

/************************************************** START OF CHAIN 0 SLAVE0 PERIPHERAL DESCRIPTION ********************************************************************************  */

/* Peripheral - 0*/

ADI_A2B_MEM_BCF_DATA
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave0_PeriConfig0=
{
	/* I2C interface status  */ 
	 .bI2CInterfaceUse = DISABLED,

	/*7 bit I2C address */ 
	.nI2Caddr = 0x50,

	/* Device type -audio source/sink/host  */ 
	.eDeviceType = A2B_AUDIO_SOURCE,

	/* Tx0 Pin in use */
	.bUseTx0 = ENABLED,

	/* Rx0 Pin in use */
	.bUseRx0 = DISABLED, 

	/* Tx1 Pin in use */
	.bUseTx1 = DISABLED, 

	/* Rx1 Pin in use */
	.bUseRx1 = DISABLED, 

	/* No of Tx0 channels  */ 
	.nChTx0 = 1,

	/* No of Rx0 channels  */ 
	.nChRx0 = 0, 

	/* No of Tx1 channels  */ 
	.nChTx1 = 0, 

	/* No of Rx1 channels  */ 
	.nChRx1 = 0, 

	/* Number of configuration units  */ 
	.nNumPeriConfigUnit = 0,

	/* Pointer to configuration units  */
	.paPeriConfigUnit = NULL_PTR
 };

/************************************************** END OF CHAIN 0 SLAVE0 PERIPHERAL DESCRIPTION ********************************************************************************  */

/************************************************** START OF CHAIN 0 SLAVE1 PERIPHERAL DESCRIPTION ********************************************************************************  */

/* Peripheral - 0*/

ADI_A2B_MEM_BCF_DATA
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave1_PeriConfig0=
{
	/* I2C interface status  */
	 .bI2CInterfaceUse = ENABLED,

	/*7 bit I2C address */
	.nI2Caddr = 0x19,

	/* Device type -audio source/sink/host  */
	.eDeviceType = A2B_AUDIO_SOURCE,

	/* Tx0 Pin in use */
	.bUseTx0 = ENABLED,

	/* Rx0 Pin in use */
	.bUseRx0 = DISABLED,

	/* Tx1 Pin in use */
	.bUseTx1 = DISABLED,

	/* Rx1 Pin in use */
	.bUseRx1 = DISABLED,

	/* No of Tx0 channels  */
	.nChTx0 = 3,

	/* No of Rx0 channels  */
	.nChRx0 = 0,

	/* No of Tx1 channels  */
	.nChTx1 = 0,

	/* No of Rx1 channels  */
	.nChRx1 = 0,

	/* Number of configuration units  */
	.nNumPeriConfigUnit = 7,

	/* Pointer to configuration units  */ 
	.paPeriConfigUnit =  &gaPeriCfg_1_19_Unit[0]
 };

/************************************************** END OF CHAIN 0 SLAVE1 PERIPHERAL DESCRIPTION ********************************************************************************  */

/************************************************** START OF CHAIN 0 SLAVE2 PERIPHERAL DESCRIPTION ********************************************************************************  */

/* Peripheral - 0*/

ADI_A2B_MEM_BCF_DATA
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave2_PeriConfig0=
{
	/* I2C interface status  */ 
	 .bI2CInterfaceUse = ENABLED, 

	/*7 bit I2C address */ 
	.nI2Caddr = 0x19,

	/* Device type -audio source/sink/host  */ 
	.eDeviceType = A2B_AUDIO_SOURCE,

	/* Tx0 Pin in use */
	.bUseTx0 = ENABLED,

	/* Rx0 Pin in use */
	.bUseRx0 = DISABLED, 

	/* Tx1 Pin in use */
	.bUseTx1 = DISABLED, 

	/* Rx1 Pin in use */
	.bUseRx1 = DISABLED, 

	/* No of Tx0 channels  */ 
	.nChTx0 = 3,

	/* No of Rx0 channels  */ 
	.nChRx0 = 0, 

	/* No of Tx1 channels  */ 
	.nChTx1 = 0, 

	/* No of Rx1 channels  */ 
	.nChRx1 = 0, 

	/* Number of configuration units  */ 
	.nNumPeriConfigUnit = 7,

	/* Pointer to configuration units  */
	.paPeriConfigUnit =  &gaPeriCfg_2_19_Unit[0]
 };

/************************************************** END OF CHAIN 0 SLAVE2 PERIPHERAL DESCRIPTION ********************************************************************************  */

/************************************************** START OF CHAIN 0 SLAVE3 PERIPHERAL DESCRIPTION ********************************************************************************  */

/* Peripheral - 0*/

ADI_A2B_MEM_BCF_DATA
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave3_PeriConfig0=
{
	/* I2C interface status  */
	 .bI2CInterfaceUse = DISABLED,

	/*7 bit I2C address */
	.nI2Caddr = 0x50,

	/* Device type -audio source/sink/host  */
	.eDeviceType = A2B_AUDIO_SOURCE,

	/* Tx0 Pin in use */
	.bUseTx0 = ENABLED,

	/* Rx0 Pin in use */
	.bUseRx0 = DISABLED,

	/* Tx1 Pin in use */
	.bUseTx1 = DISABLED,

	/* Rx1 Pin in use */
	.bUseRx1 = DISABLED,

	/* No of Tx0 channels  */
	.nChTx0 = 1,

	/* No of Rx0 channels  */
	.nChRx0 = 0,

	/* No of Tx1 channels  */
	.nChTx1 = 0,

	/* No of Rx1 channels  */
	.nChRx1 = 0,

	/* Number of configuration units  */
	.nNumPeriConfigUnit = 0,

	/* Pointer to configuration units  */ 
	.paPeriConfigUnit = NULL_PTR
 };

/************************************************** END OF CHAIN 0 SLAVE3 PERIPHERAL DESCRIPTION ********************************************************************************  */

/************************************************** START OF CHAIN 0 SLAVE4 PERIPHERAL DESCRIPTION ********************************************************************************  */

/* Peripheral - 0*/

ADI_A2B_MEM_BCF_DATA
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave4_PeriConfig0=
{
	/* I2C interface status  */
	 .bI2CInterfaceUse = DISABLED,

	/*7 bit I2C address */
	.nI2Caddr = 0x50,

	/* Device type -audio source/sink/host  */
	.eDeviceType = A2B_AUDIO_SOURCE,

	/* Tx0 Pin in use */
	.bUseTx0 = ENABLED,

	/* Rx0 Pin in use */
	.bUseRx0 = DISABLED,

	/* Tx1 Pin in use */
	.bUseTx1 = DISABLED,

	/* Rx1 Pin in use */
	.bUseRx1 = DISABLED,

	/* No of Tx0 channels  */
	.nChTx0 = 1,

	/* No of Rx0 channels  */
	.nChRx0 = 0,

	/* No of Tx1 channels  */
	.nChTx1 = 0,

	/* No of Rx1 channels  */
	.nChRx1 = 0,

	/* Number of configuration units  */
	.nNumPeriConfigUnit = 0,

	/* Pointer to configuration units  */
	.paPeriConfigUnit = NULL_PTR
 };

/************************************************** END OF CHAIN 0 SLAVE4 PERIPHERAL DESCRIPTION ********************************************************************************  */

/************************************************** START OF CHAIN 0 SLAVE5 PERIPHERAL DESCRIPTION ********************************************************************************  */

/* Peripheral - 0*/

ADI_A2B_MEM_BCF_DATA
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave5_PeriConfig0=
{
	/* I2C interface status  */
	 .bI2CInterfaceUse = DISABLED,

	/*7 bit I2C address */
	.nI2Caddr = 0x50,

	/* Device type -audio source/sink/host  */
	.eDeviceType = A2B_AUDIO_SOURCE,

	/* Tx0 Pin in use */
	.bUseTx0 = ENABLED,

	/* Rx0 Pin in use */
	.bUseRx0 = DISABLED,

	/* Tx1 Pin in use */
	.bUseTx1 = DISABLED,

	/* Rx1 Pin in use */
	.bUseRx1 = DISABLED,

	/* No of Tx0 channels  */
	.nChTx0 = 1,

	/* No of Rx0 channels  */
	.nChRx0 = 0,

	/* No of Tx1 channels  */
	.nChTx1 = 0,

	/* No of Rx1 channels  */
	.nChRx1 = 0,

	/* Number of configuration units  */
	.nNumPeriConfigUnit = 0,

	/* Pointer to configuration units  */
	.paPeriConfigUnit = NULL_PTR
 };

/************************************************** END OF CHAIN 0 SLAVE5 PERIPHERAL DESCRIPTION ********************************************************************************  */

/************************************************** START OF CHAIN 0 SLAVE6 PERIPHERAL DESCRIPTION ********************************************************************************  */

/* Peripheral - 0*/

ADI_A2B_MEM_BCF_DATA
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave6_PeriConfig0=
{
	/* I2C interface status  */
	 .bI2CInterfaceUse = ENABLED,

	/*7 bit I2C address */
	.nI2Caddr = 0x19,

	/* Device type -audio source/sink/host  */
	.eDeviceType = A2B_AUDIO_SOURCE,

	/* Tx0 Pin in use */
	.bUseTx0 = ENABLED,

	/* Rx0 Pin in use */
	.bUseRx0 = DISABLED,

	/* Tx1 Pin in use */
	.bUseTx1 = DISABLED,

	/* Rx1 Pin in use */
	.bUseRx1 = DISABLED,

	/* No of Tx0 channels  */
	.nChTx0 = 3,

	/* No of Rx0 channels  */
	.nChRx0 = 0,

	/* No of Tx1 channels  */
	.nChTx1 = 0,

	/* No of Rx1 channels  */
	.nChRx1 = 0,

	/* Number of configuration units  */
	.nNumPeriConfigUnit = 7,

	/* Pointer to configuration units  */
	.paPeriConfigUnit =  &gaPeriCfg_6_19_Unit[0]
 };

/************************************************** END OF CHAIN 0 SLAVE6 PERIPHERAL DESCRIPTION ********************************************************************************  */

/************************************************** START OF CHAIN 0 SLAVE7 PERIPHERAL DESCRIPTION ********************************************************************************  */

/* Peripheral - 0*/

ADI_A2B_MEM_BCF_DATA
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave7_PeriConfig0=
{
	/* I2C interface status  */
	 .bI2CInterfaceUse = ENABLED,

	/*7 bit I2C address */
	.nI2Caddr = 0x19,

	/* Device type -audio source/sink/host  */
	.eDeviceType = A2B_AUDIO_SOURCE,

	/* Tx0 Pin in use */
	.bUseTx0 = ENABLED,

	/* Rx0 Pin in use */
	.bUseRx0 = DISABLED,

	/* Tx1 Pin in use */
	.bUseTx1 = DISABLED,

	/* Rx1 Pin in use */
	.bUseRx1 = DISABLED,

	/* No of Tx0 channels  */
	.nChTx0 = 3,

	/* No of Rx0 channels  */
	.nChRx0 = 0,

	/* No of Tx1 channels  */
	.nChTx1 = 0,

	/* No of Rx1 channels  */
	.nChRx1 = 0,

	/* Number of configuration units  */
	.nNumPeriConfigUnit = 7,

	/* Pointer to configuration units  */
	.paPeriConfigUnit =  &gaPeriCfg_7_19_Unit[0]
 };

/************************************************** END OF CHAIN 0 SLAVE7 PERIPHERAL DESCRIPTION ********************************************************************************  */

/************************************************** START OF CHAIN 0 SLAVE8 PERIPHERAL DESCRIPTION ********************************************************************************  */

/* Peripheral - 0*/

ADI_A2B_MEM_BCF_DATA
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave8_PeriConfig0=
{
	/* I2C interface status  */
	 .bI2CInterfaceUse = DISABLED,

	/*7 bit I2C address */
	.nI2Caddr = 0x50,

	/* Device type -audio source/sink/host  */
	.eDeviceType = A2B_AUDIO_SOURCE,

	/* Tx0 Pin in use */
	.bUseTx0 = ENABLED,

	/* Rx0 Pin in use */
	.bUseRx0 = DISABLED,

	/* Tx1 Pin in use */
	.bUseTx1 = DISABLED,

	/* Rx1 Pin in use */
	.bUseRx1 = DISABLED,

	/* No of Tx0 channels  */
	.nChTx0 = 1,

	/* No of Rx0 channels  */
	.nChRx0 = 0,

	/* No of Tx1 channels  */
	.nChTx1 = 0,

	/* No of Rx1 channels  */
	.nChRx1 = 0,

	/* Number of configuration units  */
	.nNumPeriConfigUnit = 0,

	/* Pointer to configuration units  */
	.paPeriConfigUnit = NULL_PTR
 };

/************************************************** END OF CHAIN 0 SLAVE8 PERIPHERAL DESCRIPTION ********************************************************************************  */

/************************************************** START OF CHAIN 0 SLAVE9 PERIPHERAL DESCRIPTION ********************************************************************************  */

/* Peripheral - 0*/

ADI_A2B_MEM_BCF_DATA
static A2B_PERIPHERAL_DEVICE_CONFIG  sChain0_Slave9_PeriConfig0=
{
	/* I2C interface status  */
	 .bI2CInterfaceUse = DISABLED,

	/*7 bit I2C address */
	.nI2Caddr = 0x50,

	/* Device type -audio source/sink/host  */
	.eDeviceType = A2B_AUDIO_SOURCE,

	/* Tx0 Pin in use */
	.bUseTx0 = ENABLED,

	/* Rx0 Pin in use */
	.bUseRx0 = DISABLED,

	/* Tx1 Pin in use */
	.bUseTx1 = DISABLED,

	/* Rx1 Pin in use */
	.bUseRx1 = DISABLED,

	/* No of Tx0 channels  */
	.nChTx0 = 1,

	/* No of Rx0 channels  */
	.nChRx0 = 0,

	/* No of Tx1 channels  */
	.nChTx1 = 0,

	/* No of Rx1 channels  */
	.nChRx1 = 0,

	/* Number of configuration units  */
	.nNumPeriConfigUnit = 0,

	/* Pointer to configuration units  */
	.paPeriConfigUnit = NULL_PTR
 };

/************************************************** END OF CHAIN 0 SLAVE9 PERIPHERAL DESCRIPTION ********************************************************************************  */


 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_0_Data[1] =
{
	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_1_Data[1] =
{
	0x4u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_2_Data[1] =
{
	0x74u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_3_Data[1] =
{
	0x5Fu	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_4_Data[1] =
{
	0x2Fu	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_5_Data[1] =
{
	0x7Fu	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_6_Data[1] =
{
	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_7_Data[1] =
{
	0xFu	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_8_Data[6] =
{
	0x0u,	0xFDu,	0x0u,	0xCu,	0x20u,	0x1u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_9_Data[4] =
{
	0x64u,	0x0u,	0x0u,	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_10_Data[2] =
{
	0x0u,	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_11_Data[4] =
{
	0x0u,	0x0u,	0x0u,	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_12_Data[1] =
{
	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_13_Data[8] =
{
	0x0u,	0x1u,	0x5u,	0x1u,	0x5u,	0x0u,	0x0u,	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_14_Data[3] =
{
	0x13u,	0x0u,	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_15_Data[14] =
{
	0x21u,	0x0u,	0x41u,	0x0u,	0x0u,	0x0u,	0x1u,	0xE7u,	0xE7u,	0x0u,	
	0x0u,	0xE5u,	0x0u,	0x3u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_16_Data[2] =
{
	0x0u,	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_17_Data[3] =
{
	0x3u,	0x0u,	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_18_Data[1] =
{
	0xAAu	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_19_Data[2] =
{
	0xAAu,	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_20_Data[1] =
{
	0x8u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_21_Data[1020] =
{
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u	
	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_22_Data[1020] =
{
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u	
	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_23_Data[1020] =
{
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u	
	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_24_Data[1020] =
{
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u	
	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_25_Data[15] =
{
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_26_Data[1] =
{
	0x10u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_27_Data[1] =
{
	0x1u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_28_Data[5] =
{
	0x7Fu,	0x74u,	0x5Fu,	0x2Fu,	0x1u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_29_Data[4] =
{
	0x0u,	0x0u,	0x0u,	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_30_Data[2] =
{
	0x10u,	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_31_Data[5] =
{
	0x0u,	0x4u,	0x0u,	0x0u,	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_32_Data[1] =
{
	0x7Fu	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_33_Data[1] =
{
	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_34_Data[1] =
{
	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_35_Data[1] =
{
	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_36_Data[1] =
{
	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_37_Data[1] =
{
	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_38_Data[2] =
{
	0x7Fu,	0x3u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_39_Data[275] =
{
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0xFEu,	0xE0u,	0x0u,	0x0u,	0x0u,	
	0xFFu,	0x34u,	0x0u,	0x0u,	0x0u,	0xFFu,	0x2Cu,	0x0u,	0x0u,	0x0u,	
	0xFFu,	0x54u,	0x0u,	0x0u,	0x0u,	0xFFu,	0x5Cu,	0x0u,	0x0u,	0x0u,	
	0xFFu,	0xF5u,	0x8u,	0x20u,	0x0u,	0xFFu,	0x38u,	0x0u,	0x0u,	0x0u,	
	0xFFu,	0x80u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0xFEu,	0xE8u,	0xCu,	0x0u,	0x0u,	
	0xFEu,	0x30u,	0x0u,	0xE2u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0xFFu,	0xE8u,	0x7u,	0x20u,	0x8u,	
	0x0u,	0x0u,	0x6u,	0xA0u,	0x0u,	0xFFu,	0xE0u,	0x0u,	0xC0u,	0x0u,	
	0xFFu,	0x80u,	0x7u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0xFFu,	0x0u,	0x0u,	0x0u,	0x0u,	0xFEu,	0xC0u,	0x22u,	0x0u,	0x27u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0xFEu,	0xE8u,	0x1Eu,	0x0u,	0x0u,	
	0xFFu,	0xE8u,	0x1u,	0x20u,	0x0u,	0xFFu,	0xD8u,	0x1u,	0x3u,	0x0u,	
	0x0u,	0x7u,	0xC6u,	0x0u,	0x0u,	0xFFu,	0x8u,	0x0u,	0x0u,	0x0u,	
	0xFFu,	0xF4u,	0x0u,	0x20u,	0x0u,	0xFFu,	0xD8u,	0x7u,	0x2u,	0x0u,	
	0xFDu,	0xA5u,	0x8u,	0x20u,	0x0u,	0x0u,	0x0u,	0x0u,	0xE2u,	0x0u,	
	0xFDu,	0xADu,	0x8u,	0x20u,	0x0u,	0x0u,	0x8u,	0x0u,	0xE2u,	0x0u,	
	0xFDu,	0x25u,	0x8u,	0x20u,	0x0u,	0x0u,	0x10u,	0x0u,	0xE2u,	0x0u,	
	0xFDu,	0x2Du,	0x8u,	0x20u,	0x0u,	0x0u,	0x18u,	0x0u,	0xE2u,	0x0u,	
	0x0u,	0x5u,	0x8u,	0x20u,	0x0u,	0xFDu,	0x60u,	0x0u,	0xE2u,	0x0u,	
	0x0u,	0xDu,	0x8u,	0x20u,	0x0u,	0xFDu,	0x68u,	0x0u,	0xE2u,	0x0u,	
	0x0u,	0x15u,	0x8u,	0x20u,	0x0u,	0xFDu,	0xB0u,	0x0u,	0xE2u,	0x0u,	
	0x0u,	0x1Du,	0x8u,	0x20u,	0x0u,	0xFDu,	0xB8u,	0x0u,	0xE2u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0xFEu,	0x30u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0xFEu,	0xC0u,	0xFu,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_40_Data[32] =
{
	0x0u,	0x0u,	0x10u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	
	0x0u,	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_41_Data[6] =
{
	0x0u,	0x0u,	0x0u,	0x0u,	0x0u,	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_42_Data[1] =
{
	0x1u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_43_Data[1] =
{
	0x1u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_44_Data[1] =
{
	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_FF_39_45_Data[1] =
{
	0x3u	
};

ADI_A2B_MEM_PERI_CONFIG_UNIT
static	ADI_A2B_PERI_CONFIG_UNIT gaPeriCfg_FF_39_Unit[46] =
{
	{A2B_WRITE_OP,	0x2u,	0x40D0u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_0_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40D1u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_1_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40C1u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_2_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40C2u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_3_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40C3u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_4_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40EBu,	0x1u,	0x1u,	&gaPeriCfg_FF_39_5_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40F6u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_6_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x4000u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_7_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x4002u,	0x1u,	0x6u,	&gaPeriCfg_FF_39_8_Data[0]},
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_FF_39_9_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x4015u,	0x1u,	0x2u,	&gaPeriCfg_FF_39_10_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x4011u,	0x1u,	0x4u,	&gaPeriCfg_FF_39_11_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x4008u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_12_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x4009u,	0x1u,	0x8u,	&gaPeriCfg_FF_39_13_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x4019u,	0x1u,	0x3u,	&gaPeriCfg_FF_39_14_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x401Cu,	0x1u,	0xEu,	&gaPeriCfg_FF_39_15_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x4017u,	0x1u,	0x2u,	&gaPeriCfg_FF_39_16_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x402Au,	0x1u,	0x3u,	&gaPeriCfg_FF_39_17_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x402Du,	0x1u,	0x1u,	&gaPeriCfg_FF_39_18_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x402Fu,	0x1u,	0x2u,	&gaPeriCfg_FF_39_19_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x4031u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_20_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x800u,	0x1u,	0x3FCu,	&gaPeriCfg_FF_39_21_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x8CCu,	0x1u,	0x3FCu,	&gaPeriCfg_FF_39_22_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x998u,	0x1u,	0x3FCu,	&gaPeriCfg_FF_39_23_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0xA64u,	0x1u,	0x3FCu,	&gaPeriCfg_FF_39_24_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0xBFCu,	0x1u,	0xFu,	&gaPeriCfg_FF_39_25_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40E9u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_26_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40F5u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_27_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40C0u,	0x1u,	0x5u,	&gaPeriCfg_FF_39_28_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40C6u,	0x1u,	0x4u,	&gaPeriCfg_FF_39_29_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40E9u,	0x1u,	0x2u,	&gaPeriCfg_FF_39_30_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40D0u,	0x1u,	0x5u,	&gaPeriCfg_FF_39_31_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40EBu,	0x1u,	0x1u,	&gaPeriCfg_FF_39_32_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40F2u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_33_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40F3u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_34_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40F4u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_35_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40F7u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_36_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40F8u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_37_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40F9u,	0x1u,	0x2u,	&gaPeriCfg_FF_39_38_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x800u,	0x1u,	0x113u,	&gaPeriCfg_FF_39_39_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x0u,	0x1u,	0x20u,	&gaPeriCfg_FF_39_40_Data[0]},
	{A2B_READ_OP,	0x2u,	0x4002u,	0x1u,	0x6u,	&gaPeriCfg_FF_39_41_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40EBu,	0x1u,	0x1u,	&gaPeriCfg_FF_39_42_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x40F6u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_43_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x4036u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_44_Data[0]},
	{A2B_WRITE_OP,	0x2u,	0x4036u,	0x1u,	0x1u,	&gaPeriCfg_FF_39_45_Data[0]}
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_1_19_0_Data[4] =
{
	0xAu,	0x0u,	0x0u,	0x0u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA
static	uint8 gaPeriCfg_1_19_1_Data[1] =
{
	0x64u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA
static	uint8 gaPeriCfg_1_19_2_Data[4] =
{
	0x1u,	0x0u,	0x0u,	0x0u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA
static	uint8 gaPeriCfg_1_19_3_Data[1] =
{
	0x1u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA
static	uint8 gaPeriCfg_1_19_4_Data[4] =
{
	0x1u,	0x0u,	0x0u,	0x0u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA
static	uint8 gaPeriCfg_1_19_5_Data[1] =
{
	0x0u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA
static	uint8 gaPeriCfg_1_19_6_Data[4] =
{
	0xAu,	0x0u,	0x0u,	0x0u
};

ADI_A2B_MEM_PERI_CONFIG_UNIT
static	ADI_A2B_PERI_CONFIG_UNIT gaPeriCfg_1_19_Unit[7] =
{
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_1_19_0_Data[0]},
	{A2B_WRITE_OP,	0x1u,	0x2Eu,	0x1u,	0x1u,	&gaPeriCfg_1_19_1_Data[0]},
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_1_19_2_Data[0]},
	{A2B_WRITE_OP,	0x1u,	0x30u,	0x1u,	0x1u,	&gaPeriCfg_1_19_3_Data[0]},
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_1_19_4_Data[0]},
	{A2B_WRITE_OP,	0x1u,	0x26u,	0x1u,	0x1u,	&gaPeriCfg_1_19_5_Data[0]},
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_1_19_6_Data[0]}
};

 ADI_A2B_MEM_PERI_CONFIG_DATA
static	uint8 gaPeriCfg_2_19_0_Data[4] =
{
	0xAu,	0x0u,	0x0u,	0x0u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA
static	uint8 gaPeriCfg_2_19_1_Data[1] =
{
	0x64u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA
static	uint8 gaPeriCfg_2_19_2_Data[4] =
{
	0x1u,	0x0u,	0x0u,	0x0u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA
static	uint8 gaPeriCfg_2_19_3_Data[1] =
{
	0x1u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA
static	uint8 gaPeriCfg_2_19_4_Data[4] =
{
	0x1u,	0x0u,	0x0u,	0x0u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA
static	uint8 gaPeriCfg_2_19_5_Data[1] =
{
	0x0u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA
static	uint8 gaPeriCfg_2_19_6_Data[4] =
{
	0xAu,	0x0u,	0x0u,	0x0u
};

ADI_A2B_MEM_PERI_CONFIG_UNIT
static	ADI_A2B_PERI_CONFIG_UNIT gaPeriCfg_2_19_Unit[7] =
{
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_2_19_0_Data[0]},
	{A2B_WRITE_OP,	0x1u,	0x2Eu,	0x1u,	0x1u,	&gaPeriCfg_2_19_1_Data[0]},
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_2_19_2_Data[0]},
	{A2B_WRITE_OP,	0x1u,	0x30u,	0x1u,	0x1u,	&gaPeriCfg_2_19_3_Data[0]},
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_2_19_4_Data[0]},
	{A2B_WRITE_OP,	0x1u,	0x26u,	0x1u,	0x1u,	&gaPeriCfg_2_19_5_Data[0]},
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_2_19_6_Data[0]}
};

 ADI_A2B_MEM_PERI_CONFIG_DATA
static	uint8 gaPeriCfg_6_19_0_Data[4] =
{
	0xAu,	0x0u,	0x0u,	0x0u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_6_19_1_Data[1] =
{
	0x64u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_6_19_2_Data[4] =
{
	0x1u,	0x0u,	0x0u,	0x0u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_6_19_3_Data[1] =
{
	0x1u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_6_19_4_Data[4] =
{
	0x1u,	0x0u,	0x0u,	0x0u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_6_19_5_Data[1] =
{
	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_6_19_6_Data[4] =
{
	0xAu,	0x0u,	0x0u,	0x0u
};

ADI_A2B_MEM_PERI_CONFIG_UNIT
static	ADI_A2B_PERI_CONFIG_UNIT gaPeriCfg_6_19_Unit[7] =
{
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_6_19_0_Data[0]},
	{A2B_WRITE_OP,	0x1u,	0x2Eu,	0x1u,	0x1u,	&gaPeriCfg_6_19_1_Data[0]},
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_6_19_2_Data[0]},
	{A2B_WRITE_OP,	0x1u,	0x30u,	0x1u,	0x1u,	&gaPeriCfg_6_19_3_Data[0]},
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_6_19_4_Data[0]},
	{A2B_WRITE_OP,	0x1u,	0x26u,	0x1u,	0x1u,	&gaPeriCfg_6_19_5_Data[0]},
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_6_19_6_Data[0]}
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_7_19_0_Data[4] =
{
	0xAu,	0x0u,	0x0u,	0x0u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_7_19_1_Data[1] =
{
	0x64u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_7_19_2_Data[4] =
{
	0x1u,	0x0u,	0x0u,	0x0u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_7_19_3_Data[1] =
{
	0x1u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_7_19_4_Data[4] =
{
	0x1u,	0x0u,	0x0u,	0x0u
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_7_19_5_Data[1] =
{
	0x0u	
};

 ADI_A2B_MEM_PERI_CONFIG_DATA 
static	uint8 gaPeriCfg_7_19_6_Data[4] =
{
	0xAu,	0x0u,	0x0u,	0x0u
};

ADI_A2B_MEM_PERI_CONFIG_UNIT
static	ADI_A2B_PERI_CONFIG_UNIT gaPeriCfg_7_19_Unit[7] =
{
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_7_19_0_Data[0]},
	{A2B_WRITE_OP,	0x1u,	0x2Eu,	0x1u,	0x1u,	&gaPeriCfg_7_19_1_Data[0]},
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_7_19_2_Data[0]},
	{A2B_WRITE_OP,	0x1u,	0x30u,	0x1u,	0x1u,	&gaPeriCfg_7_19_3_Data[0]},
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_7_19_4_Data[0]},
	{A2B_WRITE_OP,	0x1u,	0x26u,	0x1u,	0x1u,	&gaPeriCfg_7_19_5_Data[0]},
	{A2B_DEALY_OP,	0x0u,	0x0u,	0x1u,	0x4u,	&gaPeriCfg_7_19_6_Data[0]}
};
