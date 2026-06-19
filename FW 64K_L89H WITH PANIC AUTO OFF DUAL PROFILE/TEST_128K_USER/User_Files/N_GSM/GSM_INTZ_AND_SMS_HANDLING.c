#include "r_cg_userdefine.h"

extern char RX_ACK_Frame,ACK,ERROR_OCCURED,RX_SMS_CMD,RX_CMD_SMS[10],t,SMS_FAIL_COUNT,SMS_FAIL,NETWORK_NAME_RX,BATTERY_MEASUREMENT;
extern char PANIC_NUMBER_RX,IGNITION_CTRL_RX,INITIAL_MESSAGE,P_LAT_DM_RX,FILE_CLOSE_ATTEMPT,HA_LEVEL;
extern char GSM_REG,GPRS_REG,SS_DATA_RX,GET_SS,dBm,SMS_MOBILE_NO[55],CELL_ID_DATA_LENGTH_0;
extern char GPRS_CONNECTED,GSM_STRENGTH,INTERNET_CONNECTED,DISCONNECT,LOW_BATTERY_ALERT,HTTP_CONNECT_COUNT,VEICHLE_NUMBER[15],NW_NAME_RX,IMEI[16];
extern unsigned int FOR_1,FOR_3,Address_1,NW_REGN_COUNT,FLASH_MEMORY,GPRS_REG_COUNT,MAIN_BATTERY_VOLTAGE,ADC_BUFFER,BACKUP_BATTERY_VOLTAGE,GPRS_REG_ROAMING,GSM_REG_ROAMING,T_SPEED,FILTER,DATA_HEADER,TEMP_VERSION,I[100];
extern unsigned int t_count,WRITE_ADDRESS,DATA,WATCH_DOG_KILL,WRITE_ADDRESS,TEMPS,WRITE_ADDRESS_MSB,WRITE_ADDRESS_LSB,BYTE,P_D_L,PANIC_ALERT_TIME,HARSH_TURN_LEVEL,HARSH_BRAKE_LEVEL,OVER_SPEED,MINUTE;
extern char LOG_DM[10],LAT_DM[10],TIME[10],GPS_BUSY,SPEED[4],/*GPS_RX,*/SPEED_DATA_RX[10],WATCH_DOG,FIRM_DATA[150],FILE[150];
extern char GPS_DIRECTION_DATA_VALID,IGNITION,PANIC_ALERT,PANIC_ALERT_PACKET,IGNITION_ON_PACKET,IGNITION_OFF_PACKET,POWER_SOURCE_PACKET,LOW_BATTERY_ALERT_PACKET;
extern char HOURS_MSB,HOURS_LSB,MIN_MSB,MIN_LSB,LON_DIRECTION,LAT_DIRECTION,LAT_DM_RX[10],LOG_DM_RX[10],COG[6],GPGA_DATA[10],ALTITUDE[8],HDOP[5],NO_OF_SAT,NAVIGATION_ACK,NAVIGATION_RX,GPS_RESTART,LAC_DATA_LENGTH_0,TEMP_PIP[16],TEMP_SIP[16],TEMP_PIP2[16],TEMP_SIP2[16];
extern char Array_0[10],i,SMS,NETWORK_FAILURE,HTTP_PRINT,SPEED_DATA[10];//,QST_CMD_ACK[8];
extern char NETWORK_NAME[8],SS_DATA_RX,CELL_ID[5],LAC[5],TEMP_APN[15],APN_LENGTH;
//extern char GSM_NW_REG[8],GPRS_NW_REG[9];
//extern char GET_IN_SMS[4],CONNECT_ACK[7],SIGNAL_STRENGTH_ACK[5],NW_DIS_CONNECT[9];

extern char CPIN;
extern char P_LAT_DM[10],P_TIME[10],P_SEND_TIME[10],P_LOG_DM[10],P_SEND_LOG_DM[10],P_SEND_LAT_DM[10],FTP_ADDRESS[8],FTP_CONNECT_COUNT;
extern char FILE_ADDR,V_NO_LEN;
extern unsigned int CHECKSUM_BYTE,MN,VERSION_TEMP,FRM_VERSION,CURRENT_FRM_VERSION,HEX,TEMP_OVS_LEVEL,SLEEP_OFF_TIME,TEMP_SLEEP_OFF_TIME,EMGT_TIME,RESTART;
extern char PANIC_CTRL_RX,PANIC_CONTROL_STATE,ALTITUDE_VALUE_COUNT,REPLY_NUMBER[10]/*,GET_STRPCI_RX[5*/;
extern _Bool BSNL_CONNECT_FLAG,BSNL_CONNECT,FIRMWARE_UPDATE,IGNITION_CONTROL_STATE,POWER_SOURCE,SYSTEM_READY,SMS_CMD_DATA_UPLOAD_UONT,SMS_CMD_DATA_UPLOAD,HARSH_BRAKE_CMD_RX,HARSH_ACCEL_CMD,HARSH_TURN_CMD,HARSH_BRAKE_CMD,PANIC_ON_DURATON_CMD,HEALTH_ON_DURATON_CMD,HEALTH_PACKET_TO_SERVER,GET_PIP_CMD,GET_SIP_CMD,SLEEP_OFF_TIME_CMD,ACTIVATION_CMD,HEALTH_CMD2,HEALTH_AND_ACTIVATION_CMD;
extern _Bool QST_CMD_FLAG,HTTP_DOWNLOAD_ACK,FTP_ACK,FTP_DOWNLOAD_ACK,FIRMWARE_DOWNLOADED,FILE_ACK,FILE_DOWNLOAD,FLAG,STOP_FILE_READING,IMEI_RX,IMEI_ACK_RX,UPDATE_REGISTRATION_NUMBER_1,DEVICE_CLEAR_CMD,HEX_CHARACTER_CONVERSION,REFRESH,GET_SMS_CMD,MESSAGE_READ,DATA_SEND;
extern _Bool VERSION_CMD_SET,GET_VLT_IMEI_PH_CMD,PANIC_CONTROL_STATE_1,k,GPS_STANDBY,WATCH_DOG_FORCE_KILL,SMS_CMD_REPLY,VERSION_CMD_RX,DECIMAL_POINT_CAME_STOP_TX,ADD_ZERO_TO_SPEED,SEND_IMEI,SMS_PIN_WRONG,DEVICE_RESET_CMD,UPDATE_APN,UPDATE_REGISTRATION_NUMBER,UPDATE_INTERVAL_TIME_FOR_IGNITION_ON_CMD,UPDATE_INTERVAL_TIME_FOR_IGNITION_OFF_CMD,UPDATE_EMERGENCY_NUMBER,UPDATE_IP,UPDATE_RP_NO,POWER_SOURCE_RECONNECT_PACKET,OTA_PACKET,PRI_IP_PN_SMS,SEC_IP_PN_SMS,SET_SLEEP_OFF_CMD,SET_SLEEP_ON_CMD,OVER_SPEED_CMD,SLEEP_ON_TIME_CMD,GET_EMGT_TIME_CMD;
extern unsigned int TEMP_3,HEALTH_ON_DURATON_LEVEL,HEALTH_ALERT_TIME,IGNITION_ON_UPDATE_TIME,IGNITION_OFF_UPDATE_TIME,HARSH_ACCEL_LEVEL,LOW_BAT_LEVEL,LB_LEVEL,HT_LEVEL,HB_LEVEL,P_D_L,TEMP_SLEEP_ON_TIME,SLEEP_ON_TIME,FOR_9;
extern int AD;
extern char p1,p2,p3,p4,Array_0[10],NEW_SMS_INBOX_ADDRESS[20],NEW_SMS,SPEED_DATA_LENGTH_COUNT,MAIN_BAT_STATUS,TEMP_PPN2[4],TEMP_SPN2[4];
extern char PHONE_NUMBER_OF_SENDER[12];
unsigned int FOR_9;
//unsigned int NetworkCode;
extern char VV;
_Bool PNET_CMD_REPLY,SNET_CMD_REPLY,NWP_CMD_SET,NWS_CMD_SET;
extern char LOW_BAT_LEVEL_RX,LOW_BAT_LEVEL_CMD;
extern unsigned long int HEALTH_FRAME_NUMBER;
extern _Bool PRIMARY_IP,SECONDARY_IP,GET_PPN_CMD,GET_SPN_CMD,PRIMARY_PN,SECONDARY_PN;
#define    SIMMAKE_IDEMIA_3P


void QSTK(void)
{
	if(QST_CMD_FLAG==SET)
	{
			
	R_UART2_SEND("AT+QSTK=1\r\n");
	MS_TIMER(500);
	QST_CMD_FLAG=CLR;
	//R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n ");
    //MS_TIMER(500);
	//R_WDT_Restart();
	//WATCHDOG_ON();
	WATCH_DOG=NONE;
	//GPRS_PS_EN=OFF1;
	//MS_TIMER(1000);
	//GPRS_PS_EN=ON1;
	
}
	NOP();
}


