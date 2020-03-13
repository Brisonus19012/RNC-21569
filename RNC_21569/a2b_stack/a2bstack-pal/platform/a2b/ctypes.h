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
 * \file:   ctypes.h
 * \author: Mentor Graphics, Embedded Software Division
 * \brief:  Basic A2B stack types.
 *
 *=============================================================================
 */

/*============================================================================*/
/** 
 * \defgroup a2bstack_ctypes        Stack C-Types
 *  
 * Basic A2B stack C-types (int/char/etc).
 *
 * \{ */
/*============================================================================*/

#ifndef A2B_CTYPES_H_
#define A2B_CTYPES_H_

/*======================= I N C L U D E S =========================*/

#include "a2bstack/inc/a2b/macros.h"
#include "platform/a2b/conf.h"
#include "platform/a2b/features.h"

/*======================= D E F I N E S ===========================*/

#ifndef A2B_FALSE
#define A2B_FALSE     (0U)
#endif

#ifndef A2B_TRUE
#define A2B_TRUE      (1u)
#endif

#ifndef A2B_IGNORE
#define A2B_IGNORE     (2u)
#endif

#define A2B_NULL              ((void*)0)
#define A2B_INVALID_HANDLE    A2B_NULL

/*======================= D A T A T Y P E S =======================*/

A2B_BEGIN_DECLS

#ifdef STD_C_C99

#include <stdint.h>
#include <stddef.h>
#include <string.h>

typedef unsigned char       a2b_UChar;
typedef char                a2b_Char;
#if defined (__ADSP214xx__)
typedef unsigned char       a2b_UInt8;
typedef signed char         a2b_Int8;
typedef short	            a2b_Int16;
typedef unsigned short      a2b_UInt16;
typedef unsigned char       uint8_t;
typedef signed char         int8_t;
typedef short	            int16_t;
typedef unsigned short      uint16_t;
#else	/* (__ADSP214xx__) */
typedef uint8_t             a2b_UInt8;
typedef int8_t              a2b_Int8;
typedef int16_t             a2b_Int16;
typedef uint16_t            a2b_UInt16;
#endif	/* (__ADSP214xx__) */
typedef int32_t             a2b_Int32;
typedef uint32_t            a2b_UInt32;
typedef size_t              a2b_Size;
typedef int                 a2b_Int;
typedef unsigned int        a2b_UInt;
#ifdef A2B_FEATURE_64_BIT_INTEGER
typedef int64_t             a2b_Int64;
typedef uint64_t            a2b_UInt64;
#endif

#else

typedef unsigned char       a2b_UChar;
typedef char                a2b_Char;
typedef unsigned char       a2b_UInt8;
typedef signed char         a2b_Int8;
typedef signed short        a2b_Int16;
typedef unsigned short      a2b_UInt16;
typedef signed int          a2b_Int32;
typedef unsigned int        a2b_UInt32;
typedef unsigned int        a2b_Size;
typedef int                 a2b_Int;
typedef unsigned int        a2b_UInt;
#ifdef A2B_FEATURE_64_BIT_INTEGER
typedef long long           a2b_Int64;
typedef unsigned long long int a2b_UInt64;
#endif

#endif

#if A2B_CONF_POINTER_SIZE == 64
#ifdef A2B_FEATURE_64_BIT_INTEGER
typedef a2b_UInt64          a2b_UIntPtr;
#else
typedef unsigned long long int a2b_UIntPtr;
#endif
#elif (A2B_CONF_POINTER_SIZE == 32) || (A2B_CONF_POINTER_SIZE == 24)
typedef a2b_UInt32          a2b_UIntPtr;
#elif A2B_CONF_POINTER_SIZE == 16
typedef a2b_UInt16          a2b_UIntPtr;
#else
typedef a2b_UInt8           a2b_UIntPtr;
#endif

typedef a2b_UChar           a2b_Bool;
typedef a2b_UInt8           a2b_Byte;
typedef void*               a2b_Handle;
typedef a2b_UInt32          a2b_HResult;


A2B_STATIC_ASSERT(sizeof(void*) <= sizeof(a2b_UIntPtr),
                    "data pointer must fit within integral type");

#ifdef A2B_FEATURE_64_BIT_INTEGER
#if defined (__ADSP214xx__)
/* Sizeof(long long) with -char-size-32 is equal to 2. Refer to CCES help for Sizeof */
A2B_STATIC_ASSERT(sizeof(a2b_Int64) == 2, "sizeof(a2b_Int64) != 8");
A2B_STATIC_ASSERT(sizeof(a2b_UInt64) == 2, "sizeof(a2b_UInt64) != 8");
#else	/* (__ADSP214xx__) */
/* Sizeof(long long) with -char-size-32 is equal to 8. Refer to CCES help for Sizeof */
A2B_STATIC_ASSERT(sizeof(a2b_Int64) == 8, "sizeof(a2b_Int64) != 8");
A2B_STATIC_ASSERT(sizeof(a2b_UInt64) == 8, "sizeof(a2b_UInt64) != 8");
#endif	/* (__ADSP214xx__) */
#endif

A2B_END_DECLS

/*======================= P U B L I C  P R O T O T Y P E S ========*/

/*======================= D A T A =================================*/

/** \} -- a2bstack_ctypes */

#endif /* A2B_CTYPES_H_ */
