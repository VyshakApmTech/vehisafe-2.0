#include "r_cg_userdefine.h"

void UPDATE_ONLINE_DATA_FRAME(void);
void HEL_STRING(void);
#define DATA_BUFFER_SIZE 256
char DATA_BUFFER[DATA_BUFFER_SIZE];
unsigned int DATA_BUFFER_INDEX;
void BUFFER_APPEND_CHAR(char c);
void BUFFER_APPEND_STR(const char *s);
char apn_is_default = 1;
char default_apn[25] ={'n','a','v','s','p','i','r','e','i','o','t','.','c','o','m','\0'};
char APN_INDEX = 0;  // Dedicated index for APN reception (prevents VV collision)
unsigned char CGATT_POLL_COUNT = 0;   /* already have this - no other new variables needed */
char V_NO_LEN,VN_ACK_RX,PANIC_NUMBER_RX,TEMP_SET[255],TEMP_TCP[255],SET_TCP_FRAME_RX,SETTING_CMD_FRAME_RX,RX_ACK_Frame,ACK,ERROR_OCCURED,RX_SMS_CMD,t,SMS_FAIL_COUNT,SMS_FAIL,NETWORK_NAME_RX,BATTERY_MEASUREMENT,IGNITION_CTRL_RX,INITIAL_MESSAGE,P_LAT_DM_RX,FILE_CLOSE_ATTEMPT,GSM_REG,GPRS_REG/*,SS_DATA_RX*/,GET_SS,dBm,GPRS_CONNECTED,GSM_STRENGTH='5',INTERNET_CONNECTED,DISCONNECT,LOW_BATTERY_ALERT,HTTP_CONNECT_COUNT,NW_NAME_RX,TCP_CONNECTION_OPEN=OFF;
char i,SMS,NETWORK_FAILURE,HTTP_PRINT,SPEED_DATA[10],SS_DATA_RX,CPIN,P_TIME[10],P_SEND_TIME[10],P_SEND_LOG_DM[10],P_SEND_LAT_DM[10],FTP_ADDRESS[8],FTP_CONNECT_COUNT,FILE_ADDR,FIRMWARE_VERSION_RX,I[100];
char IMEI_EEPROM[16],PANIC_CTRL_RX,PANIC_CONTROL_STATE,PANIC_CONTROL_RX,FIRM_UPDATE_CTRL_RX,FIRM_UPDATE_CONTROL_STATE,FIRM_UPDATE_CONTROL_RX,FILE[150];
char CELL_ID[5],LAC[5],NCELL_CID[4][5],NCELL_LAC[4][5],NCELL_DBM[4];
int SERVING_CELL_DBM;
unsigned int K,TEMP_EMGT_TIME,FOR_1,FOR_2,FOR_3,Address_1,NW_REGN_COUNT,FLASH_MEMORY,GPRS_REG_COUNT,MAIN_BATTERY_VOLTAGE,ADC_BUFFER,BACKUP_BATTERY_VOLTAGE,GPRS_REG_ROAMING,GSM_REG_ROAMING,T_SPEED,FILTER,DATA_HEADER,TEMP_VERSION,CHECKSUM_BYTE,MN,VERSION_TEMP,FRM_VERSION,CURRENT_FRM_VERSION,HEX,TEMP_3,VOLT,TEMP_MAIN_BATTERY_VOLTAGE,J,RESTART;
unsigned long int FRAME_NUMBER,TEMP_FRAME_NUMBER,TEMP_FRM_VERSION;
extern unsigned int t_count,WRITE_ADDRESS,DATA,WATCH_DOG_KILL,WRITE_ADDRESS,TEMPS,WRITE_ADDRESS_MSB,WRITE_ADDRESS_LSB,BYTE,MINUTE;
extern char O;
extern char LOG_DM[10],LAT_DM[10],TIME[10],GPS_BUSY,SPEED[4],SPEED_DATA_RX[10],WATCH_DOG,GPS_DIRECTION_DATA_VALID,IGNITION,PANIC_ALERT,PANIC_ALERT_PACKET,IGNITION_ON_PACKET,IGNITION_OFF_PACKET,POWER_SOURCE_PACKET,LOW_BATTERY_ALERT_PACKET,HOURS_MSB,HOURS_LSB,MIN_MSB,MIN_LSB,LON_DIRECTION,LAT_DIRECTION,LAT_DM_RX[10],LOG_DM_RX[10],COG[6],GPGA_DATA[10],ALTITUDE[8],HDOP[5],NO_OF_SAT,NAVIGATION_ACK,NAVIGATION_RX,GPS_RESTART,FIRM_DATA[150],MAIN_BAT_STATUS;
_Bool GPS_RST_FLAG,DEVICE_RESTART_RX_1,WELCOME_STRING_FRAME_BOOT,SET_OTA_UPDATE,SETTING_CMD,SET_APN,SET_TCP,BSNL_CONNECT_FLAG,BSNL_CONNECT,CONNECT_FAIL,ALREADY_CONNECT,ALREADY_CONNECT_FLAG,QST_CMD_FLAG,HARSH_BRAKE_PACKET,HARSH_TURN_PACKET,HARSH_ACC_PACKET,BATTERY_CHARGED_PACKET,REFRESH,PRIMARY_IP,SECONDARY_IP,PRI_IP_PN_SMS,SEC_IP_PN_SMS,HEALTH_CMD2,DATA_SEND,k,IGNITION_ON_PACKET_SENT,IGNITION_OFF_PACKET_SENT;
//extern unsigned int STP_DATA_RX,GET_STRPCI,STKPCI,GET_STP;
const char OK_ACK[2]={'O','K'},
ERROR_ACK[5]={'E','R','R','O','R'},
VODAFONE_ACK[15]={'+','C','O','P','S',':',' ','0',',','0',',','"','a','i','r'},
VODAFONE_ACK_V[15]={'+','C','O','P','S',':',' ','0',',','0',',','"','V','o','d'},
//GET_IN_SMS[4]={'C','M','T',','},
CONNECT_ACK[7]={'C','O','N','N','E','C','T'},
CONNECT_FAIL_ACK[12]={'C','O','N','N','E','C','T',' ','F','A','I','L'},
ALREADY_CONNECT_ACK[15]={'A','L','R','E','A','D','Y',' ','C','O','N','N','E','C','T'},
SIGNAL_STRENGTH_ACK[5]={'C','S','Q',':',' '},
NW_DIS_CONNECT[9]={'P','D','P',' ','D','E','A','C','T'},
PANIC_MOBILE_NUMBER_ACK[18]={'S','E','T',' ','E','N','O',' ','I','M','E','I',' ','2','2','0','2','='},
HTTP_RESPONSE_FAIL[4]={'h','t','t','p',},
//V_RESTART[3]={'V','R',':'},
VN_ACK[3]={'V','N',':'},
FIRM_UPDATE_CTRL[3]={'S','U',':'},
//SETTINGS_UPDATE_CTRL[3]={'U','S',':'},
//NETMODE_UPDATE_CTRL[3]={'N','M',':'},
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
//SET_TCP_FRAME[8]={'S','E','T',' ','T','C','P',' '},
//APN_S_FRAME[6]={'A','C','C','P','N',':'},
GET_SMS_FRAME[12]={'G','E','T',' ','S','E','T','T','I','N','G','S'},
//GET_VERSION_CMD[12]={'G','E','T',' ','V','E','R','S','I','O','N',' '},
	
GET_ACT_MESSAGE[5]={'A','C','T','V',','},
GET_HEALTH_MESSAGE_FRAME[5]={'H','C','H','K',','},
//PNET_CMD_FRAME[9]={'S','E','T',' ','P','N','E','T',' '},
//SNET_CMD_FRAME[9]={'S','E','T',' ','S','N','E','T',' '},
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
VEICHLE_NUMBER[15]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'},
IMEI[16]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'},//={'8','6','8','3','2','4','0','2','6','3','7','0','8','7','6','8'},
Array_0[10]={'0','1','2','3','4','5','6','7','8','9'},
NETWORK_NAME[8]={'0','0','0','0','0','0','0','0'},
//P_LAT_DM[10]={'0','0','0','0','0','0','0','0',},
//P_LOG_DM[10]={'0','0','0','0','0','0','0','0',},
SMS_MOBILE_NO[52]={'9','9','9','9','9','9','9','9','9','9','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',},
REPLY_NUMBER[10]={'0','0','0','0','0','0','0','0','0','0'};

char TEMP_PIP[30]  = "stavltsgw.tn.gov.in";       // Server 1
char TEMP_PPN[6]   = "8080";                      // Server 1 Port
char TEMP_PIP2[30] = "NA";                        // Server 2
char TEMP_PPN2[6]  = "NA";                        // Server 2 Port
char TEMP_SIP[30]  = "tracking.vlvprotect.com";   // Server 3
char TEMP_SPN[6]   = "8080";                      // Server 3 Port
char TEMP_SIP2[30] = "13.234.160.106";            // Server 4
char TEMP_SPN2[6]  = "8224";                      // Server 4 Port


char HEALTH_CMD_FRAME_RX, SET_SETTINGS_FRAME_RX, HEALTH_ON_DURATON_RX, PANIC_ON_DURATON_RX, PANIC_ON_DURATON_S_RX, HEALTH_ON_DURATON_S_RX, APN_S_RX, TEMP_APN2[20], GET_SMS_RX,GET_PIP_S_RX, GET_SIP_S_RX, SET_PIP_PN_RX, SET_SIP_PN_RX, SET_SLEEP_ON_RX, SET_SLEEP_OF_RX, SET_OVERSPEED_RX, GET_OVER_SPEED_RX, GET_SLEEP_TIME_RX, GET_SLEEP_OFF_TIME_RX;

_Bool DECIMAL_POINT_CAME_STOP_TX, POWER_SOURCE_RECONNECT_PACKET, GET_MCC_MNC_LAC_CELL_ID_RX, ADD_ZERO_TO_SPEED, SMS_PIN_WRONG, NEW_SMS_RX_FRAME_RX, PHONE_NUMBER_OF_SENDER_RX, DEVICE_RESET_CMD_FRAME_RX, DEVICE_RESET_CMD, SERVER_UPDATE_TIME_CMD_FRAME_RX, SET_EMERGENCY_NUMBER_FRAME_CMD, SET_REGN_NUMBER_FRAME_CMD, UPDATE_EMERGENCY_NUMBER, UPDATE_IP, SET_IP_FRAME_CMD, URL_PRINT, MESSAGE_READ, SET_SLEEP_OFF_CMD, SET_SLEEP_ON_CMD, OVER_SPEED_CMD, GET_EMGT_TIME_CMD, ACTIVATION_CMD, HEALTH_AND_ACTIVATION_CMD;

_Bool PANIC_CONTROL_STATE_1, GSM_NW_REG_CHECK, GPRS_REG_CHECK, GET_SIGNAL_STRENGTH_CHECK, CPIN_READY_CHECK, DECIMAL_POINT, UPDATE_RP_NO, VLT_STARTUP, NORMAL_PACKET, DEVICE_CLEAR_CMD_FRAME_RX, DEVICE_CLEAR_CMD, HARSH_BRAKE_CMD_RX, HARSH_TURN_CMD_RX, HARSH_ACCEL_CMD_RX, HEALTH_ON_DURATON_CMD, PANIC_ON_DURATON_CMD, PANIC_TIME_START, PANIC_SERVER_COUNT, HEALTH_PACKET_TO_SERVER, GET_SMS_CMD, GET_PIP_CMD, GET_SIP_CMD, GET_PPT_S_CMD, GET_SPT_S_CMD, QIMUX_SET = OFF;

extern _Bool VLT_STARTUP_INITIAL, BOOT_FLAG, FIRMWARE_UPDATE, IGNITION_CONTROL_STATE, POWER_SOURCE, SYSTEM_READY, WELCOME_STRING_FRAME, SET_SLEEP_ON_CMD, SET_SLEEP_OFF_CMD;

_Bool GPS_STANDBY, WATCH_DOG_FORCE_KILL, HTTP_DOWNLOAD_ACK, FTP_ACK, FTP_DOWNLOAD_ACK, FIRMWARE_DOWNLOADED, FILE_ACK, FILE_DOWNLOAD, FLAG, STOP_FILE_READING, IMEI_RX, IMEI_ACK_RX, DEVICE_RESTART_RX, HARSH_BRAKE_CMD, HARSH_TURN_CMD, HARSH_ACCEL_CMD;

int AD, resend;

char p1, p2, p3, p4, MCC_MNC_LAC_CELL_ID_LENGTH, FOR_7, ALTITUDE_VALUE_COUNT, NEW_SMS_INBOX_ADDRESS[20], NEW_SMS, PHONE_NUMBER_OF_SENDER[12], TEMP_REGN_NUMBER[15], TEMP_APN[25] = {'n','a','v','s','p','i','r','e','i','o','t','.','c','o','m','\0'}, SET_APN_FRAME_RX, IGNITION_ON_TIME_RX, IGNITION_OFF_TIME_RX;

unsigned int URL_COUNT, VEICHLE_REG_COUNT, IGNITION_ON_UPDATE_TIME, IGNITION_OFF_UPDATE_TIME, UPDATE_TIME_ON_TIME, UPDATE_TIME_OFF_TIME, HEALTH_ON_DURATON_LEVEL, P_DL, PANIC_ALERT_TIME, PANIC_TIME, HEALTH_ALERT_TIME, APN_TEMP, HARSH_BRAKE_LEVEL, HARSH_TURN_LEVEL, HARSH_ACCEL_LEVEL, HT_LEVEL, HB_LEVEL, P_D_L, SLEEP_ON_LEVEL, SLEEP_OF_LEVEL, SLEEP_ON_LEVEL, SLEEP_OFF_LEVEL, OVER_SPEED, TEMP_OVS_LEVEL, SLEEP_OFF_TIME, TEMP_SLEEP_OFF_TIME, EMGT_TIME;

char ENGINEER_MODE_FRAME_1_ACK, P, MCC_MNC_LAC_CELL_ID[20], GSM_COMMA, GET_IMEI_SMS_CMD_RX, UPDATE_INTERVAL_CMD, HARSH_ACCEL_CMD_SMS_RX, HARSH_TURN_CMD_SMS_RX, HARSH_BRAKE_CMD_SMS_RX, HARSH_ACCEL_CMD_SMS_LEVEL, HARSH_TURN_CMD_SMS_LEVEL, HARSH_BRAKE_CMD_SMS_LEVEL;

extern unsigned int PDOP_DATA_RX[8];

char TEMP_EMERGENCY_NUMBER[5];

char DBM_1[5], LAC_1[5], CELL_ID_1[5], DBM_2[5], LAC_2[5], CELL_ID_2[5], DBM_3[5], LAC_3[5], CELL_ID_3[5], DBM_4[5], LAC_4[5], CELL_ID_4[5], N, GSM_COMMA_2, SPEED_DATA_LENGTH_COUNT, APN_LENGTH, COG_VALUE_COUNT, PDOP_COUNT, HDOP_COUNT;

_Bool GET_VLT_IMEI_PH_CMD, VERSION_CMD_SET, ENGINEER_MODE_FRAME_2_ACK, GET_NMR_RX, HEX_CHARACTER_CONVERSION, VERSION_CMD_SET, SMS_CMD_REPLY, VERSION_CMD_RX, SEND_IMEI, UPDATE_INTERVAL_CMD_2, SET_APN_FRAME_CMD, UPDATE_APN, UPDATE_REGISTRATION_NUMBER, UPDATE_INTERVAL_TIME_FOR_IGNITION_ON_CMD, UPDATE_INTERVAL_TIME_FOR_IGNITION_OFF_CMD, SMS_CMD_DATA_UPLOAD_UONT, SMS_CMD_DATA_UPLOAD, UPDATE_REGISTRATION_NUMBER_1, OTA_PACKET, PANIC_TIME_STOP, PRIMARY_PN, SECONDARY_PN, SLEEP_ON_TIME_CMD, SLEEP_OFF_TIME_CMD;

char LOW_BAT_LEVEL_RX, LOW_BAT_LEVEL_CMD;

char GET_SPN_S_RX, GET_SPN_S_RX;

char DBM_DATA_LENGTH[5], LAC_DATA_LENGTH[5], CELL_ID_DATA_LENGTH[5], MCC_1[5], MNC[5], LAC[5], CELL_ID[5], MCC_DATA_LENGTH, MNC_DATA_LENGTH, LAC_DATA_LENGTH_0, CELL_ID_DATA_LENGTH_0, SMS_CMD_FRAME_RX, GET_IMEI_SEND_CMD_RX, TEMP_IP[15], SET_IP_FRAME_RX, SET_RP_NO_FRAME_RX, SET_RP_NO_FRAME_CMD, VV, TEMP_RP_NO[12], REPLY_NUMBER_RX;

unsigned long int FLASH_WRITE_ADDRESS = 1, FLASH_READ_ADDRESS, TEMP_FLASH_WRITE_ADDRESS, TEMP_FLASH_READ_ADDRESS, HEALTH_FRAME_NUMBER;

unsigned int updatedata, RECORD_ARRAY_ADDRESS = 1, FLASH_BYTE = 1, FLASH_WRITE_ADDRESS_1, FLASH_WRITE_ADDRESS_2, FLASH_WRITE_ADDRESS_3, FLASH_READ_ADDRESS_1, FLASH_READ_ADDRESS_2, FLASH_READ_ADDRESS_3, RLL, LOW_BAT_LEVEL, LB_LEVEL, SLEEP_ON_TIME, TEMP_SLEEP_ON_TIME;

char RECORD[180], HA_LEVEL, GET_PPN_S_RX, GET_DEVICE_CLEAR_S_RX;

_Bool FLASH_WRITING, GET_PPN_CMD, GET_SPN_CMD;
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
    R_UART2_SEND("AT+QIDEACT\r\n");
    ACK=0;ERROR_OCCURED=0;
    ACK_RX(4000,2,100,10);
    TCP_CONNECTION_OPEN = OFF;
    GPRS_REG = OFF;  // Reset GPRS flag when disconnecting
    QIMUX_SET = OFF;  // Reset QIMUX flag so it can be set again on next session
    if(RESTART==ON)
    {
        RESTART=OFF;
        goto restart5;
    }
}


// void UPDATE_SETTING(void)
// {
	
// 		if(SETTING_CMD==1)
// 		{
// 			SETTING_CMD=CLR;
			
			
// 		}
// 		else if(SET_APN==1)
		
// 		{
// 			SET_APN=CLR;
			
// 		}
		
// 		else if(SET_TCP==1)
// 		{
// 			SET_TCP=CLR;
			
// 		}
// }

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
	R_UART2_SEND("AT+COPS?\r\n");
    ACK_RX(40,2,50,0);
	//SwitchNetwork();
	if(RESTART==ON)
    {
        RESTART=OFF;
        goto restart100;
    }
	
	NETWORK_NAME_RX=OFF;
}
void LATITUDE_CONVERSION(void)
{
     unsigned long int TEMP_LC1,TEMP_LC2,LATITUDE_MINUTES;
     unsigned int FOR_2;

     MS_TIMER(1);

     LATITUDE_MINUTES=0X0F & LAT_DM_RX[2];
     for(FOR_2=3;FOR_2<=7;FOR_2++)
     {
         LATITUDE_MINUTES=LATITUDE_MINUTES*10;
         LATITUDE_MINUTES=(LATITUDE_MINUTES + (0X0F & LAT_DM_RX[FOR_2]));
     }

     TEMP_LC1=((((LAT_DM_RX[0]&0X0F)*10))+(LAT_DM_RX[1]&0X0F));

     /* FIX: convert minutes/60 to degrees BEFORE the fraction gets truncated away */
     LATITUDE_MINUTES = (TEMP_LC1*1000000) + ((LATITUDE_MINUTES*100)/60);

     TEMP_LC1=LATITUDE_MINUTES;

     TEMP_LC2=TEMP_LC1/10000000;
     LAT_DM[0]=TEMP_LC2+'0';           /* FIX: '+'0'' instead of garbage Array[] lookup */

     TEMP_LC2=10000000;
     for(FOR_2=1;FOR_2<=7;FOR_2++)
     {
         TEMP_LC1=TEMP_LC1%TEMP_LC2;
         TEMP_LC2=TEMP_LC2/10;
         LAT_DM[FOR_2]=(TEMP_LC1/TEMP_LC2)+'0';   /* FIX: same */
     }
}

void LONGITUDE_CONVERSION(void)
{
     unsigned long int TEMP_LO1,TEMP_LO2,LONGITUDE_MINUTES;
     unsigned int FOR_2;

     MS_TIMER(1);

     LONGITUDE_MINUTES=0X0F & LOG_DM_RX[3];  /* Position 3 = tens of minutes for DDD format */
     for(FOR_2=4;FOR_2<=8;FOR_2++)           /* Loop 4-8 for ones of minutes + fractional digits */
     {
         LONGITUDE_MINUTES=LONGITUDE_MINUTES*10;
         LONGITUDE_MINUTES=(LONGITUDE_MINUTES + (0X0F & LOG_DM_RX[FOR_2]));
     }

     /* FIX: Extract 3-digit degrees from positions 0,1,2 (DDD format), not 1,2 (2-digit) */
     TEMP_LO1=((((LOG_DM_RX[0]&0X0F)*100)+((LOG_DM_RX[1]&0X0F)*10))+(LOG_DM_RX[2]&0X0F));

     LONGITUDE_MINUTES = (TEMP_LO1*1000000) + ((LONGITUDE_MINUTES*100)/60);

     TEMP_LO1=LONGITUDE_MINUTES;

     TEMP_LO2=TEMP_LO1/10000000;
     LOG_DM[0]=TEMP_LO2+'0';

     TEMP_LO2=10000000;
     for(FOR_2=1;FOR_2<=7;FOR_2++)
     {
         TEMP_LO1=TEMP_LO1%TEMP_LO2;
         TEMP_LO2=TEMP_LO2/10;
         LOG_DM[FOR_2]=(TEMP_LO1/TEMP_LO2)+'0';
     }
}

