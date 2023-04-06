/*
 * File:   BUTTERFLY2.c
 * Author: Prathap
 *
 * Created on March 7, 2023, 7:02 PM
 */

#include<pic.h>
#define _XTAL_FREQ 400000
void main()
{
    TRISA=0x00;
    TRISB=0x00;
    TRISC=0x00;
    TRISD=0x00;
    TRISE=0x00;
    PORTA=0X00;
    PORTB=0x00;
    PORTC=0x00;
    PORTD=0x00;
    PORTE=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
        PORTE=0xFF;
        __delay_ms(160);
        PORTA=0xFF;
        PORTB=0xFF;
        PORTC=0xFF;
        PORTD=0xFF;
        __delay_ms(160);
        PORTA=0x00;
        PORTB=0x00;
        PORTC=0x00;
        PORTD=0x00;
        __delay_ms(160);
    }
}