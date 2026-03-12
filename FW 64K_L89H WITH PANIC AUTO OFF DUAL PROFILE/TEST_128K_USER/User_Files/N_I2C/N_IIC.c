#include "r_cg_userdefine.h"

void i2c_delay(void)
{
	char a;
	for(a=0;a<40;a++);
}
void i2c_start(void)
{
	SCL_Dir = 0;								// Set SCL pin as output
	SDA_Dir = 0;								// Set SDA pin as output
	SCL = 1;
	i2c_delay();
	SDA	= 1;
	i2c_delay();
	SDA	= 0;
	i2c_delay();
	SCL = 0;		
	i2c_delay();	
}

void i2c_stop(void)
{
	SDA_Dir = 0;						// Set SDA pin as output				
	SDA	= 0;
	i2c_delay();
	SCL	= 1;
	i2c_delay();
	SDA = 1;
	i2c_delay();
	SCL = 0;			
}

void i2c_wbyte(unsigned char i2c_wb)
{
	char a;
	SDA_Dir = 0;							// Set SDA pin as output
	for(a=0;a<8;a++)						// Send 8 bits 
	{	
		SCL = 0;	
		i2c_delay();								
		if(i2c_wb & (0x80 >> a))
		{
			
			SDA = 1;
		}
		else
		{
			SDA = 0;	
			
		}
		i2c_delay();				
		SCL	= 1;	
		i2c_delay();
	}	
	
}

unsigned char i2c_rbyte(void)
{
	unsigned char a;
	unsigned char b;
	b=0;
	SDA_Dir = 1;							// Set SDA pin as input								
	for(a=0;a<8;a++)
	{
		SCL = 1;
		i2c_delay();
		if(SDA)		
		{
			b |= (0x80 >> a);				// Set data bit on SDA line
		}
		i2c_delay();
		SCL	= 0;
		i2c_delay();
	}
	return(b);
}

char i2c_ack(void)
{
	char a;
	SDA_Dir = 0;				// Set SDA pin as output
	i2c_delay();
	SCL= 0;	
	i2c_delay();
	SDA	= 1;
	i2c_delay();
	SCL = 1;
	i2c_delay();
	SDA_Dir = 1;				// Set SDA pin as input	
	i2c_delay();
	a = SDA;
	i2c_delay();
	SCL = 0;
	i2c_delay();
	return(a);
}

void i2c_nack(void)
{
	//SDA_Dir = 1;									// Set SDA pin as output
	SDA_Dir = 0;
	SDA	= 1;
	i2c_delay();
	SCL	= 1;
	i2c_delay();
	SCL = 0;
	i2c_delay();
}