void DEVICE_REPLY_IN_SMS(unsigned char REPLY)
{
	unsigned int T;
	unsigned int FOR_0,O;
    // R_UART2_SEND("inside device reply in sms with reply value = ");
    // R_UART2_SEND_User(REPLY);
	
    if(REPLY==17)
	{
		// Send settings SMS to extracted sender number
		R_UART2_SEND("AT+CMGF=1\r\n");
		MS_TIMER(100);
		R_UART2_SEND("AT+CMGS=\"" );
		for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
		{
			if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
			{
				R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
			}
			MS_TIMER(1);
		}
		R_UART2_SEND("\"\r\n");
		MS_TIMER(100);
		R_UART2_SEND("SETTINGS:-");
		goto REPL_1;
	}

	else if(REPLY==200)
	{
		// Send VERSION SMS to extracted sender number
		R_UART2_SEND("AT+CMGF=1\r\n");
		MS_TIMER(100);
		R_UART2_SEND("AT+CMGS=\"" );
		for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
		{
			if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
			{
				R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
			}
			MS_TIMER(1);
		}
		R_UART2_SEND("\"\r\n");
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
		// Send IMEI SMS to extracted sender number
		R_UART2_SEND("AT+CMGF=1\r\n");
		MS_TIMER(100);
		R_UART2_SEND("AT+CMGS=\"" );
		for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
		{
			if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
			{
				R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
			}
			MS_TIMER(1);
		}
		R_UART2_SEND("\"\r\n");
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
/****************************************************************************************************
 DEVICE ACCEL - Send current HACL value via SMS
*****************************************************************************************************/
else if(REPLY==11)
{
    unsigned int temp_value;  // Temporary variable
    REPL_8:
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);
    R_UART2_SEND("AT+CMGS=\"" );
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
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

	//REPL_9:

	O=CLR;

	R_UART2_SEND("AT+CMGF=1\r\n");
	MS_TIMER(100);

	R_UART2_SEND("AT+CMGS=\"" );
	for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
	{
		if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
		{
			R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
		}
		MS_TIMER(1);
	}
	R_UART2_SEND("\"\r\n");
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
    R_UART2_SEND("AT+CMGS=\"" );
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
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
    R_UART2_SEND("AT+CMGS=\"" );
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
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
    MS_TIMER(100);
    
    // ✅ ADD: SMS destination setup
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(100);
    
    // Send APN data
    R_UART2_SEND("APN:");
    APN_TEMP=200+APN_LENGTH;
    J=CLR;
    for(FOR_1=200; FOR_1 < APN_TEMP; FOR_1++)  // Changed <= to <
    {
        TEMP_APN[J] = i2c_readn(0xA0, 0XFE, FOR_1);
        MS_TIMER(2);
        R_UART2_SEND_User(TEMP_APN[J]);
        NOP();
        J++;
    }
    
    // ✅ ADD: CTRL_Z to send SMS
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
    
    if(REPLY==17)
    {
        R_UART2_SEND(",");
        goto REPL_7;
    }
    goto restart11;
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
	R_UART2_SEND("Device Restarting: ");
	for(FOR_1=1;FOR_1<=15;FOR_1++)
	{
		R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);
		NOP();
		NOP();
	} //IMEI NUMBER
}

/*****************************************************************************************************/ 
// REPLY==28  SET PROFILE
/*****************************************************************************************************/
else if(REPLY == 28)
{
    // Check if profile is valid (1, 2, or 3)
    if(TEMP_PROF == '1' || TEMP_PROF == '2' || TEMP_PROF == '3')
    {
        // Step 1: Read current profile from EEPROM (address 60)
        unsigned char current_prof = i2c_readn(0xA0, 0XFE, 60);
        MS_TIMER(2);

        // Step 2: If profile is different, write new profile to EEPROM and apply
        if(current_prof != (TEMP_PROF & 0x0F))
        {
            i2c_writen(0xA0, 0XFE, 60, (TEMP_PROF & 0x0F));
            MS_TIMER(5);
        }

        // Step 3: Setup SMS mode
        R_UART2_SEND("AT+CMGF=1\r\n");
        MS_TIMER(100);

        // Step 4: Send to the ACTUAL sender number stored during SMS receive
        R_UART2_SEND("AT+CMGS=\"");
        for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
        {
            if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
            {
                R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
            }
            MS_TIMER(1);
        }
        R_UART2_SEND("\"\r\n");
        MS_TIMER(200);   // wait for '>' prompt

        // Step 5: Content - send profile change status
        if(current_prof == (TEMP_PROF & 0x0F))
        {
            R_UART2_SEND("Profile ");
            R_UART2_SEND_User(TEMP_PROF);
            R_UART2_SEND(" Already Set");
        }
        else
        {
            R_UART2_SEND("Profile Changed to ");
            R_UART2_SEND_User(TEMP_PROF);
        }

        // Step 6: Send SMS
        MS_TIMER(10);
        R_UART2_SEND_User(CTRL_Z);
        ACK_RX(2500, 2, 500, 100);

        // Refresh network name after profile switch
        //MS_TIMER(500);  // Wait for network to update
        NETWORK_NAME_RX = ON;
        R_UART2_SEND("AT+COPS?\r\n");
        ACK_RX(40, 2, 50, 0);
        NETWORK_NAME_RX = OFF;

        goto restart11;
    }
    else
    {
        // Invalid profile - send error via SMS
        R_UART2_SEND("AT+CMGF=1\r\n");
        MS_TIMER(100);

        R_UART2_SEND("AT+CMGS=\"");
        for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
        {
            if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
            {
                R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
            }
            MS_TIMER(1);
        }
        R_UART2_SEND("\"\r\n");
        MS_TIMER(200);

        R_UART2_SEND("Invalid Profile (1,2,3)");

        MS_TIMER(10);
        R_UART2_SEND_User(CTRL_Z);
        ACK_RX(2500, 2, 500, 100);
        goto restart11;
    }
}

/*****************************************************************************************************/ 
// REPLY==29  SET INTERVAL
/*****************************************************************************************************/
else if(REPLY == 29)
{
    // Step 1: Setup SMS mode
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);

    // Step 2: Send to the ACTUAL sender number stored during SMS receive
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(200);   // wait for '>' prompt

    // Step 3: Content
    R_UART2_SEND("INTERVAL CHANGE trc:");
    O = TEMP_TRC_INTVL % 100;
    R_UART2_SEND_User(((TEMP_TRC_INTVL / 100) + 0x30));
    R_UART2_SEND_User(((O / 10) + 0x30));
    R_UART2_SEND_User(((O % 10) + 0x30));

    R_UART2_SEND(",ign:");
    O = TEMP_IGN_INTVL % 100;
    R_UART2_SEND_User(((TEMP_IGN_INTVL / 100) + 0x30));
    R_UART2_SEND_User(((O / 10) + 0x30));
    R_UART2_SEND_User(((O % 10) + 0x30));

    R_UART2_SEND(",sos:");
    O = TEMP_SOS_INTVL % 100;
    R_UART2_SEND_User(((TEMP_SOS_INTVL / 100) + 0x30));
    R_UART2_SEND_User(((O / 10) + 0x30));
    R_UART2_SEND_User(((O % 10) + 0x30));

    R_UART2_SEND(",std:");
    O = TEMP_STD_INTVL % 100;
    R_UART2_SEND_User(((TEMP_STD_INTVL / 100) + 0x30));
    R_UART2_SEND_User(((O / 10) + 0x30));
    R_UART2_SEND_User(((O % 10) + 0x30));

    R_UART2_SEND(",health:");
    O = TEMP_HLT_INTVL % 100;
    R_UART2_SEND_User(((TEMP_HLT_INTVL / 100) + 0x30));
    R_UART2_SEND_User(((O / 10) + 0x30));
    R_UART2_SEND_User(((O % 10) + 0x30));

    // Step 4: Send
    MS_TIMER(10);
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
    goto restart11;
}

/*****************************************************************************************************/
//REPLY==6 REGISTRATION NUMBER
else if(REPLY == 6)
{
    
    REPL_4:

    // Step 1: Setup SMS mode
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);

    // Step 2: Send to ACTUAL sender number
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(200);

    // Step 3: Content
    R_UART2_SEND("Vehicle Number Updated :- ");
    FOR_1 = CLR;
    for(FOR_0 = 26; FOR_0 <= 35; FOR_0++)
    {
        T = i2c_readn(0xA0, 0XFE, FOR_0);
        MS_TIMER(2);
        R_UART2_SEND_User(T);
        NOP();
        VEICHLE_NUMBER[FOR_1] = T;
        FOR_1++;
    }
	
    if(REPLY == 17)
    {
    	R_UART2_SEND(","); 
    	goto REPL_5;
    }
    
    // Step 4: Send
    MS_TIMER(10);
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
    goto restart11;
}


/*****************************************************************************************************/ 
// REPLY==32  SET DEFAULT
/*****************************************************************************************************/
else if(REPLY == 32)
{
    // Step 1
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);

    // Step 2
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(200);

    // Step 3: Content
    R_UART2_SEND("Device Reverted to Default, Restarting...");

    // Step 4: Send
    MS_TIMER(10);
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
	
    /*
    // Step 5: Write defaults to EEPROM then restart
    // Default IP1
    i2c_writen(0xA0, 0XFE, 111, 0); MS_TIMER(5);
    i2c_writen(0xA0, 0XFE, 112, 0); MS_TIMER(5);
    // Default IP2
    i2c_writen(0xA0, 0XFE, 113, 0); MS_TIMER(5);
    i2c_writen(0xA0, 0XFE, 114, 0); MS_TIMER(5);
    // Default SOS
    i2c_writen(0xA0, 0XFE, 115, 0); MS_TIMER(5);
    i2c_writen(0xA0, 0XFE, 116, 0); MS_TIMER(5);
    // Default STD
    i2c_writen(0xA0, 0XFE, 117, 0); MS_TIMER(5);
    i2c_writen(0xA0, 0XFE, 118, 0); MS_TIMER(5);
    // Default HLT
    i2c_writen(0xA0, 0XFE, 119, 0); MS_TIMER(5);
    i2c_writen(0xA0, 0XFE, 120, 0); MS_TIMER(5);
    */
    RESTART = ON;

    goto restart11;
}


/*****************************************************************************************************/ 
// REPLY==33  SOS CLEAR
/*****************************************************************************************************/
else if(REPLY == 33)
{
    // Step 1
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);

    // Step 2
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(200);

    // Step 3: Content
    R_UART2_SEND("SOS Clear");

    // Step 4: Send
    MS_TIMER(10);
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
    goto restart11;
}

/*****************************************************************************************************/ 
// REPLY==34  SET SOS TIMEOUT
/*****************************************************************************************************/
else if(REPLY == 34)
{
    // Step 1
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);

    // Step 2
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(200);

    // Step 3: Read back from EEPROM � reconstruct unsigned int from 2 bytes
    R_UART2_SEND("SOS Timeout Changed to ");
    {
        unsigned int eep_val;
        unsigned int temp_o;

        eep_val  = (unsigned int)i2c_readn(0xA0, 0XFE, 122) << 8;  // high byte
        MS_TIMER(2);
        eep_val |= (unsigned int)i2c_readn(0xA0, 0XFE, 123);        // low byte
        MS_TIMER(2);

        // Print as 3 digits
        temp_o = eep_val % 100;
        R_UART2_SEND_User(((eep_val / 100) + 0x30));
        R_UART2_SEND_User(((temp_o / 10) + 0x30));
        R_UART2_SEND_User(((temp_o % 10) + 0x30));
    }

    // Step 4: Send
    MS_TIMER(10);
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
    goto restart11;
}

/*****************************************************************************************************/ 
// REPLY==35  SET SOS NUMBERS
/*****************************************************************************************************/
else if(REPLY == 35)
{
    // Step 1
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);

    // Step 2
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(200);

    // Step 3: Read back from EEPROM
    R_UART2_SEND("SOS Number Updated:");

    // Print num1 from EEPROM 124..133
    for(FOR_0 = 124; FOR_0 <= 133; FOR_0++)
    {
        T = i2c_readn(0xA0, 0XFE, FOR_0);
        MS_TIMER(2);
        if(T == '\0') break;
        R_UART2_SEND_User(T);
        NOP();
    }

    R_UART2_SEND(",");

    // Print num2 from EEPROM 134..143
    for(FOR_0 = 134; FOR_0 <= 143; FOR_0++)
    {
        T = i2c_readn(0xA0, 0XFE, FOR_0);
        MS_TIMER(2);
        if(T == '\0') break;
        R_UART2_SEND_User(T);
        NOP();
    }

    // Step 4: Send
    MS_TIMER(10);
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
    goto restart11;
}
/*****************************************************************************************************/ 
// REPLY==36  SET BATTERY THRESHOLD
/*****************************************************************************************************/
else if(REPLY == 36)
{
    // Step 1
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);

    // Step 2
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(200);

    // Step 3: Read back from EEPROM
    R_UART2_SEND("Battery Threshold Changed to ");
    T = i2c_readn(0xA0, 0XFE, 144);
    MS_TIMER(2);

    // Print value � max 2 digits (0-99)
    if(T >= 10)
    {
        R_UART2_SEND_User(Array_0[T / 10]);
    }
    R_UART2_SEND_User(Array_0[T % 10]);

    // Step 4: Send
    MS_TIMER(10);
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
    goto restart11;
}
/*****************************************************************************************************/ 
// REPLY==37  SET FOTA
/*****************************************************************************************************/
else if(REPLY == 37)
{
    // Step 1
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);

    // Step 2
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(200);

    // Step 3: Content
    R_UART2_SEND("Restarting For FOTA...");

    // Step 4: Send
    MS_TIMER(10);
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
    goto restart11;
}
/*****************************************************************************************************/ 
// REPLY==38  GET PROFILE
/*****************************************************************************************************/
else if(REPLY == 38)
{
    // Step 1: Query current network name fresh
    NETWORK_NAME_RX = ON;
    R_UART2_SEND("AT+COPS?\r\n");
    ACK_RX(40, 2, 50, 0);
    NETWORK_NAME_RX = OFF;

    // Step 2: Setup SMS
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);

    // Step 3: Send to caller
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(200);

    // Step 4: Content
    R_UART2_SEND("Current Profile : ");
    for(FOR_1 = 0; FOR_1 <= 7; FOR_1++)
    {
        if(NETWORK_NAME[FOR_1] != '0' && NETWORK_NAME[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(NETWORK_NAME[FOR_1]);
            MS_TIMER(1);
        }
        else
        {
            break;
        }
    }

    // Step 5: Send
    MS_TIMER(10);
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
    goto restart11;
}

/*****************************************************************************************************/
// REPLY==39  GET SOS TIMEOUT
/*****************************************************************************************************/
else if(REPLY == 39)
{
    // Step 1: Setup SMS mode
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);
    
    // Step 2: Send to actual sender number
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(200);  // Wait for '>' prompt
    
    // Step 3: Content - read from EEPROM addresses 122-123 (where SETSOSTIMEOUT stores it)
    R_UART2_SEND("SOS Timeout : ");
    
    // Read 16-bit value from EEPROM (high byte 122, low byte 123)
    T = (unsigned int)i2c_readn(0xA0, 0XFE, 122) << 8;  // high byte
    MS_TIMER(2);
    T |= (unsigned int)i2c_readn(0xA0, 0XFE, 123);       // low byte
    MS_TIMER(2);
    
    // Print as 3 digits (max 255)
    O = T % 100;
    R_UART2_SEND_User(((T / 100) + 0x30));
    R_UART2_SEND_User(((O / 10) + 0x30));
    R_UART2_SEND_User(((O % 10) + 0x30));
    
    // Step 4: Send SMS
    MS_TIMER(10);
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
    goto restart11;
}

/*****************************************************************************************************/
// REPLY==40  GET VEHICLE STATUS
/*****************************************************************************************************/
else if(REPLY == 40)
{
    // Step 1: Setup SMS mode
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);
    
    // Step 2: Send to actual sender number
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(200);  // Wait for '>' prompt
    
    // Step 3: Content - GPRS Status
    if(GPRS_REG == ON)  // GPRS_REG indicates GPRS registration
    {
        R_UART2_SEND("GPRS ACTIVE\n");
    }
    else
    {
        R_UART2_SEND("GPRS NOT ACTIVE\n");
    }
    
    // Signal Strength
    R_UART2_SEND("SIG : ");
    R_UART2_SEND_User(Array_0[GSM_STRENGTH/10]);
    R_UART2_SEND_User(Array_0[GSM_STRENGTH%10]);
    R_UART2_SEND("\n");
    
    // Main Voltage (float format XX.X)
    R_UART2_SEND("Mains Volt : ");
    VOLT = MAIN_BATTERY_VOLTAGE;  // Value like 153 = 15.3V
    R_UART2_SEND_User(((VOLT/100) + 0x30));  // Tens digit
    R_UART2_SEND(".");
    VOLT = VOLT % 100;
    R_UART2_SEND_User(((VOLT/10) + 0x30));   // Tenths digit
    R_UART2_SEND_User(((VOLT%10) + 0x30));   // Hundredths digit
    R_UART2_SEND("\n");
    
    // Battery Voltage (float format X.X)
    R_UART2_SEND("Batt Volt : ");
    VOLT = BACKUP_BATTERY_VOLTAGE % 1000;
    if(VOLT >= 440) { VOLT = 440; }  // Cap at 4.4V as in DATA_PRINT
    R_UART2_SEND_User(((VOLT/100) + 0x30));  // Units digit
    R_UART2_SEND(".");
    VOLT = VOLT % 100;
    R_UART2_SEND_User(((VOLT/10) + 0x30));   // Tenths digit
    R_UART2_SEND_User(((VOLT%10) + 0x30));   // Hundredths digit
    R_UART2_SEND("\n");
    
    // Server Status
    if(INTERNET_CONNECTED == ON)
    {
        R_UART2_SEND("SERVER CONNECTED\n");
    }
    else
    {
        R_UART2_SEND("SERVER NOT CONNECTED\n");
    }
    
    // GPS Status
    if(GPS_DIRECTION_DATA_VALID == ON)
    {
        R_UART2_SEND("GPS FIXED");
    }
    else
    {
        R_UART2_SEND("GPS NOT FIXED");
    }
    
    // Step 4: Send SMS
    MS_TIMER(10);
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
    goto restart11;
}

/*****************************************************************************************************/
// REPLY==41  GET SERVER DETAILS - Send all 4 servers
/*****************************************************************************************************/
else if(REPLY == 41)
{
    // Step 1: Setup SMS mode
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);
    
    // Step 2: Send to actual sender number
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(200);  // Wait for '>' prompt
    
    // Step 3: Content - IP1 (Primary Server)
    R_UART2_SEND("IP1 : ");
    for(FOR_0 = 0; FOR_0 <= 29 && TEMP_PIP[FOR_0] != '\0'; FOR_0++)
    {
        R_UART2_SEND_User(TEMP_PIP[FOR_0]);
        NOP();
    }
    R_UART2_SEND("\n");
    
    // Port1 (Primary Server Port)
    R_UART2_SEND("Port1 : ");
    for(FOR_0 = 0; FOR_0 <= 5 && TEMP_PPN[FOR_0] != '\0'; FOR_0++)
    {
        R_UART2_SEND_User(TEMP_PPN[FOR_0]);
        NOP();
    }
    R_UART2_SEND("\n");
    
    // IP2 (Secondary Server)
    R_UART2_SEND("IP2 : ");
    for(FOR_0 = 0; FOR_0 <= 29 && TEMP_PIP2[FOR_0] != '\0'; FOR_0++)
    {
        R_UART2_SEND_User(TEMP_PIP2[FOR_0]);
        NOP();
    }
    R_UART2_SEND("\n");
    
    // Port2 (Secondary Server Port)
    R_UART2_SEND("Port2 : ");
    for(FOR_0 = 0; FOR_0 <= 5 && TEMP_PPN2[FOR_0] != '\0'; FOR_0++)
    {
        R_UART2_SEND_User(TEMP_PPN2[FOR_0]);
        NOP();
    }
    R_UART2_SEND("\n");
    
    // IP3 (Tertiary Server)
    R_UART2_SEND("IP3 : ");
    for(FOR_0 = 0; FOR_0 <= 29 && TEMP_SIP[FOR_0] != '\0'; FOR_0++)
    {
        R_UART2_SEND_User(TEMP_SIP[FOR_0]);
        NOP();
    }
    R_UART2_SEND("\n");
    
    // Port3 (Tertiary Server Port)
    R_UART2_SEND("Port3 : ");
    for(FOR_0 = 0; FOR_0 <= 5 && TEMP_SPN[FOR_0] != '\0'; FOR_0++)
    {
        R_UART2_SEND_User(TEMP_SPN[FOR_0]);
        NOP();
    }
    R_UART2_SEND("\n");
    
    // IP4 (Quaternary Server)
    R_UART2_SEND("IP4 : ");
    for(FOR_0 = 0; FOR_0 <= 29 && TEMP_SIP2[FOR_0] != '\0'; FOR_0++)
    {
        R_UART2_SEND_User(TEMP_SIP2[FOR_0]);
        NOP();
    }
    R_UART2_SEND("\n");
    
    // Port4 (Quaternary Server Port)
    R_UART2_SEND("Port4 : ");
    for(FOR_0 = 0; FOR_0 <= 5 && TEMP_SPN2[FOR_0] != '\0'; FOR_0++)
    {
        R_UART2_SEND_User(TEMP_SPN2[FOR_0]);
        NOP();
    }
    R_UART2_SEND("\n");
    
    // Step 4: Send SMS
    MS_TIMER(10);
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
    goto restart11;
}
/*****************************************************************************************************/
// REPLY==42  GET LOCATION
/*****************************************************************************************************/
else if(REPLY == 42)
{
    // Step 1: Setup SMS mode
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);
    
    // Step 2: Send to actual sender number
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(200);  // Wait for '>' prompt
    
    // Step 3: Content - Latitude
    R_UART2_SEND("Lat: ");
    // LAT_DM format: DDMM.MMMM in your system
    // Convert to DD.DDDDDD format for output
    for(FOR_0 = 0; FOR_0 <= 7; FOR_0++)
    {
        R_UART2_SEND_User(LAT_DM[FOR_0]);
        if(FOR_0 == 1)  // After DD, add decimal point
        {
            R_UART2_SEND(".");
        }
    }
    R_UART2_SEND("\n");
    
    // Longitude
    R_UART2_SEND("Lon: ");
    // LOG_DM format: DDDMM.MMMM in your system
    for(FOR_0 = 0; FOR_0 <= 8; FOR_0++)
    {
        R_UART2_SEND_User(LOG_DM[FOR_0]);
        if(FOR_0 == 1)  // After DDD, add decimal point
        {
            R_UART2_SEND(".");
        }
    }
    R_UART2_SEND("\n");
    
    // Altitude
    R_UART2_SEND("Alt: ");
    // ALTITUDE array contains altitude string
    for(FOR_0 = 0; FOR_0 <= 4 && ALTITUDE[FOR_0] != 0x00 && ALTITUDE[FOR_0] != ' '; FOR_0++)
    {
        R_UART2_SEND_User(ALTITUDE[FOR_0]);
    }
    R_UART2_SEND("\n");
    
    // Speed
    R_UART2_SEND("Speed: ");
    // SPEED_DATA contains speed with decimal
    for(FOR_0 = 0; FOR_0 <= SPEED_DATA_LENGTH_COUNT; FOR_0++)
    {
        R_UART2_SEND_User(SPEED_DATA[FOR_0]);
    }
    
    // Step 4: Send SMS
    MS_TIMER(10);
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
    goto restart11;
}
/*****************************************************************************************************/
// REPLY==43  GET PANIC STATUS
/*****************************************************************************************************/
else if(REPLY == 43)
{
    // Step 1: Setup SMS mode
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);
    
    // Step 2: Send to actual sender number
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(200);  // Wait for '>' prompt
    
    // Step 3: Content - Check PANIC status
    R_UART2_SEND("SOS ");
    
    // Check various panic-related flags
    if(PANIC_ALERT == ON || PANIC_CONTROL_STATE == ON || PANIC_ALERT_PACKET == ON)
    {
        R_UART2_SEND("ON");
    }
    else
    {
        R_UART2_SEND("OFF");
    }
    
    // Step 4: Send SMS
    MS_TIMER(10);
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
    goto restart11;
}

