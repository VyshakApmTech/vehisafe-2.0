#include "r_cg_userdefine.h"

extern char RX_ACK_Frame,ACK,ERROR_OCCURED,RX_SMS_CMD,RX_CMD_SMS[10],t,SMS_FAIL_COUNT,SMS_FAIL,NETWORK_NAME_RX,BATTERY_MEASUREMENT;
extern char INITIAL_MESSAGE,P_LAT_DM_RX,FILE_CLOSE_ATTEMPT;
extern char GSM_REG,GPRS_REG,SS_DATA_RX,GET_SS,dBm,SMS_MOBILE_NO[55];
extern char GPRS_CONNECTED,RESTART,GSM_STRENGTH,INTERNET_CONNECTED,DISCONNECT,LOW_BATTERY_ALERT,HTTP_CONNECT_COUNT,VEICHLE_NUMBER[15],NW_NAME_RX,IMEI[16];
extern unsigned int FOR_1,FOR_3,Address_1,NW_REGN_COUNT,FLASH_MEMORY,GPRS_REG_COUNT,MAIN_BATTERY_VOLTAGE,ADC_BUFFER,BACKUP_BATTERY_VOLTAGE,GPRS_REG_ROAMING,GSM_REG_ROAMING,T_SPEED,FILTER,DATA_HEADER,TEMP_VERSION;
extern unsigned int t_count,WRITE_ADDRESS,DATA,WATCH_DOG_KILL,WRITE_ADDRESS,TEMPS,WRITE_ADDRESS_MSB,WRITE_ADDRESS_LSB,BYTE;
extern char LOG_DM[10],LAT_DM[10],TIME[10],GPS_BUSY,SPEED[4],/*GPS_RX,*/SPEED_DATA_RX[10],WATCH_DOG,FILE[150],I[100];
extern char GPS_DIRECTION_DATA_VALID,IGNITION,PANIC_ALERT,PANIC_ALERT_PACKET,IGNITION_ON_PACKET,IGNITION_OFF_PACKET,POWER_SOURCE_PACKET,LOW_BATTERY_ALERT_PACKET;
extern char GPS_RST_FLAG,HOURS_MSB,HOURS_LSB,MIN_MSB,MIN_LSB,LON_DIRECTION,LAT_DIRECTION,LAT_DM_RX[10],LOG_DM_RX[10],COG[6],GPGA_DATA[10],ALTITUDE[8],HDOP[5],NO_OF_SAT,NAVIGATION_ACK,NAVIGATION_RX,GPS_RESTART;

extern char Array_0[10],i,SMS,NETWORK_FAILURE,HTTP_PRINT,SPEED_DATA[10];
extern char NETWORK_NAME[8],SS_DATA_RX,FIRM_DATA[150];
//extern char GSM_NW_REG[8],GPRS_NW_REG[9];
//extern char GET_IN_SMS[4],CONNECT_ACK[7],SIGNAL_STRENGTH_ACK[5],NW_DIS_CONNECT[9];

extern char CPIN;
extern char P_LAT_DM[10],P_TIME[10],P_SEND_TIME[10],P_LOG_DM[10],P_SEND_LOG_DM[10],P_SEND_LAT_DM[10],FTP_ADDRESS[8],FTP_CONNECT_COUNT;
extern char FILE_ADDR,V_NO_LEN;
extern unsigned int CHECKSUM_BYTE,MN,VERSION_TEMP,FRM_VERSION,CURRENT_FRM_VERSION,HEX;
extern _Bool WELCOME_STRING_FRAME,FIRMWARE_UPDATE,IGNITION_CONTROL_STATE,POWER_SOURCE,SYSTEM_READY,NORMAL_PACKET,HEALTH_PACKET_TO_SERVER,IGNITION_ON_PACKET_SENT,IGNITION_OFF_PACKET_SENT;
extern _Bool HTTP_DOWNLOAD_ACK,FTP_ACK,FTP_DOWNLOAD_ACK,FIRMWARE_DOWNLOADED,FILE_ACK,FILE_DOWNLOAD,FLAG,STOP_FILE_READING,IMEI_RX,IMEI_ACK_RX;
extern _Bool GPS_STANDBY,WATCH_DOG_FORCE_KILL,RTC_DONE,POWER_SOURCE_RECONNECT_PACKET,VLT_STARTUP,PANIC_TIME_START,PANIC_TIME_STOP,PANIC_CONTROL_STATE_1;
extern unsigned int MINUTE,UPDATE_TIME,TEMP_MAIN_BATTERY_VOLTAGE,PANIC_TIME,I_HOURS;
extern int AD;
extern char p1,p2,p3,p4,LB_LEVEL;
//extern char FIRM_UPDATE_CTRL[3],PANIC_CTRL[4];
extern char PANIC_CTRL_RX,PANIC_CONTROL_STATE,PANIC_CONTROL_RX,FIRM_UPDATE_CTRL_RX,FIRM_UPDATE_CONTROL_STATE,FIRM_UPDATE_CONTROL_RX,MAIN_BAT_STATUS;
extern _Bool LOW_BATTER_ALERT_SEND,BATTERY_CHARGED_PACKET;
	
