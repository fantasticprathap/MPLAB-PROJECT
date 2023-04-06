/*
 * File:   INTERRUPT USING LED AND MOTOR.c
 * Author: Prathap
 *
 * Created on March 30, 2023, 11:15 AM
 */

#include<pic.h>
#define _XTAL_FREQ 4000000
int flag=0;
void __interrupt() itr()
{
    if (INTF==1)
    {
        flag=flag^1;
        INTF=0;
    }   
}
void main()
{
    TRISB=0X01;
    PORTB=0X00;
    TRISC=0X00;
    PORTC=0X00;
    ANSEL=0X00;
    ANSELH=0X00;
    INTCON=0b11010000;
//    GIE=1;
//    PEIE=1;
//    INTE=1;
    while(1)
    {   
        if (flag==1)
        {
            RC0=1;
            RC1=0;
        }
        if (flag==0)
        {
            RC0=0;
            RC1=1;
        }
    }
}