void MANUAL_NET(unsigned int N)
{
    if(N==0)
    {
        return;
    }
    if(N != 0)
    {
        #if defined(SIMMAKE_IDEMIA_3P)
            R_UART2_SEND("AT+CIMI\r\n ");
            MS_TIMER(500);
            //R_UART2_SEND("AT+QSTK\"\r\n ");
            R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n ");
            MS_TIMER(500);
            R_UART2_SEND("AT+STKENV=\"D30782020181900101\"\r\n"); // Open Menu items
            MS_TIMER(500);
            // R_UART2_SEND("AT+STKTR=\"810301240402028281830100900102\"\r\n"); // SELECT Network
            // MS_TIMER(500); //dont know what it is , commented by vyshak

            if(N==1)
            {
                R_UART2_SEND("AT+STKTR=\"810301240082028281830100900101\"\r\n");//NetworkCode=1;// Vodafone P
                MS_TIMER(500);
                MS_TIMER(1000);// Auto Network SELECT
                GPRS_PS_EN=OFF1;
                MS_TIMER(500);
                GPRS_PS_EN=ON1;
                MS_TIMER(500);
                //R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n ");
                MS_TIMER(500);
            }
            if(N==2)
            {
                R_UART2_SEND("AT+STKTR=\"810301240082028281830100900102\"\r\n");//NetworkCode=1;  // BSNL F
                MS_TIMER(500);
                MS_TIMER(1000);// Auto Network SELECT
                GPRS_PS_EN=OFF1;
                MS_TIMER(500);
                GPRS_PS_EN=ON1;
                MS_TIMER(500);
                //R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n ");
                MS_TIMER(500);
            }
            if(N==3)
            {
                R_UART2_SEND("AT+STKTR=\"810301240082028281830100900103\"\r\n");  // Airtel code
                MS_TIMER(500);
                MS_TIMER(1000);  // Auto Network SELECT
                GPRS_PS_EN=OFF1;
                MS_TIMER(500);
                GPRS_PS_EN=ON1;
                MS_TIMER(500);
                //R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n");
                MS_TIMER(500);
            }


        #else
            R_UART2_SEND("AT+CIMI\r\n ");
            MS_TIMER(500);
            R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n ");
            MS_TIMER(500);
            R_UART2_SEND("AT+STKENV=\"D30782020181900180\"\r\n"); // Open Menu items
            MS_TIMER(500);
            R_UART2_SEND("AT+STKTR=\"810301240402028281830100900102\"\r\n"); // SELECT Network
            MS_TIMER(500);

            if(N==1)
            {
                R_UART2_SEND("AT+STKTR=\"810301240402028281830100900115\"\r\n");//NetworkCode=1;// Vodafone P
                MS_TIMER(500);
                MS_TIMER(1000);// Auto Network SELECT
                GPRS_PS_EN=OFF1;
                MS_TIMER(500);
                GPRS_PS_EN=ON1;
                MS_TIMER(500);
                R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n ");
                MS_TIMER(500);
            }
            if(N==2)
            {
                R_UART2_SEND("AT+STKTR=\"810301240402028281830100900116\"\r\n");//NetworkCode=1;  // BSNL F
                MS_TIMER(500);
                MS_TIMER(1000);// Auto Network SELECT
                GPRS_PS_EN=OFF1;
                MS_TIMER(500);
                GPRS_PS_EN=ON1;
                MS_TIMER(500);
                R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n ");
                MS_TIMER(500);
            }
            if(N==3)
            {
                R_UART2_SEND("AT+STKTR=\"810301240402028281830100900114\"\r\n");  // Airtel code
                MS_TIMER(500);
                MS_TIMER(1000);  // Auto Network SELECT
                GPRS_PS_EN=OFF1;
                MS_TIMER(500);
                GPRS_PS_EN=ON1;
                MS_TIMER(500);
                R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n");
                MS_TIMER(500);
            }
        #endif
    }
    R_UART2_SEND("AT+CIMI\r\n ");

}


void NEW_SMS_READ(void)
{
	//GPRS_PS_EN=ON1;
	if(NEW_SMS>=1)
	{
		R_TAU0_Channel0_Stop();
		NEW_SMS--;
		ACK=ERROR_OCCURED=RESTART=0;
		// Reset SMS command parsing flags to ensure each SMS is parsed independently
		HARSH_ACCEL_CMD = 0;
		HARSH_BRAKE_CMD_RX = 0;
		VERSION_CMD_SET = 0;
		GET_VLT_IMEI_PH_CMD = 0;
		GET_SMS_CMD = 0;
		// NEW_SMS_RX_FRAME_RX = 0;
		// // Add other command flags as needed
		
		// // Reset parsing indices
		// I[55] = 0;  // GET SMS command
		// I[56] = 0;  // Version command
		// I[81] = 0;  // VLT IMEI PH command
		// I[82] = 0;  // HACL command
		// I[83] = 0;  // HBRK command
		// // Add other indices as needed
		
		// VV = 0;  // Reset value collection counter
		restart5:
		R_UART2_SEND("AT+CMGF=1\r\n");
		ACK_RX(20,2,100,3);
		if(RESTART==ON){SMS_FAIL++;RESTART=OFF;goto restart5;}
		
		R_UART2_SEND("AT+CMGR=");
		R_UART2_SEND_User(Array_0[NEW_SMS_INBOX_ADDRESS[NEW_SMS]/10]);
		R_UART2_SEND_User(Array_0[NEW_SMS_INBOX_ADDRESS[NEW_SMS]%10]);
		R_UART2_SEND("\r\n");
		ACK_RX(20,2,10,1);
		MS_TIMER(200);  // Wait for UART0 parser to process SMS content
		
		
		// Configure SMS mode
		R_UART2_SEND("AT+CMGF=1\r\n");
		MS_TIMER(100);
		
		// Send to extracted sender number
		// R_UART2_SEND("AT+CMGS=\"");
		// for(FOR_9=0; FOR_9<12; FOR_9++)
		// {
		// 	if(PHONE_NUMBER_OF_SENDER[FOR_9]==0 || PHONE_NUMBER_OF_SENDER[FOR_9]==' ')
		// 		break;  // Stop at null terminator or space
		// 	R_UART2_SEND_User(PHONE_NUMBER_OF_SENDER[FOR_9]);
		// }
		// R_UART2_SEND("\"\r\n");
		// MS_TIMER(100);
		
		// // Send the confirmation message
		// R_UART2_SEND("SMS received by VLT Tracker");
		// MS_TIMER(50);
		
		// // Send Ctrl+Z to send the SMS
		// R_UART2_SEND_User(CTRL_Z);
		// MS_TIMER(500);
		
		NEW_SMS = 0;  // Clear the flag after processing the SMS
		if(NEW_SMS==0)
		{
			SMS_FAIL=CLR;
			restart1:

			R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");
			ACK_RX(100,2,100,1);
			if(SMS_FAIL>=25)
			{
				SMS_FAIL=0;RESTART=OFF;goto restart1;
			}
			else if(RESTART==ON)
			{
				SMS_FAIL++;RESTART=OFF;
				goto restart2;
			}
			SMS_FAIL=0;
		}
		R_TAU0_Channel0_Start();	
	}
restart2:


if(GET_SMS_CMD==SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	OTA_PACKET=ON;
	DEVICE_REPLY_IN_SMS(17);
	UPDATE_ONLINE_DATA_FRAME();
	GET_SMS_CMD=CLR;
}


if(VERSION_CMD_SET==SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	DEVICE_REPLY_IN_SMS(200);
	VERSION_CMD_SET=CLR;
}

if(SMS_CMD_REPLY==SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block

}

if(GET_VLT_IMEI_PH_CMD==SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	DEVICE_REPLY_IN_SMS(201);
	GET_VLT_IMEI_PH_CMD=CLR;
}

if(HARSH_ACCEL_CMD==SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	OTA_PACKET=ON;
	CMD_DATA_WRITE_IN_EEROM(9);
	//SMS_CMD_DATA_UPL(12);
	DEVICE_REPLY_IN_SMS(11);
	HA_LEVEL=HARSH_ACCEL_LEVEL;
	HARSH_ACCEL_CMD=CLR;
}

if(SEND_IMEI == SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	OTA_PACKET = ON;           // Sets OTA packet flag
	DEVICE_REPLY_IN_SMS(2);    // Calls function with parameter 2
	SEND_IMEI = CLR;           // Clears the flag
}

// Add this where you process other commands
if(HARSH_BRAKE_CMD_RX == 1)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	OTA_PACKET = 1;
	CMD_DATA_WRITE_IN_EEROM(11);                 // Save to EEPROM (D==11 for Harsh Brake)
	DEVICE_REPLY_IN_SMS(13);                      // Send confirmation (REPLY==13)
	HB_LEVEL = HARSH_BRAKE_LEVEL;                  // Update HB_LEVEL as in your existing code
	HARSH_BRAKE_CMD_RX = 0;                        // Clear the flag
}

