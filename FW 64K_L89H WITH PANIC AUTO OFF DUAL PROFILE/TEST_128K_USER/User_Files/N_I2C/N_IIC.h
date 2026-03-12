#ifndef __N_IIC_C__
#define __N_IIC_C__
#include "r_cg_userdefine.h"


void i2c_write(unsigned char, unsigned char, unsigned char);
unsigned char i2c_read(unsigned char,unsigned char);

void i2c_delay(void);								// I2C Clock delay 
void i2c_start(void);								// Generates a I2C Start condition
void i2c_stop(void);								// Generates a I2C Stop condition
void i2c_wbyte(unsigned char);					// Writes a single byte from I2C Slave
void i2c_nack(void);								// I2C Not Acknowlegdge
unsigned char i2c_rbyte(void);					// Reads and returns a single byte from I2C Slave
char i2c_ack(void);									// I2C Acknowledge


#endif
