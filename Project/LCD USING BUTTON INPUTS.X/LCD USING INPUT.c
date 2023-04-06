/*
 * File:   LCD USING INPUT.c
 * Author: Prathap
 *
 * Created on March 20, 2023, 12:23 PM
 */


#include<pic.h>
#define _XTAL_FREQ 400000
#define button RC0
#define button1 RC1
#define button2 RC2
#define RS RC5
#define RW RC6
#define E  RC7
int count,count1,total=0;
void pulse();
void LCD(int,int);
void display(int);
void main()
{
    TRISC=0X07;
    PORTC=0X00;
    TRISD=0X00;
    PORTD=0X00;
    LCD(0x38,0);
    LCD(0X0E,0);
    while(1)
    {
        if (button==1)
        {
            LCD(0X80,0);
            count++;
            display(count);
            while(button==1);
        }
        if(button1==1)
        {
            LCD(0X8E,0);
            count1++;
            display(count1);
            while(button==1);
        }
        if(button2==1)
        {
            LCD(0XC7,0);
            total=count+count1;
            display(total-1);
            while(button==1);
        }
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
    PORTD=g;
    pulse();
}
void display(int a)
{
    LCD((0x30+(a-1)/10),1);
    LCD((0x30+(a-1)%10),1);   
}