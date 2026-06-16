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
* File Name    : r_cg_timer_user.c
* Version      : CodeGenerator for RL78/G13 V2.05.05.01 [25 Nov 2020]
* Device(s)    : R5F100FG
* Tool-Chain   : CCRL
* Description  : This file implements device driver for TAU module.
* Creation Date: 10/23/2021
***********************************************************************************************************************/


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_timer.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
//#pragma interrupt r_tau0_channel0_interrupt(vect=INTTM00)
//#pragma interrupt r_tau0_channel1_interrupt(vect=INTTM01)
///#pragma interrupt r_tau0_channel2_interrupt(vect=INTTM02)
//#pragma interrupt r_tau0_channel3_interrupt(vect=INTTM03)
//#pragma interrupt r_tau0_channel4_interrupt(vect=INTTM04)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
extern int Seconds;
extern unsigned int MINUTE_OFF,MINUTE_ON,Milli_Seconds,WATCH_DOG_KILL,MINUTE,P_D_L,MM;
extern unsigned int t_count,INTERUPT_COUNT_TIMER,MAIN_BATTERY_VOLTAGE,ADC_BUFFER,BACKUP_BATTERY_VOLTAGE,Micro_Seconds,PANIC_TIME,PANIC_ALERT_TIME,HEALTH_ALERT_TIME;
char SELECTION,WATCH_DOG;
extern char GPS_DIRECTION_DATA_VALID,BATTERY_MEASUREMENT,PANIC_ALERT_PACKET,PANIC_ALERT;
extern char PANIC_CONTROL_STATE;
unsigned int HOOTER_COUNT,ADC_COUNT,RTC_UPDATE,CHECKING,GPS_RESET_COUNT,BLINK_COUNT,T_SECONDS,T_MINUTE,T_HOUR,PANIC_COUNT,I_HOURS;
extern _Bool PANIC_CONTROL_STATE_1,RTC_DONE,PANIC_TIME_START,SMS_CMD_REPLY,PANIC_TIME_STOP;
extern _Bool GPS_STANDBY,WATCH_DOG_FORCE_KILL,POWER_BATTERY;
 char MAIN_BAT_STATUS;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_tau0_channel0_interrupt
* Description  : This function is INTTM00 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/


