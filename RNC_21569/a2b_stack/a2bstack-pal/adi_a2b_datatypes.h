/*******************************************************************************
Copyright (c) 2014 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
******************************************************************************
* @file: adi_a2b_datatypes.h
* @brief: This file contains typoedefs for basic data types used in A2B framework
* @date: $Date: 2015-07-21 09:58:13 +0530 (Tue, 21 Jul 2015) $
* Developed by: Automotive Software and Systems team, Bangalore, India
*****************************************************************************/

/*! \addtogroup Basic_Types Basic Types
* @{
*/

#ifndef _ADI_A2B_DATA_TYPES_H_
#define _ADI_A2B_DATA_TYPES_H_

/*============= I N C L U D E S =============*/
#include "platform/a2b/ctypes.h"
/*============= D E F I N E S =============*/

/*! Internal memory code sections */
#define ADI_MEM_A2B_CODE_CRIT               __attribute__ ((section ("seg_l1_block3")))
/*! External memory code sections */
#define ADI_MEM_A2B_CODE_NO_CRIT            __attribute__ ((section ("seg_l1_block2")))
/*! Internal memory data sections */
#define ADI_MEM_A2B_DATA_CRIT_CAHE          __attribute__ ((section ("seg_l1_block1")))
/*! Internal memory data sections */
#define ADI_MEM_A2B_DATA_CRIT_NO_CACHE      __attribute__ ((section ("seg_l2_bsz_data")))
/*! External memory data sections */
#define ADI_MEM_A2B_DATA_NO_CRIT            __attribute__ ((section ("seg_l1_block1")))
/*! Graph data section  */
#define ADI_A2B_MEM_BCF_DATA                __attribute__ ((section ("seg_l2_uncached")))
/*! Graph data section  */
#define ADI_A2B_MEM_GRAPH_DATA              __attribute__ ((section ("seg_l2")))

#define ADI_A2B_DATA_MEM_ALIGN4 	        __attribute__ ((aligned (4)))

/*! Peripheral data  section  */
#define ADI_A2B_MEM_PERI_CONFIG_DATA        __attribute__ ((section ("seg_l2")))
/*! Peripheral configuration section  */
#define ADI_A2B_MEM_PERI_CONFIG_UNIT        __attribute__ ((section ("seg_l2")))


/* Storage classes */

#define STATIC          static

#define EXTERN          extern

#define VOLATILE        volatile

#define REGISTER        register

#define NULL_PTR        ((void *)0)


/*============= D A T A T Y P E S=============*/

typedef unsigned short uint16;

typedef unsigned int uint32;

typedef unsigned long long uint64;

typedef unsigned char uint8;

typedef short int16;

typedef long int32;

typedef long long int64;

typedef signed char int8;

/* Boolean */
#define TRUE  (1)

#define FALSE (0)

/*======= P U B L I C P R O T O T Y P E S ========*/



#endif /* _ADI_A2B_FRAMEWORK_H_ */

/** 
 @}
*/

/*
*
* EOF: $URL$
*
*/

