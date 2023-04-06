/*
 * File:   keypad calling function.c
 * Author: Prathap
 *
 * Created on March 22, 2023, 7:07 PM
 */

#include<pic.h>
#include<stdio.h>
#define _XTAL_FREQ 400000
#define RS RA2
#define RW RA1
#define E  RA0
void pulse();
void LCD(char,char);
void LCD_s(char*);
void keypad(int,int,int,int);
void first_seg();
void second_seg();
void third_seg();
int num[ ]={ 0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x2a,0x23};
int T=0;
void main()
{
    TRISA=0X00;
    PORTA=0X00;
    TRISC=0X00;
    PORTC=0X00;
    TRISD=0X78;
    PORTD=0X00;
    ANSEL=0X00;
    ANSELH=0X00;
    LCD(0x38,0);
    LCD(0x0e,0);
    while(1)
    {
        first_seg();
        second_seg();
        third_seg();
    }
}
void pulse()
{
    E=1;
    __delay_ms(500);
    E=0;
    __delay_ms(500);
}
void LCD(char g,char h)
{
    RS=h;
    RW=0;
    PORTC=g;
    pulse();
}
void LCD_s(char *g)
{
    RS=1;
    RW=0;
    while(*g)                //try to change
    {
    PORTC=*g++;
    pulse();
    }
}
void first_seg()
{
    RD0=0;
    RD1=0;
    RD2=1;
    keypad(1,4,7,10);
}
void second_seg()
{
    RD0=0;
    RD2=0;
    RD1=1;
    keypad(2,5,8,0);
}
void third_seg()
{
    RD2=0;
    RD1=0;
    RD0=1;
    keypad(3,6,9,11);
}
void keypad(int a,int b,int c,int d)
{
    if(RD3==1)
    {
        LCD(num[a],1);
        T++;
        while(RD3==1);
    }
    if(RD4==1)
    {
        LCD(num[b],1);
        T++;
        while(RD4==1);
    }
    if(RD5==1)
    {
        LCD(num[c],1);
        T++;
        while(RD5==1);
    }
    if((RD6==1)&&(d==0))
    {
        LCD(num[d],1);
        T++;
        while((RD6==1)&&(d==0));
    }
    if ((RD6==1)&&(d==10))
    {
        if (T==10)
        {
            LCD(0xc7,0);
            LCD_s("calling..");
            while((RD6==1)&&(d==10));
        }
        else
        {
            LCD(0xc0,0);
            LCD_s("Wrong Number");
        }
    }
    if ((RD6==1)&&(d==11))
    {
        LCD(0x01,0);
        T=0;
    }
}

