#include "r_cg_userdefine.h"
char GPS_RMC_RX,data_count,RMC_DATA;
char HOURS_MSB,HOURS_LSB,MIN_MSB,MIN_LSB,SEC_MSB,SEC_LSB;
char GPS_DIRECTION_DATA_VALID;
char LON_DIRECTION='S',LAT_DIRECTION='N';
char GPS_BUSY,R,COG[6]={'0','0','0','0','0','0'};
char DATE_MSB,DATE_LSB,MONTH_MSB,MONTH_LSB,YEAR_MSB,YEAR_LSB,L,NAVIGATION_ACK,O,GPS_RESTART;
int no=0,RR;

char LAT_DM[10]={'1','2','3','4','5','6','7','8'},LOG_DM[10]={'1','2','3','4','5','6','7','8'};
char LAT_DM_RX[10]={'0','0','0','0','0','0','0','0'},COMMA,COMMA_1,VTG_FRAME_ACK,S;
char LOG_DM_RX[10]={'0','0','0','0','0','0','0','0','0'};
char GPGA_FRAME[5]={'G','N','G','G','A'},GPGA_FRAME_ACK,GPGA_DATA[10]={'0','0','.','0','0','0','0','0','.','0'},A,VTG_FRAME[3]={'V','T','G'},B,SPEED_DATA_RX[10]={'0','0','0','0','0','0','0','0','0','0'},GSA_FRAME[3]={'G','S','A'};
char GPS_GGA_RX,ALTITUDE[8]={'0','0','0','0','0','0','0','0'},HDOP[5],NO_OF_SAT,data_count_2,GGA_DATA,NAVIGATION_FRAME_ACK[6]={'$','P','M','T','K','0'};//NAVIGATION_FRAME_ACK[12]={'$','P','M','T','K','0','0','1',',','8','8','6'};
extern char NAVIGATION_RX;
extern _Bool VLT_STARTUP_INITIAL,GPS_RMC_DATA_RX,GPS_GGA_DATA_RX,GPS_VTG_DATA_RX; 
//unsigned int a,b,c,d,e,f,n;
extern unsigned int ADC_BUFFER,t_count,GPS_RESET_COUNT,RESTART;
extern _Bool GPS_STANDBY,RTC_DONE;

unsigned int Q,W,COMMA_5,UART1_BUFFER_4,PDOP_DATA_RX[8],GSA_FRAME_ACK,GPS_GSA_DATA_RX;


