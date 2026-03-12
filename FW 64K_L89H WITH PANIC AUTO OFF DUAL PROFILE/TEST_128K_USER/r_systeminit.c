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
* File Name    : r_systeminit.c
* Version      : CodeGenerator for RL78/G13 V2.05.05.01 [25 Nov 2020]
* Device(s)    : R5F100FG
* Tool-Chain   : CCRL
* Description  : This file implements system initializing function.
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
#include "u_ram_vector.h"
#include "iodefine.h" 
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
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Systeminit
* Description  : This function initializes every macro.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Systeminit(void)
{
    PIOR = 0x00U;
    R_CGC_Get_ResetSource();
    R_CGC_Create();
    R_PORT_Create();
    R_SAU0_Create();
    R_SAU1_Create();
    R_ADC_Create();
    R_TAU0_Create();
    R_WDT_Create();
    R_RTC_Create();
    R_INTC_Create();

    IAWCTL = 0x00U;
}


/***********************************************************************************************************************
* Function Name: hdwinit
* Description  : This function initializes hardware setting.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void hdwinit(void)
{
    DI();
    R_Systeminit();
    /* Start user code. Do not edit comment generated here */
        RAM_INTTM00_ISR = &r_tau0_channel0_interrupt;
    RAM_INTTM01_ISR = &r_tau0_channel1_interrupt;
    RAM_INTTM02_ISR = &r_tau0_channel2_interrupt;
    RAM_INTTM03_ISR = &r_tau0_channel3_interrupt;
    RAM_INTTM04_ISR = &r_tau0_channel4_interrupt;
    
    RAM_INTAD_ISR = &r_adc_interrupt;
    
    //RAM_INTRTC_ISR =&r_rtc_interrupt;
    
    RAM_INTST0_ISR = &r_csi00_interrupt;
    // RAM_INTST0_ISR = &CSI00_READ_INT;
    RAM_INTSR1_ISR = &r_uart1_interrupt_receive;
    RAM_INTSR2_ISR = &r_uart2_interrupt_receive;
    
    RAM_INTST1_ISR = &r_uart1_interrupt_send;
    RAM_INTST2_ISR = &r_uart2_interrupt_send;
    
    
    
    
    RAM_INTP1_ISR= &r_intc1_interrupt;
    RAM_INTP3_ISR= &r_intc3_interrupt;
    RAM_INTP4_ISR= &r_intc4_interrupt;
    RAM_INTP2_ISR= &r_intc2_interrupt;
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
