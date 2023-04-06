/*
 * File:   NAME SHOW LED.c
 * Author: Prathap
 *
 * Created on March 9, 2023, 3:55 PM
 */

#include<pic.h>
#define _XTAL_FREQ 400000
#define RS RD0
#define RW RD1
#define E RD2
int pulse();
void main()
{
    TRISC=0X00;
    TRISD=0X00;
    PORTC=0X00;
    PORTD=0X00;
    RW=0;
    RS=0;
    PORTC=0X38;                             //8 BIT TWO LINE 5*7 DOTS
    pulse();
    RW=0;
    RS=0;
    PORTC=0X0E;                             // CURSOR ON DISPLAY ON
    pulse();
    while(1)
    {
        RW=0;
        RS=0;
        PORTC=0X80;                             // ADDRESS
        pulse();
        RW=0;
        RS=1;
        PORTC="prathap";
    }
}
int pulse()
{
    E=0;
    __delay_ms(1000);
    E=1;
    __delay_ms(1000);
}