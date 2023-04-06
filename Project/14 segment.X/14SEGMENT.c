/*
 * File:   14SEGMENT.c
 * Author: Prathap
 *
 * Created on March 9, 2023, 10:50 AM
 */

#include<pic.h>
#define _XTAL_FREQ 400000
void main()
{
    TRISA=0x00;
    TRISB=0x00;
    TRISC=0x00;
    PORTA=0x00;
    PORTB=0x00;
    PORTC=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    char ca[ ]={ 0x08,0xf0,0xc6,0xf0,0xc6,0xce,0xc2,0xc9,0xf6,0xe1,0xcf,0xc7,0xc9,0xc9,0xc0,0xcc,0xc0,0xcc,0xd2,0x3e,0x01,0x0f,0x09,0xff,0xff,0x36};
    char cb[ ]={ 0x77,0xd5,0xff,0xdd,0x77,0x77,0xf7,0x77,0xdd,0xff,0x6b,0xff,0xfa,0xee,0xff,0x77,0xef,0x67,0x77,0xdd,0xff,0xbb,0xaf,0xaa,0xba,0xbb};
    int i;
    RB0=1;
    while(1)
    {
        for (i=0;i<26;i++)
        {
            PORTA=cb[i];
            PORTC=ca[i];
            __delay_ms(2000);
            __delay_ms(2000);
        }
    }
}