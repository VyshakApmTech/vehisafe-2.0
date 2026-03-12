/* RENESAS OPTIMIZING LINKER GENERATED FILE 2016.02.03 */
/*** variable information ***/
#pragma saddr gp_uart1_tx_address /* count:4,size:2,near,r_cg_serial.obj */
#pragma saddr g_uart1_tx_count /* count:4,size:2,near,r_cg_serial.obj */
#pragma saddr g_uart1_rx_count /* count:4,size:2,near,r_cg_serial.obj */
#pragma saddr gp_uart1_rx_address /* count:3,size:2,near,r_cg_serial.obj */
#pragma saddr g_uart1_rx_length /* count:3,size:2,near,r_cg_serial.obj */
#pragma saddr RAM_INTST1_ISR /* count:4,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTSR1_ISR /* count:4,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTTM00_ISR /* count:4,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTWDTI_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTLVI_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTP0_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTP1_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTP2_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTP3_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTP4_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTP5_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTST2_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTSR2_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTSRE2_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTST0_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTSR0_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTSRE0_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTSRE1_ISR /* count:2,size:4,near,My_ram_vector.obj */
/* #pragma saddr RAM_INTIICA0_ISR */ /* count:0,size:4,near,unref,My_ram_vector.obj */
#pragma saddr RAM_INTTM01_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTTM02_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTTM03_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTAD_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTRTC_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTIT_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTKR_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTST3_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTSR3_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTTRJ0_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTTM10_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTTM11_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTTM12_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTTM13_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTP6_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTP7_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTP8_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTP9_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTP10_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTP11_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTTRD0_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTTRD1_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTTRG_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTSRE3_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTIICA1_ISR /* count:2,size:4,near,My_ram_vector.obj */
#pragma saddr RAM_INTFL_ISR /* count:2,size:4,near,My_ram_vector.obj */
/* #pragma saddr send_buf */ /* count:1,size:17,near,r_main.obj */

/*** function information ***/
#pragma callt r_INTTM00_interrupt /* count:2,far,r_main.obj */
#pragma callt r_INTST1_interrupt /* count:2,far,r_cg_serial_user.obj */
#pragma callt r_INTSR1_interrupt /* count:2,far,r_cg_serial_user.obj */
#pragma callt R_CGC_Get_ResetSource /* count:1,far,r_cg_cgc_user.obj */
#pragma callt hdwinit /* count:1,far,r_systeminit.obj */
#pragma callt R_INTC8_Start /* count:1,far,r_cg_intc.obj */
#pragma callt R_INTC9_Start /* count:1,far,r_cg_intc.obj */
#pragma callt R_INTC10_Start /* count:1,far,r_cg_intc.obj */
#pragma callt R_PORT_Create /* count:1,far,r_cg_port.obj */
#pragma callt R_SAU0_Create /* count:1,far,r_cg_serial.obj */
#pragma callt R_TAU0_Channel0_Start /* count:1,far,r_cg_timer.obj */
#pragma callt R_CGC_Create /* count:1,far,r_cg_cgc.obj */
#pragma callt R_Systeminit /* count:1,far,r_systeminit.obj */
#pragma callt R_UART1_Send /* count:1,far,r_cg_serial.obj */
#pragma callt R_UART1_Start /* count:1,far,r_cg_serial.obj */
#pragma callt main /* count:1,far,r_main.obj */
#pragma callt R_TAU0_Create /* count:1,far,r_cg_timer.obj */
#pragma callt R_INTC_Create /* count:1,far,r_cg_intc.obj */
#pragma callt R_UART1_Create /* count:1,far,r_cg_serial.obj */
/* #pragma callt R_MAIN_UserInit */ /* count:0,far,unref,r_main.obj */
/* #pragma callt R_INTC8_Stop */ /* count:0,far,unref,r_cg_intc.obj */
/* #pragma callt R_INTC9_Stop */ /* count:0,far,unref,r_cg_intc.obj */
/* #pragma callt R_INTC10_Stop */ /* count:0,far,unref,r_cg_intc.obj */
/* #pragma callt R_TAU0_Channel0_Stop */ /* count:0,far,unref,r_cg_timer.obj */
/* #pragma callt R_UART1_Receive */ /* count:0,far,unref,r_cg_serial.obj */
/* #pragma callt R_UART1_Stop */ /* count:0,far,unref,r_cg_serial.obj */
/* #pragma callt r_INTWDTI_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTLVI_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTP0_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTP1_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTP2_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTP3_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTP4_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTP5_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTST2_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTSR2_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTSRE2_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTST0_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTSR0_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTSRE0_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTST1_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTSR1_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTSRE1_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTTM00_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTTM01_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTTM02_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTTM03_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTAD_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTRTC_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTIT_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTKR_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTST3_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTSR3_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTTRJ0_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTTM10_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTTM11_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTTM12_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTTM13_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTP6_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTP7_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTP8_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTP9_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTP10_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTP11_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTTRD0_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTTRD1_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTTRG_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTSRE3_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTIICA1_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */
/* #pragma callt r_INTFL_interrupt */ /* count:0,near,unref,interrupt,static,My_interrupts.obj */

