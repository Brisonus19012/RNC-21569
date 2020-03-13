/*
 **
 ** Source file generated on Feb 6, 2018 at 16:27:21.
 **
 ** Copyright (C) 2019 Analog Devices Inc., All Rights Reserved.
 **
 ** This file is generated automatically based upon the options selected in 
 ** the twi configuration dialog. Changes to this configuration should be made by
 ** changing the appropriate options rather than editing this file.
 **
 */

/** @addtogroup TWI_Driver TWI Device Driver
 *  @{
 */
 
  /** @addtogroup TWI_Driver_Static_Configuration TWI Device Driver Static Configuration
 *  @{

  Static Configuration: Using this configuration application can configure the control registers
  parameters upfront which can be set to default before TWI data transfer starts. This configuration
  has macros which can be configured through adi_twi_config_2156x.h file which by default is available
  with TWI driver. Example project can maintain a copy of it locally for custom configuration.
  In the default static configuration, TWI0/1/2 instances are enabled and PRESCALE is configured
  according to preload SYSCLOCK and set in fast mode.
*/

/*!
* @file      adi_twi_config_2156x.h
*
* @brief     TWI driver static configuration Header file
*
* @details
*            TWI driver static configuration Header file
*/
#ifndef __ADI_TWI_CONGIF_2156X_H__
#define __ADI_TWI_CONFIG_2156X_H__

#include <sys/platform.h>
#include <stdint.h>

/*!TWI0 Instance*/
/*!Select TWI0 Instance */
#define ADI_TWI0_INSTANCE                     		0u

/*! Specifies the Prescale value for internal time reference*/
#define ADI_TWI0_CTL_PRESCALE              	 	  	(12u)
/*! Specifies the TWI clock frequency in kHz*/
#define ADI_TWI0_CLK_FREQ              	 	 	  	(400u)
/*! Specifies the TWI clock duty cycle */
#define ADI_TWI0_DUTY_CYCLE              	 	  	(50u)
/*! Specifies the TWI Master Address register Configuration */
#define ADI_TWI0_MSTRADDR_ADDR 				 	 	(255u)
/*! Specifies the TWI Slave address register Configuration */
#define ADI_TWI0_SLVADDR_ADDR				     	(255u)



/*!TWI1 Instance*/
/*!Select TWI1 Instance */
#define ADI_TWI1_INSTANCE                     		0u

/*! Specifies the Prescale value for internal time reference*/
#define ADI_TWI1_CTL_PRESCALE              	 	  	(12u)
/*! Specifies the TWI clock frequency in kHz*/
#define ADI_TWI1_CLK_FREQ              	 	 	  	(400u)
/*! Specifies the TWI clock duty cycle */
#define ADI_TWI1_DUTY_CYCLE              	 	  	(50u)
/*! Specifies the TWI Master Address register Configuration */
#define ADI_TWI1_MSTRADDR_ADDR 				 	 	(255u)
/*! Specifies the TWI Slave address register Configuration */
#define ADI_TWI1_SLVADDR_ADDR				     	(255u)


/*!TWI2 Instance*/
/*!Select TWI2 Instance */
#define ADI_TWI2_INSTANCE                    		 0u

/*! Specifies the Prescale value for internal time reference*/
#define ADI_TWI2_CTL_PRESCALE              	 	  	(12u)
/*! Specifies the TWI clock frequency in kHz*/
#define ADI_TWI2_CLK_FREQ              	 	 	  	(100u)
/*! Specifies the TWI clock duty cycle */
#define ADI_TWI2_DUTY_CYCLE              	 	  	(50u)
/*! Specifies the TWI Master Address register Configuration */
#define ADI_TWI2_MSTRADDR_ADDR 				 	 	(104u)
/*! Specifies the TWI Slave address register Configuration */
#define ADI_TWI2_SLVADDR_ADDR				     	(105u)


#if defined(__ADSP21569_FAMILY__)
/*!TWI3 Instance*/
/*!Select TWI3 Instance */
#define ADI_TWI3_INSTANCE                    		 0u

/*! Specifies the Prescale value for internal time reference*/
#define ADI_TWI3_CTL_PRESCALE              	 	  	(12u)
/*! Specifies the TWI clock frequency in kHz*/
#define ADI_TWI3_CLK_FREQ              	 	 	  	(400u)
/*! Specifies the TWI clock duty cycle */
#define ADI_TWI3_DUTY_CYCLE              	 	  	(50u)
/*! Specifies the TWI Master Address register Configuration */
#define ADI_TWI3_MSTRADDR_ADDR 				 	 	(255u)
/*! Specifies the TWI Slave address register Configuration */
#define ADI_TWI3_SLVADDR_ADDR				     	(255u)


#if !defined(__ADSP21562__) && !defined(__ADSP21563__) && !defined(__ADSP21565__)
/*!TWI4 Instance*/
/*!Select TWI4 Instance */
#define ADI_TWI4_INSTANCE                    		 0u

/*! Specifies the Prescale value for internal time reference*/
#define ADI_TWI4_CTL_PRESCALE              	 	  	(12u)
/*! Specifies the TWI clock frequency in kHz*/
#define ADI_TWI4_CLK_FREQ              	 	 	  	(400u)
/*! Specifies the TWI clock duty cycle */
#define ADI_TWI4_DUTY_CYCLE              	 	  	(50u)
/*! Specifies the TWI Master Address register Configuration */
#define ADI_TWI4_MSTRADDR_ADDR 				 	 	(255u)
/*! Specifies the TWI Slave address register Configuration */
#define ADI_TWI4_SLVADDR_ADDR				     	(255u)


/*!TWI5 Instance*/
/*!Select TWI5 Instance */
#define ADI_TWI5_INSTANCE                    		 0u

/*! Specifies the Prescale value for internal time reference*/
#define ADI_TWI5_CTL_PRESCALE              	 	  	(12u)
/*! Specifies the TWI clock frequency in kHz*/
#define ADI_TWI5_CLK_FREQ              	 	 	  	(400u)
/*! Specifies the TWI clock duty cycle */
#define ADI_TWI5_DUTY_CYCLE              	 	  	(50u)
/*! Specifies the TWI Master Address register Configuration */
#define ADI_TWI5_MSTRADDR_ADDR 				 	 	(255u)
/*! Specifies the TWI Slave address register Configuration */
#define ADI_TWI5_SLVADDR_ADDR				     	(255u)

#endif
#endif
#endif /*__ADI_TWI_CONFIG_2156X_H__*/

/*@}*/

/*@}*/

