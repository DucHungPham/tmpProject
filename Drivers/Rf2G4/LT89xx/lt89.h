#ifndef __LT89_H_
#define __LT89_H_
/////////////////////////////////////////////////

/* Includes ------------------------------------------------------------------*/
#include "board_init.h"
#include "lt89Reg.h"
#include "sw_spi.h"

#define	lt89CsHigh() (P31=1)
#define	lt89CsLow()	(P31=0)
#define	lt89RstHigh() (P10=1)
#define	lt89RstLow()(P10=0)
#define	lt89Pkt() (P30)

#define	LT89Read 0x80
#define	LT89Write 0x00

void LT89WriteReg(unsigned char reg, unsigned int dat);
unsigned int LT89ReadReg(unsigned char reg);
void LT89Config(void);
unsigned char LT89ReadFIFO(unsigned char *buff);
void LT89SendFIFO(unsigned char *dat,unsigned char ch);
void LT89_SCAN_RSSI(unsigned offst,unsigned chno,unsigned wait,unsigned char *val);
/////////////////////////////////////////////////

#endif