/*****************************************************************************************************/ 
// REPLY==44  GET VEHICLE INFO
/*****************************************************************************************************/
else if(REPLY == 44)
{
    unsigned int T_VAL;
    unsigned int sos_idx;
    unsigned int i;
    ICCID_RX = 0;  // Set flag to capture ICCID response in UART RX handler
    R_UART2_SEND("AT+QCCID\r\n");
    //ACK_RX(40, 2, 50, 0);  // Wait for modem response, not blind timer
    MS_TIMER(300);           // give modem time to send ICCID line after OK

    // Step 2: Fetch fresh network name - clear buffer and parser state first
    
    for(i = 0; i < 8; i++)
    {
        NETWORK_NAME[i] = ' ';  /* Clear with spaces, not garbage */
    }
    MS_TIMER(50);  /* Let any pending UART data settle */
    
    NETWORK_NAME_RX = ON;
    R_UART2_SEND("AT+COPS?\r\n");
    ACK_RX(40, 2, 50, 0);
    MS_TIMER(100);  /* Wait for parser to finish capturing network name */
    NETWORK_NAME_RX = OFF;

    // Step 3: Setup SMS
    R_UART2_SEND("AT+CMGF=1\r\n");
    MS_TIMER(100);

    // Step 4: Send to caller
    R_UART2_SEND("AT+CMGS=\"");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(PHONE_NUMBER_OF_SENDER[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_1]);
        }
        MS_TIMER(1);
    }
    R_UART2_SEND("\"\r\n");
    MS_TIMER(200);

    // ---- MFG ----
    R_UART2_SEND("MFG : LKSI\n");

    // ---- IMEI ----
    R_UART2_SEND("IMEI : ");
    for(FOR_1 = 1; FOR_1 <= 15; FOR_1++)
    {
        R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);
        NOP();
    }
    R_UART2_SEND("\n");

    // ---- CCID ----
    R_UART2_SEND("CCID : ");
    for(FOR_1 = 0; FOR_1 <= 19; FOR_1++)
    {
        if(ICCID[FOR_1] != '\0')
        {
            R_UART2_SEND_User(ICCID[FOR_1]);
            MS_TIMER(1);
        }
        else 
        { 
            break; 
        }
    }
    R_UART2_SEND("\n");

    // ---- Vehicle Number ----
    R_UART2_SEND("VehicleNo : ");
    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(VEICHLE_NUMBER[FOR_1] != ' ' && VEICHLE_NUMBER[FOR_1] != '\0')
        {
            R_UART2_SEND_User(VEICHLE_NUMBER[FOR_1]);
            MS_TIMER(1);
        }
    }
    R_UART2_SEND("\n");

    // ---- Network ----
    R_UART2_SEND("Network : ");
    for(FOR_1 = 0; FOR_1 <= 7; FOR_1++)
    {
        if(NETWORK_NAME[FOR_1] != '0' && NETWORK_NAME[FOR_1] != 0x00)
        {
            R_UART2_SEND_User(NETWORK_NAME[FOR_1]);
            MS_TIMER(1);
        }
        else { break; }
    }
    R_UART2_SEND("\n");
    // ---- APN MODE ----
    // Compare current APN against default "sensem2m"
    // If APN was manually set and differs from default -> MANUAL
    // Otherwise -> AUTO
    for(FOR_1 = 0; FOR_1 < 15; FOR_1++)
    {
        if(TEMP_APN[FOR_1] != default_apn[FOR_1])
        {
            apn_is_default = 0;
            break;
        }
    }

    if(apn_is_default)
    {
        R_UART2_SEND("APNMODE : AUTO\n");
    }
    else
    {
        R_UART2_SEND("APNMODE : MANUAL\n");
    }


    // ---- Current APN ----

    R_UART2_SEND("APN : ");

    for(FOR_1 = 0; FOR_1 < APN_LENGTH; FOR_1++)
    {
        R_UART2_SEND_User(TEMP_APN[FOR_1]);
        MS_TIMER(1);
    }

    R_UART2_SEND("\n");

    // ---- Batt Threshold ----
    // Stored at EEPROM 144 as integer e.g. 36 = 3.6V
    T_VAL = i2c_readn(0xA0, 0XFE, 144);
    MS_TIMER(2);
    R_UART2_SEND("Batt Threshold : ");
    R_UART2_SEND_User(Array_0[T_VAL / 10]);
    R_UART2_SEND(".");
    R_UART2_SEND_User(Array_0[T_VAL % 10]);
    R_UART2_SEND("V\n");

    // ---- SOS1 (EEPROM 124..133) ----
    R_UART2_SEND("SOS1 : ");
    for(sos_idx = 124; sos_idx <= 133; sos_idx++)
    {
        T_VAL = i2c_readn(0xA0, 0XFE, sos_idx);
        MS_TIMER(2);
        if(T_VAL == '\0' || T_VAL == 0xFF) break;
        R_UART2_SEND_User(T_VAL);
        NOP();
    }
    R_UART2_SEND("\n");

    // ---- SOS2 (EEPROM 134..143) ----
    R_UART2_SEND("SOS2 : ");
    for(sos_idx = 134; sos_idx <= 143; sos_idx++)
    {
        T_VAL = i2c_readn(0xA0, 0XFE, sos_idx);
        MS_TIMER(2);
        if(T_VAL == '\0' || T_VAL == 0xFF) break;
        R_UART2_SEND_User(T_VAL);
        NOP();
    }
    // R_UART2_SEND("\n");

    // ---- Latitude ----
    // R_UART2_SEND("Lat : ");
    // if(GPS_DIRECTION_DATA_VALID == ON)
    // {
    //     for(FOR_1 = 0; FOR_1 <= 7; FOR_1++)
    //     {
    //         R_UART2_SEND_User(LAT_DM[FOR_1]);
    //         if(FOR_1 == 1) 
    //         { 
    //             R_UART2_SEND(".");
    //         }
    //     }
    //     if(LAT_DIRECTION == 'N') 
    //     { 
    //         R_UART2_SEND("N"); 
    //     }
    //     else
    //     { 
    //         R_UART2_SEND("S"); 
    //     }
    //     R_UART2_SEND("\n");
    //     // ---- Longitude ----
    //     R_UART2_SEND("Lon : ");
    //     for(FOR_1 = 0; FOR_1 <= 7; FOR_1++)
    //     {
    //         R_UART2_SEND_User(LOG_DM[FOR_1]);

    //         if(FOR_1 == 1) 
    //         { 
    //             R_UART2_SEND("."); 
    //         }
    //     }
    //     if(LON_DIRECTION == 'E') 
    //     { 
    //         R_UART2_SEND("E"); 
    //     }
    //     else                     
    //     { 
    //         R_UART2_SEND("W"); 
    //     }
    // }
    // else
    // {
    //     R_UART2_SEND("00.000000");
    //     if(LAT_DIRECTION == 'N') 
    //     { 
    //         R_UART2_SEND("N"); 
    //     }
    //     else
    //     { 
    //         R_UART2_SEND("S"); 
    //     }
    //     R_UART2_SEND("\n");
    //     R_UART2_SEND("00.000000");
    //     if(LON_DIRECTION == 'E') 
    //     { 
    //         R_UART2_SEND("E"); 
    //     }
    //     else                     
    //     { 
    //         R_UART2_SEND("W"); 
    //     }
    // }

    // Step 5: Send
    MS_TIMER(10);
    R_UART2_SEND_User(CTRL_Z);
    ACK_RX(2500, 2, 500, 100);
    goto restart11;
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
R_UART2_SEND("Device Restarting� ");
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
//REPL_10:
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
	for(FOR_0=0; FOR_0 <= 29 && TEMP_PIP2[FOR_0] != '\0'; FOR_0++)
	{
		R_UART2_SEND_User(TEMP_PIP2[FOR_0]);
		NOP();
	}
}
/*****************************************************************************************************/
else if(REPLY==19)
{
R_UART2_SEND("SECONDARY IP:");
for(FOR_0=0; FOR_0 <= 29 && TEMP_SIP2[FOR_0] != '\0'; FOR_0++)
{
R_UART2_SEND_User(TEMP_SIP2[FOR_0]);NOP();
}
}
/*****************************************************************************************************/
else if(REPLY==20)
{
	//REPL_14:
	R_UART2_SEND("PRIMARY IP:");
	
	for(FOR_0 = 0; FOR_0 <= 30 && TEMP_PIP[FOR_0] != '\0'; FOR_0++)
    {
        R_UART2_SEND_User(TEMP_PIP[FOR_0]);
        NOP();
    }
	
	R_UART2_SEND(" PORT NUM:");

	for(FOR_0 = 0; FOR_0 <= 6 && TEMP_PPN[FOR_0] != '\0'; FOR_0++)
    {
        R_UART2_SEND_User(TEMP_PPN[FOR_0]);
        NOP();
    }
	
	if(REPLY==17)
	{
		R_UART2_SEND(",");
		goto REPL_15;
	}
}
/*****************************************************************************************************/
else if(REPLY == 21)
{
    REPL_15:
    R_UART2_SEND("SECONDARY IP:");

    for(FOR_0 = 0; FOR_0 <= 30 && TEMP_SIP[FOR_0] != '\0'; FOR_0++)
    {
        R_UART2_SEND_User(TEMP_SIP[FOR_0]);
        NOP();
    }

    R_UART2_SEND(" PORT NUM:");

    for(FOR_0 = 0; FOR_0 <= 6 && TEMP_SPN[FOR_0] != '\0'; FOR_0++)
    {
        R_UART2_SEND_User(TEMP_SPN[FOR_0]);
        NOP();
    }

    if(REPLY == 17)
    {
        R_UART2_SEND(",");
        goto REPL_16;
    }
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
    BATTERY_MEASUREMENT = ON;

    MS_TIMER(10);

         if(BACKUP_BATTERY_VOLTAGE <= 330)                          { R_UART2_SEND("010,"); }
    else if(BACKUP_BATTERY_VOLTAGE >= 330 && BACKUP_BATTERY_VOLTAGE < 345) { R_UART2_SEND("020,"); }
    else if(BACKUP_BATTERY_VOLTAGE >= 345 && BACKUP_BATTERY_VOLTAGE < 350) { R_UART2_SEND("030,"); }
    else if(BACKUP_BATTERY_VOLTAGE >= 350 && BACKUP_BATTERY_VOLTAGE < 355) { R_UART2_SEND("040,"); }
    else if(BACKUP_BATTERY_VOLTAGE >= 355 && BACKUP_BATTERY_VOLTAGE < 360) { R_UART2_SEND("050,"); }
    else if(BACKUP_BATTERY_VOLTAGE >= 360 && BACKUP_BATTERY_VOLTAGE < 365) { R_UART2_SEND("060,"); }
    else if(BACKUP_BATTERY_VOLTAGE >= 365 && BACKUP_BATTERY_VOLTAGE < 370) { R_UART2_SEND("070,"); }
    else if(BACKUP_BATTERY_VOLTAGE >= 370 && BACKUP_BATTERY_VOLTAGE < 375) { R_UART2_SEND("080,"); }
    else if(BACKUP_BATTERY_VOLTAGE >= 375 && BACKUP_BATTERY_VOLTAGE < 420) { R_UART2_SEND("090,"); }
    else if(BACKUP_BATTERY_VOLTAGE >= 420 && BACKUP_BATTERY_VOLTAGE < 490) { R_UART2_SEND("100,"); }

    BATTERY_MEASUREMENT = OFF;
}

void GET_TIME(void)
{
    TIME[0] = DAY;
    TIME[1] = MONTH;
    TIME[2] = YEAR;
    TIME[3] = HOUR;
    TIME[4] = MIN;
    TIME[5] = SEC;
}

void PRINT_ZEROS(unsigned int q)
{
         if(q == 0)
    {
        R_UART2_SEND("000");
        NOP();
    }
    else if(q == 1)
    {
        R_UART2_SEND("00");
        NOP();
    }
    else if(q == 2)
    {
        R_UART2_SEND("0");
        NOP();
    }
}

void PRINT_ZEROS_2(unsigned int q)
{
         if(q == 0)
    {
        SEND_TO_ARRAY("000");
        NOP();
    }
    else if(q == 1)
    {
        SEND_TO_ARRAY("00");
        NOP();
    }
    else if(q == 2)
    {
        SEND_TO_ARRAY("0");
        NOP();
    }
}

void GET_DEGREES(void)
{
    for(FOR_1 = 0; FOR_1 <= 7; FOR_1++)
    {
        LAT_DM[FOR_1] = LAT_DM_RX[FOR_1];
    }

    P_LAT_DM_RX = LAT_DM_RX[5];

    for(FOR_1 = 0; FOR_1 <= 8; FOR_1++)
    {
        LOG_DM[FOR_1] = LOG_DM_RX[FOR_1];
    }
}

void GET_SPEED_DATA(void)
{
    ADD_ZERO_TO_SPEED = CLR;

    if(NO_OF_SAT <= 3)
    {
        for(FOR_1 = 0; FOR_1 <= 3; FOR_1++)
        {
            NOP();

            SPEED_DATA[FOR_1] = '0';
        }

        SPEED_DATA[2] = '.';
        SPEED_DATA_LENGTH_COUNT = 3;
    }
    else
    {
        for(FOR_1 = 0; FOR_1 <= 4; FOR_1++)
        {
            NOP();

            SPEED_DATA[FOR_1] = SPEED_DATA_RX[FOR_1];

            if(SPEED_DATA[FOR_1] == '.')
            {
                DECIMAL_POINT_CAME_STOP_TX = ON;

                if(FOR_1 == 1)
                {
                    ADD_ZERO_TO_SPEED = SET;
                }
            }
            else if(DECIMAL_POINT_CAME_STOP_TX == ON)
            {
                DECIMAL_POINT_CAME_STOP_TX = OFF;
                SPEED_DATA_LENGTH_COUNT = FOR_1;

                FOR_1 = 5;

                break;
            }
        }

        T_SPEED = 0x0F & SPEED_DATA[0];

        if(SPEED_DATA[1] != '.')
        {
            T_SPEED = ((T_SPEED * 10) + (0x0F & SPEED_DATA[1]));
        }
    }
}

void GET_IMEI(void)
{
restart100:

    IMEI_RX = ON;

    //R_UART2_SEND("AT\r\n");
    //ACK_RX(20, 2, 10, 1);

    //MS_TIMER(100);

    R_UART2_SEND("AT+GSN\r\n");
    ACK_RX(40, 2, 50, 0);

    if(RESTART == ON)
    {
        RESTART = OFF;
        goto restart100;
    }

    IMEI_RX = OFF;

    if(IMEI_ACK_RX == 0)
    {
        CMD_DATA_WRITE_IN_EEROM(19);

        for(K = 0; K < 16; K++)
        {
            IMEI_EEPROM[K] = i2c_readn(0xA0, 0XFA, K);
            MS_TIMER(5);
        }
    }
}

void GET_MCC_MNC_LAC_CELL_ID(void)
{
    /* Initialize all cell data arrays to zeros on each call */
    for(FOR_1 = 0; FOR_1 < 5; FOR_1++)
    {
        CELL_ID[FOR_1] = '0';
        LAC[FOR_1] = '0';
    }

    for(FOR_1 = 0; FOR_1 < 4; FOR_1++)
    {
        for(FOR_2 = 0; FOR_2 < 5; FOR_2++)
        {
            NCELL_CID[FOR_1][FOR_2] = '0';
            NCELL_LAC[FOR_1][FOR_2] = '0';
        }

        NCELL_DBM[FOR_1] = 0;
    }

restart5:

    R_UART2_SEND("AT+QENG=1,3\r\n");

    ACK_RX(200, 2, 50, 50);

    if(RESTART == ON)
    {
        RESTART = OFF;
        goto restart5;
    }

    ACK = CLR;

    GET_MCC_MNC_LAC_CELL_ID_RX = GET_NMR_RX = SET;

    R_UART2_SEND("AT+QENG?\r\n");

    ACK_RX(200, 2, 50, 0);

    if(RESTART == ON)
    {
        RESTART = OFF;
        goto restart5;
    }

    GET_MCC_MNC_LAC_CELL_ID_RX = GET_NMR_RX = CLR;

    /* Convert Serving Cell dBm to CSQ (0-31) - preserve sign without VOLT */
    {
        int csq = (SERVING_CELL_DBM + 113) / 2;

        SERVING_CELL_DBM = csq;
    }

    /* Copy neighbor cell 1 data */
    for(FOR_2 = 0; FOR_2 < 4; FOR_2++)
    {
        NCELL_LAC[0][FOR_2] = LAC_1[FOR_2];
        NCELL_CID[0][FOR_2] = CELL_ID_1[FOR_2];
    }

    VOLT = 0;
    FOR_3 = 0;

    if(DBM_1[0] == '-')
    {
        FOR_3 = 1;
        FOR_2 = 1;
    }
    else
    {
        FOR_2 = 0;
    }

    while(FOR_2 <= DBM_DATA_LENGTH[1] && DBM_1[FOR_2] >= '0' && DBM_1[FOR_2] <= '9')
    {
        VOLT = (VOLT * 10) + (DBM_1[FOR_2] - '0');

        FOR_2++;
    }

    if(FOR_3 == 1)
    {
        VOLT = -(VOLT);
    }

    NCELL_DBM[0] = (VOLT + 113) / 2;

    if(NCELL_DBM[0] < 0)
    {
        NCELL_DBM[0] = 0;
    }

    if(NCELL_DBM[0] > 31)
    {
        NCELL_DBM[0] = 31;
    }

    /* Copy neighbor cell 2 data */
    for(FOR_2 = 0; FOR_2 < 4; FOR_2++)
    {
        NCELL_LAC[1][FOR_2] = LAC_2[FOR_2];
        NCELL_CID[1][FOR_2] = CELL_ID_2[FOR_2];
    }

    VOLT = 0;
    FOR_3 = 0;

    if(DBM_2[0] == '-')
    {
        FOR_3 = 1;
        FOR_2 = 1;
    }
    else
    {
        FOR_2 = 0;
    }

    while(FOR_2 <= DBM_DATA_LENGTH[2] && DBM_2[FOR_2] >= '0' && DBM_2[FOR_2] <= '9')
    {
        VOLT = (VOLT * 10) + (DBM_2[FOR_2] - '0');

        FOR_2++;
    }

    if(FOR_3 == 1)
    {
        VOLT = -(VOLT);
    }

    NCELL_DBM[1] = (VOLT + 113) / 2;

    if(NCELL_DBM[1] < 0)
    {
        NCELL_DBM[1] = 0;
    }

    if(NCELL_DBM[1] > 31)
    {
        NCELL_DBM[1] = 31;
    }

    /* Copy neighbor cell 3 data */
    for(FOR_2 = 0; FOR_2 < 4; FOR_2++)
    {
        NCELL_LAC[2][FOR_2] = LAC_3[FOR_2];
        NCELL_CID[2][FOR_2] = CELL_ID_3[FOR_2];
    }

    VOLT = 0;
    FOR_3 = 0;

    if(DBM_3[0] == '-')
    {
        FOR_3 = 1;
        FOR_2 = 1;
    }
    else
    {
        FOR_2 = 0;
    }

    while(FOR_2 <= DBM_DATA_LENGTH[3] && DBM_3[FOR_2] >= '0' && DBM_3[FOR_2] <= '9')
    {
        VOLT = (VOLT * 10) + (DBM_3[FOR_2] - '0');

        FOR_2++;
    }

    if(FOR_3 == 1)
    {
        VOLT = -(VOLT);
    }

    NCELL_DBM[2] = (VOLT + 113) / 2;

    if(NCELL_DBM[2] < 0)
    {
        NCELL_DBM[2] = 0;
    }

    if(NCELL_DBM[2] > 31)
    {
        NCELL_DBM[2] = 31;
    }

    /* Copy neighbor cell 4 data */
    for(FOR_2 = 0; FOR_2 < 4; FOR_2++)
    {
        NCELL_LAC[3][FOR_2] = LAC_4[FOR_2];
        NCELL_CID[3][FOR_2] = CELL_ID_4[FOR_2];
    }

    VOLT = 0;
    FOR_3 = 0;

    if(DBM_4[0] == '-')
    {
        FOR_3 = 1;
        FOR_2 = 1;
    }
    else
    {
        FOR_2 = 0;
    }

    while(FOR_2 <= DBM_DATA_LENGTH[4] && DBM_4[FOR_2] >= '0' && DBM_4[FOR_2] <= '9')
    {
        VOLT = (VOLT * 10) + (DBM_4[FOR_2] - '0');

        FOR_2++;
    }

    if(FOR_3 == 1)
    {
        VOLT = -(VOLT);
    }

    NCELL_DBM[3] = (VOLT + 113) / 2;

    if(NCELL_DBM[3] < 0)
    {
        NCELL_DBM[3] = 0;
    }

    if(NCELL_DBM[3] > 31)
    {
        NCELL_DBM[3] = 31;
    }
}

