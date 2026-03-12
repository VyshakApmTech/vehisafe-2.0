#include "r_cg_userdefine.h"


char V_NO_LEN,VN_ACK_RX,PANIC_NUMBER_RX,TEMP_SET[255],TEMP_TCP[255],SET_TCP_FRAME_RX,SETTING_CMD_FRAME_RX,RX_ACK_Frame,ACK,ERROR_OCCURED,RX_SMS_CMD,t,SMS_FAIL_COUNT,SMS_FAIL,NETWORK_NAME_RX,BATTERY_MEASUREMENT,IGNITION_CTRL_RX,INITIAL_MESSAGE,P_LAT_DM_RX,FILE_CLOSE_ATTEMPT,GSM_REG,GPRS_REG/*,SS_DATA_RX*/,GET_SS,dBm,GPRS_CONNECTED,GSM_STRENGTH='5',INTERNET_CONNECTED,DISCONNECT,LOW_BATTERY_ALERT,HTTP_CONNECT_COUNT,NW_NAME_RX;
char i,SMS,NETWORK_FAILURE,HTTP_PRINT,SPEED_DATA[10],SS_DATA_RX,CPIN,P_TIME[10],P_SEND_TIME[10],P_SEND_LOG_DM[10],P_SEND_LAT_DM[10],FTP_ADDRESS[8],FTP_CONNECT_COUNT,FILE_ADDR,FIRMWARE_VERSION_RX,I[100];
char IMEI_EEPROM[16],PANIC_CTRL_RX,PANIC_CONTROL_STATE,PANIC_CONTROL_RX,FIRM_UPDATE_CTRL_RX,FIRM_UPDATE_CONTROL_STATE,FIRM_UPDATE_CONTROL_RX,FILE[150];
unsigned int K,TEMP_EMGT_TIME,FOR_1,FOR_3,Address_1,NW_REGN_COUNT,FLASH_MEMORY,GPRS_REG_COUNT,MAIN_BATTERY_VOLTAGE,ADC_BUFFER,BACKUP_BATTERY_VOLTAGE,GPRS_REG_ROAMING,GSM_REG_ROAMING,T_SPEED,FILTER,DATA_HEADER,TEMP_VERSION,CHECKSUM_BYTE,MN,VERSION_TEMP,FRM_VERSION,CURRENT_FRM_VERSION,HEX,TEMP_3,VOLT,TEMP_MAIN_BATTERY_VOLTAGE,J,RESTART;
unsigned long int FRAME_NUMBER,TEMP_FRAME_NUMBER,TEMP_FRM_VERSION;
extern unsigned int t_count,WRITE_ADDRESS,DATA,WATCH_DOG_KILL,WRITE_ADDRESS,TEMPS,WRITE_ADDRESS_MSB,WRITE_ADDRESS_LSB,BYTE;
extern char LOG_DM[10],LAT_DM[10],TIME[10],GPS_BUSY,SPEED[4],SPEED_DATA_RX[10],WATCH_DOG,GPS_DIRECTION_DATA_VALID,IGNITION,PANIC_ALERT,PANIC_ALERT_PACKET,IGNITION_ON_PACKET,IGNITION_OFF_PACKET,POWER_SOURCE_PACKET,LOW_BATTERY_ALERT_PACKET,HOURS_MSB,HOURS_LSB,MIN_MSB,MIN_LSB,LON_DIRECTION,LAT_DIRECTION,LAT_DM_RX[10],LOG_DM_RX[10],COG[6],GPGA_DATA[10],ALTITUDE[8],HDOP[5],NO_OF_SAT,NAVIGATION_ACK,NAVIGATION_RX,GPS_RESTART,FIRM_DATA[150],MAIN_BAT_STATUS;
_Bool GPS_RST_FLAG,DEVICE_RESTART_RX_1,WELCOME_STRING_FRAME_BOOT,SET_OTA_UPDATE,SETTING_CMD,SET_APN,SET_TCP,BSNL_CONNECT_FLAG,BSNL_CONNECT,CONNECT_FAIL,ALREADY_CONNECT,ALREADY_CONNECT_FLAG,QST_CMD_FLAG,HARSH_BRAKE_PACKET,HARSH_TURN_PACKET,HARSH_ACC_PACKET,BATTERY_CHARGED_PACKET,REFRESH,PRIMARY_IP,SECONDARY_IP,PRI_IP_PN_SMS,SEC_IP_PN_SMS,HEALTH_CMD2,DATA_SEND,k;
//extern unsigned int STP_DATA_RX,GET_STRPCI,STKPCI,GET_STP;
const char OK_ACK[2]={'O','K'},
ERROR_ACK[5]={'E','R','R','O','R'},
VODAFONE_ACK[15]={'+','C','O','P','S',':',' ','0',',','0',',','"','a','i','r'},
VODAFONE_ACK_V[15]={'+','C','O','P','S',':',' ','0',',','0',',','"','V','o','d'},
GET_IN_SMS[4]={'C','M','T',','},
CONNECT_ACK[7]={'C','O','N','N','E','C','T'},
CONNECT_FAIL_ACK[12]={'C','O','N','N','E','C','T',' ','F','A','I','L'},
ALREADY_CONNECT_ACK[15]={'A','L','R','E','A','D','Y',' ','C','O','N','N','E','C','T'},
SIGNAL_STRENGTH_ACK[5]={'C','S','Q',':',' '},
NW_DIS_CONNECT[9]={'P','D','P',' ','D','E','A','C','T'},
PANIC_MOBILE_NUMBER_ACK[18]={'S','E','T',' ','E','N','O',' ','I','M','E','I',' ','2','2','0','2','='},
HTTP_RESPONSE_FAIL[4]={'h','t','t','p',},
V_RESTART[3]={'V','R',':'},
VN_ACK[3]={'V','N',':'},
FIRM_UPDATE_CTRL[3]={'S','U',':'},
SETTINGS_UPDATE_CTRL[3]={'U','S',':'},
NETMODE_UPDATE_CTRL[3]={'N','M',':'},
PANIC_CTRL[4]={'P','S','A',':'},
IGNITION_CTRL[4]={'I','G','S',':'},
IMEI_ACK[9]={'A','T','+','G','S','N','\r','\r','\n'},
GSM_NW_REG[8]={'C','R','E','G',':',' ','0',','},
GPRS_NW_REG[9]={'C','G','R','E','G',':',' ','0',','},
CPIN_READY[11]={'C','P','I','N',':',' ','R','E','A','D','Y'},
HTTP_DOWNLOAD[8]={'Q','H','T','T','P','D','L',':'},
FTP_ADDRESS_ACK[8]={'Q','F','O','P','E','N',':',' '},
FILE_DOWNLOAD_ACK[8]={'C','O','N','N','E','C','T',' '},
SET_TCP_FRAME[8]={'S','E','T',' ','T','C','P',' '},
SETTING_CMD_FRAME[13]={'S','E','T',' ','S','E','T','T','I','N','G','S',' '},
ENGINEER_MODE_FRAME_1[9]={'Q','E','N','G',':',' ','0'},
ENGINEER_MODE_FRAME_2[10]={'Q','E','N','G',':',' ','1',',','1',','},
NEW_SMS_FRAME[11]={'C','M','T','I',':',' ','"','S','M','"',','},
PHONE_NUMBER_OF_SENDER_FRAME[23]={'C','M','G','R',':',' ','"','R','E','C',' ','U','N','R','E','A','D','"',',','"','+','9','1'},
GET_IMEI_SMS_CMD[13]={'G','E','T',' ','V','L','T',' ','I','M','E','I',' '},
DEVICE_RESET_CMD_FRAME[14]={'S','E','T',' ','V','L','T',' ','R','E','S','E','T',' '},
SET_APN_FRAME[8]={'S','E','T',' ','A','P','N',' '},
//SET_TCP_FRAME[8]={'S','E','T',' ','T','C','P',' '},
APN_S_FRAME[6]={'A','C','C','P','N',':'},
GET_SMS_FRAME[12]={'G','E','T',' ','S','E','T','T','I','N','G','S'},
GET_VERSION_CMD[12]={'G','E','T',' ','V','E','R','S','I','O','N',' '},
	
GET_ACT_MESSAGE[5]={'A','C','T','V',','},
GET_HEALTH_MESSAGE_FRAME[5]={'H','C','H','K',','},
PNET_CMD_FRAME[9]={'S','E','T',' ','P','N','E','T',' '},
SNET_CMD_FRAME[9]={'S','E','T',' ','S','N','E','T',' '},
NWA_CMD_FRAME[10]={'+','Q','S','P','N',':',' ','"','A','i'},
NWI_CMD_FRAME[10]={'+','Q','S','P','N',':',' ','"','V','o'},
NWS_CMD_FRAME[10]={'+','Q','S','P','N',':',' ','"','B','S'},
QST_CMD_FRAME[8]={'+','Q','S','T','K',':',' ','0'},
DEVICE_RESTART_ACK[12]={'V','L','T','_','R','e','s','t','a','r','t',':'},
GET_GPS_CLEAR_S_FRAME[9]={'G','P','S','C','L','E','A','R',':'},
NW_NAME_ACK[5]={'C','O','P','S',':'};
//GET_DEVICE_CLEAR_S_FRAME[7]={'C','L','R',' ','V','L','T'},
//SET_SLEEP_ON_FRAME[7]={'S','E','T',' ','S','N',' '},
//SET_SLEEP_OFF_FRAME[7]={'S','E','T',' ','S','F',' '},
//SET_OVERSPEED_FRAME[8]={'S','E','T',' ','O','S',' '};
//SET_VST_FRAME[7]={'S','E','T',' ','V','S'};


char
VEICHLE_NUMBER[15]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0'},
IMEI[16]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'},//={'8','6','8','3','2','4','0','2','6','3','7','0','8','7','6','8'},
Array_0[10]={'0','1','2','3','4','5','6','7','8','9'},
NETWORK_NAME[8]={'0','0','0','0','0','0','0','0'},
P_LAT_DM[10]={'0','0','0','0','0','0','0','0',},
P_LOG_DM[10]={'0','0','0','0','0','0','0','0',},
SMS_MOBILE_NO[52]={'9','9','9','9','9','9','9','9','9','9','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',},
REPLY_NUMBER[10]={'0','0','0','0','0','0','0','0','0','0'};


char HEALTH_CMD_FRAME_RX,SET_SETTINGS_FRAME_RX,HEALTH_ON_DURATON_RX,PANIC_ON_DURATON_RX,PANIC_ON_DURATON_S_RX,HEALTH_ON_DURATON_S_RX,APN_S_RX,TEMP_APN2[255],GET_SMS_RX,TEMP_PIP[16]={'1','0','3','.','1','2','9','.','9','8','.','1','9','4'},TEMP_PIP2[16]={'1','0','3','.','1','2','9','.','9','8','.','1','9','4'},GET_PIP_S_RX,TEMP_SIP[16]={'1','0','3','.','1','2','9','.','9','8','.','2','0','8'},TEMP_SIP2[16]={'1','0','3','.','1','2','9','.','9','8','.','2','0','8'},GET_SIP_S_RX,SET_PIP_PN_RX,SET_SIP_PN_RX,SET_SLEEP_ON_RX,SET_SLEEP_OF_RX,SET_OVERSPEED_RX,GET_OVER_SPEED_RX,GET_SLEEP_TIME_RX,GET_SLEEP_OFF_TIME_RX;
_Bool DECIMAL_POINT_CAME_STOP_TX,POWER_SOURCE_RECONNECT_PACKET,GET_MCC_MNC_LAC_CELL_ID_RX,ADD_ZERO_TO_SPEED,SMS_PIN_WRONG,NEW_SMS_RX_FRAME_RX,PHONE_NUMBER_OF_SENDER_RX,DEVICE_RESET_CMD_FRAME_RX,DEVICE_RESET_CMD,SERVER_UPDATE_TIME_CMD_FRAME_RX,SET_EMERGENCY_NUMBER_FRAME_CMD,SET_REGN_NUMBER_FRAME_CMD,UPDATE_EMERGENCY_NUMBER,UPDATE_IP,SET_IP_FRAME_CMD,URL_PRINT,MESSAGE_READ,SET_SLEEP_OFF_CMD,SET_SLEEP_ON_CMD,OVER_SPEED_CMD,GET_EMGT_TIME_CMD,ACTIVATION_CMD,HEALTH_AND_ACTIVATION_CMD;
_Bool PANIC_CONTROL_STATE_1,GSM_NW_REG_CHECK,GPRS_REG_CHECK,GET_SIGNAL_STRENGTH_CHECK,CPIN_READY_CHECK,DECIMAL_POINT,UPDATE_RP_NO,VLT_STARTUP,NORMAL_PACKET,DEVICE_CLEAR_CMD_FRAME_RX,DEVICE_CLEAR_CMD,HARSH_BRAKE_CMD_RX,HARSH_TURN_CMD_RX,HARSH_ACCEL_CMD_RX,HEALTH_ON_DURATON_CMD,PANIC_ON_DURATON_CMD,PANIC_TIME_START,PANIC_SERVER_COUNT,HEALTH_PACKET_TO_SERVER,GET_SMS_CMD,GET_PIP_CMD,GET_SIP_CMD,GET_PPT_S_CMD,GET_SPT_S_CMD;
extern _Bool VLT_STARTUP_INITIAL,BOOT_FLAG,FIRMWARE_UPDATE,IGNITION_CONTROL_STATE,POWER_SOURCE,SYSTEM_READY,WELCOME_STRING_FRAME,SET_SLEEP_ON_CMD,SET_SLEEP_OFF_CMD;
_Bool GPS_STANDBY,WATCH_DOG_FORCE_KILL,HTTP_DOWNLOAD_ACK,FTP_ACK,FTP_DOWNLOAD_ACK,FIRMWARE_DOWNLOADED,FILE_ACK,FILE_DOWNLOAD,FLAG,STOP_FILE_READING,IMEI_RX,IMEI_ACK_RX,DEVICE_RESTART_RX,HARSH_BRAKE_CMD,HARSH_TURN_CMD,HARSH_ACCEL_CMD;
int AD,resend;
char p1,p2,p3,p4,MCC_MNC_LAC_CELL_ID_LENGTH,FOR_7,ALTITUDE_VALUE_COUNT,NEW_SMS_INBOX_ADDRESS[20],NEW_SMS,PHONE_NUMBER_OF_SENDER[12],TEMP_REGN_NUMBER[15],TEMP_APN[15]={'s','e','n','s','e','m','2','m'},SET_APN_FRAME_RX,IGNITION_ON_TIME_RX,IGNITION_OFF_TIME_RX;
unsigned int URL_COUNT,VEICHLE_REG_COUNT,IGNITION_ON_UPDATE_TIME,IGNITION_OFF_UPDATE_TIME,UPDATE_TIME_ON_TIME,UPDATE_TIME_OFF_TIME,HEALTH_ON_DURATON_LEVEL,P_DL,PANIC_ALERT_TIME,PANIC_TIME,HEALTH_ALERT_TIME,APN_TEMP,HARSH_BRAKE_LEVEL,HARSH_TURN_LEVEL,HARSH_ACCEL_LEVEL,HT_LEVEL,HB_LEVEL,P_D_L,SLEEP_ON_LEVEL,SLEEP_OF_LEVEL,SLEEP_ON_LEVEL,SLEEP_OFF_LEVEL,OVER_SPEED,TEMP_OVS_LEVEL,SLEEP_OFF_TIME,TEMP_SLEEP_OFF_TIME,EMGT_TIME;
char ENGINEER_MODE_FRAME_1_ACK,P,MCC_MNC_LAC_CELL_ID[20],GSM_COMMA,GET_IMEI_SMS_CMD_RX,UPDATE_INTERVAL_CMD,HARSH_ACCEL_CMD_SMS_RX,HARSH_TURN_CMD_SMS_RX,HARSH_BRAKE_CMD_SMS_RX,HARSH_ACCEL_CMD_SMS_LEVEL,HARSH_TURN_CMD_SMS_LEVEL,HARSH_BRAKE_CMD_SMS_LEVEL;
extern unsigned int PDOP_DATA_RX[8];
char TEMP_EMERGENCY_NUMBER[5];
char DBM_1[5],LAC_1[5],CELL_ID_1[5],DBM_2[5],LAC_2[5],CELL_ID_2[5],DBM_3[5],LAC_3[5],CELL_ID_3[5],DBM_4[5],LAC_4[5],CELL_ID_4[5],N,GSM_COMMA_2,SPEED_DATA_LENGTH_COUNT,APN_LENGTH,COG_VALUE_COUNT,PDOP_COUNT,HDOP_COUNT;
_Bool GET_VLT_IMEI_PH_CMD,VERSION_CMD_SET,ENGINEER_MODE_FRAME_2_ACK,GET_NMR_RX,HEX_CHARACTER_CONVERSION,VERSION_CMD_SET,SMS_CMD_REPLY,VERSION_CMD_RX,SEND_IMEI,UPDATE_INTERVAL_CMD_2,SET_APN_FRAME_CMD,UPDATE_APN,UPDATE_REGISTRATION_NUMBER,UPDATE_INTERVAL_TIME_FOR_IGNITION_ON_CMD,UPDATE_INTERVAL_TIME_FOR_IGNITION_OFF_CMD,SMS_CMD_DATA_UPLOAD_UONT,SMS_CMD_DATA_UPLOAD,UPDATE_REGISTRATION_NUMBER_1,OTA_PACKET,PANIC_TIME_STOP,PRIMARY_PN,SECONDARY_PN,SLEEP_ON_TIME_CMD,SLEEP_OFF_TIME_CMD;

char LOW_BAT_LEVEL_RX,LOW_BAT_LEVEL_CMD,TEMP_PPN[4]={'9','0','0','0'},TEMP_PPN2[4]={'9','0','0','0'};
char GET_SPN_S_RX,TEMP_SPN[4]={'9','0','0','0'},TEMP_SPN2[4]={'9','0','0','0'},GET_SPN_S_RX;
char DBM_DATA_LENGTH[5],LAC_DATA_LENGTH[5],CELL_ID_DATA_LENGTH[5],MCC_1[5],MNC[5],LAC[5],CELL_ID[5],MCC_DATA_LENGTH,MNC_DATA_LENGTH,LAC_DATA_LENGTH_0,CELL_ID_DATA_LENGTH_0,SMS_CMD_FRAME_RX,GET_IMEI_SEND_CMD_RX,TEMP_IP[15],SET_IP_FRAME_RX,SET_RP_NO_FRAME_RX,SET_RP_NO_FRAME_CMD,VV,TEMP_RP_NO[12],REPLY_NUMBER_RX;
unsigned long int FLASH_WRITE_ADDRESS=1,FLASH_READ_ADDRESS,TEMP_FLASH_WRITE_ADDRESS,TEMP_FLASH_READ_ADDRESS,HEALTH_FRAME_NUMBER;
unsigned int updatedata,RECORD_ARRAY_ADDRESS=1,FLASH_BYTE=1,FLASH_WRITE_ADDRESS_1,FLASH_WRITE_ADDRESS_2,FLASH_WRITE_ADDRESS_3,FLASH_READ_ADDRESS_1,FLASH_READ_ADDRESS_2,FLASH_READ_ADDRESS_3,RLL,LOW_BAT_LEVEL,LB_LEVEL,SLEEP_ON_TIME,TEMP_SLEEP_ON_TIME;
char RECORD[180],HA_LEVEL,GET_PPN_S_RX,GET_DEVICE_CLEAR_S_RX;
_Bool FLASH_WRITING,GET_PPN_CMD,GET_SPN_CMD;
uint8_t RDSR[]={0x05};
uint8_t WRSR[]={0x01,0x00};
uint8_t WREN[]={0x06};
//uint8_t SECT_ERASE[]={0x20,0x00,0x00,0x00};
uint8_t CE[]={0x60}; 
uint8_t STATUS_REG[]={0x05};
uint8_t FLASH_STATUS[10];
//uint8_t SIX_FOUR_KB_ERASE_FR[]={0x20,0x00,0x00,0x00};
uint8_t READ[]={0x03,0x00,0x00,0x00};


