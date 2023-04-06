/*
 * File:   LCD DISPLAY.c
 * Author: Prathap
 *
 * Created on March 9, 2023, 12:48 PM
 */

#include<pic.h>
#define _XTAL_FREQ 400000
void main()
{
    TRISC=0x00;
    TRISD=0x00;
    PORTC=0x00;
    PORTD=0x00;
    RD0=0;
    RD1=0;
    PORTC=0X38;
    RD2=1;
    __delay_ms(1000);
    RD2=0;
    __delay_ms(1000);
    RD0=0;
    RD1=0;
    PORTC=0x0E;
    RD2=1;
    __delay_ms(1000);
    RD2=0;
    __delay_ms(1000);
    int i;
    while(1)
    {
        RD0=0;
        RD1=0;
        PORTC=0x8f;
        RD2=1;
        __delay_ms(1000);
        RD2=0;
        __delay_ms(1000);
            RD0=0;
            RD1=1;
            PORTC='A';
            RD2=1;
            __delay_ms(1000);
            RD2=0;
            __delay_ms(1000);
            RD0=0;
            RD1=1;
//            RD0=0;
//            RD1=0;
//            PORTC=0X1C;
//            RD2=1;
//            __delay_ms(1000);
//            RD2=0;
//            __delay_ms(1000);
            RD0=0;
            RD1=0;
            PORTC=0X18;
            RD2=1;
            __delay_ms(1000);
            RD2=0;
            __delay_ms(1000);
    }
}