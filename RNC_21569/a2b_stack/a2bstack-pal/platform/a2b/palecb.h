/*=============================================================================
 *
 * Project: a2bstack
 *
 * Copyright (c) 2015 - Analog Devices Inc. All Rights Reserved.
 * This software is subject to the terms and conditions of the license set 
 * forth in the project LICENSE file. Downloading, reproducing, distributing or 
 * otherwise using the software constitutes acceptance of the license. The 
 * software may not be used except as expressly authorized under the license.
 *
 *=============================================================================
 *
 * \file:   palecb.h
 * \author: Mentor Graphics, Embedded Software Division
 * \brief:  Platform specific extensions to the environment control block (ECB).
 *
 *=============================================================================
 */

/*============================================================================*/
/** 
 * \defgroup a2bstack_palecb        PAL ECB
 *  
 * Platform specific extensions to the environment control block (ECB).
 *
 * \{ */
/*============================================================================*/

#ifndef A2B_PALECB_H_
#define A2B_PALECB_H_

/*======================= I N C L U D E S =========================*/

#include "a2bstack/inc/a2b/macros.h"
#include "platform/a2b/ctypes.h"

#ifndef A2B_QAC
#if defined(__ADSP214xx__)
#include "adi_a2b_twi_internal.h"
#include "adi_a2b_twidriver.h"
#include "adi_a2b_framework.h"
#include "adi_a2b_busconfig.h"
#else	/* defined(__ADSP214xx__) */
#include "a2bstack-protobuf/inc/adi_a2b_busconfig.h"
#include "a2bstack-protobuf/inc/bdd_pb2.pb.h"
#include "adi_a2b_framework.h"
#endif	/* defined(__ADSP214xx__) */
#endif /* A2B_QAC */
#ifdef __ADSPBF7xx__
#include "a2bstack/inc/a2b/msgtypes.h"
#endif	/* __ADSPBF7xx__ */

/*======================= D E F I N E S ===========================*/


/*======================= D A T A T Y P E S =======================*/

A2B_BEGIN_DECLS

/*======================= P U B L I C  P R O T O T Y P E S ========*/
typedef struct a2b_PalEcb
{
#ifndef A2B_QAC

	/* Empty for the non-platform specific case. The contents of this type
     * definition should be replaced by a target/platform specific
     * implementation.
     */
	a2b_Handle                       i2chnd;
	ADI_A2B_TIMER_HANDLER            oTWITimer;
	ADI_A2B_TWI_CONFIG               oTWIConfig;
	ADI_A2B_TIMER_HANDLER            oTimerHandler;
	uint64_t                         nCurrTime;
	a2b_Int32						 nChainIndex;
#if defined(A2B_FEATURE_SEQ_CHART) || defined(A2B_FEATURE_TRACE)
	A2B_LOG_INFO                   oLogConfig[A2B_TOTAL_LOG_CH];
#endif
	/*! Table to get peripheral configuration structure */
	ADI_A2B_NODE_PERICONFIG *pAudioHostDeviceConfig;
#else
	a2b_Handle                       i2chnd;
#endif /* A2B_QAC */

} a2b_PalEcb;

A2B_END_DECLS

/*======================= D A T A =================================*/

/** \} -- a2bstack_palecb */

#endif /* A2B_PALECB_H_ */
