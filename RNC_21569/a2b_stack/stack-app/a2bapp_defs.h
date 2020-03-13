/*******************************************************************************
Copyright (c) 2016 - Analog Devices Inc. All Rights Reserved.
This software is proprietary & confidential to Analog Devices, Inc.
and its licensors.
******************************************************************************
* @file: a2bapp_defs.h
* @brief: This file contains Typedefs for various configuration parameters of stack
*         specific to this A2B application
* @version: $Revision: 3888 $
* @date: $Date: 2016-01-17 18:46:38 +0530 (Sun, 17 Jan 2016) $
* Developed by: Automotive Software and Systems team, Bangalore, India
*****************************************************************************/

#ifndef __A2BAPP_DEFS_H__
#define __A2BAPP_DEFS_H__

/*============= I N C L U D E S =============*/
/*============= D E F I N E S =============*/
/* Add your custom header content here */


/* DEFAULT TRACE LEVEL */
#define A2B_CONF_DEFAULT_TRACE_LVL		(A2B_TRC_DOM_ALL | A2B_TRC_LVL_DEBUG | A2B_TRC_LVL_INFO | A2B_TRC_LVL_DEFAULT)
/* DEFAULT TRACE FILE */
#define A2B_CONF_DEFAULT_TRACE_CHAN_URL     "..//a2b_trace.txt"

/* DEFAULT SEQUENCE CHART FILE */
#define A2B_CONF_DEFAULT_SEQCHART_CHAN_URL     "..//SequenceFile.txt"

/* #define A2B_PRINT_CONSOLE */

/* #define ENABLE_SUPERBCF */

#endif /* __A2BAPP_DEFS_H__ */