_Bool VLT_STARTUP_INITIAL,RS_ALERT_UPDATE,PS_ALERT_UPDATE,LB_ALERT_SEND;	
extern unsigned int UPDATE_TIME_ON_TIME,UPDATE_TIME_OFF_TIME,LOW_BAT_LEVEL;
unsigned int A_COUNT,AVERAGE[10];
unsigned long int Test,Ax,Ay,Az;
char INT_BAT_PERCENTAGE;

#define SIGNAL_PATH_RESET  0x68
#define I2C_SLV0_ADDR      0x37
#define ACCEL_CONFIG       0x1C 
#define MOT_THR            0x1F  // Motion DETECTion threshold bits [7:0]
#define MOT_DUR            0x20  // Duration counter threshold for motion interrupt generation, 1 kHz rate, LSB = 1 ms
#define MOT_DETECT_CTRL    0x69
#define INT_ENABLE         0x38
//#define WHO_AM_I_MPU6050   0x75 // Should return 0x68
#define WHO_AM_I_MPU6050   0x0F  // SHOULD RETURN 0x6A
#define INT_STATUS 0x3A

   
//      #define SIGNAL_PATH_RESET  0x68
//      #define I2C_SLV0_ADDR      0x37
//      #define ACCEL_CONFIG       0x1C 
//      #define MOT_THR            0x1F  // Motion DETECTion threshold bits [7:0]
//      #define MOT_DUR            0x20  // Duration counter threshold for motion interrupt generation, 1 kHz rate, LSB = 1 ms
//      #define MOT_DETECT_CTRL    0x69
//      #define INT_ENABLE         0x38
//      #define WHO_AM_I_MPU6050   0x75 // Should return 0x68
//      #define INT_STATUS	 0x3A
      #define MPU6050_ADDRESS    0xD4//0xD0


