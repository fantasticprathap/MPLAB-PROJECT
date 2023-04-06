/*
 * File:   TIMER 1 USING LED GLOW.c
 * Author: Prathap
 *
 * Created on March 28, 2023, 12:06 PM
 */

#include<pic.h>
#define _XTAL_FREQ 4000000
#define RS RC2
#define RW RC3
#define E  RC4
#define button1 RC0
#define button2 RC1
void pulse();
void timer(int);
void LCD(int,int);
void display(int);
int count=0,count1=0;
void main()
{
    TRISC=0X03;
    PORTC=0X00;
    TRISD=0X00;
    PORTD=0X00;
    TMR1=55536;
    T1CON=0X11;
    LCD(0x02,0);
    LCD(0X28,0);
    LCD(0X0E,0);
    LCD(0X80,0);
    while(1)
    {
        if (button1==1)
        {
            LCD(0X80,0);
            count++;
            display(count); 
            while(button1==1);
        }
        if (button2==1)
        {
            while(button2==1);
            RC5=1;
            timer(count); 
            RC5=0;   
        }
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
void timer(int m)
{
    int time=0,cnt=0;
    while (m>time)
    {
      if (TMR1IF==1) 
      {
          cnt++;
          TMR1IF=0; 
          TMR1=55536;
      }
      if (cnt==50)
      {
          time++;
          cnt=0;
      }
    }
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


