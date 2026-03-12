#include "r_cg_userdefine.h"

extern _Bool HEX_CHARACTER_CONVERSION,URL_PRINT;

extern unsigned int RECORD_ARRAY_ADDRESS;
extern char RECORD[180];
char CSI00_RX_DATA;
_Bool CSI00_RX;
//uint8_t RDSR[]={0x05};
//uint8_t WRSR[]={0x01,0x00};
//uint8_t WREN[]={0x06};
//uint8_t WRITE[]={0x02,0x00,0x00,0x00,0xAB,0xAC,0xAD,0xAE,0xAF};
//uint8_t READ[]={0x03,0x00,0x00,0x00,0x00};
//uint8_t x[10],y[5];

void R_UART2_SEND_User(char x)
{
//    	MD_STATUS status = MD_OK;
	STMK2 = 1U;NOP();    /* disable INTST0 interrupt */
	     if(x==0x00 && URL_PRINT==ON){x='+';}
	else if(x==0x00){x=0x30;}
	
	     if(HEX_CHARACTER_CONVERSION==ON && x=='a'){x='A';}
	else if(HEX_CHARACTER_CONVERSION==ON && x=='b'){x='B';}
	else if(HEX_CHARACTER_CONVERSION==ON && x=='c'){x='C';}
	else if(HEX_CHARACTER_CONVERSION==ON && x=='d'){x='D';}
	else if(HEX_CHARACTER_CONVERSION==ON && x=='e'){x='E';}
	else if(HEX_CHARACTER_CONVERSION==ON && x=='f'){x='F';}
	
        TXD2 = x;NOP();
	while(STIF2==0U);NOP();
	STMK2 = 0U;NOP();    /* enable INTST0 interrupt */
}
void R_UART2_SEND(const char *b)
{
    unsigned int z=0;
    for(;b[z]!=0;z++)
    R_UART2_SEND_User(b[z]);NOP();
}

void R_UART1_Send_1_User(char x)
{
//    	MD_STATUS status = MD_OK;
	STMK1 = 1U;NOP();    /* disable INTST0 interrupt */
	TXD1 = x;NOP();
	while(STIF1==0U);NOP();
	STMK1 = 0U;NOP();    /* enable INTST0 interrupt */
}
void R_UART1_SEND(const char *b)
{
    unsigned int z=0;
    for(;b[z]!=0;z++)
    R_UART1_Send_1_User(b[z]);NOP();
}
void R_CSI00_SEND(char x)
{
//MD_STATUS status = MD_OK;
CSIMK00=1U;                     /* disable INTCSI00 interrupt */
SIO00=x;
while(CSIIF00==0U);NOP();
CSIMK00 = 0U;                     /* enable INTCSI00 interrupt */
}

//unsigned char CSI00_READ(void)
//{
//	unsigned char a;
//	MD_STATUS status = MD_OK;
//	CSI00_RX=LOW;
//	CSIMK00=1U;                     /* disable INTCSI00 interrupt */
//	SIO00=0xFF;
//	while(CSIIF00==0U);NOP();
//	CSIMK00 = 0U;                     /* enable INTCSI00 interrupt */
//	//SIO00=0xFF;
//	while(CSI00_RX==LOW);
//	return(CSI00_RX_DATA);
//}
//void CSI00_READ_INT(void)
//{
//	CSI00_RX_DATA=SIO00;
//	CSI00_RX=HIGH;
//}


void SEND_TO_ARRAY(const char *b)
{
    unsigned int z=0;
    for(;b[z]!=0;z++)
    {
    RECORD[RECORD_ARRAY_ADDRESS]=(b[z]);NOP();
    RECORD_ARRAY_ADDRESS++;
    }
}
void SEND_TO_ARRAY_Value(char b)
{
	if(b==0x00){b=0x30;}
	
  	     if(HEX_CHARACTER_CONVERSION==ON && b=='a'){b='A';}
	else if(HEX_CHARACTER_CONVERSION==ON && b=='b'){b='B';}
	else if(HEX_CHARACTER_CONVERSION==ON && b=='c'){b='C';}
	else if(HEX_CHARACTER_CONVERSION==ON && b=='d'){b='D';}
	else if(HEX_CHARACTER_CONVERSION==ON && b=='e'){b='E';}
	else if(HEX_CHARACTER_CONVERSION==ON && b=='f'){b='F';}
	else if(HEX_CHARACTER_CONVERSION==ON && b=='x'){b='0';}
RECORD[RECORD_ARRAY_ADDRESS]=b;NOP();
RECORD_ARRAY_ADDRESS++;
}

