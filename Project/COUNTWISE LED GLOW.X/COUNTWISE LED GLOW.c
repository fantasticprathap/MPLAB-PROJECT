/*
 * File:   COUNTWISE LED GLOW.c
 * Author: Prathap
 *
 * Created on March 14, 2023, 12:09 PM
 */

#include<pic.h>
#define _XTAL_FREQ 400000
void main()
{
    TRISC=0x03;
    PORTC=0X00;
    int i,j;
    i=0;
    j=0;
    while(1)
    {
        if(RC0==1)
        {     
               i++;
               while(RC0==1);                 //key bouncing
        }
        if((RC1==1)&&(RC0==0))
        {
            for(j=0;j<i;j++)
            {
                RC7=1;
                __delay_ms(2000);
                RC7=0;
                __delay_ms(2000);
            } 
            i=0;
        }
    }
}