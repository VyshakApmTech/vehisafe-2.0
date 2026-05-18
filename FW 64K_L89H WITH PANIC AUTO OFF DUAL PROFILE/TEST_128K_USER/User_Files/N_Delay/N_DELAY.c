#include "r_cg_userdefine.h"
volatile unsigned int Milli_Seconds,Micro_Seconds;
/*void delay__us(unsigned int us)
{  
	unsigned int z;
	us = us * 3;
	for(z=0;z<us;z++);           			// For 30MHz
}
void delay__ms(long ms)
{
	long j;
	ms = ms * 780;			 		// For 30MHz
	for(j=0;j<ms;j++);
}*/
void MS_TIMER(unsigned int y)
{
	Milli_Seconds=0;
	R_TAU0_Channel1_Start();
	while(Milli_Seconds<=y);
	R_TAU0_Channel1_Stop();
}

void US_TIMER(unsigned int o)
{
	Micro_Seconds=0;
	R_TAU0_Channel3_Start();
	while(Micro_Seconds<=o);
	R_TAU0_Channel3_Stop();
}