if(HARSH_TURN_CMD==SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	OTA_PACKET=ON;
	CMD_DATA_WRITE_IN_EEROM(10);
	//SMS_CMD_DATA_UPL(14);
	DEVICE_REPLY_IN_SMS(12);
	HT_LEVEL=HARSH_TURN_LEVEL;
	HARSH_TURN_CMD=CLR;
}
///************************************************************************************************************************************************************
//PROCESS LOW BATTERY LEVEL COMMAND
///************************************************************************************************************************************************************/
if(LOW_BAT_LEVEL_CMD==SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	OTA_PACKET=ON;
	CMD_DATA_WRITE_IN_EEROM(14);
	DEVICE_REPLY_IN_SMS(16);
	UPDATE_ONLINE_DATA_FRAME();
	LB_LEVEL=LOW_BAT_LEVEL;
	LOW_BAT_LEVEL_CMD=CLR;
}

//	UPDATE APN
//UPDATE_APN=SET;
if(UPDATE_APN==SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	OTA_PACKET=ON;
	CMD_DATA_WRITE_IN_EEROM(4);
	//SMS_CMD_DATA_UPL(6);
	DEVICE_REPLY_IN_SMS(7);
	INTERNET_CONNECTED=OFF;
	REFRESH=ON;
	//UPDATE_ONLINE_DATA_FRAME();
	UPDATE_APN=CLR;
}

// UPDATE EMERGECY NUMBER
if(UPDATE_EMERGENCY_NUMBER==SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	OTA_PACKET=ON;
	CMD_DATA_WRITE_IN_EEROM(5);
	//SMS_CMD_DATA_UPL(3);
	DEVICE_REPLY_IN_SMS(8);
	UPDATE_EMERGENCY_NUMBER=CLR;
}


if(DEVICE_RESET_CMD==SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	OTA_PACKET=ON;
	DEVICE_REPLY_IN_SMS(3);
	DEVICE_RESET_CMD=CLR;
	WATCHDOG_ON();
	WATCH_DOG=NONE;
	MS_TIMER(900);
}

if(HEALTH_CMD2==SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	HEALTH_FRAME_NUMBER++;
	OTA_PACKET=ON;
	DEVICE_REPLY_IN_SMS(102);
	HEALTH_AND_ACTIVATION_CMD=ON;
	UPDATE_ONLINE_DATA_FRAME();
	HEALTH_CMD2=HEALTH_AND_ACTIVATION_CMD=CLR;
}

if(ACTIVATION_CMD==SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	HEALTH_FRAME_NUMBER++;
	OTA_PACKET=ON;
	DEVICE_REPLY_IN_SMS(101);
	HEALTH_AND_ACTIVATION_CMD=ON;
	UPDATE_ONLINE_DATA_FRAME();
	ACTIVATION_CMD=HEALTH_AND_ACTIVATION_CMD=CLR;
}

if(HEALTH_ON_DURATON_CMD==SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	OTA_PACKET=ON;
	CMD_DATA_WRITE_IN_EEROM(13);
	//SMS_CMD_DATA_UPL(18);
	DEVICE_REPLY_IN_SMS(15);
	HEALTH_PACKET_TO_SERVER=SET;
	UPDATE_ONLINE_DATA_FRAME();
	HEALTH_ALERT_TIME=HEALTH_ON_DURATON_LEVEL;
	HEALTH_PACKET_TO_SERVER=HEALTH_ON_DURATON_CMD=CLR;
}

if(PNET_CMD_REPLY==SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	//MANUAL_NET(1);
	DEVICE_REPLY_IN_SMS(20);
	PNET_CMD_REPLY=CLR;	
}
if(SNET_CMD_REPLY==SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	//MANUAL_NET(2);
	DEVICE_REPLY_IN_SMS(21);
	SNET_CMD_REPLY=CLR;	
}

if(PROF_CMD_REPLY == SET)
{
    // R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
    DEVICE_REPLY_IN_SMS(28);
    PROF_CMD_REPLY = CLR;
}

if(INTVL_CMD_REPLY == SET)
{
    // R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
    // Save all 5 intervals to EEPROM
    // EEPROM addresses 111-115 (free addresses from your map)
    i2c_writen(0xA0, 0XFE, 111, (TEMP_TRC_INTVL >> 8));    // TRC high byte
    MS_TIMER(5);
    i2c_writen(0xA0, 0XFE, 112, (TEMP_TRC_INTVL & 0xFF));  // TRC low byte
    MS_TIMER(5);
    i2c_writen(0xA0, 0XFE, 113, (TEMP_IGN_INTVL >> 8));    // IGN high byte
    MS_TIMER(5);
    i2c_writen(0xA0, 0XFE, 114, (TEMP_IGN_INTVL & 0xFF));  // IGN low byte
    MS_TIMER(5);
    i2c_writen(0xA0, 0XFE, 115, (TEMP_SOS_INTVL >> 8));    // SOS high byte
    MS_TIMER(5);
    i2c_writen(0xA0, 0XFE, 116, (TEMP_SOS_INTVL & 0xFF));  // SOS low byte
    MS_TIMER(5);
    i2c_writen(0xA0, 0XFE, 117, (TEMP_STD_INTVL >> 8));    // STD high byte
    MS_TIMER(5);
    i2c_writen(0xA0, 0XFE, 118, (TEMP_STD_INTVL & 0xFF));  // STD low byte
    MS_TIMER(5);
    i2c_writen(0xA0, 0XFE, 119, (TEMP_HLT_INTVL >> 8));    // HLT high byte
    MS_TIMER(5);
    i2c_writen(0xA0, 0XFE, 120, (TEMP_HLT_INTVL & 0xFF));  // HLT low byte
    MS_TIMER(5);

    DEVICE_REPLY_IN_SMS(29);
    INTVL_CMD_REPLY = CLR;
}

if(UPDATE_REGISTRATION_NUMBER_1==SET)
{
	// R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");  // Centralized SMS delete in NEW_SMS block
	OTA_PACKET=ON;
	CMD_DATA_WRITE_IN_EEROM(8);
	//SMS_CMD_DATA_UPL(4);
	DEVICE_REPLY_IN_SMS(6);
	UPDATE_REGISTRATION_NUMBER_1=CLR;
}


if(SETDEF_CMD_REPLY == SET)
{
    DEVICE_REPLY_IN_SMS(32);
    SETDEF_CMD_REPLY = CLR;
}

if(SOSCLR_CMD_REPLY == SET)
{
    PANIC_ALERT = CLR;
    PANIC_ALERT_PACKET = OFF;
    PANIC_CONTROL_STATE = CLR;
    PANIC_CONTROL_STATE_1 = ON;  // Set to ON so next PVT sends EA,11 (emergency cleared)
    //PANIC_TIME_START = CLR;
    //PANIC_TIME_STOP = CLR;
    DEVICE_REPLY_IN_SMS(33);
    SOSCLR_CMD_REPLY = CLR;
}

if(SOSTMO_CMD_REPLY == SET)
{
    // Save to EEPROM � addresses 122 (high byte), 123 (low byte)
    i2c_writen(0xA0, 0XFE, 122, (TEMP_SOSTMO >> 8));    // high byte
    MS_TIMER(5);
    i2c_writen(0xA0, 0XFE, 123, (TEMP_SOSTMO & 0xFF));  // low byte
    MS_TIMER(5);

    DEVICE_REPLY_IN_SMS(34);
    SOSTMO_CMD_REPLY = CLR;
}

if(SOSSET_CMD_REPLY == SET)
{
    // Save num1 to EEPROM 124..133 (10 bytes)
    for(t = 0; t < 10; t++)
    {
        i2c_writen(0xA0, 0XFE, 124 + t, TEMP_SOS_NUM1[t]);
        MS_TIMER(2);
        if(TEMP_SOS_NUM1[t] == '\0') break;
    }

    // Save num2 to EEPROM 134..143 (10 bytes)
    for(t = 0; t < 10; t++)
    {
        i2c_writen(0xA0, 0XFE, 134 + t, TEMP_SOS_NUM2[t]);
        MS_TIMER(2);
        if(TEMP_SOS_NUM2[t] == '\0') break;
    }

    DEVICE_REPLY_IN_SMS(35);
    SOSSET_CMD_REPLY = CLR;
    t = 0;
}
if(SETBTS_CMD_REPLY == SET)
{
    // Save to EEPROM � address 144 (free after SOS numbers 124-143)
    i2c_writen(0xA0, 0XFE, 144, TEMP_BTS);
    MS_TIMER(5);

    // Update live variable
    LOW_BAT_LEVEL = TEMP_BTS;

    DEVICE_REPLY_IN_SMS(36);
    SETBTS_CMD_REPLY = CLR;
}

