#include "lt89.h"

void LT89WriteReg(unsigned char reg, unsigned int dat)
{
	lt89CsLow();
	swSpiWrite(reg);
	swSpiWrite(dat>>8);
	swSpiWrite(dat);
	lt89CsHigh();
}

unsigned int LT89ReadReg(unsigned char reg)
{
	unsigned int dat;
	lt89CsLow();
	swSpiWrite(LT89Read|reg);
	dat = swSpiWrite(0);
	dat = dat <<8 | swSpiWrite(0);
	lt89CsHigh();
	return dat;
}
/*
void LT89_SCAN_RSSI(unsigned offst,unsigned chno,unsigned wait,unsigned char *val)
{
	unsigned char pos = 0;
	unsigned int dat =0;
	
	LT89WriteReg(42,(chno)<<SCAN_RSSI_CH_NO);
	LT89WriteReg(43,SCAN_RSSI_EN|(offst)<<SCAN_STRT_CH_OFFST|(wait)<<WAIT_RSSI_SCAN_TIM);
	
	//wait PKL_flag
   //read the results.
     
	while(pos < chno)
	{
		dat = LT89ReadReg(TXRX_FIFO_REG);
		val[pos++] = dat >> 8;
	}
}
*/
void LT89Config(void)
{
	// wait 5ms
	swSpiDelay();
	/* Recommended Register Values */
	LT89WriteReg(0,0x6fe0);//
	LT89WriteReg(1,0x5681);
	LT89WriteReg(2,0x6617);
	LT89WriteReg(4,0x9cc9);
	LT89WriteReg(5,0x6637);
	LT89WriteReg(8,0x6c90);
	LT89WriteReg(9,0x4800);//Sets Tx power max level
	LT89WriteReg(10,0x7ffd);//Crystal osc. enabled
	LT89WriteReg(11,0x0008);//RSSI enabled.	
	LT89WriteReg(12,0x0000);
	LT89WriteReg(13,0x48bd);
	LT89WriteReg(22,0x00ff);
	LT89WriteReg(23,0x8005);//Calibrate VCO before each and every Tx/Rx
	LT89WriteReg(24,0x0067);
	LT89WriteReg(25,0x1659);
	LT89WriteReg(26,0x19e0);
	LT89WriteReg(27,0x1300);//No crystal trim. 
	LT89WriteReg(28,0x1800);		
	LT89WriteReg(43,0x000f);//WAIT_RSSI_SCAN_TIM = 0xf
//-------------------------------

/*Config time delay*/

	LT89WriteReg(33,0x3fc7);
	LT89WriteReg(34,0x2000);
	
	LT89WriteReg(35,3<<RE_TRANSMIT_TIMES);
	
/*Config Packet Data Structure*/

	LT89WriteReg(32,(PRE_3BYTE<<PREAMBLE_LEN)|(SYNC_32BIT<<SYNCWORD_LEN));	

	LT89WriteReg(SYNC_WORD0_REG,0x0380);
	
	LT89WriteReg(SYNC_WORD3_REG,0x0380);
	
	LT89WriteReg(40,0x4401);
	
	LT89WriteReg(41,CRC_ON|PACK_LENGTH_EN|FLAG_ACTIVE_LOW);
	
	LT89WriteReg(42,0xfdb0);//RX_ACK_TIME 0xb0 = 176 us
	
/*Config Data rate */

	LT89WriteReg(AIR_RATE_REG,_62K5BPS);//
	LT89WriteReg(OPTION_REG,_NOR);//
		
}

unsigned char LT89ReadFIFO(unsigned char *buff)
{
	unsigned int val;
	unsigned char len_parket,i;
	
	val = LT89ReadReg(TXRX_FIFO_REG);
	
	len_parket = val>>8;
	buff[0] = len_parket;
	buff[1] = val;
	i=2;

	do
	{	
		val = LT89ReadReg(TXRX_FIFO_REG);
		buff[i++] = val>>8; 
		buff[i++] = val;
		
	}while(i<=len_parket);
	
	return buff[0]+1;
}

void LT89SendFIFO(unsigned char *dat,unsigned char ch)
{
  /*Send parket */
   
   unsigned int tmp=0;
	
	LT89WriteReg(SET_CHANNEL_REG,(ch<<RF_PLL_CH_NO));	
  //RXTX FIFO pointer is Read Only
  //Clear RXTX FIFO pointer to 0
  LT89WriteReg(FIFO_PTR_REG,CLR_W_PTR|CLR_R_PTR);

  //Add data to FIFO
  tmp =dat[0]<<8| dat[1];//
  LT89WriteReg(TXRX_FIFO_REG,tmp); //PACK_LENGTH = 5
  tmp =dat[2]<<8 | dat[3];
  LT89WriteReg(TXRX_FIFO_REG,tmp); 
  tmp =dat[4]<<8 | dat[5];//
  LT89WriteReg(TXRX_FIFO_REG,tmp);
  
  //Set channel 7bit
  //Channel The on-air frequency f = 2402 + 16 -> Tx enable
  LT89WriteReg(SET_CHANNEL_REG,TX_EN|(ch<<RF_PLL_CH_NO));
  
  //tmp=10;
  //while(lt89Pkt()!=0 || tmp==0){tmp--;delay(10);}
  
}