#ifndef __LT89xx_H_
#define __LT89xx_H_

/* Memory Map */

// Bit Mask

/* Register 3  – Read only */
#define RF_SYNTH_LOCK 12

/* Register 6  – Read only */
#define RAW_RSSI_REG 6
#define RAW_RSSI	10	// 6bit

/* Register 7 */
#define SET_CHANNEL_REG 7
#define TX_EN	0x100 //bit8
#define RX_EN	0x80	//bit7
#define RF_PLL_CH_NO 0 // 7bit

/* Register 9 */
#define PA_PWCTR	12	// 3bit
#define PA_GN	7// 3bit

/* Register 10 */
#define XTAL_OSC_EN 1

/* Register 11 */
#define RSSI_PDN 0x100 //Received Signal Strength Indicator

/* Register 23 */
#define TXRX_VCO_CAL_EN	4

/* Register 27 */
#define XI_TRIM 0//6bit	

/* Register 29 – Read only */
#define RF_VER_ID	4//4bit
#define DIG_VER	0//2bit

/* Register 30 – Read only */
#define ID_CODE_L 0//16bit

/* Register 31 – Read only */
#define RF_CODE_ID 12//4bit
#define ID_CODE_H 0//11bit

/* Register 32 */ 
#define PREAMBLE_LEN 13//3bit
	//------
	#define PRE_1BYTE 0
	#define PRE_2BYTE 1
	#define PRE_3BYTE 2
	#define PRE_4BYTE 3
	#define PRE_5BYTE 4
	#define PRE_6BYTE 5
	#define PRE_7BYTE 6
	#define PRE_8BYTE 7
	//------

#define SYNCWORD_LEN 11//2bit
	//------
	#define SYNC_64BIT 3//{Reg39[15:0],Reg38[15:0],Reg37[15:0],Reg36[15:0]} 
	#define SYNC_48BIT 2//{Reg39[15:0],Reg38[15:0],Reg36[15:0]}
	#define SYNC_32BIT 1//{Reg39[15:0],Reg36[15:0] 
	#define SYNC_16BIT 0//{Reg36[15:0]} 
	//------

#define TRAILER_LEN 8//3bit
	//------
	#define TRAIL_4BIT 0
	#define TRAIL_6BIT 1
	#define TRAIL_8BIT 2
	#define TRAIL_10BIT 3
	#define TRAIL_12BIT 4
	#define TRAIL_14BIT 5
	#define TRAIL_16BIT 6
	#define TRAIL_18BIT 7
	//------

#define DATA_PACKET_TYPE 6//2bit
	//------
	#define DATA_NRZ 0
	#define DATA_MAN 1
	#define DATA_8P10 2
	#define DATA_INTER 3
	//------

#define FEC_TYPE 4//2bit Forward Error Correction
	//------
	#define FEC_NO 0
	#define FEC_13 1
	#define FEC_23 2
	//------

#define BRCLK_SEL 1//3bit
	//------
	#define KEEP_LOW 0
	#define CRY_BUF 1
	#define CRY_DIV2 2
	#define CRY_DIV4 3
	#define CRY_DIV8 4
	#define TX_CLK 5
	#define APLL_CLK 6
	//------

/* Register 33 */
#define VCO_ON_DELAY_CNT 8//8bit
#define TX_PA_OFF_DELAY 6//2bit
#define TX_PA_ON_DELAY 0//6bi

/* Register 34 */
#define BPKCTL_DIR 0x8000
#define TX_CW_DLY 8//7bit
#define TX_SW_ON_DELAY 0//6bit

/* Register 35 */
#define POWER_DOWN 0x8000
#define SLEEP_MODE 0x4000
#define BRCLK_ON_SLEEP 0x1000
#define RE_TRANSMIT_TIMES 8//4bit
#define MISO_TRI_OPT 0x80
#define SCRAMBLE_DAT 0//7bit

/* Register 36 */
#define SYNC_WORD0_REG 36
/* Register 37 */
#define SYNC_WORD1_REG 37
/* Register 38 */
#define SYNC_WORD2_REG 38
/* Register 39 */
#define SYNC_WORD3_REG 39

/* Register 40 */
#define FIFO_EMPTY_THRES 11//5bit
#define FIFO_FULL_THRES 6//5bit
#define SYNCWORD_THRES 0//6bit

/* Register 41 */
#define CRC_ON 0x8000
#define SCRAMBLE_ON 0x4000
#define PACK_LENGTH_EN 0x2000
#define FW_TERM_TX  0x1000
#define AUTO_ACK 0x800
#define FLAG_ACTIVE_LOW 0x400 //PKT_FIFO_FLAG_ACTIVELOW
#define CRC_INITIAL_DATA 0//8bit

/* Register 42 */
#define SCAN_RSSI_CH_NO 10//6b
#define RX_ACK_TIME 0//8b

/* Register 43 */
#define SCAN_RSSI_EN 0x8000
#define SCAN_STRT_CH_OFFST 8//7b
#define WAIT_RSSI_SCAN_TIM 0//8b

/* Register 44 */
#define AIR_RATE_REG 44
#define _1MBPS 0x0100
#define _250KBPS 0x0400
#define _125KBPS 0x0800
#define _62K5BPS 0x1000

/* Register 45 */
#define OPTION_REG 45
#define _1M 0x0080
#define _NOR 0x0552

/* Register 48 – Read only */
#define STATUS_REG 48
//------
	#define CRC_ERROR 0x8000
	#define FEC23_ERROR 0x4000
	#define FRAMER_ST 0x3f00//6b
	#define SYNCWORD_RECV 0x80
	#define PKT_FLAG 0x40
	#define FIFO_FLAG 0x20
//------

/* Register 50 */
#define TXRX_FIFO_REG 50//16b

/* Register 52 */
#define FIFO_PTR_REG 52
#define CLR_W_PTR 0x8000
#define FIFO_WR_PTR 8//6b
#define CLR_R_PTR 0x80
#define FIFO_RD_PTR 0//6b


#endif