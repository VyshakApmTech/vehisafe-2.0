#ifndef __N_GSM_RESPONSE_HANDLE_C__
#define __N_GSM_RESPONSE_HANDLE__C__

#include "r_cg_userdefine.h"

void GSM_UART_RX(unsigned char UART0_BUFFER);
void ACK_RX(unsigned int ct,unsigned int ack,unsigned int REDIAL,unsigned int WAIT_TIME);
void PIN_CHECK(char x,char z);
void CMD_DATA_WRITE_IN_EEROM(char D);
void CMD_DATA_READ_IN_EEPROM(void);
#endif