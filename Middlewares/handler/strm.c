#include "strm.h"

void dataStream(void* sendByte,unsigned char buf,unsigned char len){
	unsigned char i=0;
	while(i<len){
		sendByte(buf[i]);
		i++;
	}
}