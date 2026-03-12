//#pragma section @@DATA RAM_VECT AT 0FFD00H	// RAM Vector Address of Bootloader and Application Program has to be matched
#pragma section bss RAM_VECT
#include "u_ram_vector.h"

void __near (*RAM_INTWDTI_ISR)();
void __near (*RAM_INTLVI_ISR)();
void __near (*RAM_INTP0_ISR)();
void __near (*RAM_INTP1_ISR)();
void __near (*RAM_INTP2_ISR)();
void __near (*RAM_INTP3_ISR)();
void __near (*RAM_INTP4_ISR)();
void __near (*RAM_INTP5_ISR)();
void __near (*RAM_INTST2_ISR)();
void __near (*RAM_INTSR2_ISR)();
void __near (*RAM_INTSRE2_ISR)();
 ////////////////DMA//////////////
 ////////////////DMA//////////////
void __near (*RAM_INTST0_ISR)();
void __near (*RAM_INTSR0_ISR)();
void __near (*RAM_INTSRE0_ISR)();
void __near (*RAM_INTST1_ISR)();
void __near (*RAM_INTSR1_ISR)();
void __near (*RAM_INTSRE1_ISR)();
void __near (*RAM_INTIICA0_ISR)();
void __near (*RAM_INTTM00_ISR)();
void __near (*RAM_INTTM01_ISR)();
void __near (*RAM_INTTM02_ISR)();
void __near (*RAM_INTTM03_ISR)();
void __near (*RAM_INTAD_ISR)();
void __near (*RAM_INTRTC_ISR)();
void __near (*RAM_INTIT_ISR)();
void __near (*RAM_INTKR_ISR)();
 //////////////UART3/////////////
 //////////////UART3/////////////
 //void __near (*RAM_INTTM13_ISR)();
void __near (*RAM_INTTM04_ISR)();
void __near (*RAM_INTTM05_ISR)();
void __near (*RAM_INTTM06_ISR)();
void __near (*RAM_INTTM07_ISR)();
void __near (*RAM_INTP6_ISR)();
void __near (*RAM_INTP7_ISR)();
void __near (*RAM_INTP8_ISR)();
void __near (*RAM_INTP9_ISR)();
void __near (*RAM_INTP10_ISR)();
void __near (*RAM_INTP11_ISR)();
//void __near (*RAM_INTIICA1_ISR)();
void __near (*RAM_INTFL_ISR)();