void WELCOME_STRING(void)
{
    DATA_BUFFER_INDEX = 0;   /* start a fresh packet in the buffer */
    CHECKSUM_BYTE = 0;

    BUFFER_APPEND_STR("$LGN,");

    CHECKSUM_BYTE ^= 0x24;
    CHECKSUM_BYTE ^= 0x4C;
    CHECKSUM_BYTE ^= 0x47;
    CHECKSUM_BYTE ^= 0x4E;
    CHECKSUM_BYTE ^= 0x2C;

    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(VEICHLE_NUMBER[FOR_1] != ' ' && VEICHLE_NUMBER[FOR_1] != '\0')
        {
            BUFFER_APPEND_CHAR(VEICHLE_NUMBER[FOR_1]);

            CHECKSUM_BYTE ^= VEICHLE_NUMBER[FOR_1];

            MS_TIMER(1);
        }
    } // VR NUMBER

    BUFFER_APPEND_STR(",");
    CHECKSUM_BYTE ^= 0x2C;

    for(FOR_1 = 1; FOR_1 <= 15; FOR_1++)
    {
        BUFFER_APPEND_CHAR(IMEI_EEPROM[FOR_1]);

        CHECKSUM_BYTE ^= IMEI_EEPROM[FOR_1];

        NOP();
        NOP();
    } //IMEI NUMBER

    BUFFER_APPEND_STR(",");
    CHECKSUM_BYTE ^= 0x2C;

    BUFFER_APPEND_CHAR(((CURRENT_FRM_VERSION / 100) + 0x30));
    CHECKSUM_BYTE ^= ((CURRENT_FRM_VERSION / 100) + 0x30);

    BUFFER_APPEND_STR(".");
    CHECKSUM_BYTE ^= 0x2E;

    NOP();

    TEMP_FRM_VERSION = CURRENT_FRM_VERSION % 100;

    BUFFER_APPEND_CHAR(((TEMP_FRM_VERSION / 10) + 0x30));
    CHECKSUM_BYTE ^= ((TEMP_FRM_VERSION / 10) + 0x30);

    BUFFER_APPEND_STR(".");
    CHECKSUM_BYTE ^= 0x2E;

    NOP();

    BUFFER_APPEND_CHAR(((TEMP_FRM_VERSION % 10) + 0x30));
    CHECKSUM_BYTE ^= ((TEMP_FRM_VERSION % 10) + 0x30);                        // FRM VERSION

    BUFFER_APPEND_STR(",");
    CHECKSUM_BYTE ^= 0x2C;

    BUFFER_APPEND_STR("1.0.1");

    CHECKSUM_BYTE ^= 0x31;
    CHECKSUM_BYTE ^= 0x2E;
    CHECKSUM_BYTE ^= 0x30;
    CHECKSUM_BYTE ^= 0x2E;
    CHECKSUM_BYTE ^= 0x31;                                                    // Protocol Version

    BUFFER_APPEND_STR(",");
    CHECKSUM_BYTE ^= 0x2C;

    READ_LAST_LOCATION();   /* now appends into the same DATA_BUFFER, does not reset index */

    BUFFER_APPEND_STR(",");

    if(CHECKSUM_BYTE >= 16)
    {
        BUFFER_APPEND_CHAR(
            (CHECKSUM_BYTE / 16) +
            (CHECKSUM_BYTE / 16 < 10 ? 0x30 : 0x37)
        );

        BUFFER_APPEND_CHAR(
            (CHECKSUM_BYTE % 16) +
            (CHECKSUM_BYTE % 16 < 10 ? 0x30 : 0x37)
        );
    }
    else
    {
        BUFFER_APPEND_STR("0");
        BUFFER_APPEND_CHAR(CHECKSUM_BYTE + 0x30);
    }

    BUFFER_APPEND_STR("*");

    DATA_BUFFER[DATA_BUFFER_INDEX] = '\0';   /* null-terminate the completed packet */
}

#if 0
void WELCOME_STRING(void)
{
    CHECKSUM_BYTE = 0;

    R_UART2_SEND("$LGN,");

    CHECKSUM_BYTE ^= 0x24;
    CHECKSUM_BYTE ^= 0x4C;
    CHECKSUM_BYTE ^= 0x47;
    CHECKSUM_BYTE ^= 0x4E;
    CHECKSUM_BYTE ^= 0x2C;

    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(VEICHLE_NUMBER[FOR_1] != ' ' && VEICHLE_NUMBER[FOR_1] != '\0')
        {
            R_UART2_SEND_User(VEICHLE_NUMBER[FOR_1]);

            CHECKSUM_BYTE ^= VEICHLE_NUMBER[FOR_1];

            MS_TIMER(1);
        }
    } // VR NUMBER

    R_UART2_SEND(",");
    CHECKSUM_BYTE ^= 0x2C;

    for(FOR_1 = 1; FOR_1 <= 15; FOR_1++)
    {
        R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);

        CHECKSUM_BYTE ^= IMEI_EEPROM[FOR_1];

        NOP();
        NOP();
    } //IMEI NUMBER

    R_UART2_SEND(",");
    CHECKSUM_BYTE ^= 0x2C;

    R_UART2_SEND_User(((CURRENT_FRM_VERSION / 100) + 0x30));
    CHECKSUM_BYTE ^= ((CURRENT_FRM_VERSION / 100) + 0x30);

    R_UART2_SEND(".");
    CHECKSUM_BYTE ^= 0x2E;

    NOP();

    TEMP_FRM_VERSION = CURRENT_FRM_VERSION % 100;

    R_UART2_SEND_User(((TEMP_FRM_VERSION / 10) + 0x30));
    CHECKSUM_BYTE ^= ((TEMP_FRM_VERSION / 10) + 0x30);

    R_UART2_SEND(".");
    CHECKSUM_BYTE ^= 0x2E;

    NOP();

    R_UART2_SEND_User(((TEMP_FRM_VERSION % 10) + 0x30));
    CHECKSUM_BYTE ^= ((TEMP_FRM_VERSION % 10) + 0x30);                        // FRM VERSION

    R_UART2_SEND(",");
    CHECKSUM_BYTE ^= 0x2C;

    R_UART2_SEND("1.0.1");

    CHECKSUM_BYTE ^= 0x31;
    CHECKSUM_BYTE ^= 0x2E;
    CHECKSUM_BYTE ^= 0x30;
    CHECKSUM_BYTE ^= 0x2E;
    CHECKSUM_BYTE ^= 0x31;                                                    // Protocol Version

    R_UART2_SEND(",");
    CHECKSUM_BYTE ^= 0x2C;

    READ_LAST_LOCATION();

    R_UART2_SEND(",");

    if(CHECKSUM_BYTE >= 16)
    {
        R_UART2_SEND_User(
            (CHECKSUM_BYTE / 16) +
            (CHECKSUM_BYTE / 16 < 10 ? 0x30 : 0x37)
        );

        R_UART2_SEND_User(
            (CHECKSUM_BYTE % 16) +
            (CHECKSUM_BYTE % 16 < 10 ? 0x30 : 0x37)
        );
    }
    else
    {
        R_UART2_SEND("0");
        R_UART2_SEND_User(CHECKSUM_BYTE + 0x30);
    }

    R_UART2_SEND("*");
}
#endif
// void BOOT_STRING(void)
// {
//     R_UART2_SEND("$,BOOT,");

//     //for(FOR_1=0;FOR_1<=9;FOR_1++){if(VEICHLE_NUMBER[FOR_1]!=' '){R_UART2_SEND_User(VEICHLE_NUMBER[FOR_1]);MS_TIMER(1);}} // VR NUMBER
//     //R_UART2_SEND("$");

//     for(FOR_1 = 1; FOR_1 <= 15; FOR_1++)
//     {
//         R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);

//         NOP();
//         NOP();
//     } //IMEI NUMBER
// }


void STORE_LAST_LOCATION(void)
{
    char Address = 0;

    MS_TIMER(1);

    for(FOR_1 = 0; FOR_1 <= 7; FOR_1++)                    //LATITUDE AND DIRECTION
    {
        NOP();

        i2c_writen(0xA0, 0XFD, FOR_1, LAT_DM[FOR_1]);

        MS_TIMER(1);
    }

    Address = 8;

    for(FOR_1 = 0; FOR_1 <= 8; FOR_1++)                    //LATITUDE AND DIRECTION
    {
        NOP();

        i2c_writen(0xA0, 0XFD, Address, LOG_DM[FOR_1]);

        MS_TIMER(1);

        Address++;
    }

    MS_TIMER(1);

    if(LAT_DIRECTION == 'N')
    {
        MS_TIMER(1);

        i2c_writen(0xA0, 0XFD, 18, 'N');
    }
    else
    {
        MS_TIMER(1);

        i2c_writen(0xA0, 0XFF, 8, 'S');
    }

    if(LON_DIRECTION == 'E')
    {
        MS_TIMER(1);

        i2c_writen(0xA0, 0XFD, 19, 'E');
    }
    else
    {
        MS_TIMER(1);

        i2c_writen(0xA0, 0XFF, 8, 'W');
    }

    MS_TIMER(1);
}


void READ_LAST_LOCATION(void)
{
    RLL = i2c_readn(0xA0, 0XFD, 18);
    NOP();

    if(RLL == 'N' || RLL == 'S')
    {
        RLL = i2c_readn(0xA0, 0XFD, 19);
        NOP();

        if(RLL == 'E' || RLL == 'W')
        {
            NOP();

            RLL = i2c_readn(0xA0, 0XFD, 19);
            NOP();

            for(FOR_1 = 0; FOR_1 <= 7; FOR_1++)            // READ LAT
            {
                NOP();

                RLL = i2c_readn(0xA0, 0XFD, FOR_1);
                NOP();

                if(RLL < '0' || RLL > '9')
                {
                    RLL = '0';
                }

                if(FOR_1 == 2)
                {
                    BUFFER_APPEND_STR(".");
                }

                BUFFER_APPEND_CHAR(RLL);
            }

            BUFFER_APPEND_STR(",");

            NOP();

            RLL = i2c_readn(0xA0, 0XFD, 18);
            NOP();     // READ LAT DIRECTION

            BUFFER_APPEND_CHAR(RLL);

            BUFFER_APPEND_STR(",");

            /* FIX: longitude is 2-digit-degree + 6-decimal = 8 digits total,
               matching DATA_PRINT's LOG_DM[0..7] format. Was reading 9 digits
               (address 8..16) with decimal after the 3rd digit — now reads
               8 digits (address 8..15) with decimal after the 2nd digit. */
            for(FOR_1 = 8; FOR_1 <= 15; FOR_1++)            // READ LOG (8 digits)
            {
                NOP();

                RLL = i2c_readn(0xA0, 0XFD, FOR_1);
                NOP();

                if(RLL < '0' || RLL > '9')
                {
                    RLL = '0';
                }

                BUFFER_APPEND_CHAR(RLL);

                if(FOR_1 == 9)                              /* FIX: decimal after 2 digits, not 3 */
                {
                    BUFFER_APPEND_STR(".");
                }
            }

            BUFFER_APPEND_STR(",");

            NOP();

            RLL = i2c_readn(0xA0, 0XFD, 19);
            NOP();     // READ LOG DIRECTION

            BUFFER_APPEND_CHAR(RLL);
        }
    }
    else
    {
        BUFFER_APPEND_STR("00.000000,N,00.000000,E");
    }
}

#if 0
void READ_LAST_LOCATION(void)
{
    RLL = i2c_readn(0xA0, 0XFD, 18);
    NOP();

    if(RLL == 'N' || RLL == 'S')
    {
        RLL = i2c_readn(0xA0, 0XFD, 19);
        NOP();

        if(RLL == 'E' || RLL == 'W')
        {
            NOP();

            RLL = i2c_readn(0xA0, 0XFD, 19);
            NOP();

            for(FOR_1 = 0; FOR_1 <= 7; FOR_1++)            // READ LAT
            {
                NOP();

                RLL = i2c_readn(0xA0, 0XFD, FOR_1);
                NOP();

                if(FOR_1 == 1)
                {
                    R_UART2_SEND(".");
                }

                R_UART2_SEND_User(RLL);
            }

            R_UART2_SEND(",");

            NOP();

            RLL = i2c_readn(0xA0, 0XFD, 18);
            NOP();     // READ LAT DIRECTION

            R_UART2_SEND_User(RLL);

            R_UART2_SEND(",");

            for(FOR_1 = 8; FOR_1 <= 16; FOR_1++)            // READ LOG
            {
                NOP();

                RLL = i2c_readn(0xA0, 0XFD, FOR_1);
                NOP();

                R_UART2_SEND_User(RLL);

                if(FOR_1 == 10)
                {
                    R_UART2_SEND(".");
                }
            }

            R_UART2_SEND(",");

            NOP();

            RLL = i2c_readn(0xA0, 0XFD, 19);
            NOP();     // READ LOG DIRECTION

            R_UART2_SEND_User(RLL);
        }
    }
    else
    {
        R_UART2_SEND("00.000000,N,00.0000000,E");
    }
}
#endif

#if 0
void DATA_PRINT(char FORMAT)
{
    URL_PRINT = ON;

    if(FORMAT == 0)
    {
        if(PANIC_ALERT == ON)
        {
            R_UART2_SEND("$PVT,LKSI,");
        }
        else
        {
            R_UART2_SEND("$PVT,LKSI,");
        }

/************************************************************************************************************************************************************/

        R_UART2_SEND_User(((CURRENT_FRM_VERSION / 100) + 0x30));
        R_UART2_SEND(".");
        NOP();

        TEMP_FRM_VERSION = CURRENT_FRM_VERSION % 100;

        R_UART2_SEND_User(((TEMP_FRM_VERSION / 10) + 0x30));
        R_UART2_SEND(".");
        NOP();

        R_UART2_SEND_User(((TEMP_FRM_VERSION % 10) + 0x30));

        R_UART2_SEND(",");
        NOP();

        VOLT = BACKUP_BATTERY_VOLTAGE % 1000;

/************************************************************************************************************************************************************/
        // START CHARACTER, HEADER, VENDOR ID, FIRMWARE VERSION

        if(POWER_SOURCE_PACKET == ON)
        {
            R_UART2_SEND("BD,03,");
        }
        else if(POWER_SOURCE_RECONNECT_PACKET == ON)
        {
            R_UART2_SEND("BR,06,");
        }
        else if(LOW_BATTERY_ALERT_PACKET == ON)
        {
            R_UART2_SEND("BL,04,");
        }
        else if(BATTERY_CHARGED_PACKET == ON)
        {
            R_UART2_SEND("BH,05,");
        }
        else if(OTA_PACKET == ON)
        {
            OTA_PACKET = OFF;
            R_UART2_SEND("PC,12,");
        }
        else if(HARSH_BRAKE_PACKET == ON)
        {
            HARSH_BRAKE_PACKET = OFF;
            R_UART2_SEND("HB,13,");
            R_INTC1_Start();
        }
        else if(HARSH_ACC_PACKET == ON)
        {
            HARSH_ACC_PACKET = OFF;
            R_UART2_SEND("HA,14,");
            R_INTC1_Start();
        }
        else if(HARSH_TURN_PACKET == ON)
        {
            HARSH_TURN_PACKET = OFF;
            R_UART2_SEND("RT,15,");
            R_INTC1_Start();
        }
        else if(PANIC_CONTROL_STATE_1 == ON)
        {
            PANIC_TIME_STOP = CLR;
            PANIC_TIME_START = CLR;
            PANIC_ALERT = 0;
            PANIC_ALERT_PACKET = OFF;
            PANIC_CONTROL_STATE_1 = OFF;
            HOOTER = ON;
            R_UART2_SEND("EA,11,");
        }
        else if(PANIC_ALERT == ON && P3_bit.no0 == HIGH)
        {
            R_UART2_SEND("EA,10,");
        }
        else if(IGNITION_ON_PACKET == ON && IGNITION_ON_PACKET_SENT == OFF)
        {
            R_UART2_SEND("IN,07,");
            IGNITION_ON_PACKET_SENT = ON;
        }
        else if(IGNITION_OFF_PACKET == ON && IGNITION_OFF_PACKET_SENT == OFF)
        {
            R_UART2_SEND("IF,08,");
            IGNITION_OFF_PACKET_SENT = ON;
        }
        else if(NORMAL_PACKET == ON)
        {
            R_UART2_SEND("NR,01,");

            // if(IGNITION_ON_PACKET)
            // {
            //     R_UART2_SEND("07,");
            // }
            // else if(PANIC_ALERT)
            // {
            //     R_UART2_SEND("10,");
            // }
            // else
            // {
            //     R_UART2_SEND("01,");
            // }
        }

        NOP();
        R_UART2_SEND("L,");
        NOP();   // H- HISTORY , L-LIVE

/************************************************************************************************************************************************************/

        // Testing - IMEI NUMBER
        for(FOR_1 = 1; FOR_1 <= 15; FOR_1++)
        {
            R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);
            NOP();
            NOP();
        }

        R_UART2_SEND(",");
        NOP();

        // VEHICLE NUMBER
        for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
        {
            if(VEICHLE_NUMBER[FOR_1] != ' ' && VEICHLE_NUMBER[FOR_1] != '\0')
            {
                R_UART2_SEND_User(VEICHLE_NUMBER[FOR_1]);
                MS_TIMER(1);
            }
        }

        R_UART2_SEND(",");
        NOP();   // VEHICLE NUMBER

/************************************************************************************************************************************************************/

        R_UART2_SEND_User(Array_0[GPS_DIRECTION_DATA_VALID]);
        R_UART2_SEND(",");
        NOP();   // GPS VALID OR INVALID
    }

/************************************************************************************************************************************************************/

    for(FOR_1 = 0; FOR_1 <= 5; FOR_1++)
    {
        R_UART2_SEND_User(((TIME[FOR_1] & 0xF0) >> 4) + 0X30);
        R_UART2_SEND_User((TIME[FOR_1] & 0x0F) + 0X30);

        if(FOR_1 == 1)
        {
            R_UART2_SEND("20");
        }

        if(FOR_1 == 2 || FOR_1 == 5)
        {
            R_UART2_SEND(",");
        }
    }

    //RTC:- DDMMYYYY,HHMMSS,

    if(FORMAT == 1)
    {
        if(GPS_DIRECTION_DATA_VALID == ON)
        {
            R_UART2_SEND("A");
        }
        else
        {
            R_UART2_SEND("V");
        }
    }

/************************************************************************************************************************************************************/

    /* Testing R_UART2_SEND("12.582621,N,077.384200,E,");*/

    /* Testing */
    if(GPS_DIRECTION_DATA_VALID == ON)
    {
        for(FOR_1 = 0; FOR_1 <= 7; FOR_1++)
        {
            NOP();     //LATITUDE AND DIRECTION
            /* Testing */ R_UART2_SEND_User(LAT_DM[FOR_1]);

            if(FOR_1 == 1)
            {
                R_UART2_SEND(".");
            }
        }
    }
    else
    {
        R_UART2_SEND("00.000000");
    }

    /* Testing*/
    if(LAT_DIRECTION == 'N')
    {
        R_UART2_SEND(",N,");
    }
    else
    {
        R_UART2_SEND(",S,");
    }

/************************************************************************************************************************************************************/

    /* Testing*/
    if(GPS_DIRECTION_DATA_VALID == ON)
    {
        for(FOR_1 = 0; FOR_1 <= 7; FOR_1++)
        {
            NOP();     //LONGITUDE AND DIRECTION
            /* Testing*/ R_UART2_SEND_User(LOG_DM[FOR_1]);

            if(FOR_1 == 1)
            {
                R_UART2_SEND(".");
            }
        }
    }
    else
    {
        R_UART2_SEND("000.000000");
    }

    /* Testing*/
    if(LON_DIRECTION == 'E')
    {
        R_UART2_SEND(",E,");
    }
    else
    {
        R_UART2_SEND(",W,");
    }

    NOP();

/************************************************************************************************************************************************************/

    //R_UART2_SEND("25.2,");NOP();//310.56,4,183.5,PDOP,HDOP,		//SPEED
    //GET_SPEED_DATA();

    if(ADD_ZERO_TO_SPEED == SET)
    {
        R_UART2_SEND("0");
    }

    for(FOR_1 = 0; FOR_1 <= SPEED_DATA_LENGTH_COUNT; FOR_1++)
    {
        NOP();
        R_UART2_SEND_User(SPEED_DATA[FOR_1]);
    }

    DECIMAL_POINT_CAME_STOP_TX = OFF;

    NOP();
    R_UART2_SEND(",");
    NOP();

/************************************************************************************************************************************************************/

    COG_VALUE_COUNT = CLR;

    for(FOR_1 = 0; FOR_1 <= 5; FOR_1++)
    {
        NOP();

        if(COG[FOR_1] != '.')
        {
            COG_VALUE_COUNT++;
        }
        else if(COG[FOR_1] == '.')
        {
            break;
        }
    }

    if(COG_VALUE_COUNT == 1)
    {
        R_UART2_SEND("00");
        COG_VALUE_COUNT = 3;
        NOP();
    }
    else if(COG_VALUE_COUNT == 2)
    {
        R_UART2_SEND("0");
        COG_VALUE_COUNT = 4;
        NOP();
    }
    else
    {
        COG_VALUE_COUNT = 5;
    }

    DECIMAL_POINT = OFF;

    for(FOR_1 = 0; FOR_1 <= COG_VALUE_COUNT; FOR_1++)
    {
        NOP();

        if(COG[FOR_1] == '.' && DECIMAL_POINT == ON)
        {
            DECIMAL_POINT = OFF;
            COG[FOR_1] = '0';
        }
        else if(COG[FOR_1] == '.')
        {
            DECIMAL_POINT = ON;
        }

        R_UART2_SEND_User(COG[FOR_1]);
    }

    // HEADING :-COURSE OVER GROUND IN DEGREE
    R_UART2_SEND(",");
    NOP();

    R_UART2_SEND_User((NO_OF_SAT / 10) + 0x30);
    R_UART2_SEND_User((NO_OF_SAT % 10) + 0x30);
    R_UART2_SEND(",");
    NOP();      // NO OF SATELLITE

/************************************************************************************************************************************************************/

    ALTITUDE_VALUE_COUNT = CLR;

    for(FOR_1 = 0; FOR_1 <= 4; FOR_1++)
    {
        NOP();

        if(ALTITUDE[FOR_1] != '.')
        {
            ALTITUDE_VALUE_COUNT++;
        }
        else if(ALTITUDE[FOR_1] == '.')
        {
            break;
        }
    }

    if(ALTITUDE_VALUE_COUNT == 1)
    {
        R_UART2_SEND("00");
        ALTITUDE_VALUE_COUNT = 2;
        NOP();
    }
    else if(ALTITUDE_VALUE_COUNT == 2)
    {
        R_UART2_SEND("0");
        ALTITUDE_VALUE_COUNT = 3;
        NOP();
    }
    else
    {
        ALTITUDE_VALUE_COUNT = 4;
    }

    for(FOR_1 = 0; FOR_1 <= ALTITUDE_VALUE_COUNT; FOR_1++)
    {
        NOP();
        R_UART2_SEND_User(ALTITUDE[FOR_1]);
    }

    //R_UART2_SEND(",0.00,"); NOP();

    R_UART2_SEND(",");
    NOP();

    for(FOR_1 = 0; FOR_1 <= 4; FOR_1++)
    {
        NOP();

        if(PDOP_DATA_RX[FOR_1] == '1' || PDOP_DATA_RX[FOR_1] == '2' || PDOP_DATA_RX[FOR_1] == '3' || PDOP_DATA_RX[FOR_1] == '4' || PDOP_DATA_RX[FOR_1] == '5' || PDOP_DATA_RX[FOR_1] == '6' || PDOP_DATA_RX[FOR_1] == '7' || PDOP_DATA_RX[FOR_1] == '8' || PDOP_DATA_RX[FOR_1] == '9' || PDOP_DATA_RX[FOR_1] == '0' || PDOP_DATA_RX[FOR_1] == '.')
        {
            R_UART2_SEND_User(PDOP_DATA_RX[FOR_1]);
        }
        else
        {
            R_UART2_SEND("0");
        }
    }

    //}

    R_UART2_SEND(",");
    NOP();

