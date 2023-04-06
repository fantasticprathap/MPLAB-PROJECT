/*
 * File:   9 button 8 led.c
 * Author: Prathap
 *
 * Created on March 14, 2023, 2:50 PM
 */
#include<xc.h>
#define _XTAL_FREQ 400000
void main()
{
    int count=0;
    TRISA=0X01;
    TRISC=0XFF;
    TRISD=0X00;
    PORTA=0X00;
    PORTC=0X00;
    PORTD=0X00;
    ANSEL=0X00;
    ANSELH=0X00;
    while(1)
    {
//        if((RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==1)&&(RA0==0))
//        {
//            RD0=1;
//        }
//        if((RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==2)&&(RA0==0))
//        {
//            RD1=1;
//        }
//        if((RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==3)&&(RA0==0))
//        {
//            RD2=1;
//        }
//        if((RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==4)&&(RA0==0))
//        {
//            RD3=1;
//        }
//        if((RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==5)&&(RA0==0))
//        {
//            RD4=1;
//        }
//        if((RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==6)&&(RA0==0))
//        {
//            RD5=1;
//        }
//        if((RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==7)&&(RA0==0))
//        {
//            RD6=1;
//        }
//        if((RC0+RC1+RC2+RC3+RC4+RC5+RC6+RC7==8)&&(RA0==0))
//        {
//            RD7=1;
//        }
//        if(RA0==1)
//        {
//            PORTD=0X00;
//        }
//}
//}
        
        
        
        if((RC0==1)||(RC1==1)||(RC2==1)||(RC3==1)||(RC4==1)||(RC5==1)||(RC6==1)||(RC7==1))
        {
            count++;
        }
        while((RC0==1)||(RC1==1)||(RC2==1)||(RC3==1)||(RC4==1)||(RC5==1)||(RC6==1)||(RC7==1));
        PORTD|=(1<<(count-1));
        if(RA0==1)
        {
            count=0;
            PORTD=0X00;
            while(RA0==1);
        }
    }
}