/***********************************************************************************************************************
* Function Name: GPS_NAVIGATION_MODE
* Description  : This function is used SET THE GPS TO NAVIGATION MODE 
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void GPS_NAVIGATION_MODE(void)
{
	R_UART1_Start();
	GPS_RESTART=CLR;
restart101:
	NAVIGATION_RX=ON;
	//GREEN_LED=
	BLUE_LED=ON;
	R_UART1_SEND("$PMTK886,2*2A\r\n");MS_TIMER(1);
	//R_UART1_Send("$PMTK386,0.5*38\r\n",17);NOP();
	ACK_RX(12,7,50,1);
	if(GPS_RESTART>=5){GPS_RESTART=CLR;GPS_RST=ON;MS_TIMER(100);GPS_RST=OFF;goto restart101;}
	if(RESTART==ON){GPS_RESTART++;RESTART=OFF;goto restart101;}
	GPS_RESTART=CLR;
	//GREEN_LED=
	BLUE_LED=OFF;
	NAVIGATION_RX=OFF;
	R_UART1_Stop();
}
/***********************************************************************************************************************
* Function Name: GPS_STATIONARY_MODE
* Description  : This function is used SET THE GPS TO STATIONARY MODE 
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void GPS_STATIONARY_MODE(void)
{
	R_UART1_Start();
	restart102:
	NAVIGATION_RX=ON;
	//GREEN_LED=
	BLUE_LED=ON;
	R_UART1_SEND("$PMTK386,0.6*3B\r\n");MS_TIMER(1);
	ACK_RX(24,7,50,1);if(RESTART==ON){RESTART=OFF;goto restart102;}
	//GREEN_LED=
	BLUE_LED=OFF;
	NAVIGATION_RX=OFF;
	R_UART1_Stop();
}

/***********************************************************************************************************************
* Function Name: GPS_DATA_INTZ
* Description  : This function is used INTIALIZE THE GPS DATA
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
/***********************************************************************************************************************
* Function Name: BAUD_RATE_AND_INITIAL_SETTINGS
* Description  : This function is used SET THE BAUDRATE & INTIAL SETTINGS 
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void BAUD_RATE_AND_INITIAL_SETTINGS(void)
{

	
	//restart102:
	//R_UART1_Start();
	//R_UART1_SEND("$PMTK386,0.6*3B\r\n");MS_TIMER(1);
	//ACK_RX(24,7,50,1);
	//if(GPS_RESTART>=5){GPS_RESTART=CLR;GPS_RST=ON;MS_TIMER(100);GPS_RST=OFF;goto restart102;}
	//if(RESTART==ON){GPS_RESTART++;RESTART=OFF;goto restart102;}
	//GPS_RESTART=CLR;
	//GREEN_LED=BLUE_LED=OFF;
	//NAVIGATION_RX=OFF;
	//GPS_NAVIGATION_MODE();
        //GPS_STATIONARY_MODE();
	
//	GPS_FIX_INTERVAL();
//	GPS_SATELLITE_ENABLE();
//	GPS_PPS_DISABLE();
}
/***********************************************************************************************************************
* Function Name: GPS_FIX_INTERVAL
* Description  : This function is used SET THE GPS FIX INTERVAL MEANS:-AFTER 100m/S MOVEMENT ONLY IT CAPTURES LAT & LOG DATA
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
///***********************************************************************************************************************
//* Function Name: GPS_NORMAL_MODE
//* Description  : This function use to gps to normal mode
//* Arguments    : None
//* Return Value : None
//***********************************************************************************************************************/
void GPS_NORMAL_MODE(void)
{

	R_UART1_Start();
	restart102:
	//GREEN_LED=
	BLUE_LED=ON;
	NAVIGATION_RX=ON;
	R_UART1_SEND("$PMTK225,0*2B\r\n");MS_TIMER(1);
	//R_UART1_Send("$PMTK\r\n",7);MS_TIMER(1);R_UART1_Send("$PMTK\r\n",7);MS_TIMER(1);R_UART1_Send("$PMTK\r\n",7);MS_TIMER(1);
	ACK_RX(12,7,50,1);
	if(GPS_RESTART>=5){GPS_RESTART=CLR;GPS_RST=ON;MS_TIMER(100);GPS_RST=OFF;BAUD_RATE_AND_INITIAL_SETTINGS();goto restart102;}
	if(RESTART==ON){GPS_RESTART++;RESTART=OFF;goto restart102;}
	GPS_RESTART=CLR;
	//GREEN_LED=
	BLUE_LED=OFF;
	NAVIGATION_RX=OFF;
	R_UART1_Stop();
	GPS_STANDBY=OFF;
}
void GET_GPS_DATA(void)
{
    R_UART1_Start();
    t_count=0;
	    while(GPS_RMC_DATA_RX==OFF && t_count<=60){NOP();}						      if(t_count>=60){t_count=0;BAUD_RATE_AND_INITIAL_SETTINGS();}t_count=0;
    while(GPS_GGA_DATA_RX==OFF && t_count<=60){NOP();}                if(t_count>=60){t_count=0;BAUD_RATE_AND_INITIAL_SETTINGS();}t_count=0;
    //while(GPS_VTG_DATA_RX==OFF && GPS_DIRECTION_DATA_VALID==ON && NO_OF_SAT<=7 && t_count<=60){NOP();}if(t_count>=60){t_count=0;BAUD_RATE_AND_INITIAL_SETTINGS();}t_count=0;
    
    while(GPS_VTG_DATA_RX==OFF && GPS_DIRECTION_DATA_VALID==ON && t_count<=60){NOP();}if(t_count>=60){t_count=0;BAUD_RATE_AND_INITIAL_SETTINGS();}t_count=0;
    
    while(GPS_VTG_DATA_RX==OFF && GPS_DIRECTION_DATA_VALID==ON && t_count<=60){NOP();}if(t_count>=60){t_count=0;BAUD_RATE_AND_INITIAL_SETTINGS();}t_count=0;
    while(GPS_GSA_DATA_RX==OFF && GPS_DIRECTION_DATA_VALID==ON && t_count<=60){NOP();}if(t_count>=60){t_count=0;BAUD_RATE_AND_INITIAL_SETTINGS();}t_count=0;
    GPS_RMC_DATA_RX=GPS_GGA_DATA_RX=GPS_VTG_DATA_RX=GPS_GSA_DATA_RX=OFF;
    R_UART1_Stop();
}

