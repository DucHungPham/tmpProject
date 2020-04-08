#ifndef __var_H
#define __var_H

/**
 * For example.,
If you want to declare a 8bit register with one-2bit bitfield, one-3bit bitfield, one-1bit bitfield, then the code will be,

// declaration
typedef union
{
    unsigned char Byte;
    struct
    {
         unsigned char bit012 : 3;
         unsigned char bit34 : 2;
         unsigned char bit5 : 1;
         unsigned char bit6 : 1;
         unsigned char bit7 : 1;
     }bits;
}registerType;

// define a pointer and cast it to point to the registers memory location
registerType *pReg = (registerType*)0x00008000;

// use the fields as
pReg->bits.bit5 = 1;
pReg->bits.bit012 = 7;

// access the whole byte as
pReg->Byte = 0x55;
 */
typedef unsigned char uint8_t;
typedef unsigned short ushort;
typedef unsigned int uint16_t;
typedef unsigned long ulong;

typedef union {
    unsigned char byte;
    struct{
        unsigned char b0 : 1;
        unsigned char b1 : 1;
        unsigned char b2 : 1;
        unsigned char b3 : 1;
        unsigned char b4 : 1;
        unsigned char b5 : 1;
        unsigned char b6 : 1;
        unsigned char b7 : 1;
    } bits;
}regType;

#endif
