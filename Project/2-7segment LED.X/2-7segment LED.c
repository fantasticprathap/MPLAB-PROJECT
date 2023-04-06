/*
 * File:   2-7segment LED.c
 * Author: Prathap
 *
 * Created on March 8, 2023, 11:41 AM
 */


#include<pic.h>
#define _XTAL_FREQ 400000

void main()
{
    TRISA=0x00;
    TRISB=0x00;
    TRISC=0x00;
    PORTA=0x00;
    PORTB=0x00;
    PORTC=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    int ca[ ]={ 0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90 };
    int cc[ ]={ 0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67 };
    int i,j,k,l;
    while(1)
    {
        for (i=0;i<=9;i++)
        {
            for(j=0;j<=9;j++)
            {
                RB0=0;RB1=1; 
                PORTA=ca[i];
                RB2=1;RB3=0; 
                PORTC=cc[i];
                __delay_ms(500);
                RB1=0;RB0=1;
                PORTA=ca[j];
                RB3=1;RB2=0;
                PORTC=cc[j];
                __delay_ms(500);
            }
        }
    }
}