//struct {
//   unsigned int widthValidated : 1;
//   unsigned int heightValidated : 1;
//} status2;
 
void GPRS_DISCONNECT(void)
{
restart5:
	  R_UART2_SEND("AT+QIDEACT\r\n");ACK=0;ERROR_OCCURED=0;ACK_RX(4000,2,100,10);if(RESTART==ON){RESTART=OFF;goto restart5;}
}


void UPDATE_SETTING(void)
{
	
		if(SETTING_CMD==1)
		{
			SETTING_CMD=CLR;
			
			
		}
		else if(SET_APN==1)
		
		{
			SET_APN=CLR;
			
		}
		
		else if(SET_TCP==1)
		{
			SET_TCP=CLR;
			
		}
		
		
			
	
	
}

void GET_SIGNAL_STRENGTH(void)
{
restart5:
	GET_SIGNAL_STRENGTH_CHECK=SET;
	R_UART2_SEND("AT+CSQ\r\n");
	ACK_RX(40,4,50,0);
	if(RESTART==ON){RESTART=OFF;goto restart5;}
	GSM_STRENGTH=dBm;
	GET_SIGNAL_STRENGTH_CHECK=CLR;
}
void GET_NETWORK_NAME(void)
{
	restart100:
	NETWORK_NAME_RX=ON;
	ACK=CLR;
	R_UART2_SEND("AT+COPS?\r\n");ACK_RX(40,2,50,0);
	//SwitchNetwork();
	if(RESTART==ON){RESTART=OFF;goto restart100;}
	
	NETWORK_NAME_RX=OFF;
}
/*void LATITUDE_CONVERSION(void)

{
     unsigned long int TEMP_LC1,TEMP_LC2,LATITUDE_MINUTES,Array[10];
     
unsigned int TEMP_LC3,FOR_2;
     
MS_TIMER(1);
     
LATITUDE_MINUTES=0X0F & LAT_DM_RX[2];
     
for(FOR_2=3;FOR_2<=7;FOR_2++){
     
LATITUDE_MINUTES=LATITUDE_MINUTES*10;
     
LATITUDE_MINUTES=(LATITUDE_MINUTES + (0X0F & LAT_DM_RX[FOR_2]));
     
}
 
TEMP_LC1=((((LAT_DM_RX[0]&0X0F)*10))+(LAT_DM_RX[1]&0X0F));
  
LATITUDE_MINUTES=((((LATITUDE_MINUTES/10000)/60)+TEMP_LC1)*1000000);
 
TEMP_LC1=(double)LATITUDE_MINUTES;
    
 TEMP_LC2=TEMP_LC1/10000000;
  
   LAT_DM[0]=Array[TEMP_LC2];
    
 TEMP_LC2=10000000;
     
for(FOR_2=1;FOR_2<=7;FOR_2++)
{
     TEMP_LC1=TEMP_LC1%TEMP_LC2;
  
   TEMP_LC2=TEMP_LC2/10;
    
 LAT_DM[FOR_2]=TEMP_LC1/TEMP_LC2;
  
   LAT_DM[FOR_2]=Array[LAT_DM[FOR_2]];
 
    }	    
 
}

void LONGITUDE_CONVERSION(void)

{
     unsigned long int TEMP_LO1,TEMP_LO2,LONGITUDE_MINUTES,Array[10];
   
  unsigned int TEMP_LO3,FOR_2;
     MS_TIMER(1);
  
   LONGITUDE_MINUTES=0X0F & LOG_DM_RX[3];
   
  for(FOR_2=4;FOR_2<=8;FOR_2++)
{
     LONGITUDE_MINUTES=LONGITUDE_MINUTES*10;
 
    LONGITUDE_MINUTES=(LONGITUDE_MINUTES + (0X0F & LOG_DM_RX[FOR_2]));
  
   }
     
     
TEMP_LO1=((((LOG_DM_RX[1]&0X0F)*10))+(LOG_DM_RX[2]&0X0F));
   
  LONGITUDE_MINUTES=((((LONGITUDE_MINUTES/10000)/60)+TEMP_LO1)*1000000);
   
  TEMP_LO1=(double)LONGITUDE_MINUTES;
  
   TEMP_LO2=TEMP_LO1/10000000;
   
  LOG_DM[0]=Array[TEMP_LO2];
   
  TEMP_LO2=10000000;
   
  for(FOR_2=1;FOR_2<=7;FOR_2++)
{
     
TEMP_LO1=TEMP_LO1%TEMP_LO2;
   
  TEMP_LO2=TEMP_LO2/10;
    
 LOG_DM[FOR_2]=TEMP_LO1/TEMP_LO2;
  
   LOG_DM[FOR_2]=Array[LOG_DM[FOR_2]];
  
   }
   
  
}*/

void DEVICE_REPLY_IN_SMS(unsigned char REPLY)
{
	unsigned int T;
	unsigned int FOR_0,O;
    // R_UART2_SEND("inside device reply in sms with reply value = ");
    // R_UART2_SEND_User(REPLY);
	
    if(REPLY==17)
	{
		// Send settings SMS to default number
		R_UART2_SEND("AT+CMGF=1\r\n");
		MS_TIMER(100);
		R_UART2_SEND("AT+CMGS=\"8939575036\"\r\n");
		MS_TIMER(100);
		R_UART2_SEND("SETTINGS:-");
		goto REPL_1;
	}

	else if(REPLY==200)
	{
		// Send VERSION SMS to default number
		R_UART2_SEND("AT+CMGF=1\r\n");
		MS_TIMER(100);
		R_UART2_SEND("AT+CMGS=\"8939575036\"\r\n");
		MS_TIMER(100);
		R_UART2_SEND("VERSION: 1.0.0");
		
		// Send Ctrl+Z to send the SMS
		R_UART2_SEND_User(CTRL_Z);
		
		// Wait for SMS send confirmation
		ACK_RX(2500,2,500,100);
		goto restart11;
	}

	else if(REPLY == 201)
	{
		// Send IMEI SMS to default number
		R_UART2_SEND("AT+CMGF=1\r\n");
		MS_TIMER(100);
		R_UART2_SEND("AT+CMGS=\"8939575036\"\r\n");
		MS_TIMER(100);
		R_UART2_SEND("IMEI: ");
		for(FOR_1=1; FOR_1<=15; FOR_1++)
		{
			R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);
		}
		
		// Send Ctrl+Z to send the SMS
		R_UART2_SEND_User(CTRL_Z);
		
		// Wait for SMS send confirmation
		ACK_RX(2500,2,500,100);
		goto restart11;
	}
/*****************************************************************************************************/
//DEVICE ACCEL - Send current HACL value via SMS
/*****************************************************************************************************/
else if(REPLY==11)
{
    unsigned int temp_value;  // Temporary variable
    REPL_8:
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);
    R_UART2_SEND("AT+CMGS=\"8939575036\"\r\n");
    MS_TIMER(100);
    
    R_UART2_SEND("H-ACCEL LEV:");
    
    // Read current value from EEPROM address 37
    temp_value = i2c_readn(0xA0, 0XFE, 37);
    MS_TIMER(2);
    
    // Convert to string and send digit by digit
    if(temp_value >= 100)
    {
        R_UART2_SEND_User(Array_0[temp_value/100]);
        temp_value = temp_value % 100;
    }
    if(temp_value >= 10)
    {
        R_UART2_SEND_User(Array_0[temp_value/10]);
        temp_value = temp_value % 10;
    }
    R_UART2_SEND_User(Array_0[temp_value]);
    
    // Send Ctrl+Z to send the SMS
    R_UART2_SEND_User(CTRL_Z);
    
    // Wait for SMS send confirmation
    ACK_RX(2500,2,500,100);
    
    goto restart11;
}

/*****************************************************************************************************/
//DEVICE HTRN - Send current HTURN value via SMS
/*****************************************************************************************************/
else if(REPLY==12)
{
	unsigned int temp_value;

	REPL_9:

	O=CLR;

	R_UART2_SEND("AT+CMGF=1\r\n");
	MS_TIMER(100);

	R_UART2_SEND("AT+CMGS=\"8939575036\"\r\n");
	MS_TIMER(100);

	R_UART2_SEND("H-TURN LEV:");

	temp_value = i2c_readn(0xA0,0XFE,38);  // Read from EEPROM location 38
	MS_TIMER(2);

	// Convert number to digits and send
	if(temp_value >= 100)
	{
		R_UART2_SEND_User(Array_0[temp_value/100]);
		temp_value = temp_value % 100;
	}

	if(temp_value >= 10)
	{
		R_UART2_SEND_User(Array_0[temp_value/10]);
		temp_value = temp_value % 10;
	}

	R_UART2_SEND_User(Array_0[temp_value]);

	R_UART2_SEND_User(CTRL_Z);

	ACK_RX(2500,2,500,100);

	goto restart11;
}
/*****************************************************************************************************/
//DEVICE HBRK - Send current HBRK value via SMS
/*****************************************************************************************************/
else if(REPLY == 13)  // Harsh Brake confirmation
{
    unsigned int temp_value;
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);
    R_UART2_SEND("AT+CMGS=\"8939575036\"\r\n");
    MS_TIMER(100);
    
    R_UART2_SEND("H-BRAKE LEV:");
    
    temp_value = i2c_readn(0xA0, 0XFE, 39);  // Read from EEPROM address 39
    MS_TIMER(2);
    
    // Convert to string and send digit by digit
    if(temp_value >= 100)
    {
        R_UART2_SEND_User(Array_0[temp_value/100]);
        temp_value = temp_value % 100;
    }
    if(temp_value >= 10)
    {
        R_UART2_SEND_User(Array_0[temp_value/10]);
        temp_value = temp_value % 10;	
    }
    R_UART2_SEND_User(Array_0[temp_value]);
    
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500,2,500,100);
    goto restart11;
}
/*****************************************************************************************************/
//DEVICE LBAT - Send current LOW BAT LEVEL via SMS
/*****************************************************************************************************/
else if(REPLY==16)
{
    unsigned int temp_value;

    REPL_13:
    O = CLR;

    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);
    R_UART2_SEND("AT+CMGS=\"8939575036\"\r\n");
    MS_TIMER(100);
    R_UART2_SEND("LOW-BAT-LEV:");

    temp_value = i2c_readn(0xA0,0XFE,46);
    MS_TIMER(2);

    // Single digit (1-9) - just send it directly
    R_UART2_SEND_User(Array_0[temp_value]);

    // Remove the "0%" or add it correctly
    // R_UART2_SEND("%");  // Optional: add % if needed

    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500,2,500,100);
    goto restart11;
}


/*****************************************************************************************************/
//REPLY==7 UPDATE APN
else if(REPLY==7)
{
REPL_5:
R_UART2_SEND("AT+CMGF=1\r\n");
APN_TEMP=200+APN_LENGTH;
R_UART2_SEND("APN:-");
J=CLR;
for(FOR_1=200;FOR_1<=APN_TEMP;FOR_1++)
{
T=i2c_readn(0xA0,0XFE,FOR_1);MS_TIMER(2);
R_UART2_SEND_User(T);NOP();
TEMP_APN[J]=T;
J++;
}
if(REPLY==17){R_UART2_SEND(",");goto REPL_7;}
}

/*****************************************************************************************************/
//REPLY==8 UPDATE EMERGENCY NUMBER
/*****************************************************************************************************/
else if(REPLY==8)
{
	//REPL_6:
	R_UART2_SEND("AT+CMGF=1\r\n");
	O=CLR;
	R_UART2_SEND("VLT EMER No:-");
	for(FOR_0=50;FOR_0<=99;FOR_0++)
	{
		MS_TIMER(1);
		T=i2c_readn(0xA0,0XFE,FOR_0);
		MS_TIMER(1);
		R_UART2_SEND_User(T);
		NOP();
		SMS_MOBILE_NO[O]=T;
		O++;
		if(O%10==0)
		{
			R_UART2_SEND(",");
		}
	}
	//if(REPLY==17){R_UART2_SEND(",");goto REPL_7;}
}

//REPLY==3 DEVICE RESTART
else if(REPLY==3)
{
	R_UART2_SEND("DEVICE WILL RESTART.");
	for(FOR_1=1;FOR_1<=15;FOR_1++)
	{
		R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);
		NOP();
		NOP();
	} //IMEI NUMBER
}











if(REPLY!=100)
{
SMS_FAIL=CLR;
restart1:
        
	R_UART2_SEND("AT+QSMSCODE=2\r\n");
	ACK_RX(20,2,100,1);
	if(SMS_FAIL>=2){SMS_FAIL=0;RESTART=OFF;goto restart11;}
   else if(RESTART==ON){SMS_FAIL++;RESTART=OFF;goto restart1;}SMS_FAIL=0;

restart2:
	ACK=ERROR_OCCURED=RESTART=0;
	R_UART2_SEND("AT+CMGF=1\r\n");
	ACK_RX(20,2,100,3);
	if(SMS_FAIL>=2){SMS_FAIL=0;RESTART=OFF;goto restart11;}
   else if(RESTART==ON){SMS_FAIL++;RESTART=OFF;goto restart2;}SMS_FAIL=0;

restart3:
	
	
	R_UART2_SEND("AT+CMGS=\"");
        
	for(FOR_1=0;FOR_1<=9;FOR_1++)
	{
	if(PHONE_NUMBER_OF_SENDER[0]==0x00 && PHONE_NUMBER_OF_SENDER[1]==0x00)
	{
	R_UART2_SEND_User(SMS_MOBILE_NO[FOR_1]);MS_TIMER(1);
	}
	else
	{
	R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);MS_TIMER(1);
	}
	}
	R_UART2_SEND("\"\r\n");MS_TIMER(50);
}
/******************************************************************************************************/
// REPLY==0 SEND WRONG PIN
if(REPLY==0)
{
R_UART2_SEND("WRONG PIN...TRY AGAIN....");
}
/******************************************************************************************************/
// REPLY==1 SEND HEALTH PACKET

else if(REPLY==1 || REPLY==102 || REPLY==101 || REPLY==110 || REPLY==111)
{
	// if(REPLY==1) {R_UART2_SEND_User(D_SYM);}
	//else if(REPLY==100){R_UART2_SEND("$");}
	//LONGITUDE_CONVERSION();
	//LATITUDE_CONVERSION();

	if(REPLY==1 || REPLY==102 || REPLY==111)
	{
		R_UART2_SEND("HCHKR,777777,VIDD,V");
	}
	else if(REPLY==101 || REPLY==110)
	{
		R_UART2_SEND("ACTVR,777777,VIDD,V");
	}

	/*****************************************************************************************************/
	// FIRMWARE VERSION
	R_UART2_SEND_User(((CURRENT_FRM_VERSION/100)+0x30));
	R_UART2_SEND(".");
	NOP();
	TEMP_FRM_VERSION = CURRENT_FRM_VERSION % 100;
	R_UART2_SEND_User(((TEMP_FRM_VERSION/10)+0x30));
	R_UART2_SEND(".");
	NOP();
	R_UART2_SEND_User(((TEMP_FRM_VERSION%10)+0x30));
	R_UART2_SEND(",");
	NOP();

	/*****************************************************************************************************/
	// IMEI NUMBER
	for(FOR_1=1; FOR_1<=15; FOR_1++)
	{
		R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);
		NOP();
		NOP();
	} //IMEI NUMBER

	/*****************************************************************************************************/
	/*****************************************************************************************************/
	// ALERT ID
	R_UART2_SEND(",01,0");
	/*****************************************************************************************************/

	for(FOR_1=0; FOR_1<=7; FOR_1++)
	{
		NOP(); //LATITUDE AND DIRECTION
		R_UART2_SEND_User(LAT_DM[FOR_1]);
		if(FOR_1==1)
		{
			R_UART2_SEND(".");
		}
	}

	if(LAT_DIRECTION=='N')
	{
		R_UART2_SEND(",N,");
	}
	else
	{
		R_UART2_SEND(",S,");
	}

	/************************************************************************************************************************************************************/

	for(FOR_1=0; FOR_1<=8; FOR_1++)
	{
		NOP(); //LONGITUDE AND DIRECTION
		R_UART2_SEND_User(LOG_DM[FOR_1]);
		if(FOR_1==2)
		{
			R_UART2_SEND(".");
		}
	}

	if(LON_DIRECTION=='E')
	{
		R_UART2_SEND(",E,");
	}
	else
	{
		R_UART2_SEND(",W,");
	}
	NOP();

	/************************************************************************************************************************************************************/

	R_UART2_SEND_User(Array_0[GPS_DIRECTION_DATA_VALID]);
	R_UART2_SEND(",");
	NOP(); //GPS VALID OR INVALID

	/************************************************************************************************************************************************************/

	for(FOR_1=0; FOR_1<=5; FOR_1++)
	{
		R_UART2_SEND_User(((TIME[FOR_1] & 0xF0)>>4)+0X30);
		R_UART2_SEND_User((TIME[FOR_1] & 0x0F)+0X30);

		if(FOR_1==2 && REPLY==100)
		{
			R_UART2_SEND("+");
		}
		if(FOR_1==2 && REPLY==1)
		{
			R_UART2_SEND(" ");
		}
		if(FOR_1==1)
		{
			R_UART2_SEND("20");
		}
	}

	R_UART2_SEND(",");

	if(COG_VALUE_COUNT==1)
	{
		R_UART2_SEND("00");
		COG_VALUE_COUNT=3;
		NOP();
	}
	else if(COG_VALUE_COUNT==2)
	{
		R_UART2_SEND("0");
		COG_VALUE_COUNT=4;
		NOP();
	}
	else
	{
		COG_VALUE_COUNT=5;
	}

	DECIMAL_POINT=OFF;

	for(FOR_1=0; FOR_1<=COG_VALUE_COUNT; FOR_1++)
	{
		NOP();

		if(COG[FOR_1]=='.' && DECIMAL_POINT==ON)
		{
			DECIMAL_POINT=OFF;
			COG[FOR_1]='0';
		}
		else if(COG[FOR_1]=='.')
		{
			DECIMAL_POINT=ON;
		}

		R_UART2_SEND_User(COG[FOR_1]);
	}

	/************************************************************************************************************************************************************/

	if(ADD_ZERO_TO_SPEED==SET)
	{
		R_UART2_SEND("0");
	}

	R_UART2_SEND(",");

	for(FOR_1=0; FOR_1<=SPEED_DATA_LENGTH_COUNT; FOR_1++)
	{
		NOP();
		R_UART2_SEND_User(SPEED_DATA[FOR_1]);
	}

	DECIMAL_POINT_CAME_STOP_TX=OFF;
	NOP();
	R_UART2_SEND(",");
	NOP();

	/************************************************************************************************************************************************************/

	R_UART2_SEND_User(Array_0[GSM_STRENGTH/10]);
	NOP();
	R_UART2_SEND_User(Array_0[GSM_STRENGTH%10]);
	NOP(); //GSM SIGNAL STRENGTH

	/************************************************************************************************************************************************************/

	R_UART2_SEND(",404,");

	HEX_CHARACTER_CONVERSION=SET;

	if(MNC_DATA_LENGTH==0 || MNC[0]==0x78)
	{
		R_UART2_SEND("00");
	}
	else
	{
		if(MNC_DATA_LENGTH>=2)
		{
			MNC_DATA_LENGTH=1;
		}

		for(FOR_1=0; FOR_1<=MNC_DATA_LENGTH; FOR_1++)
		{
			NOP();
			R_UART2_SEND_User(MNC[FOR_1]);
		}
	}

	HEX_CHARACTER_CONVERSION=CLR;
	R_UART2_SEND(",");

	PRINT_ZEROS(LAC_DATA_LENGTH_0);

	for(FOR_1=0; FOR_1<=LAC_DATA_LENGTH_0; FOR_1++)
	{
		NOP();
		R_UART2_SEND_User(LAC[FOR_1]);
	}

	R_UART2_SEND(",");

	if(MAIN_BAT_STATUS==OFF)
	{
		R_UART2_SEND("0,");
	}
	else
	{
		MAIN_BAT_STATUS=ON;
		R_UART2_SEND("1,");
	}
	NOP(); // MAIN BATTERY STATUS

	R_UART2_SEND_User(Array_0[IGNITION]);
	NOP();
	R_UART2_SEND(",");
	NOP(); // IGNITION

	/************************************************************************************************************************************************************/

	BATTERY_MEASUREMENT=ON;

	R_UART2_SEND_User(((MAIN_BATTERY_VOLTAGE/100)+0x30));
	VOLT = MAIN_BATTERY_VOLTAGE % 100;

	R_UART2_SEND_User(((VOLT/10)+0x30));
	NOP();
	R_UART2_SEND(".");
	R_UART2_SEND_User(((VOLT%10)+0x30));
	R_UART2_SEND(","); //MAIN BATTERY VOLTAGE

	/************************************************************************************************************************************************************/

	if(HEALTH_FRAME_NUMBER>=1000000)
	{
		HEALTH_FRAME_NUMBER=1;
	}

	TEMP_FRAME_NUMBER = HEALTH_FRAME_NUMBER;

	R_UART2_SEND_User(((TEMP_FRAME_NUMBER/100000)+0x30));

	TEMP_FRAME_NUMBER = TEMP_FRAME_NUMBER % 100000;
	R_UART2_SEND_User(((TEMP_FRAME_NUMBER/10000)+0x30));

	TEMP_FRAME_NUMBER = TEMP_FRAME_NUMBER % 10000;
	R_UART2_SEND_User(((TEMP_FRAME_NUMBER/1000)+0x30));

	TEMP_FRAME_NUMBER = TEMP_FRAME_NUMBER % 1000;
	R_UART2_SEND_User(((TEMP_FRAME_NUMBER/100)+0x30));

	TEMP_FRAME_NUMBER = TEMP_FRAME_NUMBER % 100;
	R_UART2_SEND_User(((TEMP_FRAME_NUMBER/10)+0x30));
	R_UART2_SEND_User(((TEMP_FRAME_NUMBER%10)+0x30));

	/************************************************************************************************************************************************************/

	R_UART2_SEND(",ID");

	/*****************************************************************************************************/
}