void GPS_UART_RX_1(unsigned int UART1_BUFFER)
{
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //				 GPS DATA RECIEVE 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

    if(UART1_BUFFER=='R' && GPS_RMC_RX==0)
    {
	    GPS_RMC_RX=1;
    }
    else if(GPS_RMC_RX==1 && UART1_BUFFER=='M')
    {
	    GPS_RMC_RX=2;    
    }
    else if(GPS_RMC_RX==2 && UART1_BUFFER=='C')
    {
	    GPS_RMC_RX=3;    
    }
    else if(GPS_RMC_RX==3 && UART1_BUFFER==',')
    {
	    GPS_RMC_RX=4;
	    
    }
    else if(GPS_RMC_RX==4 && UART1_BUFFER=='*')
    {
	    GPS_RMC_RX=0;    
	    RMC_DATA=0;no=0;
	    
    }
    else if(GPS_RMC_RX==4)
    {
	         if(UART1_BUFFER==','){RMC_DATA++;data_count=0;no++;}
	    else if(UART1_BUFFER=='.' && no!=7){RMC_DATA++;}
	   else
	   {
	    //no=0;
	    GPS_BUSY=ON;
	    switch (no)
	    {
		//R_UART2_SEND_User(UART1_BUFFER);    
		
		    case 0:
		    {
		    if(data_count==0){HOURS_MSB=UART1_BUFFER;}
	       else if(data_count==1){HOURS_LSB=UART1_BUFFER;}
	       else if(data_count==2){  MIN_MSB=UART1_BUFFER;}
	       else if(data_count==3){  MIN_LSB=UART1_BUFFER;}
	       else if(data_count==4){  SEC_MSB=UART1_BUFFER;}
	       else if(data_count==5){  SEC_LSB=UART1_BUFFER;}
	       data_count++;
	            break;
		    }
		case 1:
		    {
		    if(UART1_BUFFER=='A' || UART1_BUFFER=='D'){GPS_DIRECTION_DATA_VALID=ON;/*CHARGE_STATE=ON;*/}  // P1.7/P5.1 now read-only (ignition sense)
		    else{GPS_DIRECTION_DATA_VALID=OFF;/*CHARGE_STATE=OFF;*/}  // Commented out - P1.7 is shorted to P5.1 on PCB
	            break;
		    }
		    case 2:
		    {
		    if(GPS_DIRECTION_DATA_VALID==ON)
	            {
			    LAT_DM_RX[data_count]=UART1_BUFFER;
	  	     data_count++;
	            break;
		    }
		    }
		    case 3:
		    {
	            if(UART1_BUFFER=='N' || UART1_BUFFER=='S'){LAT_DIRECTION=UART1_BUFFER;}
	            break;
		    }
		    case 4:
		    {
		    if(GPS_DIRECTION_DATA_VALID==ON)
	            {
			    LOG_DM_RX[data_count]=UART1_BUFFER;
		    data_count++;
	            break;
		    }
		    }
		    case 5:
		    {
	            if(UART1_BUFFER=='E' || UART1_BUFFER=='W'){LON_DIRECTION=UART1_BUFFER;}
	            break;
		    }
		    case 7:
		    {
			    if(GPS_DIRECTION_DATA_VALID==ON)
			    {
			    COG[data_count]=UART1_BUFFER;
			    }
			    if(data_count==5)
			    {
				    NOP();
			    }
	            data_count++;
	            break;
		    }
                    case 8:
		    {
	            if(data_count==0){DATE_MSB=UART1_BUFFER;}
	       else if(data_count==1){DATE_LSB=UART1_BUFFER;}
	       else if(data_count==2){MONTH_MSB=UART1_BUFFER;}
	       else if(data_count==3){MONTH_LSB=UART1_BUFFER;}
	       else if(data_count==4){YEAR_MSB=UART1_BUFFER;}
	       else if(data_count==5){YEAR_LSB=UART1_BUFFER;GPS_RMC_DATA_RX=ON;}
	            data_count++;
		    
	            break;
		    }
		    
		    
	    }
		    
    }
	GPS_BUSY=OFF;    
    }
  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




}
void GPS_UART_RX_2(char UART1_BUFFER_2)
{
    GPS_BUSY=ON;
    
    if(A == 0)
    {
        if(UART1_BUFFER_2 == 'G')
        {
            A = 1;
        }
    }
    else if(A == 1)
    {
        if(UART1_BUFFER_2 == 'N' || UART1_BUFFER_2 == 'P')
        {
            A = 2;
        }
        else
        {
            A = 0;
        }
    }
    else if(A == 2)
    {
        if(UART1_BUFFER_2 == 'G')
        {
            A = 3;
        }
        else
        {
            A = 0;
        }
    }
    else if(A == 3)
    {
        if(UART1_BUFFER_2 == 'G')
        {
            A = 4;
        }
        else
        {
            A = 0;
        }
    }
    else if(A == 4)
    {
        if(UART1_BUFFER_2 == 'A')
        {
            A = 5;
            COMMA = 0;
            L = 0;
            R = 0;
            NO_OF_SAT = 0;
            HDOP[0]='0';HDOP[1]='0';HDOP[2]='0';HDOP[3]='0';HDOP[4]=0;
            ALTITUDE[0]='0';ALTITUDE[1]='0';ALTITUDE[2]='0';ALTITUDE[3]='0';ALTITUDE[4]='0';ALTITUDE[5]='0';ALTITUDE[6]='0';
        }
        else
        {
            A = 0;
        }
    }
    else if(A == 5)
    {
        if(UART1_BUFFER_2 == ',')
        {
            if(COMMA >= 7)
            {
                L++;
                R = 0;
            }
            COMMA++;
        }
        else if(COMMA >= 7 && COMMA < 10)
        {
            if(L == 0)
            {
                if(R >= 1)
                {
                    NO_OF_SAT = (NO_OF_SAT * 10) + (UART1_BUFFER_2 & 0x0F);
                }
                else
                {
                    NO_OF_SAT = UART1_BUFFER_2 & 0x0F;
                    R++;
                }
            }
            else if(L == 1)
            {
                HDOP[R] = UART1_BUFFER_2;
                R++;
            }
            else if(L == 2)
            {
                ALTITUDE[R] = UART1_BUFFER_2;
                R++;
            }
        }
        
        if(UART1_BUFFER_2 == '*')
        {
            GPS_GGA_DATA_RX = ON;
            A = 0;
            COMMA = 0;
            L = 0;
            R = 0;
        }
    }
    
    GPS_BUSY = OFF;
}	
	
	
	
	
	
