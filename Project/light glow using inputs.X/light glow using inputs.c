/*
 * File:   light glow using inputs.c
 * Author: Prathap
 *
 * Created on March 14, 2023, 10:35 AM
 */
#include<pic.h>
#define _XTAL_FREQ 400000
#define green RC0
#define red   RC3
void main()
{
    TRISC=0X03;
    TRISD=0X00;
    PORTC=0X00;
    PORTD=0X00;
    while(1)
    {
        if(green==1&&red==0)
    {
        RD0=1;
    }
    if(red==1)
    {
        RD0=0;
    }
        if(green==red)
        {
            RD0=0;
        }
    }
}