/*****************************************************************************************************/
//REPLY==
else if(REPLY==201)
{
R_UART2_SEND("PRIMARY NETWORK SELECTED");NOP();NOP();	
}
else if(REPLY==202)
{
R_UART2_SEND("SECONDARY NETWORK SELECTED");NOP();NOP();	
}
else if(REPLY==2)
{
REPL_1:
R_UART2_SEND("IMEI:-");
for(FOR_1=1;FOR_1<=15;FOR_1++){R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);NOP();NOP();} //IMEI NUMBER
if(REPLY==17){R_UART2_SEND(",");goto REPL_2;}
}

/*****************************************************************************************************/
//REPLY==3 DEVICE RESTART
else if(REPLY==3)
{
R_UART2_SEND("DEVICE WILL RESTART.");
for(FOR_1=1;FOR_1<=15;FOR_1++){R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);NOP();NOP();} //IMEI NUMBER
}
//REPLY==4 IGNITION ON
/*****************************************************************************************************/
else if(REPLY==4)
{
REPL_2:
R_UART2_SEND("IGNITION ON TIME:-");
////T=i2c_readn(0xA0,0XFE,20);MS_TIMER(2);
R_UART2_SEND_User(Array_0[T]);NOP();
//T=i2c_readn(0xA0,0XFE,21);MS_TIMER(2);
R_UART2_SEND_User(Array_0[T]);NOP();
//T=i2c_readn(0xA0,0XFE,22);MS_TIMER(2);
R_UART2_SEND_User(Array_0[T]);NOP();
R_UART2_SEND(" SEC");
if(REPLY==17){R_UART2_SEND(",");goto REPL_3;}
}
/*****************************************************************************************************/
//REPLY==5 IGNITION OFF
else if(REPLY==5)
{
REPL_3:
R_UART2_SEND("IGNITION OFF TIME:-");
MS_TIMER(2);
//T=i2c_readn(0xA0,0XFE,23);MS_TIMER(2);
R_UART2_SEND_User(Array_0[T]);NOP();
//T=i2c_readn(0xA0,0XFE,24);MS_TIMER(2);
R_UART2_SEND_User(Array_0[T]);NOP();
//T=i2c_readn(0xA0,0XFE,25);MS_TIMER(2);
R_UART2_SEND_User(Array_0[T]);NOP();
R_UART2_SEND(" HRS");
if(REPLY==17){R_UART2_SEND(",");goto REPL_4;}
}
/*****************************************************************************************************/
//REPLY==6 REGISTRATION NUMBER
else if(REPLY==6)
{
REPL_4:
R_UART2_SEND("REG NO:-");
FOR_1=CLR;
for(FOR_0=26;FOR_0<=35;FOR_0++)
{
//T=i2c_readn(0xA0,0XFE,FOR_0);MS_TIMER(2);
R_UART2_SEND_User(T);NOP();
VEICHLE_NUMBER[FOR_1]=T;
FOR_1++;
}
if(REPLY==17){R_UART2_SEND(",");goto REPL_5;}
}

/*****************************************************************************************************/

/*****************************************************************************************************/
//REPLY==8 UPDATE EMERGENCY NUMBER
/*****************************************************************************************************/
else if(REPLY==8)
{
//REPL_6:
O=CLR;
R_UART2_SEND("VLT EMER No:-");
for(FOR_0=50;FOR_0<=99;FOR_0++)
{
MS_TIMER(1);//T=i2c_readn(0xA0,0XFE,FOR_0);MS_TIMER(1);
R_UART2_SEND_User(T);NOP();
SMS_MOBILE_NO[O]=T;
O++;
if(O%10==0){R_UART2_SEND(",");}
}
//if(REPLY==17){R_UART2_SEND(",");goto REPL_7;}
}
/*****************************************************************************************************/
//UPDATE REPLY NUMBER
/*****************************************************************************************************/
else if(REPLY==9)
{
REPL_7:
O=CLR;
R_UART2_SEND("VLT REPLY NO:-");
for(FOR_0=100;FOR_0<=109;FOR_0++)
{
//T=i2c_readn(0xA0,0XFE,FOR_0);MS_TIMER(2);
R_UART2_SEND_User(T);NOP();
REPLY_NUMBER[O]=T;
O++;
}
if(REPLY==17){R_UART2_SEND(",");goto REPL_8;}
}
/*****************************************************************************************************/
/*****************************************************************************************************/
//DEVICE CLEAR
/*****************************************************************************************************/
else if(REPLY==10)
{
O=CLR;
R_UART2_SEND("CLR COMMAND Running...");
}


else if(REPLY==13)
{
REPL_10:
O=CLR;
R_UART2_SEND("H-BRAKE LEV:");
//T=i2c_readn(0xA0,0XFE,39);MS_TIMER(2);
R_UART2_SEND_User(Array_0[T]);NOP();
if(REPLY==17){R_UART2_SEND(",");goto REPL_11;}
}
/*****************************************************************************************************/
else if(REPLY==14)
{
REPL_11:
O=CLR;
R_UART2_SEND("P-ALERT TIME:");
//T=i2c_readn(0xA0,0XFE,40);MS_TIMER(2);
R_UART2_SEND_User(Array_0[T]);NOP();
//T=i2c_readn(0xA0,0XFE,41);MS_TIMER(2);
R_UART2_SEND_User(Array_0[T]);NOP();
//T=i2c_readn(0xA0,0XFE,42);MS_TIMER(2);
R_UART2_SEND_User(Array_0[T]);NOP();
R_UART2_SEND("MIN");
if(REPLY==17){R_UART2_SEND(",");goto REPL_12;}
}
/*****************************************************************************************************/
else if(REPLY==15)
{
	REPL_12:
	O=CLR;
	R_UART2_SEND("H-ALERT TIME:");
	MS_TIMER(1);
	T=i2c_readn(0xA0,0XFE,43);
	MS_TIMER(2);
	R_UART2_SEND_User(Array_0[T]);
	MS_TIMER(1);
	T=i2c_readn(0xA0,0XFE,44);
	MS_TIMER(2);
	R_UART2_SEND_User(Array_0[T]);
	MS_TIMER(1);
	T=i2c_readn(0xA0,0XFE,45);
	MS_TIMER(2);
	R_UART2_SEND_User(Array_0[T]);
	MS_TIMER(1);
	R_UART2_SEND(" HOURS");
	if(REPLY==17)
	{
		R_UART2_SEND(",");
		goto REPL_13;
	}
}
/*****************************************************************************************************/

/*****************************************************************************************************/
else if(REPLY==17)
{
O=CLR;
R_UART2_SEND("SETTINGS:-");
goto REPL_1;
}
/*****************************************************************************************************/
else if(REPLY==18)
{
R_UART2_SEND("PRIMARY IP:");
for(FOR_0=0;FOR_0<=13;FOR_0++)
{
R_UART2_SEND_User(TEMP_PIP2[FOR_0]);NOP();
}
}
/*****************************************************************************************************/
else if(REPLY==19)
{
R_UART2_SEND("SECONDARY IP:");
for(FOR_0=0;FOR_0<=13;FOR_0++)
{
R_UART2_SEND_User(TEMP_SIP2[FOR_0]);NOP();
}
}
/*****************************************************************************************************/
else if(REPLY==20)
{
REPL_14:
R_UART2_SEND("PRIMARY IP:");
for(FOR_0=0;FOR_0<=13;FOR_0++)
{
R_UART2_SEND_User(TEMP_PIP2[FOR_0]);NOP();
}
R_UART2_SEND(" PORT NUM:");
for(FOR_0=0;FOR_0<=4;FOR_0++)
{
R_UART2_SEND_User(TEMP_PPN2[FOR_0]);NOP();
}
if(REPLY==17){R_UART2_SEND(",");goto REPL_15;}
}
/*****************************************************************************************************/
else if(REPLY==21)
{
REPL_15:
R_UART2_SEND("SEC-IP:");
for(FOR_0=0;FOR_0<=13;FOR_0++)
{
R_UART2_SEND_User(TEMP_SIP2[FOR_0]);NOP();
}
R_UART2_SEND(" PORT NUM:");
for(FOR_0=0;FOR_0<=4;FOR_0++)
{
R_UART2_SEND_User(TEMP_SPN2[FOR_0]);NOP();
}
if(REPLY==17){R_UART2_SEND(",");goto REPL_16;}
}
/*****************************************************************************************************/
/*****************************************************************************************************/
else if(REPLY==22)
{
R_UART2_SEND("P-PORT NUM:");
for(FOR_0=0;FOR_0<=3;FOR_0++)
{
R_UART2_SEND_User(TEMP_PPN2[FOR_0]);NOP();
}
}
/*****************************************************************************************************/
else if(REPLY==23)
{
R_UART2_SEND("S-PORT NUM:");
for(FOR_0=0;FOR_0<=3;FOR_0++)
{
R_UART2_SEND_User(TEMP_SPN2[FOR_0]);NOP();
}
}

/*****************************************************************************************************/
// SLEEP ON TIME
else if(REPLY==24)
{
REPL_16:
//O=CLR;
R_UART2_SEND("SLEEP ON:");
O=SLEEP_ON_TIME%100;
R_UART2_SEND_User(((SLEEP_ON_TIME/100)+0x30));
R_UART2_SEND_User(((O/10)+0x30));
R_UART2_SEND_User(((O%10)+0x30));
R_UART2_SEND("SEC");
if(REPLY==17){R_UART2_SEND(",");goto REPL_17;}
}
/*****************************************************************************************************/
// SLEEP OFF TIME
else if(REPLY==25)
{
REPL_17:
R_UART2_SEND("SLEEP OFF:");
O=SLEEP_OFF_TIME%100;
R_UART2_SEND_User(((SLEEP_OFF_TIME/100)+0x30));
R_UART2_SEND_User(((O/10)+0x30));
R_UART2_SEND_User(((O%10)+0x30));
R_UART2_SEND("SEC");
if(REPLY==17){R_UART2_SEND(",");goto REPL_18;}
}
/*****************************************************************************************************/
// SLEEP OFF TIME
else if(REPLY==26)
{
REPL_18:
R_UART2_SEND("OVER SPEED:");
O=OVER_SPEED%100;
R_UART2_SEND_User(((OVER_SPEED/100)+0x30));
R_UART2_SEND_User(((O/10)+0x30));
R_UART2_SEND_User(((O%10)+0x30));
R_UART2_SEND("KM/Hr");
if(REPLY==17){R_UART2_SEND(",");goto REPL_19;}
}
// EMERGENCY TIME
else if(REPLY==27)
{
REPL_19:
R_UART2_SEND("EMER-TIME:");
O=EMGT_TIME%100;
R_UART2_SEND_User(((EMGT_TIME/100)+0x30));
R_UART2_SEND_User(((O/10)+0x30));
R_UART2_SEND_User(((O%10)+0x30));
R_UART2_SEND("SEC");
}
if(REPLY!=100 && REPLY!=110 && REPLY!=111 && DATA_SEND==CLR)
{
R_UART2_SEND_User(CTRL_Z);
ACK_RX(2500,2,500,100);
if(SMS_FAIL_COUNT>=1){SMS_FAIL_COUNT=0;RESTART=OFF;}
else if(RESTART==ON){SMS_FAIL_COUNT++;RESTART=OFF;goto restart3;}
SMS_FAIL_COUNT=CLR;
}
restart11:
MS_TIMER(100);

}




void BATTERY_PERCENTAGE_CALCULATE(void)
{
BATTERY_MEASUREMENT=ON;MS_TIMER(10);
BACKUP_BATTERY_VOLTAGE=BACKUP_BATTERY_VOLTAGE%1000;
     if(BACKUP_BATTERY_VOLTAGE<=330){R_UART2_SEND("010,");}
else if(BACKUP_BATTERY_VOLTAGE>=330 && BACKUP_BATTERY_VOLTAGE<345){R_UART2_SEND("020,");}		
else if(BACKUP_BATTERY_VOLTAGE>=345 && BACKUP_BATTERY_VOLTAGE<350){R_UART2_SEND("030,");}		
else if(BACKUP_BATTERY_VOLTAGE>=350 && BACKUP_BATTERY_VOLTAGE<355){R_UART2_SEND("040,");}		
else if(BACKUP_BATTERY_VOLTAGE>=355 && BACKUP_BATTERY_VOLTAGE<360){R_UART2_SEND("050,");}		
else if(BACKUP_BATTERY_VOLTAGE>=360 && BACKUP_BATTERY_VOLTAGE<365){R_UART2_SEND("060,");}		
else if(BACKUP_BATTERY_VOLTAGE>=365 && BACKUP_BATTERY_VOLTAGE<370){R_UART2_SEND("070,");}		
else if(BACKUP_BATTERY_VOLTAGE>=370 && BACKUP_BATTERY_VOLTAGE<375){R_UART2_SEND("080,");}		
else if(BACKUP_BATTERY_VOLTAGE>=375 && BACKUP_BATTERY_VOLTAGE<420){R_UART2_SEND("090,");}		
else if(BACKUP_BATTERY_VOLTAGE>=420 && BACKUP_BATTERY_VOLTAGE<490){R_UART2_SEND("100,");}		
BATTERY_MEASUREMENT=OFF;
}

void GET_TIME(void)
{
	
TIME[0]=DAY;TIME[1]=MONTH;TIME[2]=YEAR;TIME[3]=HOUR;TIME[4]=MIN;TIME[5]=SEC;
}

void PRINT_ZEROS(unsigned int q)
{
 	 if(q==0){R_UART2_SEND("000");NOP();}   
    else if(q==1){R_UART2_SEND("00");NOP();}
    else if(q==2){R_UART2_SEND("0");NOP();}
}
void PRINT_ZEROS_2(unsigned int q)
{
 	 if(q==0){SEND_TO_ARRAY("000");NOP();}   
    else if(q==1){SEND_TO_ARRAY("00");NOP();}
    else if(q==2){SEND_TO_ARRAY("0");NOP();}
}

void GET_DEGREES(void)
{
for(FOR_1=0;FOR_1<=7;FOR_1++){LAT_DM[FOR_1]=LAT_DM_RX[FOR_1];}
P_LAT_DM_RX=LAT_DM_RX[5];
for(FOR_1=0;FOR_1<=8;FOR_1++){LOG_DM[FOR_1]=LOG_DM_RX[FOR_1];}	
}
void GET_SPEED_DATA(void)
{
ADD_ZERO_TO_SPEED=CLR;	
if(NO_OF_SAT<=3)
{
for(FOR_1=0;FOR_1<=3;FOR_1++)
{
NOP();
SPEED_DATA[FOR_1]='0';
}
SPEED_DATA[2]='.';
SPEED_DATA_LENGTH_COUNT=3;
}
else
{
for(FOR_1=0;FOR_1<=4;FOR_1++)
{
NOP();
SPEED_DATA[FOR_1]=SPEED_DATA_RX[FOR_1];
if(SPEED_DATA[FOR_1]=='.')
{
DECIMAL_POINT_CAME_STOP_TX=ON;
if(FOR_1==1)
{
ADD_ZERO_TO_SPEED=SET;
}
}
else if(DECIMAL_POINT_CAME_STOP_TX==ON)
{
DECIMAL_POINT_CAME_STOP_TX=OFF;
SPEED_DATA_LENGTH_COUNT=FOR_1;
FOR_1=5;
break;
}
}
T_SPEED=0x0F&SPEED_DATA[0];
if(SPEED_DATA[1]!='.')
{
T_SPEED=((T_SPEED*10)+(0x0F&SPEED_DATA[1]));
}
}
}
void GET_IMEI(void)
{
	restart100:
	IMEI_RX=ON;
	R_UART2_SEND("AT\r\n");ACK_RX(20,2,10,1);
     MS_TIMER(300);
	R_UART2_SEND("AT+GSN\r\n");ACK_RX(40,2,50,0);if(RESTART==ON){RESTART=OFF;goto restart100;}
	IMEI_RX=OFF;
	if(IMEI_ACK_RX==0)
	{
		CMD_DATA_WRITE_IN_EEROM(19);
		for(K=0;K<16;K++)
		{
			IMEI_EEPROM[K]=i2c_readn(0xA0,0XFA,K);
			MS_TIMER(5);
		}
	}
	
}

