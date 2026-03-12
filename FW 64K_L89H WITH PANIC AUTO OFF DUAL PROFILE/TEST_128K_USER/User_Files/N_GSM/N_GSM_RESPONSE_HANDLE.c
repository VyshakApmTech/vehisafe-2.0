#include "r_cg_userdefine.h"
//const unsigned char DEVICE_RESET_CMD_FRAME[] = {"SET VLT RESET IMEI "};
const unsigned char SET_HEALTH_FRAME[] = {"SET HPET IMEI "};
const unsigned char GET_VERSION_FRAME[12] = {"GET VERSION "};
const unsigned char GET_VLT_IMEI_PH_FRAME[] = {"GET VLT IMEI 0669 "};
const unsigned char SET_HACL_FRAME[] = {"SET HACL IMEI 2202="};
const unsigned char SET_HBRK_FRAME[] = {"SET HBRK IMEI 2202="};
const unsigned char SET_HTRN_FRAME[] = {"SET HTRN IMEI 2202="};
const unsigned char SET_LBAT_FRAME[] = {"SET LBAT IMEI 2202="};
const unsigned char SET_APN_FRAME2[] = {"SET APN IMEI 2202="};
// const unsigned char SET_ENO_FRAME[] = {"SET ENO IMEI 2202="};  // 18 characters (same as APN)
char TEMP_HACL_VALUE[3];  // For storing the HACL value (e.g., "30")
extern char IMEI_EEPROM[16],RX_ACK_Frame,ACK,ERROR_OCCURED,RX_SMS_CMD,RX_CMD_SMS[10],t,SMS_FAIL_COUNT,SMS_FAIL,NETWORK_NAME_RX,BATTERY_MEASUREMENT,SET_OVERSPEED_RX,GET_SLEEP_TIME_RX;
extern char IGNITION_CTRL_RX,INITIAL_MESSAGE,P_LAT_DM_RX,FILE_CLOSE_ATTEMPT;
extern char V_NO_LEN,GSM_REG,GPRS_REG,SS_DATA_RX,GET_SS,dBm,SMS_MOBILE_NO[55],HEALTH_ON_DURATON_S_RX;
extern char VN_ACK_RX,PANIC_NUMBER_RX,GPRS_CONNECTED,GSM_STRENGTH,INTERNET_CONNECTED,DISCONNECT,LOW_BATTERY_ALERT,HTTP_CONNECT_COUNT,VEICHLE_NUMBER[15],NW_NAME_RX,IMEI[16];
extern unsigned int FOR_1,FOR_3,Address_1,NW_REGN_COUNT,FLASH_MEMORY,GPRS_REG_COUNT,MAIN_BATTERY_VOLTAGE,ADC_BUFFER,BACKUP_BATTERY_VOLTAGE,GPRS_REG_ROAMING,GSM_REG_ROAMING,T_SPEED,FILTER,DATA_HEADER,TEMP_VERSION,SLEEP_ON_LEVEL,SLEEP_OF_LEVEL,OVER_SPEED;
extern unsigned int t_count,WRITE_ADDRESS,DATA,WATCH_DOG_KILL,WRITE_ADDRESS,TEMPS,WRITE_ADDRESS_MSB,WRITE_ADDRESS_LSB,BYTE;
extern char LOG_DM[10],LAT_DM[10],TIME[10],GPS_BUSY,SPEED[4],/*GPS_RX,*/SPEED_DATA_RX[10],WATCH_DOG,FILE[150],FIRM_DATA[150];
extern char GPS_DIRECTION_DATA_VALID,IGNITION,PANIC_ALERT,PANIC_ALERT_PACKET,IGNITION_ON_PACKET,IGNITION_OFF_PACKET,POWER_SOURCE_PACKET,LOW_BATTERY_ALERT_PACKET;
extern char HOURS_MSB,HOURS_LSB,MIN_MSB,MIN_LSB,LON_DIRECTION,LAT_DIRECTION,LAT_DM_RX[10],LOG_DM_RX[10],COG[6],GPGA_DATA[10],ALTITUDE[8],HDOP[5],NO_OF_SAT,NAVIGATION_ACK,NAVIGATION_RX,GPS_RESTART,REPLY_NUMBER_RX,REPLY_NUMBER[10];

extern char Array_0[10],I[100],i,SMS,NETWORK_FAILURE,HTTP_PRINT,SPEED_DATA[10],GET_IMEI_SEND_CMD_RX,APN_LENGTH,GET_SLEEP_OFF_TIME_RX;
extern char NWI_CMD_FRAME[10],NETWORK_NAME[8],SS_DATA_RX,SET_RP_NO_FRAME_CMD,GET_SMS_RX,TEMP_SIP[16],TEMP_SIP2[16],GET_SIP_S_RX;
extern  char HA_LEVEL,TEMP_PIP[16],TEMP_PIP2[16];
extern const char VODAFONE_ACK_V[15],VN_ACK[3],OK_ACK[2],ERROR_ACK[5],HTTP_RESPONSE_FAIL[4],IMEI_ACK[9],GSM_NW_REG[8],GPRS_NW_REG[9],ENGINEER_MODE_FRAME_1[9],SETTINGS_UPDATE_CTRL[3],NETMODE_UPDATE_CTRL[3];
extern const char SET_TCP_FRAME[8],SETTING_CMD_FRAME[13],GET_IN_SMS[4],CONNECT_ACK[7],SIGNAL_STRENGTH_ACK[5],NW_DIS_CONNECT[9],DEVICE_RESTART_ACK[12],IGNITION_CTRL[4],CPIN_READY[11];
extern const char FILE_DOWNLOAD_ACK[8],HTTP_DOWNLOAD[8],FTP_ADDRESS_ACK[8],FILE_DOWNLOAD_ACK[8],FIRM_UPDATE_CTRL[3],PANIC_CTRL[4];
extern const char ENGINEER_MODE_FRAME_2[10],NEW_SMS_FRAME[11],PHONE_NUMBER_OF_SENDER_FRAME[23],GET_IMEI_SMS_CMD[12],DEVICE_RESET_CMD_FRAME[13]; 
extern const char NW_NAME_ACK[5];
extern const char ALREADY_CONNECT_ACK[15],SET_APN_FRAME[8],SET_IP_FRAME[8],SET_RP_NO_FRAME[8],REPLY_MOBILE_NUMBER_ACK[8],DEVICE_CLEAR_CMD_FRAME[14],HARSH_ACCEL_CMD_FRAME[9],HARSH_TURN_CMD_FRAME[8],HARSH_BRAKE_CMD_FRAME[9],QST_CMD_FRAME[8];
extern const char PANIC_ON_DURATON_FRAME[9],HEALTH_ON_DURATON_FRAME[9],PANIC_ON_DURATON_S_FRAME[4],HEALTH_ON_DURATON_S_FRAME[4],LOW_BAT_LEVEL_FRAME[9],APN_S_FRAME[6],GET_SMS_FRAME[13],GET_ACT_MESSAGE[5];
extern const char GET_PIP_S_FRAME[4],GET_SIP_S_FRAME[5],GET_SLEEP_TIME_FRAME[5],GET_PPN_S_FRAME[11],GET_SPN_S_FRAME[11],SET_PIP_PN_FRAME[11],SET_SIP_PN_FRAME[11],GET_DEVICE_CLEAR_S_FRAME[9];
extern const char GET_GPS_CLEAR_S_FRAME[9],PANIC_MOBILE_NUMBER_ACK[5],CONNECT_FAIL_ACK[12],GET_HEALTH_MESSAGE_FRAME[5],PNET_CMD_FRAME[9],SNET_CMD_FRAME[9],NWA_CMD_FRAME[10],NWS_CMD_FRAME[10],GET_OVER_SPEED_FRAME[10];



extern char CPIN,SET_RP_NO_FRAME_RX,SET_TCP_FRAME_RX,SET_SETTINGS_FRAME_RX;
extern char P_LAT_DM[10],P_TIME[10],P_SEND_TIME[10],P_LOG_DM[10],P_SEND_LOG_DM[10],P_SEND_LAT_DM[10],FTP_ADDRESS[8],FTP_CONNECT_COUNT;
extern char FILE_ADDR,V_NO_LEN,IGNITION_OFF_TIME_RX,SLEEP_ON_TIME_RX;
extern unsigned int CHECKSUM_BYTE,MN,VERSION_TEMP,FRM_VERSION,CURRENT_FRM_VERSION,HEX,APN_TEMP,TEMP_OVS_LEVEL,SLEEP_ON_TIME,TEMP_SLEEP_ON_TIME,SLEEP_OFF_TIME,TEMP_SLEEP_OFF_TIME,TEMP_EMGT_TIME;
extern _Bool BSNL_CONNECT_FLAG,BSNL_CONNECT,FIRMWARE_UPDATE,IGNITION_CONTROL_STATE,POWER_SOURCE,SYSTEM_READY,MAIN_BAT_STATUS,DEVICE_RESTART_RX,DEVICE_RESTART_RX_1,DEVICE_CLEAR_CMD,HARSH_BRAKE_CMD_RX,HARSH_TURN_CMD_RX,HARSH_ACCEL_CMD_RX,HEALTH_ON_DURATON_CMD,PANIC_ON_DURATON_CMD,GET_SIP_CMD,MESSAGE_READ,SLEEP_OFF_TIME_CMD,ACTIVATION_CMD;
extern _Bool GPS_RST_FLAG,ALREADY_CONNECT,HTTP_DOWNLOAD_ACK,FTP_ACK,FTP_DOWNLOAD_ACK,FIRMWARE_DOWNLOADED,FILE_ACK,FILE_DOWNLOAD,FLAG,STOP_FILE_READING,IMEI_RX,IMEI_ACK_RX,UPDATE_EMERGENCY_NUMBER,UPDATE_REGISTRATION_NUMBER_1,HEALTH_PACKET_TO_SERVER,GET_PIP_CMD,GET_EMGT_TIME_CMD;
extern _Bool GPS_STANDBY,WATCH_DOG_FORCE_KILL,GET_MCC_MNC_LAC_CELL_ID_RX,SEND_IMEI,SET_EMERGENCY_NUMBER_FRAME_CMD,UPDATE_APN,UPDATE_REGISTRATION_NUMBER,UPDATE_INTERVAL_TIME_FOR_IGNITION_ON_CMD,UPDATE_INTERVAL_TIME_FOR_IGNITION_OFF_CMD,DEVICE_CLEAR_CMD_FRAME_RX,PRI_IP_PN_SMS,SEC_IP_PN_SMS,OVER_SPEED_CMD,ACTIVATION_CMD,HEALTH_CMD2;
extern unsigned int TEMP_3,IGNITION_ON_UPDATE_TIME,IGNITION_OFF_UPDATE_TIME,UPDATE_TIME_ON_TIME,UPDATE_TIME_OFF_TIME,HEALTH_ON_DURATON_LEVEL,P_D_L,PANIC_ALERT_TIME,HEALTH_ALERT_TIME,HARSH_ACCEL_LEVEL,HT_LEVEL,HB_LEVEL,EMGT_TIME;
extern int AD;
extern char p1,p2,p3,p4,UPDATE_INTERVAL_CMD,APN_LENGTH,TEMP_IP[15],SET_IP_FRAME_RX,IGNITION_ON_TIME_RX,APN_S_RX,TEMP_APN2[255],TEMP_SET[255],TEMP_TCP[255],GET_PIP_S_RX,SET_PIP_PN_RX;
extern char TEMP_RP_NO[12];
extern char VV;
extern char HEALTH_CMD_FRAME_RX,SETTING_CMD_FRAME_RX,PANIC_CTRL_RX,PANIC_CONTROL_STATE,PANIC_CONTROL_RX,FIRM_UPDATE_CTRL_RX,FIRM_UPDATE_CONTROL_STATE,FIRM_UPDATE_CONTROL_RX,NEW_SMS_INBOX_ADDRESS[20],NEW_SMS;

extern char MCC_MNC_LAC_CELL_ID_LENGTH;
extern _Bool SMS_PIN_WRONG,NEW_SMS_RX_FRAME_RX,SET_IP_FRAME_CMD,GET_SMS_CMD,PNET_CMD_REPLY,SNET_CMD_REPLY,NWP_CMD_SET,NWS_CMD_SET;

