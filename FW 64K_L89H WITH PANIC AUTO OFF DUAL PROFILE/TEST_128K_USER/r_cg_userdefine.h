/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011, 2020 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_userdefine.h
* Version      : CodeGenerator for RL78/G13 V2.05.05.01 [25 Nov 2020]
* Device(s)    : R5F100FG
* Tool-Chain   : CCRL
* Description  : This file includes user definition.
* Creation Date: 10/23/2021
***********************************************************************************************************************/

#ifndef _USER_DEF_H
#define _USER_DEF_H

/***********************************************************************************************************************
User definitions
***********************************************************************************************************************/

/* Start user code for function. Do not edit comment generated here */
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_userdefine.h"
#include "r_cg_intc.h"
#include "r_cg_serial.h"
#include "r_cg_adc.h"
#include "r_cg_timer.h"
#include "r_cg_rtc.h"
#include "r_cg_wdt.h"


#include "N_GSM.h"
#include "N_DELAY.h"
#include "N_GPS.h"
#include "N_IIC.h"
#include "N_Serial.h"
#include "N_EEPROM.h"
#include "N_GSM_RESPONSE_HANDLE.h"
#include "FIRMWARE_HANDLING.h"
#include "V_Control.h"
#include "N_IEEPROM.h"
//#include "V_Control.h"

#define MAIN_PS_EN P12_bit.no0
#define GPS_RST P1_bit.no6
#define IGNITION_CONTROL P7_bit.no3
#define GPRS_PS_EN P14_bit.no7
#define MAIN_BATT P12_bit.no0
#define GREEN_LED P2_bit.no4
#define RED_LED P2_bit.no5
#define BLUE_LED P2_bit.no6
#define CHARGE_STATE P1_bit.no7
#define RESET_SW P1_bit.no0
#define IGNITION_SW P5_bit.no1
#define GPS_PWR_EN P5_bit.no0
#define FLASH_HOLD P7_bit.no1
#define HOOTER P7_bit.no2
#define FLASH_WP P1_bit.no5
#define FLASH_CE P14_bit.no6

#define ON  1
#define OFF 0
#define ON1  1
#define OFF1 0
#define NONE 2

#define SET  1
#define HIGH  1
#define CLR 0
#define LOW 0


#define OPEN 1
#define CLOSE 0

#define CTRL_Z 0x1A
#define D_SYM  0x02
#define MAIN_BATTERY 0x03
#define BACKUP_BATTERY 0x07
#define	SCL			P6_bit.no0              						// Port pin for SCL line
#define	SDA			P6_bit.no1     							// Port pin for SDA line
#define	SCL_Dir		        PM6_bit.no0                  						// DIRECTION bit for SCL line
#define	SDA_Dir		       PM6_bit.no1           						// DIRECTION bit for SDA line
#define _3200_UART1_TRANSMIT_DIVISOR     (0x3200U)

#define SMS_MODE	1
#define DATA_MODE	2

void r_tau0_channel2_interrupt (void);
void r_tau0_channel0_interrupt (void) ;
void r_tau0_channel1_interrupt (void);
void r_tau0_channel3_interrupt (void);
void r_tau0_channel4_interrupt (void);
void r_tau0_channel4_interrupt (void);
void r_adc_interrupt (void);
void r_csi00_interrupt (void);
void r_uart1_interrupt_receive (void);
void r_uart2_interrupt_receive (void);
void r_uart1_interrupt_send (void);
void r_uart2_interrupt_send (void);
void r_intc1_interrupt (void);
void r_intc3_interrupt (void);
void r_intc4_interrupt (void); 
void r_intc2_interrupt(void);
void WATCHDOG_ON(void);
void R_UART2_SEND_User(char x);
/* End user code. Do not edit comment generated here */
#endif