/************************************************************************************************************************************************************/

    for(FOR_1 = 0; FOR_1 <= 4; FOR_1++)
    {
        NOP();

        if(HDOP[FOR_1] == '1' || HDOP[FOR_1] == '2' || HDOP[FOR_1] == '3' || HDOP[FOR_1] == '4' || HDOP[FOR_1] == '5' || HDOP[FOR_1] == '6' || HDOP[FOR_1] == '7' || HDOP[FOR_1] == '8' || HDOP[FOR_1] == '9' || HDOP[FOR_1] == '0' || HDOP[FOR_1] == '.')
        {
            R_UART2_SEND_User(HDOP[FOR_1]);
        }
        else
        {
            R_UART2_SEND("0");
        }
    }

    R_UART2_SEND(",");
    NOP();   //HDOP

/************************************************************************************************************************************************************/

    for(FOR_1 = 0; FOR_1 < 8 && NETWORK_NAME[FOR_1] != '\0'; FOR_1++)
    {
        NOP();
        R_UART2_SEND_User(NETWORK_NAME[FOR_1]);
    }

    R_UART2_SEND(",");
    NOP();   //NETWORK OPEATOR NAME

/************************************************************************************************************************************************************/

    NOP();
    R_UART2_SEND_User(Array_0[IGNITION]);
    NOP();
    R_UART2_SEND(",");
    NOP();   // IGNITION

/************************************************************************************************************************************************************/

    //if(MAIN_BATTERY_VOLTAGE<=40){MAIN_BAT_STATUS=OFF;TEMP_MAIN_BATTERY_VOLTAGE=0;R_UART2_SEND("0,");}else{MAIN_BAT_STATUS=ON;R_UART2_SEND("1,");}NOP();		// MAIN BATTERY STATUS

    if(MAIN_BAT_STATUS == OFF)
    {
        R_UART2_SEND("0,");
    }
    else
    {
        MAIN_BAT_STATUS = ON;
        R_UART2_SEND("1,");
    }

    NOP();     // MAIN BATTERY STATUS

    BATTERY_MEASUREMENT = ON;

    R_UART2_SEND_User(((MAIN_BATTERY_VOLTAGE / 100) + 0x30));

    VOLT = MAIN_BATTERY_VOLTAGE % 100;

    R_UART2_SEND_User(((VOLT / 10) + 0x30));
    NOP();
    R_UART2_SEND(".");

    R_UART2_SEND_User(((VOLT % 10) + 0x30));
    R_UART2_SEND(",");     //MAIN BATTERY VOLTAGE

/************************************************************************************************************************************************************/

    VOLT = BACKUP_BATTERY_VOLTAGE % 1000;

    if(VOLT >= 440)
    {
        VOLT = 440;
    }

    R_UART2_SEND_User(((VOLT / 100) + 0x30));

    VOLT = VOLT % 100;

    R_UART2_SEND(".");
    R_UART2_SEND_User(((VOLT / 10) + 0x30));        //R_UART2_SEND_User(((VOLT%10)+0x30));
    R_UART2_SEND(",");                              //BACKUP BATTERY VOLTAGE

    BATTERY_MEASUREMENT = OFF;

/************************************************************************************************************************************************************/

    R_UART2_SEND_User(Array_0[PANIC_ALERT]);
    NOP();
    R_UART2_SEND(",C,");     //PANIC ALERT & TAMPER ALERT 'C'

/************************************************************************************************************************************************************/

    R_UART2_SEND_User(Array_0[GSM_STRENGTH / 10]);
    NOP();

    R_UART2_SEND_User(Array_0[GSM_STRENGTH % 10]);
    NOP();     //GSM SIGNAL STRENGTH

/************************************************************************************************************************************************************/                          //PANIC ALERT & TAMPER ALERT 'C'

    R_UART2_SEND(",404,");

    HEX_CHARACTER_CONVERSION = SET;

    if(MNC_DATA_LENGTH == 0 || MNC[0] == 0x78)
    {
        R_UART2_SEND("00");
    }
    else
    {
        if(MNC_DATA_LENGTH >= 2)
        {
            MNC_DATA_LENGTH = 1;
        }

        for(FOR_1 = 0; FOR_1 <= MNC_DATA_LENGTH; FOR_1++)
        {
            NOP();
            R_UART2_SEND_User(MNC[FOR_1]);
        }
    }

    R_UART2_SEND(",");

    /* Serving Cell LAC - Print as 4-digit hex (currently zeros) */
    for(FOR_1 = 0; FOR_1 < 4; FOR_1++)
    {
        if(LAC[FOR_1] != '0' || FOR_1 >= 2)
        {
            R_UART2_SEND_User(LAC[FOR_1]);
        }
        else
        {
            R_UART2_SEND_User('0');
        }
    }

    R_UART2_SEND(",");

    /* Serving Cell ID - Print as 4-digit hex (currently zeros) */
    for(FOR_1 = 0; FOR_1 < 4; FOR_1++)
    {
        if(CELL_ID[FOR_1] != '0' || FOR_1 >= 2)
        {
            R_UART2_SEND_User(CELL_ID[FOR_1]);
        }
        else
        {
            R_UART2_SEND_User('0');
        }
    }

    R_UART2_SEND(",");

    /* Serving Cell Signal Strength (0-31 decimal) */
    if(SERVING_CELL_DBM >= 10)
    {
        R_UART2_SEND_User(Array_0[SERVING_CELL_DBM / 10]);
    }

    R_UART2_SEND_User(Array_0[SERVING_CELL_DBM % 10]);
    R_UART2_SEND(",");

    /* Neighbour Cells 1-4: (Cell ID, LAC, Signal) triplets */
    for(FOR_1 = 0; FOR_1 < 4; FOR_1++)
    {
        for(FOR_2 = 0; FOR_2 < 4; FOR_2++)
        {
            if(NCELL_CID[FOR_1][FOR_2] != '0' || FOR_2 >= 2)
            {
                R_UART2_SEND_User(NCELL_CID[FOR_1][FOR_2]);
            }
            else
            {
                R_UART2_SEND_User('0');
            }
        }

        R_UART2_SEND(",");

        for(FOR_2 = 0; FOR_2 < 4; FOR_2++)
        {
            if(NCELL_LAC[FOR_1][FOR_2] != '0' || FOR_2 >= 2)
            {
                R_UART2_SEND_User(NCELL_LAC[FOR_1][FOR_2]);
            }
            else
            {
                R_UART2_SEND_User('0');
            }
        }

        R_UART2_SEND(",");

        if(NCELL_DBM[FOR_1] >= 10)
        {
            R_UART2_SEND_User(Array_0[NCELL_DBM[FOR_1] / 10]);
        }

        R_UART2_SEND_User(Array_0[NCELL_DBM[FOR_1] % 10]);

        if(FOR_1 < 3)
        {
            R_UART2_SEND(",");
        }
    }

    HEX_CHARACTER_CONVERSION = CLR;

    R_UART2_SEND(",00");

    if(PANIC_ALERT_PACKET == ON)
    {
        R_UART2_SEND("1");
    }
    else
    {
        R_UART2_SEND("0");
    }

    if(IGNITION_SW == CLOSE)
    {
        R_UART2_SEND("1");
    }
    else
    {
        R_UART2_SEND("0");
    }

    R_UART2_SEND(",00,");
    NOP();

/************************************************************************************************************************************************************/

/************************************************************************************************************************************************************/

    FRAME_NUMBER++;

    if(FRAME_NUMBER >= 1000000)
    {
        FRAME_NUMBER = 1;
    }

    TEMP_FRAME_NUMBER = FRAME_NUMBER;

    R_UART2_SEND_User(((TEMP_FRAME_NUMBER / 100000) + 0x30));

    TEMP_FRAME_NUMBER = TEMP_FRAME_NUMBER % 100000;

    R_UART2_SEND_User(((TEMP_FRAME_NUMBER / 10000) + 0x30));

    TEMP_FRAME_NUMBER = TEMP_FRAME_NUMBER % 10000;

    R_UART2_SEND_User(((TEMP_FRAME_NUMBER / 1000) + 0x30));

    TEMP_FRAME_NUMBER = TEMP_FRAME_NUMBER % 1000;

    R_UART2_SEND_User(((TEMP_FRAME_NUMBER / 100) + 0x30));

    TEMP_FRAME_NUMBER = TEMP_FRAME_NUMBER % 100;

    R_UART2_SEND_User(((TEMP_FRAME_NUMBER / 10) + 0x30));
    R_UART2_SEND_User(((TEMP_FRAME_NUMBER % 10) + 0x30));

/************************************************************************************************************************************************************/

    /* Calculate XOR checksum of packet data */

    VOLT = 0;

    /* XOR MCC, MNC */
    FOR_1 = 0;

    while(FOR_1 < 3)
    {
        if(MCC_1[FOR_1] >= '0')
        {
            VOLT ^= MCC_1[FOR_1];
        }

        FOR_1++;
    }

    FOR_1 = 0;

    while(MCC_DATA_LENGTH >= FOR_1)
    {
        VOLT ^= MNC[FOR_1];
        FOR_1++;
    }

    /* XOR LAC, Cell ID */
    FOR_1 = 0;

    while(LAC_DATA_LENGTH_0 >= FOR_1)
    {
        VOLT ^= LAC[FOR_1];
        FOR_1++;
    }

    FOR_1 = 0;

    while(CELL_ID_DATA_LENGTH_0 >= FOR_1)
    {
        VOLT ^= CELL_ID[FOR_1];
        FOR_1++;
    }

    /* XOR Serving Cell Signal */
    VOLT ^= (SERVING_CELL_DBM + 0x30);

    /* XOR neighbor cells */
    FOR_1 = 0;

    while(FOR_1 < 4)
    {
        FOR_2 = 0;

        while(FOR_2 < 4)
        {
            if(NCELL_CID[FOR_1][FOR_2] != '0')
            {
                VOLT ^= NCELL_CID[FOR_1][FOR_2];
            }

            FOR_2++;
        }

        FOR_2 = 0;

        while(FOR_2 < 4)
        {
            if(NCELL_LAC[FOR_1][FOR_2] != '0')
            {
                VOLT ^= NCELL_LAC[FOR_1][FOR_2];
            }

            FOR_2++;
        }

        VOLT ^= (NCELL_DBM[FOR_1] + 0x30);

        FOR_1++;
    }

    /* Send checksum as 2-digit hex */
    R_UART2_SEND(",");

    R_UART2_SEND_User((VOLT / 16 < 10) ? (VOLT / 16 + 0x30) : (VOLT / 16 + 0x37));

    R_UART2_SEND_User(
        ((VOLT % 16) < 10) ?
        ((VOLT % 16) + 0x30) :
        ((VOLT % 16) + 0x37)
    );

    R_UART2_SEND("*");
    NOP();
    NOP();

/************************************************************************************************************************************************************/

    URL_PRINT = OFF;
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
#endif
void BUFFER_APPEND_CHAR(char c)
{
    if(DATA_BUFFER_INDEX < (DATA_BUFFER_SIZE - 1))   /* keep 1 byte reserved for null terminator */
    {
        DATA_BUFFER[DATA_BUFFER_INDEX] = c;
        DATA_BUFFER_INDEX++;
    }
}

void BUFFER_APPEND_STR(const char *s)
{
    while(*s != '\0')
    {
        BUFFER_APPEND_CHAR(*s);
        s++;
    }
}

void HEL_STRING(void)
{
    DATA_BUFFER_INDEX = 0;       /* Start a fresh HEL packet */
    URL_PRINT = ON;

    BUFFER_APPEND_STR("$HEL,VID,");

    NOP();

    // Firmware Version

    BUFFER_APPEND_CHAR((CURRENT_FRM_VERSION / 100) + 0x30);

    BUFFER_APPEND_STR(".");

    NOP();

    TEMP_FRM_VERSION = CURRENT_FRM_VERSION % 100;

    BUFFER_APPEND_CHAR((TEMP_FRM_VERSION / 10) + 0x30);

    BUFFER_APPEND_STR(".");

    NOP();

    BUFFER_APPEND_CHAR((TEMP_FRM_VERSION % 10) + 0x30);

    BUFFER_APPEND_STR(",");

    NOP();

    // IMEI NUMBER

    for(FOR_1 = 1; FOR_1 <= 15; FOR_1++)
    {
        BUFFER_APPEND_CHAR(IMEI_EEPROM[FOR_1]);

        NOP();

        NOP();
    }

    BUFFER_APPEND_STR(",");

    NOP();

    // Battery Percentage - Use BACKUP_BATTERY_VOLTAGE directly

    VOLT = BACKUP_BATTERY_VOLTAGE;

    if(VOLT > 100)
    {
        VOLT = 100;
    }

    BUFFER_APPEND_CHAR((VOLT / 100) + 0x30);

    BUFFER_APPEND_CHAR(((VOLT % 100) / 10) + 0x30);

    BUFFER_APPEND_CHAR((VOLT % 10) + 0x30);

    BUFFER_APPEND_STR(",");

    NOP();

    // Low Battery Threshold

    VOLT = LOW_BAT_LEVEL;

    if(VOLT > 100)
    {
        VOLT = 100;
    }

    BUFFER_APPEND_CHAR((VOLT / 100) + 0x30);

    BUFFER_APPEND_CHAR(((VOLT % 100) / 10) + 0x30);

    BUFFER_APPEND_CHAR((VOLT % 10) + 0x30);

    BUFFER_APPEND_STR(",");

    NOP();

    // Memory Percentage

    VOLT = (FLASH_MEMORY * 100) / 128;

    if(VOLT > 100)
    {
        VOLT = 100;
    }

    BUFFER_APPEND_CHAR((VOLT / 100) + 0x30);

    BUFFER_APPEND_CHAR(((VOLT % 100) / 10) + 0x30);

    BUFFER_APPEND_CHAR((VOLT % 10) + 0x30);

    BUFFER_APPEND_STR(",");

    NOP();

    // Update Rate Ignition ON

    VOLT = UPDATE_TIME_ON_TIME;

    BUFFER_APPEND_CHAR((VOLT / 100) + 0x30);

    BUFFER_APPEND_CHAR(((VOLT % 100) / 10) + 0x30);

    BUFFER_APPEND_CHAR((VOLT % 10) + 0x30);

    BUFFER_APPEND_STR(",");

    NOP();

    // Update Rate Ignition OFF

    VOLT = UPDATE_TIME_OFF_TIME;

    BUFFER_APPEND_CHAR((VOLT / 100) + 0x30);

    BUFFER_APPEND_CHAR(((VOLT % 100) / 10) + 0x30);

    BUFFER_APPEND_CHAR((VOLT % 10) + 0x30);

    BUFFER_APPEND_STR(",");

    NOP();

    // Digital I/O Status

    BUFFER_APPEND_STR("0001,");

    NOP();

    // Analog I/O Status

    BUFFER_APPEND_STR("00,");

    NOP();

    // End character

    BUFFER_APPEND_STR("*");

    NOP();

    DATA_BUFFER[DATA_BUFFER_INDEX] = '\0';    /* Null terminate HEL packet */

    URL_PRINT = OFF;
}