extern char  ENGINEER_MODE_FRAME_1_ACK,P,MCC_MNC_LAC_CELL_ID[20],GSM_COMMA,N,GSM_COMMA_2;
extern char DBM_1[5],LAC_1[5],CELL_ID_1[5],DBM_2[5],LAC_2[5],CELL_ID_2[5],DBM_3[5],LAC_3[5],CELL_ID_3[5],DBM_4[5],LAC_4[5],CELL_ID_4[5];
extern _Bool ENGINEER_MODE_FRAME_2_ACK,GET_NMR_RX,EW_SMS_RX_FRAME_RX,DEVICE_RESET_CMD_FRAME_RX,DEVICE_RESET_CMD,UPDATE_INTERVAL_CMD_2,SET_REGN_NUMBER_FRAME_CMD,SET_APN_FRAME_CMD,UPDATE_IP;

extern char MCC_1[5],MNC[5],LAC[5],CELL_ID[5],MCC_DATA_LENGTH,MNC_DATA_LENGTH,LAC_DATA_LENGTH_0,CELL_ID_DATA_LENGTH_0;

extern char TEMP_EMERGENCY_NUMBER[55];
extern char FOR_7,DBM_DATA_LENGTH[5],LAC_DATA_LENGTH[5],CELL_ID_DATA_LENGTH[5];
extern _Bool ALREADY_CONNECT_FLAG,VERSION_CMD_SET,GET_VLT_IMEI_PH_CMD,SMS_CMD_REPLY,PHONE_NUMBER_OF_SENDER_RX,SERVER_UPDATE_TIME_CMD_FRAME_RX,UPDATE_RP_NO,HARSH_BRAKE_CMD,HARSH_TURN_CMD,HARSH_ACCEL_CMD,PRIMARY_IP,SECONDARY_IP,GET_PPN_CMD,PRIMARY_PN,SECONDARY_PN;
extern char PHONE_NUMBER_OF_SENDER[12],GET_IMEI_SMS_CMD_RX,TEMP_REGN_NUMBER[15],TEMP_APN[15],SET_APN_FRAME_RX;
char G,PIN_COUNT_CHECK,Y,V,U,SNET_CMD_FRAME_RX,PNET_CMD_FRAME_RX,NWA_CMD_FRAME_RX,NWS_CMD_FRAME_RX;
extern _Bool GSM_NW_REG_CHECK,GPRS_REG_CHECK,GET_SIGNAL_STRENGTH_CHECK,CPIN_READY_CHECK;
extern const char VODAFONE_ACK[15],IGNITION_ON_TIME_ACK[11],IGNITION_OFF_TIME_ACK[12];
extern const char HARSH_ACCEL_CMD_SMS_FRAME[9],HARSH_TURN_CMD_SMS_FRAME[9],HARSH_BRAKE_CMD_SMS_FRAME[9];
extern char HARSH_ACCEL_CMD_SMS_RX,HARSH_TURN_CMD_SMS_RX,HARSH_BRAKE_CMD_SMS_RX,HARSH_ACCEL_CMD_SMS_LEVEL,HARSH_TURN_CMD_SMS_LEVEL,HARSH_BRAKE_CMD_SMS_LEVEL;
extern char HEALTH_ON_DURATON_RX,PANIC_ON_DURATON_RX,PANIC_ON_DURATON_S_RX;
extern char LOW_BAT_LEVEL_RX,LOW_BAT_LEVEL_CMD;
extern unsigned int HARSH_BRAKE_LEVEL,HARSH_TURN_LEVEL,LOW_BAT_LEVEL,LB_LEVEL,SLEEP_OFF_LEVEL;
extern char GET_PPN_S_RX,TEMP_PPN[4],TEMP_PPN2[4];
extern char GET_SPN_S_RX,TEMP_SPN[4],TEMP_SPN2[4],GET_SPN_S_RX,SET_SIP_PN_RX,GET_DEVICE_CLEAR_S_RX;
extern _Bool SETTING_CMD,SET_APN,SET_TCP,CONNECT_FAIL,QST_CMD_FLAG,GET_SPN_CMD,SET_SLEEP_OFF_CMD,SET_SLEEP_ON_CMD,SLEEP_ON_TIME_CMD;
extern char SET_SLEEP_OFF_FRAME[7],SET_SLEEP_ON_FRAME[7],SET_SLEEP_OF_RX,SET_SLEEP_ON_RX,SET_OVERSPEED_FRAME[8],GET_OVER_SPEED_RX;
extern unsigned int RESTART;
// CHACKING
unsigned int TEMP_D[25],TD;
//extern char QST_CMD_ACK[8];


