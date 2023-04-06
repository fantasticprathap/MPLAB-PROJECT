/*
 * File:   2 way switch.c
 * Author: Prathap
 *
 * Created on March 14, 2023, 11:25 AM
 */
#include<pic.h>
#define _XTAL_FREQ 400000
void main()
{
    TRISC=0x81;
    TRISD=0x00;
    PORTC=0X00;
    PORTD=0X00;
    while(1)
    {
        if((RC0==1)&&(RC7==0))
        {
            RD0=1;
        }
        if((RC0==0)&&(RC7==1))
        {
            RD0=1;
        } 
        if(RC0==RC7)
        {
            RD0=0;
        }
    }
}


