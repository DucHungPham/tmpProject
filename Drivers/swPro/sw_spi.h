#ifndef __SWSPI_H_
#define __SWSPI_H_

#include "board_init.h"
#include "intrins.h"

#define spiCkp
#define spi3w	//mIO|clk|cs
#define spi4w	//mi|mo|clk|cs
#define spiFre

#define	swSpiDelay()	{	_nop_();}		

#define	swSpiMiso()		( P11 )
#define	swSpiMosiHigh()	( P55 = 1 )
#define	swSpiMosiLow()	( P55 = 0 )
#define	swSpiSckHigh()	( P32 = 1 )
#define	swSpiSckLow()	( P32 = 0 )

unsigned char swSpiWrite(unsigned char datOutput);

/////////////////////////////////////////////////

#endif