void ACK_RX(unsigned int ct,unsigned int ack,unsigned int REDIAL,unsigned int WAIT_TIME)
{
	t_count=0;
/************************************************************************************************************************************************************/
	if(ack==0)              ///GSM REGISTRATION (CREG: 0,1)
	{
	while(GSM_REG==0 && t_count<=ct){NOP();}
	if(GSM_REG==2 || t_count>=ct)
	{
	GSM_REG=0;
	t_count=0;
	MS_TIMER(REDIAL);
	RESTART=ON;
	}
	GSM_REG=0;
	}
/************************************************************************************************************************************************************/
	else if(ack==1)		///GPRS REGISTRATION (CGREG: 0,1)
	{
	while(GPRS_REG==0 && t_count<=ct){NOP();}
	if(GPRS_REG==2 || t_count>=ct){GPRS_REG=0;t_count=0;RESTART=ON;
	MS_TIMER(REDIAL);
	}
	GPRS_REG=0;
	}
/************************************************************************************************************************************************************/	
	else if (ack==2)	/// OK
	{
	while(ACK==0 && ERROR_OCCURED==0 && t_count<=ct){NOP();}
	if(ERROR_OCCURED==1 || t_count>=ct)
	{
	t_count=0;ACK=0;ERROR_OCCURED=0;
	RESTART=ON;
	NOP();
	MS_TIMER(REDIAL);
	}
	ACK=0;
	}
/************************************************************************************************************************************************************/	
	else if (ack==3)	/// HTTP CONNECT
	{
	while(GPRS_CONNECTED==0 && ERROR_OCCURED==0 && t_count<=ct && INTERNET_CONNECTED==ON){NOP();}
	
	if(ERROR_OCCURED==1 || t_count>=ct || INTERNET_CONNECTED==OFF){
	GPRS_CONNECTED=OFF;t_count=0;ERROR_OCCURED=0;RESTART=ON;
	MS_TIMER(REDIAL);
	}
	GPRS_CONNECTED=OFF;
	}
/************************************************************************************************************************************************************/	
	else if (ack==4)	/// GET SIGNAL STRENGTH
	{
	while(GET_SS==0 && ERROR_OCCURED==0 && t_count<=ct){NOP();}
	if(ERROR_OCCURED==1 || t_count>=ct)
	{
	t_count=0;ERROR_OCCURED=0;RESTART=ON;
	MS_TIMER(REDIAL);
	}
	GET_SS=OFF;ACK=OFF;
	}
/************************************************************************************************************************************************************/	
	else if (ack==5)	/// OK & PDP ACT
	{
	while(ACK==0 && ERROR_OCCURED==0 && t_count<=ct && INTERNET_CONNECTED==ON){NOP();}
	if(ERROR_OCCURED==1 || t_count>=ct || INTERNET_CONNECTED==OFF)
	{
	t_count=0;ACK=0;ERROR_OCCURED=0;RESTART=ON;
	MS_TIMER(REDIAL);
	}
	ACK=0;
	}
/************************************************************************************************************************************************************/	
	else if (ack==6)	/// CPIN READY
	{
	while(CPIN==0 && ERROR_OCCURED==0 && t_count<=ct){NOP();}
	if(ERROR_OCCURED==1 || t_count>=ct){t_count=0;ACK=0;ERROR_OCCURED=0;RESTART=ON;
	MS_TIMER(REDIAL);
	}
	ACK=0;CPIN=0;
	}
/************************************************************************************************************************************************************/	
	else if (ack==7)	/// GPS PMTK COMMAND
	{
	while(NAVIGATION_ACK==0 && t_count<=ct){NOP();}
	if(t_count>=ct){t_count=0;RESTART=ON;
	MS_TIMER(REDIAL);
	}
	NAVIGATION_ACK=0;
	}
/************************************************************************************************************************************************************/	
	else if (ack==8)	/// HTTP FILE DOWNLOAD
	{
	while(HTTP_DOWNLOAD_ACK==0 && t_count<=ct){NOP();}
	if(ERROR_OCCURED==1 || t_count>=ct){t_count=0;ACK=0;ERROR_OCCURED=0;RESTART=ON;
	MS_TIMER(REDIAL);
	}
	HTTP_DOWNLOAD_ACK=0;
	}
/************************************************************************************************************************************************************/	
	else if (ack==9)	/// FTP FILE HANDLE ADDRESS
	{
	while(ERROR_OCCURED==0 && FTP_DOWNLOAD_ACK==0 && t_count<=ct){NOP();}
	if(ERROR_OCCURED==1 || t_count>=ct){t_count=0;ACK=0;ERROR_OCCURED=0;RESTART=ON;
	MS_TIMER(REDIAL);
	}
	FTP_DOWNLOAD_ACK=0;
	}
/************************************************************************************************************************************************************/	
	else if (ack==10)	/// FTP DOWNLOAD TO MC TO TEMP VARIABLE
	{
	while(ERROR_OCCURED==0 && t_count<=ct && FILE_DOWNLOAD==0){NOP();}
	if(t_count>=ct || ERROR_OCCURED==1)
	{
	t_count=0;RESTART=ON;ERROR_OCCURED=0;ACK=0;
	MS_TIMER(REDIAL);
	}
	FILE_DOWNLOAD=OFF;
	}
/************************************************************************************************************************************************************/	
	BLUE_LED=ON;
	MS_TIMER(WAIT_TIME);
	ACK=CLR;
	BLUE_LED=OFF;
	
}
void CMD_DATA_READ_IN_EEPROM(void)
{
	unsigned int A,B,C;

	
	IGNITION_ON_UPDATE_TIME=((i2c_readn(0xA0,0XFE,20))*10);MS_TIMER(2);
	
	IGNITION_ON_UPDATE_TIME=(((i2c_readn(0xA0,0XFE,21))+IGNITION_ON_UPDATE_TIME)*10);MS_TIMER(2);
	IGNITION_ON_UPDATE_TIME=((i2c_readn(0xA0,0XFE,22))+IGNITION_ON_UPDATE_TIME);MS_TIMER(2);
	
	if(IGNITION_ON_UPDATE_TIME>=1 && IGNITION_ON_UPDATE_TIME<=999)
	{
	UPDATE_TIME_ON_TIME=IGNITION_ON_UPDATE_TIME;
	}
	IGNITION_OFF_UPDATE_TIME=((i2c_readn(0xA0,0XFE,23))*10);MS_TIMER(2);
	IGNITION_OFF_UPDATE_TIME=(((i2c_readn(0xA0,0XFE,24))+IGNITION_OFF_UPDATE_TIME)*10);MS_TIMER(2);
	IGNITION_OFF_UPDATE_TIME=((i2c_readn(0xA0,0XFE,25))+IGNITION_OFF_UPDATE_TIME);MS_TIMER(2);
	A=CLR;
	
	if(IGNITION_OFF_UPDATE_TIME>=1 && IGNITION_OFF_UPDATE_TIME<=999)
	{
	UPDATE_TIME_OFF_TIME=IGNITION_OFF_UPDATE_TIME;
	}
	A=CLR;
	C=i2c_readn(0xA0,0XFE,26);
	if(C>=0x41 && C<=0x5A)
	{
	for(B=26;B<=35;B++)
	{
	VEICHLE_NUMBER[A]=i2c_readn(0xA0,0XFE,B);MS_TIMER(2);
	A++;
	}
	}
	A=CLR;
	for(B=50;B<=99;B++)
	{
		C=i2c_readn(0xA0,0XFE,B);MS_TIMER(2);  
	if(C>=0x30 && C<=0x39)
	{
	TEMP_EMERGENCY_NUMBER[A]=i2c_readn(0xA0,0XFE,B);MS_TIMER(2);  
	}
	else
	{
	TEMP_EMERGENCY_NUMBER[A]='0';
	}
	A++;
	}
	A=CLR;
	for(B=100;B<=109;B++)
	{
	C=i2c_readn(0xA0,0XFE,B);
	if(C>=0x30 && C<=0x39)
	{
	REPLY_NUMBER[A]=i2c_readn(0xA0,0XFE,B);MS_TIMER(2);  
	}
	else
	{
	REPLY_NUMBER[A]='0';
	}
	A++;
	}
	P_D_L=((i2c_readn(0xA0,0XFE,40))*10);MS_TIMER(2);
	P_D_L=(((i2c_readn(0xA0,0XFE,41))+P_D_L)*10);MS_TIMER(2);
	P_D_L=((i2c_readn(0xA0,0XFE,42))+P_D_L);MS_TIMER(2);
	if(P_D_L>=1 && P_D_L<=999)
	{
	PANIC_ALERT_TIME=P_D_L;
	}
	else
	{
	i2c_writen(0xA0,0XFE,40,0);MS_TIMER(2);
	i2c_writen(0xA0,0XFE,41,0);MS_TIMER(2);
	i2c_writen(0xA0,0XFE,42,1);MS_TIMER(2);
	PANIC_ALERT_TIME=P_D_L=1;
	}
	
	HEALTH_ON_DURATON_LEVEL=((i2c_readn(0xA0,0XFE,43))*10);MS_TIMER(2);
	HEALTH_ON_DURATON_LEVEL=(((i2c_readn(0xA0,0XFE,44))+HEALTH_ON_DURATON_LEVEL)*10);MS_TIMER(2);
	HEALTH_ON_DURATON_LEVEL=((i2c_readn(0xA0,0XFE,45))+HEALTH_ON_DURATON_LEVEL);MS_TIMER(2);
	if(HEALTH_ON_DURATON_LEVEL>=1 && HEALTH_ON_DURATON_LEVEL<=999)
	{
	HEALTH_ALERT_TIME=HEALTH_ON_DURATON_LEVEL;
	}
	else
	{
	i2c_writen(0xA0,0XFE,43,0);MS_TIMER(2);
	i2c_writen(0xA0,0XFE,44,0);MS_TIMER(2);
	i2c_writen(0xA0,0XFE,45,1);MS_TIMER(2);
	HEALTH_ON_DURATON_LEVEL=HEALTH_ALERT_TIME=1;
	}
	
	HARSH_ACCEL_LEVEL=i2c_readn(0xA0,0XFE,37);MS_TIMER(2); 
	if(HARSH_ACCEL_LEVEL<=3)
	{
	HA_LEVEL=HARSH_ACCEL_LEVEL;
	}
	else 
	{
	MS_TIMER(1);i2c_writen(0xA0,0XFE,37,1);MS_TIMER(1);
	HA_LEVEL=HARSH_ACCEL_LEVEL=1;
	}
	
	HARSH_TURN_LEVEL=i2c_readn(0xA0,0XFE,38);MS_TIMER(2); 
	if(HARSH_TURN_LEVEL<=3)
	{
	HT_LEVEL=HARSH_TURN_LEVEL;
	}
	else
	{
	MS_TIMER(1);i2c_writen(0xA0,0XFE,38,1);MS_TIMER(1);
	HT_LEVEL=HARSH_TURN_LEVEL=1;
	}
	
	HARSH_BRAKE_LEVEL=i2c_readn(0xA0,0XFE,39);MS_TIMER(2); 
	     if(HARSH_BRAKE_LEVEL<=3)
	     {
	     HB_LEVEL=HARSH_BRAKE_LEVEL;
	     }
	else
	{
	     MS_TIMER(1);i2c_writen(0xA0,0XFE,39,1);MS_TIMER(1);
	     HB_LEVEL=HARSH_BRAKE_LEVEL=1;
	}
	
	LOW_BAT_LEVEL=i2c_readn(0xA0,0XFE,46);MS_TIMER(2); 
	    if(LOW_BAT_LEVEL<=9)
	    {
	    LB_LEVEL=LOW_BAT_LEVEL;
	    }
	else
	{
	MS_TIMER(1);i2c_writen(0xA0,0XFE,46,1);MS_TIMER(1);
	LB_LEVEL=LOW_BAT_LEVEL=1;
	}
	
	APN_TEMP=i2c_readn(0xA0,0XFE,199);MS_TIMER(2);
	if(APN_TEMP<=20)
	{
		APN_LENGTH=APN_TEMP;
		APN_TEMP=APN_TEMP+200;
		A=CLR;
		for(B=200;B<=APN_TEMP;B++)
		{
		MS_TIMER(1);
		TEMP_APN[A]=i2c_readn(0xA0,0XFE,B);MS_TIMER(1);
		if(TEMP_APN[A]>=0x30 && TEMP_APN[A]<=0x39 || TEMP_APN[A]>=0x61 && TEMP_APN[A]<=0x7A)
		{
		TEMP_APN[A]=i2c_readn(0xA0,0XFE,B);MS_TIMER(1);
		}
		else
		{
			goto DEFAULT;
		}
		A++;
		}
	}
	else
	{
		DEFAULT:
		TEMP_APN[0]='s';
		TEMP_APN[1]='e';
		TEMP_APN[2]='n';
		TEMP_APN[3]='s';
		TEMP_APN[4]='e';
		TEMP_APN[5]='m';
		TEMP_APN[6]='2';
		TEMP_APN[7]='m';
		TEMP_APN[8]='m';
		TEMP_APN[9]='s';
		APN_LENGTH=7;
		CMD_DATA_WRITE_IN_EEROM(4);
			
	}
	TEMP_OVS_LEVEL=((i2c_readn(0xA0,0XFE,110))*10);MS_TIMER(2);
	TEMP_OVS_LEVEL=(((i2c_readn(0xA0,0XFE,111))+TEMP_OVS_LEVEL)*10);MS_TIMER(2);
	TEMP_OVS_LEVEL=((i2c_readn(0xA0,0XFE,112))+TEMP_OVS_LEVEL);MS_TIMER(2);
	if(TEMP_OVS_LEVEL<=999)
	{
		OVER_SPEED=TEMP_OVS_LEVEL;
	}
	else
	{
	OVER_SPEED=100;
	}
	TEMP_SLEEP_ON_TIME=((i2c_readn(0xA0,0XFE,113))*10);MS_TIMER(2);
	TEMP_SLEEP_ON_TIME=(((i2c_readn(0xA0,0XFE,114))+TEMP_SLEEP_ON_TIME)*10);MS_TIMER(2);
	TEMP_SLEEP_ON_TIME=((i2c_readn(0xA0,0XFE,115))+TEMP_SLEEP_ON_TIME);MS_TIMER(2);
	if(TEMP_SLEEP_ON_TIME<=600)
	{
		SLEEP_ON_TIME=TEMP_SLEEP_ON_TIME;
	}
	else
	{
	SLEEP_ON_TIME=120;
	}
	TEMP_SLEEP_OFF_TIME=((i2c_readn(0xA0,0XFE,116))*10);MS_TIMER(2);
	TEMP_SLEEP_OFF_TIME=(((i2c_readn(0xA0,0XFE,117))+TEMP_SLEEP_OFF_TIME)*10);MS_TIMER(2);
	TEMP_SLEEP_OFF_TIME=((i2c_readn(0xA0,0XFE,118))+TEMP_SLEEP_OFF_TIME);MS_TIMER(2);
	if(TEMP_SLEEP_OFF_TIME<=600)
	{
		SLEEP_OFF_TIME=TEMP_SLEEP_OFF_TIME;
	}
	else
	{
	SLEEP_OFF_TIME=120;
	}
	TEMP_EMGT_TIME=((i2c_readn(0xA0,0XFE,119))*10);MS_TIMER(2);
	TEMP_EMGT_TIME=(((i2c_readn(0xA0,0XFE,120))+TEMP_EMGT_TIME)*10);MS_TIMER(2);
	TEMP_EMGT_TIME=((i2c_readn(0xA0,0XFE,121))+TEMP_EMGT_TIME);MS_TIMER(2);
	if(TEMP_EMGT_TIME<=600)
	{
		EMGT_TIME=TEMP_EMGT_TIME;
	}
	else
	{
	EMGT_TIME=120;
	}
	
	
	
}


void PIN_CHECK(char x,char z)
{
    if(PIN_COUNT_CHECK==0)
    {
        if(x==IMEI[12])
            PIN_COUNT_CHECK=1;
    }

    else if(PIN_COUNT_CHECK==1)
    {
        if(x==IMEI[13])
            PIN_COUNT_CHECK=2;
        else
            PIN_COUNT_CHECK=0;
    }

    else if(PIN_COUNT_CHECK==2)
    {
        if(x==IMEI[14])
            PIN_COUNT_CHECK=3;
        else
            PIN_COUNT_CHECK=0;
    }

    else if(PIN_COUNT_CHECK==3)
    {
        if(x==IMEI[15])
        {
            if(z==1)        DEVICE_RESET_CMD=ON;
            else if(z==2)   UPDATE_INTERVAL_CMD=ON;
            else if(z==3)   UPDATE_INTERVAL_CMD_2=ON;
            else if(z==4)   SET_EMERGENCY_NUMBER_FRAME_CMD=ON;
            else if(z==5)   SET_REGN_NUMBER_FRAME_CMD=ON;
            else if(z==6)   SET_APN_FRAME_CMD=ON;
            else if(z==7)   SET_IP_FRAME_CMD=ON;
            else if(z==8)   SET_RP_NO_FRAME_CMD=ON;
            else if(z==9)   DEVICE_CLEAR_CMD=SET;
            else if(z==10)  HARSH_ACCEL_CMD=SET;
            else if(z==11)  HARSH_BRAKE_CMD=SET;
            else if(z==12)  HARSH_TURN_CMD=ON;
            else if(z==13)  PANIC_ON_DURATON_CMD=SET;
            else if(z==14)  HEALTH_ON_DURATON_CMD=SET;
            else if(z==15)  LOW_BAT_LEVEL_CMD=SET;
            else if(z==16)  GET_SMS_CMD=SET;

            PIN_COUNT_CHECK=0;
        }
        else
        {
            SMS_PIN_WRONG=SET;
            PIN_COUNT_CHECK=0;
        }
    }
}



