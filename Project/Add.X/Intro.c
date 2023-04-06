/*
 * File:   Intro.c
 * Author: Prathap
 *
 * Created on March 2, 2023, 3:26 PM
 */

#include<pic.h>
#define _XTAL_FREQ 400000
void delay(int j)
{
 while(j--);   
}
void main()
{
    TRISA=0x00;
    PORTA=0x00;
    TRISB=0x00;
    TRISC=0x00;
    TRISD=0x00;
    TRISE=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
        PORTA=0xFF;
        delay(1000);
        PORTA=0x00;
        delay(1000);
        PORTB=0xFF;
        PORTC=0xFF;
        PORTD=0xFF;
        delay(1000);
        PORTD=0x00;
        delay(1000);
        PORTE=0xFF;
    }
}    
