#include "sw_spi.h"

unsigned char swSpiWrite(unsigned char dataOutput)
{
	unsigned char i,dataIntput=0;
	
	swSpiDelay();	
	swSpiDelay();
	swSpiSckLow();	
	for(i=0; i<8; i++)
	{		
		if(dataOutput & 0x80) {
			swSpiMosiHigh();
		} else {
			swSpiMosiLow();
		}
		dataOutput <<= 1;
				
		swSpiSckHigh();
		swSpiDelay(); 
		dataIntput <<= 1;
		if( swSpiMiso() )dataIntput|=1;
		swSpiSckLow();
		swSpiDelay();
	}
	return dataIntput;
}