void CMD_DATA_WRITE_IN_EEROM(char D)
{
	unsigned int K, FOR_5;

	MS_TIMER(100);

	if(D==1)
	{
		UPDATE_TIME_ON_TIME = IGNITION_ON_UPDATE_TIME;
		K = IGNITION_ON_UPDATE_TIME % 100;

		MS_TIMER(2);
		i2c_writen(0xA0,0XFE,20,IGNITION_ON_UPDATE_TIME/100); MS_TIMER(2);
		i2c_writen(0xA0,0XFE,21,K/10); MS_TIMER(2);
		i2c_writen(0xA0,0XFE,22,K%10); MS_TIMER(2);
	}

	if(D==2)
	{
		UPDATE_TIME_OFF_TIME = IGNITION_OFF_UPDATE_TIME;
		K = IGNITION_OFF_UPDATE_TIME % 100;

		MS_TIMER(2);
		i2c_writen(0xA0,0XFE,23,IGNITION_OFF_UPDATE_TIME/100); MS_TIMER(2);
		i2c_writen(0xA0,0XFE,24,K/10); MS_TIMER(2);
		i2c_writen(0xA0,0XFE,25,K%10); MS_TIMER(2);
	}

	if(D==3)
	{
		K = 26;

		for(FOR_5=0;FOR_5<=9;FOR_5++)
		{
			MS_TIMER(1);
			i2c_writen(0xA0,0XFE,K,TEMP_REGN_NUMBER[FOR_5]);
			MS_TIMER(2);
			K++;
		}
	}

	if(D==4)
	{
		MS_TIMER(2);
		i2c_writen(0xA0,0XFE,199,APN_LENGTH);
		MS_TIMER(2);

		K = 200;

		for(FOR_5=0;FOR_5<=APN_LENGTH;FOR_5++)
		{
			i2c_writen(0xA0,0XFE,K,TEMP_APN2[FOR_5]);
			MS_TIMER(2);
			K++;
		}

		MS_TIMER(1);
		i2c_writen(0xA0,0XFE,19,APN_LENGTH);
		MS_TIMER(2);
	}

	if(D==5)
	{
		K = 50;

		for(FOR_5=0;FOR_5<=49;FOR_5++)
		{
			MS_TIMER(1);
			i2c_writen(0xA0,0XFE,K,TEMP_EMERGENCY_NUMBER[FOR_5]);
			MS_TIMER(2);
			K++;
		}
	}

	//	if(D==6)
	//	{
	//	K=100;
	//	for(FOR_5=0;FOR_5<=14;FOR_5++)
	//	{
	//	//i2c_writen(0xA0,0XFE,K,TEMP_IP[FOR_5]);MS_TIMER(2);
	//	K++;
	//	}
	//	}


	if(D==7)
	{
		K = 100;

		for(FOR_5=0;FOR_5<=9;FOR_5++)
		{
			MS_TIMER(1);
			i2c_writen(0xA0,0XFE,K,TEMP_RP_NO[FOR_5]);
			MS_TIMER(2);
			K++;
		}
	}

	if(D==8)
	{
		K = 26;

		for(FOR_5=0;FOR_5<=9;FOR_5++)
		{
			MS_TIMER(1);
			i2c_writen(0xA0,0XFE,K,VEICHLE_NUMBER[FOR_5]);
			MS_TIMER(2);
			K++;
		}
	}

	if(D==9)
	{
		K = 37;

		MS_TIMER(2);
		i2c_writen(0xA0,0XFE,K,HARSH_ACCEL_LEVEL);
		MS_TIMER(2);
	}

	if(D==10)
	{
		K = 38;

		MS_TIMER(1);
		i2c_writen(0xA0,0XFE,K,HARSH_TURN_LEVEL);
		MS_TIMER(2);
	}

	if(D==11)
	{
		K = 39;

		MS_TIMER(1);
		i2c_writen(0xA0,0XFE,K,HARSH_BRAKE_LEVEL);
		MS_TIMER(2);
	}

	if(D==12)
	{
		K = P_D_L % 100;

		MS_TIMER(1);
		i2c_writen(0xA0,0XFE,40,P_D_L/100); MS_TIMER(2);
		i2c_writen(0xA0,0XFE,41,K/10); MS_TIMER(2);
		i2c_writen(0xA0,0XFE,42,K%10); MS_TIMER(2);
	}

	if(D==13)
	{
		K = HEALTH_ON_DURATON_LEVEL % 100;

		MS_TIMER(1);
		i2c_writen(0xA0,0XFE,43,HEALTH_ON_DURATON_LEVEL/100); MS_TIMER(2);
		i2c_writen(0xA0,0XFE,44,K/10); MS_TIMER(2);
		i2c_writen(0xA0,0XFE,45,K%10); MS_TIMER(2);
	}

	if(D==14)
	{
		K = 46;

		MS_TIMER(1);
		i2c_writen(0xA0,0XFE,K,LOW_BAT_LEVEL);
		MS_TIMER(2);
	}

	if(D==15)
	{
		K = OVER_SPEED % 100;

		MS_TIMER(1);
		i2c_writen(0xA0,0XFE,110,OVER_SPEED/100); MS_TIMER(2);
		i2c_writen(0xA0,0XFE,111,K/10); MS_TIMER(2);
		i2c_writen(0xA0,0XFE,112,K%10); MS_TIMER(2);
	}

	if(D==16)
	{
		K = SLEEP_ON_TIME % 100;

		MS_TIMER(1);
		i2c_writen(0xA0,0XFE,113,SLEEP_ON_TIME/100); MS_TIMER(2);
		i2c_writen(0xA0,0XFE,114,K/10); MS_TIMER(2);
		i2c_writen(0xA0,0XFE,115,K%10); MS_TIMER(2);
	}

	if(D==17)
	{
		K = SLEEP_OFF_TIME % 100;

		MS_TIMER(1);
		i2c_writen(0xA0,0XFE,116,SLEEP_OFF_TIME/100); MS_TIMER(2);
		i2c_writen(0xA0,0XFE,117,K/10); MS_TIMER(2);
		i2c_writen(0xA0,0XFE,118,K%10); MS_TIMER(2);
	}

	if(D==18)
	{
		K = EMGT_TIME % 100;

		MS_TIMER(1);
		i2c_writen(0xA0,0XFE,119,EMGT_TIME/100); MS_TIMER(2);
		i2c_writen(0xA0,0XFE,120,K/10); MS_TIMER(2);
		i2c_writen(0xA0,0XFE,121,K%10); MS_TIMER(2);
	}

	if(D==19)
	{
		K = 0;

		for(FOR_5=0;FOR_5<=16;FOR_5++)
		{
			MS_TIMER(1);
			i2c_writen(0xA0,0XFA,K,IMEI[FOR_5]);
			MS_TIMER(2);
			K++;
		}
	}

	MS_TIMER(100);
}



