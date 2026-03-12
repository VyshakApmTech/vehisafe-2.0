#ifndef __N_EEPROM_C__
#define __N_EEPROM_C__

#include "r_cg_userdefine.h"

#define  EEPROM  0xA0
#define  ADDRESS 0X20 


void i2c_writen(unsigned char id, unsigned char add,unsigned char add1, unsigned char dat);
unsigned char i2c_readn(unsigned char id,unsigned char add,unsigned char add1);
void GPS_DATA_EEPROM_WRITE(void);
void GPS_DATA_EEPROM_READ(void);
void EEPROM_PRINT(void);
//void i2c_PAGE_WRITE(unsigned char id, unsigned char add,unsigned char add1);
//void EEPROM_CONDITION(void);
unsigned char i2c_readn_2(unsigned char id,unsigned char add,unsigned char add1);

void i2c_writen_2(unsigned char id, unsigned char add, unsigned char dat);
unsigned char i2c_readn_3(unsigned char id,unsigned char add);
#endif
