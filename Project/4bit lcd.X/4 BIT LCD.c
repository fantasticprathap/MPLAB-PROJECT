/*
 * File:   4 BIT LCD.c
 * Author: Prathap
 *
 * Created on March 13, 2023, 10:30 AM
 */

#include<pic.h>
#define _XTAL_FREQ 400000
#define RS RC5
#define RW RC6
#define E  RC7
void pulse();
void lcd(int,int);
void main()
{
    TRISC=0x00;
    TRISD=0x00;
    PORTC=0x00;
    PORTD=0x00;
    lcd(0x02,0);
    lcd(0x28,0);
    lcd(0x0E,0);
    while(1)
    {
        lcd(0x80,0);
        lcd(0x41,1);
    } 
}
void pulse()
{
    E=1;
    __delay_ms(1000);
    E=0;
    __delay_ms(1000);
}
void lcd(int a,int b)
{
    RW=0;
    RS=b;
    PORTD=(a&0xF0)>>4;
    pulse();
    PORTD=(a&0x0F);
    pulse();
}
