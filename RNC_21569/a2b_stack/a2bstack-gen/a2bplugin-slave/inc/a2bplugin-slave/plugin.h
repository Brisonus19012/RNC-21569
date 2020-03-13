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
 * \file:   plugin.h
 * \author: Mentor Graphics, Embedded Software Division
 * \brief:  This is the definition of a A2B slave node plugin.
 *
 *=============================================================================
 */

/*============================================================================*/
/** 
 * \defgroup a2bplugin_slave_plugin         Slave Plugin Module
 *  
 * This is the definition of a A2B slave node plugin.
 *
 * \{ */
/*============================================================================*/

#ifndef A2B_SLAVE_PLUGIN_H
#define A2B_SLAVE_PLUGIN_H

/*======================= I N C L U D E S =========================*/

#include "a2bstack/inc/a2b/macros.h"
#include "platform/a2b/ctypes.h"
#include "a2bstack/inc/a2b/msgtypes.h"


/*======================= D E F I N E S ===========================*/

/*----------------------------------------------------------------------------*/
/** 
 * \defgroup a2bplugin_slave_cmd            Message Commands
 *  
 * Slave Plugin Specific Request Message Commands
 *
 * \{ */
/*----------------------------------------------------------------------------*/

/** Custom notification of a new DTC */
#define A2B_MSGNOTIFY_DTC     (A2B_MSGNOTIFY_CUSTOM + 1u)

/** Custom request for information associated with specific
 *  ODB-II Parameter ID
 */
#define A2B_MSGREQ_GET_PID    (A2B_MSGREQ_CUSTOM + 1u)

/** \} -- a2bplugin_slave_cmd */

/*----------------------------------------------------------------------------*/
/** 
 * \defgroup a2bplugin_slave_defs            Plugin Types/Defs
 *  
 * The various defines and data types used within the slave plugin modules.
 *
 * \{ */
/*----------------------------------------------------------------------------*/

/** The maximum size of a DTC buffer */
#define A2B_DTC_BUFFER_SIZE         (24u)


/*======================= D A T A T Y P E S =======================*/

A2B_BEGIN_DECLS

/* Forward Declarations */
struct a2b_PluginApi;

/**
 * The structure passed to the slave plugin containing the P-code (OBD-II
 * parameter identifier) to scan. The A2B_MSGREQ_GET_PID request message
 * is referenced via the 'args' field in the a2b_MsgReq_CustomHandle which
 * is the payload of the A2B_MSGREQ_GET_PID command. This same structure is
 * also sent as an unsolicited notification (A2B_MSGNOTIFY_DTC) when a new
 * DTC appears. The custom notification structure (a2b_MsgNotify_CustomHandle)
 * has an 'args' field which references this structure.
 */
typedef struct a2b_DtcInfo
{
    /**
     * The application specifies these fields on a request or it's filled in
     * on a notification.
     */

    /** OBD-II mode of operation */
    a2b_Byte    mode;

    /** OBD-II parameter identifier */
    a2b_Byte    pid;

    /**
     * The slave plugin returns this data associated with the P-code.
     */

    /** The maximum sized DTC buffer */
    a2b_Byte    buf[A2B_DTC_BUFFER_SIZE];

    /** The number of bytes actually used in the above buffer */
    a2b_UInt8   nBytes;

} a2b_DtcInfo;

/** \} -- a2bplugin_slave_defs */

/*======================= P U B L I C  P R O T O T Y P E S ========*/

/*----------------------------------------------------------------------------*/
/** 
 * \defgroup a2bplugin_slave_init       External Library API
 *  
 * This is the external entry point for the library (shared or archive).
 *
 * \{ */
/*----------------------------------------------------------------------------*/

/** The name of the plugin. Must be less than A2B_CONF_DEFAULT_PLUGIN_NAME_LEN
 * characters long (including A2B_NULL terminator). Should be chosen to be
 * unique from other plugins.
 */
#define A2B_SLAVE_PLUGIN_NAME     "A2B Slave Plugin"

#ifdef A2B_STATIC_PLUGIN
/* Static linking so this MUST be unique for each slave plugin that
 * is defined
 */

/* Give the option to override this name in case there is a naming conflict. */
#ifndef A2B_SLAVE_PLUGIN_INIT
#define A2B_SLAVE_PLUGIN_INIT     a2b_pluginSlaveInit
#endif

#else
/* Dynamically linked so name should not change since shared library
 * loader will look for this symbol name in the plugin shared library.
 */
#define A2B_SLAVE_PLUGIN_INIT     a2b_Slave_pluginInit
#endif

A2B_DSO_PUBLIC a2b_Bool A2B_CALL A2B_SLAVE_PLUGIN_INIT(
                                                    struct a2b_PluginApi* api);

/** \} -- a2bplugin_slave_init */

A2B_END_DECLS

/*======================= D A T A =================================*/

/** \} -- a2bplugin_slave_plugin */

#endif /* A2B_SLAVE_PLUGIN_H */
