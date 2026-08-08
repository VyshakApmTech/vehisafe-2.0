#ifndef __N_GSM_RESPONSE_HANDLE_C__
#define __N_GSM_RESPONSE_HANDLE__C__

#include "r_cg_userdefine.h"

extern void GSM_SMS_DIAG(void);
void GSM_INTZ(char MODE);
void NEW_SMS_READ(void);
void IsSTKInit(void);
void InitM95(void);
void SwitchNetwork(void);
//void SMS_CMD_DATA_UPL(unsigned int MSET);
void MANUAL_NET(unsigned int N);
//void QSTK(void);
//void CHECK_IP(unsigned int T);
#endif
