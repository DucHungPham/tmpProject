#include "utf8.h"
/**
 * Convert encode bytes array to unicode array
 * @param  buf :encode bytes array.
 * @param  len :length of buffer.
 * @return     length of decode bytes array.
 */
uint16_t utf8_decode(uint8_t *buf, uint16_t len) {
	uint16_t decd[];
	uint16_t j = 0, tmp;
	uint16_t i;
	//110vvvvv 10vvvvvv
	//1110vvvv 10vvvvvv 10vvvvvv
	for ( i = 0; i < len; i++)
	{
		if ((buf[i] & 0xf0) == 0xe0) {
			tmp = (buf[i] & 0x0f) << 12;
			tmp = tmp | ((buf[i + 1] & 0x3f) << 6);
			tmp = tmp | (buf[i + 2] & 0x3f);
			decd[j] = tmp ;
			i = i + 2;
		} else if ((buf[i] & 0xe0) == 0xc0) {
			tmp = (buf[i] & 0x1f) << 6;
			tmp = tmp | (buf[i + 1] & 0x3f);
			decd[j] = tmp ;
			i = i + 1;
		} else if ((buf[i] < 128)) {
			decd[j] = buf[i] ;
		}
		j++;
	}	
	return j;
}