/*	//if(GPS_DIRECTION_DATA_VALID==ON){
	
		
	GPS_BUSY=ON;    
	if(UART1_BUFFER_2==GPGA_FRAME[L] || GPGA_FRAME_ACK>=1)
	{
		L++;
		
		if(GPGA_FRAME_ACK==1){
		     if(UART1_BUFFER_2==','){COMMA++;}
		else if(COMMA>=6){
		if(UART1_BUFFER_2!=0x00){GPGA_DATA[RR]=UART1_BUFFER_2;RR++;}}     
		}
		else if(L>=5){L=0;GPGA_FRAME_ACK=1;RR=0;COMMA=0;GREEN_LED=1;}
	        //if(UART1_BUFFER_2=='*' && GPGA_FRAME_ACK==1){GPGA_FRAME_ACK=0;A=0;}
		//if(COMMA>=9 && UART1_BUFFER_2==',' ||  COMMA>=9 && UART1_BUFFER_2=='M' ){RR=0;COMMA=0;GPGA_FRAME_ACK=0;A=0;}
		//GPS_BUSY=OFF;    
	
      }
	else{L=0;}	
		
	//	else if(COMMA==7){
	//	GPGA_DATA[RR]=UART1_BUFFER_2;RR++;}
	//	else if(A>=5){A=0;GPGA_FRAME_ACK=1;RR=0;COMMA=0;GREEN_LED=ON;}
	        //if(UART1_BUFFER_2=='M' && COMMA>=7){GPGA_FRAME_ACK=0;A=0;}
	//	if(COMMA>=7){GPGA_FRAME_ACK=0;A=0;}
		//GPS_BUSY=OFF;    
	//else{GPS_BUSY=OFF;COMMA=0;;A=0;GPGA_FRAME_ACK=0;}
	//else{A=0;}
//}
}*/

