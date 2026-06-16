#ifndef __N_GSM_C__
#define __N_GSM_C__

#include "r_cg_userdefine.h"

void SEND_AIS140_PVT(void);
void ACK_RX(unsigned int ct,unsigned int ack,unsigned int REDIAL,unsigned int WAIT_TIME);
void GSM_UART_RX(unsigned char UART0_BUFFER);
void GSM_INTZ(char MODE);
//void WELCOME_STRING(void);
void Auto_Read_Message_Intz(void);
void RESTART_MODEM(void);
void Enter(void);
//void UPDATE_SETTING(void);
void SYSTEM_STATUS(void);
void GET_NETWORK_NAME(void);
void GET_DEGREES(void);
void GPS_PRINT(void);
//void CONNECT_AND_SEND_TO_SERVER(void);
void UPDATE_ONLINE_DATA_FRAME(void);
void GET_SIGNAL_STRENGTH(void);
void DATA_PRINT(char FORMAT);
void FIRMWARE_DOWNLOAD_FROM_M95(void);
void CHEKSUM_CALC(void);
void EEPROM_FILE_WRITE(void);
void EEPROM_FILE_READ(void);
void GET_TIME(void);
void GET_SPEED_DATA(void);
void GET_IMEI(void);
void BAUD_RATE_AND_INITIAL_SETTINGS(void);
void GET_MCC_MNC_LAC_CELL_ID(void);
void Auto_Read_Message_Intz(void);
void NEW_SMS_READ(void);
void BATTERY_PERCENTAGE_CALCULATE(void);
void BOOT_STRING(void);
//void //DEVICE_REPLY_IN_SMS(unsigned char REPLY);
void PIN_CHECK(char x,char z);
void CMD_DATA_WRITE_IN_EEROM(char D);
void CMD_DATA_READ_IN_EEPROM(void);
void DATA_TO_ARRAY(void);
void PRINT_ZEROS_2(unsigned int q);
void SEND_COMMA_TO_ARRAY(void);
void FLASH_WRITE(void);
void READ_FLASH_MEM(void);
void CHIP_ERASE(void);
void SEctOR_ERASE(void);
void WAIT_UNTILL_FLASH_BUSY(void);
void SEND_WREN_COMMAND(void);
void SIX_FOUR_KB_ERASE(void);
void GPRS_DISCONNECT(void);
void PRINT_ZEROS(unsigned int q);
void LONGITUDE_CONVERSION(void);
void LATITUDE_CONVERSION(void);
void STORE_LAST_LOCATION(void);
void WELCOME_STRING(void);
void READ_LAST_LOCATION(void);	
void DEVICE_REPLY_IN_SMS(unsigned char REPLY);
void SwitchNetwork(void);
void InitM95(void);
//void IsSTKInit(unsigned int k);
void IsSTKInit(void);
//void SMS_CMD_DATA_UPL(unsigned int MSET);
#endif