void GET_MCC_MNC_LAC_CELL_ID(void)
{
restart5:
             
	  R_UART2_SEND("AT+QENG=1,3\r\n");
	  ACK_RX(200,2,50,50);
	  if(RESTART==ON){RESTART=OFF;goto restart5;}
	  
ACK=CLR;	  
GET_MCC_MNC_LAC_CELL_ID_RX=GET_NMR_RX=SET;

	  R_UART2_SEND("AT+QENG?\r\n");
	   ACK_RX(200,2,50,0);
	  if(RESTART==ON){RESTART=OFF;goto restart5;}
	  
GET_MCC_MNC_LAC_CELL_ID_RX=GET_NMR_RX=CLR;
}
	  
void WELCOME_STRING(void)
{
R_UART2_SEND("$,LOGIN,");

for(FOR_1=0;FOR_1<=9;FOR_1++){if(VEICHLE_NUMBER[FOR_1]!=' '){R_UART2_SEND_User(VEICHLE_NUMBER[FOR_1]);MS_TIMER(1);}} // VR NUMBER
R_UART2_SEND(",");
for(FOR_1=1;FOR_1<=15;FOR_1++){R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);NOP();NOP();} //IMEI NUMBER
R_UART2_SEND(",");
R_UART2_SEND_User(((CURRENT_FRM_VERSION/100)+0x30));R_UART2_SEND(".");NOP();
TEMP_FRM_VERSION=CURRENT_FRM_VERSION%100;
R_UART2_SEND_User(((TEMP_FRM_VERSION/10)+0x30));R_UART2_SEND(".");NOP();
R_UART2_SEND_User(((TEMP_FRM_VERSION%10)+0x30));						// FRM VERSION
R_UART2_SEND(",");
R_UART2_SEND("1.0.1");										// Protocol Version
R_UART2_SEND(",");
READ_LAST_LOCATION();
R_UART2_SEND("$");

}

void BOOT_STRING(void)
{
R_UART2_SEND("$,BOOT,");

//for(FOR_1=0;FOR_1<=9;FOR_1++){if(VEICHLE_NUMBER[FOR_1]!=' '){R_UART2_SEND_User(VEICHLE_NUMBER[FOR_1]);MS_TIMER(1);}} // VR NUMBER
//R_UART2_SEND("$");
for(FOR_1=1;FOR_1<=15;FOR_1++){R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);NOP();NOP();} //IMEI NUMBER

}


void STORE_LAST_LOCATION(void)
{
	char Address=0;
MS_TIMER(1);
for(FOR_1=0;FOR_1<=7;FOR_1++)					//LATITUDE AND DIRECTION
{
NOP();
i2c_writen(0xA0,0XFD,FOR_1,LAT_DM[FOR_1]);MS_TIMER(1);
}
Address=8;
for(FOR_1=0;FOR_1<=8;FOR_1++)					//LATITUDE AND DIRECTION
{
NOP();
i2c_writen(0xA0,0XFD,Address,LOG_DM[FOR_1]);MS_TIMER(1);
Address++;
}
MS_TIMER(1);
if(LAT_DIRECTION=='N'){MS_TIMER(1);i2c_writen(0xA0,0XFD,18,'N');}else{MS_TIMER(1);i2c_writen(0xA0,0XFF,8,'S');}
if(LON_DIRECTION=='E'){MS_TIMER(1);i2c_writen(0xA0,0XFD,19,'E');}else{MS_TIMER(1);i2c_writen(0xA0,0XFF,8,'W');}
MS_TIMER(1);
}

void READ_LAST_LOCATION(void)
{
RLL=i2c_readn(0xA0,0XFD,18);NOP();
if(RLL=='N' || RLL=='S')
{
RLL=i2c_readn(0xA0,0XFD,19);NOP();	
if(RLL=='E' || RLL=='W')
{
NOP();RLL=i2c_readn(0xA0,0XFD,19);NOP();
for(FOR_1=0;FOR_1<=7;FOR_1++)			// READ LAT
{
NOP();RLL=i2c_readn(0xA0,0XFD,FOR_1);NOP();
if(FOR_1==2){R_UART2_SEND(".");}
R_UART2_SEND_User(RLL);
}
R_UART2_SEND(",");
NOP();RLL=i2c_readn(0xA0,0XFD,18);NOP();	// READ LAT DIRECTION
R_UART2_SEND_User(RLL);
R_UART2_SEND(",");
for(FOR_1=8;FOR_1<=16;FOR_1++)			// READ LOG 
{
NOP();RLL=i2c_readn(0xA0,0XFD,FOR_1);NOP();
R_UART2_SEND_User(RLL);
if(FOR_1==10){R_UART2_SEND(".");}
}
R_UART2_SEND(",");
NOP();RLL=i2c_readn(0xA0,0XFD,19);NOP();	// READ LOG DIRECTION
R_UART2_SEND_User(RLL);
}
}
else
{
R_UART2_SEND("00.000000,N,000.000000,E");	
}
}

void DATA_PRINT(char FORMAT)
{	
URL_PRINT=ON;

	  if(FORMAT==0){
	  R_UART2_SEND("$,H,VID,");
/************************************************************************************************************************************************************/

	  R_UART2_SEND_User(((CURRENT_FRM_VERSION/100)+0x30));R_UART2_SEND(".");NOP();
	  TEMP_FRM_VERSION=CURRENT_FRM_VERSION%100;
	  R_UART2_SEND_User(((TEMP_FRM_VERSION/10)+0x30));R_UART2_SEND(".");NOP();
	  R_UART2_SEND_User(((TEMP_FRM_VERSION%10)+0x30));
	  
	  R_UART2_SEND(",");NOP();
	  
	  
VOLT=BACKUP_BATTERY_VOLTAGE%1000;	  
/************************************************************************************************************************************************************/	  
	  					  //START CHARACTER , HEADER , VENDOR ID, FIRMWARE VERSION
  
	      
	  
	       if(POWER_SOURCE_PACKET==ON){R_UART2_SEND("BD,03,");}
	  else if(POWER_SOURCE_RECONNECT_PACKET==ON){R_UART2_SEND("BR,06,");}
	  else if(LOW_BATTERY_ALERT_PACKET==ON){R_UART2_SEND("BL,04,");}
	  else if(BATTERY_CHARGED_PACKET==ON){R_UART2_SEND("BH,05,");}
	 
	  else if(OTA_PACKET==ON){OTA_PACKET=OFF;R_UART2_SEND("PC,12,");}
	  
	  else if(HARSH_BRAKE_PACKET==ON){HARSH_BRAKE_PACKET=OFF;R_UART2_SEND("HB,13,");R_INTC1_Start();}
	  else if(HARSH_ACC_PACKET==ON){HARSH_ACC_PACKET=OFF;R_UART2_SEND("HA,14,");R_INTC1_Start();}
	  else if(HARSH_TURN_PACKET==ON){HARSH_TURN_PACKET=OFF;R_UART2_SEND("RT,15,");R_INTC1_Start();}
	   else if( PANIC_CONTROL_STATE_1==ON){
	  PANIC_TIME_STOP=CLR;
	  PANIC_TIME_START=CLR;
	  PANIC_ALERT=0;
PANIC_ALERT_PACKET=OFF;
 PANIC_CONTROL_STATE_1=OFF;HOOTER=ON;
 
	  R_UART2_SEND("EF,11,");
	  }
	  
	 // else if(PANIC_TIME_STOP==SET){PANIC_TIME_STOP=CLR;R_UART2_SEND("EF,11,");}
	  else if(PANIC_ALERT==ON && P3_bit.no0==HIGH){R_UART2_SEND("EA,10,");}
	//  else if(PANIC_TIME_START==SET && P3_bit.no0==HIGH){R_UART2_SEND("DT,16,");}
	  else if(IGNITION_ON_PACKET==ON){R_UART2_SEND("IN,07,");/*IGNITION_ON_PACKET=OFF;*/}
	  else if(IGNITION_OFF_PACKET==ON){R_UART2_SEND("IF,08,");}
	  else if(NORMAL_PACKET==ON){R_UART2_SEND("NR,01,");}						 //NR-NORMAL , EA-EMERGENCY ALERT
	  
	  NOP();
	  R_UART2_SEND("L,");NOP();   //H- HISTORY , L-LIVE
/************************************************************************************************************************************************************/	  
	  
	   /*Testing*/ for(FOR_1=1;FOR_1<=15;FOR_1++){R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);NOP();NOP();}R_UART2_SEND(",");NOP(); //IMEI NUMBER
	  //R_UART2_SEND("868324026409396,");NOP();
	  
	  for(FOR_1=0;FOR_1<=9;FOR_1++)
	  {
	  if(VEICHLE_NUMBER[FOR_1]!=' ')
	  {
          R_UART2_SEND_User(VEICHLE_NUMBER[FOR_1]);
	  MS_TIMER(1);
	  }
	  }
	  //R_UART2_SEND_User(0x20);NOP();
	  
	  
	  
	  R_UART2_SEND(",");NOP(); //VEICHLE NUMBER
/************************************************************************************************************************************************************/	  
	  R_UART2_SEND_User(Array_0[GPS_DIRECTION_DATA_VALID]);R_UART2_SEND(",");NOP();				   //GPS VALID OR INVALID
	  }
	  
/************************************************************************************************************************************************************/	  
	  for(FOR_1=0;FOR_1<=5;FOR_1++){R_UART2_SEND_User(((TIME[FOR_1] & 0xF0)>>4)+0X30);R_UART2_SEND_User((TIME[FOR_1] & 0x0F)+0X30);if(FOR_1==1){R_UART2_SEND("20");}if(FOR_1==2 || FOR_1==5){R_UART2_SEND(",");}}
	  																						//RTC:- DDMMYYYY,HHMMSS,
	  if(FORMAT==1){if(GPS_DIRECTION_DATA_VALID==ON){R_UART2_SEND("A");}else{R_UART2_SEND("V");}}																						
																							
/************************************************************************************************************************************************************/																							
	  /* Testing R_UART2_SEND("12.582621,N,077.384200,E,");*/

	  /* Testing */ for(FOR_1=0;FOR_1<=7;FOR_1++){NOP();		//LATITUDE AND DIRECTION
	  /* Testing */ R_UART2_SEND_User(LAT_DM[FOR_1]);
	  /* Testing */ if(FOR_1==1){R_UART2_SEND(".");}}
	  /* Testing*/ if(LAT_DIRECTION=='N'){R_UART2_SEND(",N,");}else{R_UART2_SEND(",S,");}
/************************************************************************************************************************************************************/	  
	  /* Testing*/ for(FOR_1=0;FOR_1<=8;FOR_1++){NOP();		//LONGITUDE AND DIRECTION
	  /* Testing*/ R_UART2_SEND_User(LOG_DM[FOR_1]);
	  /* Testing*/ if(FOR_1==2){R_UART2_SEND(".");}}
	  /* Testing*/ if(LON_DIRECTION=='E'){R_UART2_SEND(",E,");}else{R_UART2_SEND(",W,");} NOP();
/************************************************************************************************************************************************************/
	 
	  //R_UART2_SEND("25.2,");NOP();//310.56,4,183.5,PDOP,HDOP,		//SPEED
	  //GET_SPEED_DATA();
	  
	  if(ADD_ZERO_TO_SPEED==SET){R_UART2_SEND("0");}
	  for(FOR_1=0;FOR_1<=SPEED_DATA_LENGTH_COUNT;FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(SPEED_DATA[FOR_1]);
	  }
	  DECIMAL_POINT_CAME_STOP_TX=OFF;
	  NOP();
	  R_UART2_SEND(",");
	  NOP();
	  
/************************************************************************************************************************************************************/	  
	  COG_VALUE_COUNT=CLR;
	  for(FOR_1=0;FOR_1<=5;FOR_1++)
	  {
	  NOP();
	  if(COG[FOR_1]!='.')
	  {
		  COG_VALUE_COUNT++;
	  }
	  else if(COG[FOR_1]=='.')
	  {
	  break;
	  }
	  }
	       if(COG_VALUE_COUNT==1){R_UART2_SEND("00");COG_VALUE_COUNT=3; NOP();}
	  else if(COG_VALUE_COUNT==2){R_UART2_SEND("0");COG_VALUE_COUNT=4;NOP();}
	  else{COG_VALUE_COUNT=5;}
	  DECIMAL_POINT=OFF;
          for(FOR_1=0;FOR_1<=COG_VALUE_COUNT;FOR_1++)
	  {
	  NOP();
	       if(COG[FOR_1]=='.' && DECIMAL_POINT==ON){DECIMAL_POINT=OFF;COG[FOR_1]='0';}
	  else if(COG[FOR_1]=='.'){DECIMAL_POINT=ON;}
	  R_UART2_SEND_User(COG[FOR_1]);
	  }
	  
	  // HEADING :-COURSE OVER GROUND IN DEGREE
	  R_UART2_SEND(",");NOP();
	  
	  R_UART2_SEND_User((NO_OF_SAT/10)+0x30);R_UART2_SEND_User((NO_OF_SAT%10)+0x30);R_UART2_SEND(",");NOP(); 		// NO OF SATELLITE
	  
/************************************************************************************************************************************************************/
	  ALTITUDE_VALUE_COUNT=CLR;
	  for(FOR_1=0;FOR_1<=4;FOR_1++)
	  {
	  NOP();
	  if(ALTITUDE[FOR_1]!='.')
	  {
		  ALTITUDE_VALUE_COUNT++;
	  }
	  else if(ALTITUDE[FOR_1]=='.')
	  {
	  break;
	  }
	  }
	       if(ALTITUDE_VALUE_COUNT==1){R_UART2_SEND("00");ALTITUDE_VALUE_COUNT=2; NOP();}
	  else if(ALTITUDE_VALUE_COUNT==2){R_UART2_SEND("0");ALTITUDE_VALUE_COUNT=3;NOP();}
	  else{ALTITUDE_VALUE_COUNT=4;}
	  for(FOR_1=0;FOR_1<=ALTITUDE_VALUE_COUNT;FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(ALTITUDE[FOR_1]);
	  }

	  //R_UART2_SEND(",0.00,"); NOP();
	  
	  R_UART2_SEND(","); NOP();
	  
	  for(FOR_1=0;FOR_1<=4;FOR_1++)
	  {
	  NOP();
	  if(PDOP_DATA_RX[FOR_1]=='1' || PDOP_DATA_RX[FOR_1]=='2' || PDOP_DATA_RX[FOR_1]=='3' || PDOP_DATA_RX[FOR_1]=='4' || PDOP_DATA_RX[FOR_1]=='5' || PDOP_DATA_RX[FOR_1]=='6' || PDOP_DATA_RX[FOR_1]=='7' || PDOP_DATA_RX[FOR_1]=='8' || PDOP_DATA_RX[FOR_1]=='9' || PDOP_DATA_RX[FOR_1]=='0'|| PDOP_DATA_RX[FOR_1]=='.')
	  {
	  R_UART2_SEND_User(PDOP_DATA_RX[FOR_1]);
	  }
	  else{R_UART2_SEND("0");}
	  }
	  //}
	  R_UART2_SEND(","); NOP();
/************************************************************************************************************************************************************/	  
	  
	  for(FOR_1=0;FOR_1<=4;FOR_1++)
	  {
	  NOP();
	  if(HDOP[FOR_1]=='1' || HDOP[FOR_1]=='2' || HDOP[FOR_1]=='3' || HDOP[FOR_1]=='4' || HDOP[FOR_1]=='5' || HDOP[FOR_1]=='6' || HDOP[FOR_1]=='7' || HDOP[FOR_1]=='8' || HDOP[FOR_1]=='9' || HDOP[FOR_1]=='0'|| HDOP[FOR_1]=='.')
	  {
	  R_UART2_SEND_User(HDOP[FOR_1]);
	  }
	  else{R_UART2_SEND("0");}
	  }

	  R_UART2_SEND(",");	NOP();   //HDOP
/************************************************************************************************************************************************************/	  
	  for(FOR_1=0;FOR_1<=7;FOR_1++){NOP();R_UART2_SEND_User(NETWORK_NAME[FOR_1]);}R_UART2_SEND(",");NOP();   //NETWORK OPEATOR NAME
/************************************************************************************************************************************************************/
	  NOP();
	  R_UART2_SEND_User(Array_0[IGNITION]);NOP();R_UART2_SEND(",");NOP();						   // IGNITION
/************************************************************************************************************************************************************/	  
	  
	  //if(MAIN_BATTERY_VOLTAGE<=40){MAIN_BAT_STATUS=OFF;TEMP_MAIN_BATTERY_VOLTAGE=0;R_UART2_SEND("0,");}else{MAIN_BAT_STATUS=ON;R_UART2_SEND("1,");}NOP();		// MAIN BATTERY STATUS
	  
	  if(MAIN_BAT_STATUS==OFF){R_UART2_SEND("0,");}else{MAIN_BAT_STATUS=ON;R_UART2_SEND("1,");}NOP();		// MAIN BATTERY STATUS
	  
	  BATTERY_MEASUREMENT=ON;
	  R_UART2_SEND_User(((MAIN_BATTERY_VOLTAGE/100)+0x30));
	  VOLT=MAIN_BATTERY_VOLTAGE%100;
	  R_UART2_SEND_User(((VOLT/10)+0x30));NOP();R_UART2_SEND(".");
	  R_UART2_SEND_User(((VOLT%10)+0x30));R_UART2_SEND(",");//MAIN BATTERY VOLTAGE
/************************************************************************************************************************************************************/	  
	  VOLT=BACKUP_BATTERY_VOLTAGE%1000;
	  if(VOLT>=440){VOLT=440;}
	  R_UART2_SEND_User(((VOLT/100)+0x30));VOLT=VOLT%100;R_UART2_SEND(".");
	  R_UART2_SEND_User(((VOLT/10)+0x30));        //R_UART2_SEND_User(((VOLT%10)+0x30));
	  R_UART2_SEND(",");				//BACKUP BATTERY VOLTAGE
	  BATTERY_MEASUREMENT=OFF;
/************************************************************************************************************************************************************/	  
	  R_UART2_SEND_User(Array_0[PANIC_ALERT]);NOP();R_UART2_SEND(",C,");							//PANIC ALERT & TAMPER ALERT 'C'
/************************************************************************************************************************************************************/
	  R_UART2_SEND_User(Array_0[GSM_STRENGTH/10]);NOP();R_UART2_SEND_User(Array_0[GSM_STRENGTH%10]);NOP();	//GSM SIGNAL STRENGTH
