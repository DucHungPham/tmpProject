#include "sw_uart.h"

void swUartSendByte(unsigned char dat) {
    unsigned char i;

    //startBit
    //
    swUartTxLow();
    swUartDelay();
    //data
    //
    for (i = 0; i < 8; i++) {
        if(dat & 1) swUartTxHigh();
        else swUartTxLow();
        dat = dat >> 1;
        swUartDelay();
    }
    //parity bit
    //swUartTx = 0;
    //swUartDelay();
    //
    //StopBit
    swUartTxHigh();
    swUartDelay();

}
