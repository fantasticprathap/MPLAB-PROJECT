/*
 * File:   ketpad input.c
 * Author: Prathap
 *
 * Created on March 21, 2023, 11:38 AM
 */

#include<pic.h>
#define _XTAL_FREQ 400000
#define RS RA2
#define RW RA1
#define E  RA0
void puse();
void LCD();
void first_seg();
void second_seg();
void third_seg();
void keypad(int,int,int,int);
int a=0x30;int b=0x31;int c=0x32;int d=0x33;int e=0x34;int f=0x35;
int i=0x36;int j=0x37;int k=0x38;int l=0x39;int m=0x2a;int n=0x23;
void main()
{
    TRISD=0Xf8;
    PORTD=0X00;
    TRISC=0X00;
    PORTC=0X00;
    TRISA=0X00;
    PORTA=0X00;
    ANSEL=0X00;
    ANSELH=0X00;
    LCD(0x38,0);
    LCD(0X0E,0);
    while(1)
    {
        first_seg();
        second_seg();
        third_seg();
        if(RD7==1)
        {
            LCD(0X01,1);
        }
    }
}
void keypad(int w,int x,int y,int z)
{
    if(RD3==1)
    {
        LCD(w,1);
        while(RD3==1);
    }
    if(RD4==1)
    {
        LCD(x,1);
        while(RD4==1);
    }
    if(RD5==1)
    {
        LCD(y,1);
        while(RD5==1);
    }
    if(RD6==1)
    {
        LCD(z,1);
        while(RD6==1);
    }
}
void pulse()
{
    E=1;
    __delay_ms(500);
    E=0;
    __delay_ms(500);
}
void LCD(int g,int h)
{
    RS=h;
    RW=0;
    PORTC=g;
    pulse();
}
void first_seg()
{
    RD0=0;
    RD1=0;
    RD2=1;
    keypad(b,e,j,m);
}
void second_seg()
{
    RD2=0;
    RD0=0;
    RD1=1;
    keypad(c,f,k,a);
}
void third_seg()
{
    RD1=0;
    RD2=0;
    RD0=1;
    keypad(d,i,l,n);
}