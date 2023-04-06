/*
 * File:   led.c
 * Author: Prathap
 *
 * Created on March 7, 2023, 10:56 AM
 */
#include<pic.h>
#define _XTAL_FREQ 400000

void main()
{
    TRISA=0x00;
    PORTA=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
        RA0=1;
        __delay_ms(3000);
        RA1=1;
        __delay_ms(3000);
        RA2=1;
        __delay_ms(3000);
        RA3=1;
        __delay_ms(3000);
        RA4=1;
        __delay_ms(3000);
        RA5=1;
        __delay_ms(3000);
        RA6=1;
        __delay_ms(3000);
        RA7=1;
        __delay_ms(3000);
        PORTA=0x00;
        RA7=1;
        __delay_ms(3000);
        RA6=1;
        __delay_ms(3000);
        RA5=1;
        __delay_ms(3000);
        RA4=1;
        __delay_ms(3000);
        RA3=1;
        __delay_ms(3000);
        RA2=1;
        __delay_ms(3000);
        RA1=1;
        __delay_ms(3000);
        RA0=1;
        __delay_ms(3000);
        PORTA=0x00;
    }
}