void DATA_PRINT(char FORMAT)
{
    DATA_BUFFER_INDEX = 0;   /* start a fresh packet in the buffer each call */
    URL_PRINT = ON;

    if(FORMAT == 0)
    {
        if(PANIC_ALERT == ON)
        {
            BUFFER_APPEND_STR("$PVT,LKSI,");
        }
        else
        {
            BUFFER_APPEND_STR("$PVT,LKSI,");
        }

/************************************************************************************************************************************************************/

        BUFFER_APPEND_CHAR(((CURRENT_FRM_VERSION / 100) + 0x30));
        BUFFER_APPEND_STR(".");
        NOP();

        TEMP_FRM_VERSION = CURRENT_FRM_VERSION % 100;

        BUFFER_APPEND_CHAR(((TEMP_FRM_VERSION / 10) + 0x30));
        BUFFER_APPEND_STR(".");
        NOP();

        BUFFER_APPEND_CHAR(((TEMP_FRM_VERSION % 10) + 0x30));

        BUFFER_APPEND_STR(",");
        NOP();

        VOLT = BACKUP_BATTERY_VOLTAGE % 1000;

/************************************************************************************************************************************************************/
        // START CHARACTER, HEADER, VENDOR ID, FIRMWARE VERSION

        if(POWER_SOURCE_PACKET == ON)
        {
            BUFFER_APPEND_STR("BD,03,");
        }
        else if(POWER_SOURCE_RECONNECT_PACKET == ON)
        {
            BUFFER_APPEND_STR("BR,06,");
        }
        else if(LOW_BATTERY_ALERT_PACKET == ON)
        {
            BUFFER_APPEND_STR("BL,04,");
        }
        else if(BATTERY_CHARGED_PACKET == ON)
        {
            BUFFER_APPEND_STR("BH,05,");
        }
        else if(OTA_PACKET == ON)
        {
            OTA_PACKET = OFF;
            BUFFER_APPEND_STR("PC,12,");
        }
        else if(HARSH_BRAKE_PACKET == ON)
        {
            HARSH_BRAKE_PACKET = OFF;
            BUFFER_APPEND_STR("HB,13,");
            R_INTC1_Start();
        }
        else if(HARSH_ACC_PACKET == ON)
        {
            HARSH_ACC_PACKET = OFF;
            BUFFER_APPEND_STR("HA,14,");
            R_INTC1_Start();
        }
        else if(HARSH_TURN_PACKET == ON)
        {
            HARSH_TURN_PACKET = OFF;
            BUFFER_APPEND_STR("RT,15,");
            R_INTC1_Start();
        }
        else if(PANIC_CONTROL_STATE_1 == ON)
        {
            PANIC_TIME_STOP = CLR;
            PANIC_TIME_START = CLR;
            PANIC_ALERT = 0;
            PANIC_ALERT_PACKET = OFF;
            PANIC_CONTROL_STATE_1 = OFF;
            HOOTER = ON;
            BUFFER_APPEND_STR("EA,11,");
        }
        else if(PANIC_ALERT == ON && P3_bit.no0 == HIGH)
        {
            BUFFER_APPEND_STR("EA,10,");
        }
        else if(IGNITION_ON_PACKET == ON && IGNITION_ON_PACKET_SENT == OFF)
        {
            BUFFER_APPEND_STR("IN,07,");
            IGNITION_ON_PACKET_SENT = ON;
        }
        else if(IGNITION_OFF_PACKET == ON && IGNITION_OFF_PACKET_SENT == OFF)
        {
            BUFFER_APPEND_STR("IF,08,");
            IGNITION_OFF_PACKET_SENT = ON;
        }
        else if(NORMAL_PACKET == ON)
        {
            BUFFER_APPEND_STR("NR,01,");
        }

        NOP();
        BUFFER_APPEND_STR("L,");
        NOP();   // H- HISTORY , L-LIVE

/************************************************************************************************************************************************************/

        // IMEI NUMBER
        for(FOR_1 = 1; FOR_1 <= 15; FOR_1++)
        {
            BUFFER_APPEND_CHAR(IMEI_EEPROM[FOR_1]);
            NOP();
            NOP();
        }

        BUFFER_APPEND_STR(",");
        NOP();

        // VEHICLE NUMBER
        for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
        {
            if(VEICHLE_NUMBER[FOR_1] != ' ' && VEICHLE_NUMBER[FOR_1] != '\0')
            {
                BUFFER_APPEND_CHAR(VEICHLE_NUMBER[FOR_1]);
                MS_TIMER(1);
            }
        }

        BUFFER_APPEND_STR(",");
        NOP();   // VEHICLE NUMBER

/************************************************************************************************************************************************************/

        BUFFER_APPEND_CHAR(Array_0[GPS_DIRECTION_DATA_VALID]);
        BUFFER_APPEND_STR(",");
        NOP();   // GPS VALID OR INVALID
    }

/************************************************************************************************************************************************************/

    for(FOR_1 = 0; FOR_1 <= 5; FOR_1++)
    {
        BUFFER_APPEND_CHAR(((TIME[FOR_1] & 0xF0) >> 4) + 0X30);
        BUFFER_APPEND_CHAR((TIME[FOR_1] & 0x0F) + 0X30);

        if(FOR_1 == 1)
        {
            BUFFER_APPEND_STR("20");
        }

        if(FOR_1 == 2 || FOR_1 == 5)
        {
            BUFFER_APPEND_STR(",");
        }
    }

    //RTC:- DDMMYYYY,HHMMSS,

    if(FORMAT == 1)
    {
        if(GPS_DIRECTION_DATA_VALID == ON)
        {
            BUFFER_APPEND_STR("A");
        }
        else
        {
            BUFFER_APPEND_STR("V");
        }
    }

/************************************************************************************************************************************************************/

    if(GPS_DIRECTION_DATA_VALID == ON)
    {
        for(FOR_1 = 0; FOR_1 <= 7; FOR_1++)
        {
            NOP();     //LATITUDE AND DIRECTION
            BUFFER_APPEND_CHAR(LAT_DM[FOR_1]);

            if(FOR_1 == 1)
            {
                BUFFER_APPEND_STR(".");
            }
        }
    }
    else
    {
        BUFFER_APPEND_STR("00.000000");
    }

    if(LAT_DIRECTION == 'N')
    {
        BUFFER_APPEND_STR(",N,");
    }
    else
    {
        BUFFER_APPEND_STR(",S,");
    }

/************************************************************************************************************************************************************/

    if(GPS_DIRECTION_DATA_VALID == ON)
    {
        for(FOR_1 = 0; FOR_1 <= 7; FOR_1++)
        {
            NOP();     //LONGITUDE AND DIRECTION
            BUFFER_APPEND_CHAR(LOG_DM[FOR_1]);

            if(FOR_1 == 1)
            {
                BUFFER_APPEND_STR(".");
            }
        }
    }
    else
    {
        BUFFER_APPEND_STR("00.0000000");
    }

    if(LON_DIRECTION == 'E')
    {
        BUFFER_APPEND_STR(",E,");
    }
    else
    {
        BUFFER_APPEND_STR(",W,");
    }

    NOP();

/************************************************************************************************************************************************************/

    if(ADD_ZERO_TO_SPEED == SET)
    {
        BUFFER_APPEND_STR("0");
    }

    for(FOR_1 = 0; FOR_1 <= SPEED_DATA_LENGTH_COUNT; FOR_1++)
    {
        NOP();
        BUFFER_APPEND_CHAR(SPEED_DATA[FOR_1]);
    }

    DECIMAL_POINT_CAME_STOP_TX = OFF;

    NOP();
    BUFFER_APPEND_STR(",");
    NOP();

/************************************************************************************************************************************************************/

    COG_VALUE_COUNT = CLR;

    for(FOR_1 = 0; FOR_1 <= 5; FOR_1++)
    {
        NOP();

        if(COG[FOR_1] != '.')
        {
            COG_VALUE_COUNT++;
        }
        else if(COG[FOR_1] == '.')
        {
            break;
        }
    }

    if(COG_VALUE_COUNT == 1)
    {
        BUFFER_APPEND_STR("00");
        COG_VALUE_COUNT = 3;
        NOP();
    }
    else if(COG_VALUE_COUNT == 2)
    {
        BUFFER_APPEND_STR("0");
        COG_VALUE_COUNT = 4;
        NOP();
    }
    else
    {
        COG_VALUE_COUNT = 5;
    }

    DECIMAL_POINT = OFF;

    for(FOR_1 = 0; FOR_1 <= COG_VALUE_COUNT; FOR_1++)
    {
        NOP();

        if(COG[FOR_1] == '.' && DECIMAL_POINT == ON)
        {
            DECIMAL_POINT = OFF;
            COG[FOR_1] = '0';
        }
        else if(COG[FOR_1] == '.')
        {
            DECIMAL_POINT = ON;
        }

        BUFFER_APPEND_CHAR(COG[FOR_1]);
    }

    // HEADING :-COURSE OVER GROUND IN DEGREE
    BUFFER_APPEND_STR(",");
    NOP();

    BUFFER_APPEND_CHAR((NO_OF_SAT / 10) + 0x30);
    BUFFER_APPEND_CHAR((NO_OF_SAT % 10) + 0x30);
    BUFFER_APPEND_STR(",");
    NOP();      // NO OF SATELLITE

/************************************************************************************************************************************************************/

    ALTITUDE_VALUE_COUNT = CLR;

    for(FOR_1 = 0; FOR_1 <= 4; FOR_1++)
    {
        NOP();

        if(ALTITUDE[FOR_1] != '.')
        {
            ALTITUDE_VALUE_COUNT++;
        }
        else if(ALTITUDE[FOR_1] == '.')
        {
            break;
        }
    }

    if(ALTITUDE_VALUE_COUNT == 1)
    {
        BUFFER_APPEND_STR("00");
        ALTITUDE_VALUE_COUNT = 2;
        NOP();
    }
    else if(ALTITUDE_VALUE_COUNT == 2)
    {
        BUFFER_APPEND_STR("0");
        ALTITUDE_VALUE_COUNT = 3;
        NOP();
    }
    else
    {
        ALTITUDE_VALUE_COUNT = 4;
    }

    for(FOR_1 = 0; FOR_1 <= ALTITUDE_VALUE_COUNT; FOR_1++)
    {
        NOP();
        BUFFER_APPEND_CHAR(ALTITUDE[FOR_1]);
    }

    BUFFER_APPEND_STR(",");
    NOP();

    for(FOR_1 = 0; FOR_1 <= 4; FOR_1++)
    {
        NOP();

        if(PDOP_DATA_RX[FOR_1] == '1' || PDOP_DATA_RX[FOR_1] == '2' || PDOP_DATA_RX[FOR_1] == '3' || PDOP_DATA_RX[FOR_1] == '4' || PDOP_DATA_RX[FOR_1] == '5' || PDOP_DATA_RX[FOR_1] == '6' || PDOP_DATA_RX[FOR_1] == '7' || PDOP_DATA_RX[FOR_1] == '8' || PDOP_DATA_RX[FOR_1] == '9' || PDOP_DATA_RX[FOR_1] == '0' || PDOP_DATA_RX[FOR_1] == '.')
        {
            BUFFER_APPEND_CHAR(PDOP_DATA_RX[FOR_1]);
        }
        else
        {
            BUFFER_APPEND_STR("0");
        }
    }

    BUFFER_APPEND_STR(",");
    NOP();

/************************************************************************************************************************************************************/

    for(FOR_1 = 0; FOR_1 <= 4; FOR_1++)
    {
        NOP();

        if(HDOP[FOR_1] == '1' || HDOP[FOR_1] == '2' || HDOP[FOR_1] == '3' || HDOP[FOR_1] == '4' || HDOP[FOR_1] == '5' || HDOP[FOR_1] == '6' || HDOP[FOR_1] == '7' || HDOP[FOR_1] == '8' || HDOP[FOR_1] == '9' || HDOP[FOR_1] == '0' || HDOP[FOR_1] == '.')
        {
            BUFFER_APPEND_CHAR(HDOP[FOR_1]);
        }
        else
        {
            BUFFER_APPEND_STR("0");
        }
    }

    BUFFER_APPEND_STR(",");
    NOP();   //HDOP

/************************************************************************************************************************************************************/

    for(FOR_1 = 0; FOR_1 < 8 && NETWORK_NAME[FOR_1] != '\0' && NETWORK_NAME[FOR_1] != ' ' && NETWORK_NAME[FOR_1] != '\n' && NETWORK_NAME[FOR_1] != '\r'; FOR_1++)
    {
        NOP();
        BUFFER_APPEND_CHAR(NETWORK_NAME[FOR_1]);
    }

    BUFFER_APPEND_STR(",");
    NOP();   //NETWORK OPEATOR NAME

/************************************************************************************************************************************************************/

    NOP();
    BUFFER_APPEND_CHAR(Array_0[IGNITION]);
    NOP();
    BUFFER_APPEND_STR(",");
    NOP();   // IGNITION

/************************************************************************************************************************************************************/

    if(MAIN_BAT_STATUS == OFF)
    {
        BUFFER_APPEND_STR("0,");
    }
    else
    {
        MAIN_BAT_STATUS = ON;
        BUFFER_APPEND_STR("1,");
    }

    NOP();     // MAIN BATTERY STATUS

    BATTERY_MEASUREMENT = ON;

    BUFFER_APPEND_CHAR(((MAIN_BATTERY_VOLTAGE / 100) + 0x30));

    VOLT = MAIN_BATTERY_VOLTAGE % 100;

    BUFFER_APPEND_CHAR(((VOLT / 10) + 0x30));
    NOP();
    BUFFER_APPEND_STR(".");

    BUFFER_APPEND_CHAR(((VOLT % 10) + 0x30));
    BUFFER_APPEND_STR(",");     //MAIN BATTERY VOLTAGE

/************************************************************************************************************************************************************/

    VOLT = BACKUP_BATTERY_VOLTAGE % 1000;

    if(VOLT >= 440)
    {
        VOLT = 440;
    }

    BUFFER_APPEND_CHAR(((VOLT / 100) + 0x30));

    VOLT = VOLT % 100;

    BUFFER_APPEND_STR(".");
    BUFFER_APPEND_CHAR(((VOLT / 10) + 0x30));
    BUFFER_APPEND_STR(",");                              //BACKUP BATTERY VOLTAGE

    BATTERY_MEASUREMENT = OFF;

/************************************************************************************************************************************************************/

    BUFFER_APPEND_CHAR(Array_0[PANIC_ALERT]);
    NOP();
    BUFFER_APPEND_STR(",C,");     //PANIC ALERT & TAMPER ALERT 'C'

/************************************************************************************************************************************************************/

    BUFFER_APPEND_CHAR(Array_0[GSM_STRENGTH / 10]);
    NOP();

    BUFFER_APPEND_CHAR(Array_0[GSM_STRENGTH % 10]);
    NOP();     //GSM SIGNAL STRENGTH

/************************************************************************************************************************************************************/

    BUFFER_APPEND_STR(",404,");

    HEX_CHARACTER_CONVERSION = SET;

    if(MNC_DATA_LENGTH == 0 || MNC[0] == 0x78)
    {
        BUFFER_APPEND_STR("00");
    }
    else
    {
        if(MNC_DATA_LENGTH >= 2)
        {
            MNC_DATA_LENGTH = 1;
        }

        for(FOR_1 = 0; FOR_1 <= MNC_DATA_LENGTH; FOR_1++)
        {
            NOP();
            BUFFER_APPEND_CHAR(MNC[FOR_1]);
        }
    }

    BUFFER_APPEND_STR(",");

    /* Serving Cell LAC */
    for(FOR_1 = 0; FOR_1 < 4; FOR_1++)
    {
        if(LAC[FOR_1] != '0' || FOR_1 >= 2)
        {
            BUFFER_APPEND_CHAR(LAC[FOR_1]);
        }
        else
        {
            BUFFER_APPEND_CHAR('0');
        }
    }

    BUFFER_APPEND_STR(",");

    /* Serving Cell ID */
    for(FOR_1 = 0; FOR_1 < 4; FOR_1++)
    {
        if(CELL_ID[FOR_1] != '0' || FOR_1 >= 2)
        {
            BUFFER_APPEND_CHAR(CELL_ID[FOR_1]);
        }
        else
        {
            BUFFER_APPEND_CHAR('0');
        }
    }

    BUFFER_APPEND_STR(",");

    /* Serving Cell Signal Strength (0-31 decimal) */
    if(SERVING_CELL_DBM >= 10)
    {
        BUFFER_APPEND_CHAR(Array_0[SERVING_CELL_DBM / 10]);
    }

    BUFFER_APPEND_CHAR(Array_0[SERVING_CELL_DBM % 10]);
    BUFFER_APPEND_STR(",");

    /* Neighbour Cells 1-4: (Cell ID, LAC, Signal) triplets */
    for(FOR_1 = 0; FOR_1 < 4; FOR_1++)
    {
        for(FOR_2 = 0; FOR_2 < 4; FOR_2++)
        {
            if(NCELL_CID[FOR_1][FOR_2] != '0' || FOR_2 >= 2)
            {
                BUFFER_APPEND_CHAR(NCELL_CID[FOR_1][FOR_2]);
            }
            else
            {
                BUFFER_APPEND_CHAR('0');
            }
        }

        BUFFER_APPEND_STR(",");

        for(FOR_2 = 0; FOR_2 < 4; FOR_2++)
        {
            if(NCELL_LAC[FOR_1][FOR_2] != '0' || FOR_2 >= 2)
            {
                BUFFER_APPEND_CHAR(NCELL_LAC[FOR_1][FOR_2]);
            }
            else
            {
                BUFFER_APPEND_CHAR('0');
            }
        }

        BUFFER_APPEND_STR(",");

        if(NCELL_DBM[FOR_1] >= 10)
        {
            BUFFER_APPEND_CHAR(Array_0[NCELL_DBM[FOR_1] / 10]);
        }

        BUFFER_APPEND_CHAR(Array_0[NCELL_DBM[FOR_1] % 10]);

        if(FOR_1 < 3)
        {
            BUFFER_APPEND_STR(",");
        }
    }

    HEX_CHARACTER_CONVERSION = CLR;

    BUFFER_APPEND_STR(",00");

    if(PANIC_ALERT_PACKET == ON)
    {
        BUFFER_APPEND_STR("1");
    }
    else
    {
        BUFFER_APPEND_STR("0");
    }

    if(IGNITION_SW == CLOSE)
    {
        BUFFER_APPEND_STR("1");
    }
    else
    {
        BUFFER_APPEND_STR("0");
    }

    BUFFER_APPEND_STR(",00,");
    NOP();

/************************************************************************************************************************************************************/

    FRAME_NUMBER++;

    if(FRAME_NUMBER >= 1000000)
    {
        FRAME_NUMBER = 1;
    }

    TEMP_FRAME_NUMBER = FRAME_NUMBER;

    BUFFER_APPEND_CHAR(((TEMP_FRAME_NUMBER / 100000) + 0x30));

    TEMP_FRAME_NUMBER = TEMP_FRAME_NUMBER % 100000;

    BUFFER_APPEND_CHAR(((TEMP_FRAME_NUMBER / 10000) + 0x30));

    TEMP_FRAME_NUMBER = TEMP_FRAME_NUMBER % 10000;

    BUFFER_APPEND_CHAR(((TEMP_FRAME_NUMBER / 1000) + 0x30));

    TEMP_FRAME_NUMBER = TEMP_FRAME_NUMBER % 1000;

    BUFFER_APPEND_CHAR(((TEMP_FRAME_NUMBER / 100) + 0x30));

    TEMP_FRAME_NUMBER = TEMP_FRAME_NUMBER % 100;

    BUFFER_APPEND_CHAR(((TEMP_FRAME_NUMBER / 10) + 0x30));
    BUFFER_APPEND_CHAR(((TEMP_FRAME_NUMBER % 10) + 0x30));

/************************************************************************************************************************************************************/

    /* Calculate XOR checksum of packet data — unchanged, pure computation, no UART calls */

    VOLT = 0;

    FOR_1 = 0;
    while(FOR_1 < 3)
    {
        if(MCC_1[FOR_1] >= '0')
        {
            VOLT ^= MCC_1[FOR_1];
        }
        FOR_1++;
    }

    FOR_1 = 0;
    while(MCC_DATA_LENGTH >= FOR_1)
    {
        VOLT ^= MNC[FOR_1];
        FOR_1++;
    }

    FOR_1 = 0;
    while(LAC_DATA_LENGTH_0 >= FOR_1)
    {
        VOLT ^= LAC[FOR_1];
        FOR_1++;
    }

    FOR_1 = 0;
    while(CELL_ID_DATA_LENGTH_0 >= FOR_1)
    {
        VOLT ^= CELL_ID[FOR_1];
        FOR_1++;
    }

    VOLT ^= (SERVING_CELL_DBM + 0x30);

    FOR_1 = 0;
    while(FOR_1 < 4)
    {
        FOR_2 = 0;
        while(FOR_2 < 4)
        {
            if(NCELL_CID[FOR_1][FOR_2] != '0')
            {
                VOLT ^= NCELL_CID[FOR_1][FOR_2];
            }
            FOR_2++;
        }

        FOR_2 = 0;
        while(FOR_2 < 4)
        {
            if(NCELL_LAC[FOR_1][FOR_2] != '0')
            {
                VOLT ^= NCELL_LAC[FOR_1][FOR_2];
            }
            FOR_2++;
        }

        VOLT ^= (NCELL_DBM[FOR_1] + 0x30);

        FOR_1++;
    }

    /* Send checksum as 2-digit hex */
    BUFFER_APPEND_STR(",");

    BUFFER_APPEND_CHAR((VOLT / 16 < 10) ? (VOLT / 16 + 0x30) : (VOLT / 16 + 0x37));

    BUFFER_APPEND_CHAR(
        ((VOLT % 16) < 10) ?
        ((VOLT % 16) + 0x30) :
        ((VOLT % 16) + 0x37)
    );

    BUFFER_APPEND_STR("*");
    NOP();
    NOP();

/************************************************************************************************************************************************************/

    DATA_BUFFER[DATA_BUFFER_INDEX] = '\0';   /* null-terminate the completed packet */

    URL_PRINT = OFF;
}

