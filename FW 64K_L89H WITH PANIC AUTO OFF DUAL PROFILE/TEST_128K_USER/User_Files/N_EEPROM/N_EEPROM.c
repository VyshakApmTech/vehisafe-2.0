#include "r_cg_userdefine.h"

unsigned int FOR_5,NEXT,DATA,READ_ADDRESS,WRITE_ADDRESS,TEMPS,WRITE_ADDRESS_MSB,WRITE_ADDRESS_LSB;
extern char LOG_DM[10],LAT_DM[10];
extern char HOURS_MSB,HOURS_LSB,MIN_MSB,MIN_LSB,LON_DIRECTION,LAT_DIRECTION,MAIN_BAT_STATUS;
extern char GSM_STRENGTH,IGNITION,PANIC_ALERT,LOW_BATTERY_ALERT,SPEED_DATA_RX[10];
char Array_1[10]={'0','1','2','3','4','5','6','7','8','9'};
char TIME[10],FIRM_DATA[150];
extern _Bool EEPROM_WORKING;
_Bool STOP_WRITING;
unsigned int BYTE,EEPROM_ADDRESS;
extern unsigned int WRITE_ADDRESS,UPDATE_TIME;
void i2c_writen(unsigned char id, unsigned char add,unsigned char add1, unsigned char dat)
{
	add &=0xFF;
	add1 &=0xFF;
        i2c_start();
	i2c_wbyte(id);
	i2c_ack();
	i2c_wbyte(add);
	i2c_ack();
	i2c_wbyte(add1);
	i2c_ack();
	i2c_wbyte(dat); 
	i2c_ack();
	i2c_stop();	
	//US_TIMER(2);
}


unsigned char i2c_readn(unsigned char id,unsigned char add,unsigned char add1)
{
	unsigned char rd;
	
	add &=0xFF;
	add1 &=0xFF;
	i2c_start();
	i2c_wbyte(id);
	i2c_ack();
	i2c_wbyte(add);
	i2c_ack();
	i2c_wbyte(add1);
	i2c_ack();
	i2c_start();
	i2c_wbyte((id|0x01));
	i2c_ack();
	rd = i2c_rbyte();
	i2c_nack();
	i2c_stop();
	//US_TIMER(2);
	return(rd);
}


void i2c_PAGE_WRITE(unsigned char id, unsigned char add,unsigned char add1)
{
//	char i;
	add &=0xFF;
	add1 &=0xFF;
        
	i2c_start();
	i2c_wbyte(id);
	i2c_ack();
	i2c_wbyte(add);
	i2c_ack();
	i2c_wbyte(add1);
	i2c_ack();
	
	while(STOP_WRITING==0)
	{
	i2c_wbyte(FIRM_DATA[BYTE]);
	i2c_ack();
	BYTE++;
	EEPROM_ADDRESS++;
	if(BYTE>132 || EEPROM_ADDRESS%128==0){STOP_WRITING=1;WRITE_ADDRESS=EEPROM_ADDRESS;}
	}
	STOP_WRITING=0; 
	i2c_stop();	
	MS_TIMER(5);
}






//void GPS_DATA_EEPROM_WRITE(void)
//{
//}
     
//void GPS_DATA_EEPROM_READ(void)
//{
//}


	
//void EEPROM_CONDITION(void)
//{
//if(IGNITION_SW==CLOSE){UPDATE_TIME=1;}
//else if(IGNITION_SW==OPEN){UPDATE_TIME=10800;}
//}





void i2c_writen_2(unsigned char id, unsigned char add, unsigned char dat)
{
MS_TIMER(1);
	add &=0xFF;
	
        i2c_start();
	i2c_wbyte(id);
	i2c_ack();
	i2c_wbyte(add);
	i2c_ack();
	i2c_wbyte(dat);
	i2c_ack();
	i2c_stop();	
	MS_TIMER(1);
}


unsigned char i2c_readn_3(unsigned char id,unsigned char add)
{
	unsigned char rd;
	
	add &=0xFF;
	i2c_start();
	i2c_wbyte(id);
	i2c_ack();
	i2c_wbyte(add);
	i2c_ack();
	i2c_start();
	i2c_wbyte((id|0x01));
	i2c_ack();
	rd = i2c_rbyte();
	i2c_nack();
	i2c_stop();
	return(rd);
}

