/*
 * File:   LED BUTTON GLOW USING TIMER.c
 * Author: Prathap
 *
 * Created on March 26, 2023, 10:43 AM
 */

#include<pic.h>
#define _XTAL_FREQ 400000
#define RS RA2
#define RW RA1
#define E  RA0
#define button1 RA3
#define button2 RA6
void pulse();
void timer();
void LCD(char);
void display(char);
int count=0;
int i=3;
void main()
{
    TRISA=0X48;
    PORTA=0X00;
    TRISC=0X00;
    PORTC=0X00;
    TRISD=0X00;
    PORTD=0X00;
    ANSEL=0x00;
    OPTION_REG=0x06;
    TMR0=131;
    LCD(0x38);
    LCD(0x0e);
    {
        LCD(0x80);
        if (button1==1)
        {
            while(button2==0)
            {
                LCD(0x80);
                timer();
                display(count);
            }        
        }
        if (button2==1)
        {
            while(count>=0)
            {
                LCD(0x02);
                display(count);
                RA7=1;
                count--;
            }
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
void LCD(char g)
{
    RS=0;
    RW=0;
    PORTC=g;
    pulse();         
}
void timer()
{
    if(T0IF==1)
    {
        count++;
        T0IF=0;
    }
}
void display(char h)
{
    RS=1;
    RW=0;
    PORTC=(0x30+(h/10));
    pulse();
    PORTC=(0x30+(h%10));
    pulse();
}