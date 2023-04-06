/*
 * File:   flag using count LED.c
 * Author: Prathap
 *
 * Created on March 15, 2023, 11:54 AM
 */
#include<pic.h>
#define _XTAL_FREQ 400000
void main()
{
    TRISA=0X01;
    TRISC=0X0F;
    TRISD=0X00;
    PORTA=0X00;
    PORTC=0X00;
    PORTD=0X00;
    ANSEL=0X00;
    ANSELH=0X00;
    int flag,count=0;
    while(1)
    {
        if (((RC0==1)||(RC1==1)||(RC2==1)||(RC3==1))&&(flag==0)&&(RA0==0))
        {
            flag=1;
        }
        if (flag==1)
        {
            count++;
            flag++;
        }
        if ((RC0==0)&&(RC1==0)&&(RC2==0)&&(RC3==0))
        {
            flag=0;
        }
        int i;
        for (i=0;i<count;i++)
        {
           PORTD|=1<<i; 
        } 
        if(RA0==1)
        {
            count=0;
            __delay_ms(5000);  
            PORTD=0X00;
            __delay_ms(5000);  
        }
    }
}