/************************************************************************************************************************************************************/	  						//PANIC ALERT & TAMPER ALERT 'C'
	  
	  R_UART2_SEND(",404,");
	  
          HEX_CHARACTER_CONVERSION=SET;
	        
	      if(MNC_DATA_LENGTH==0 || MNC[0]==0x78){R_UART2_SEND("00");}
		
	  else
	  {
		  if(MNC_DATA_LENGTH>=2){MNC_DATA_LENGTH=1;}
	  for(FOR_1=0;FOR_1<=MNC_DATA_LENGTH;FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(MNC[FOR_1]);
	  }
	  }
	  R_UART2_SEND(",");
	  
	  
	  PRINT_ZEROS(LAC_DATA_LENGTH_0);
	  for(FOR_1=0;FOR_1<=LAC_DATA_LENGTH_0;FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(LAC[FOR_1]);
	  }
	  R_UART2_SEND(",");
	  
	  
	  PRINT_ZEROS(CELL_ID_DATA_LENGTH_0);
	  
	  for(FOR_1=0;FOR_1<=CELL_ID_DATA_LENGTH_0;FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(CELL_ID[FOR_1]);
	  }
	  R_UART2_SEND(",");NOP();  
	 
	 
/************************************************************************************************************************************************************/	  
// CELL ID:-1
               //if(CELL_ID_DATA_LENGTH[1]==1){R_UART2_SEND("00");NOP();}
	  //else if(CELL_ID_DATA_LENGTH[1]==2){R_UART2_SEND("0");NOP();}
	  
	  PRINT_ZEROS(CELL_ID_DATA_LENGTH[1]);
	  
	  for(FOR_1=0;FOR_1<=CELL_ID_DATA_LENGTH[1];FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(CELL_ID_1[FOR_1]);
	  }
	  R_UART2_SEND(",");NOP();  
// LAC:-1 	  
	  PRINT_ZEROS(LAC_DATA_LENGTH[1]);
	  for(FOR_1=0;FOR_1<=LAC_DATA_LENGTH[1];FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(LAC_1[FOR_1]);
	  }
	  R_UART2_SEND(",");NOP();  
// DBM:-1 	  
	  for(FOR_1=0;FOR_1<=DBM_DATA_LENGTH[1];FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(DBM_1[FOR_1]);
	       if(DBM_DATA_LENGTH[1]==2 && FOR_1==0){R_UART2_SEND("0");NOP();}
	  else if(DBM_DATA_LENGTH[1]==1 && FOR_1==0){R_UART2_SEND("00");NOP();}
	  }
	  R_UART2_SEND(",");NOP();  
/************************************************************************************************************************************************************/	  

/************************************************************************************************************************************************************/	  
// CELL ID:-2 	  
	  PRINT_ZEROS(CELL_ID_DATA_LENGTH[2]);
	  for(FOR_1=0;FOR_1<=CELL_ID_DATA_LENGTH[2];FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(CELL_ID_2[FOR_1]);
	  }
	  R_UART2_SEND(",");NOP();  
// LAC:-2 	 
	  PRINT_ZEROS(LAC_DATA_LENGTH[2]);
	  for(FOR_1=0;FOR_1<=LAC_DATA_LENGTH[2];FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(LAC_2[FOR_1]);
	  }
	  R_UART2_SEND(",");NOP();  
// DBM:-2 	  
	  for(FOR_1=0;FOR_1<=DBM_DATA_LENGTH[2];FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(DBM_2[FOR_1]);
	       if(DBM_DATA_LENGTH[2]==2 && FOR_1==0){R_UART2_SEND("0");NOP();}
	  else if(DBM_DATA_LENGTH[2]==1 && FOR_1==0){R_UART2_SEND("00");NOP();}
	  }
	  R_UART2_SEND(",");NOP();  
/************************************************************************************************************************************************************/	  
// CELL ID:-3
          PRINT_ZEROS(CELL_ID_DATA_LENGTH[3]);
	  for(FOR_1=0;FOR_1<=CELL_ID_DATA_LENGTH[3];FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(CELL_ID_3[FOR_1]);
	  }
	  R_UART2_SEND(",");NOP();  
// LAC:-3 	  
	  PRINT_ZEROS(LAC_DATA_LENGTH[3]);
	  for(FOR_1=0;FOR_1<=LAC_DATA_LENGTH[3];FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(LAC_3[FOR_1]);
	  }
	  R_UART2_SEND(",");NOP();  
// DBM:-3 	  
	  for(FOR_1=0;FOR_1<=DBM_DATA_LENGTH[3];FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(DBM_3[FOR_1]);
	       if(DBM_DATA_LENGTH[3]==2 && FOR_1==0){R_UART2_SEND("0");NOP();}
	  else if(DBM_DATA_LENGTH[3]==1 && FOR_1==0){R_UART2_SEND("00");NOP();}
	  }
	  R_UART2_SEND(",");NOP();  
/************************************************************************************************************************************************************/	  
//CELL ID:-4

	  PRINT_ZEROS(CELL_ID_DATA_LENGTH[4]);
	  for(FOR_1=0;FOR_1<=CELL_ID_DATA_LENGTH[4];FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(CELL_ID_4[FOR_1]);
	  }
	  R_UART2_SEND(",");NOP();  
// LAC:-4 	  
	  PRINT_ZEROS(LAC_DATA_LENGTH[4]);
          for(FOR_1=0;FOR_1<=LAC_DATA_LENGTH[4];FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(LAC_4[FOR_1]);
	  }
	  R_UART2_SEND(",");NOP();  
// DBM:-4 	  
	  for(FOR_1=0;FOR_1<=DBM_DATA_LENGTH[4];FOR_1++)
	  {
	  NOP();
	  R_UART2_SEND_User(DBM_4[FOR_1]);
	       if(DBM_DATA_LENGTH[4]==2 && FOR_1==0){R_UART2_SEND("0");NOP();}
	  else if(DBM_DATA_LENGTH[4]==1 && FOR_1==0){R_UART2_SEND("00");NOP();}
	  }
	  HEX_CHARACTER_CONVERSION=CLR;
	  R_UART2_SEND(",00");
	  if(PANIC_ALERT_PACKET==ON){R_UART2_SEND("1");}else{R_UART2_SEND("0");}
	  if(IGNITION_SW==CLOSE){R_UART2_SEND("1");}else{R_UART2_SEND("0");}
	
	R_UART2_SEND(",00,");NOP();  
/************************************************************************************************************************************************************/	  



/************************************************************************************************************************************************************/	  
	  FRAME_NUMBER++;
	  if(FRAME_NUMBER>=1000000){FRAME_NUMBER=1;}
	  TEMP_FRAME_NUMBER=FRAME_NUMBER;
	  R_UART2_SEND_User(((TEMP_FRAME_NUMBER/100000)+0x30));
	  
	  TEMP_FRAME_NUMBER=TEMP_FRAME_NUMBER%100000;
	  R_UART2_SEND_User(((TEMP_FRAME_NUMBER/10000)+0x30));
	  
	  TEMP_FRAME_NUMBER=TEMP_FRAME_NUMBER%10000;
	  R_UART2_SEND_User(((TEMP_FRAME_NUMBER/1000)+0x30));
	  
	  TEMP_FRAME_NUMBER=TEMP_FRAME_NUMBER%1000;
	  R_UART2_SEND_User(((TEMP_FRAME_NUMBER/100)+0x30));
	  
	  TEMP_FRAME_NUMBER=TEMP_FRAME_NUMBER%100;
	  R_UART2_SEND_User(((TEMP_FRAME_NUMBER/10)+0x30));
	  R_UART2_SEND_User(((TEMP_FRAME_NUMBER%10)+0x30));
/************************************************************************************************************************************************************/	  
          R_UART2_SEND(",00,*");NOP();NOP();
/************************************************************************************************************************************************************/


URL_PRINT=OFF;	  
}
//void WELCOME_STRING(void)
//{
//	//GET_IMEI();
//R_UART2_SEND("$W,");

//for(FOR_1=0;FOR_1<=9;FOR_1++){if(VEICHLE_NUMBER[FOR_1]!=' '){R_UART2_SEND_User(VEICHLE_NUMBER[FOR_1]);MS_TIMER(1);}} // VR NUMBER
//R_UART2_SEND("$");
//for(FOR_1=1;FOR_1<=15;FOR_1++){R_UART2_SEND_User(IMEI[FOR_1]);NOP();NOP();} //IMEI NUMBER
//R_UART2_SEND("$");
//R_UART2_SEND_User(((CURRENT_FRM_VERSION/100)+0x30));R_UART2_SEND(".");NOP();
//TEMP_FRM_VERSION=CURRENT_FRM_VERSION%100;
//R_UART2_SEND_User(((TEMP_FRM_VERSION/10)+0x30));R_UART2_SEND(".");NOP();
//R_UART2_SEND_User(((TEMP_FRM_VERSION%10)+0x30));						// FRM VERSION
//R_UART2_SEND("$");
//R_UART2_SEND("1.0.1");										// Protocol Version
//R_UART2_SEND("$");
//READ_LAST_LOCATION();
//R_UART2_SEND("$");

//}




void UPDATE_ONLINE_DATA_FRAME(void)
{
//unsigned int T;
//MS_TIMER(1000);
if(REFRESH==ON){REFRESH=OFF;BLUE_LED=ON;GPRS_PS_EN=OFF1;MS_TIMER(200);GPRS_PS_EN=ON1;MS_TIMER(500);//R_UART2_SEND("AT+CRSM=214,28539,0,0,12,\"FFFFFFFFFFFFFFFFFFFFFFFF\"\r\n");
MS_TIMER(500);BLUE_LED=OFF;MS_TIMER(1000);}

restart000:
if(INTERNET_CONNECTED==OFF){
NW_REGN_COUNT=0;
/************************************************************************************************************************************************************/
restart_CMEE:
        
	R_UART2_SEND("AT+CMEE?\r\n");ACK_RX(20,2,10,1); 
	if(RESTART==ON){RESTART=OFF;goto restart_CMEE;}
	R_UART2_SEND("AT+QSPN?\r\n");
    MS_TIMER(300);
    //SwitchNetwork();
/************************************************************************************************************************************************************/
restart_CPIN:
        CPIN=OFF;
	CPIN_READY_CHECK=ON;
	R_UART2_SEND("AT+CPIN?\r\n");ACK_RX(100,6,1,0);
	     if(NW_REGN_COUNT>5){RESTART=OFF;NETWORK_FAILURE++;if(NETWORK_FAILURE>=2){NETWORK_FAILURE=0;INTERNET_CONNECTED=NONE;goto restart09;}BLUE_LED=ON;GPRS_PS_EN=OFF1;MS_TIMER(100);GPRS_PS_EN=ON1;MS_TIMER(500);//R_UART2_SEND("AT+CRSM=214,28539,0,0,12,\"FFFFFFFFFFFFFFFFFFFFFFFF\"\r\n");
MS_TIMER(500);BLUE_LED=OFF;MS_TIMER(300);NW_REGN_COUNT=0;goto restart000;}//GPRS_PS_EN=OFF1 INTERNET_CONNECTED=NONE;
	else if(RESTART==ON){RESTART=OFF;NW_REGN_COUNT++;goto restart_CPIN;}
	     
	     CPIN_READY_CHECK=OFF;
	//NW_REGN_COUNT=0;NETWORK_FAILURE=0;
/************************************************************************************************************************************************************/	
restart00:
	GSM_NW_REG_CHECK=SET;
	
	R_UART2_SEND("AT+CREG?\r\n");ACK_RX(100,0,100,100);
	     if(NW_REGN_COUNT>10){RESTART=OFF;NETWORK_FAILURE++;if(NETWORK_FAILURE>=2){NETWORK_FAILURE=0;INTERNET_CONNECTED=NONE;goto restart09;}BLUE_LED=ON;GPRS_PS_EN=OFF1;MS_TIMER(200);GPRS_PS_EN=ON1;MS_TIMER(5000);//R_UART2_SEND("AT+CRSM=214,28539,0,0,12,\"FFFFFFFFFFFFFFFFFFFFFFFF\"\r\n");
MS_TIMER(500);BLUE_LED=OFF;MS_TIMER(1000);NW_REGN_COUNT=0;goto restart000;}//GPRS_PS_EN=OFF1 INTERNET_CONNECTED=NONE;
	else if(RESTART==ON){RESTART=OFF;NW_REGN_COUNT++;goto restart00;}
	     
	GSM_NW_REG_CHECK=CLR;
	
MS_TIMER(300);
/************************************************************************************************************************************************************/
restart01:
	GPRS_REG_CHECK=SET;
	R_UART2_SEND("AT+CGREG?\r\n");ACK_RX(100,1,100,100);
	MS_TIMER(300);
	R_UART2_SEND("AT+QSSLSTATE?\r\n");
	MS_TIMER(300);
	     if(NW_REGN_COUNT>10){RESTART=OFF;NETWORK_FAILURE++;if(NETWORK_FAILURE>=2){NETWORK_FAILURE=0;INTERNET_CONNECTED=NONE;goto restart09;}BLUE_LED=ON;GPRS_PS_EN=OFF1;MS_TIMER(100);GPRS_PS_EN=ON1;MS_TIMER(5000);//R_UART2_SEND("AT+CRSM=214,28539,0,0,12,\"FFFFFFFFFFFFFFFFFFFFFFFF\"\r\n");
MS_TIMER(500);BLUE_LED=OFF;MS_TIMER(1000);NW_REGN_COUNT=0;goto restart000;}//GPRS_PS_EN=OFF1 INTERNET_CONNECTED=NONE;
	else if(RESTART==ON){RESTART=OFF;NW_REGN_COUNT++;goto restart01;}
	     
	  NW_REGN_COUNT=0;NETWORK_FAILURE=0;
	  GPRS_REG_CHECK=CLR;
/************************************************************************************************************************************************************/

GET_NETWORK_NAME();
if(BSNL_CONNECT_FLAG==1)
	{
		
		//NOP();
		BSNL_CONNECT_FLAG=0;
		goto restart000;
		
	}


if(DISCONNECT==ON){DISCONNECT=OFF;GPRS_DISCONNECT();}

restart4:
           if(GPRS_REG_COUNT>=10){GPRS_REG_COUNT=0;INTERNET_CONNECTED=NONE;goto restart09;}
      //else if(GPRS_REG_COUNT==3){GPRS_DISCONNECT();}
      R_UART2_SEND("AT+QIFGCNT=0\r\n");ACK_RX(100,2,10,1);if(RESTART==ON){RESTART=OFF;GPRS_REG_COUNT++;goto restart4;}
/************************************************************************************************************************************************************/      
        
      R_UART2_SEND("AT+QICSGP=1,\"sensem2m\"\r\n");
      ACK_RX(100,2,10,10);if(RESTART==ON){RESTART=OFF;GPRS_REG_COUNT++;goto restart4;}ACK=0;ERROR_OCCURED=0;
/************************************************************************************************************************************************************/
      INTERNET_CONNECTED=ON;NW_REGN_COUNT=0;
      R_UART2_SEND("AT+QIREGAPP\r\n");ACK_RX(100,2,100,200);if(RESTART==ON){RESTART=OFF;GPRS_REG_COUNT++;goto restart4;}
/************************************************************************************************************************************************************/      
      R_UART2_SEND("AT+CGATT=1\r\n");ACK_RX(100,2,100,200);if(RESTART==ON){GPRS_REG_COUNT++;RESTART=OFF;goto restart4;}
       R_UART2_SEND("AT+QIACT\r\n");ACK_RX(100,2,100,200);if(RESTART==ON){GPRS_REG_COUNT++;RESTART=OFF;goto restart4;}
       R_UART2_SEND("AT+QIDNSIP=1\r\n");ACK_RX(100,2,100,200);
/************************************************************************************************************************************************************/      
      R_UART2_SEND("AT+CGPADDR=1\r\n");MS_TIMER(500);
INTERNET_CONNECTED=ON;NW_REGN_COUNT=0;
      //GET_NETWORK_NAME();//GET_IMEI();
      
      GET_NETWORK_NAME();
      if(BSNL_CONNECT_FLAG==1)
	{
		
		//NOP();
		BSNL_CONNECT_FLAG=0;
		goto restart000;
		
	}
      
      
      
}
if(FIRMWARE_UPDATE==ON)
{
restart_http:
 	  if(HTTP_CONNECT_COUNT>=7){HTTP_CONNECT_COUNT=0;goto restart00;}
	  R_UART2_SEND("AT+QHTTPURL=47,120\r\n");ACK_RX(100,3,100,10);
	       if(DISCONNECT==ON){goto restart000;}
          else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restart_http;}
 	  ACK=0;
/************************************************************************************************************************************************************/  
	  R_UART2_SEND("http://www.lakshikagpstracker.com/devicescript/FIRMWARE.txt");
	  ACK_RX(100,2,100,200);
	  if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restart_http;}
	  ACK=0;ERROR_OCCURED=0;
/************************************************************************************************************************************************************/	  
          R_UART2_SEND("AT+QHTTPGET=120\r\n");
	  ACK_RX(1210,5,100,10);
               if(DISCONNECT==ON){goto restart000;}
	  else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restart_http;}
/************************************************************************************************************************************************************/	

	  R_UART2_SEND("AT+QHTTPDL=\"RAM:1.TXT\",110000\r\n");MS_TIMER(1);
          ACK_RX(600,8,50,5);
	       if(DISCONNECT==ON){goto restart000;}
	  else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restart_http;}
/************************************************************************************************************************************************************/
	  FIRMWARE_DOWNLOADED=ON;
	  FIRMWARE_DOWNLOAD_FROM_M95();
	  ///*GREEN_LED=ON*/;MS_TIMER(5);
	  
 	
}

//WELCOME STRING SEND
///////////////////////////////////////////////////////////////////////////////////////////////////////
//if(INTERNET_CONNECTED==ON && FIRMWARE_UPDATE==OFF && WELCOME_STRING_FRAME==ON)
//{
////restartW10:
	   
//restartW66:
//          if(HTTP_CONNECT_COUNT>=2){INTERNET_CONNECTED=OFF;HTTP_CONNECT_COUNT=0;goto restart000;}
//	  HTTP_PRINT=ON;
	  
//	  R_UART2_SEND("AT+QHTTPURL=128,120\r\n");
//	  ACK_RX(100,3,100,10);
//	       if(DISCONNECT==ON){goto restart000;}
//          else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restartW66;}
// 	  ACK=0;
///************************************************************************************************************************************************************/
	  
	  
//	  R_UART2_SEND("http://www.lakshikagpstracker.com/apis/update-vehicle-tracking.php?datas=");
//	  WELCOME_STRING();
//	  ACK_RX(100,2,100,200);if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restartW66;}
//	  ACK=0;ERROR_OCCURED=0;HTTP_PRINT=OFF;
///************************************************************************************************************************************************************/	  
//         R_UART2_SEND("AT+QHTTPGET=120\r\n");ACK_RX(1210,5,100,10);//MS_TIMER(10);
//               if(DISCONNECT==ON){BLUE_LED=ON;GPRS_PS_EN=OFF1;MS_TIMER(1000);GPRS_PS_EN=ON1;MS_TIMER(500);//R_UART2_SEND("AT+CRSM=214,28539,0,0,12,\"FFFFFFFFFFFFFFFFFFFFFFFF\"\r\n");
//MS_TIMER(500);BLUE_LED=OFF;HTTP_CONNECT_COUNT=0;goto restart000;}
//	  else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restart66;}
//	 /*GREEN_LED=OFF*/;HTTP_CONNECT_COUNT=0;
///************************************************************************************************************************************************************/
//	  R_UART2_SEND("AT+QHTTPREAD=60\r\n");MS_TIMER(1);ACK_RX(700,5,50,5);
//	       if(DISCONNECT==ON){BLUE_LED=ON;GPRS_PS_EN=OFF1;MS_TIMER(1000);GPRS_PS_EN=ON1;MS_TIMER(500);//R_UART2_SEND("AT+CRSM=214,28539,0,0,12,\"FFFFFFFFFFFFFFFFFFFFFFFF\"\r\n");
//MS_TIMER(500);BLUE_LED=OFF;HTTP_CONNECT_COUNT=0;goto restart000;}
//	  else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restart66;}
//	  /*GREEN_LED=ON*/;MS_TIMER(2);/*GREEN_LED=OFF*/;
	  
