/*
 * File:   INTERRUPT USING 2 SEGMENT.c
 * Author: Prathap
 *
 * Created on March 30, 2023, 12:27 PM
 */

#include<pic.h>
#define _XTAL_FREQ 4000000
#define RS RA0
#define RW RA1
#define E  RA2
int cc[ ]={ 0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67 };
void pulse();
void LCD(int,int);
void display(int);
void __interrupt () itr ()
{
    if (INTF==1)
    {  
        int i=0;
        for (i=0;i<=9;i++)
        {
            PORTD=cc[i];
            __delay_ms(500);
        }
        i=0;
        INTF=0;
    }
}
void main()
{
    TRISA=0x00;
    PORTA=0x00;
    TRISB=0X01;
    PORTB=0X00;
    TRISC=0X00;
    PORTC=0X00;
    TRISD=0X00;
    PORTD=0X00;
    ANSEL=0X00;
    ANSELH=0X00;
    LCD(0x02,0);
    LCD(0x28,0);
    LCD(0x0e,0);
    INTCON=0b11010000;
    int cnt=0;
    while(1)
    {
        LCD(0x80,0);
        cnt++;
        display(cnt);
    }
}
void pulse()
{
    E=1;
    __delay_ms(10);
    E=0;
    __delay_ms(10);
}
void LCD(int g,int h)
{
   RS=h;
   RW=0;
   PORTC=(g&0Xf0)>>4;
   pulse();
   PORTC=(g&0x0f);
   pulse();
}
void display(int k)
{
    int a,b,c;
    a=k/100;
    b=(k%100)/10;
    c=k%10;
    LCD(0x30+a,1);
    LCD(0x30+b,1);
    LCD(0x30+c,1);
}