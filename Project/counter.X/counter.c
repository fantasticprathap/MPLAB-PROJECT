/*
 * File:   counter.c
 * Author: Prathap
 *
 * Created on April 3, 2023, 2:30 PM
 */

#include<pic.h>
#define _XTAL_FREQ 4000000
#define RS RE0
#define E  RE1
void pulse();
void LCD(int,int);
void display(int);
void main()
{
    TRISA=0X10;
    PORTA=0X00;
    TRISD=0X00;
    PORTD=0X00;
    TRISE=0X00;
    PORTE=0X00;
    ANSEL=0X00;
    ANSELH=0X00;
    OPTION_REG=0X21;
    TMR0=0;
    LCD(0X02,0);
    LCD(0X28,0);
    LCD(0X0E,0);
    while(1)
    {
        display(TMR0);
    }
}
void pulse()
{
    E=1;
    __delay_ms(50);
    E=0;
    __delay_ms(50);
}
void LCD(int g,int h)
{
    RS=h;
    PORTD=(g&0xf0)>>4;
    pulse();
    PORTD=(g&0x0f);
    pulse();
}
void display(int k)
{
    LCD(0X80,0);
    int a,b,c;
    a=k/100;
    b=(k%100)/10;
    c=k%10;
    LCD(0x30+a,1);
    LCD(0x30+b,1);
    LCD(0x30+c,1);
}









//void LCD( int g,int h)
//{
//    RS=h;
//    PORTD=g;
//    pulse();
//}