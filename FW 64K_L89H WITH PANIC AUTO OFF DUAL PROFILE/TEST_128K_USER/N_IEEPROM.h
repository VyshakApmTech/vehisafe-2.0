#ifndef __N_IEEPROM_C__
#define __N_IEEPROM_C__

#include "r_cg_userdefine.h"
void fdl_clcok_init(void);
void blank_check(unsigned char block_num);
void block_erase(unsigned char block_num);
void fdl_write(unsigned int addr);
void fdl_read(unsigned int addr);
void delay(unsigned int d);
//void MS_TIMER(unsigned int x);
//void US_TIMER(unsigned int o);

#endif