/*
 * File:   7 SEGMENT.c
 * Author: Prathap
 *
 * Created on March 8, 2023, 10:28 AM
 */
#include<pic.h>
#define _XTAL_FREQ 400000
void main()
{
    TRISA=0x00;
    PORTA=0x00;
    TRISB=0x00;
    PORTB=0X00;
    ANSEL=0x00;
    ANSELH=0x00;
    int ca[ ]={ 0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90 };
    int cc[ ]={ 0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X67 };
    int i;
    while(1)
    {
        for (i=0;i<=9;i++)
        {
            PORTA=ca[i];
            PORTB=cc[i];
            __delay_ms(4000);
        }
    }
}