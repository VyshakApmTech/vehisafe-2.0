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
	* File Name    : r_main.c
	* Version      : CodeGenerator for RL78/G13 V2.05.05.01 [25 Nov 2020]
	* Device(s)    : R5F100FG
	* Tool-Chain   : CCRL
	* Description  : This file implements main function.
	* Creation Date: 10/23/2021
	***********************************************************************************************************************/

	/***********************************************************************************************************************
	Includes
	***********************************************************************************************************************/
	#include "r_cg_macrodriver.h"
	#include "r_cg_cgc.h"
	#include "r_cg_port.h"
	#include "r_cg_intc.h"
	#include "r_cg_serial.h"
	#include "r_cg_adc.h"
	#include "r_cg_timer.h"
	#include "r_cg_wdt.h"
	#include "r_cg_rtc.h"
	/* Start user code for include. Do not edit comment generated here */
	/* End user code. Do not edit comment generated here */
	#include "r_cg_userdefine.h"

	/***********************************************************************************************************************
	Pragma directive
	***********************************************************************************************************************/
	/* Start user code for pragma. Do not edit comment generated here */
	/* End user code. Do not edit comment generated here */

	/***********************************************************************************************************************
	Global variables and functions
	***********************************************************************************************************************/
	/* Start user code for global. Do not edit comment generated here */
	unsigned int UPDATE_TIME,WATCH_DOG_KILL,t_count,MINUTE;
	_Bool BOOT_FLAG,RTC_DONE,ONCE_RESTART,EEPROM_WORKING,IGNITION_CONTROL_STATE,LOW_BATTER_ALERT_SEND,SYSTEM_READY,FIRMWARE_UPDATE,GPS_RMC_DATA_RX,GPS_GGA_DATA_RX,GPS_VTG_DATA_RX,POWER_SOURCE,WELCOME_STRING_FRAME;
	char PANIC_ALERT_PACKET,IGNITION_ON_PACKET,IGNITION_OFF_PACKET,POWER_SOURCE_PACKET,LOW_BATTERY_ALERT_PACKET,PANIC_ALERT=OFF,IGNITION;
	extern unsigned int CURRENT_FRM_VERSION,FLASH_MEMORY;
	extern _Bool GPS_RST_FLAG,VLT_STARTUP_INITIAL,SMS_CMD_REPLY,SET_OTA_UPDATE,ACTIVATION_CMD_1,GPS_STANDBY,WATCH_DOG_FORCE_KILL,VLT_STARTUP,SMS_CMD_DATA_UPLOAD;
	extern char GPS_DIRECTION_DATA_VALID,INITIAL_MESSAGE;
	unsigned int a,b,c,d,z,l,a0,p;
	extern unsigned int Ax,Ay,Az,Gx,Gy,Gz;
	extern uint8_t FLASH_STATUS[10];
	void READ_DEVICE_ID(void);
	void CMD_DATA_WRITE_IN_EEROM(char D);
	void CMD_DATA_READ_IN_EEPROM(void);
	void convert(unsigned long int i)
	{
		
		l=i/10000;
		a0=i%10000;
	        a=a0/1000;
		z=i%1000;
		b=z/100;
		i=z%100;
		c=i/10;
		d=i%10;
		
		R_UART2_SEND_User(0x30+l);
		R_UART2_SEND_User(0x30+a);
		R_UART2_SEND_User(0x30+b);
		R_UART2_SEND_User(0x30+c);
		R_UART2_SEND_User(0x30+d);
		R_UART2_SEND(" , ");NOP();
	}

	/* End user code. Do not edit comment generated here */
	void R_MAIN_UserInit(void);

	/***********************************************************************************************************************
	* Function Name: main
	* Description  : This function implements main function.
	* Arguments    : None
	* Return Value : None
	***********************************************************************************************************************/
	void main(void)
	{
	    R_MAIN_UserInit();
	    /* Start user code. Do not edit comment generated here */
	    
	    while (1U)
	    {
		GET_GPS_DATA();
		    
	    /////if(GPS_STANDBY==OFF){WATCHDOG_ON();GET_GPS_DATA();WATCHDOG_OFF();}
	    if(GPS_DIRECTION_DATA_VALID==ON && GPS_STANDBY==OFF){WATCHDOG_ON();RTC_SET();WATCHDOG_OFF();}
	    
	            
	          NEW_SMS_READ();
		    VLT_RUNNING_MODE();
		//   ACC_GYRO_READ();
		    WATCHDOG_OFF();
		    SYSTEM_ALERT_CHECK();
		    //UPDATE_SETTING();
	//UPDATE_ONLINE_DATA_FRAME_1();
	//UPDATE_ONLINE_DATA_FRAME();
	     	    
		    


	    }
	    /* End user code. Do not edit comment generated here */
	}

	/***********************************************************************************************************************
	* Function Name: R_MAIN_UserInit
	* Description  : This function adds user code before implementing main function.
	* Arguments    : None
	* Return Value : None
	***********************************************************************************************************************/
	void R_MAIN_UserInit(void)
	{
	    /* Start user code. Do not edit comment generated here */
	    EI();
	    WATCHDOG_OFF();
	    
	    GPRS_PS_EN=OFF1;
	    P0_bit.no0=P0_bit.no1=OFF;
	    GPS_PWR_EN=ON;
	    RED_LED=ON;
	    HOOTER=ON;
	  //  //i2c_writen(0xA0,0XFE,0X01,0X00);MS_TIMER(100);
	    //BLUE_LED=ON;
	    SMS_CMD_REPLY=CLR;
	    IGNITION_CONTROL=ON;
	    R_TAU0_Channel2_Start();
	    WATCH_DOG_FORCE_KILL=OFF;
	    WATCH_DOG_KILL=CLR;
	    //MS_TIMER(1000);
	    P0_bit.no0=P0_bit.no1=ON;
	    WATCHDOG_ON();
	    WDTE = 0xACU;
	    R_UART1_Start();
	    R_UART2_Start();
	    R_CSI00_Start();
	    R_RTC_Start();
	    R_TAU0_Channel0_Start();
	    R_ADC_Create();R_ADC_Start();R_ADC_Set_OperationOn();R_ADC_Start();
	    PM3_bit.no1=1;
	    PM5_bit.no0=1;
	     WATCHDOG_ON();
	    R_INTC1_Start();
	    R_INTC3_Start();
	    R_INTC4_Start();
	   // ACC_GRY_INTZ();
	   // ACC_GYRO_READ();
	   R_UART1_SEND("$PSTMSRR\r\n");MS_TIMER(500);
	    GPS_RST=ON;//HAVE TO CHANGE NEW CIRCUIT PIN PORT
	    //GPS_RST_FLAG=CLR;
	    GPS_RST_FLAG=OFF;
	    MS_TIMER(500);
	    GPS_RST=OFF;
	    FLASH_HOLD=FLASH_WP=HIGH;
	    WATCHDOG_OFF();
	    WELCOME_STRING_FRAME=OFF;
	    BOOT_FLAG=1;
	    MAIN_PS_EN=ON;
	    POWER_SOURCE=ON;
	    WATCHDOG_ON();
	    READ_DEVICE_ID();
	    CHIP_ERASE();
	    MS_TIMER(100);
	    //MS_TIMER(1);
	    /// R_UART1_SEND("$PSTMCOLD\r\n");MS_TIMER(1);
	    INITIAL_MESSAGE=0x01;//i2c_readn(0xA0,0XFF,0X05);MS_TIMER(100);
	    //CURRENT_FRM_VERSION=i2c_readn(0xA0,0XFE,0X01);MS_TIMER(5);
	    CURRENT_FRM_VERSION=151;
	    WATCHDOG_OFF();
	    RED_LED=OFF;
	    GPRS_PS_EN=ON1;
	    MS_TIMER(1500);
	    R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n ");
	    MS_TIMER(500);
	    R_UART2_SEND("AT+QSTK?\r\n");
	MS_TIMER(500);
	QSTK();
	    R_UART2_SEND("AT+CRSM=214,28539,0,0,12,\"FFFFFFFFFFFFFFFFFFFFFFFF\"\r\n");
	     MS_TIMER(300);
	    POWER_SOURCE=ON;
	    VLT_STARTUP=SET;
	    VLT_STARTUP_INITIAL=SET;
	    IGNITION_CONTROL_STATE=ON;
	    FLASH_HOLD=FLASH_WP=ON;
	    VLT_STARTUP=ON;
	    //ACC_GRY_INTZ();
	    //ACC_GYRO_READ();
	        R_UART2_SEND("AT\r\n");ACK_RX(20,2,10,1);
	    MS_TIMER(300);
	     R_UART2_SEND("AT+CBC\r\n");ACK_RX(20,2,10,1);
	    MS_TIMER(300);
	         R_UART2_SEND("AT+CFUN=1\r\n");
	    MS_TIMER(300);
	    R_UART2_SEND("AT+CREG=0\r\n");
	    MS_TIMER(300);
	     R_UART2_SEND("AT+QSPN?\r\n");
	    MS_TIMER(300);
	   // SwitchNetwork();
	    R_UART2_SEND("AT+QCCID\r\n");
	    MS_TIMER(300);
	     R_UART2_SEND("AT+COPS=?\r\n");
	     
	    MS_TIMER(2000);
	      R_UART2_SEND("AT+CREG?\r\n");
	    MS_TIMER(300);
	    GET_IMEI();
	   
	   // R_UART2_SEND("AT+GSN\r\n");
	   //  MS_TIMER(300);
	   // GSM_INTZ(SMS_MODE);
	    GET_IMEI();
	     R_UART2_SEND("AT\r\n");ACK_RX(20,2,10,1);
	    MS_TIMER(300);
	     R_UART2_SEND("AT\r\n");ACK_RX(20,2,10,1);
	    MS_TIMER(300);
	         GET_IMEI();
		  GET_IMEI();
	   CMD_DATA_READ_IN_EEPROM();
	//    
	    //R_UART1_Start();
	    t_count=0;
	    //while(GPS_RMC_DATA_RX==OFF && t_count<=60){NOP();}
	   // R_UART1_Stop();
	//FLASH_MEMORY=10;
	    
	//    


	//    //if(GPS_DIRECTION_DATA_VALID==OFF){WATCHDOG_ON();GPS_RST=ON;MS_TIMER(100);GPS_RST=OFF;WATCHDOG_OFF();}
	////    while(1)
	////    {
	////    ACC_GYRO_READ();
	////    }
	    
	    /* End user code. Do not edit comment generated here */
	}

	/* Start user code for adding. Do not edit comment generated here */

	void READ_DEVICE_ID(void)
	{
	MS_TIMER(5);FLASH_CE=0;
	R_CSI00_SEND(0x90);//R_CSI00_SEND(0x00);R_CSI00_SEND(0x00);R_CSI00_SEND(0x00);						// READ COMMAND
	R_CSI00_SEND(0x00);					// READ-ADDRESS-1
	R_CSI00_SEND(0x00);			// READ-ADDRESS-2
	R_CSI00_SEND(0x00);					// READ-ADDRESS-3
	R_CSI00_Send_Receive(FLASH_STATUS,1,FLASH_STATUS);
	//R_CSI00_Send_Receive(0x90,6,Flash_Status);
	MS_TIMER(100);FLASH_CE=1;		
	}
	/* End user code. Do not edit comment generated here */
