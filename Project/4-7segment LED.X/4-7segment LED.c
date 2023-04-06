/*
 * File:   4-7segment LED.c
 * Author: Prathap
 *
 * Created on March 8, 2023, 2:54 PM
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
    PORTA=0x00;
    PORTB=0x00;
    PORTC=0x00;
    PORTD=0x00;
    PORTE=0x00;
    char ca[ ]={ 0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90 };
    char cc[ ]={ 0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67 };
    int i,j,k,l;
    while(1)
    {
        for (i=0;i<=9;i++)
        {
            for (j=0;j<=9;j++)
            {
                for (k=0;k<=9;k++)
                {
                    for (l=0;l<=9;l++)
                    {
                      RB3=0;RB2=0;RB1=0;RB0=1;
                      PORTA=ca[i];
                      RD1=1;RD2=1;RD3=1;RD0=0;
                      PORTC=cc[i];
                      __delay_ms(100);
                      RB3=0;RB2=0;RB0=0;RB1=1;
                      PORTA=ca[j];
                      RD0=1;RD2=1;RD3=1;RD1=0;
                      PORTC=cc[j];
                      __delay_ms(100);
                      RB3=0;RB1=0;RB0=0;RB2=1;
                      PORTA=ca[k];
                      RD0=1;RD1=1;RD3=1;RD2=0;
                      PORTC=cc[k];
                      __delay_ms(100);
                      RB0=0;RB1=0;RB2=0;RB3=1;
                      PORTA=ca[l];
                      RD0=1;RD1=1;RD2=1;RD3=0;
                      PORTC=cc[l];
                      __delay_ms(100);
                    }
                }
            }
        } 
    }
}