void GSM_UART_RX(unsigned char UART0_BUFFER)
{
	
	//char QST_CMD_FRAME[8]={'+','Q','S','T','K',':',' ','0'};
//************************************************************************************************************************************************************
//					   GET NMR FROM GSM  QENG: 1,
//************************************************************************************************************************************************************

if(GET_NMR_RX==SET)
{
	
	if(UART0_BUFFER==ENGINEER_MODE_FRAME_2[I[26]] || ENGINEER_MODE_FRAME_2_ACK==SET)
	{
		
		
	if(ENGINEER_MODE_FRAME_2_ACK==CLR)
	{
	I[26]++;
	}	
		
		if(ENGINEER_MODE_FRAME_2_ACK==SET && UART0_BUFFER==',')
		{
			GSM_COMMA_2++;
			N=0;
		}
		
		else if(GSM_COMMA_2==1)
		{
		if(UART0_BUFFER!='x')
		{
                DBM_1[N]=UART0_BUFFER;
		DBM_DATA_LENGTH[1]=N;
                N++;
		}
		else
		{
		DBM_DATA_LENGTH[1]=3;	
		}
		}
		else if(GSM_COMMA_2==7)
		{
                if(UART0_BUFFER!='x')
		{
                LAC_1[N]=UART0_BUFFER;
		LAC_DATA_LENGTH[1]=N;
                N++;
		}
		else{LAC_DATA_LENGTH[1]=3;}
		}
		else if(GSM_COMMA_2==8)
		{
		if(UART0_BUFFER!='x')
		{
                CELL_ID_1[N]=UART0_BUFFER;
		CELL_ID_DATA_LENGTH[1]=N;
                N++;
		}
		else{CELL_ID_DATA_LENGTH[1]=3;}
		}
		
		else if(GSM_COMMA_2==11)
		{
		if(UART0_BUFFER!='x')
		{
                DBM_2[N]=UART0_BUFFER;
                DBM_DATA_LENGTH[2]=N;
		N++;
		}
		else{DBM_DATA_LENGTH[2]=3;}
		}
		else if(GSM_COMMA_2==17)
		{
		if(UART0_BUFFER!='x')
		{
                LAC_2[N]=UART0_BUFFER;
                LAC_DATA_LENGTH[2]=N;
		N++;
		}
		else{LAC_DATA_LENGTH[2]=3;}
		}
		else if(GSM_COMMA_2==18)
		{
                if(UART0_BUFFER!='x')
		{
                CELL_ID_2[N]=UART0_BUFFER;
		CELL_ID_DATA_LENGTH[2]=N;
                N++;
		}
		else{CELL_ID_DATA_LENGTH[2]=3;}
		}
		
		else if(GSM_COMMA_2==21)
		{
		if(UART0_BUFFER!='x')
		{
                DBM_3[N]=UART0_BUFFER;
                DBM_DATA_LENGTH[3]=N;
		N++;
		}
		else{DBM_DATA_LENGTH[3]=3;}
		}
		else if(GSM_COMMA_2==27)
		{
                if(UART0_BUFFER!='x')
		{
                LAC_3[N]=UART0_BUFFER;
		LAC_DATA_LENGTH[3]=N;
                N++;
		}
		else{LAC_DATA_LENGTH[3]=3;}
		}
		else if(GSM_COMMA_2==28)
		{
		if(UART0_BUFFER!='x')
		{
                CELL_ID_3[N]=UART0_BUFFER;
		CELL_ID_DATA_LENGTH[3]=N;
                N++;
		}
		else{CELL_ID_DATA_LENGTH[3]=3;}
		}
		else if(GSM_COMMA_2==31)
		{
		if(UART0_BUFFER!='x')
		{
                DBM_4[N]=UART0_BUFFER;
		DBM_DATA_LENGTH[4]=N;
                N++;
		}
		else{DBM_DATA_LENGTH[4]=3;}
		}
		else if(GSM_COMMA_2==37)
		{
		if(UART0_BUFFER!='x')
		{
                LAC_4[N]=UART0_BUFFER;
		LAC_DATA_LENGTH[4]=N;
                N++;
		}
		else{LAC_DATA_LENGTH[4]=3;}
		}
		
		else if(GSM_COMMA_2==38)
		{
		if(UART0_BUFFER!='x')
		{
                CELL_ID_4[N]=UART0_BUFFER;
		CELL_ID_DATA_LENGTH[4]=N;
                N++;
		}
		else{CELL_ID_DATA_LENGTH[4]=3;}
		}
		
		
		else if(GSM_COMMA_2>=39)
		{
                GSM_COMMA_2=CLR;
                N=CLR;
		ENGINEER_MODE_FRAME_2_ACK=CLR;
		I[26]=CLR;
		}
/*******************************************************************************************/		
                else if(I[26]>=10)
		{
		ENGINEER_MODE_FRAME_2_ACK=SET;
		I[26]=CLR;
		N=CLR;
		GSM_COMMA_2=CLR;
		for(FOR_7=0;FOR_7<=5;FOR_7++)
		{
		DBM_1[FOR_7]=CELL_ID_1[FOR_7]=LAC_1[FOR_7]=DBM_2[FOR_7]=CELL_ID_2[FOR_7]=LAC_2[FOR_7]=DBM_3[FOR_7]=CELL_ID_3[FOR_7]=LAC_3[FOR_7]=DBM_4[FOR_7]=CELL_ID_4[FOR_7]=LAC_4[FOR_7]='0';	
		DBM_DATA_LENGTH[FOR_7]=LAC_DATA_LENGTH[FOR_7]=CELL_ID_DATA_LENGTH[FOR_7]=0;
		}
		}
		
		
	}
else{I[26]=0;}		
}	

	
//***********************************************************************************************************************************************************
//  				 GSM REGISTRAION IN NETWORK
//************************************************************************************************************************************************************
	if(GSM_NW_REG_CHECK==SET)
	{
	if(UART0_BUFFER==GSM_NW_REG[I[1]] || GSM_REG_ROAMING==1)
	{
		     if(GSM_REG_ROAMING==CLR){I[1]++;}
		
		else if(GSM_REG_ROAMING==1)
		{
		if(UART0_BUFFER=='1' || UART0_BUFFER=='5'){I[1]=0;GSM_REG=1;GSM_REG_ROAMING=0;}
		else{I[1]=0;GSM_REG=2;GSM_REG_ROAMING=0;}
		}
			
		if(I[1]>=8){GSM_REG_ROAMING=1;}
	}
	else{I[1]=0;}
	}
//************************************************************************************************************************************************************
//  				 GPRS REGISTRAION IN NETWORK
//************************************************************************************************************************************************************
	if(GPRS_REG_CHECK==SET)
	{
	if(UART0_BUFFER==GPRS_NW_REG[I[2]] || GPRS_REG_ROAMING==1)
	{
		     if(GPRS_REG_ROAMING==CLR){I[2]++;}
		else if(GPRS_REG_ROAMING==SET)
		{
		if(UART0_BUFFER=='1' || UART0_BUFFER=='5'){I[2]=0;GPRS_REG=1;GPRS_REG_ROAMING=0;}
		else{I[2]=0;GPRS_REG=2;GSM_REG_ROAMING=0;}
		}
		
		if(I[2]>=9){GPRS_REG_ROAMING=1;}
	}
	else{I[2]=0;}
	}

//************************************************************************************************************************************************************
//  				 OK ACK RECIVE FROM GSM MODULE
//************************************************************************************************************************************************************
	
	if(UART0_BUFFER==OK_ACK[I[3]])
	{
		I[3]++;
		if(I[3]>=2){I[3]=0;ACK=1;}
	}
	else{I[3]=0;}
///*************************************************************************************************************************************************************/

//				ALREADY CONNECT?? //CONNECT_FAIL_ACK[12]

///*************************************************************************************************************************************************************/

if(UART0_BUFFER==ALREADY_CONNECT_ACK[I[75]])
	{
		I[75]++;
		
		if(I[75]>=15)
		{
			I[75]=0;
		
		ALREADY_CONNECT=SET;
						
		}
				
				
	}
	else{I[75]=0;}	
	
	

///*************************************************************************************************************************************************************/

//				ALREADY CONNECT?? //CONNECT_FAIL_ACK[12]

///*************************************************************************************************************************************************************/

if(UART0_BUFFER==CONNECT_FAIL_ACK[I[76]])
	{
		I[76]++;
		
		if(I[76]>=12)
		{
			I[75]=0;
		
		CONNECT_FAIL=SET;
						
		}
				
				
	}
	else{I[76]=0;}	
	
	/************************************************************************************************************************************************************
  				 ALREADY_CONNECT CODE RECIVE FROM GSM MODULE  //VODAFONE_ACK[15]
	************************************************************************************************************************************************************/
    
	if(UART0_BUFFER==VODAFONE_ACK[I[77]])
	{
		I[77]++;
		if(I[77]>=15)
		{
		I[77]=0;
		BSNL_CONNECT=1;
		}
	}
	else{I[77]=0;}
	/************************************************************************************************************************************************************
  				 ALREADY_CONNECT CODE RECIVE FROM GSM MODULE  //VODAFONE_ACK[15]
	************************************************************************************************************************************************************/
    
	if(UART0_BUFFER==VODAFONE_ACK_V[I[79]])
	{
		I[79]++;
		if(I[79]>=15)
		{
		I[79]=0;
		BSNL_CONNECT=1;
		}
	}
	else{I[79]=0;}
	

	
//************************************************************************************************************************************************************
//  				 ERROR CODE RECIVE FROM GSM MODULE
//************************************************************************************************************************************************************
    
	if(UART0_BUFFER==ERROR_ACK[I[4]])
	{
		I[4]++;
		if(I[4]>=5)
		{
		I[4]=0;ERROR_OCCURED=1;
		}
	}
	else{I[4]=0;}

//************************************************************************************************************************************************************
//					HTTP CONNECT ACK							
//************************************************************************************************************************************************************/
	
	if(UART0_BUFFER==CONNECT_ACK[I[7]])
	{
		I[7]++;
		if(I[7]>=7){I[7]=0;GPRS_CONNECTED=ON;}
	}
	else{I[7]=0;}
//************************************************************************************************************************************************************
//					GET SIGNAL STRENGTH						
//************************************************************************************************************************************************************/
	if(GET_SIGNAL_STRENGTH_CHECK==SET)
	{
	if(UART0_BUFFER==SIGNAL_STRENGTH_ACK[I[8]] || SS_DATA_RX>=1)
	{
		if(SS_DATA_RX==CLR){I[8]++;}
		     if(SS_DATA_RX==1)
		     {
		     dBm=((0X0F&UART0_BUFFER)*10);
		     SS_DATA_RX=2;
		     }
		else if(SS_DATA_RX==2)
		{
		dBm=(dBm+(0X0F&UART0_BUFFER));
		GET_SS=1;
		SS_DATA_RX=0;
		I[8]=0;
		}    
		else if(I[8]>=5){SS_DATA_RX=1;}
		
	}
	else{I[8]=0;}
	}
//************************************************************************************************************************************************************
//					INTERNET DISCONNECT ACK							
//************************************************************************************************************************************************************/

	if(UART0_BUFFER==NW_DIS_CONNECT[I[9]])
	{
		I[9]++;
		if(I[9]>=9){I[9]=0;INTERNET_CONNECTED=OFF;DISCONNECT=ON;}
	}
	else{I[9]=0;}

//************************************************************************************************************************************************************
//					        CPIN READY								//
//************************************************************************************************************************************************************/
        if(CPIN_READY_CHECK==SET)
	{
	if(UART0_BUFFER==CPIN_READY[I[10]])
	{
		I[10]++;
		if(I[10]>=11){I[10]=0;CPIN=ON;}
	}
	else{I[10]=0;}
	}


//************************************************************************************************************************************************************
//					        HTTP RESPONSE FAIL
//************************************************************************************************************************************************************/

	if(UART0_BUFFER==HTTP_RESPONSE_FAIL[I[13]])
	{
		I[13]++;
		if(I[13]>=4){I[13]=0;INTERNET_CONNECTED=OFF;DISCONNECT=ON;}
	}
	else{I[13]=0;}
//************************************************************************************************************************************************************
//					     IGNITION CTRL									 
//************************************************************************************************************************************************************/

	if(UART0_BUFFER==IGNITION_CTRL[I[14]] || IGNITION_CTRL_RX>=1)
	{
		I[14]++;
		
		//if(IGNITION_CTRL_RX==1){if(UART0_BUFFER=='1'){IGNITION_CONTROL_STATE=ON;}else{IGNITION_CONTROL_STATE=OFF;}IGNITION_CTRL_RX=0;I[14]=0;}
		if(IGNITION_CTRL_RX==1){if(UART0_BUFFER=='1'){IGNITION_CONTROL=ON;}else{IGNITION_CONTROL=OFF;}IGNITION_CTRL_RX=0;I[14]=0;}
		else if(I[14]>=4){IGNITION_CTRL_RX=1;}
		
	}
	else{I[14]=0;}
 	

///************************************************************************************************************************************************************
//					GET NETWORK NAME				    				// 
///************************************************************************************************************************************************************/

        if(NETWORK_NAME_RX==ON)
	{
	if(UART0_BUFFER==NW_NAME_ACK[I[16]] || NW_NAME_RX>=1)
	{
		
		if(NW_NAME_RX==CLR){I[16]++;}
		
		     if(NW_NAME_RX==1)
		     {
		     if(UART0_BUFFER=='"')
		     {
		     NW_NAME_RX=2;t=0;
		     NETWORK_NAME[0]=NETWORK_NAME[1]=NETWORK_NAME[2]=NETWORK_NAME[3]=NETWORK_NAME[4]=NETWORK_NAME[5]=NETWORK_NAME[6]=NETWORK_NAME[7]='0';
		     }
		     }
	        //else if(NW_NAME_RX==2 && UART0_BUFFER=='"'){NW_NAME_RX=0;}
		else if(NW_NAME_RX==2 && UART0_BUFFER==' ')
		{
		NW_NAME_RX=0;
		}
		else if(NW_NAME_RX==2)
		{
		NETWORK_NAME[t]=UART0_BUFFER;
		t++;
		}
		else if(I[16]>=5)
		{
		I[16]=0;
		NW_NAME_RX=1;
		t=0;
		}
	}
	else{I[16]=0;NW_NAME_RX=0;}
	}
	
///************************************************************************************************************************************************************
//					GET IMEI ACK				    				 
///************************************************************************************************************************************************************/

	if(IMEI_RX==ON){
	if(UART0_BUFFER==IMEI_ACK[I[17]] || IMEI_ACK_RX>=1)
	{
		I[17]++;
		
		///*GREEN_LED=ON*/;
		     
	             if(IMEI_ACK_RX==1)
		     {
		     IMEI[t]=UART0_BUFFER;t++;
		     }
		     
		else if(I[17]>=9){I[17]=0;t=1;IMEI_ACK_RX=1;}
		     if(t>=16)
		     {
		     IMEI_ACK_RX=0;t=1;
		     }
		
	}
	
	else{I[17]=0;}
	}
///************************************************************************************************************************************************************
//					GET HTTP FILE DOWNLOAD ACK				    				
///************************************************************************************************************************************************************/
if(FIRMWARE_UPDATE==1){	
	if(UART0_BUFFER==HTTP_DOWNLOAD[I[18]])
	{
		I[18]++;
		if(I[18]>=8){I[18]=0;HTTP_DOWNLOAD_ACK=1;}
	}
	
	else{I[18]=0;}
}

///************************************************************************************************************************************************************
//					GET FILE HANDLE ADDRESS				    				
///************************************************************************************************************************************************************/

	if(FIRMWARE_DOWNLOADED==ON){
	if(UART0_BUFFER==FTP_ADDRESS_ACK[I[19]] || FTP_ACK>=1)
	{
		I[19]++;
		     
	             if(FTP_ACK==1){FTP_ADDRESS[t]=UART0_BUFFER;t++;}
		     
		else if(I[19]>=8){I[19]=0;t=1;FTP_ACK=1;}
		     if(t>=7){FTP_ACK=0;t=1;FTP_DOWNLOAD_ACK=1;}
		
	}
	else{I[19]=0;}
	}
	
///**********************************************************************************************************/	
/************************************************************************************************************************************************************
					   DEVICE RESTART ON/OFF
/************************************************************************************************************************************************************/

	if(UART0_BUFFER==DEVICE_RESTART_ACK[I[41]] || DEVICE_RESTART_RX_1>=1)
	{
		I[41]++;
		if(DEVICE_RESTART_RX_1==1)
		{
		if(UART0_BUFFER=='1')
		{
		WATCHDOG_ON();
		WATCH_DOG=NONE;
		MS_TIMER(900);}
		
		DEVICE_RESTART_RX_1=0;I[41]=0;}
		else if(I[41]>=12)
		{
			//I[41]=0;
		DEVICE_RESTART_RX_1=1;
		}
		
		}
	else{I[41]=0;DEVICE_RESTART_RX_1=CLR;}	
///************************************************************************************************************************************************************
//					GET FILE FROM M95 RAM				    				 
///************************************************************************************************************************************************************/

	if(FIRMWARE_DOWNLOADED==ON){
	if(UART0_BUFFER==FILE_DOWNLOAD_ACK[I[20]] || FILE_ACK>=1)
	{
		I[20]++;
		
		      	if(FILE_ACK==1 && FILE_ADDR==1 && UART0_BUFFER=='#')
			{
			FILE_ACK=0;FILE_ADDR=0;
			while(AD<129){FILE[AD]=0x1A;AD++;}
			STOP_FILE_READING=ON;
			}
		   else if(FILE_ACK==1 && FILE_ADDR==1)
				   {
		      		   if(FLAG==0)
			      	   {
				   FLAG=1;
								   
				   if(UART0_BUFFER>=48 && UART0_BUFFER<=57)
				   {
				   UART0_BUFFER=UART0_BUFFER&0x0F;
				   }
				   else if ((UART0_BUFFER>=97 && UART0_BUFFER<=102)||(UART0_BUFFER>=65 && UART0_BUFFER<=70))
				   {
					UART0_BUFFER=UART0_BUFFER&0x0F; 
					UART0_BUFFER=(UART0_BUFFER+9);
				   }
				   
				   TEMP_3=(UART0_BUFFER<<4);
				   }
			      else if(FLAG==1)
			           {
			           FLAG=0;
			      	   if(UART0_BUFFER>=48 && UART0_BUFFER<=57)
				   {
				   UART0_BUFFER=UART0_BUFFER&0x0F;
				   TEMP_3 = UART0_BUFFER | TEMP_3;
				  				   
				   }
				   if ((UART0_BUFFER>=97 && UART0_BUFFER<=102)||(UART0_BUFFER>=65 && UART0_BUFFER<=70))
				   {
					UART0_BUFFER=UART0_BUFFER&0x0F; 
					UART0_BUFFER=UART0_BUFFER+9;
					TEMP_3 = UART0_BUFFER | TEMP_3;
					
				   }
				   FILE[AD]=TEMP_3;
					AD++;
				   }
				   }
		      else if(FILE_ACK==1)
		      {
			      if(UART0_BUFFER=='\n'){FILE_ADDR=1;}
		      }
				   
			           
		     
		      
		else if(I[20]>=8){I[20]=0;AD=1;FILE_ACK=1;}
		
		     if(AD>=129){/*GREEN_LED=ON*/;FILE_ACK=0;FILE_ADDR=0;AD=1;FILE_DOWNLOAD=1;}
		
	}
	
	else{I[20]=0;}
	}	


/////************************************************************************************************************************************************************
////					     PANIC ALERT ON/OFF
/////************************************************************************************************************************************************************/

	if(UART0_BUFFER==PANIC_CTRL[I[22]] || PANIC_CTRL_RX>=1)
	{
		I[22]++;
		if(PANIC_CTRL_RX==1){if(UART0_BUFFER=='1'){PANIC_CONTROL_STATE=ON;}else{PANIC_CONTROL_STATE=OFF;}PANIC_CTRL_RX=0;I[22]=0;}
		else if(I[22]>=4){PANIC_CTRL_RX=1;}
		
	}
	else{I[22]=0;}

	
/////************************************************************************************************************************************************************
////					   FIRMWARE  UPDATE ON/OFF
/////************************************************************************************************************************************************************/

	if(UART0_BUFFER==FIRM_UPDATE_CTRL[I[23]] || FIRM_UPDATE_CTRL_RX>=1)
	{
		I[23]++;
		if(FIRM_UPDATE_CTRL_RX==1){if(UART0_BUFFER=='1'){FIRM_UPDATE_CONTROL_STATE=ON;}else{FIRM_UPDATE_CONTROL_STATE=OFF;}FIRM_UPDATE_CTRL_RX=0;I[23]=0;}
		else if(I[23]>=3){FIRM_UPDATE_CTRL_RX=1;}
		
	}
	else{I[23]=0;}	


///************************************************************************************************************************************************************
//					   GET MCC MNC LAC,CELL-ID FROM GSM  QENG: 0,
///************************************************************************************************************************************************************/
if(GET_MCC_MNC_LAC_CELL_ID_RX==SET)
{
	if(UART0_BUFFER==ENGINEER_MODE_FRAME_1[I[25]] || ENGINEER_MODE_FRAME_1_ACK==SET)
	{
		I[25]++;
		
		if(ENGINEER_MODE_FRAME_1_ACK==SET && UART0_BUFFER==',')
		{
			GSM_COMMA++;
			P=0;
		}
		
		else if(GSM_COMMA==2)
		{
			MNC[P]=UART0_BUFFER;
			MNC_DATA_LENGTH=P;
			P++;
			  
		}
		else if(GSM_COMMA==3)
		{
			LAC[P]=UART0_BUFFER;
			LAC_DATA_LENGTH_0=P;
			P++;
			  
		}
		else if(GSM_COMMA==4)
		{
			CELL_ID[P]=UART0_BUFFER;
			CELL_ID_DATA_LENGTH_0=P;
			P++;
			  
		}
		
		
		else if(GSM_COMMA>=5)
		{
		ENGINEER_MODE_FRAME_1_ACK=CLR;
		MCC_MNC_LAC_CELL_ID_LENGTH=P;
		P=CLR;
		I[25]=CLR;
		GSM_COMMA=CLR;
		}
		
		     
		     else if(I[25]>=7)
		     {
		     ENGINEER_MODE_FRAME_1_ACK=SET;
		     I[25]=CLR;
		     P=CLR;
		     }
		     
		
	}
	else{I[25]=0;}	
}

///*************************************************************************************************************************************************************/

//				CHECK NEW SMS 

///*************************************************************************************************************************************************************/
if(UART0_BUFFER==NEW_SMS_FRAME[I[28]] || NEW_SMS_RX_FRAME_RX>=1)
	{
		I[28]++;
		
		if(NEW_SMS_RX_FRAME_RX==SET && UART0_BUFFER=='\n' || NEW_SMS_RX_FRAME_RX==SET && UART0_BUFFER=='\r' || NEW_SMS_RX_FRAME_RX==SET && UART0_BUFFER==0x00)
		{
			NEW_SMS_RX_FRAME_RX=CLR;
			NEW_SMS++;
			I[28]=CLR;
		}
		if(NEW_SMS_RX_FRAME_RX==SET)
		{
			if(I[28]==1)
			{
				NEW_SMS_INBOX_ADDRESS[NEW_SMS]=(0x0F & UART0_BUFFER);
			}
				else if(I[28]==2){NEW_SMS_INBOX_ADDRESS[NEW_SMS]=NEW_SMS_INBOX_ADDRESS[NEW_SMS]*10;NEW_SMS_INBOX_ADDRESS[NEW_SMS]=NEW_SMS_INBOX_ADDRESS[NEW_SMS]+(0x0F & UART0_BUFFER);}
			}
		
		if(I[28]>=11)
		{
			NEW_SMS_RX_FRAME_RX=SET;
			I[28]=0;
		}
		
	}
	else
	{
		I[28]=0;
		NEW_SMS_RX_FRAME_RX=CLR;
	}	
///*************************************************************************************************************************************************************/
//				 GET PHONE NUMBER OF SENDER 
///*************************************************************************************************************************************************************/
if(UART0_BUFFER==PHONE_NUMBER_OF_SENDER_FRAME[I[29]] || PHONE_NUMBER_OF_SENDER_RX>=1)
	{
		I[29]++;
		
		if(PHONE_NUMBER_OF_SENDER_RX==SET && UART0_BUFFER=='"' )
		{
		PHONE_NUMBER_OF_SENDER_RX=CLR;
		I[29]=CLR;
		}
		if(PHONE_NUMBER_OF_SENDER_RX==SET)
		{
		     PHONE_NUMBER_OF_SENDER[G]=UART0_BUFFER;
		     G++;
                }
		
		if(I[29]>=23)
		{
		PHONE_NUMBER_OF_SENDER_RX=SET;
		I[29]=0;
		}
		
	}
	else{I[29]=0;PHONE_NUMBER_OF_SENDER_RX=CLR;}	
	
///*************************************************************************************************************************************************************/

//				GET SMS COMMAND FOR IMEI

///*************************************************************************************************************************************************************/
if(UART0_BUFFER==GET_IMEI_SMS_CMD[I[30]] || GET_IMEI_SMS_CMD_RX>=1)
{
		I[30]++;
		
		if(GET_IMEI_SMS_CMD_RX==1 && UART0_BUFFER==SMS_MOBILE_NO[6])
		{
                GET_IMEI_SMS_CMD_RX=2;
		}
		else if(GET_IMEI_SMS_CMD_RX==2 && UART0_BUFFER==SMS_MOBILE_NO[7])
		{
                GET_IMEI_SMS_CMD_RX=3;
		}
		else if(GET_IMEI_SMS_CMD_RX==3 && UART0_BUFFER==SMS_MOBILE_NO[8])
		{
                GET_IMEI_SMS_CMD_RX=4;
		}
		else if(GET_IMEI_SMS_CMD_RX==4 && UART0_BUFFER==SMS_MOBILE_NO[9])
		{
                GET_IMEI_SMS_CMD_RX=CLR;
		SEND_IMEI=SET;
		SMS_PIN_WRONG=CLR;
		}
		else if(GET_IMEI_SMS_CMD_RX>=1)
		{
		GET_IMEI_SMS_CMD_RX=CLR;
		SMS_PIN_WRONG=SET;
		}
		if(I[30]>=13)
		{
		GET_IMEI_SMS_CMD_RX=SET;
		I[30]=0;
		}
		
		
}

else
{
	I[30]=0;GET_IMEI_SMS_CMD_RX=CLR;
}	

///******************************************************************************************************
// RESET FRAME
///******************************************************************************************************

if (UART0_BUFFER == DEVICE_RESET_CMD_FRAME[I[31]] || DEVICE_RESET_CMD_FRAME_RX == SET)
{
    if (DEVICE_RESET_CMD_FRAME_RX == CLR)
    {
        I[31]++;   // increment only while matching frame
    }

    if (DEVICE_RESET_CMD_FRAME_RX == SET)
    {
        PIN_CHECK(UART0_BUFFER, 1);

        if (DEVICE_RESET_CMD == SET || SMS_PIN_WRONG == SET)
        {
            DEVICE_RESET_CMD_FRAME_RX = CLR;
        }
    }

    if (I[31] >= 14)
    {
        DEVICE_RESET_CMD_FRAME_RX = SET;
        I[31] = 0;
        PIN_COUNT_CHECK = 0;
    }
}
else
{
    I[31] = 0;
    DEVICE_RESET_CMD_FRAME_RX = CLR;
}


///************************************************************************************************************************************************************
//GET SETTINGS FROM SMS
///************************************************************************************************************************************************************/
	if(UART0_BUFFER==GET_SMS_FRAME[I[55]])
	{
		
			I[55]++;
		
			
			if(I[55]>=12)
			{
			GET_SMS_CMD=SET;
			I[55]=0;
			}
			
		}
			else{I[55]=0;
		}	


///************************************************************************************************************************************************************
//GET VERSION FROM SMS
///************************************************************************************************************************************************************/
if(UART0_BUFFER == GET_VERSION_FRAME[I[56]])
{
    I[56]++;
    
    if(I[56]>=12)  // or whatever length your version command string is
    {
        VERSION_CMD_SET = SET;
        I[56]=0;
    }
}
else
{
	I[56]=0;
}

///************************************************************************************************************************************************************
//GET VLT IMEI PH(0669) FROM SMS
///************************************************************************************************************************************************************/
if(UART0_BUFFER == GET_VLT_IMEI_PH_FRAME[I[81]])
{
    I[81]++;
    
    if(I[81] >= 18)  // "GET VLT IMEI 0669 " = 18 characters
    {
        GET_VLT_IMEI_PH_CMD = SET;
        I[81] = 0;
    }
}
else
{
    I[81] = 0;
}

///************************************************************************************************************************************************************
//SET HARSH ACCELERATION LEVEL
///************************************************************************************************************************************************************/
if(UART0_BUFFER == SET_HACL_FRAME[I[82]])  // Detects "SET HACL IMEI 2202="
{
    I[82]++;
    
    if(I[82] >= 19)  // Full command matched
    {
        HARSH_ACCEL_CMD = SET;  // SETS THE FLAG
        I[82] = 0;
        VV = 0;  // Reset counter for value
    }
}
else if(HARSH_ACCEL_CMD == SET)  // Reading the value part (e.g., "30")
{
    if(UART0_BUFFER == '#' || UART0_BUFFER == 0x00 || UART0_BUFFER == '\r' || UART0_BUFFER == '\n')
    {
        int i=0;
        // End of command - process the value
        // DON'T clear the flag here! Let main loop handle it.
        // HARSH_ACCEL_CMD = CLR;  ← REMOVE THIS LINE
        
        // Convert TEMP_HACL_VALUE to number
        HARSH_ACCEL_LEVEL = 0;
        for(i=0; i<VV; i++)
        {
            HARSH_ACCEL_LEVEL = (HARSH_ACCEL_LEVEL * 10) + (TEMP_HACL_VALUE[i] - '0');
        }
        
        // Validate (1-3 range)
        // if(HARSH_ACCEL_LEVEL > 3) HARSH_ACCEL_LEVEL = 3;
        // if(HARSH_ACCEL_LEVEL < 1) HARSH_ACCEL_LEVEL = 1;
        
        // Flag remains SET for main loop to process
    }
    else
    {
        TEMP_HACL_VALUE[VV] = UART0_BUFFER;  // Store digits
        VV++;
        if(VV >= 3) VV = 2;  // Prevent overflow (max 2 digits)
    }
}
else
{
    I[82] = 0;
}


///************************************************************************************************************************************************************
//SET HARSH BRAKE LEVEL (REUSING TEMP_HACL_VALUE BUFFER)
///************************************************************************************************************************************************************/
if(UART0_BUFFER == SET_HBRK_FRAME[I[83]])  // Use I[83] for HBRK (different index)
{
    I[83]++;
    
    if(I[83] >= 19)  // Full command matched "SET HBRK IMEI 2202=" (19 chars)
    {
        HARSH_BRAKE_CMD_RX = 1;  // SETS THE FLAG
        I[83] = 0;
        VV = 0;  // Reset counter for value (reusing VV)
    }
}
else if(HARSH_BRAKE_CMD_RX == 1)  // Reading the value part (e.g., "20")
{
    if(UART0_BUFFER == '#' || UART0_BUFFER == 0x00 || UART0_BUFFER == '\r' || UART0_BUFFER == '\n')
    {
        int i=0;
        // End of command - process the value
        // DON'T clear the flag here! Let main loop handle it.
        
        // Convert TEMP_HACL_VALUE to number (reusing buffer)
        HARSH_BRAKE_LEVEL = 0;
        for(i=0; i<VV; i++)
        {
            HARSH_BRAKE_LEVEL = (HARSH_BRAKE_LEVEL * 10) + (TEMP_HACL_VALUE[i] - '0');
        }
        
        // Validate (1-3 range based on your existing code)
        //if(HARSH_BRAKE_LEVEL > 3) HARSH_BRAKE_LEVEL = 3;
        //if(HARSH_BRAKE_LEVEL < 1) HARSH_BRAKE_LEVEL = 1;
        
        // Flag remains SET for main loop to process
    }
    else
    {
        TEMP_HACL_VALUE[VV] = UART0_BUFFER;  // Store digits (reusing buffer)
        VV++;
        if(VV >= 3) VV = 2;  // Prevent overflow (max 2 digits)
    }
}
else
{
	I[83] = 0;
}


///************************************************************************************************************************************************************
//SET HARSH TURN LEVEL (REUSING TEMP_HACL_VALUE BUFFER)
///************************************************************************************************************************************************************/
if(UART0_BUFFER == SET_HTRN_FRAME[I[84]])  // Use I[84] for HTRN
{
    I[84]++;
    
    if(I[84] >= 19)  // Full command matched "SET HTRN IMEI 2202="
    {
        HARSH_TURN_CMD_RX = 1;  // SETS THE FLAG
        I[84] = 0;
        VV = 0;  // Reset counter for value
    }
}
else if(HARSH_TURN_CMD_RX == 1)  // Reading value (e.g., "30")
{
    if(UART0_BUFFER == '#' || UART0_BUFFER == 0x00 || UART0_BUFFER == '\r' || UART0_BUFFER == '\n')
    {
        int i=0;

        // Convert TEMP_HACL_VALUE to number
        HARSH_TURN_LEVEL = 0;

        for(i=0; i<VV; i++)
        {
            HARSH_TURN_LEVEL = (HARSH_TURN_LEVEL * 10) + (TEMP_HACL_VALUE[i] - '0');
        }

        HARSH_TURN_CMD = SET;   // ready for main loop
    }
    else
    {
        TEMP_HACL_VALUE[VV] = UART0_BUFFER;  // reuse same buffer
        VV++;

        if(VV >= 3) VV = 2;  // overflow protection
    }
}
else
{
	I[84] = 0;
}

///************************************************************************************************************************************************************
//SET LOW BATTERY ALERT LEVEL (REUSING TEMP_HACL_VALUE BUFFER)
///************************************************************************************************************************************************************/
if(UART0_BUFFER == SET_LBAT_FRAME[I[85]])
{
    I[85]++;
    
    if(I[85] >= 19)   // "SET LBAT IMEI 2202="
    {
        LOW_BAT_LEVEL_RX = 1;   // SET RX FLAG
        I[85] = 0;
        VV = 0;
    }
}
else if(LOW_BAT_LEVEL_RX == 1)
{
    if(UART0_BUFFER == '#' || UART0_BUFFER == 0x00 || UART0_BUFFER == '\r' || UART0_BUFFER == '\n')
    {
        int i=0;
        LOW_BAT_LEVEL = 0;

        // SAFETY: Only process if VV is reasonable (1 digit for LBAT)
        if(VV > 2) VV = 2;  // Max 2 digits for safety
        
        for(i=0; i<VV; i++)
        {
            // Validate each character is a digit
            if(TEMP_HACL_VALUE[i] >= '0' && TEMP_HACL_VALUE[i] <= '9')
            {
                LOW_BAT_LEVEL = (LOW_BAT_LEVEL * 10) + (TEMP_HACL_VALUE[i] - '0');
            }
        }

        // VALIDATE RANGE 1-9
        if(LOW_BAT_LEVEL < 1) LOW_BAT_LEVEL = 1;
        if(LOW_BAT_LEVEL > 9) LOW_BAT_LEVEL = 9;

        // DEBUG: Check if we got correct value
        // If LOW_BAT_LEVEL is not 3, then VV or buffer is corrupted

        LOW_BAT_LEVEL_CMD = SET;
        VV = 0;
    }
    else
    {
        if(VV < 3)  // Only store if within bounds
        {
            TEMP_HACL_VALUE[VV] = UART0_BUFFER;
            VV++;
        }
    }
}
else
{
	I[85] = 0;
}

///******************************************************************************************************
// HEALTH DURATION FRAME - "SET HPET IMEI "
///******************************************************************************************************

if (UART0_BUFFER == SET_HEALTH_FRAME[I[87]] || HEALTH_CMD_FRAME_RX == SET)
{
	int i=0;
    if (HEALTH_CMD_FRAME_RX == CLR)
    {
        I[87]++;   // increment only while matching frame "SET HPET IMEI "
    }

    if (HEALTH_CMD_FRAME_RX == SET)
    {
        // PIN verification phase - expecting "2202"
        PIN_CHECK(UART0_BUFFER, 14);  // z=14 for health duration

        if (HEALTH_ON_DURATON_CMD == SET)
        {
            // PIN verified successfully, now move to value collection
            HEALTH_CMD_FRAME_RX = 2;  // Move to value collection state
            VV = 0;  // Reset value counter
        }
        else if (SMS_PIN_WRONG == SET)
        {
            // PIN wrong - reset everything
            HEALTH_CMD_FRAME_RX = CLR;
            SMS_PIN_WRONG = CLR;
            I[87] = 0;
            VV = 0;
        }
    }
    else if (HEALTH_CMD_FRAME_RX == 2)  // Value collection state
    {
        // Collect the value after "=" (e.g., "2")
        if (UART0_BUFFER == '=')  // Skip the '=' character
        {
            // Just ignore, value starts after '='
        }
        else if (UART0_BUFFER == '#' || UART0_BUFFER == '\r' || UART0_BUFFER == '\n' || UART0_BUFFER == 0x00)
        {
            // End of value - convert to number
            HEALTH_ON_DURATON_LEVEL = 0;
            for( i=0; i<VV; i++)
            {
                HEALTH_ON_DURATON_LEVEL = (HEALTH_ON_DURATON_LEVEL * 10) + (TEMP_HACL_VALUE[i] - '0');
            }
            
            // Validate range (1-999 as per your EEPROM)
            if(HEALTH_ON_DURATON_LEVEL < 1) HEALTH_ON_DURATON_LEVEL = 1;
            if(HEALTH_ON_DURATON_LEVEL > 999) HEALTH_ON_DURATON_LEVEL = 999;
            
            // Reset state machine
            HEALTH_CMD_FRAME_RX = CLR;
            I[87] = 0;
            VV = 0;
            
            // HEALTH_ON_DURATON_CMD is already SET by PIN_CHECK
            // It will be processed in NEW_SMS_READ()
        }
        else
        {
            // Store digit in TEMP_HACL_VALUE (reusing your existing buffer)
            TEMP_HACL_VALUE[VV] = UART0_BUFFER;
            VV++;
            if(VV >= 4) VV = 3;  // Max 3 digits for 1-999 range
        }
    }

    // Check if we've received the full "SET HPET IMEI " frame (14 characters?)
    // Count the characters in your SET_HEALTH_FRAME
    if (I[87] >= 14)  // Adjust this number based on your frame length
    {
        HEALTH_CMD_FRAME_RX = SET;  // Frame detected, now expect PIN
        I[87] = 0;
        PIN_COUNT_CHECK = 0;  // Reset PIN counter for new PIN entry
    }
}
else
{
    I[87] = 0;
    HEALTH_CMD_FRAME_RX = CLR;
    VV = 0;  // Reset value counter on mismatch
}




///*********************************************************************************************************/
if(UART0_BUFFER==GET_ACT_MESSAGE[I[67]])
{
		I[67]++;
		
		if(I[67]>=5)
		{
		ACTIVATION_CMD=SET;
		I[67]=0;
		}
		
}
	else{I[67]=0;}		
///*********************************************************************************************************/
if(UART0_BUFFER==GET_HEALTH_MESSAGE_FRAME[I[68]])
{
		I[68]++;
		if(I[68]>=5)
		{
		HEALTH_CMD2=SET;
		I[68]=0;
		}
		
}
else{I[68]=0;}		


	


///*************************************************************************************************************************************************************/

//				SET PRIMARY NETWORK COMMAND SMS // IDEA P

///*************************************************************************************************************************************************************/
if(UART0_BUFFER==PNET_CMD_FRAME[I[69]] || PNET_CMD_FRAME_RX>=1)
	{
		I[69]++;
		
		if(PNET_CMD_FRAME_RX==1 && UART0_BUFFER==IMEI[12])
		{
                PNET_CMD_FRAME_RX=2;
		}
		else if( PNET_CMD_FRAME_RX==2 && UART0_BUFFER==IMEI[13])
		{
                PNET_CMD_FRAME_RX=3;
		}
		else if( PNET_CMD_FRAME_RX==3 && UART0_BUFFER==IMEI[14])
		{
                PNET_CMD_FRAME_RX=4;
		}
		else if(PNET_CMD_FRAME_RX==4 && UART0_BUFFER==IMEI[15])
		{
                PNET_CMD_FRAME_RX=CLR;
		PNET_CMD_REPLY=SET;
		SMS_PIN_WRONG=CLR;
		}
		else if( PNET_CMD_FRAME_RX>=1 )
		{
		PNET_CMD_FRAME_RX=CLR;
		SMS_PIN_WRONG=SET;
		}
		
		if(I[69]>=9)
		{
		PNET_CMD_FRAME_RX=SET;
		I[69]=0;
		}
		
	}
	else{I[69]=0;PNET_CMD_FRAME_RX=CLR;}	

///*************************************************************************************************************************************************************/

//				SET SECONDARY NETWORK COMMAND SMS // BSNL F

///*************************************************************************************************************************************************************/
if(UART0_BUFFER==SNET_CMD_FRAME[I[70]] || SNET_CMD_FRAME_RX>=1)
	{
		I[70]++;
		
		if(SNET_CMD_FRAME_RX==1 && UART0_BUFFER==IMEI[12])
		{
                SNET_CMD_FRAME_RX=2;
		}
		else if( SNET_CMD_FRAME_RX==2 && UART0_BUFFER==IMEI[13])
		{
                SNET_CMD_FRAME_RX=3;
		}
		else if( SNET_CMD_FRAME_RX==3 && UART0_BUFFER==IMEI[14])
		{
                SNET_CMD_FRAME_RX=4;
		}
		else if(SNET_CMD_FRAME_RX==4 && UART0_BUFFER==IMEI[15])
		{
                SNET_CMD_FRAME_RX=CLR;
		SNET_CMD_REPLY=SET;
		SMS_PIN_WRONG=CLR;
		}
		else if( SNET_CMD_FRAME_RX>=1 )
		{
		SNET_CMD_FRAME_RX=CLR;
		SMS_PIN_WRONG=SET;
		}
		
		if(I[70]>=9)
		{
		SNET_CMD_FRAME_RX=SET;
		I[70]=0;
		}
		
	}
	else{I[70]=0;SNET_CMD_FRAME_RX=CLR;}	






///*************************************************************************************************************************************************************/

//				AUTO NETWORK COMMAND SMS // Idea 0

///*************************************************************************************************************************************************************/
if(UART0_BUFFER==NWA_CMD_FRAME[I[71]])
	{
		I[71]++;
		
					
		if(I[71]>=9)
		{
		NWP_CMD_SET=SET;
		I[71]=0;
		}
		
	}
	else{I[71]=0;}	
	///*************************************************************************************************************************************************************/

//				AUTO NETWORK COMMAND SMS // Idea 0

///*************************************************************************************************************************************************************/
if(UART0_BUFFER==NWI_CMD_FRAME[I[78]])
	{
		I[78]++;
		
					
		if(I[78]>=9)
		{
		NWP_CMD_SET=SET;
		I[78]=0;
		}
		
	}
	else{I[78]=0;}	
	
		///*************************************************************************************************************************************************************/

//				GPS CLEAR RESET

///*************************************************************************************************************************************************************/
if(UART0_BUFFER==GET_GPS_CLEAR_S_FRAME[I[80]] || DEVICE_RESTART_RX>=1)
	{
		I[80]++;
		if(DEVICE_RESTART_RX==1){if(UART0_BUFFER=='1')
		{
			//R_UART1_SEND("$PSTMSRR\r\n");//MS_TIMER(1);
			GPS_RST_FLAG=ON;//HAVE TO CHANGE NEW CIRCUIT PIN PORT
    			//MS_TIMER(10);
    			//GPS_RST=OFF;
		}
		
		DEVICE_RESTART_RX=0;I[80]=0;}
		else if(I[80]>=9){DEVICE_RESTART_RX=1;}
		
	}
	else{I[80]=0;DEVICE_RESTART_RX=CLR;}
///*************************************************************************************************************************************************************/

//				AUTO NETWORK COMMAND SMS // BSNL F
//GET_GPS_CLEAR_S_FRAME[9]
///*************************************************************************************************************************************************************/
if(UART0_BUFFER==NWS_CMD_FRAME[I[72]])
	{
		I[72]++;
		
		if(I[72]>=9)
		{
			I[72]=0;
			NWS_CMD_SET=SET;
						
		}
				
				
	}
	else{I[72]=0;}	

///*************************************************************************************************************************************************************/

//				QSTK?? //

///*************************************************************************************************************************************************************/
if(UART0_BUFFER==QST_CMD_FRAME[I[73]])
	{
		I[73]++;
		
		if(I[73]>=8)
		{
			I[73]=0;
			//NWS_CMD_SET=SET;
   		 //R_UART2_SEND("AT+QSTK=1\r\n");
		 QST_CMD_FLAG=SET;
						
		}
				
				
	}
	else{I[73]=0;}	
	
	
	
//	if(UART0_BUFFER==CME_ERROR_ACK[I[74]])
//	{ALREADY_CONNECT_ACK[15]
//		I[74]++;
//		if(I[74]>=10)
//		{
//		I[74]=0;
//		CME_ERROR_OCCURED=1;
//		WATCHDOG_ON();
//		WATCH_DOG=NONE;
//		MS_TIMER(900);
//		}
//	}
//	else{I[74]=0;}

///*************************************************************************************************************************************************************/

//				SET SETTINGS IMEI= //

///*************************************************************************************************************************************************************/

	
if(UART0_BUFFER==SETTING_CMD_FRAME[I[27]] || SETTING_CMD_FRAME_RX>=1)
	{
		I[27]++;
			
		
	
		if(I[27]>=13 && SETTING_CMD_FRAME_RX==CLR)
		{
		SETTING_CMD_FRAME_RX=SET;
		I[27]=CLR;
		}
		else if(SETTING_CMD_FRAME_RX==SET)
		{
		PIN_CHECK(UART0_BUFFER,8);
		if(SET_RP_NO_FRAME_CMD==ON)
		{
			SETTING_CMD_FRAME_RX=2;
		}
		if(SMS_PIN_WRONG==SET)
                {
		SETTING_CMD_FRAME_RX=CLR;
		I[27]=CLR;
		}
		}
		else if(SETTING_CMD_FRAME_RX==2)
		{
			if(UART0_BUFFER=='=')
			{
			SETTING_CMD_FRAME_RX=3;VV=CLR;
			}
		}
		else if(SETTING_CMD_FRAME_RX==3)
		{
			if(UART0_BUFFER=='#' || UART0_BUFFER==0X00 || UART0_BUFFER=='\r' || UART0_BUFFER=='\n')
			{
				SETTING_CMD_FRAME_RX=CLR;
				I[27]=CLR;
				SET_RP_NO_FRAME_CMD=CLR;
				SETTING_CMD=SET;
				//UPDATE_RP_NO=SET;
			}
		        
			else
			{
			TEMP_SET[VV]=UART0_BUFFER;
			//APN_LENGTH=VV;
			VV++;
			}
		}
		else if(SETTING_CMD_FRAME_RX>=1)
		{
			SETTING_CMD_FRAME_RX=CLR;
			I[27]=0;
		}
}
		
		


	else
	{
	I[27]=0;
	SETTING_CMD_FRAME_RX=CLR;
	}	
	
///*************************************************************************************************************************************************************/
//				SET APN IMEI 2202=  (NEW FORMAT - NO PIN CHECK)
///*************************************************************************************************************************************************************/

if(UART0_BUFFER == SET_APN_FRAME2[I[86]] || SET_APN_FRAME_RX >= 1)  // Using new index I[86]
{
    I[86]++;
    
    // Check if we've received the full "SET APN IMEI 2202=" string (18 characters)
    if(I[86] >= 18 && SET_APN_FRAME_RX == CLR)
    {
        SET_APN_FRAME_RX = 1;  // Move to APN collection mode
        I[86] = CLR;
        VV = CLR;  // Reset counter for APN value
    }
    else if(SET_APN_FRAME_RX == 1)
    {
        // We're now collecting the APN value
        
        // End of APN detected
        if(UART0_BUFFER == '\r' || UART0_BUFFER == '\n' || UART0_BUFFER == 0x00)
        {
            SET_APN_FRAME_RX = CLR;  // Reset state machine
            I[86] = CLR;
            
            // Store the APN length
            APN_LENGTH = VV;
            
            // Set the flag that will trigger APN update in NEW_SMS_READ()
            UPDATE_APN = SET;
        }
        else
        {
            // Store APN characters (including dots!)
            TEMP_APN2[VV] = UART0_BUFFER;
            VV++;
            
            // Prevent buffer overflow
            if(VV >= 254) VV = 254;
        }
    }
}
else
{
    // Only reset if not in APN collection mode
    if(SET_APN_FRAME_RX != 1)
    {
        I[86] = 0;
        SET_APN_FRAME_RX = CLR;
    }
}
	
///*************************************************************************************************************************************************************/

//				SET TCP IMEI= //

///*************************************************************************************************************************************************************/

	
	if(UART0_BUFFER==SET_TCP_FRAME[I[24]] || SET_TCP_FRAME_RX>=1)
	{
		I[24]++;
			
		
	
		if(I[24]>=8 && SET_TCP_FRAME_RX==CLR)
		{
		SET_TCP_FRAME_RX=SET;
		I[24]=CLR;
		}
		else if(SET_TCP_FRAME_RX==SET)
		{
		PIN_CHECK(UART0_BUFFER,6);
		if(SET_IP_FRAME_CMD==ON)
		{
			SET_TCP_FRAME_RX=2;
		}
		if(SMS_PIN_WRONG==SET)
                {
		SET_TCP_FRAME_RX=CLR;
		I[24]=CLR;
		}
		}
		else if(SET_TCP_FRAME_RX==2)
		{
			if(UART0_BUFFER=='=')
			{
			SET_TCP_FRAME_RX=3;VV=CLR;
			}
		}
		else if(SET_TCP_FRAME_RX==3)
		{
			if(UART0_BUFFER=='*' || UART0_BUFFER==0X00 || UART0_BUFFER=='\r' || UART0_BUFFER=='\n')
			{
				SET_TCP_FRAME_RX=CLR;
				I[24]=CLR;
				SET_IP_FRAME_CMD=CLR;
				SET_TCP=SET;
				//UPDATE_RP_NO=SET;
			}
		        
			else
			{
			TEMP_TCP[VV]=UART0_BUFFER;
			//APN_LENGTH=VV;
			VV++;
			}
		}
		else if(SET_TCP_FRAME_RX>=1)
		{
			SET_TCP_FRAME_RX=CLR;
			I[24]=0;
		}
}
		
		


	else
	{
	I[24]=0;
	SET_TCP_FRAME_RX=CLR;
	}	
	
//	///*************************************************************************************************************************************************************/

////				SET TCP IMEI= //SETTING_CMD_FRAME[TEMP_SET[255],TEMP_TCP[255],

/////*************************************************************************************************************************************************************/

	
//	if(UART0_BUFFER==SETTING_CMD_FRAME[I[78]] || SET_SETTINGS_FRAME_RX>=1)
//	{
//		I[78]++;
			
		
	
//		if(I[78]>=13 && SET_SETTINGS_FRAME_RX==CLR)
//		{
//		SET_SETTINGS_FRAME_RX=SET;
//		I[78]=CLR;
//		}
//		else if(SET_SETTINGS_FRAME_RX==SET)
//		{
//		PIN_CHECK(UART0_BUFFER,7);
//		if(SET_IP_FRAME_CMD==ON)
//		{
//			SET_SETTINGS_FRAME_RX=2;
//		}
//		if(SMS_PIN_WRONG==SET)
//                {
//		SET_SETTINGS_FRAME_RX=CLR;
//		I[78]=CLR;
//		}
//		}
//		else if(SET_SETTINGS_FRAME_RX==2)
//		{
//			if(UART0_BUFFER=='=')
//			{
//			SET_SETTINGS_FRAME_RX=3;VV=CLR;
//			}
//		}
//		else if(SET_SETTINGS_FRAME_RX==3)
//		{
//			if(UART0_BUFFER=='#' || UART0_BUFFER==0X00 || UART0_BUFFER=='\r' || UART0_BUFFER=='\n')
//			{
//				SET_SETTINGS_FRAME_RX=CLR;
//				I[78]=CLR;
//				SET_IP_FRAME_CMD=CLR;
//				//UPDATE_RP_NO=SET;
//			}
		        
//			else
//			{
//			TEMP_APN2[VV]=UART0_BUFFER;
//			//APN_LENGTH=VV;
//			VV++;
//			}
//		}
//		else if(SET_SETTINGS_FRAME_RX>=1)
//		{
//			SET_SETTINGS_FRAME_RX=CLR;
//			I[78]=0;
//		}
//}
		
		


//	else
//	{
//	I[78]=0;
//	SET_SETTINGS_FRAME_RX=CLR;
//	}	

/************************************************************************************************************************************************************
					        PANIC_MOBILE_NUMBER_ACK			 					 
/************************************************************************************************************************************************************/
	
if(UART0_BUFFER == PANIC_MOBILE_NUMBER_ACK[I[21]] || PANIC_NUMBER_RX == 1)
{
    int i=0;
    I[21]++;
    
    if(PANIC_NUMBER_RX == 1)
    {
			// Check for end of number (carriage return or newline)
			if(UART0_BUFFER == '\r' || UART0_BUFFER == '\n' || UART0_BUFFER == 0x00)
			{
				// Number collection complete
				PANIC_NUMBER_RX = 0;
				I[21] = 0;
				
				// Copy collected numbers to TEMP_EMERGENCY_NUMBER
				for(i = 0; i < t; i++)
				{
					TEMP_EMERGENCY_NUMBER[i] = SMS_MOBILE_NO[i];
				}
				
				// Set flag to update emergency numbers
				UPDATE_EMERGENCY_NUMBER = SET;
				
				t = 0;  // Reset t after copying
			}
			
			else
			{
				SMS_MOBILE_NO[t] = UART0_BUFFER;  // Store mobile number after '='
				t++;
				SMS_MOBILE_NO[t] = 0;
			}
    }


    else if(I[21] >= 18)  // Now 18 for "SET ENO IMEI 2202="
    {
        I[21] = 0;
        PANIC_NUMBER_RX = 1;  // Start collecting
        t = 0;
    }
}
else
{
    I[21] = 0;
}
	/************************************************************************************************************************************************************
					     GET VEICHLE NUMBER									 
/************************************************************************************************************************************************************/

	if(UART0_BUFFER==VN_ACK[I[15]] || VN_ACK_RX>=1)
	{
		I[15]++;
		     if(UART0_BUFFER=='#' && VN_ACK_RX==1){VN_ACK_RX=0;I[15]=0;/*VEICHLE_NUMBER[t]=0;*/V_NO_LEN=t-1;t=0;if(V_NO_LEN<=0){V_NO_LEN=9;}}
		else if(VN_ACK_RX==1)
		{
		if(UART0_BUFFER==0X00){UART0_BUFFER=0X30;}
		if(VEICHLE_NUMBER[t]!=UART0_BUFFER)
		{
		UPDATE_REGISTRATION_NUMBER_1=SET;
		}
		VEICHLE_NUMBER[t]=UART0_BUFFER;
		t++;
		//VEICHLE_NUMBER[t]=0;
		}
		else if(I[15]>=3){VN_ACK_RX=1;t=0;V_NO_LEN=0;}
		
	}
	else{I[15]=0;}
		
	
		
	
	


}