void SYSTEM_STATUS(void)
{
    if(IGNITION_SW==CLOSE)
    {
        //UPDATE_TIME_ON_TIME=5;
        IGNITION=ON;
        IGNITION_OFF_PACKET=OFF;  // Clear stuck OFF flag when ignition closes
        IGNITION_OFF_PACKET_SENT=OFF;  // Reset gate so OFF packet can be sent on next OFF event
        
        GPRS_PS_EN=ON;

        if(VLT_STARTUP==CLR && IGNITION_ON_PACKET==OFF && NORMAL_PACKET==ON)
        {
            NORMAL_PACKET=OFF;
            IGNITION_ON_PACKET=ON;
            VLT_STARTUP=SET;
            WELCOME_STRING_FRAME=ON;
        }
        else if(IGNITION_ON_PACKET==OFF && NORMAL_PACKET==OFF)
        {
        IGNITION_ON_PACKET=ON;
        }
        else if(IGNITION_ON_PACKET==ON  && NORMAL_PACKET==OFF)
        {
            IGNITION_OFF_PACKET=OFF;
            IGNITION_ON_PACKET=ON; 
            NORMAL_PACKET=ON;
        }
        else if(IGNITION_ON_PACKET==ON  && NORMAL_PACKET==ON)
        {
        IGNITION_ON_PACKET=OFF;
        NORMAL_PACKET=ON;
        }
        else if(IGNITION_OFF_PACKET==ON && NORMAL_PACKET==ON)
        {
        IGNITION_OFF_PACKET=IGNITION_ON_PACKET=OFF;
        NORMAL_PACKET=ON;
        }
    }

    if(IGNITION_SW==OPEN)
    {
        IGNITION=OFF;
        IGNITION_ON_PACKET=OFF;  // Clear stuck ON flag when ignition opens
        IGNITION_ON_PACKET_SENT=OFF;  // Reset gate so IN packet can be sent on next ON event
        IGNITION_OFF_PACKET=ON;
        if(VLT_STARTUP==SET && NORMAL_PACKET==ON)
        {
            NORMAL_PACKET=OFF;
            IGNITION_OFF_PACKET=ON;
        }
        else if(IGNITION_OFF_PACKET == ON && IGNITION_OFF_PACKET_SENT == OFF)
        {
            IGNITION_OFF_PACKET= ON;
            IGNITION_OFF_PACKET_SENT = OFF;
        }
        // else if(IGNITION_OFF_PACKET==OFF && NORMAL_PACKET==OFF)
        // {
        //     IGNITION_OFF_PACKET=ON;
        // }
        // else if(IGNITION_OFF_PACKET==ON  && NORMAL_PACKET==OFF)
        // {
        //     IGNITION_OFF_PACKET=OFF; 
        //     NORMAL_PACKET=ON;
        // }
        // else if(IGNITION_OFF_PACKET==ON  && NORMAL_PACKET==ON)
        // {
        //     IGNITION_OFF_PACKET=OFF;
        //     NORMAL_PACKET=ON;
        // }
        // else if(IGNITION_ON_PACKET==ON &&  NORMAL_PACKET==ON)
        // {
        //     IGNITION_OFF_PACKET=IGNITION_ON_PACKET=OFF;
        //     NORMAL_PACKET=ON;
        // }
    }
}