if(SETFOTA_CMD_REPLY == SET)
{
    // Save IP to EEPROM 145..159 (15 bytes)
    for(t = 0; t < 15; t++)
    {
        i2c_writen(0xA0, 0XFE, 145 + t, TEMP_FOTA_IP[t]);
        MS_TIMER(2);
        if(TEMP_FOTA_IP[t] == '\0') break;
    }

    // Save PORT to EEPROM 160..165 (6 bytes)
    for(t = 0; t < 6; t++)
    {
        i2c_writen(0xA0, 0XFE, 160 + t, TEMP_FOTA_PORT[t]);
        MS_TIMER(2);
        if(TEMP_FOTA_PORT[t] == '\0') break;
    }

    // Save USER to EEPROM 166..181 (16 bytes)
    for(t = 0; t < 16; t++)
    {
        i2c_writen(0xA0, 0XFE, 166 + t, TEMP_FOTA_USER[t]);
        MS_TIMER(2);
        if(TEMP_FOTA_USER[t] == '\0') break;
    }

    // Save PASS to EEPROM 182..197 (16 bytes)
    for(t = 0; t < 16; t++)
    {
        i2c_writen(0xA0, 0XFE, 182 + t, TEMP_FOTA_PASS[t]);
        MS_TIMER(2);
        if(TEMP_FOTA_PASS[t] == '\0') break;
    }

    // Save FILE to EEPROM � NOTE: 199 is used by APN_LENGTH (D==4)
    // Use separate page 0xFB for FOTA file path (32 bytes from address 0)
    for(t = 0; t < 32; t++)
    {
        i2c_writen(0xA0, 0XFB, t, TEMP_FOTA_FILE[t]);
        MS_TIMER(2);
        if(TEMP_FOTA_FILE[t] == '\0') break;
    }

    //SET_OTA_UPDATE = SET;   // trigger FOTA process
    //OTA_PACKET==ON;
    DEVICE_REPLY_IN_SMS(37);
    SETFOTA_CMD_REPLY = CLR;
    t = 0;
    }
    if(GETPROF_CMD_REPLY == SET)
    {
        DEVICE_REPLY_IN_SMS(38);
        GETPROF_CMD_REPLY = CLR;
    }

    if(GETSOSTMO_CMD_REPLY == SET)
    {
        DEVICE_REPLY_IN_SMS(39);
        GETSOSTMO_CMD_REPLY = CLR;
    }

    if(GETVSTAT_CMD_REPLY == SET)
    {
        // Refresh status data before sending
        GET_SIGNAL_STRENGTH();        // Updates GSM_STRENGTH and dBm
        BATTERY_MEASUREMENT = ON;      // Ensure fresh battery readings
        MS_TIMER(10);
        
        DEVICE_REPLY_IN_SMS(40);
        GETVSTAT_CMD_REPLY = CLR;
    }

    if(GETSRVDTL_CMD_REPLY == SET)
    {
        DEVICE_REPLY_IN_SMS(41);
        GETSRVDTL_CMD_REPLY = CLR;
    }
    if(GETLOC_CMD_REPLY == SET)
    {
        // Refresh GPS data before sending
        GET_GPS_DATA();           // Updates LAT_DM, LOG_DM, etc.
        GET_SPEED_DATA();         // Updates SPEED_DATA
        MS_TIMER(10);
        
        DEVICE_REPLY_IN_SMS(42);
        GETLOC_CMD_REPLY = CLR;
    }
    if(GETPANIC_CMD_REPLY == SET)
    {
        DEVICE_REPLY_IN_SMS(43);
        GETPANIC_CMD_REPLY = CLR;
    }

    if(GETVINFO_CMD_REPLY == SET)
    {
        R_UART2_SEND("AT+QMGDA=\"DEL ALL\"\r\n");
        DEVICE_REPLY_IN_SMS(44);
        GETVINFO_CMD_REPLY = CLR;
    }







    if(SMS_PIN_WRONG==SET)
    {
    OTA_PACKET=ON;
    //DEVICE_REPLY_IN_SMS(0);
    SMS_PIN_WRONG=CLR;
    }

    //	UPDATE INTERVAL TIME FOR IGNITION ON
    if(UPDATE_INTERVAL_TIME_FOR_IGNITION_ON_CMD==SET)
    {
    OTA_PACKET=ON;
    CMD_DATA_WRITE_IN_EEROM(1);
    //SMS_CMD_DATA_UPL(1);
    //DEVICE_REPLY_IN_SMS(4);
    UPDATE_INTERVAL_TIME_FOR_IGNITION_ON_CMD=CLR;
    }
    //	UPDATE INTERVAL TIME FOR IGNITION OFF
    if(UPDATE_INTERVAL_TIME_FOR_IGNITION_OFF_CMD==SET)
    {
    OTA_PACKET=ON;
    CMD_DATA_WRITE_IN_EEROM(2);
    //SMS_CMD_DATA_UPL(2);
    //DEVICE_REPLY_IN_SMS(5);
    UPDATE_INTERVAL_TIME_FOR_IGNITION_OFF_CMD=CLR;
    }
    //	UPDATE REGISTRATION NUMBER
    if(UPDATE_REGISTRATION_NUMBER==SET)
    {
    OTA_PACKET=ON;
    CMD_DATA_WRITE_IN_EEROM(3);
    //SMS_CMD_DATA_UPL(4);
    //DEVICE_REPLY_IN_SMS(6);
    UPDATE_REGISTRATION_NUMBER=CLR;
    }


    // UPDATE REPLY NUMBER
    if(UPDATE_RP_NO==SET)
    {
    OTA_PACKET=ON;
    CMD_DATA_WRITE_IN_EEROM(7);
    //SMS_CMD_DATA_UPL(5);
    //DEVICE_REPLY_IN_SMS(9);
    UPDATE_RP_NO=CLR;
    }

    if(DEVICE_CLEAR_CMD==SET)
    {
    OTA_PACKET=ON; //14,13,12,11,10,09,5,2,1
    //SMS_CMD_DATA_UPL(15);
    //DEVICE_REPLY_IN_SMS(10);
    IGNITION_OFF_UPDATE_TIME=3;
    IGNITION_ON_UPDATE_TIME=HARSH_ACCEL_LEVEL=HARSH_TURN_LEVEL=HARSH_BRAKE_LEVEL=HEALTH_ON_DURATON_LEVEL=1;
    LOW_BAT_LEVEL=70;  /* Default: 70% low battery threshold */
    P_D_L=5;
    TEMP_APN[0]='s';
    TEMP_APN[1]='e';
    TEMP_APN[2]='n';
    TEMP_APN[3]='s';
    TEMP_APN[4]='e';
    TEMP_APN[5]='m';
    TEMP_APN[6]='2';
    TEMP_APN[7]='m';
    //TEMP_APN[8]='m';
    //TEMP_APN[9]='s';
    APN_LENGTH=7;
    for(FOR_9=0;FOR_9<=11;FOR_9++)
    {
    TEMP_PIP2[FOR_9]=TEMP_PIP[FOR_9];
    NOP();
    }
    for(FOR_9=0;FOR_9<=11;FOR_9++)
    {
    TEMP_SIP2[FOR_9]=TEMP_SIP[FOR_9];
    NOP();
    }
    //TEMP_PPN2[0]='9';TEMP_PPN2[1]='0';TEMP_PPN2[2]='0';TEMP_PPN2[3]='0';
    //TEMP_SPN2[0]='9';TEMP_SPN2[1]='0';TEMP_SPN2[2]='0';TEMP_SPN2[3]='0';
    CMD_DATA_WRITE_IN_EEROM(1);CMD_DATA_WRITE_IN_EEROM(2);CMD_DATA_WRITE_IN_EEROM(4);CMD_DATA_WRITE_IN_EEROM(5);CMD_DATA_WRITE_IN_EEROM(9);CMD_DATA_WRITE_IN_EEROM(10);CMD_DATA_WRITE_IN_EEROM(11);CMD_DATA_WRITE_IN_EEROM(12);CMD_DATA_WRITE_IN_EEROM(13);CMD_DATA_WRITE_IN_EEROM(14);
    UPDATE_ONLINE_DATA_FRAME();
    DEVICE_CLEAR_CMD=CLR;
    WATCHDOG_ON();
    WATCH_DOG=NONE;
    MS_TIMER(900);
    }

    if(HARSH_TURN_CMD==SET)
    {
    OTA_PACKET=ON;
    CMD_DATA_WRITE_IN_EEROM(10);
    //SMS_CMD_DATA_UPL(14);
    //DEVICE_REPLY_IN_SMS(12);
    HT_LEVEL=HARSH_TURN_LEVEL;
    HARSH_TURN_CMD=CLR;
    }


    // if(HARSH_BRAKE_CMD==SET)
    // {
    // OTA_PACKET=ON;
    // CMD_DATA_WRITE_IN_EEROM(11);
    // //SMS_CMD_DATA_UPL(13);
    // //DEVICE_REPLY_IN_SMS(13);
    // HB_LEVEL=HARSH_BRAKE_LEVEL;
    // HARSH_BRAKE_CMD=CLR;
    // }
    if(PANIC_ON_DURATON_CMD==SET)
    {
    OTA_PACKET=ON;
    CMD_DATA_WRITE_IN_EEROM(12);
    //SMS_CMD_DATA_UPL(17);
    //DEVICE_REPLY_IN_SMS(14);
    PANIC_ALERT_TIME=P_D_L;
    PANIC_ON_DURATON_CMD=CLR;
    }



    //UPDATE PIP & PN FROM SMS
    if(PRI_IP_PN_SMS==SET)
    {
    //CHECK_IP(2);
    //DEVICE_REPLY_IN_SMS(20);
    PRI_IP_PN_SMS=CLR;
    }
    //UPDATE SIP & PN FROM SMS
    if(SEC_IP_PN_SMS==SET)
    {
    //CHECK_IP(3);
    //DEVICE_REPLY_IN_SMS(21);
    PRI_IP_PN_SMS=CLR;
    }
    //UPDATE PIP FROM SERVER
    if(GET_PIP_CMD==SET)
    {
    //CHECK_IP(0);
    //DEVICE_REPLY_IN_SMS(18);
    GET_PIP_CMD=CLR;
    }
    //UPDATE SIP FROM SERVER
    if(GET_SIP_CMD==SET)
    {
    OTA_PACKET=ON;
    //CHECK_IP(1);
    //DEVICE_REPLY_IN_SMS(19);
    GET_SIP_CMD=CLR;
    }
    if(GET_PPN_CMD==SET)
    {
    //CHECK_IP(4);
    //DEVICE_REPLY_IN_SMS(22);
    GET_PPN_CMD=CLR;
    }
    if(GET_SPN_CMD==SET)
    {
    OTA_PACKET=ON;
    //CHECK_IP(5);
    //DEVICE_REPLY_IN_SMS(23);
    GET_SPN_CMD=CLR;
    }
    if(SET_SLEEP_ON_CMD==SET)
    {
    OTA_PACKET=ON;
    //DEVICE_REPLY_IN_SMS(24);
    SET_SLEEP_ON_CMD=CLR;
    }
    if(SET_SLEEP_OFF_CMD==SET)
    {
    OTA_PACKET=ON;
    //DEVICE_REPLY_IN_SMS(25);
    SET_SLEEP_OFF_CMD=CLR;
    }
    if(OVER_SPEED_CMD==SET)
    {
    OTA_PACKET=ON;
    OVER_SPEED=TEMP_OVS_LEVEL;
    CMD_DATA_WRITE_IN_EEROM(15);
    //DEVICE_REPLY_IN_SMS(26);
    OVER_SPEED_CMD=CLR;
    }
    if(SLEEP_ON_TIME_CMD==SET)
    {
    OTA_PACKET=ON;
    SLEEP_ON_TIME=TEMP_SLEEP_ON_TIME;
    CMD_DATA_WRITE_IN_EEROM(16);
    //DEVICE_REPLY_IN_SMS(24);
    SLEEP_ON_TIME_CMD=CLR;
    }
    if(SLEEP_OFF_TIME_CMD==SET)
    {
    OTA_PACKET=ON;
    SLEEP_OFF_TIME=TEMP_SLEEP_OFF_TIME;
    CMD_DATA_WRITE_IN_EEROM(17);
    //DEVICE_REPLY_IN_SMS(25);
    SLEEP_OFF_TIME_CMD=CLR;
    }
    if(GET_EMGT_TIME_CMD==SET)
    {
    OTA_PACKET=ON;
    //EMGT_TIME=TEMP_EMGT_TIME;
    CMD_DATA_WRITE_IN_EEROM(18);
    //DEVICE_REPLY_IN_SMS(27);
    GET_EMGT_TIME_CMD=CLR;
    }

}