void GPS_UART_RX_3(unsigned int UART1_BUFFER_3)
{
	//if(GPS_DIRECTION_DATA_VALID==ON && NO_OF_SAT<=7){
	//if(GPS_DIRECTION_DATA_VALID==ON){	
	   
	if(UART1_BUFFER_3==VTG_FRAME[B] || VTG_FRAME_ACK>=1)
	{
		 
		B++;
		     /*if(VTG_FRAME_ACK==2 && UART1_BUFFER_3=='K'){VTG_FRAME_ACK=0;S=0;}
		else if(VTG_FRAME_ACK==2){SPEED_DATA_RX[S]=0;SPEED_DATA_RX[S]=UART1_BUFFER_3;S++;}
		else if(VTG_FRAME_ACK==1 && UART1_BUFFER_3=='N'){VTG_FRAME_ACK=2;S=0;}
		else if(B>=3){VTG_FRAME_ACK=1;}
		*/
		
		
		
		if(VTG_FRAME_ACK==1){
		     if(UART1_BUFFER_3==','){COMMA_1++;}

		     else if(COMMA_1>=7){GPS_BUSY=ON;SPEED_DATA_RX[S]=0;SPEED_DATA_RX[S]=UART1_BUFFER_3;S++;}}
		else if(B>=3){B=0;VTG_FRAME_ACK=1;S=0;COMMA_1=0;}
	        if(COMMA_1>=8 && UART1_BUFFER_3==',' || COMMA_1>=8 && UART1_BUFFER_3=='K' ){GPS_VTG_DATA_RX=ON;S=0;COMMA_1=0;B=0;VTG_FRAME_ACK=0;VTG_FRAME_ACK=0;B=0;}
	
	}
	else{GPS_BUSY=OFF;COMMA_1=0;;B=0;VTG_FRAME_ACK=0;}
	
//}
}
void GPS_UART_RX_4(unsigned int UART1_BUFFER_4)
{
	if(NAVIGATION_FRAME_ACK[O]==UART1_BUFFER_4)
	{
		O++;
		if(O>=6){NAVIGATION_ACK=1;O=0;}
	}
	else{O=0;}
}


void GPS_UART_RX_5(unsigned int UART1_BUFFER_5)
{
if(GPS_DIRECTION_DATA_VALID==ON)
{
	   
	if(UART1_BUFFER_5==GSA_FRAME[Q] || GSA_FRAME_ACK>=1)
	{
		 
		Q++;
		     /*if(VTG_FRAME_ACK==2 && UART1_BUFFER_3=='K'){VTG_FRAME_ACK=0;S=0;}
		else if(VTG_FRAME_ACK==2){SPEED_DATA_RX[S]=0;SPEED_DATA_RX[S]=UART1_BUFFER_3;S++;}
		else if(VTG_FRAME_ACK==1 && UART1_BUFFER_3=='N'){VTG_FRAME_ACK=2;S=0;}
		else if(B>=3){VTG_FRAME_ACK=1;}
		*/
		
		
		
		if(GSA_FRAME_ACK==1)
		{
		          if(UART1_BUFFER_5==',')
			  {
			  COMMA_5++;
			  }
	             else if(COMMA_5>=15)
		     {
			  GPS_BUSY=ON;PDOP_DATA_RX[W]=0;PDOP_DATA_RX[W]=UART1_BUFFER_5;W++;Q=0;
		     }
		}
		else if(Q>=3)
		{
		Q=0;GSA_FRAME_ACK=1;W=0;COMMA_5=0;
		}
	        
		if(COMMA_5>=16 && UART1_BUFFER_5==',')
		{
		GPS_GSA_DATA_RX=ON;W=0;COMMA_5=0;Q=0;GSA_FRAME_ACK=0;W=0;
		}
	
	}
	else{GPS_BUSY=OFF;COMMA_5=0;W=0;GSA_FRAME_ACK=0;Q=0;}
	
}
}

void RTC_SET(void)
{
HOUR=(HOURS_LSB&0x0F);
HOUR=(HOUR+((HOURS_MSB<<4)&0xF0));
MIN=(MIN_LSB&0x0F);
MIN=(MIN+((MIN_MSB<<4)&0xF0));
SEC=(SEC_LSB&0x0F);
SEC=(SEC+((SEC_MSB<<4)&0xF0));


DAY=(DATE_LSB&0x0F);
DAY=(DAY+((DATE_MSB<<4)&0xF0));

MONTH=(MONTH_LSB&0x0F);
MONTH=(MONTH+((MONTH_MSB<<4)&0xF0));

YEAR=(YEAR_LSB&0x0F);
YEAR=(YEAR+((YEAR_MSB<<4)&0xF0));
}

void GPS_SLEEP_MODE(void)
{
	//R_UART1_Send("$PMTK225,4*2F\r\n",13);MS_TIMER(1);
}