void VLT_RUNNING_MODE(void)
{
    //WATCHDOG_ON();
    //UPDATE_ONLINE_DATA_FRAME();
    //WATCHDOG_OFF();

    /*************************************************************************************/
    // MODE:- IGNITION ON
    /*************************************************************************************/
    if(IGNITION_SW==CLOSE)
    {
        //UPDATE_TIME_ON_TIME=5;
        GPRS_PS_EN=ON1;
        MS_TIMER(1500);

        //R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n ");  // ← REMOVED: Hardcoded network switch
        //MS_TIMER(500);
        //R_UART2_SEND("AT+QSTK?\r\n");
        //MS_TIMER(500);
        //QSTK();
        //R_UART2_SEND("AT+CRSM=214,28539,0,0,12,\"FFFFFFFFFFFFFFFFFFFFFFFF\"\r\n");
        //MS_TIMER(300);

        //     if(VLT_STARTUP==CLR && IGNITION_ON_PACKET==OFF && NORMAL_PACKET==ON){NORMAL_PACKET=OFF;IGNITION_ON_PACKET=ON;}
        //else if(IGNITION_ON_PACKET==OFF && NORMAL_PACKET==OFF){IGNITION_ON_PACKET=ON;}
        //else if(IGNITION_ON_PACKET==ON  && NORMAL_PACKET==OFF){IGNITION_ON_PACKET=OFF; NORMAL_PACKET=ON;}
        //else if(IGNITION_ON_PACKET==ON  && NORMAL_PACKET==ON){IGNITION_ON_PACKET=OFF; NORMAL_PACKET=ON;}
        //else if(IGNITION_OFF_PACKET==ON && NORMAL_PACKET==ON){IGNITION_OFF_PACKET=IGNITION_ON_PACKET=OFF; NORMAL_PACKET=ON;}

        if(MINUTE>=10)
        {
            /* Health packet trigger every 5 minutes (30 cycles × 10 sec = 300 sec) */
            static unsigned int health_packet_cycle_count = 0;

            WATCHDOG_ON();
            VLT_STARTUP=CLR;
            //MINUTE=0;
            IGNITION=ON;

            health_packet_cycle_count++;

            if(health_packet_cycle_count >= 10)
            {
                health_packet_cycle_count = 0;
                HEALTH_PACKET_TO_SERVER = ON;  /* Trigger health packet */
            }

            R_TAU0_Channel0_Stop();
            MINUTE=I_HOURS=CLR;//INTERNET_CONNECTED=2;
            UPDATE_ONLINE_DATA_FRAME();
            R_TAU0_Channel0_Start();
            VLT_STARTUP_INITIAL=SET;
            WATCHDOG_OFF();
        }
    }

    /*************************************************************************************/
    // MODE:- IGNITION OFF
    /*************************************************************************************/
    if(IGNITION_SW==OPEN)
    {
        IGNITION=OFF;

        //     if(VLT_STARTUP==SET && NORMAL_PACKET==ON){NORMAL_PACKET=OFF;IGNITION_OFF_PACKET=ON;}
        //else if(IGNITION_OFF_PACKET==OFF && NORMAL_PACKET==OFF){IGNITION_OFF_PACKET=ON;}
        //else if(IGNITION_OFF_PACKET==ON  && NORMAL_PACKET==OFF){IGNITION_OFF_PACKET=OFF; NORMAL_PACKET=ON;}
        //else if(IGNITION_OFF_PACKET==ON  && NORMAL_PACKET==ON){IGNITION_OFF_PACKET=OFF; NORMAL_PACKET=ON;}
        //else if(IGNITION_ON_PACKET==ON &&  NORMAL_PACKET==ON){IGNITION_OFF_PACKET=IGNITION_ON_PACKET=OFF; NORMAL_PACKET=ON;}

        if(IGNITION_OFF_PACKET == ON && IGNITION_OFF_PACKET_SENT == OFF)
        {
            UPDATE_ONLINE_DATA_FRAME();   // DATA_PRINT will select IF,08
            R_TAU0_Channel0_Start();
            GPRS_DISCONNECT();
        }
        
        if(MINUTE>=600)
        {
            WATCHDOG_ON();
            GPRS_PS_EN=ON1;
            MS_TIMER(1500);

            //R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n ");  // ← REMOVED: Hardcoded network switch
            //MS_TIMER(500);
            //R_UART2_SEND("AT+QSTK?\r\n");
            //MS_TIMER(500);
            //QSTK();
            //R_UART2_SEND("AT+CRSM=214,28539,0,0,12,\"FFFFFFFFFFFFFFFFFFFFFFFF\"\r\n");
            //MS_TIMER(300);

            R_TAU0_Channel0_Stop();
            MINUTE=I_HOURS=CLR;
            UPDATE_ONLINE_DATA_FRAME();
            R_TAU0_Channel0_Start();
            GPRS_DISCONNECT();
            INTERNET_CONNECTED=OFF;
            GPRS_PS_EN=OFF1;
            R_TAU0_Channel0_Start();
            WATCHDOG_OFF();
        }
    }

    ///*************************************************************************************/
    //// MODE:- STARTUP
    ///*************************************************************************************/
    if(VLT_STARTUP_INITIAL==SET && IGNITION_SW==OPEN)
    {
        WATCHDOG_ON();
        IGNITION=OFF;
        NORMAL_PACKET=OFF;
        GPRS_PS_EN=ON1;
        MS_TIMER(1500);

        //R_UART2_SEND("AT+STKTR=\"810301250082028281830100\"\r\n ");  // ← REMOVED: Hardcoded network switch
        //MS_TIMER(500);
        //R_UART2_SEND("AT+QSTK?\r\n");
        //MS_TIMER(500);
        //QSTK();
        //R_UART2_SEND("AT+CRSM=214,28539,0,0,12,\"FFFFFFFFFFFFFFFFFFFFFFFF\"\r\n");
        //MS_TIMER(300);

        R_TAU0_Channel0_Stop();
        UPDATE_ONLINE_DATA_FRAME();
        R_TAU0_Channel0_Start();
        GPRS_DISCONNECT();
        INTERNET_CONNECTED=OFF;
        GPRS_PS_EN=OFF1;
        R_TAU0_Channel0_Start();
        VLT_STARTUP=CLR;
        VLT_STARTUP_INITIAL=CLR;
        WATCHDOG_OFF();
    }

    ///*************************************************************************************/
    //// SEND UNTILL PANIC DURATION
    ///*************************************************************************************/

    //if(PANIC_TIME_START==SET || PANIC_TIME_STOP==SET)
    //{
    //    WATCHDOG_ON();
    //    MS_TIMER(10);
    //    GPRS_PS_EN=ON1;
    //    //UPDATE_ONLINE_DATA_FRAME();
    //    WATCHDOG_OFF();
    //}
}	 
	 
	 
	 
	

