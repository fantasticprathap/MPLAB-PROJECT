/*
 * File:   4 bit forward and reverse.c
 * Author: Prathap
 *
 * Created on March 13, 2023, 6:43 PM
 */
#include<pic.h>
#define _XTAL_FREQ 400000
#define RS RC0
#define RW RC1
#define E  RC2
void pulse();
void LCD(char,int);
void display();
void display1();
void main()
{
    TRISC=0X00;
    TRISD=0X00;
    PORTC=0X00;
    PORTD=0X00;
    LCD(0X02,0);
    LCD(0X28,0);
    LCD(0X0E,0);
    while(1)
    {
        display();
    }
}
void pulse()
{
    E=1;
    __delay_ms(200);
    E=0;
    __delay_ms(200);
}
void LCD(char a, int b)
{
    RS=b;
    RW=0;
    PORTD=(a&0xf0)>>4;
    pulse();
    PORTD=(a&0x0f);
    pulse();
}
void display()
{
    int j,k,l,x,y,z;
    for (j=0,x=9;j<=9,x>=0;x--,j++)
    {
        for (k=0,y=9;k<=9,y>=0;y--,k++)
        {
            for (l=0,z=9;l<=9,z>=0;z--,l++)
            {
                LCD(0X80,0);
                LCD((0X30+j),1);
                LCD((0X30+k),1);
                LCD((0X30+l),1);
                LCD(0Xcd,0);
                LCD((0X30+x),1);
                LCD((0X30+y),1);
                LCD((0X30+z),1);
            }
        }
    }
}