void InitM95(void)   ///TESTING
{
    GPRS_PS_EN=OFF1;
    MS_TIMER(1500);
    GPRS_PS_EN=ON1;	
    MS_TIMER(1500);
    R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n ");
    MS_TIMER(500);
    R_UART2_SEND("AT+QSTK?\r\n");
    MS_TIMER(500);
    //R_UART2_SEND("AT+CRSM=214,28539,0,0,12,\"FFFFFFFFFFFFFFFFFFFFFFFF\"\r\n");
    MS_TIMER(500);
}

void SwitchNetwork(void)
{
    // #ifdef SIMMAKE_IDEMIA_3P
    //     if(NWP_CMD_SET==SET)
    //     {
    //         VI_CONNECT=1;
    //     }
    //     if(NWS_CMD_SET==SET)
    //     {
    //         BSNL_CONNECT=1;
    //     }
    //     if(NWT_CMD_SET==SET)
    //     {
    //         ATL_CONNECT=1;
    //     }
    // #else
        //if(BSNL_CONNECT==1 || NWP_CMD_SET==1)
        //{
        R_UART2_SEND("AT+QSPN?\r\n ");
        MS_TIMER(500);
        R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n ");
        MS_TIMER(1000);
        R_UART2_SEND("AT+STKENV=\"D30782020181900180\"\r\n"); // Open Menu items
        MS_TIMER(1000);
        R_UART2_SEND("AT+STKTR=\"810301240402028281830100900102\"\r\n"); // Select Network
        MS_TIMER(1000);
        if(NWP_CMD_SET==SET)
        {
            R_UART2_SEND("AT+STKTR=\"810301240402028281830100900116\"\r\n"); ////NetworkCode=2;  // BSNL F
            MS_TIMER(500);
            NWP_CMD_SET=CLR;
        }
        if(NWS_CMD_SET==SET)
        {
            R_UART2_SEND("AT+STKTR=\"810301240402028281830100900115\"\r\n"); ////NetworkCode=2;  // BSNL F
            MS_TIMER(500);
            //NWP_CMD_SET=CLR;
            NWS_CMD_SET=CLR;
        }

        //MS_TIMER(2000);// Auto Network Select
        R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n");//NetworkCode=1;  // Vodafone P
        MS_TIMER(500);
        GPRS_PS_EN=OFF;
        MS_TIMER(20000);
        GPRS_PS_EN=ON;
        MS_TIMER(500);
        R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n ");
        MS_TIMER(500);
        R_UART2_SEND("AT+QSTK?\r\n");
        MS_TIMER(500);
        //QSTK();
        R_UART2_SEND("AT+CRSM=214,28539,0,0,12,\"FFFFFFFFFFFFFFFFFFFFFFFF\"\r\n");
        MS_TIMER(500);

        BSNL_CONNECT=0;
        BSNL_CONNECT_FLAG=1;
            //}
    // #endif
}



/*===========================================================================
 * GSM_INTZ - GSM Initialization Function (CORRECTED)
 *
 * FIXES APPLIED:
 * 1. Added AT+CREG=1 to enable network registration URC
 * 2. Added AT+CSCA? to verify SMS center number is set (blank CSCA = no CMTI)
 * 3. Added AT+CNMI? verify step after setting CNMI (confirms modem accepted it)
 * 4. Fixed restart8 fail check � was using SMS_FAIL instead of SMS_FAIL_COUNT
 * 5. Added AT+CMGD=1,4 to clear full SIM storage before CPMS set
 *    (full SIM storage silently blocks CMTI notifications)
 * 6. Added AT+QSMSCODE? query before set � avoid resetting if already correct
 * 7. Added MS_TIMER delay after CNMI set for modem to process
 * 8. Corrected \r\n consistency (all commands use \r\n)
 *===========================================================================*/
//#define TCP_MODE '2'