void SYSTEM_ALERT_CHECK(void)
{

    if(PANIC_ALERT==1)
    {
        uint8_t i;
        PANIC_ALERT_PACKET=ON;
        WATCHDOG_ON();
        PANIC_TIME_START=ON;
        PANIC_TIME=CLR;
        GPRS_PS_EN=ON1;
        MS_TIMER(1);
        //GSM_INTZ(SMS_MODE);  // ← Commented: SMS via phone numbers
        PANIC_CONTROL_STATE = ON;  // Set ON for packets 1-5 (EMR type)
        for (i = 1; i <= 5; i++)
        {
            GSM_INTZ(DATA_MODE);          // ← EPB via TCP (packets 1-5: EMR)
            UPDATE_ONLINE_DATA_FRAME();   // ← PVT via TCP (packets 1-5: EA,10)
        }
        // Send 6th packet separately to guarantee execution
        PANIC_CONTROL_STATE = OFF;       // 6th packet: SEM type
        PANIC_CONTROL_STATE_1 = ON;      // 6th packet: EA,11 type
        GSM_INTZ(DATA_MODE);             // ← 6th EPB: SEM
        UPDATE_ONLINE_DATA_FRAME();      // ← 6th PVT: EA,11 (clears PANIC_TIME_START)
        PANIC_ALERT=0;
        PANIC_ALERT_PACKET=OFF;
        WATCHDOG_OFF();
    }
    
    if(IGNITION_ON_PACKET==ON || IGNITION_OFF_PACKET==ON)
    {
        WATCHDOG_ON();
        //GPRS_PS_EN=ON1;
        MS_TIMER(1);
        if(INTERNET_CONNECTED==NONE){GSM_INTZ(SMS_MODE);}
        WATCHDOG_OFF();	
    }
    if(GPS_RST_FLAG==ON)
    {
        R_UART1_Stop();
        GPS_RST=ON;
        GPS_RST_FLAG=CLR;
        MS_TIMER(500);
        GPS_RST=OFF;
        //R_UART1_Start();
        //R_UART1_SEND("$PSTMSRR\r\n");MS_TIMER(500);	     
    }

    if(MAIN_BAT_STATUS==ON && SYSTEM_READY==ON && RS_ALERT_UPDATE==OFF)
    {
        PS_ALERT_UPDATE=OFF;
        RS_ALERT_UPDATE=ON;
        POWER_SOURCE_RECONNECT_PACKET=ON;
        WATCHDOG_ON();
        //GPRS_PS_EN=ON1;
        MS_TIMER(1);
        if(INTERNET_CONNECTED==NONE)
        {
            GSM_INTZ(SMS_MODE);
        }
        //UPDATE_ONLINE_DATA_FRAME();
        //PANIC_ALERT=0;
        POWER_SOURCE_RECONNECT_PACKET=OFF;
        WATCHDOG_OFF();
    }
    if(MAIN_BAT_STATUS==OFF && SYSTEM_READY==ON && PS_ALERT_UPDATE==OFF)
    {
        PS_ALERT_UPDATE=ON;
        RS_ALERT_UPDATE=OFF;
        POWER_SOURCE_PACKET=ON;
        WATCHDOG_ON();
        //GPRS_PS_EN=ON1;
        MS_TIMER(1);
        if(INTERNET_CONNECTED==NONE)
        {
            GSM_INTZ(SMS_MODE);
        }
        //UPDATE_ONLINE_DATA_FRAME();
        //PANIC_ALERT=0;
        POWER_SOURCE_PACKET=OFF;
        WATCHDOG_OFF();
    }

    BATTERY_PERCENTAGE_CALC();

    if(INT_BAT_PERCENTAGE<=LOW_BAT_LEVEL && LB_ALERT_SEND==OFF)
    {
        LOW_BATTERY_ALERT_PACKET=SET;
        LB_ALERT_SEND=SET;
        WATCHDOG_ON();
        //GPRS_PS_EN=ON1;
        MS_TIMER(1);
        //UPDATE_ONLINE_DATA_FRAME();
        if(INTERNET_CONNECTED==NONE){GSM_INTZ(SMS_MODE);}
        LOW_BATTERY_ALERT_PACKET=CLR;
        WATCHDOG_OFF();
    }

    if(INT_BAT_PERCENTAGE>LOW_BAT_LEVEL && LB_ALERT_SEND==ON)
    {
        BATTERY_CHARGED_PACKET=SET;
        LB_ALERT_SEND=OFF;
        WATCHDOG_ON();
        //GPRS_PS_EN=ON1;
        MS_TIMER(1);
        //UPDATE_ONLINE_DATA_FRAME();
        if(INTERNET_CONNECTED==NONE){GSM_INTZ(SMS_MODE);}
        BATTERY_CHARGED_PACKET=CLR;
        WATCHDOG_OFF();
    }







    if(SYSTEM_READY==OFF)
    {
        SYSTEM_READY=ON;
        R_INTC3_Start();
        R_TAU0_Channel4_Start();
    }

    //if(IGNITION_SW==CLOSE)
    //{
    ////UPDATE_TIME_ON_TIME=5;
    ////GPRS_PS_EN=ON1;
    //     if(VLT_STARTUP==CLR && IGNITION_ON_PACKET==OFF && NORMAL_PACKET==ON){NORMAL_PACKET=OFF;IGNITION_ON_PACKET=ON;}
    //else if(IGNITION_ON_PACKET==OFF && NORMAL_PACKET==OFF){IGNITION_ON_PACKET=ON;}
    //else if(IGNITION_ON_PACKET==ON  && NORMAL_PACKET==OFF){IGNITION_ON_PACKET=OFF; NORMAL_PACKET=ON;}
    //else if(IGNITION_ON_PACKET==ON  && NORMAL_PACKET==ON){IGNITION_ON_PACKET=OFF; NORMAL_PACKET=ON;}
    //else if(IGNITION_OFF_PACKET==ON && NORMAL_PACKET==ON){IGNITION_OFF_PACKET=IGNITION_ON_PACKET=OFF; NORMAL_PACKET=ON;}
    ////if(MINUTE>=UPDATE_TIME_ON_TIME)
    ////{
    ////MINUTE=I_HOURS=CLR;
    ////WATCHDOG_ON();
    //VLT_STARTUP=SET;
    //////MINUTE=0;
    //IGNITION=ON;
    ////R_TAU0_Channel0_Stop();
    //////INTERNET_CONNECTED=2;
    ////UPDATE_ONLINE_DATA_FRAME();
    ////R_TAU0_Channel0_Start();
    ////WATCHDOG_OFF();
    ////}
    //}
    /*************************************************************************************/
    // MODE:- IGNITION OFF
    /*************************************************************************************/
    //if(IGNITION_SW==OPEN)
    //{
    //IGNITION=OFF;
    //     if(VLT_STARTUP==SET && NORMAL_PACKET==ON){NORMAL_PACKET=OFF;IGNITION_OFF_PACKET=ON;}
    //else if(IGNITION_OFF_PACKET==OFF && NORMAL_PACKET==OFF){IGNITION_OFF_PACKET=ON;}
    //else if(IGNITION_OFF_PACKET==ON  && NORMAL_PACKET==OFF){IGNITION_OFF_PACKET=OFF; NORMAL_PACKET=ON;}
    //else if(IGNITION_OFF_PACKET==ON  && NORMAL_PACKET==ON){IGNITION_OFF_PACKET=OFF; NORMAL_PACKET=ON;}
    //else if(IGNITION_ON_PACKET==ON &&  NORMAL_PACKET==ON){IGNITION_OFF_PACKET=IGNITION_ON_PACKET=OFF; NORMAL_PACKET=ON;}
    //if(MINUTE>=UPDATE_TIME_OFF_TIME*3600)
    //{
    //MINUTE=I_HOURS=CLR;
    //WATCHDOG_ON();
    //GPRS_PS_EN=ON1;
    //R_TAU0_Channel0_Stop();
    //UPDATE_ONLINE_DATA_FRAME();
    //R_TAU0_Channel0_Start();
    //GPRS_DISCONNECT();
    //INTERNET_CONNECTED=OFF;
    ////GPRS_PS_EN=OFF1;
    //R_TAU0_Channel0_Start();
    //WATCHDOG_OFF();
    //}
    //}

    if(VLT_STARTUP==SET && IGNITION_SW==OPEN)
    {
        //WATCHDOG_ON();
        IGNITION=OFF;
        NORMAL_PACKET=OFF;
        //GPRS_PS_EN=ON1;
        //R_TAU0_Channel0_Stop();
        //UPDATE_ONLINE_DATA_FRAME();
        //R_TAU0_Channel0_Start();
        //GPRS_DISCONNECT();
        INTERNET_CONNECTED=OFF;
        //GPRS_PS_EN=OFF1;
        //R_TAU0_Channel0_Start();
        VLT_STARTUP=CLR;
        //WATCHDOG_OFF();
    }
    /*************************************************************************************/	 
    // SEND UNTILL PANIC DURATION
    /*************************************************************************************/	 

    if(PANIC_TIME_START==SET || PANIC_TIME_STOP==SET)
    {
        WATCHDOG_ON();
        MS_TIMER(10);
        //GPRS_PS_EN=ON1;
        //UPDATE_ONLINE_DATA_FRAME();
        WATCHDOG_OFF();	
    }
}
void BATTERY_PERCENTAGE_CALC(void)
{
BATTERY_MEASUREMENT=ON;MS_TIMER(10);
BACKUP_BATTERY_VOLTAGE=BACKUP_BATTERY_VOLTAGE%1000;
     if(BACKUP_BATTERY_VOLTAGE<=330 ){INT_BAT_PERCENTAGE=1;}
else if(BACKUP_BATTERY_VOLTAGE>=330 && BACKUP_BATTERY_VOLTAGE<345 ){INT_BAT_PERCENTAGE=2;}
else if(BACKUP_BATTERY_VOLTAGE>=345 && BACKUP_BATTERY_VOLTAGE<350 ){INT_BAT_PERCENTAGE=3;}
else if(BACKUP_BATTERY_VOLTAGE>=350 && BACKUP_BATTERY_VOLTAGE<355 ){INT_BAT_PERCENTAGE=4;}
else if(BACKUP_BATTERY_VOLTAGE>=355 && BACKUP_BATTERY_VOLTAGE<360 ){INT_BAT_PERCENTAGE=5;}
else if(BACKUP_BATTERY_VOLTAGE>=360 && BACKUP_BATTERY_VOLTAGE<365 ){INT_BAT_PERCENTAGE=6;}
else if(BACKUP_BATTERY_VOLTAGE>=365 && BACKUP_BATTERY_VOLTAGE<370 ){INT_BAT_PERCENTAGE=7;}
else if(BACKUP_BATTERY_VOLTAGE>=370 && BACKUP_BATTERY_VOLTAGE<375 ){INT_BAT_PERCENTAGE=8;}
else if(BACKUP_BATTERY_VOLTAGE>=375 && BACKUP_BATTERY_VOLTAGE<410 ){INT_BAT_PERCENTAGE=9;}
else if(BACKUP_BATTERY_VOLTAGE>=410  ){INT_BAT_PERCENTAGE=10;}
BATTERY_MEASUREMENT=OFF;
}


