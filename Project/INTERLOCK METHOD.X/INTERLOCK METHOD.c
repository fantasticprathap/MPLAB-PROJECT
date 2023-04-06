/*
 * File:   INTERLOCK METHOD.c
 * Author: Prathap
 *
 * Created on March 15, 2023, 1:58 PM
 */


#include <xc.h>
#define _XTAL_FREQ 400000
void main()
{
    TRISC=0x13;
    PORTC=0X00;
    while(1)
    {
        if((RC4==0)&&((RC0==1)||(RC1==1)))
        {
            if((RC0==1)&&(RC4==0)&&(RC7==0))
            {
                RC6=1;
            }
            else if((RC1==1)&&(RC4==0)&&(RC6==0))
            {
                RC7=1;
            }
        }
            if(RC4==1)
            {
                RC7=0;
                RC6=0;
            }
    }
}