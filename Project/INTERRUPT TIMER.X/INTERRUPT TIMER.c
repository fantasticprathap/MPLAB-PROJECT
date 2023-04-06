/*
 * File:   INTERRUPT TIMER.c
 * Author: Prathap
 *
 * Created on March 31, 2023, 11:13 AM
 */

#include<pic.h>
#define _XTAL_FREQ 4000000
#define RS RC0
#define RW RD5
#define E  RD6
void pulse();
void LCD(int,int);
void display(int);
int cnt,sec=0;
void __interrupt() timer1_int()
{
    if (TMR1IF==1)
    { 
        cnt++;
        TMR1IF=0;
        TMR1=55536; 
        LCD(0x80,0);
        display(cnt);
        if(sec<2)
        {
            RC1=1;
        }
        if (sec>2)
        {
             RC1=0;
        }
    }    
}
void main()
{
    TRISD=0X00;
    PORTD=0X00;
    TRISC=0X00;
    PORTC=0X00;
    T1CON=0X11;
    TMR1=55536;
    GIE=1;
    PEIE=1;
    TMR1IE=1;
    LCD(0x02,0);
    LCD(0x28,0);
    LCD(0x0E,0);
    int cnt1=0;
    while(1)
    {
        timer();
    }
}
void pulse()
{
    E=1;
    __delay_us(50);
    E=0;
    __delay_us(50);
}
void LCD(int g,int h)
{
    RS=h;
    RW=0;
    PORTD=(g&0xf0)>>4;
    pulse();
    PORTD=(g&0x0f);
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
timer()
{
    if (cnt==50)
    {
        sec++;
        cnt=0;
        LCD(0xc0,0);
        display(sec);
    }
    if (sec<2)
    {
        RC6=0;
        RC7=0;
        RC5=1;
    }
    if ((sec>2)&&(sec<4))
    {
        RC5=0;
        RC7=0;
        RC6=1;
    }
    if ((sec>4)&&(sec<6))
    {
        RC6=0;
        RC5=0;
        RC7=1;
    }
    if (sec>7)
    {
        sec=0;
    }
}