void ACC_GRY_INTZ(void)
{
    MS_TIMER(1);
//    i2c_writen_2( MPU6050_ADDRESS, 0x6B, 0x00);
i2c_writen_2( MPU6050_ADDRESS, 0x10, 0x60);
MS_TIMER(50);
i2c_writen_2( MPU6050_ADDRESS, 0x0D, 0x80);
MS_TIMER(50);
//i2c_writen_2( MPU6050_ADDRESS, 0x11, 0x60);
//MS_TIMER(50);
//i2c_writen_2( MPU6050_ADDRESS, 0x0D, 0x02);
//MS_TIMER(50);
i2c_writen_2( MPU6050_ADDRESS, 0x19, 0x25);
MS_TIMER(50);
i2c_writen_2( MPU6050_ADDRESS, 0x1D, 0x7F);
MS_TIMER(50);

i2c_writen_2( MPU6050_ADDRESS, 0x53, 0x40);
//    i2c_writen_2( MPU6050_ADDRESS, SIGNAL_PATH_RESET, 0x07);//Reset all internal signal paths in the MPU-6050 by writing 0x07 to register 0x68;
//    i2c_writen_2( MPU6050_ADDRESS, I2C_SLV0_ADDR, 0x20);//write register 0x37 to SELECT how to use the interrupt pin. For an active high, push-pull signal that stays until register (decimal) 58 is read, write 0x20.
//    i2c_writen_2( MPU6050_ADDRESS, ACCEL_CONFIG, 0x01);//Write register 28 (==0x1C) to set the Digital High Pass Filter, bits 3:0. For example set it to 0x01 for 5Hz. (These 3 bits are grey in the data sheet, but they are used! Leaving them 0 means the filter always outputs 0.)
    MS_TIMER(300);
//    //i2c_writen_2( MPU6050_ADDRESS, MOT_THR, 20);  //Write the desired Motion threshold to register 0x1F (For example, write decimal 20).  
    
//    i2c_writen_2( MPU6050_ADDRESS, MOT_THR, 10);  //Write the desired Motion threshold to register 0x1F (For example, write decimal 20).  
//    i2c_writen_2( MPU6050_ADDRESS, MOT_DUR, 40 );  //Set motion DETECT duration to 1  ms; LSB is 1 ms @ 1 kHz rate  
//    i2c_writen_2( MPU6050_ADDRESS, MOT_DETECT_CTRL, 0x15); //to register 0x69, write the motion DETECTion decrement and a few other settings (for example write 0x15 to set both free-fall and motion decrements to 1 and accelerometer start-up delay to 5ms total by adding 1ms. )   
//    //i2c_writen_2( MPU6050_ADDRESS, MOT_DETECT_CTRL, 0x00); //to register 0x69, write the motion DETECTion decrement and a few other settings (for example write 0x15 to set both free-fall and motion decrements to 1 and accelerometer start-up delay to 5ms total by adding 1ms. )   
    
    
//    i2c_writen_2( MPU6050_ADDRESS, INT_ENABLE, 0xE0 ); //write register 0x38, bit 6 (0x40), to enable motion DETECTion interrupt.     
//    i2c_writen_2( MPU6050_ADDRESS, 0x37, 160 ); // now INT pin is active low

}