void UPDATE_ONLINE_DATA_FRAME(void)
{
    unsigned char current_profile;

    if (REFRESH == ON)
    {
        REFRESH = OFF;
        BLUE_LED = ON;
        GPRS_PS_EN = OFF1;
        MS_TIMER(200);
        GPRS_PS_EN = ON1;
        MS_TIMER(500);
        //MS_TIMER(500);
        BLUE_LED = OFF;
        //MS_TIMER(1000);
    }

restart000:
    if (INTERNET_CONNECTED == OFF)
    {
        NW_REGN_COUNT = 0;

        /************************************************************************************************************************************************************/
restart_CMEE:

        R_UART2_SEND("AT+CMEE?\r\n");
        ACK_RX(20, 2, 10, 1);

        if (RESTART == ON)
        {
            RESTART = OFF;
            goto restart_CMEE;
        }

        R_UART2_SEND("AT+QSPN?\r\n");
        // Removed: MS_TIMER(300); - unsolicited response, no delay needed

        /************************************************************************************************************************************************************/
restart_CPIN:

        CPIN = OFF;
        CPIN_READY_CHECK = ON;

        R_UART2_SEND("AT+CPIN?\r\n");
        ACK_RX(100, 6, 1, 0);

        if (NW_REGN_COUNT > 5)
        {
            RESTART = OFF;
            NETWORK_FAILURE++;

            if (NETWORK_FAILURE >= 2)
            {
                NETWORK_FAILURE = 0;
                INTERNET_CONNECTED = NONE;
                /* Close TCP on network failure */
                R_UART2_SEND("AT+QICLOSE\r\n");
                MS_TIMER(100);// changed to 100 from 500
                TCP_CONNECTION_OPEN = OFF;
                goto restart09;
            }

            BLUE_LED = ON;
            GPRS_PS_EN = OFF1;
            MS_TIMER(100);
            GPRS_PS_EN = ON1;
            MS_TIMER(500);
            //MS_TIMER(500);
            BLUE_LED = OFF;
            MS_TIMER(300);
            NW_REGN_COUNT = 0;
            goto restart000;
        }
        else if (RESTART == ON)
        {
            RESTART = OFF;
            NW_REGN_COUNT++;
            goto restart_CPIN;
        }

        CPIN_READY_CHECK = OFF;

        /************************************************************************************************************************************************************/
restart00:

        GSM_NW_REG_CHECK = SET;

        R_UART2_SEND("AT+CREG?\r\n");
        ACK_RX(100, 0, 100, 100);

        if (NW_REGN_COUNT > 10)
        {
            RESTART = OFF;
            NETWORK_FAILURE++;

            if (NETWORK_FAILURE >= 2)
            {
                NETWORK_FAILURE = 0;
                INTERNET_CONNECTED = NONE;
                /* Close TCP on network failure */
                R_UART2_SEND("AT+QICLOSE\r\n");
                MS_TIMER(10);
                TCP_CONNECTION_OPEN = OFF;
                goto restart09;
            }

            BLUE_LED = ON;
            GPRS_PS_EN = OFF1;
            MS_TIMER(200);
            GPRS_PS_EN = ON1;
            MS_TIMER(500);  // Reduced from 5000ms - faster error recovery
            MS_TIMER(500);
            BLUE_LED = OFF;
            MS_TIMER(500);
            NW_REGN_COUNT = 0;
            goto restart000;
        }
        else if (RESTART == ON)
        {
            RESTART = OFF;
            NW_REGN_COUNT++;
            goto restart00;
        }

        GSM_NW_REG_CHECK = CLR;

        MS_TIMER(50);  // Reduced from 300ms - ACK_RX already waited

        /************************************************************************************************************************************************************/
restart01:

        GPRS_REG_CHECK = SET;

        R_UART2_SEND("AT+CGREG?\r\n");
        ACK_RX(100, 1, 100, 100);
        // Removed: MS_TIMER(300); - redundant, ACK_RX already waited

        R_UART2_SEND("AT+QSSLSTATE?\r\n");
        // Removed: MS_TIMER(300); - unsolicited response, no delay needed

        if (NW_REGN_COUNT > 10)
        {
            RESTART = OFF;
            NETWORK_FAILURE++;

            if (NETWORK_FAILURE >= 2)
            {
                NETWORK_FAILURE = 0;
                INTERNET_CONNECTED = NONE;
                /* Close TCP on network failure */
                R_UART2_SEND("AT+QICLOSE\r\n");
                MS_TIMER(100);
                TCP_CONNECTION_OPEN = OFF;
                goto restart09;
            }

            BLUE_LED = ON;
            GPRS_PS_EN = OFF1;
            MS_TIMER(100);
            GPRS_PS_EN = ON1;
            MS_TIMER(500);  // Reduced from 5000ms - faster error recovery
            MS_TIMER(500);
            BLUE_LED = OFF;
            MS_TIMER(1000);
            NW_REGN_COUNT = 0;
            goto restart000;
        }
        else if (RESTART == ON)
        {
            RESTART = OFF;
            NW_REGN_COUNT++;
            goto restart01;
        }

        NW_REGN_COUNT = 0;
        NETWORK_FAILURE = 0;
        GPRS_REG_CHECK = CLR;

        /************************************************************************************************************************************************************/

        GET_NETWORK_NAME();

        if (BSNL_CONNECT_FLAG == 1)
        {
            BSNL_CONNECT_FLAG = 0;
            /* Close TCP before network restart */
            R_UART2_SEND("AT+QICLOSE\r\n");
            MS_TIMER(200);
            TCP_CONNECTION_OPEN = OFF;
            goto restart000;
        }

        if (DISCONNECT == ON)
        {
            DISCONNECT = OFF;
            /* Close TCP connection on manual disconnect */
            R_UART2_SEND("AT+QICLOSE\r\n");
            MS_TIMER(200);
            TCP_CONNECTION_OPEN = OFF;
            GPRS_DISCONNECT();
        }

restart4:

        if (GPRS_REG_COUNT >= 10)
        {
            GPRS_REG_COUNT = 0;
            INTERNET_CONNECTED = NONE;
            goto restart09;
        }

        R_UART2_SEND("AT+QIFGCNT=0\r\n");
        ACK_RX(100, 2, 10, 1);

        if (RESTART == ON)
        {
            RESTART = OFF;
            GPRS_REG_COUNT++;
            goto restart4;
        }

        /************************************************************************************************************************************************************/

        // Read current profile from EEPROM offset 60
        current_profile = i2c_readn(0xA0, 0XFE, 60);
        if(apn_is_default)
        {
            MS_TIMER(2);

        #ifdef SIMMAKE_IDEMIA_3P

            if(current_profile == 0x31)  // Vodafone
            {
                R_UART2_SEND("AT+QICSGP=1,\"sensem2m\"\r\n");
            }
            else if(current_profile == 0x32)  // BSNL
            {
                R_UART2_SEND("AT+QICSGP=1,\"bsnlnet\"\r\n");
            }
            else if(current_profile == 0x33)  // Airtel
            {
                R_UART2_SEND("AT+QICSGP=1,\"airtelgprs.com\"\r\n");
            }
            else
            {
                R_UART2_SEND("AT+QICSGP=1,\"sensem2m\"\r\n");
            }

        #elif defined(SIMMAKE_GND)

            if(current_profile == 0x31)  // BSNL
            {
                R_UART2_SEND("AT+QICSGP=1,\"bsnlnet\"\r\n");
            }
            else if(current_profile == 0x32)  // AIRTEL
            {
                R_UART2_SEND("AT+QICSGP=1,\"navspireiot.m2m\"\r\n");
            }
            else if(current_profile == 0x33)  // VI
            {
                R_UART2_SEND("AT+QICSGP=1,\"navspireiot.com\"\r\n");
            }
            else
            {
                INTERNET_CONNECTED = NONE;
                goto restart09;
            }

        #endif
        }
        else
        {
            R_UART2_SEND("AT+QICSGP=1,\"");
            R_UART2_SEND(TEMP_APN2);
            R_UART2_SEND("\"\r\n");
        }

        ACK_RX(100, 2, 10, 10);

        if (RESTART == ON)
        {
            RESTART = OFF;
            GPRS_REG_COUNT++;
            goto restart4;
        }

        ACK = 0;
        ERROR_OCCURED = 0;

        /************************************************************************************************************************************************************/

        /* Set multiplex mode ONLY ONCE at boot (not on reconnection retries) */
        if (QIMUX_SET == OFF)
        {
            R_UART2_SEND("AT+QIMUX=1\r\n");
            ACK_RX(100, 2, 100, 200);
            QIMUX_SET = ON;  /* Mark QIMUX as set - don't call again */
        }

        if (RESTART == ON)
        {
            RESTART = OFF;
            GPRS_REG_COUNT++;
            goto restart4;
        }

        INTERNET_CONNECTED = ON;
        NW_REGN_COUNT = 0;

        R_UART2_SEND("AT+QIREGAPP\r\n");
        ACK_RX(100, 2, 100, 200);

        if (RESTART == ON)
        {
            RESTART = OFF;
            GPRS_REG_COUNT++;
            goto restart4;
        }

        /************************************************************************************************************************************************************/

        R_UART2_SEND("AT+CGATT=1\r\n");
        ACK_RX(100, 2, 100, 200);
        //MS_TIMER(2000);  // Wait 2 seconds for GPRS attachment to complete

        if (RESTART == ON)
        {
            GPRS_REG_COUNT++;
            RESTART = OFF;
            goto restart4;
        }

        R_UART2_SEND("AT+QIACT\r\n");
        ACK_RX(100, 2, 100, 200);

        if (RESTART == ON)
        {
            GPRS_REG_COUNT++;
            RESTART = OFF;
            goto restart4;
        }

        R_UART2_SEND("AT+QIDNSIP=1\r\n");
        ACK_RX(100, 2, 100, 200);

        /************************************************************************************************************************************************************/

        R_UART2_SEND("AT+CGPADDR=1\r\n");
        MS_TIMER(100);  // Reduced from 1000ms - modem responds in <500ms

        // Set GPRS_REG flag to indicate GPRS is active
        GPRS_REG = ON;
        
        INTERNET_CONNECTED = ON;
        NW_REGN_COUNT = 0;

        GET_NETWORK_NAME();

        if (BSNL_CONNECT_FLAG == 1)
        {
            BSNL_CONNECT_FLAG = 0;
            goto restart000;
        }
    }

    /************************************************************************************************************************************************************/
    /* Normal tracking data send via TCP */
    /************************************************************************************************************************************************************/
    if (FIRMWARE_UPDATE == OFF)
    {
restart_tracking:

        if (HTTP_CONNECT_COUNT >= 7)
        {
            HTTP_CONNECT_COUNT = 0;
            goto restart00;
        }

        /* Health packet trigger moved to V_Control.c */
        /* (Triggered every 5 minutes via 30-cycle counter in ignition ON mode) */

        /* TCP Connection Pooling - Only open if not already connected */
        if (TCP_CONNECTION_OPEN == OFF)
        {
            /* Connection 0 → Server 1 */
            DATA_BUFFER_INDEX = 0;
            BUFFER_APPEND_STR("AT+QIOPEN=0,\"TCP\",\"");
            BUFFER_APPEND_STR(TEMP_PIP);
            BUFFER_APPEND_STR("\",\"");
            BUFFER_APPEND_STR(TEMP_PPN);
            BUFFER_APPEND_STR("\"\r\n");
            BUFFER_APPEND_CHAR('\0');
            R_UART2_SEND(DATA_BUFFER);
            ACK_RX(100, 3, 100, 10);

            /* Connection 1 → Server 3 */
            DATA_BUFFER_INDEX = 0;
            BUFFER_APPEND_STR("AT+QIOPEN=1,\"TCP\",\"");
            BUFFER_APPEND_STR(TEMP_SIP);
            BUFFER_APPEND_STR("\",\"");
            BUFFER_APPEND_STR(TEMP_SPN);
            BUFFER_APPEND_STR("\"\r\n");
            BUFFER_APPEND_CHAR('\0');
            R_UART2_SEND(DATA_BUFFER);
            ACK_RX(100, 3, 100, 10);

            /* Connection 2 → Server 4 */
            DATA_BUFFER_INDEX = 0;
            BUFFER_APPEND_STR("AT+QIOPEN=2,\"TCP\",\"");
            BUFFER_APPEND_STR(TEMP_SIP2);
            BUFFER_APPEND_STR("\",\"");
            BUFFER_APPEND_STR(TEMP_SPN2);
            BUFFER_APPEND_STR("\"\r\n");
            BUFFER_APPEND_CHAR('\0');
            R_UART2_SEND(DATA_BUFFER);
            ACK_RX(100, 3, 100, 10);

            if (DISCONNECT == ON)
            {
                goto restart000;
            }
            else if (RESTART == ON)
            {
                HTTP_CONNECT_COUNT++;
                RESTART = OFF;
                goto restart_tracking;
            }
            /* Connection successful - mark as open */
            TCP_CONNECTION_OPEN = ON;
            /* Send LGN packet only once per boot (on first successful TCP connection) */
            /* Send LGN packet only once per boot (on first successful TCP connection) */
            if (WELCOME_STRING_FRAME_BOOT == OFF)
            {
                /* Send to Connection 0 (Server 1) */
                R_UART2_SEND("AT+QISEND=0\r\n");
                ACK_RX(10, 2, 100, 10);  
                WELCOME_STRING();
                R_UART2_SEND(DATA_BUFFER);
                R_UART2_SEND_User(CTRL_Z);
                MS_TIMER(100);
                /* Send to Connection 1 (Server 3) */
                R_UART2_SEND("AT+QISEND=1\r\n");
                ACK_RX(10, 2, 100, 10);
                //WELCOME_STRING();
                R_UART2_SEND(DATA_BUFFER);
                R_UART2_SEND_User(CTRL_Z);
                MS_TIMER(100);
                /* Send to Connection 2 (Server 4) */
                R_UART2_SEND("AT+QISEND=2\r\n");
                ACK_RX(10, 2, 100, 10);
                //WELCOME_STRING();
                R_UART2_SEND(DATA_BUFFER);
                R_UART2_SEND_User(CTRL_Z);
                MS_TIMER(100);
                WELCOME_STRING_FRAME_BOOT = ON;  /* Mark LGN as sent after boot */
            }
        }

        ACK = 0;

        /* Collect fresh data before sending (AT commands must run before AT+QISEND) */
        if(PANIC_ALERT == 0) 
        {
            GET_SIGNAL_STRENGTH();
        }

        if(INTERNET_CONNECTED==ON &&  PANIC_ALERT==0) 
        { 
            GET_MCC_MNC_LAC_CELL_ID(); 
        }
        
        GET_TIME();
        GET_SPEED_DATA();
        // GET_DEGREES();   /* REMOVED: LAT_DM/LOG_DM already set correctly by LATITUDE_CONVERSION()/LONGITUDE_CONVERSION() in GET_GPS_DATA() */
        #if 0
        /* Send tracking data to Connection 0 (Server 1) */
        R_UART2_SEND("AT+QISEND=0\r\n");
        ACK_RX(10, 2, 100, 10);  
        NORMAL_PACKET=ON;

        /* Send the actual tracking data frame */
        DATA_PRINT(0);
        R_UART2_SEND_User(CTRL_Z);
        MS_TIMER(100);

        /* Send tracking data to Connection 1 (Server 3) */
        R_UART2_SEND("AT+QISEND=1\r\n");
        ACK_RX(10, 2, 100, 10);    

        /* Send the actual tracking data frame */
        DATA_PRINT(0);
        R_UART2_SEND_User(CTRL_Z);
        MS_TIMER(100);
        #endif
        NORMAL_PACKET = ON;

        /* Build packet ONCE */
        DATA_PRINT(0);
        /* =================CON 0 -  SERVER 1 ================= */
        R_UART2_SEND("AT+QISEND=0\r\n");
        ACK_RX(10, 2, 100, 10);
        R_UART2_SEND(DATA_BUFFER);
        R_UART2_SEND_User(CTRL_Z);
        MS_TIMER(100);
        /* =================CON 1 - SERVER 3 ================= */
        R_UART2_SEND("AT+QISEND=1\r\n");
        ACK_RX(10, 2, 100, 10);
        R_UART2_SEND(DATA_BUFFER);
        R_UART2_SEND_User(CTRL_Z);
        MS_TIMER(100);
        /* =================CON 2 - SERVER 4 ================= */
        R_UART2_SEND("AT+QISEND=2\r\n");
        ACK_RX(10, 2, 100, 10);
        R_UART2_SEND(DATA_BUFFER);
        R_UART2_SEND_User(CTRL_Z);
        MS_TIMER(100);

        /* Send HEL packet if health check requested (every 5 minutes) */
        if(HEALTH_PACKET_TO_SERVER == ON) 
        {
            /* Send to Connection 0 (Server 1) */
            R_UART2_SEND("AT+QISEND=0\r\n");
            ACK_RX(10, 2, 100, 10);  
            HEL_STRING();
            R_UART2_SEND(DATA_BUFFER);
            R_UART2_SEND_User(CTRL_Z);
            MS_TIMER(100);  
            /* Send to Connection 1 (Server 3) */
            R_UART2_SEND("AT+QISEND=1\r\n");
            ACK_RX(10, 2, 100, 10);
            R_UART2_SEND(DATA_BUFFER);
            R_UART2_SEND_User(CTRL_Z);
            MS_TIMER(100);
            /* Send to Connection 2 (Server 4) */
            R_UART2_SEND("AT+QISEND=2\r\n");
            ACK_RX(10, 2, 100, 10);
            R_UART2_SEND(DATA_BUFFER);
            R_UART2_SEND_User(CTRL_Z);
            MS_TIMER(100);
            HEALTH_PACKET_TO_SERVER = OFF;
        }

        ACK = 0;
        ERROR_OCCURED = 0;

        /************************************************************************************************************************************************************/
        /* TCP Connection Pooling - Keep connection open for next packet */
        /* Connection will be closed only on network failure or disconnect */

        HTTP_CONNECT_COUNT = 0;
        
        /* ✅ FIX STKTR DELAY: Exit after successful TCP packet send */
        /* Prevent restart09 from executing SwitchNetwork() on every normal packet */
        return;
    }

    if (FIRMWARE_UPDATE == ON)
    {
restart_tcp:

        if (HTTP_CONNECT_COUNT >= 7)
        {
            HTTP_CONNECT_COUNT = 0;
            goto restart00;
        }

        /* Firmware update uses dedicated TCP connection - close any existing connection */
        R_UART2_SEND("AT+QICLOSE\r\n");
        MS_TIMER(500);
        TCP_CONNECTION_OPEN = OFF;

        /************************************************************************************************************************************************************/

        /* Open TCP connection to custom server 78.46.190.117 port 50022 */
        //R_UART2_SEND("AT+QIOPEN=2,\"TCP\",\"13.234.160.106\",\"8224\"\r\n");
        //ACK_RX(100, 3, 100, 10);

        if (DISCONNECT == ON)
        {
            goto restart000;
        }
        else if (RESTART == ON)
        {
            HTTP_CONNECT_COUNT++;
            RESTART = OFF;
            goto restart_tcp;
        }

        ACK = 0;

        /************************************************************************************************************************************************************/

        /* Send firmware request data to the TCP server */
        R_UART2_SEND("AT+QISEND\r\n");
        ACK_RX(10, 2, 100, 10);    /* Wait for '>' prompt */

        if (RESTART == ON)
        {
            HTTP_CONNECT_COUNT++;
            RESTART = OFF;
            goto restart_tcp;
        }

        /* Send the actual request payload to the server */
        R_UART2_SEND("FIRMWARE_REQUEST\x1A");  /* 0x1A = Ctrl+Z to end send */
        ACK_RX(100, 2, 100, 200);

        if (RESTART == ON)
        {
            HTTP_CONNECT_COUNT++;
            RESTART = OFF;
            goto restart_tcp;
        }

        ACK = 0;
        ERROR_OCCURED = 0;

        /************************************************************************************************************************************************************/

        /* Wait to receive firmware data from server */
        ACK_RX(600, 8, 50, 5);

        if (DISCONNECT == ON)
        {
            goto restart000;
        }
        else if (RESTART == ON)
        {
            HTTP_CONNECT_COUNT++;
            RESTART = OFF;
            goto restart_tcp;
        }

        /************************************************************************************************************************************************************/

        /* Close TCP connection after data received */
        R_UART2_SEND("AT+QICLOSE\r\n");
        MS_TIMER(500);
        TCP_CONNECTION_OPEN = OFF;

        FIRMWARE_DOWNLOADED = ON;
        FIRMWARE_DOWNLOAD_FROM_M95();
        MS_TIMER(5);
    }

    /************************************************************************************************************************************************************/
restart09:

    if (INTERNET_CONNECTED == NONE)
    {
        INTERNET_CONNECTED = OFF;
        NW_REGN_COUNT = 0;
        NETWORK_FAILURE = 0;
        RESTART = OFF;
        MS_TIMER(1);
        WATCH_DOG_KILL = OFF;
        //DATA_TO_ARRAY();
        //FLASH_WRITE();
        BLUE_LED = ON;
        GPRS_PS_EN = OFF1;
        MS_TIMER(200);
        GPRS_PS_EN = ON1;
        MS_TIMER(500);
        BLUE_LED = OFF;
        MS_TIMER(500);
        //SwitchNetwork(); // COMMENTED THIS USELESS CALL AND DEFINITION
        // ADDED THIS 
        // Calculate next profile: 0x01→0x02, 0x02→0x03, 0x03→0x01 (cycling)
        current_profile = i2c_readn(0xA0, 0xFE, 60);
        MS_TIMER(50);
        if (current_profile == 0x31)  // '1'
        {
            TEMP_PROF = 0x32;  // Set to '2'
        } 
        else if (current_profile == 0x32)  // '2'
        {
            TEMP_PROF = 0x33;  // Set to '3'
        } 
        else if (current_profile == 0x33)  // '3'
        {
            TEMP_PROF = 0x31;  // Set to '1'
        } 
        else
        {  
            TEMP_PROF = 0x33;  // Default to '3'
        }

        // Write new profile back to EEPROM offset 60
        i2c_writen(0xA0, 0xFE, 60, TEMP_PROF);
        MS_TIMER(50);
    }
}

#if 0
void HEL_STRING(void)
{
    R_UART2_SEND("$HEL,VID,");

    NOP();

    // Firmware Version

    R_UART2_SEND_User(((CURRENT_FRM_VERSION/100) + 0x30));

    R_UART2_SEND(".");

    NOP();

    TEMP_FRM_VERSION = CURRENT_FRM_VERSION % 100;

    R_UART2_SEND_User(((TEMP_FRM_VERSION/10) + 0x30));

    R_UART2_SEND(".");

    NOP();

    R_UART2_SEND_User(((TEMP_FRM_VERSION%10) + 0x30));

    R_UART2_SEND(",");

    NOP();

    // IMEI NUMBER

    for(FOR_1=1; FOR_1<=15; FOR_1++)
    {
        R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);

        NOP();

        NOP();
    }

    R_UART2_SEND(",");

    NOP();

    // Battery Percentage - Use BACKUP_BATTERY_VOLTAGE directly

    VOLT = BACKUP_BATTERY_VOLTAGE;

    if(VOLT > 100)
    {
        VOLT = 100;
    }

    R_UART2_SEND_User((VOLT/100) + 0x30);

    R_UART2_SEND_User(((VOLT%100)/10) + 0x30);

    R_UART2_SEND_User((VOLT%10) + 0x30);

    R_UART2_SEND(",");

    NOP();

    // Low Battery Threshold

    VOLT = LOW_BAT_LEVEL;

    if(VOLT > 100)
    {
        VOLT = 100;
    }

    R_UART2_SEND_User((VOLT/100) + 0x30);

    R_UART2_SEND_User(((VOLT%100)/10) + 0x30);

    R_UART2_SEND_User((VOLT%10) + 0x30);

    R_UART2_SEND(",");

    NOP();

    // Memory Percentage (assuming 128KB flash, adjust if different)

    VOLT = (FLASH_MEMORY * 100) / 128;

    if(VOLT > 100)
    {
        VOLT = 100;
    }

    R_UART2_SEND_User((VOLT/100) + 0x30);

    R_UART2_SEND_User(((VOLT%100)/10) + 0x30);

    R_UART2_SEND_User((VOLT%10) + 0x30);

    R_UART2_SEND(",");

    NOP();

    // Update Rate Ignition ON

    VOLT = UPDATE_TIME_ON_TIME;

    R_UART2_SEND_User((VOLT/100) + 0x30);

    R_UART2_SEND_User(((VOLT%100)/10) + 0x30);

    R_UART2_SEND_User((VOLT%10) + 0x30);

    R_UART2_SEND(",");

    NOP();

    // Update Rate Ignition OFF

    VOLT = UPDATE_TIME_OFF_TIME;

    R_UART2_SEND_User((VOLT/100) + 0x30);

    R_UART2_SEND_User(((VOLT%100)/10) + 0x30);

    R_UART2_SEND_User((VOLT%10) + 0x30);

    R_UART2_SEND(",");

    NOP();

    // Digital I/O Status

    R_UART2_SEND("0001,");

    NOP();

    // Analog I/O Status

    R_UART2_SEND("00,");

    NOP();

    // End character

    R_UART2_SEND("*");

    NOP();
}
#endif

// void DATA_TO_ARRAY(void)
// {
//     GET_TIME();
//     GET_SPEED_DATA();
//     GET_SIGNAL_STRENGTH();
//     GET_MCC_MNC_LAC_CELL_ID();
//     //if(IGNITION_SW==OPEN && T_SPEED>=5 || IGNITION_SW==OPEN && P_LAT_DM_RX!=LAT_DM[3]){GET_DEGREES();}
//     //else if(IGNITION_SW==CLOSE){GET_DEGREES();}
//     GET_DEGREES();
// /************************************************************************************************************************************************************/
//     //START CHARACTER , HEADER , VENDOR ID, FIRMWARE VERSION
//            if(PANIC_ALERT_PACKET==ON){SEND_TO_ARRAY("EA,02,");}
//       else if(IGNITION_ON_PACKET==ON){SEND_TO_ARRAY("IN,05,");}
//       else if(IGNITION_OFF_PACKET==ON){SEND_TO_ARRAY("IF,06,");}
//       else if(POWER_SOURCE_PACKET==ON){SEND_TO_ARRAY("BD,07,");}
//       else if(POWER_SOURCE_RECONNECT_PACKET==ON){SEND_TO_ARRAY("BR,08,");}
//       else if(LOW_BATTERY_ALERT_PACKET==ON){SEND_TO_ARRAY("BL,09,");}
//       else{SEND_TO_ARRAY("NR,02,");}                         //NR-NORMAL , EA-EMERGENCY ALERT

// /************************************************************************************************************************************************************/

//     SEND_TO_ARRAY_Value(Array_0[GPS_DIRECTION_DATA_VALID]);

//     SEND_TO_ARRAY(",");

//     NOP();                                                   //GPS VALID OR INVALID

// /************************************************************************************************************************************************************/

//     for(FOR_1=0; FOR_1<=5; FOR_1++)
//     {
//         SEND_TO_ARRAY_Value(((TIME[FOR_1] & 0xF0) >> 4) + 0X30);
//         SEND_TO_ARRAY_Value((TIME[FOR_1] & 0x0F) + 0X30);

//         if(FOR_1==1)
//         {
//             SEND_TO_ARRAY("20");
//         }

//         if(FOR_1==2 || FOR_1==5)
//         {
//             SEND_COMMA_TO_ARRAY();
//         }
//     }

//     //RTC:- DDMMYYYY,HHMMSS,

// ///************************************************************************************************************************************************************/

//     for(FOR_1=0; FOR_1<=7; FOR_1++)
//     {
//         NOP();                                                //LATITUDE AND DIRECTION

//         SEND_TO_ARRAY_Value(LAT_DM[FOR_1]);

//         if(FOR_1==1)
//         {
//             SEND_TO_ARRAY(".");
//         }
//     }

//     if(LAT_DIRECTION=='N')
//     {
//         SEND_TO_ARRAY(",N,");
//     }
//     else
//     {
//         SEND_TO_ARRAY(",S,");
//     }

// ///************************************************************************************************************************************************************/

//     for(FOR_1=0; FOR_1<=8; FOR_1++)
//     {
//         NOP();                                                //LONGITUDE AND DIRECTION

//         SEND_TO_ARRAY_Value(LOG_DM[FOR_1]);

//         if(FOR_1==2)
//         {
//             SEND_TO_ARRAY(".");
//         }
//     }

//     if(LON_DIRECTION=='E')
//     {
//         SEND_TO_ARRAY(",E,");
//     }
//     else
//     {
//         SEND_TO_ARRAY(",W,");
//     }

//     NOP();

// ///************************************************************************************************************************************************************/

//     GET_SPEED_DATA();

//     if(ADD_ZERO_TO_SPEED==SET)
//     {
//         SEND_TO_ARRAY("0");
//     }

//     for(FOR_1=0; FOR_1<=SPEED_DATA_LENGTH_COUNT; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(SPEED_DATA[FOR_1]);
//     }

//     DECIMAL_POINT_CAME_STOP_TX=OFF;

//     NOP();

//     SEND_COMMA_TO_ARRAY();

//     NOP();

// ///************************************************************************************************************************************************************/

//     COG_VALUE_COUNT=CLR;

//     for(FOR_1=0; FOR_1<=5; FOR_1++)
//     {
//         NOP();

//         if(COG[FOR_1]!='.')
//         {
//             COG_VALUE_COUNT++;
//         }
//         else if(COG[FOR_1]=='.')
//         {
//             break;
//         }
//     }

//          if(COG_VALUE_COUNT==1)
//     {
//         SEND_TO_ARRAY("00");

//         COG_VALUE_COUNT=3;

//         NOP();
//     }
//     else if(COG_VALUE_COUNT==2)
//     {
//         SEND_TO_ARRAY_Value("0");

//         COG_VALUE_COUNT=4;

//         NOP();
//     }
//     else
//     {
//         COG_VALUE_COUNT=5;
//     }

//     for(FOR_1=0; FOR_1<=COG_VALUE_COUNT; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(COG[FOR_1]);
//     }

