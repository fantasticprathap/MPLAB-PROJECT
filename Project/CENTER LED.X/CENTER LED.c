/*
 * File:   CENTER LED.c
 * Author: Prathap
 *
 * Created on March 7, 2023, 11:37 AM
 */

#include<pic.h>
#define _XTAL_FREQ 400000

void main()
{
    TRISA=0x00;
    PORTA=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    int i,j;
    while(1)
    {
        for(i=3,j=4;i<=0,j<=7;i--,j++)
        {
            PORTA|=1<<i;
            PORTA|=1<<j;
            __delay_ms(4000);
        }
     //   __delay_ms(4000);
        for (i,j;i<=3,j>=4;i++,j--)
        {
            PORTA&=(~(1<<i));
            PORTA&=(~(1<<j));
            __delay_ms(4000);
        }
    }
}