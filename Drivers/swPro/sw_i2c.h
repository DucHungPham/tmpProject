#ifndef __i2cSW_H
#define __i2cSW_H

#include "board_init.h"

#define swSdaHigh()	(RA1 = 1)
#define swSdaLow()	(RA1 = 0)
#define swSda()		(RA1)

#define swSdaDrOut()  (TRISA &=0xfD)
#define swSdaDrIn()   (TRISA |=0x02)

#define swSlcHigh()	(RA0 = 1)
#define swSlcLow()	(RA0 = 0)

#define i2cFre 400000

#define swI2C_ACK 0
#define swI2C_NACK 1
#define swI2C_Read 1
#define swI2C_Write 0

#define swI2cDelay() {__delay_us(8);}// 1*NOP =  2.5us (HSI =16MHz) (time =16b)~400kHz

void swI2C_Init(void);
void swI2C_Start(void);
void swI2C_Stop(void);
unsigned char swI2cWrite(unsigned char dat);
unsigned char swI2cRead(unsigned char Ack);

#endif