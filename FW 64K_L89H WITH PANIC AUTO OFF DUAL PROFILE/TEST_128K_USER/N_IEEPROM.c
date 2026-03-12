#include "pfdl.h"
#include "pfdl_types.h"
#include "r_cg_userdefine.h"
/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
pfdl_request_t my_request;
pfdl_descriptor_t my_descriptor;
pfdl_status_t my_status;

unsigned char bit0, bit1,bit2,bit3,bit4;
unsigned char err_blcok0,err_blcok1,err_blcok2,err_blcok3;
unsigned char intp_cnt;
extern unsigned char a[255],b[255];
extern unsigned int i,j;


void fdl_clcok_init(void);
void blank_check(unsigned char block_num);
void block_erase(unsigned char block_num);
void fdl_write(unsigned int addr);
void fdl_read(unsigned int addr); 
void delay(unsigned int d);

struct{
	unsigned char data1,data2,data3,data4,data5,data6,data7,data8,data9,data10;

}Write_Buffer;
struct{
	unsigned char data1,data2,data3,data4,data5,data6,data7,data8,data9,data10;

}Write_Buffer2;

struct{
	unsigned char data1,data2,data3,data4,data5;
	unsigned char data6,data7,data8,data9,data10;

}Read_Buffer;
struct{
	unsigned char data1,data2,data3,data4,data5,data6,data7,data8,data9,data10;

}Read_Buffer2;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

void fdl_clcok_init(void)
{
	my_descriptor.fx_MHz_u08 = 32;
	my_descriptor.wide_voltage_mode_u08 = 0;
	my_status=PFDL_Open(&my_descriptor);
	delay(100);
	if(my_status == PFDL_BUSY)
	{	
		while(my_status == PFDL_BUSY)
		{
			my_status=PFDL_Handler();
		}
	}
	while(my_status != PFDL_OK)
	{
		my_status=PFDL_Handler();
	}
}
void blank_check(unsigned char block_num)
{
	my_status = PFDL_OK;
	my_request.index_u16 = block_num;
	//my_descriptor.data_pu08
	my_request.bytecount_u16 =  1024;
	my_request.command_enu = PFDL_CMD_BLANKCHECK_BYTES;

	my_status=PFDL_Execute(&my_request);	
	
	if(my_status == PFDL_BUSY)
	{
		while(my_status == PFDL_BUSY)
		{
			my_status=PFDL_Handler();
		}
	}
	if(my_status == PFDL_ERR_MARGIN)
	{
		if(block_num == 0)
		{
			err_blcok0=1;
		}
	
		if(block_num == 1)
		{
			err_blcok1=1;
		}
	}
	
	if(my_status == PFDL_OK)
        {
		return;
	}	
}
void block_erase(unsigned char block_num)
{
	my_status = PFDL_OK;
	my_request.index_u16 = block_num;
	my_request.command_enu = PFDL_CMD_ERASE_BLOCK;
	my_status=PFDL_Execute(&my_request);		
	if(my_status != PFDL_OK)
	{
		while(my_status == PFDL_BUSY)
		{
			my_status=PFDL_Handler();
		}
	}	
	if(my_status != PFDL_OK)
	{
		NOP();
	}
	
}
void fdl_write(unsigned int addr)
{
	//Write_Buffer.data1=a[0];
//	Write_Buffer.data2=0X55;
//	Write_Buffer.data3=0X55;
//	Write_Buffer.data4=0X55;
//	Write_Buffer.data5=0X55;
//	Write_Buffer.data6=0X55;
//	Write_Buffer.data7=0X55;
//	Write_Buffer.data8=0X55;
//	Write_Buffer.data9=0X55;
//	Write_Buffer.data10=0X55;
	
	my_status = PFDL_OK;
	my_request.index_u16 = addr;
	//my_request.data_pu08=(unsigned char *)&Write_Buffer;
	my_request.data_pu08=(unsigned char *)&a[0];
	my_request.bytecount_u16 =  255;
	my_request.command_enu = PFDL_CMD_WRITE_BYTES;
	my_status=PFDL_Execute(&my_request);	
	if(my_status != PFDL_OK)
	{
		while(my_status == PFDL_BUSY)
		{
			my_status=PFDL_Handler();
		}
	}
	while(my_status == PFDL_ERR_WRITE)
	{
		NOP();
		my_status=PFDL_Handler();
	}
	if(my_status == PFDL_OK)
	{
		NOP();
	}
}
void fdl_read(unsigned int addr)
{
	my_status = PFDL_OK;
	my_request.index_u16 = addr;
	if(addr == 0x0000)
	{
	my_request.data_pu08 = (unsigned char *)&b[0];
	}
	if(addr == 0x0400)
	{
	my_request.data_pu08 = (unsigned char *)&Read_Buffer2;
	}
	my_request.bytecount_u16 =  255;
	my_request.command_enu = PFDL_CMD_READ_BYTES;
	my_status=PFDL_Execute(&my_request);
	if(my_status != PFDL_OK)
	{
		while(my_status == PFDL_BUSY)
		{
			my_status=PFDL_Handler();
		}
	}	
	if(my_status != PFDL_OK)
	{
		NOP();
	}
}
void delay(unsigned int d)
{
	while(d!=1)
	d--;
}