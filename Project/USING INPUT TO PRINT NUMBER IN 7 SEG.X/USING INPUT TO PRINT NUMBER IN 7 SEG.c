/*
 * File:   USING INPUT TO PRINT NUMBER IN 7 SEG.c
 * Author: Prathap
 *
 * Created on March 15, 2023, 7:13 PM
 */
#include<pic.h>
#define _XTAL_FREQ 400000
void main()
{
    TRISC=0X03;
    TRISD=0X00;
    PORTC=0X00;
    PORTD=0X00;
    int cc[ ]={ 0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X67 };
    int count=0;
    int flag,i=0;
    while(1)
    {
        if ((RC0==1)&&(RC1==0)&&(flag==0))
        {
            flag=1;
        }
        if (flag==1)
        {
            count++;
            flag++;
        }
        if ((RC0==0)&&(RC1==0))
        {
            flag=0;
        }
        if((count<11)&&(count>0))
        {
            PORTD|=cc[count-1];
            __delay_ms(2000);
        }
        if(count>=11)
        {
            __delay_ms(2000);
            count=1;
        }
        if(RC1==1)
        {
            count=0;
            PORTD=0X00;
        }
    }
}