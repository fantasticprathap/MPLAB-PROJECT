/*
 * File:   4 SEG AIRTHMATIC.c
 * Author: Prathap
 *
 * Created on March 17, 2023, 11:12 AM
 */
#include<pic.h>
#define _XTAL_FREQ 400000
#define first_button RA0
#define second_button RA1
int i,j,k,l,flag,flag1,count;
flag,flag1,count=0;
void first_seg();
void second_seg();
void display();
void display1(int);
int cc[ ]={ 0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67 };
void main()
{
    TRISA=0X03;
    PORTA=0X00;
    TRISC=0X00;
    PORTC=0X00;
    TRISD=0X00;
    PORTD=0X00;
    ANSEL=0X00;
    ANSELH=0X00;
    while(1)
    {
        if((first_button==1)&&(second_button==0)&&(flag==0))
        {
            flag=1;
        }
        if(flag==1)
        {
            count++;
            flag++;
            first_seg();
        }
        if((first_button==0)&&(second_button==0))
        {
            flag=0;
        }
    }
}
void first_seg()
{
    display();
}
void display()
{
    RD3=1;RD0=1;RD1=1;RD2=0;    
    PORTC=cc[j];                                                
    __delay_ms(500);
    RD2=1;RD0=1;RD1=1;RD3=0;
    PORTC=cc[k];
    __delay_ms(500);
}

