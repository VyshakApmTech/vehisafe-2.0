#ifndef __N_Serial_C__
#define __N_Serial_C__

#include "r_cg_userdefine.h"

void R_UART1_Send_1_User(char x);

void R_UART2_SEND(const char *b);
void R_UART1_SEND(const char *b);

void R_CSI00_SEND(char x);
void CSI00_READ_INT(void);
unsigned char CSI00_READ(void);

void SEND_TO_ARRAY(const char *b);
void SEND_TO_ARRAY_Value(char b);


#endif