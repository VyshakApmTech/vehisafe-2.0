#ifndef __N_GPS_C__
#define __N_GPS_C__
#include "r_cg_userdefine.h"

void GPS_UART_RX_1(unsigned int UART1_BUFFER);
void GPS_UART_RX_2(char UART1_BUFFER_2);
void GPS_UART_RX_3(unsigned int UART1_BUFFER_3);
void UPDATE_DEVICE_CONTROL_FRAME(void);
void LATITUDE_CONVERSION(void);
void LONGITUDE_CONVERSION(void);
void RTC_SET(void);
void GET_SPEED(unsigned int UART1_BUFFER);
void GPS_SLEEP_MODE(void);
void ADC_PRINT(void);
void GPS_UART_RX_4(unsigned int UART1_BUFFER_4);
void GET_GPS_DATA(void);
void GPS_NAVIGATION_MODE(void);
void GPS_STATIONARY_MODE(void);
void GPS_FULL_COLD_START(void);
void GPS_COLD_START(void);
void GPS_WARM_START(void);
void GPS_DATA_INTZ(void);
void GPS_FIX_INTERVAL(void);
void GPS_SATELLITE_ENABLE(void);
void GPS_STANDBY_MODE(void);
void GPS_NORMAL_MODE(void);
void GPS_START_MODE(void);
void GPS_UART_RX_5(unsigned int UART1_BUFFER_5);
#endif