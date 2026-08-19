#ifndef __N_GSM_RESPONSE_HANDLE_C__
#define __N_GSM_RESPONSE_HANDLE__C__

#include "r_cg_userdefine.h"


//extern char PRIM_IP[16];
//extern char PRIM_PORT[6];
//extern unsigned char i;
extern char PROF_CMD_FRAME_RX;
extern char PROF_CMD_REPLY;
extern char TEMP_PROF;
extern char SETDEF_CMD_FRAME_RX,SETDEF_CMD_REPLY;
extern char SOSCLR_CMD_FRAME_RX,SOSCLR_CMD_REPLY;

extern char SOSTMO_CMD_FRAME_RX;
extern char SOSTMO_CMD_REPLY;
extern int TEMP_SOSTMO;
//extern unsigned int EMGT_TIME;

extern char SOSSET_CMD_REPLY;
extern char TEMP_SOS_NUM1[11];
extern char TEMP_SOS_NUM2[11];

extern char SETBTS_CMD_FRAME_RX;
extern char SETBTS_CMD_REPLY;
extern unsigned int TEMP_BTS;

extern char SETFOTA_CMD_FRAME_RX;
extern char SETFOTA_CMD_REPLY;
extern char TEMP_FOTA_IP[16];
extern char TEMP_FOTA_PORT[6];
extern char TEMP_FOTA_USER[16];
extern char TEMP_FOTA_PASS[16];
extern char TEMP_FOTA_FILE[32];

extern char GETPROF_CMD_FRAME_RX;
extern char GETPROF_CMD_REPLY;

extern char GETSOSTMO_CMD_FRAME_RX;
extern char GETSOSTMO_CMD_REPLY;

extern char GETVSTAT_CMD_FRAME_RX;
extern char GETVSTAT_CMD_REPLY;

extern char GETSRVDTL_CMD_FRAME_RX;
extern char GETSRVDTL_CMD_REPLY;

extern char GETLOC_CMD_FRAME_RX;
extern char GETLOC_CMD_REPLY;

extern char GETPANIC_CMD_FRAME_RX;
extern char GETPANIC_CMD_REPLY;

extern char GETVINFO_CMD_FRAME_RX;
extern char GETVINFO_CMD_REPLY;
extern char ICCID[22];
extern char ICCID_RX;


extern char INTVL_CMD_FRAME_RX;
extern char INTVL_CMD_REPLY;
extern unsigned int TEMP_TRC_INTVL;    // tracking interval
extern unsigned int TEMP_IGN_INTVL;    // ignition on interval
extern unsigned int TEMP_SOS_INTVL;    // SOS interval
extern unsigned int TEMP_STD_INTVL;    // standby interval
extern unsigned int TEMP_HLT_INTVL;    // health interval

extern char APN_INDEX;  // Dedicated index for APN reception (prevents VV collision)

void GSM_UART_RX(unsigned char UART0_BUFFER);
void ACK_RX(unsigned int ct,unsigned int ack,unsigned int REDIAL,unsigned int WAIT_TIME);
//void PIN_CHECK(char x,char z);
void CMD_DATA_WRITE_IN_EEROM(char D);
void CMD_DATA_READ_IN_EEPROM(void);
#endif