///************************************************************************************************************************************************************/ 	
//	HTTP_CONNECT_COUNT=0;
//WELCOME_STRING_FRAME=OFF;	  
//}


////////////////////////////////////////////////////////////////////////////////////////////////////////
//if(INTERNET_CONNECTED==ON && FIRMWARE_UPDATE==OFF)
//{
////restart10:
//	   if(FLASH_MEMORY<=0)
//	   {
	
//	   GET_TIME();
	   
//	   GET_SPEED_DATA();
	   
//	   GET_SIGNAL_STRENGTH();
	   
	   
//	   GET_MCC_MNC_LAC_CELL_ID();
	   
	   
//	  //      if(IGNITION_SW==OPEN && T_SPEED>=5 || IGNITION_SW==OPEN && P_LAT_DM_RX!=LAT_DM[3]){GET_DEGREES();}
//	  // else if(IGNITION_SW==CLOSE){GET_DEGREES();}

	   
//	   /* FOR TESTING */	   
///*******************************************************************/	   
//	   GET_DEGREES();
///*******************************************************************/	   
	   
//	   FLASH_WRITE_ADDRESS=1;FLASH_READ_ADDRESS=0;
//	   } 
	   
	   
//	   ERROR_OCCURED=0;ACK=0;GPRS_CONNECTED=0;
	   
//	   //URL_COUNTING();
	   
///************************************************************************************************************************************************************/	   
//restart66:
//          if(HTTP_CONNECT_COUNT>=2){INTERNET_CONNECTED=OFF;HTTP_CONNECT_COUNT=0;goto restart000;}
//	  HTTP_PRINT=ON;
	  
//	  //R_UART2_SEND("AT+QHTTPURL=311,120\r\n");ACK_RX(100,3,100,10);
//	  R_UART2_SEND("AT+QHTTPURL=318,120\r\n");ACK_RX(100,3,100,10);
	  
//	  //R_UART2_SEND("AT+QHTTPURL=310,120\r\n");ACK_RX(100,3,100,10);
//	  ///R_UART2_SEND("AT+QHTTPURL=");NOP();
//	  //TEMP_URL_COUNT=URL_COUNT%100;
	  
//	  // R_UART2_SEND_User(((URL_COUNT/100)+0x30));NOP();
//	  // R_UART2_SEND_User(((TEMP_URL_COUNT/10)+0x30));NOP();
//	  // R_UART2_SEND_User(((TEMP_URL_COUNT%10)+0x30));NOP();
	   
//	  //R_UART2_SEND(",120\r\n");NOP();
//	  //ACK_RX(100,3,100,10);
//	       if(DISCONNECT==ON){goto restart000;}
//          else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restart66;}
// 	  ACK=0;
///************************************************************************************************************************************************************/
	  
//	  R_UART2_SEND("http://lakshikagpstracker.com");
//	  R_UART2_SEND("/apis/update-vlt-tracking");
//	  R_UART2_SEND(".php?vltdatas=");
//	  DATA_PRINT(0);
//	  ACK_RX(100,2,100,200);
	  
	  
//	  if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restart66;}
//	  ACK=0;ERROR_OCCURED=0;HTTP_PRINT=OFF;
///************************************************************************************************************************************************************/	  
//          R_UART2_SEND("AT+QHTTPGET=120\r\n");ACK_RX(100,5,100,10);//MS_TIMER(10);
//               if(DISCONNECT==ON){BLUE_LED=ON;GPRS_PS_EN=OFF1;MS_TIMER(1000);GPRS_PS_EN=ON1;MS_TIMER(500);//R_UART2_SEND("AT+CRSM=214,28539,0,0,12,\"FFFFFFFFFFFFFFFFFFFFFFFF\"\r\n");
//MS_TIMER(500);BLUE_LED=OFF;HTTP_CONNECT_COUNT=0;goto restart000;}
//	  else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restart66;}
//	 /*GREEN_LED=OFF*/;HTTP_CONNECT_COUNT=0;
///************************************************************************************************************************************************************/
//	  R_UART2_SEND("AT+QHTTPREAD=60\r\n");ACK_RX(100,5,50,5);
//	       if(DISCONNECT==ON){BLUE_LED=ON;GPRS_PS_EN=OFF1;MS_TIMER(1000);GPRS_PS_EN=ON1;MS_TIMER(500);//R_UART2_SEND("AT+CRSM=214,28539,0,0,12,\"FFFFFFFFFFFFFFFFFFFFFFFF\"\r\n");
//MS_TIMER(500);BLUE_LED=OFF;HTTP_CONNECT_COUNT=0;goto restart000;}
//	  else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restart66;}
//	  /*GREEN_LED=ON*/;MS_TIMER(5);/*GREEN_LED=OFF*/;
	  
///************************************************************************************************************************************************************/ 	
//	HTTP_CONNECT_COUNT=0;
//	    //if(FLASH_MEMORY>0){WATCH_DOG_KILL=OFF;MS_TIMER(10);goto restart10;}
//	  //else {WRITE_ADDRESS=0;DATA=0;}
///************************************************************************************************************************************************************/	  
//	  //if(CURRENT_FRM_VERSION!=FRM_VERSION && GPS_DIRECTION_DATA_VALID==ON && FIRM_UPDATE_CONTROL_STATE==ON) 
//	  if(CURRENT_FRM_VERSION!=FRM_VERSION && FIRM_UPDATE_CONTROL_STATE==ON) 
//	  {
//	  FIRMWARE_UPDATE=ON;
//	  }
//	   if(GPS_DIRECTION_DATA_VALID==ON){STORE_LAST_LOCATION();}
	  	  
//}

//if(INTERNET_CONNECTED==ON && FIRMWARE_UPDATE==OFF)
//{
restart10:
	  // if(FLASH_MEMORY<=0)
	  // {
	
//	   GET_TIME();
	   
//	   GET_SPEED_DATA();
	   
//	   GET_SIGNAL_STRENGTH();
	   
	   
//	   GET_MCC_MNC_LAC_CELL_ID();
	   
	   
	       // if(IGNITION_SW==OPEN && T_SPEED>=0 || IGNITION_SW==OPEN && P_LAT_DM_RX[7]!=LAT_DM[3]){GET_DEGREES();}
	  // else if(IGNITION_SW==CLOSE){GET_DEGREES();}
//GPS_DATA:
	  // GET_DEGREES();
	   
	
	   ERROR_OCCURED=0;ACK=0;GPRS_CONNECTED=0;
	   
	   //URL_COUNTING();
	   
/************************************************************************************************************************************************************/	   
restart66:
          if(HTTP_CONNECT_COUNT>=2){INTERNET_CONNECTED=OFF;HTTP_CONNECT_COUNT=0;goto restart000;}
	  HTTP_PRINT=ON;
	  
//updatedata=0;
//MS_TIMER(500);
	  R_UART2_SEND("AT+QIOPEN=");      
      R_UART2_SEND("\"TCP\",\"www.lakshikagpstracker.com\",9000");
      R_UART2_SEND("\r\n");
            ACK_RX(500,3,100,10);
	  if(DISCONNECT==ON){goto restart000;}
	 else if( CONNECT_FAIL==ON){GPRS_PS_EN=OFF;MS_TIMER(2000);GPRS_PS_EN=ON;MS_TIMER(500);R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n ");MS_TIMER(500);R_UART2_SEND("AT+CRSM=214,28539,0,0,12,\"FFFFFFFFFFFFFFFFFFFFFFFF\"\r\n");MS_TIMER(500);CONNECT_FAIL=OFF;goto restart00;}
	  else if( ALREADY_CONNECT==ON){R_UART2_SEND("AT+QICLOSE\r\n");MS_TIMER(500);ALREADY_CONNECT=OFF;goto restart10;}
          else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restart66;}
 	  ACK=0;
	  
	  if(INTERNET_CONNECTED==ON && FIRMWARE_UPDATE==OFF)
{
	//unsigned int resend;CONNECT_FAIL
RESTART_SEND:
//SYSTEM_ALERT_CHECK();
 GET_GPS_DATA();
GET_TIME();
GET_DEGREES();
//	   
	   GET_SPEED_DATA();
//	   
	   GET_SIGNAL_STRENGTH();
//	   
//	   
	   GET_MCC_MNC_LAC_CELL_ID();
	   
	   SYSTEM_STATUS();
//	   
//	   
//	       // if(IGNITION_SW==OPEN && T_SPEED>=0 || IGNITION_SW==OPEN && P_LAT_DM_RX[7]!=LAT_DM[3]){GET_DEGREES();}
//	  // else if(IGNITION_SW==CLOSE){GET_DEGREES();}
////GPS_DATA:
//	   GET_DEGREES();
 R_UART2_SEND("AT+QISEND\r\n");MS_TIMER(10);
/************************************************************************************************************************************************************/
//if(ACTIVATION_CMD_1==SET)
//{
//	HEALTH_FRAME_NUMBER++;
//	HEALTH(101);
//	ACTIVATION_CMD_1=OFF;
//}
//else if (HEALTH_CMD2_1==SET)
//{
//	HEALTH_FRAME_NUMBER++;
//	HEALTH(100);
//	HEALTH_CMD2_1=OFF;
//}1 
//else if (IGNITION_ON_PACKET==ON && WELCOME_STRING_FRAME ==ON)
//{
//	WELCOME_STRING();
//	WELCOME_STRING_FRAME=OFF;
	
//}
//else if (HEALTH_CMD2_1==OFF || ACTIVATION_CMD_1==OFF )
//{
//	  DATA_PRINT(0);
	  //resend++;
	//  updatedata++;
//}
//if(ACTIVATION_CMD_1==SET)
//{
//	HEALTH_FRAME_NUMBER++;
//	HEALTH(101);
//	ACTIVATION_CMD_1=OFF;
//}
//else if (HEALTH_CMD2_1==SET)
//{
//	HEALTH_FRAME_NUMBER++;
//	HEALTH(100);
//	HEALTH_CMD2_1=OFF;
//}
if(BOOT_FLAG==1)
{
	//BOOT_STRING();
WELCOME_STRING();
	BOOT_FLAG=0;
	WELCOME_STRING_FRAME_BOOT=1;
}
else if (WELCOME_STRING_FRAME_BOOT ==1)
{
	WELCOME_STRING();
	WELCOME_STRING_FRAME_BOOT=0;
}
else if (IGNITION_ON_PACKET==ON && WELCOME_STRING_FRAME ==ON)
{
	WELCOME_STRING();
	WELCOME_STRING_FRAME=OFF;
	
}
else 
{
	  DATA_PRINT(0);
	  VLT_STARTUP_INITIAL=0;
	 // resend++;
	//  updatedata++;
}
	  
	     R_UART2_SEND_User(CTRL_Z);
      ACK_RX(100,2,500,200); 
      if(RESTART==ON){GPRS_REG_COUNT++;RESTART=OFF;GPRS_PS_EN=OFF;MS_TIMER(2000);GPRS_PS_EN=ON;MS_TIMER(500);goto restart4;}
      /************************************************************************************************************************************************************/      
      R_UART2_SEND("AT+QISACK\r\n");
      ACK_RX(100,2,500,1000);if(DISCONNECT==ON){goto restart000;}else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto RESTART_SEND;}
      ACK=0;
/************************************************************************************************************************************************************/               
      R_UART2_SEND("AT+QIRD=0,1,0,1024\r\n");
      ACK_RX(1000,2,500,1000);if(DISCONNECT==ON){goto restart000;}else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto RESTART_SEND;}
      ACK=0;
       
//      if(resend>=10)
//      {
//	      GREEN_LED=ON;
//	      NOP();
//	      resend=0;
//     goto CLOSE_SEND;
//      }
//      goto RESTART_SEND;
if(ERROR_OCCURED==1 || PANIC_ALERT==ON || SET_OTA_UPDATE==SET || NEW_SMS>=1 || GPS_RST_FLAG==ON || (IGNITION_SW==OPEN && WELCOME_STRING_FRAME==OFF && WELCOME_STRING_FRAME_BOOT==0 && BOOT_FLAG==0 && HEALTH_PACKET_TO_SERVER==0 && VLT_STARTUP_INITIAL==0)|| HEALTH_PACKET_TO_SERVER==1)
{
	GREEN_LED=ON;MS_TIMER(50);GREEN_LED=OFF;SET_OTA_UPDATE=CLR;
	goto CLOSE_SEND; NOP(); NOP();
} 
    if(ERROR_OCCURED==0)
{
GREEN_LED=ON;MS_TIMER(50);GREEN_LED=OFF;
 SYSTEM_ALERT_CHECK();

goto RESTART_SEND;
}

}
    //  if(updatedata>=2){NOP();}else{GREEN_LED=ON;MS_TIMER(50);GREEN_LED=OFF; goto  RESTART_SEND;}ERROR_OCCURED
/************************************************************************************************************************************************************/         
CLOSE_SEND:      
R_UART2_SEND("AT+QICLOSE\r\n");
      ACK_RX(100,2,100,200);if(DISCONNECT==ON){goto restart000;}else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto RESTART_SEND;}
      ACK=0;
	  
	  if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restart66;}
	  ACK=0;ERROR_OCCURED=0;HTTP_PRINT=OFF;

	  GREEN_LED=ON;MS_TIMER(50);GREEN_LED=OFF;
//goto RESTART_SEND;	  
/************************************************************************************************************************************************************/ 	
	HTTP_CONNECT_COUNT=0;
	
	  if(CURRENT_FRM_VERSION!=FRM_VERSION && FIRM_UPDATE_CONTROL_STATE==ON) 
	  {
	  FIRMWARE_UPDATE=ON;
	  }
	   if(GPS_DIRECTION_DATA_VALID==ON){STORE_LAST_LOCATION();}
	  	  
//}




/************************************************************************************************************************************************************/
if(INTERNET_CONNECTED==ON && FIRMWARE_UPDATE==OFF && PANIC_ALERT_PACKET==ON)
{


	GET_TIME();
	   GET_SPEED_DATA();
	   GET_SIGNAL_STRENGTH();
	   GET_MCC_MNC_LAC_CELL_ID();
	   
	   //     if(IGNITION_SW==OPEN && T_SPEED>=5 || IGNITION_SW==OPEN && P_LAT_DM_RX!=LAT_DM[3]){GET_DEGREES();}
	   //else if(IGNITION_SW==CLOSE){GET_DEGREES();}
GET_DEGREES();
	   
   ERROR_OCCURED=0;ACK=0;GPRS_CONNECTED=0;
		   
/************************************************************************************************************************************************************/	   
for(PANIC_SERVER_COUNT=0;PANIC_SERVER_COUNT<=1;PANIC_SERVER_COUNT++)
{
restartP2:
          if(HTTP_CONNECT_COUNT>=2){INTERNET_CONNECTED=OFF;HTTP_CONNECT_COUNT=0;goto restart000;}
	  HTTP_PRINT=ON;
if(PANIC_SERVER_COUNT==0)
{
	  R_UART2_SEND("AT+QIOPEN=");      
      R_UART2_SEND("\"TCP\",\"www.lakshikagpstracker.com\",9000");
//      R_UART2_SEND("\r\n");
// R_UART2_SEND("AT+QIOPEN=\"TCP\",\"");    
//	   // R_UART2_SEND("AT+QIOPEN="); 
//	    // R_UART2_SEND("AT+QIOPEN="); 
//	    for(FOR_1=0;FOR_1<=14;FOR_1++)
//{
//R_UART2_SEND_User(TEMP_TCP_EE[FOR_1]);
//MS_TIMER(1);
//}
//R_UART2_SEND("\",");
//	    for(FOR_1=16;FOR_1<=19;FOR_1++)
//{
//R_UART2_SEND_User(TEMP_TCP_EE[FOR_1]);
//MS_TIMER(1);
//}

    // R_UART2_SEND("\"TCP\",\"103.129.98.194\",9000");
      R_UART2_SEND("\r\n");
            ACK_RX(3000,3,100,100);
	       if(DISCONNECT==ON){goto restart000;}
	       else if( ALREADY_CONNECT==ON){R_UART2_SEND("AT+QICLOSE\r\n");ALREADY_CONNECT=OFF;goto restartP2;}
          else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restartP2;}
 	  ACK=0;
//RESTART_SEND:
 R_UART2_SEND("AT+QISEND\r\n");MS_TIMER(10);
/************************************************************************************************************************************************************/
	//  R_UART2_SEND("http://103.129.98.194/apis/update-panic-alert.php?datas=");
	//  R_UART2_SEND("http://103.129.98.208/apis/update-vehicle-tracking.php?datas=");
	  //DATA_PRINT(0);/*data modified on 13112019*/
	  GSM_INTZ(DATA_MODE);
	  R_UART2_SEND_User(CTRL_Z);
     ACK_RX(500,2,100,100);
	  if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restartP2;}
	  ACK=0;ERROR_OCCURED=0;HTTP_PRINT=OFF;
      /************************************************************************************************************************************************************/      
      R_UART2_SEND("AT+QISACK\r\n");
      ACK_RX(500,2,500,500);if(DISCONNECT==ON){goto restart000;}else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto RESTART_SEND;}
      ACK=0;
/************************************************************************************************************************************************************/               
      R_UART2_SEND("AT+QIRD=0,1,0,1024\r\n");
      ACK_RX(500,2,500,500);if(DISCONNECT==ON){goto restart000;}else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto RESTART_SEND;}
      ACK=0;
/************************************************************************************************************************************************************/         
      R_UART2_SEND("AT+QICLOSE\r\n");
      ACK_RX(100,2,100,200);if(DISCONNECT==ON){goto restart000;}else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto RESTART_SEND;}
      ACK=0;
	  
	  if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restart66;}
	  ACK=0;ERROR_OCCURED=0;HTTP_PRINT=OFF;

	  GREEN_LED=ON;MS_TIMER(50);GREEN_LED=OFF;  
}
else
{
	  
	  R_UART2_SEND("AT+QIOPEN=");      
 R_UART2_SEND("\"TCP\",\"www.vehisafe.in\",9000");//103.93.17.117
//     R_UART2_SEND("\"TCP\",\"103.93.17.117\",9000");
//      R_UART2_SEND("\r\n");
// R_UART2_SEND("AT+QIOPEN=\"TCP\",\"");    
//	   // R_UART2_SEND("AT+QIOPEN="); 
//	    // R_UART2_SEND("AT+QIOPEN="); 
//	    for(FOR_1=21;FOR_1<=35;FOR_1++)
//{
//R_UART2_SEND_User(TEMP_TCP_EE[FOR_1]);
//MS_TIMER(1);
//}
//R_UART2_SEND("\",");
//	    for(FOR_1=37;FOR_1<=40;FOR_1++)
//{
//R_UART2_SEND_User(TEMP_TCP_EE[FOR_1]);
//MS_TIMER(1);
//}

    // R_UART2_SEND("\"TCP\",\"103.129.98.194\",9000");
      R_UART2_SEND("\r\n");
            ACK_RX(3000,3,100,100);
	       if(DISCONNECT==ON){goto restart000;}
	       else if( ALREADY_CONNECT==ON){R_UART2_SEND("AT+QICLOSE\r\n");ALREADY_CONNECT=OFF;goto restartP2;}
          else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restartP2;}
 	  ACK=0;
	//  RESTART_SEND:
 R_UART2_SEND("AT+QISEND\r\n");MS_TIMER(10);