//     // HEADING :-COURSE OVER GROUND IN DEGREE

//     SEND_COMMA_TO_ARRAY();

//     SEND_TO_ARRAY_Value((NO_OF_SAT/10)+0x30);
//     SEND_TO_ARRAY_Value((NO_OF_SAT%10)+0x30);

//     SEND_TO_ARRAY(",");

//     NOP();                                                    // NO OF SATELLITE

// ///************************************************************************************************************************************************************/

//     ALTITUDE_VALUE_COUNT=CLR;

//     for(FOR_1=0; FOR_1<=4; FOR_1++)
//     {
//         NOP();

//         if(ALTITUDE[FOR_1]!='.')
//         {
//             ALTITUDE_VALUE_COUNT++;
//         }
//         else if(ALTITUDE[FOR_1]=='.')
//         {
//             break;
//         }
//     }

//          if(ALTITUDE_VALUE_COUNT==1)
//     {
//         SEND_TO_ARRAY("00");

//         ALTITUDE_VALUE_COUNT=2;

//         NOP();
//     }
//     else if(ALTITUDE_VALUE_COUNT==2)
//     {
//         SEND_TO_ARRAY("0");

//         ALTITUDE_VALUE_COUNT=3;

//         NOP();
//     }
//     else
//     {
//         ALTITUDE_VALUE_COUNT=4;
//     }

//     for(FOR_1=0; FOR_1<=ALTITUDE_VALUE_COUNT; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(ALTITUDE[FOR_1]);
//     }

//     //R_UART2_SEND(",0.00,"); NOP();

//     SEND_COMMA_TO_ARRAY();

//     for(FOR_1=0; FOR_1<=4; FOR_1++)
//     {
//         NOP();

//         if(PDOP_DATA_RX[FOR_1]=='1' || PDOP_DATA_RX[FOR_1]=='2' || PDOP_DATA_RX[FOR_1]=='3' || PDOP_DATA_RX[FOR_1]=='4' || PDOP_DATA_RX[FOR_1]=='5' || PDOP_DATA_RX[FOR_1]=='6' || PDOP_DATA_RX[FOR_1]=='7' || PDOP_DATA_RX[FOR_1]=='8' || PDOP_DATA_RX[FOR_1]=='9' || PDOP_DATA_RX[FOR_1]=='0' || PDOP_DATA_RX[FOR_1]=='.')
//         {
//             SEND_TO_ARRAY_Value(PDOP_DATA_RX[FOR_1]);
//         }
//         else
//         {
//             SEND_TO_ARRAY("0");
//         }
//     }

//     SEND_COMMA_TO_ARRAY();

// ///************************************************************************************************************************************************************/

//     for(FOR_1=0; FOR_1<=4; FOR_1++)
//     {
//         NOP();

//         if(HDOP[FOR_1]=='1' || HDOP[FOR_1]=='2' || HDOP[FOR_1]=='3' || HDOP[FOR_1]=='4' || HDOP[FOR_1]=='5' || HDOP[FOR_1]=='6' || HDOP[FOR_1]=='7' || HDOP[FOR_1]=='8' || HDOP[FOR_1]=='9' || HDOP[FOR_1]=='0' || HDOP[FOR_1]=='.')
//         {
//             SEND_TO_ARRAY_Value(HDOP[FOR_1]);
//         }
//         else
//         {
//             SEND_TO_ARRAY("0");
//         }
//     }

//     SEND_COMMA_TO_ARRAY();                                    //HDOP

// ///************************************************************************************************************************************************************/

// //******    for(FOR_1=0;FOR_1<=7;FOR_1++){NOP();R_UART2_SEND_User(NETWORK_NAME[FOR_1]);}R_UART2_SEND(",");NOP();   //NETWORK OPEATOR NAME

// ///************************************************************************************************************************************************************/

//     NOP();

//     SEND_TO_ARRAY_Value(Array_0[IGNITION]);

//     NOP();

//     SEND_TO_ARRAY(",");

//     NOP();                                                    // IGNITION

// ///************************************************************************************************************************************************************/

//     //if(MAIN_BATTERY_VOLTAGE<=40){MAIN_BAT_STATUS=OFF;TEMP_MAIN_BATTERY_VOLTAGE=0;SEND_TO_ARRAY("0,");}else{MAIN_BAT_STATUS=ON;SEND_TO_ARRAY("1,");}NOP();      // MAIN BATTERY STATUS

//     if(MAIN_BAT_STATUS==OFF)
//     {
//         SEND_TO_ARRAY("0,");
//     }
//     else
//     {
//         SEND_TO_ARRAY("1,");
//     }

//     NOP();                                                    // MAIN BATTERY STATUS

//     BATTERY_MEASUREMENT=ON;

//     SEND_TO_ARRAY_Value(((MAIN_BATTERY_VOLTAGE/100)+0x30));

//     VOLT=MAIN_BATTERY_VOLTAGE%100;

//     SEND_TO_ARRAY_Value(((VOLT/10)+0x30));

//     NOP();

//     SEND_TO_ARRAY(".");

//     SEND_TO_ARRAY_Value(((VOLT%10)+0x30));

//     SEND_TO_ARRAY(",");                                       //MAIN BATTERY VOLTAGE

// ///************************************************************************************************************************************************************/

//     VOLT=BACKUP_BATTERY_VOLTAGE%1000;

//     SEND_TO_ARRAY_Value(((VOLT/100)+0x30));

//     VOLT=VOLT%100;

//     SEND_TO_ARRAY(".");

//     SEND_TO_ARRAY_Value(((VOLT/10)+0x30));

//     //R_UART2_SEND_User(((VOLT%10)+0x30));

//     SEND_COMMA_TO_ARRAY();                                    //BACKUP BATTERY VOLTAGE

//     BATTERY_MEASUREMENT=OFF;

// ///************************************************************************************************************************************************************/

//     SEND_TO_ARRAY_Value(Array_0[PANIC_ALERT]);

//     NOP();                                                    //PANIC ALERT

// ///************************************************************************************************************************************************************/

// ///************************************************************************************************************************************************************/                              //PANIC ALERT & TAMPER ALERT 'C'

//     HEX_CHARACTER_CONVERSION=SET;

//     if(MNC[0]==0x78)
//     {
//         SEND_TO_ARRAY("00");
//     }
//     else
//     {
//         if(MNC_DATA_LENGTH>=2)
//         {
//             MNC_DATA_LENGTH=1;
//         }

//         for(FOR_1=0; FOR_1<=MNC_DATA_LENGTH; FOR_1++)
//         {
//             NOP();

//             SEND_TO_ARRAY_Value(MNC[FOR_1]);
//         }
//     }

//     SEND_COMMA_TO_ARRAY();

// ///************************************************************************************************************************************************************/

//     PRINT_ZEROS_2(LAC_DATA_LENGTH_0);

//     for(FOR_1=0; FOR_1<=LAC_DATA_LENGTH_0; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(LAC[FOR_1]);
//     }

//     SEND_COMMA_TO_ARRAY();

//     PRINT_ZEROS_2(CELL_ID_DATA_LENGTH_0);

// /************************************************************************************************************************************************************/

//     for(FOR_1=0; FOR_1<=CELL_ID_DATA_LENGTH_0; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(CELL_ID[FOR_1]);
//     }

//     SEND_COMMA_TO_ARRAY();

// /************************************************************************************************************************************************************/

//     // CELL ID:-1

//     PRINT_ZEROS_2(CELL_ID_DATA_LENGTH[1]);

//     for(FOR_1=0; FOR_1<=CELL_ID_DATA_LENGTH[1]; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(CELL_ID_1[FOR_1]);
//     }

//     SEND_COMMA_TO_ARRAY();

//     // LAC:-1

//     PRINT_ZEROS_2(LAC_DATA_LENGTH[1]);

//     for(FOR_1=0; FOR_1<=LAC_DATA_LENGTH[1]; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(LAC_1[FOR_1]);
//     }

//     SEND_COMMA_TO_ARRAY();

//     // DBM:-1

//     for(FOR_1=0; FOR_1<=DBM_DATA_LENGTH[1]; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(DBM_1[FOR_1]);

//              if(DBM_DATA_LENGTH[1]==2 && FOR_1==0)
//         {
//             SEND_TO_ARRAY("0");

//             NOP();
//         }
//         else if(DBM_DATA_LENGTH[1]==1 && FOR_1==0)
//         {
//             SEND_TO_ARRAY("00");

//             NOP();
//         }
//     }

//     SEND_COMMA_TO_ARRAY();

// /************************************************************************************************************************************************************/

// /************************************************************************************************************************************************************/

//     // CELL ID:-2

//     PRINT_ZEROS_2(CELL_ID_DATA_LENGTH[2]);

//     for(FOR_1=0; FOR_1<=CELL_ID_DATA_LENGTH[2]; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(CELL_ID_2[FOR_1]);
//     }

//     SEND_COMMA_TO_ARRAY();

//     // LAC:-2

//     PRINT_ZEROS_2(LAC_DATA_LENGTH[2]);

//     for(FOR_1=0; FOR_1<=LAC_DATA_LENGTH[2]; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(LAC_2[FOR_1]);
//     }

//     SEND_COMMA_TO_ARRAY();

//     // DBM:-2

//     for(FOR_1=0; FOR_1<=DBM_DATA_LENGTH[2]; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(DBM_2[FOR_1]);

//              if(DBM_DATA_LENGTH[2]==2 && FOR_1==0)
//         {
//             SEND_TO_ARRAY("0");

//             NOP();
//         }
//         else if(DBM_DATA_LENGTH[2]==1 && FOR_1==0)
//         {
//             SEND_TO_ARRAY("00");

//             NOP();
//         }
//     }

//     SEND_COMMA_TO_ARRAY();

// /************************************************************************************************************************************************************/

//     // CELL ID:-3

//     PRINT_ZEROS_2(CELL_ID_DATA_LENGTH[3]);

//     for(FOR_1=0; FOR_1<=CELL_ID_DATA_LENGTH[3]; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(CELL_ID_3[FOR_1]);
//     }

//     SEND_COMMA_TO_ARRAY();

//     // LAC:-3

//     PRINT_ZEROS_2(LAC_DATA_LENGTH[3]);

//     for(FOR_1=0; FOR_1<=LAC_DATA_LENGTH[3]; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(LAC_3[FOR_1]);
//     }

//     SEND_COMMA_TO_ARRAY();

//     // DBM:-3

//     for(FOR_1=0; FOR_1<=DBM_DATA_LENGTH[3]; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(DBM_3[FOR_1]);

//              if(DBM_DATA_LENGTH[3]==2 && FOR_1==0)
//         {
//             SEND_TO_ARRAY("0");

//             NOP();
//         }
//         else if(DBM_DATA_LENGTH[3]==1 && FOR_1==0)
//         {
//             SEND_TO_ARRAY("00");

//             NOP();
//         }
//     }

//     SEND_COMMA_TO_ARRAY();

// /************************************************************************************************************************************************************/

//     //CELL ID:-4

//     PRINT_ZEROS_2(CELL_ID_DATA_LENGTH[4]);

//     for(FOR_1=0; FOR_1<=CELL_ID_DATA_LENGTH[4]; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(CELL_ID_4[FOR_1]);
//     }

//     SEND_COMMA_TO_ARRAY();

//     // LAC:-4

//     PRINT_ZEROS_2(LAC_DATA_LENGTH[4]);

//     for(FOR_1=0; FOR_1<=LAC_DATA_LENGTH[4]; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(LAC_4[FOR_1]);
//     }

//     SEND_COMMA_TO_ARRAY();

//     // DBM:-4

//     for(FOR_1=0; FOR_1<=DBM_DATA_LENGTH[4]; FOR_1++)
//     {
//         NOP();

//         SEND_TO_ARRAY_Value(DBM_4[FOR_1]);

//              if(DBM_DATA_LENGTH[4]==2 && FOR_1==0)
//         {
//             SEND_TO_ARRAY("0");

//             NOP();
//         }
//         else if(DBM_DATA_LENGTH[4]==1 && FOR_1==0)
//         {
//             SEND_TO_ARRAY("00");

//             NOP();
//         }
//     }

//     HEX_CHARACTER_CONVERSION=CLR;

// ///************************************************************************************************************************************************************/

//     FRAME_NUMBER++;

//     if(FRAME_NUMBER>=1000000)
//     {
//         FRAME_NUMBER=1;
//     }

//     TEMP_FRAME_NUMBER=FRAME_NUMBER;

//     SEND_TO_ARRAY_Value(((TEMP_FRAME_NUMBER/100000)+0x30));

//     TEMP_FRAME_NUMBER=TEMP_FRAME_NUMBER%100000;

//     SEND_TO_ARRAY_Value(((TEMP_FRAME_NUMBER/10000)+0x30));

//     TEMP_FRAME_NUMBER=TEMP_FRAME_NUMBER%10000;

//     SEND_TO_ARRAY_Value(((TEMP_FRAME_NUMBER/1000)+0x30));

//     TEMP_FRAME_NUMBER=TEMP_FRAME_NUMBER%1000;

//     SEND_TO_ARRAY_Value(((TEMP_FRAME_NUMBER/100)+0x30));

//     TEMP_FRAME_NUMBER=TEMP_FRAME_NUMBER%100;

//     SEND_TO_ARRAY_Value(((TEMP_FRAME_NUMBER/10)+0x30));

//     SEND_TO_ARRAY_Value(((TEMP_FRAME_NUMBER%10)+0x30));

//     RECORD_ARRAY_ADDRESS=1;
// }


void SEND_WREN_COMMAND(void)
{
    MS_TIMER(5);

    FLASH_CE = LOW;

    R_CSI00_SEND(WREN);

    //R_CSI00_Send_Receive(WREN,1u,0);

    MS_TIMER(5);

    FLASH_CE = HIGH;
}

void WRITE_STATUS_REGISTER(void)
{
    MS_TIMER(5);

    FLASH_CE = LOW;

    R_CSI00_Send_Receive(WRSR, 2u, 0);

    MS_TIMER(5);

    FLASH_CE = HIGH;
}

void READ_STATUS_REGISTER(void)
{
    MS_TIMER(5);

    FLASH_CE = LOW;

    R_CSI00_Send_Receive(RDSR, 2u, 0);

    MS_TIMER(5);

    FLASH_CE = HIGH;
}

void CHIP_ERASE(void)
{
    SEND_WREN_COMMAND();

    MS_TIMER(50);

    FLASH_CE = LOW;

    R_CSI00_SEND(CE);

    //R_CSI00_Send_Receive(CE,1u,0);

    MS_TIMER(50);

    FLASH_CE = HIGH;

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

    MS_TIMER(5);

    FLASH_CE = LOW;

    R_CSI00_SEND(STATUS_REG);

    //R_CSI00_Send_Receive(STATUS_REG,2u,FLASH_STATUS);
    //R_CSI00_Send_Receive(FLASH_STATUS,2u,FLASH_STATUS);

    MS_TIMER(5);

    FLASH_CE = HIGH;

    if(FLASH_STATUS[1] != 0)
    {
        MS_TIMER(10);

        goto CHECK_AGAIN;
    }
}

// void SEND_COMMA_TO_ARRAY(void)
// {
//     SEND_TO_ARRAY(",");

//     NOP();
// }

void FLASH_WRITE(void)
{
    /*GREEN_LED=ON*/;

    FLASH_HOLD = FLASH_WP = HIGH;

    //WRITE_STATUS_REGISTER();
    //READ_STATUS_REGISTER();

REPEAT_WRITING:

    SEND_WREN_COMMAND();        // WREN COMMAND SENDING

    //if(FLASH_READ_ADDRESS==1){CHIP_ERASE();}

    TEMP_FLASH_WRITE_ADDRESS = FLASH_WRITE_ADDRESS / 65536;

    FLASH_WRITE_ADDRESS_1 = TEMP_FLASH_WRITE_ADDRESS;

    TEMP_FLASH_WRITE_ADDRESS = FLASH_WRITE_ADDRESS % 65536;

    FLASH_WRITE_ADDRESS_2 = TEMP_FLASH_WRITE_ADDRESS / 256;
    FLASH_WRITE_ADDRESS_3 = TEMP_FLASH_WRITE_ADDRESS % 256;

    MS_TIMER(5);

    FLASH_CE = LOW;

    R_CSI00_SEND(0x02);         // READ COMMAND
    //R_CSI00_SEND(0x00);
    //R_CSI00_SEND(0x00);
    //R_CSI00_SEND(0x00);

    R_CSI00_SEND(FLASH_WRITE_ADDRESS_1);      // READ-ADDRESS-1
    R_CSI00_SEND(FLASH_WRITE_ADDRESS_2);      // READ-ADDRESS-2
    R_CSI00_SEND(FLASH_WRITE_ADDRESS_3);      // READ-ADDRESS-3

    while(FLASH_WRITING == LOW)
    {
        R_CSI00_SEND(RECORD[FLASH_BYTE]);

        FLASH_WRITE_ADDRESS++;

        FLASH_BYTE++;

        FLASH_WRITE_ADDRESS_3++;

        if(FLASH_BYTE > 174 || FLASH_WRITE_ADDRESS_3 % 256 == 0)
        {
            FLASH_WRITING = HIGH;
        }
    }

    MS_TIMER(5);

    FLASH_CE = HIGH;

    FLASH_WRITING = LOW;

    if(FLASH_WRITE_ADDRESS_3 % 256 == 0 && FLASH_BYTE <= 174)
    {
        goto REPEAT_WRITING;
    }

    FLASH_BYTE = 1;

    for(FOR_1 = 0; FOR_1 <= 179; FOR_1++)
    {
        RECORD[FOR_1] = 0;
    }

    FLASH_MEMORY++;
}

void READ_FLASH_MEM(void)
{
    for(FOR_1 = 0; FOR_1 <= 200; FOR_1++)
    {
        RECORD[FOR_1] = 0;

        NOP();
    }

    TEMP_FLASH_READ_ADDRESS = FLASH_READ_ADDRESS / 65536;

    FLASH_READ_ADDRESS_1 = TEMP_FLASH_READ_ADDRESS;

    TEMP_FLASH_READ_ADDRESS = FLASH_READ_ADDRESS % 65536;

    FLASH_READ_ADDRESS_2 = TEMP_FLASH_READ_ADDRESS / 256;
    FLASH_READ_ADDRESS_3 = TEMP_FLASH_READ_ADDRESS % 256;

    MS_TIMER(100);

    FLASH_CE = LOW;

    R_CSI00_SEND(0x03);                                         // READ COMMAND
    //R_CSI00_SEND(0x00);
    //R_CSI00_SEND(0x00);
    //R_CSI00_SEND(0x00);

    R_CSI00_SEND(FLASH_READ_ADDRESS_1);                         // READ-ADDRESS-1
    R_CSI00_SEND(FLASH_READ_ADDRESS_2);                         // READ-ADDRESS-2
    R_CSI00_SEND(FLASH_READ_ADDRESS_3);                         // READ-ADDRESS-3

    R_CSI00_Send_Receive(RECORD, 175, RECORD);

    MS_TIMER(100);

    FLASH_CE = HIGH;

    /*****************************************************************************************/

    R_UART2_SEND("http://103.129.98.194/apis/update-vehicle-tracking.php?datas=$,PVT,VID,");

    NOP();
    NOP();

    /*****************************************************************************************/

    R_UART2_SEND_User(((CURRENT_FRM_VERSION / 100) + 0x30));

    R_UART2_SEND(".");

    NOP();

    TEMP_FRM_VERSION = CURRENT_FRM_VERSION % 100;

    R_UART2_SEND_User(((TEMP_FRM_VERSION / 10) + 0x30));

    R_UART2_SEND(".");

    NOP();

    R_UART2_SEND_User(((TEMP_FRM_VERSION % 10) + 0x30));

    R_UART2_SEND(",");

    NOP();

    /*****************************************************************************************/

    for(FOR_1 = 1; FOR_1 <= 6; FOR_1++)
    {
        R_UART2_SEND_User(RECORD[FOR_1]);
    }

    R_UART2_SEND("H,");

    NOP();

    for(FOR_1 = 1; FOR_1 <= 15; FOR_1++)
    {
        R_UART2_SEND_User(IMEI_EEPROM[FOR_1]);

        NOP();
        NOP();
    }

    R_UART2_SEND(",");

    NOP();                                                      //IMEI NUMBER

    for(FOR_1 = 0; FOR_1 <= 9; FOR_1++)
    {
        if(VEICHLE_NUMBER[FOR_1] != ' ' && VEICHLE_NUMBER[FOR_1] != '\0')
        {
            R_UART2_SEND_User(VEICHLE_NUMBER[FOR_1]);

            MS_TIMER(1);
        }
    }

    R_UART2_SEND(",");

    NOP();                                                      //VEICHLE NUMBER

    for(FOR_1 = 7; FOR_1 <= 82; FOR_1++)
    {
        R_UART2_SEND_User(RECORD[FOR_1]);                       // GPS FIX, DATA, TIME, LATITUDE,LAT-DIRECTION, LONGITUDE, LONG-DIRECTION, SPEED, HEADING, NO OF SAT, ALTITITUDE, PDOP, HDOP,
    }

    R_UART2_SEND("00000000,");

    NOP();                                                      // NETWORK NAME

    for(FOR_1 = 83; FOR_1 <= 96; FOR_1++)
    {
        R_UART2_SEND_User(RECORD[FOR_1]);                       // IGNITION, MAIN POWER STATUS, MAIN INPUT VOLTAGE, BACKUP BATTERY VOLTAGE, PANIC ALERT
    }

    R_UART2_SEND(",C,00,404,");

    NOP();                                                      // TAMPER ALERT OPTIONAL

    for(FOR_1 = 97; FOR_1 <= 168; FOR_1++)
    {
        R_UART2_SEND_User(RECORD[FOR_1]);

        NOP();                                                  // GPS FIX, DATA, TIME, LATITUDE,LAT-DIRECTION, LONGITUDE, LONG-DIRECTION, SPEED, HEADING, NO OF SAT, ALTITITUDE, PDOP, HDOP,
    }

    R_UART2_SEND(",0000,00,");

    NOP();                                                      // DIGITAL & ANALOG STATUS

    for(FOR_1 = 169; FOR_1 <= 174; FOR_1++)
    {
        R_UART2_SEND_User(RECORD[FOR_1]);

        NOP();                                                  // GPS FIX, DATA, TIME, LATITUDE,LAT-DIRECTION, LONGITUDE, LONG-DIRECTION, SPEED, HEADING, NO OF SAT, ALTITITUDE, PDOP, HDOP,
    }

    R_UART2_SEND(",00,*");

    NOP();

    FLASH_READ_ADDRESS = FLASH_READ_ADDRESS + 174;
}