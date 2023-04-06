/*
 * File:   BUTTERFLY.c
 * Author: Prathap
 *
 * Created on March 7, 2023, 2:50 PM
 */

#include<pic.h>
#define _XTAL_FREQ 400000
void main()
{
    TRISA=0x00;
    TRISB=0x00;
    TRISC=0x00;
    TRISD=0x00;
    TRISE=0x00;
    PORTA=0X00;
    PORTB=0x00;
    PORTC=0x00;
    PORTD=0x00;
    PORTE=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    int i,j;
    while(1)
    {
        PORTE=0xFF;
        for (i=0;i<=7;i++)
        {
            PORTA|=1<<i;
            PORTC|=1<<i;
            __delay_ms(3000);
        }
        for(j=0;j<=7;j++)
        {
            PORTB|=1<<j;
            PORTD|=1<<j;
            __delay_ms(3000);
        }
        for (j;j>=0;j--)
        {
           PORTB&=~(1<<j);
           PORTD&=~(1<<j);
           __delay_ms(3000); 
        }
        for (i;i>=0;i--)
        {
            PORTA&=~(1<<i);
            PORTC&=~(1<<i);
            __delay_ms(3000);
        }
    }
}