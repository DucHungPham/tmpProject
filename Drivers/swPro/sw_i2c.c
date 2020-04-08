#include "sw_i2c.h"

/*
sau moi xung SCL = 0
*/

//==============================================================================
void swI2C_Init(void) {
//bus readly
	swSdaDrOut();
//	swSCL_DDRO;
	swI2cDelay();
	swSlcHigh();
	swSdaHigh();
	swI2cDelay();
	swI2cDelay();
	swI2cDelay();
	swI2cDelay();
}
//==============================================================================
void swI2C_Start(void)
{
// start
	swSlcHigh();
//swI2cDelay();
	swSdaHigh();
	swI2cDelay();
	swSdaLow();
	swI2cDelay();
	swSlcLow();
	swI2cDelay();
}
//==============================================================================
void swI2C_Stop(void)
{
// stop
	swSdaLow();
	swSlcHigh();
	swI2cDelay();
	swSdaHigh();
	swI2cDelay();
}

//==============================================================================
void swI2C_Scanner(void) {
	/*    byte error, address;
	int nDevices;

	Serial.println("Scanning...");

	nDevices = 0;
	for(address = 1; address < 127; address++ )
	{
	// The i2c_scanner uses the return value of
	// the Write.endTransmisstion to see if
	// a device did acknowledge to the address.
	Wire.beginTransmission(address);
	error = Wire.endTransmission();

	if (error == 0)
	{
	Serial.print("I2C device found at address 0x");
	if (address<16)
	Serial.print("0");
	Serial.print(address,HEX);
	Serial.println("  !");

	nDevices++;
	}
	else if (error==4)
	{
	Serial.print("Unknown error at address 0x");
	if (address<16)
	Serial.print("0");
	Serial.println(address,HEX);
	}
	}
	if (nDevices == 0)
	Serial.println("No I2C devices found\n");
	else
	Serial.println("done\n");
	*/
}
//==============================================================================
unsigned char swI2cWrite( unsigned char dat)
{
	unsigned char i;

	swSdaDrOut();
	swI2cDelay();
	for (i = 0; i < 8; i++)
	{
		if(dat & 0x80) swSdaHigh();
		else swSdaLow();
		dat <<= 1;
		swSlcHigh();
		swI2cDelay();
		swSlcLow();
		swI2cDelay();
	}
// read ack
	swSdaDrIn();
	swI2cDelay();
	swSlcHigh();
	swI2cDelay();
	i = swSda();
	swSlcLow();
	swSdaDrOut();
	return i;
}
//==============================================================================
unsigned char swI2cRead(unsigned char Ack)// read 1 byte data
{

	unsigned char i, dat = 0;
	swSlcLow();
	swSdaDrIn();
	swI2cDelay();
	for (i = 0; i < 8; i++)
	{
		swSlcHigh();
		swI2cDelay();
		dat = dat << 1; 
		if (swSda()) dat|=1;
		swSlcLow();
		swI2cDelay();
	}

	swSdaDrOut();

	if(Ack) swSdaLow();
		else swSdaHigh();
	swSlcHigh();
	swI2cDelay();
	swSlcLow();
	swI2cDelay();
	return dat;
}