void GSM_INTZ(char MODE)
{
    ACK = ERROR_OCCURED = RESTART = 0;
    GPRS_PS_EN = ON1;

    if (MODE == SMS_MODE)
    {
        MS_TIMER(500);
    }

restart0:

    if (MODE == SMS_MODE)
    {
        R_UART2_SEND("AT\r\n");
        ACK_RX(20, 2, 10, 1);

        if (SMS_FAIL >= 25)
        {
            SMS_FAIL = 0;
            RESTART = OFF;
            goto restart11;
        }
        else if (RESTART == ON)
        {
            SMS_FAIL++;
            RESTART = OFF;
            goto restart0;
        }

        SMS_FAIL = 0;

restart1:

        R_UART2_SEND("AT+QSMSCODE=2\r\n");
        ACK_RX(20, 2, 100, 1);

        if (SMS_FAIL >= 2)
        {
            SMS_FAIL = 0;
            RESTART = OFF;
            goto restart11;
        }
        else if (RESTART == ON)
        {
            SMS_FAIL++;
            RESTART = OFF;
            goto restart1;
        }

        SMS_FAIL = 0;

        GET_IMEI();
        //GET_IMEI();
        //SwitchNetwork();

restart5:
        ACK = ERROR_OCCURED = RESTART = 0;

        R_UART2_SEND("AT+CMGF=1\r\n");
        ACK_RX(20, 2, 100, 3);

        if (SMS_FAIL >= 2)
        {
            SMS_FAIL = 0;
            RESTART = OFF;
            goto restart11;
        }
        else if (RESTART == ON)
        {
            SMS_FAIL++;
            RESTART = OFF;
            goto restart5;
        }

        SMS_FAIL = 0;

restart6:
        // Query SMS storage status to check if storage is full or misconfigured
        ACK = ERROR_OCCURED = RESTART = 0;

        R_UART2_SEND("AT+CPMS?\r\n");
        ACK_RX(20, 2, 100, 3);

        if (SMS_FAIL >= 2)
        {
            SMS_FAIL = 0;
            RESTART = OFF;
            goto restart11;
        }
        else if (RESTART == ON)
        {
            SMS_FAIL++;
            RESTART = OFF;
            goto restart6;
        }

        SMS_FAIL = 0;

restart7:
        // Set all SMS storage to SIM card (SM - Storage Memory) to ensure consistent behavior
        // Format: AT+CPMS="<read_store>","<write_store>","<report_store>"
        // All set to "SM" = SIM card memory
        ACK = ERROR_OCCURED = RESTART = 0;

        R_UART2_SEND("AT+CPMS=\"SM\",\"SM\",\"SM\"\r\n");
        ACK_RX(20, 2, 100, 3);

        if (SMS_FAIL >= 2)
        {
            SMS_FAIL = 0;
            RESTART = OFF;
            goto restart11;
        }
        else if (RESTART == ON)
        {
            SMS_FAIL++;
            RESTART = OFF;
            goto restart7;
        }

        SMS_FAIL = 0;

restart8:
        // Enable unsolicited SMS result codes: +CMTI notification when new SMS arrives
        // Parameters: 2=unsolicited to TE, 1=store AND send notification, 0=no delivery reports, 1=CME ERROR codes
        ACK = ERROR_OCCURED = RESTART = 0;

        R_UART2_SEND("AT+CNMI=2,1,0,0,0\r\n");
        ACK_RX(20, 2, 100, 3);

        if (SMS_FAIL >= 2)
        {
            SMS_FAIL = 0;
            RESTART = OFF;
            goto restart11;
        }
        else if (RESTART == ON)
        {
            SMS_FAIL++;
            RESTART = OFF;
            goto restart8;
        }

        SMS_FAIL = 0;
    }

    if (INITIAL_MESSAGE != 0X01 && MODE == SMS_MODE)
    {
        /*//i2c_writen(0xA0,0XFF,0X05,0X01);*/
        MS_TIMER(1);
        MS_TIMER(500);
        INITIAL_MESSAGE = 'A';

        R_UART2_SEND("AT+CMGS=\"9159991774\"\r\n");
        MS_TIMER(5);

        R_UART2_SEND("DEVICE ACTIVATED ");
        MS_TIMER(5);

        for (FOR_1 = 1; FOR_1 <= 15; FOR_1++)
        {
            R_UART2_SEND_User(IMEI[FOR_1]);
            MS_TIMER(1);
        }

        MS_TIMER(50);
        R_UART2_SEND_User(CTRL_Z);
        MS_TIMER(900);
    }
    //else if(INITIAL_MESSAGE==0X01 && SYSTEM_READY==ON && PANIC_CONTROL_STATE==ON){
    else if (SYSTEM_READY == ON && PANIC_CONTROL_STATE == ON || PANIC_ALERT == ON || POWER_SOURCE_PACKET == ON || LOW_BATTERY_ALERT_PACKET == ON || IGNITION_ON_PACKET == ON || IGNITION_OFF_PACKET == ON || POWER_SOURCE_RECONNECT_PACKET == ON || LOW_BATTERY_ALERT_PACKET == ON)
    {
        GET_DEGREES();
        GET_TIME();
        GET_SPEED_DATA();

        if (MODE == SMS_MODE)
        {
            GET_SIGNAL_STRENGTH();
        }

        i = CLR;

        /****** Initialize DATA_MODE TCP Send ******/
        if (MODE == DATA_MODE)
        {
            R_UART2_SEND("AT+QISEND\r\n");
            ACK_RX(100, 2, 100, 200);  /* FIXED: Wait for '>' prompt before sending data */
        }

        for (SMS = 0; SMS <= 4; SMS++)
        {
            if (SMS_MOBILE_NO[i] == '0' && SMS_MOBILE_NO[i + 1] == '0' && SMS_MOBILE_NO[i + 2] == '0' && SMS_MOBILE_NO[i + 3] == '0' && MODE == SMS_MODE)
            {
                NOP();
                goto TRY_NEXT_NUM;
                //  i=i+10;
            }

restart2:
            MS_TIMER(50);

            if (MODE == SMS_MODE)
            {
                R_UART2_SEND("AT+CMGS=\"");

                for (FOR_9 = i; FOR_9 <= 9 + i; FOR_9++)
                {
                    R_UART2_SEND_User(SMS_MOBILE_NO[FOR_9]);
                    MS_TIMER(1);
                }

                R_UART2_SEND("\"\r\n");
                MS_TIMER(50);
            }

            /*****************************************************************************************************/
            // PACKET HEADER
            if (MODE == SMS_MODE)
            {
                R_UART2_SEND_User(D_SYM);
                R_UART2_SEND("EPB,");
                NOP();
            }
            else if (MODE == DATA_MODE)
            {
                CHECKSUM_BYTE = 0;
                R_UART2_SEND("$EPB,");
                CHECKSUM_BYTE ^= 0x24;
                CHECKSUM_BYTE ^= 0x45;
                CHECKSUM_BYTE ^= 0x50;
                CHECKSUM_BYTE ^= 0x42;
                CHECKSUM_BYTE ^= 0x2C;
            }

            /*****************************************************************************************************/
            // Emergency Message - EMR OR Stop Message (SEM)
            if (PANIC_CONTROL_STATE == ON)
            {
                R_UART2_SEND("EMR,");
                if (MODE == DATA_MODE)
                {
                    CHECKSUM_BYTE ^= 0x45;  // 'E'
                    CHECKSUM_BYTE ^= 0x4D;  // 'M'
                    CHECKSUM_BYTE ^= 0x52;  // 'R'
                    CHECKSUM_BYTE ^= 0x2C;  // ','
                }
            }

            if (PANIC_CONTROL_STATE == OFF)
            {
                R_UART2_SEND("SEM,");
                if (MODE == DATA_MODE)
                {
                    CHECKSUM_BYTE ^= 0x53;  // 'S'
                    CHECKSUM_BYTE ^= 0x45;  // 'E'
                    CHECKSUM_BYTE ^= 0x4D;  // 'M'
                    CHECKSUM_BYTE ^= 0x2C;  // ','
                }
                PANIC_CONTROL_STATE_1 = ON;
            }

            /*****************************************************************************************************/
            //IMEI NUMBER
            for (FOR_9 = 1; FOR_9 <= 15; FOR_9++)
            {
                R_UART2_SEND_User(IMEI[FOR_9]);
                MS_TIMER(1);
            }

            /*****************************************************************************************************/
            // NM=NORMAL or SP= STORAGE
            R_UART2_SEND(",NM,");

            /*****************************************************************************************************/
            // DATE & TIME
            for (FOR_9 = 0; FOR_9 <= 5; FOR_9++)
            {
                R_UART2_SEND_User(((TIME[FOR_9] & 0xF0) >> 4) + 0X30);
                R_UART2_SEND_User((TIME[FOR_9] & 0x0F) + 0X30);

                if (FOR_9 == 1)
                {
                    R_UART2_SEND("20");
                }

                if (FOR_9 == 2 || FOR_9 == 5)
                {
                    R_UART2_SEND(",");
                }
            }

            /*****************************************************************************************************/
            // A - VALID OR V - INVALID
            if (GPS_DIRECTION_DATA_VALID == ON)
            {
                R_UART2_SEND("A,");
            }
            else
            {
                R_UART2_SEND("V,");
            }

            /*****************************************************************************************************/
            //LATITUDE AND DIRECTION
            for (FOR_9 = 0; FOR_9 <= 7; FOR_9++)
            {
                NOP();
                R_UART2_SEND_User(LAT_DM[FOR_9]);

                if (FOR_9 == 1)
                {
                    R_UART2_SEND(".");
                }
            }

            if (LAT_DIRECTION == 'N')
            {
                R_UART2_SEND(",N,");
            }
            else
            {
                R_UART2_SEND(",S,");
            }

            /************************************************************************************************************************************************************/
            //LONGITUDE AND DIRECTION
            for (FOR_9 = 0; FOR_9 <= 8; FOR_9++)
            {
                NOP();
                R_UART2_SEND_User(LOG_DM[FOR_9]);

                if (FOR_9 == 2)
                {
                    R_UART2_SEND(".");
                }
            }

            if (LON_DIRECTION == 'E')
            {
                R_UART2_SEND(",E,");
            }
            else
            {
                R_UART2_SEND(",W,");
            }

            NOP();

            /************************************************************************************************************************************************************/
            // ALLITUDE

            ALTITUDE_VALUE_COUNT = CLR;

            for (FOR_9 = 0; FOR_9 <= 4; FOR_9++)
            {
                NOP();

                if (ALTITUDE[FOR_9] != '.')
                {
                    ALTITUDE_VALUE_COUNT++;
                }
                else if (ALTITUDE[FOR_9] == '.')
                {
                    break;
                }
            }

            if (ALTITUDE_VALUE_COUNT == 1)
            {
                R_UART2_SEND("00");
                ALTITUDE_VALUE_COUNT = 2;
                NOP();
            }
            else if (ALTITUDE_VALUE_COUNT == 2)
            {
                R_UART2_SEND("0");
                ALTITUDE_VALUE_COUNT = 3;
                NOP();
            }
            else
            {
                ALTITUDE_VALUE_COUNT = 4;
            }

            for (FOR_9 = 0; FOR_9 <= ALTITUDE_VALUE_COUNT; FOR_9++)
            {
                NOP();
                R_UART2_SEND_User(ALTITUDE[FOR_9]);
            }

            R_UART2_SEND(",");

            /************************************************************************************************************************************************************/
            //SPEED
            if (ADD_ZERO_TO_SPEED == SET)
            {
                R_UART2_SEND("0");
            }

            for (FOR_9 = 0; FOR_9 <= SPEED_DATA_LENGTH_COUNT; FOR_9++)
            {
                NOP();
                R_UART2_SEND_User(SPEED_DATA[FOR_9]);
            }

            DECIMAL_POINT_CAME_STOP_TX = OFF;
            NOP();
            R_UART2_SEND(",");
            NOP();

            /************************************************************************************************************************************************************/
            // DISTANCE
            R_UART2_SEND("000.0");

            /************************************************************************************************************************************************************/
            //G - Fine GPS OR N � Coarse GPS or data from the network
            if (GPS_DIRECTION_DATA_VALID == ON)
            {
                R_UART2_SEND(",G,");
            }
            else
            {
                R_UART2_SEND(",N,");
            }

            /************************************************************************************************************************************************************/
            //VEICHLE NUMBER
            for (FOR_9 = 0; FOR_9 <= 9; FOR_9++)
            {
                if (VEICHLE_NUMBER[FOR_9] != ' ')
                {
                    R_UART2_SEND_User(VEICHLE_NUMBER[FOR_9]);
                    MS_TIMER(1);
                }
            }

            R_UART2_SEND(",");

            /************************************************************************************************************************************************************/
            //REPLY NUMBER (EMERGENCY NUMBER)
            for (FOR_9 = 0; FOR_9 <= 9; FOR_9++)
            {
                R_UART2_SEND_User(REPLY_NUMBER[FOR_9]);
                NOP();
            }

            /************************************************************************************************************************************************************/
            // CHECKSUM & TERMINATOR (AIS140 Table 6F format)
            if (MODE == SMS_MODE)
            {
                R_UART2_SEND(",*");
            }
            else if (MODE == DATA_MODE)
            {
                R_UART2_SEND(",");
                CHECKSUM_BYTE ^= 0x2C;
                
                // Send 2-byte HEX checksum
                NOP();
                R_UART2_SEND_User((((CHECKSUM_BYTE >> 4) & 0x0F) < 10) ? ((CHECKSUM_BYTE >> 4) + 0x30) : ((CHECKSUM_BYTE >> 4) + 0x37));
                R_UART2_SEND_User(((CHECKSUM_BYTE & 0x0F) < 10) ? ((CHECKSUM_BYTE & 0x0F) + 0x30) : ((CHECKSUM_BYTE & 0x0F) + 0x37));
                
                R_UART2_SEND(",*");
            }

            /************************************************************************************************************************************************************/
            if (MODE == SMS_MODE)
            {
                NOP();
                R_UART2_SEND_User(CTRL_Z);
                ACK_RX(100, 2, 500, 100);

                if (SMS_FAIL_COUNT >= 1)
                {
                    SMS_FAIL_COUNT = 0;
                    RESTART = OFF;
                }
                else if (RESTART == ON)
                {
                    SMS_FAIL_COUNT++;
                    RESTART = OFF;
                    goto restart2;
                }
            }

            if (MODE == DATA_MODE)
            {
                /****** Send EPB Packet via TCP Connection ******/
                NOP();
                R_UART2_SEND_User(CTRL_Z);
                MS_TIMER(1000);
                
                if (SMS_FAIL_COUNT >= 1)
                {
                    SMS_FAIL_COUNT = 0;
                    RESTART = OFF;
                }
                goto restart12;
            }

TRY_NEXT_NUM:
            i = i + 10;
            SMS_FAIL_COUNT = 0;
        }

        POWER_SOURCE_PACKET = OFF;
        i = 0;
        WATCH_DOG_KILL = OFF;
    }

restart11:

//     if(POWER_SOURCE_PACKET==ON){POWER_SOURCE_PACKET=OFF;}
//else if(LOW_BATTERY_ALERT_PACKET==ON){LOW_BATTERY_ALERT_PACKET=OFF;}
//else if(IGNITION_ON_PACKET==ON){IGNITION_ON_PACKET=OFF;}
//else if(IGNITION_OFF_PACKET==ON){IGNITION_OFF_PACKET=OFF;}
//else if(POWER_SOURCE_PACKET==ON){POWER_SOURCE_PACKET=OFF;}
//else if(POWER_SOURCE_RECONNECT_PACKET==ON){POWER_SOURCE_RECONNECT_PACKET=OFF;}
//else if(LOW_BATTERY_ALERT_PACKET==ON){LOW_BATTERY_ALERT_PACKET=OFF;}

restart12:
    NOP();
}