/***********************************************************************************************************************
* Function Name: r_tau0_channel3_interrupt
* Description  : This function is INTTM03 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/


/***********************************************************************************************************************
* Function Name: TIMER 0 INTERRUPT
* Description  : 1-S P-LOW
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_tau0_channel0_interrupt (void)   
{
	//    MINUTE_OFF++;
	//	MINUTE_ON++;
	MINUTE++;
	    //if(MINUTE>=3600){MINUTE=CLR;I_HOURS++;}
	//GREEN_LED=~GREEN_LED;
	//     if(MINUTE_OFF>=300){MINUTE_OFF=CLR;
	//    GREEN_LED=~GREEN_LED;I_HOURS++;}	
}

/***********************************************************************************************************************
* Function Name: TIMER 1 INTERRUPT
* Description  : 10-MS P-LEVEL 2
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_tau0_channel1_interrupt (void)
{
	    Milli_Seconds++;
	    
}

/***********************************************************************************************************************
* Function Name: TIMER 2 INTERRUPT
* Description  : 100-MS P-LOW
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_tau0_channel2_interrupt (void)
{
	
	
	
	CHECKING++;
    //ACC_GYRO_READ();
    t_count++;
    BLINK_COUNT++;
    HOOTER_COUNT++;
    //WATCH_DOG_KILL++;
    ADC_COUNT++;
    RTC_UPDATE++;
    if(GPS_DIRECTION_DATA_VALID==OFF && GPS_STANDBY==OFF){GPS_RESET_COUNT++;}
    else{GPS_RESET_COUNT=0;}
    
    //if(RESET_SW==0){WATCH_DOG=NONE;}
    
    if(WATCH_DOG==OFF && WATCH_DOG_FORCE_KILL==OFF)
    {
     R_WDT_Restart();
    WATCH_DOG_KILL=OFF;
    }
    if(WATCH_DOG==ON && WATCH_DOG_KILL<=6000){
    R_WDT_Restart();
    }
    
   if(PANIC_ALERT_PACKET==ON || PANIC_ALERT==ON || PANIC_TIME_START==ON)
   {
	   if(BLINK_COUNT>=1){RED_LED=~RED_LED;BLINK_COUNT=CLR;}
	   if(HOOTER_COUNT>=1 && PANIC_TIME_STOP==OFF ){HOOTER=~HOOTER;HOOTER_COUNT=CLR;}
   }
   else
   {
   	   	if(BLINK_COUNT>=101 && GPS_DIRECTION_DATA_VALID==OFF){BLINK_COUNT=0;HOOTER_COUNT=0;RED_LED=OFF;}
	   else if(BLINK_COUNT>=115 && GPS_DIRECTION_DATA_VALID==ON){BLINK_COUNT=0;HOOTER_COUNT=0;RED_LED=OFF;}
           else if(BLINK_COUNT>=100){RED_LED=ON;} 
   }
    //INTERUPT_COUNT_TIMER++;
    //if(INTERUPT_COUNT_TIMER==50){R_INTC3_Start();}
 
    //MAIN_BATTERY_VOLTAGE=ADC_BUFFER/40.875; 
    
    
    if(BATTERY_MEASUREMENT==OFF)
    {
    if(ADC_COUNT>2)
    {
    ADC_COUNT=0;
    if(SELECTION==0)
    {
    MAIN_BATTERY_VOLTAGE=ADC_BUFFER/1.85796;
    if(MAIN_BATTERY_VOLTAGE<=40)
    {
    MAIN_BAT_STATUS=OFF;//POWER_BATTERY=OFF;
    }
    else
    {
    MAIN_BAT_STATUS=ON;//POWER_BATTERY=ON;
    }
    
    ADS=BACKUP_BATTERY;
    ADC_COUNT=0;
    SELECTION=1;
    }
    else{
    BACKUP_BATTERY_VOLTAGE=ADC_BUFFER-75;
    if(BACKUP_BATTERY_VOLTAGE>=440){BACKUP_BATTERY_VOLTAGE=440;}
    //BACKUP_BATTERY=ADC_BUFFER
    
    ADS=MAIN_BATTERY;
    SELECTION=0;
    }
    }
    }
	
    if(RTC_UPDATE>=36000){RTC_UPDATE=0;RTC_DONE=OFF;}
    if(PANIC_TIME_START==ON)
    {
	    PANIC_COUNT++;
	    if(PANIC_COUNT>=1200){PANIC_TIME++;PANIC_COUNT=CLR;}
	   // if(PANIC_TIME>=PANIC_ALERT_TIME)
	   if(PANIC_TIME>=1)
	    {
	            PANIC_CONTROL_STATE = ON;
	            PANIC_TIME=PANIC_TIME_START=CLR;
	            PANIC_TIME_STOP=ON;
	            HOOTER=ON;HOOTER_COUNT=CLR;
	            PANIC_CONTROL_STATE_1=OFF;
				
	    }
    }
    
    

}

/***********************************************************************************************************************
* Function Name: TIMER 3 INTERRUPT
* Description  : 5-MS P-LOW
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_tau0_channel3_interrupt (void)
{
	    Micro_Seconds++;
}
/* End user code. Do not edit comment generated here */
/***********************************************************************************************************************
* Function Name: TIMER 3 INTERRUPT
* Description  : 1-Second P-LOW
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_tau0_channel4_interrupt (void)
{
	   T_SECONDS++;
	   if(T_SECONDS>=60)
	   {
		   T_SECONDS=CLR;
		   T_MINUTE++;
		   if(T_MINUTE>=60){T_MINUTE=CLR;T_HOUR++;}
	   }
	   if(T_HOUR>=1)
	   {
		   SMS_CMD_REPLY=SET;
		   T_HOUR=CLR;
	   }
}
/* End user code. Do not edit comment generated here */