/************************************************************************************************************************************************************/
	 // R_UART2_SEND("http://103.129.98.194/apis/update-panic-alert.php?datas=");
	//  R_UART2_SEND("http://103.129.98.208/apis/update-panic-alert.php?datas=");
	  GSM_INTZ(DATA_MODE);
	R_UART2_SEND_User(CTRL_Z);
     ACK_RX(500,2,100,100);
	  if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restartP2;}
	  ACK=0;ERROR_OCCURED=0;HTTP_PRINT=OFF;
      /************************************************************************************************************************************************************/      
      R_UART2_SEND("AT+QISACK\r\n");
     ACK_RX(500,2,500,500);if(DISCONNECT==ON){goto restart000;}else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto RESTART_SEND;}
      ACK=0;
/************************************************************************************************************************************************************/               
      R_UART2_SEND("AT+QIRD=0,1,0,1024\r\n");
      ACK_RX(500,2,500,500);if(DISCONNECT==ON){goto restart000;}else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto RESTART_SEND;}
      ACK=0;
/************************************************************************************************************************************************************/         
      R_UART2_SEND("AT+QICLOSE\r\n");
      ACK_RX(100,2,100,200);if(DISCONNECT==ON){goto restart000;}else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto RESTART_SEND;}
      ACK=0;
	  
	  if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restart66;}
	  ACK=0;ERROR_OCCURED=0;HTTP_PRINT=OFF;

	  GREEN_LED=ON;MS_TIMER(50);GREEN_LED=OFF;  
	  
}

 
if(PANIC_SERVER_COUNT==1){break;}
}	  	  
}
/***************************************************************************************************************************************/
if(INTERNET_CONNECTED==ON && FIRMWARE_UPDATE==OFF && HEALTH_PACKET_TO_SERVER==SET)
{
restartP5:
	  R_UART2_SEND("AT+QIOPEN=");      
      R_UART2_SEND("\"TCP\",\"www.lakshikagpstracker.com\",9000");
      R_UART2_SEND("\r\n");
            ACK_RX(3000,3,100,100);
	       if(DISCONNECT==ON){goto restart000;}
	       else if( ALREADY_CONNECT==ON){R_UART2_SEND("AT+QICLOSE\r\n");ALREADY_CONNECT=OFF;goto restartP5;}
          else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restartP5;}
 	  ACK=0;
	//  RESTART_SEND:
 R_UART2_SEND("AT+QISEND\r\n");MS_TIMER(10);
/************************************************************************************************************************************************************/
	//  R_UART2_SEND("http://103.129.98.194/apis/update-health-pack.php?datas=");
	  ////DEVICE_REPLY_IN_SMS(100);
	  HEALTH_STRING();
	 
	  
 R_UART2_SEND_User(CTRL_Z);
      ACK_RX(500,2,100,100);
	  if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restartP5;}
	  ACK=0;ERROR_OCCURED=0;HTTP_PRINT=OFF;
      /************************************************************************************************************************************************************/      
      R_UART2_SEND("AT+QISACK\r\n");
      ACK_RX(500,2,500,500);if(DISCONNECT==ON){goto restart000;}else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto RESTART_SEND;}
      ACK=0;
/************************************************************************************************************************************************************/               
      R_UART2_SEND("AT+QIRD=0,1,0,1024\r\n");
      ACK_RX(500,2,500,500);if(DISCONNECT==ON){goto restart000;}else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto RESTART_SEND;}
      ACK=0;
/************************************************************************************************************************************************************/         
      R_UART2_SEND("AT+QICLOSE\r\n");
      ACK_RX(100,2,100,200);if(DISCONNECT==ON){goto restart000;}else if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto RESTART_SEND;}
      ACK=0;
	  
	  if(RESTART==ON){HTTP_CONNECT_COUNT++;RESTART=OFF;goto restart66;}
	  ACK=0;ERROR_OCCURED=0;HTTP_PRINT=OFF;

	  GREEN_LED=ON;MS_TIMER(50);GREEN_LED=OFF;HEALTH_PACKET_TO_SERVER=CLR;

}	  	  


/***************************************************************************************************************************************/



restart09:
if(INTERNET_CONNECTED==NONE)
{
	/*GREEN_LED=ON*/;
	INTERNET_CONNECTED=OFF;
	NW_REGN_COUNT=0;NETWORK_FAILURE=0;RESTART=OFF;
	MS_TIMER(1);
	WATCH_DOG_KILL=OFF;
	DATA_TO_ARRAY();
	FLASH_WRITE();
	/*GREEN_LED=OFF*/;
	BLUE_LED=ON;
	GPRS_PS_EN=OFF1;
	MS_TIMER(200);
	GPRS_PS_EN=ON1;
	MS_TIMER(500);
	//R_UART2_SEND("AT+CRSM=214,28539,0,0,12,\"FFFFFFFFFFFFFFFFFFFFFFFF\"\r\n");
MS_TIMER(500);
	BLUE_LED=OFF;
	SwitchNetwork();
}
}

void HEALTH_STRING(void)
{
R_UART2_SEND("$,HCHKR,777777,VIDD,V");
R_UART2_SEND_User(((CURRENT_FRM_VERSION/100)+0x30));R_UART2_SEND(".");NOP();
TEMP_FRM_VERSION=CURRENT_FRM_VERSION%100;
R_UART2_SEND_User(((TEMP_FRM_VERSION/10)+0x30));R_UART2_SEND(".");NOP();
R_UART2_SEND_User(((TEMP_FRM_VERSION%10)+0x30));
R_UART2_SEND(",");NOP();
/*****************************************************************************************************/
// IMEI NUMBER
for(FOR_1=1;FOR_1<=15;FOR_1++){R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);NOP();NOP();} //IMEI NUMBER
/*****************************************************************************************************/
/*****************************************************************************************************/
// ALERT ID
R_UART2_SEND(",01,0");
/*****************************************************************************************************/
for(FOR_1=0;FOR_1<=7;FOR_1++){NOP(); //LATITUDE AND DIRECTION
R_UART2_SEND_User(LAT_DM[FOR_1]);
if(FOR_1==1){R_UART2_SEND(".");}}
if(LAT_DIRECTION=='N'){R_UART2_SEND(",N,");}else{R_UART2_SEND(",S,");}
/************************************************************************************************************************************************************/
for(FOR_1=0;FOR_1<=8;FOR_1++){NOP(); //LONGITUDE AND DIRECTION
R_UART2_SEND_User(LOG_DM[FOR_1]);
if(FOR_1==2){R_UART2_SEND(".");}}
if(LON_DIRECTION=='E'){R_UART2_SEND(",E,");}else{R_UART2_SEND(",W,");} NOP();
/************************************************************************************************************************************************************/

R_UART2_SEND_User(Array_0[GPS_DIRECTION_DATA_VALID]);R_UART2_SEND(",");NOP(); //GPS VALID OR INVALID
/************************************************************************************************************************************************************/
for(FOR_1=0;FOR_1<=5;FOR_1++)
{
R_UART2_SEND_User(((TIME[FOR_1] & 0xF0)>>4)+0X30);
R_UART2_SEND_User((TIME[FOR_1] & 0x0F)+0X30);
//if(FOR_1==2 && REPLY==100){R_UART2_SEND("+");}
//if(FOR_1==2 && REPLY==1){R_UART2_SEND(" ");}
if(FOR_1==1)
{
R_UART2_SEND("20");
}
}
R_UART2_SEND(",");
if(COG_VALUE_COUNT==1){R_UART2_SEND("00");COG_VALUE_COUNT=3; NOP();}
else if(COG_VALUE_COUNT==2){R_UART2_SEND("0");COG_VALUE_COUNT=4;NOP();}
else{COG_VALUE_COUNT=5;}
DECIMAL_POINT=OFF;
for(FOR_1=0;FOR_1<=COG_VALUE_COUNT;FOR_1++)
{
NOP();
if(COG[FOR_1]=='.' && DECIMAL_POINT==ON){DECIMAL_POINT=OFF;COG[FOR_1]='0';}
else if(COG[FOR_1]=='.'){DECIMAL_POINT=ON;}
R_UART2_SEND_User(COG[FOR_1]);
}
/************************************************************************************************************************************************************/
if(ADD_ZERO_TO_SPEED==SET){R_UART2_SEND("0");}
R_UART2_SEND(",");
for(FOR_1=0;FOR_1<=SPEED_DATA_LENGTH_COUNT;FOR_1++)
{
NOP();
R_UART2_SEND_User(SPEED_DATA[FOR_1]);
}
DECIMAL_POINT_CAME_STOP_TX=OFF;
NOP();
R_UART2_SEND(",");
NOP();
/************************************************************************************************************************************************************/
R_UART2_SEND_User(Array_0[GSM_STRENGTH/10]);NOP();R_UART2_SEND_User(Array_0[GSM_STRENGTH%10]);NOP();	//GSM SIGNAL STRENGTH
/************************************************************************************************************************************************************/
R_UART2_SEND(",404,");

HEX_CHARACTER_CONVERSION=SET;
if(MNC_DATA_LENGTH==0 || MNC[0]==0x78){R_UART2_SEND("00");}
else
{
if(MNC_DATA_LENGTH>=2){MNC_DATA_LENGTH=1;}
for(FOR_1=0;FOR_1<=MNC_DATA_LENGTH;FOR_1++)
{
NOP();
R_UART2_SEND_User(MNC[FOR_1]);
}
}
HEX_CHARACTER_CONVERSION=CLR;
R_UART2_SEND(",");

PRINT_ZEROS(LAC_DATA_LENGTH_0);
for(FOR_1=0;FOR_1<=LAC_DATA_LENGTH_0;FOR_1++)
{
NOP();
R_UART2_SEND_User(LAC[FOR_1]);
}
R_UART2_SEND(",");

if(MAIN_BAT_STATUS==OFF){R_UART2_SEND("0,");}else{MAIN_BAT_STATUS=ON;R_UART2_SEND("1,");}NOP(); // MAIN BATTERY STATUS

R_UART2_SEND_User(Array_0[IGNITION]);NOP();R_UART2_SEND(",");NOP(); // IGNITION
/************************************************************************************************************************************************************/


BATTERY_MEASUREMENT=ON;
R_UART2_SEND_User(((MAIN_BATTERY_VOLTAGE/100)+0x30));
VOLT=MAIN_BATTERY_VOLTAGE%100;
R_UART2_SEND_User(((VOLT/10)+0x30));NOP();R_UART2_SEND(".");
R_UART2_SEND_User(((VOLT%10)+0x30));R_UART2_SEND(",");//MAIN BATTERY VOLTAGE
/************************************************************************************************************************************************************/

if(HEALTH_FRAME_NUMBER>=1000000){HEALTH_FRAME_NUMBER=1;}
TEMP_FRAME_NUMBER=HEALTH_FRAME_NUMBER;
R_UART2_SEND_User(((TEMP_FRAME_NUMBER/100000)+0x30));

TEMP_FRAME_NUMBER=TEMP_FRAME_NUMBER%100000;
R_UART2_SEND_User(((TEMP_FRAME_NUMBER/10000)+0x30));

TEMP_FRAME_NUMBER=TEMP_FRAME_NUMBER%10000;
R_UART2_SEND_User(((TEMP_FRAME_NUMBER/1000)+0x30));

TEMP_FRAME_NUMBER=TEMP_FRAME_NUMBER%1000;
R_UART2_SEND_User(((TEMP_FRAME_NUMBER/100)+0x30));

TEMP_FRAME_NUMBER=TEMP_FRAME_NUMBER%100;
R_UART2_SEND_User(((TEMP_FRAME_NUMBER/10)+0x30));
R_UART2_SEND_User(((TEMP_FRAME_NUMBER%10)+0x30));
/************************************************************************************************************************************************************/

R_UART2_SEND(",ID");

}