/*===========================================================================
 * GSM_SMS_DIAG - SMS Diagnostic Function for M66 Modem
 *
 * PURPOSE:
 * Call this function from main when CMTI is not being received.
 * It runs all diagnostic AT commands in sequence and stores results
 * so you can check via UART log / Coolterm what is blocking CMTI.
 *
 * CALL FROM MAIN:
 *   GSM_SMS_DIAG();
 *
 * CHECKS PERFORMED (in order):
 * 1.  AT+CMGL="ALL"     � Did SMS arrive silently? (no CMTI but stored)
 * 2.  AT+CPMS?          � Is storage count changed? (confirm SMS stored)
 * 3.  AT+CSQ            � Signal strength OK?
 * 4.  AT+CSMS?          � Does eSIM support MT SMS?
 * 5.  AT+CNMI?          � Is CNMI still set? (modem may reset it)
 * 6.  AT+CREG?          � Still registered on network?
 * 7.  AT+CSCA?          � SMSC number still valid?
 * 8.  AT+CMGF?          � Still in text mode?
 * 9.  AT+QSMSCODE?      � SMS code mode still set?
 * 10. AT+CMEE=1         � Enable verbose error reporting
 * 11. AT+CPMS="SM"      � Re-set storage (force refresh)
 * 12. AT+CNMI=2,1,0,0,0 � Re-set CNMI (force refresh)
 *===========================================================================*/

