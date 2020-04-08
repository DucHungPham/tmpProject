#ifndef __swuart_h
#define __swuart_h

#include "board_init.h"

#define swUartTxHigh() (RC0 = 1)
#define swUartTxLow() (RC0 = 0)

#define swUartBR 9600

#define	swUartDelay()	{ __delay_us(1000000/swUartBR);}	

void swUartSendByte(unsigned char dat);

#endif