void DATA_TO_ARRAY(void)
{
GET_TIME();
GET_SPEED_DATA();
GET_SIGNAL_STRENGTH();
GET_MCC_MNC_LAC_CELL_ID();
	   
//if(IGNITION_SW==OPEN && T_SPEED>=5 || IGNITION_SW==OPEN && P_LAT_DM_RX!=LAT_DM[3]){GET_DEGREES();}
//else if(IGNITION_SW==CLOSE){GET_DEGREES();}

GET_DEGREES();

/************************************************************************************************************************************************************/	  
	  					  //START CHARACTER , HEADER , VENDOR ID, FIRMWARE VERSION
  
	       if(PANIC_ALERT_PACKET==ON){SEND_TO_ARRAY("EA,02,");}
	  else if(IGNITION_ON_PACKET==ON){SEND_TO_ARRAY("IN,05,");}
	  else if(IGNITION_OFF_PACKET==ON){SEND_TO_ARRAY("IF,06,");}
	  else if(POWER_SOURCE_PACKET==ON){SEND_TO_ARRAY("BD,07,");}
	  else if(POWER_SOURCE_RECONNECT_PACKET==ON){SEND_TO_ARRAY("BR,08,");}
	  else if(LOW_BATTERY_ALERT_PACKET==ON){SEND_TO_ARRAY("BL,09,");}
	  else{SEND_TO_ARRAY("NR,02,");}						 //NR-NORMAL , EA-EMERGENCY ALERT
/************************************************************************************************************************************************************/	  
	  
	    SEND_TO_ARRAY_Value(Array_0[GPS_DIRECTION_DATA_VALID]);SEND_TO_ARRAY(",");NOP();				   //GPS VALID OR INVALID
	 
	  
/************************************************************************************************************************************************************/	  
	  for(FOR_1=0;FOR_1<=5;FOR_1++){SEND_TO_ARRAY_Value(((TIME[FOR_1] & 0xF0)>>4)+0X30);SEND_TO_ARRAY_Value((TIME[FOR_1] & 0x0F)+0X30);if(FOR_1==1){SEND_TO_ARRAY("20");}if(FOR_1==2 || FOR_1==5){SEND_COMMA_TO_ARRAY();}}
	  																						//RTC:- DDMMYYYY,HHMMSS,
	  
																							
///************************************************************************************************************************************************************/																							
	   for(FOR_1=0;FOR_1<=7;FOR_1++){NOP();		//LATITUDE AND DIRECTION
	   SEND_TO_ARRAY_Value(LAT_DM[FOR_1]);
	   if(FOR_1==1){SEND_TO_ARRAY(".");}}
	   if(LAT_DIRECTION=='N'){SEND_TO_ARRAY(",N,");}else{SEND_TO_ARRAY(",S,");}
///************************************************************************************************************************************************************/	  
	  for(FOR_1=0;FOR_1<=8;FOR_1++){NOP();		//LONGITUDE AND DIRECTION
	  SEND_TO_ARRAY_Value(LOG_DM[FOR_1]);
	  if(FOR_1==2){SEND_TO_ARRAY(".");}}
	  if(LON_DIRECTION=='E'){SEND_TO_ARRAY(",E,");}else{SEND_TO_ARRAY(",W,");} NOP();
///************************************************************************************************************************************************************/
//	 

	  GET_SPEED_DATA();
	  
	  if(ADD_ZERO_TO_SPEED==SET){SEND_TO_ARRAY("0");}
	  for(FOR_1=0;FOR_1<=SPEED_DATA_LENGTH_COUNT;FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(SPEED_DATA[FOR_1]);
	  }
	  DECIMAL_POINT_CAME_STOP_TX=OFF;
	  NOP();
	  SEND_COMMA_TO_ARRAY();
	  NOP();
	  
///************************************************************************************************************************************************************/	  
	  COG_VALUE_COUNT=CLR;
	  for(FOR_1=0;FOR_1<=5;FOR_1++)
	  {
	  NOP();
	  if(COG[FOR_1]!='.')
	  {
		  COG_VALUE_COUNT++;
	  }
	  else if(COG[FOR_1]=='.')
	  {
	  break;
	  }
	  }
	       if(COG_VALUE_COUNT==1) {SEND_TO_ARRAY("00");COG_VALUE_COUNT=3; NOP();}
	  else if(COG_VALUE_COUNT==2) {SEND_TO_ARRAY_Value("0");COG_VALUE_COUNT=4;NOP();}
	  else {COG_VALUE_COUNT=5;}
	  	  
          for(FOR_1=0;FOR_1<=COG_VALUE_COUNT;FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(COG[FOR_1]);
	  }
//	  // HEADING :-COURSE OVER GROUND IN DEGREE
	  SEND_COMMA_TO_ARRAY();
	  
	  SEND_TO_ARRAY_Value((NO_OF_SAT/10)+0x30);SEND_TO_ARRAY_Value((NO_OF_SAT%10)+0x30);SEND_TO_ARRAY(",");NOP(); 		// NO OF SATELLITE
//	  
///************************************************************************************************************************************************************/
	  ALTITUDE_VALUE_COUNT=CLR;
	  for(FOR_1=0;FOR_1<=4;FOR_1++)
	  {
	  NOP();
	  if(ALTITUDE[FOR_1]!='.')
	  {
		  ALTITUDE_VALUE_COUNT++;
	  }
	  else if(ALTITUDE[FOR_1]=='.')
	  {
	  break;
	  }
	  }
	       if(ALTITUDE_VALUE_COUNT==1){SEND_TO_ARRAY("00");ALTITUDE_VALUE_COUNT=2; NOP();}
	  else if(ALTITUDE_VALUE_COUNT==2){SEND_TO_ARRAY("0");ALTITUDE_VALUE_COUNT=3;NOP();}
	  else{ALTITUDE_VALUE_COUNT=4;}
	  for(FOR_1=0;FOR_1<=ALTITUDE_VALUE_COUNT;FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(ALTITUDE[FOR_1]);
	  }

	  //R_UART2_SEND(",0.00,"); NOP();
	  
	  SEND_COMMA_TO_ARRAY();
	  
	  for(FOR_1=0;FOR_1<=4;FOR_1++)
	  {
	  NOP();
	  if(PDOP_DATA_RX[FOR_1]=='1' || PDOP_DATA_RX[FOR_1]=='2' || PDOP_DATA_RX[FOR_1]=='3' || PDOP_DATA_RX[FOR_1]=='4' || PDOP_DATA_RX[FOR_1]=='5' || PDOP_DATA_RX[FOR_1]=='6' || PDOP_DATA_RX[FOR_1]=='7' || PDOP_DATA_RX[FOR_1]=='8' || PDOP_DATA_RX[FOR_1]=='9' || PDOP_DATA_RX[FOR_1]=='0'|| PDOP_DATA_RX[FOR_1]=='.')
	  {
	  SEND_TO_ARRAY_Value(PDOP_DATA_RX[FOR_1]);
	  }
	  else{SEND_TO_ARRAY("0");}
	  }

	  SEND_COMMA_TO_ARRAY();
///************************************************************************************************************************************************************/	  
	  
	  for(FOR_1=0;FOR_1<=4;FOR_1++)
	  {
	  NOP();
	  if(HDOP[FOR_1]=='1' || HDOP[FOR_1]=='2' || HDOP[FOR_1]=='3' || HDOP[FOR_1]=='4' || HDOP[FOR_1]=='5' || HDOP[FOR_1]=='6' || HDOP[FOR_1]=='7' || HDOP[FOR_1]=='8' || HDOP[FOR_1]=='9' || HDOP[FOR_1]=='0'|| HDOP[FOR_1]=='.')
	  {
	  SEND_TO_ARRAY_Value(HDOP[FOR_1]);
	  }
	  else{SEND_TO_ARRAY("0");}
	  }

	  SEND_COMMA_TO_ARRAY();   //HDOP
///************************************************************************************************************************************************************/	  
//******	  for(FOR_1=0;FOR_1<=7;FOR_1++){NOP();R_UART2_SEND_User(NETWORK_NAME[FOR_1]);}R_UART2_SEND(",");NOP();   //NETWORK OPEATOR NAME
///************************************************************************************************************************************************************/
	  NOP();
	  SEND_TO_ARRAY_Value(Array_0[IGNITION]);NOP();SEND_TO_ARRAY(",");NOP();						   // IGNITION
///************************************************************************************************************************************************************/	  
//	  
	  //if(MAIN_BATTERY_VOLTAGE<=40){MAIN_BAT_STATUS=OFF;TEMP_MAIN_BATTERY_VOLTAGE=0;SEND_TO_ARRAY("0,");}else{MAIN_BAT_STATUS=ON;SEND_TO_ARRAY("1,");}NOP();		// MAIN BATTERY STATUS
	  if(MAIN_BAT_STATUS==OFF){SEND_TO_ARRAY("0,");}else{SEND_TO_ARRAY("1,");}NOP();		// MAIN BATTERY STATUS
	  
	  BATTERY_MEASUREMENT=ON;
	  SEND_TO_ARRAY_Value(((MAIN_BATTERY_VOLTAGE/100)+0x30));
	  VOLT=MAIN_BATTERY_VOLTAGE%100;
	  SEND_TO_ARRAY_Value(((VOLT/10)+0x30));NOP();SEND_TO_ARRAY(".");
	  SEND_TO_ARRAY_Value(((VOLT%10)+0x30));SEND_TO_ARRAY(",");//MAIN BATTERY VOLTAGE
///************************************************************************************************************************************************************/	  
	  VOLT=BACKUP_BATTERY_VOLTAGE%1000;
	  SEND_TO_ARRAY_Value(((VOLT/100)+0x30));VOLT=VOLT%100;SEND_TO_ARRAY(".");
	  SEND_TO_ARRAY_Value(((VOLT/10)+0x30));        //R_UART2_SEND_User(((VOLT%10)+0x30));
	  SEND_COMMA_TO_ARRAY();				//BACKUP BATTERY VOLTAGE
	  BATTERY_MEASUREMENT=OFF;
///************************************************************************************************************************************************************/	  
	  SEND_TO_ARRAY_Value(Array_0[PANIC_ALERT]);NOP();							//PANIC ALERT 
///************************************************************************************************************************************************************/
	  
///************************************************************************************************************************************************************/	  						//PANIC ALERT & TAMPER ALERT 'C'
HEX_CHARACTER_CONVERSION=SET;
	if(MNC[0]==0x78){SEND_TO_ARRAY("00");}
	else
	{
		if(MNC_DATA_LENGTH>=2){MNC_DATA_LENGTH=1;}
	  for(FOR_1=0;FOR_1<=MNC_DATA_LENGTH;FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(MNC[FOR_1]);
	  }
	}
	  SEND_COMMA_TO_ARRAY();
///************************************************************************************************************************************************************/
	  PRINT_ZEROS_2(LAC_DATA_LENGTH_0);
	  for(FOR_1=0;FOR_1<=LAC_DATA_LENGTH_0;FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(LAC[FOR_1]);
	  }
	  SEND_COMMA_TO_ARRAY();
	  
	  PRINT_ZEROS_2(CELL_ID_DATA_LENGTH_0);
/************************************************************************************************************************************************************/	  	  
	  for(FOR_1=0;FOR_1<=CELL_ID_DATA_LENGTH_0;FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(CELL_ID[FOR_1]);
	  }
	  SEND_COMMA_TO_ARRAY();
	 
/************************************************************************************************************************************************************/	  
// CELL ID:-1
	  
	  PRINT_ZEROS_2(CELL_ID_DATA_LENGTH[1]);
	  
	  for(FOR_1=0;FOR_1<=CELL_ID_DATA_LENGTH[1];FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(CELL_ID_1[FOR_1]);
	  }
	  SEND_COMMA_TO_ARRAY();
// LAC:-1 	  
	  PRINT_ZEROS_2(LAC_DATA_LENGTH[1]);
	  for(FOR_1=0;FOR_1<=LAC_DATA_LENGTH[1];FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(LAC_1[FOR_1]);
	  }
	  SEND_COMMA_TO_ARRAY();
// DBM:-1 	  
	  for(FOR_1=0;FOR_1<=DBM_DATA_LENGTH[1];FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(DBM_1[FOR_1]);
	       if(DBM_DATA_LENGTH[1]==2 && FOR_1==0){SEND_TO_ARRAY("0");NOP();}
	  else if(DBM_DATA_LENGTH[1]==1 && FOR_1==0){SEND_TO_ARRAY("00");NOP();}
	  }
	  SEND_COMMA_TO_ARRAY();
/************************************************************************************************************************************************************/	  

/************************************************************************************************************************************************************/	  
// CELL ID:-2 	  
	  PRINT_ZEROS_2(CELL_ID_DATA_LENGTH[2]);
	  for(FOR_1=0;FOR_1<=CELL_ID_DATA_LENGTH[2];FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(CELL_ID_2[FOR_1]);
	  }
	  SEND_COMMA_TO_ARRAY();
// LAC:-2 	 
	  PRINT_ZEROS_2(LAC_DATA_LENGTH[2]);
	  for(FOR_1=0;FOR_1<=LAC_DATA_LENGTH[2];FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(LAC_2[FOR_1]);
	  }
	  SEND_COMMA_TO_ARRAY();
// DBM:-2 	  
	  for(FOR_1=0;FOR_1<=DBM_DATA_LENGTH[2];FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(DBM_2[FOR_1]);
	       if(DBM_DATA_LENGTH[2]==2 && FOR_1==0){SEND_TO_ARRAY("0");NOP();}
	  else if(DBM_DATA_LENGTH[2]==1 && FOR_1==0){SEND_TO_ARRAY("00");NOP();}
	  }
	  SEND_COMMA_TO_ARRAY();
/************************************************************************************************************************************************************/	  
// CELL ID:-3
          PRINT_ZEROS_2(CELL_ID_DATA_LENGTH[3]);
	  for(FOR_1=0;FOR_1<=CELL_ID_DATA_LENGTH[3];FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(CELL_ID_3[FOR_1]);
	  }
	  SEND_COMMA_TO_ARRAY();
// LAC:-3 	  
	  PRINT_ZEROS_2(LAC_DATA_LENGTH[3]);
	  for(FOR_1=0;FOR_1<=LAC_DATA_LENGTH[3];FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(LAC_3[FOR_1]);
	  }
	  SEND_COMMA_TO_ARRAY();
// DBM:-3 	  
	  for(FOR_1=0;FOR_1<=DBM_DATA_LENGTH[3];FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(DBM_3[FOR_1]);
	       if(DBM_DATA_LENGTH[3]==2 && FOR_1==0){SEND_TO_ARRAY("0");NOP();}
	  else if(DBM_DATA_LENGTH[3]==1 && FOR_1==0){SEND_TO_ARRAY("00");NOP();}
	  }
	  SEND_COMMA_TO_ARRAY();
/************************************************************************************************************************************************************/	  
//CELL ID:-4

	  PRINT_ZEROS_2(CELL_ID_DATA_LENGTH[4]);
	  for(FOR_1=0;FOR_1<=CELL_ID_DATA_LENGTH[4];FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(CELL_ID_4[FOR_1]);
	  }
	  SEND_COMMA_TO_ARRAY();
// LAC:-4 	  
	  PRINT_ZEROS_2(LAC_DATA_LENGTH[4]);
          for(FOR_1=0;FOR_1<=LAC_DATA_LENGTH[4];FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(LAC_4[FOR_1]);
	  }
	  SEND_COMMA_TO_ARRAY();
	  
// DBM:-4 	  
	  for(FOR_1=0;FOR_1<=DBM_DATA_LENGTH[4];FOR_1++)
	  {
	  NOP();
	  SEND_TO_ARRAY_Value(DBM_4[FOR_1]);
	       if(DBM_DATA_LENGTH[4]==2 && FOR_1==0){SEND_TO_ARRAY("0");NOP();}
	  else if(DBM_DATA_LENGTH[4]==1 && FOR_1==0){SEND_TO_ARRAY("00");NOP();}
	  }
	  HEX_CHARACTER_CONVERSION=CLR;
	  	 
	  
	  
          
///************************************************************************************************************************************************************/	  
	
	FRAME_NUMBER++;
	  if(FRAME_NUMBER>=1000000){FRAME_NUMBER=1;}
	  TEMP_FRAME_NUMBER=FRAME_NUMBER;
	  SEND_TO_ARRAY_Value(((TEMP_FRAME_NUMBER/100000)+0x30));
	  
	  TEMP_FRAME_NUMBER=TEMP_FRAME_NUMBER%100000;
	  SEND_TO_ARRAY_Value(((TEMP_FRAME_NUMBER/10000)+0x30));
	  
	  TEMP_FRAME_NUMBER=TEMP_FRAME_NUMBER%10000;
	  SEND_TO_ARRAY_Value(((TEMP_FRAME_NUMBER/1000)+0x30));
	  
	  TEMP_FRAME_NUMBER=TEMP_FRAME_NUMBER%1000;
	  SEND_TO_ARRAY_Value(((TEMP_FRAME_NUMBER/100)+0x30));
	  
	  TEMP_FRAME_NUMBER=TEMP_FRAME_NUMBER%100;
	  SEND_TO_ARRAY_Value(((TEMP_FRAME_NUMBER/10)+0x30));
	  SEND_TO_ARRAY_Value(((TEMP_FRAME_NUMBER%10)+0x30));

	  
RECORD_ARRAY_ADDRESS=1;
	  

	  



}

void SEND_WREN_COMMAND(void)
{
MS_TIMER(5);FLASH_CE=LOW;
R_CSI00_SEND(WREN);
//R_CSI00_Send_Receive(WREN,1u,0);
MS_TIMER(5);FLASH_CE=HIGH;
}

void WRITE_STATUS_REGISTER(void)
{
MS_TIMER(5);FLASH_CE=LOW;
R_CSI00_Send_Receive(WRSR,2u,0);
MS_TIMER(5);FLASH_CE=HIGH;
}
void READ_STATUS_REGISTER(void)
{
MS_TIMER(5);FLASH_CE=LOW;
R_CSI00_Send_Receive(RDSR,2u,0);
MS_TIMER(5);FLASH_CE=HIGH;
}
void CHIP_ERASE(void)
{
SEND_WREN_COMMAND();	
MS_TIMER(50);FLASH_CE=LOW;
R_CSI00_SEND(CE);
//R_CSI00_Send_Receive(CE,1u,0);
MS_TIMER(50);FLASH_CE=HIGH;
MS_TIMER(500);
WAIT_UNTILL_FLASH_BUSY();
}

/*void SECTOR_ERASE(void)
{
SEND_WREN_COMMAND();	
MS_TIMER(5);FLASH_CE=LOW;
R_CSI00_Send_Receive(SECT_ERASE,4u,0);
MS_TIMER(5);FLASH_CE=HIGH;
MS_TIMER(500);
}*/

/*void SIX_FOUR_KB_ERASE(void)
{
SEND_WREN_COMMAND();	
MS_TIMER(5);FLASH_CE=LOW;
R_CSI00_Send_Receive(SIX_FOUR_KB_ERASE_FR,4u,0);
MS_TIMER(5);FLASH_CE=HIGH;
MS_TIMER(500);
}*/

void WAIT_UNTILL_FLASH_BUSY(void)
{
CHECK_AGAIN:	
MS_TIMER(5);FLASH_CE=LOW;
R_CSI00_SEND(STATUS_REG);
//R_CSI00_Send_Receive(STATUS_REG,2u,FLASH_STATUS);
//R_CSI00_Send_Receive(FLASH_STATUS,2u,FLASH_STATUS);
MS_TIMER(5);FLASH_CE=HIGH;
if(FLASH_STATUS[1]!=0){MS_TIMER(10);goto CHECK_AGAIN;}
}
void SEND_COMMA_TO_ARRAY(void)
{
SEND_TO_ARRAY(",");NOP();  
}

void FLASH_WRITE(void)
{

/*GREEN_LED=ON*/;
FLASH_HOLD=FLASH_WP=HIGH;
//WRITE_STATUS_REGISTER();
//READ_STATUS_REGISTER();
REPEAT_WRITING:
SEND_WREN_COMMAND();	// WREN COMMAND SENDING

//if(FLASH_READ_ADDRESS==1){CHIP_ERASE();}

TEMP_FLASH_WRITE_ADDRESS=FLASH_WRITE_ADDRESS/65536;
FLASH_WRITE_ADDRESS_1=TEMP_FLASH_WRITE_ADDRESS;
TEMP_FLASH_WRITE_ADDRESS=FLASH_WRITE_ADDRESS%65536;
FLASH_WRITE_ADDRESS_2=TEMP_FLASH_WRITE_ADDRESS/256;
FLASH_WRITE_ADDRESS_3=TEMP_FLASH_WRITE_ADDRESS%256;



MS_TIMER(5);FLASH_CE=LOW;
R_CSI00_SEND(0x02);//R_CSI00_SEND(0x00);R_CSI00_SEND(0x00);R_CSI00_SEND(0x00);						// READ COMMAND
R_CSI00_SEND(FLASH_WRITE_ADDRESS_1);					// READ-ADDRESS-1
R_CSI00_SEND(FLASH_WRITE_ADDRESS_2);			// READ-ADDRESS-2
R_CSI00_SEND(FLASH_WRITE_ADDRESS_3);					// READ-ADDRESS-3
while(FLASH_WRITING==LOW)
{
R_CSI00_SEND(RECORD[FLASH_BYTE]);
FLASH_WRITE_ADDRESS++;
FLASH_BYTE++;
FLASH_WRITE_ADDRESS_3++;
if(FLASH_BYTE>174 || FLASH_WRITE_ADDRESS_3%256==0){FLASH_WRITING=HIGH;}
}
MS_TIMER(5);FLASH_CE=HIGH;
FLASH_WRITING=LOW;
if(FLASH_WRITE_ADDRESS_3%256==0 && FLASH_BYTE<=174)
{
goto REPEAT_WRITING;
}
FLASH_BYTE=1;
for(FOR_1=0;FOR_1<=179;FOR_1++)
{
	RECORD[FOR_1]=0;
}
FLASH_MEMORY++;
}


void READ_FLASH_MEM(void)
{
for(FOR_1=0;FOR_1<=200;FOR_1++)
{
RECORD[FOR_1]=0;
NOP();
}

TEMP_FLASH_READ_ADDRESS=FLASH_READ_ADDRESS/65536;
FLASH_READ_ADDRESS_1=TEMP_FLASH_READ_ADDRESS;
TEMP_FLASH_READ_ADDRESS=FLASH_READ_ADDRESS%65536;
FLASH_READ_ADDRESS_2=TEMP_FLASH_READ_ADDRESS/256;
FLASH_READ_ADDRESS_3=TEMP_FLASH_READ_ADDRESS%256;


MS_TIMER(100);FLASH_CE=LOW;
R_CSI00_SEND(0x03);//R_CSI00_SEND(0x00);R_CSI00_SEND(0x00);R_CSI00_SEND(0x00);						// READ COMMAND
R_CSI00_SEND(FLASH_READ_ADDRESS_1);					// READ-ADDRESS-1
R_CSI00_SEND(FLASH_READ_ADDRESS_2);			// READ-ADDRESS-2
R_CSI00_SEND(FLASH_READ_ADDRESS_3);					// READ-ADDRESS-3
R_CSI00_Send_Receive(RECORD,175,RECORD);
MS_TIMER(100);FLASH_CE=HIGH;

/*****************************************************************************************/
R_UART2_SEND("http://103.129.98.194/apis/update-vehicle-tracking.php?datas=$,H,VID,");NOP();NOP();
/*****************************************************************************************/
	  R_UART2_SEND_User(((CURRENT_FRM_VERSION/100)+0x30));R_UART2_SEND(".");NOP();
	  TEMP_FRM_VERSION=CURRENT_FRM_VERSION%100;
	  R_UART2_SEND_User(((TEMP_FRM_VERSION/10)+0x30));R_UART2_SEND(".");NOP();
	  R_UART2_SEND_User(((TEMP_FRM_VERSION%10)+0x30));
	  R_UART2_SEND(",");NOP();
/*****************************************************************************************/	 
for(FOR_1=1;FOR_1<=6;FOR_1++)
{
R_UART2_SEND_User(RECORD[FOR_1]);
}
R_UART2_SEND("H,");NOP();
for(FOR_1=1;FOR_1<=15;FOR_1++){R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);NOP();NOP();}R_UART2_SEND(",");NOP(); //IMEI NUMBER
for(FOR_1=0;FOR_1<=9;FOR_1++){if(VEICHLE_NUMBER[FOR_1]!=' '){R_UART2_SEND_User(VEICHLE_NUMBER[FOR_1]);MS_TIMER(1);}}R_UART2_SEND(",");NOP(); //VEICHLE NUMBER

for(FOR_1=7;FOR_1<=82;FOR_1++)
{
R_UART2_SEND_User(RECORD[FOR_1]);	// GPS FIX, DATA, TIME, LATITUDE,LAT-DIRECTION, LONGITUDE, LONG-DIRECTION, SPEED, HEADING, NO OF SAT, ALTITITUDE, PDOP, HDOP,
}	  
R_UART2_SEND("00000000,");NOP();	// NETWORK NAME
for(FOR_1=83;FOR_1<=96;FOR_1++)
{
R_UART2_SEND_User(RECORD[FOR_1]);	// IGNITION, MAIN POWER STATUS, MAIN INPUT VOLTAGE, BACKUP BATTERY VOLTAGE, PANIC ALERT
}
R_UART2_SEND(",C,00,404,");NOP();	// TAMPER ALERT OPTIONAL
for(FOR_1=97;FOR_1<=168;FOR_1++)
{
R_UART2_SEND_User(RECORD[FOR_1]);NOP();	// GPS FIX, DATA, TIME, LATITUDE,LAT-DIRECTION, LONGITUDE, LONG-DIRECTION, SPEED, HEADING, NO OF SAT, ALTITITUDE, PDOP, HDOP,
}
R_UART2_SEND(",0000,00,");NOP();	// DIGITAL & ANALOG STATUS
for(FOR_1=169;FOR_1<=174;FOR_1++)
{
R_UART2_SEND_User(RECORD[FOR_1]);NOP();	// GPS FIX, DATA, TIME, LATITUDE,LAT-DIRECTION, LONGITUDE, LONG-DIRECTION, SPEED, HEADING, NO OF SAT, ALTITITUDE, PDOP, HDOP,
}
R_UART2_SEND(",00,*");NOP();
FLASH_READ_ADDRESS=FLASH_READ_ADDRESS+174;
}