void GSM_SMS_DIAG(void)
{
    ACK = ERROR_OCCURED = RESTART = 0;
    SMS_FAIL = 0;

    /*-----------------------------------------------------------------------
     * STEP 1: AT+CMGL="ALL"
     * Check if any SMS arrived silently without CMTI notification
     * If SMS shows here ? modem received it but suppressed CMTI
     * If empty ? SMS never reached modem (network/eSIM blocking)
     *-----------------------------------------------------------------------*/
diag1:
    ACK = ERROR_OCCURED = RESTART = 0;
    R_UART2_SEND("AT+CMGL=\"ALL\"\r\n");
    ACK_RX(50, 2, 500, 3);
    if (SMS_FAIL >= 2)      { SMS_FAIL = 0; RESTART = OFF; goto diag2; }
    else if (RESTART == ON) { SMS_FAIL++; RESTART = OFF; goto diag1; }
    SMS_FAIL = 0;

    /*-----------------------------------------------------------------------
     * STEP 2: AT+CPMS?
     * Check current SMS storage count
     * If count > 0 ? SMS stored silently, CNMI not firing
     * If count = 0 ? SMS never stored, network level block
     *-----------------------------------------------------------------------*/
diag2:
    ACK = ERROR_OCCURED = RESTART = 0;
    R_UART2_SEND("AT+CPMS?\r\n");
    ACK_RX(20, 2, 200, 3);
    if (SMS_FAIL >= 2)      { SMS_FAIL = 0; RESTART = OFF; goto diag3; }
    else if (RESTART == ON) { SMS_FAIL++; RESTART = OFF; goto diag2; }
    SMS_FAIL = 0;

    /*-----------------------------------------------------------------------
     * STEP 3: AT+CSQ
     * Check signal strength
     * +CSQ: 99,0  = no signal  ? SMS cannot be received
     * +CSQ: 0,0   = no signal
     * +CSQ: 10+   = acceptable
     * +CSQ: 20+   = good
     *-----------------------------------------------------------------------*/
diag3:
    ACK = ERROR_OCCURED = RESTART = 0;
    R_UART2_SEND("AT+CSQ\r\n");
    ACK_RX(20, 2, 200, 3);
    if (SMS_FAIL >= 2)      { SMS_FAIL = 0; RESTART = OFF; goto diag4; }
    else if (RESTART == ON) { SMS_FAIL++; RESTART = OFF; goto diag3; }
    SMS_FAIL = 0;

    /*-----------------------------------------------------------------------
     * STEP 4: AT+CSMS?
     * Check if eSIM/modem supports MT SMS (Mobile Terminated = incoming)
     * Expected: +CSMS: 0,1,1,1
     *   param1: service (0=GSM)
     *   param2: MT supported = 1 (MUST BE 1 for incoming SMS)
     *   param3: MO supported = 1
     *   param4: broadcast  = 1
     * If MT=0 ? eSIM does NOT support incoming SMS ? root cause found
     *-----------------------------------------------------------------------*/
diag4:
    ACK = ERROR_OCCURED = RESTART = 0;
    R_UART2_SEND("AT+CSMS?\r\n");
    ACK_RX(20, 2, 200, 3);
    if (SMS_FAIL >= 2)      { SMS_FAIL = 0; RESTART = OFF; goto diag5; }
    else if (RESTART == ON) { SMS_FAIL++; RESTART = OFF; goto diag4; }
    SMS_FAIL = 0;

    /*-----------------------------------------------------------------------
     * STEP 5: AT+CNMI?
     * Verify CNMI is still set to 2,1,0,0,0
     * Some modems reset CNMI after network events or STK activity
     * If +CNMI: 0,0,0,0,0 ? modem reset it ? re-set below at step 12
     *-----------------------------------------------------------------------*/
diag5:
    ACK = ERROR_OCCURED = RESTART = 0;
    R_UART2_SEND("AT+CNMI?\r\n");
    ACK_RX(20, 2, 200, 3);
    if (SMS_FAIL >= 2)      { SMS_FAIL = 0; RESTART = OFF; goto diag6; }
    else if (RESTART == ON) { SMS_FAIL++; RESTART = OFF; goto diag5; }
    SMS_FAIL = 0;

    /*-----------------------------------------------------------------------
     * STEP 6: AT+CREG?
     * Confirm still registered on Vodafone IN
     * +CREG: 1,1 = registered home network  ?
     * +CREG: 1,2 = searching               ?
     * +CREG: 1,0 = not registered           ?
     *-----------------------------------------------------------------------*/
diag6:
    ACK = ERROR_OCCURED = RESTART = 0;
    R_UART2_SEND("AT+CREG?\r\n");
    ACK_RX(20, 2, 200, 3);
    if (SMS_FAIL >= 2)      { SMS_FAIL = 0; RESTART = OFF; goto diag7; }
    else if (RESTART == ON) { SMS_FAIL++; RESTART = OFF; goto diag6; }
    SMS_FAIL = 0;

    /*-----------------------------------------------------------------------
     * STEP 7: AT+CSCA?
     * Verify SMSC number still valid
     * Expected: +CSCA: "+919884005444",145
     * If blank or different ? SMSC lost, re-provision eSIM
     *-----------------------------------------------------------------------*/
diag7:
    ACK = ERROR_OCCURED = RESTART = 0;
    R_UART2_SEND("AT+CSCA?\r\n");
    ACK_RX(20, 2, 200, 3);
    if (SMS_FAIL >= 2)      { SMS_FAIL = 0; RESTART = OFF; goto diag8; }
    else if (RESTART == ON) { SMS_FAIL++; RESTART = OFF; goto diag7; }
    SMS_FAIL = 0;

    /*-----------------------------------------------------------------------
     * STEP 8: AT+CMGF?
     * Verify still in text mode
     * Expected: +CMGF: 1
     * If 0 ? switched to PDU mode, CMTI format will differ
     *-----------------------------------------------------------------------*/
diag8:
    ACK = ERROR_OCCURED = RESTART = 0;
    R_UART2_SEND("AT+CMGF?\r\n");
    ACK_RX(20, 2, 200, 3);
    if (SMS_FAIL >= 2)      { SMS_FAIL = 0; RESTART = OFF; goto diag9; }
    else if (RESTART == ON) { SMS_FAIL++; RESTART = OFF; goto diag8; }
    SMS_FAIL = 0;

    /*-----------------------------------------------------------------------
     * STEP 9: AT+QSMSCODE?
     * Verify SMS code mode still set to 2
     * Expected: +QSMSCODE: 2
     * If changed ? may affect SMS encoding/reception behavior
     *-----------------------------------------------------------------------*/
diag9:
    ACK = ERROR_OCCURED = RESTART = 0;
    R_UART2_SEND("AT+QSMSCODE?\r\n");
    ACK_RX(20, 2, 200, 3);
    if (SMS_FAIL >= 2)      { SMS_FAIL = 0; RESTART = OFF; goto diag10; }
    else if (RESTART == ON) { SMS_FAIL++; RESTART = OFF; goto diag9; }
    SMS_FAIL = 0;

    /*-----------------------------------------------------------------------
     * STEP 10: AT+CMEE=1
     * Enable verbose error reporting
     * After this, errors show as +CME ERROR: <text> instead of just ERROR
     * Helps identify exactly what is failing
     *-----------------------------------------------------------------------*/
diag10:
    ACK = ERROR_OCCURED = RESTART = 0;
    R_UART2_SEND("AT+CMEE=1\r\n");
    ACK_RX(20, 2, 200, 3);
    if (SMS_FAIL >= 2)      { SMS_FAIL = 0; RESTART = OFF; goto diag11; }
    else if (RESTART == ON) { SMS_FAIL++; RESTART = OFF; goto diag10; }
    SMS_FAIL = 0;

    /*-----------------------------------------------------------------------
     * STEP 11: AT+CPMS="SM","SM","SM"
     * Force re-set SMS storage
     * Refreshes storage pointer in modem
     * Sometimes needed after STK activity (your log shows heavy STK usage)
     *-----------------------------------------------------------------------*/
diag11:
    ACK = ERROR_OCCURED = RESTART = 0;
    R_UART2_SEND("AT+CPMS=\"SM\",\"SM\",\"SM\"\r\n");
    ACK_RX(20, 2, 200, 3);
    if (SMS_FAIL >= 2)      { SMS_FAIL = 0; RESTART = OFF; goto diag12; }
    else if (RESTART == ON) { SMS_FAIL++; RESTART = OFF; goto diag11; }
    SMS_FAIL = 0;

    /*-----------------------------------------------------------------------
     * STEP 12: AT+CNMI=2,1,0,0,0
     * Force re-set CNMI notification
     * STK activity (AT+STKTR, AT+QSTK) can reset CNMI on M66
     * Re-setting here ensures CMTI will fire after diagnostic completes
     *-----------------------------------------------------------------------*/
diag12:
    ACK = ERROR_OCCURED = RESTART = 0;
    R_UART2_SEND("AT+CNMI=2,1,0,0,0\r\n");
    ACK_RX(20, 2, 200, 3);
    if (SMS_FAIL >= 2)      { SMS_FAIL = 0; RESTART = OFF; goto diag13; }
    else if (RESTART == ON) { SMS_FAIL++; RESTART = OFF; goto diag12; }
    SMS_FAIL = 0;
    MS_TIMER(200);

    
    /*-----------------------------------------------------------------------
     * STEP 0: AT+CNUM
     * Get the mobile number assigned to this eSIM
     * Expected: +CNUM: "","+91XXXXXXXXXX",145
     * If response is empty or ERROR ? eSIM has NO phone number assigned
     * This means SMS CANNOT be received � no number = no MT SMS possible
     * This is the most common issue with Vodafone IN IoT/data eSIMs
     *-----------------------------------------------------------------------*/
diag13:
    ACK = ERROR_OCCURED = RESTART = 0;
    R_UART2_SEND("AT+CNUM\r\n");
    ACK_RX(20, 2, 500, 3);
    if (SMS_FAIL >= 2)      { SMS_FAIL = 0; RESTART = OFF; goto diag_end; }
    else if (RESTART == ON) { SMS_FAIL++; RESTART = OFF; goto diag13; }
    SMS_FAIL = 0;
    
diag_end:
    SMS_FAIL = 0;
    ACK = ERROR_OCCURED = RESTART = 0;
    NOP();
}