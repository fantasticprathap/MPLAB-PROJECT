/*
 * File:   TIMER USING LED.c
 * Author: Prathap
 *
 * Created on March 25, 2023, 12:06 PM
 */
#include<pic.h>
#define _XTAL_FREQ 400000
#define RS  RC5
#define RW  RC6
#define E   RC7
void pulse();
void LCD(char);
void timer();
void display();
int count=0;
void main()
{
    TRISA=0x00;
    PORTA=0x00;
    TRISC=0x00;
    PORTC=0x00;
    TRISD=0x00;
    PORTD=0x00;
    ANSEL=0x00;
    OPTION_REG=0x06;
    TMR0=131;
    LCD(0x38);
    LCD(0x0e);
    LCD(0x80);
    while(1)
    {
        LCD(0x80);
        timer();
        display();
        if((count>0)&&(count<=20))
        {
            RA0=0;
            RA1=0;
            RA4=0;
            RA5=0;
            RA2=1;
            RA3=1;
        }
        if((count>20)&&(count<=30))
        {
            RA2=0;
            RA0=0;
            RA3=0;
            RA4=0;
            RA1=1;
            RA4=1;
        }
        if((count>30)&&(count<=50))
        {
            RA1=0;
            RA2=0;
            RA3=0;
            RA4=0;
            RA0=1;
            RA5=1;
        }
        if(count>50)
        {
            count=0;
        }
    }
}
void pulse()
{
    E = 1;
    __delay_ms(500);
    E = 0;
    __delay_ms(500);
}
void LCD(char g)
{
    RS=0;
    RW=0;
    PORTD=g;
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
void display()
{
    RS=1;
    RW=0;
    PORTD=(0x30+count/10);
    pulse();
    PORTD=(0x30+count%10);
    pulse();

}