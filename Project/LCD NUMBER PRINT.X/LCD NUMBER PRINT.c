/*
 * File:   LCD NUMBER PRINT.c
 * Author: Prathap
 *
 * Created on March 10, 2023, 10:51 AM
 */

#include<pic.h>
#define _XTAL_FREQ 400000
#define RS RD0
#define RW RD1
#define E  RD2
int pulse();
void main()
{
    TRISC=0X00;
    TRISD=0X00;
    PORTC=0X00;
    PORTD=0X00;
    int i,j,k;
    RW=0;
    RS=0;
    PORTC=0X38;
    pulse();
    RW=0;
    RS=0;
    PORTC=0X0E;
    pulse();
    while(1)
    {
        for (i=0;i<=9;i++)
        {
           for (j=0;j<=9;j++)
           {
               for (k=0;k<=9;k++)
               {
                   RW=0;
                   RS=0;
                   PORTC=0X80;
                   pulse();
                   RW=0;
                   RS=1;
                   PORTC=0x30+i;
                   pulse();
                   PORTC=0x30+j;
                   pulse();
                   PORTC=0X30+k;
                   pulse();
               }
           }   
        }
    }
}
pulse()
{
    E=0;
    __delay_ms(1000);
    E=1;
    __delay_ms(1000);
}