void ACC_GYRO_READ(void)
{
char q=0;
SYSTEM_READY=ON;
//A=i2c_readn_3(MPU6050_ADDRESS,0x3A);
//B=i2c_readn_3(MPU6050_ADDRESS,0x37);
//C=i2c_readn_3(MPU6050_ADDRESS,0x38);	
Test=i2c_readn_3(0xD4,0x0F); //// who i am 
MS_TIMER(300);
	
	//WDTE = 0xACU;
	Ax=i2c_readn_3(MPU6050_ADDRESS,0x29);//3B//2B
        q=i2c_readn_3(MPU6050_ADDRESS,0x28);//3C//2A
	Ax=Ax<<8;
	Ax=q+Ax;
	 MS_TIMER(10);
//	Ay=i2c_readn_3(0xD0,0x2B);//3D
//        q=i2c_readn_3(0xD0,0x2A);//3E
//	Ay=Ay<<8;
//	Ay=q+Ay;
//WDTE = 0xACU;
	Ay=i2c_readn_3(0xD4,0x2B);//3D
        q=i2c_readn_3(0xD4,0x2A);//3E
	Ay=Ay<<8;
	Ay=q+Ay;
	
	 MS_TIMER(10);
	 //WDTE = 0xACU;
	Az=i2c_readn_3(0xD4,0x2D);//3F
        q=i2c_readn_3(0xD4,0x2C);//40
	Az=Az<<8;
	Az=q+Az;
	 MS_TIMER(10);
//	Gx=i2c_readn_3(0xD0,0x3B);
//        q=i2c_readn_3(0xD0,0x3C);
//	Gx=Gx<<8;
//	Gx=q+Gx;
//	
//	Gy=i2c_readn_3(0xD0,0x3D);
//        q=i2c_readn_3(0xD0,0x3E);
//	Gy=Gy<<8;
//	Gy=q+Gy;
//	
//	Gz=i2c_readn_3(0xD0,0x3F);
//        q=i2c_readn_3(0xD0,0x40);
//	Gz=Gz<<8;
//	Gz=q+Gz;
//WDTE = 0xACU;
	NOP();
	//WDTE = 0xACU;
	
}
