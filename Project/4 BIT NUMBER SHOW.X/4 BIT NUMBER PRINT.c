/*
 * File:   4 BIT NUMBER PRINT.c
 * Author: Prathap
 *
 * Created on March 13, 2023, 2:23 PM
 */
#include<pic.h>
#define _XTAL_FREQ 400000
#define RS RC0
#define RW RC1
#define E  RC2
void pulse();
void LCD(char a,int h);
void display(int);
void main()
{
    TRISC=0X00;
    TRISD=0X00;
    PORTC-0X00;
    PORTD=0X00;
    LCD(0X02,0);
    LCD(0X28,0);
    LCD(0X0E,0); 
    while(1)
    {
        display(3543);
    }
}
void pulse()
{
    E=1;
    __delay_ms(500);
    E=0;
    __delay_ms(500);
}
void LCD(char a,int h)
{
    RS=h;
    RW=0;
    PORTD=(a&0xf0)>>4;
    pulse();
    PORTD=(a&0x0f);
    pulse();
}
void display(int b)
{
   LCD(0X80,0); 
   LCD((b/1000)+0X30,1);
   LCD(((b%1000)/100)+0X30,1);
   LCD((((b%1000)%100)/10)+0x30,1);
   LCD((((b%1000)%100)%10)+0x30,1);   
}