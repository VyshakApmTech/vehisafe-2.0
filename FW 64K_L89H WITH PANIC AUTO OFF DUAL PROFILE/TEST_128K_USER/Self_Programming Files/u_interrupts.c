#include "iodefine.h"
#pragma interrupt watchdog_intrpt(vect=INTWDTI)
#pragma interrupt  lvi_intrpt(vect=INTLVI)
#pragma interrupt  intp0_intrpt(vect=INTP0)
#pragma interrupt  intp1_intrpt(vect=INTP1)
#pragma interrupt  intp2_intrpt(vect=INTP2)
#pragma interrupt  intp3_intrpt(vect=INTP3)
#pragma interrupt  intp4_intrpt(vect=INTP4)
#pragma interrupt  intp5_intrpt(vect=INTP5)
#pragma interrupt  intst2_interrupt(vect=INTST2) 
#pragma interrupt  intsr2_interrupt(vect=INTSR2) 
#pragma interrupt  intsre2_interrupt(vect=INTSRE2)
////////////////DMA//////////////
////////////////DMA//////////////
#pragma interrupt  intst0_interrupt(vect=INTST0)
#pragma interrupt  intsr0_interrupt(vect=INTSR0)
#pragma interrupt  intsre0_interrupt(vect=INTSRE0)
#pragma interrupt   intst1_interrupt(vect=INTST1)
#pragma interrupt  intsr1_interrupt(vect=INTSR1)
#pragma interrupt  intsre1_interrupt(vect=INTSRE1)
#pragma interrupt  intsic_interrupt(vect=INTIICA0)
#pragma interrupt  inttm00_interrupt(vect=INTTM00)
#pragma interrupt  inttm01_interrupt(vect=INTTM01)
#pragma interrupt  inttm02_interrupt(vect=INTTM02)
#pragma interrupt  inttm03_interrupt(vect=INTTM03)
#pragma interrupt    intad_interrupt(vect=INTAD)
#pragma interrupt   intrtc_interrrupt(vect=INTRTC)
#pragma interrupt    intit_interrrupt(vect=INTIT)
#pragma interrupt    intkr_interrupt(vect=INTKR)
//////////////UART3/////////////
//////////////UART3/////////////
//#pragma interrupt INTTM13 inttm13_interrupt
#pragma interrupt  inttm04_interrupt(vect=INTTM04)
#pragma interrupt  inttm05_interrupt(vect=INTTM05)
#pragma interrupt  inttm06_interrupt(vect=INTTM06)
#pragma interrupt  inttm07_interrupt(vect=INTTM07)
//#pragma interrupt INTP6   intp6_interrupt
//#pragma interrupt INTP7   intp7_interrupt
//#pragma interrupt INTP8   intp8_interrupt
//#pragma interrupt INTP9   intp9_interrupt
//#pragma interrupt INTP10  intp10_interrupt
//#pragma interrupt INTP11  intp11_interrupt
//#pragma interrupt INTIICA1	inticca_interrupt
#pragma interrupt 		intfl_interrupt(vect=INTFL)
//------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "r_cg_macrodriver.h"
#include "r_cg_serial.h"
#include "u_ram_vector.h"
#include "r_cg_userdefine.h"
#include "r_cg_timer.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


 static void __near watchdog_intrpt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTWDTI_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near lvi_intrpt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTLVI_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intp0_intrpt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTP0_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intp1_intrpt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTP1_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intp2_intrpt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTP2_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intp3_intrpt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTP3_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intp4_intrpt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTP4_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intp5_intrpt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTP5_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intst2_interrupt (void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTST2_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intsr2_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTSR2_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intsre2_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTSRE2_ISR)();
    /* End user code. Do not edit comment generated here */
}

////////////////DMA//////////////
////////////////DMA//////////////

 static void __near intst0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTST0_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intsr0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTSR0_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intsre0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTSRE0_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intst1_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTST1_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intsr1_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTSR1_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intsre1_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTSRE1_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intsic_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTIICA0_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near inttm00_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTTM00_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near inttm01_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTTM01_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near inttm02_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTTM02_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near inttm03_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTTM03_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intad_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTAD_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intrtc_interrrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTRTC_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intit_interrrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTIT_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intkr_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTKR_ISR)();
    /* End user code. Do not edit comment generated here */
}


// static void __near inttm13_interrupt(void)
//{
//    /* Start user code. Do not edit comment generated here */
//    (*RAM_INTTM13_ISR)();
//    /* End user code. Do not edit comment generated here */
//}


 static void __near inttm04_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTTM04_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near inttm05_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTTM05_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near inttm06_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTTM06_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near inttm07_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTTM07_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intp6_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTP6_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intp7_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTP7_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intp8_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTP8_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intp9_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTP9_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intp10_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTP10_ISR)();
    /* End user code. Do not edit comment generated here */
}


 static void __near intp11_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTP11_ISR)();
    /* End user code. Do not edit comment generated here */
}


// static void __near inticca_interrupt(void)
//{
//    /* Start user code. Do not edit comment generated here */
//    (*RAM_INTIICA1_ISR)();
//    /* End user code. Do not edit comment generated here */
//}


 static void __near intfl_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    (*RAM_INTFL_ISR)();
    /* End user code. Do not edit comment generated here */
}


