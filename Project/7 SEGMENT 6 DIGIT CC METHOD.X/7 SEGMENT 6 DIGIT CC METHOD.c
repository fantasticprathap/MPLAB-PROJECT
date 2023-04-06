/*
 * File:   7 SEGMENT 6 DIGIT CC METHOD.c
 * Author: Prathap
 *
 * Created on March 29, 2023, 10:40 AM
 */

#include<pic.h>
#define _XTAL_FREQ 4000000
void timer();
int count,count2=0;
int cc[ ]={ 0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67 };
void seg(int c,int s)
{
    int x,y,z,m,n,o;
    x=c/100;
    y=(c%100)/10;
    z=c%10;
    m=s/100;
    n=(s%100)/10;
    o=s%10;
    RD3=1;RD4=1;RD5=1;RD6=1;RD7=1;RD2=0;
    PORTC=cc[m];
    __delay_ms(10);
    RD2=1;RD4=1;RD5=1;RD6=1;RD7=1;RD3=0;
    PORTC=cc[n];
    __delay_ms(10);
    RD3=1;RD2=1;RD5=1;RD6=1;RD7=1;RD4=0;
    PORTC=cc[o];
    __delay_ms(10);
    RD3=1;RD4=1;RD2=1;RD6=1;RD7=1;RD5=0;
    PORTC=cc[x];
    __delay_ms(10);
    RD3=1;RD4=1;RD5=1;RD2=1;RD7=1;RD6=0;
    PORTC=cc[y];
    __delay_ms(10);
    RD3=1;RD4=1;RD5=1;RD6=1;RD2=1;RD7=0;
    PORTC=cc[z];
    __delay_ms(10);
}
void main()
{
    TRISA=0X00;
    PORTA=0X00;
    TRISC=0X00;
    PORTC=0X00;
    TRISD=0X00;
    PORTD=0X00;
    TMR2=156;
    T2CON=0X27;
    ANSEL=0X00;
    while(1)
    {
        timer();
    }
}
void timer()
{
    
    int cnt1;
        if (TMR2IF==1)
        {
            
            cnt1++;
            TMR2IF=0;
            TMR2=156;
            RA1=1;
        }
        if(cnt1==125)
        {
            count++;
            cnt1=0;
            RA0=1;
        }
//        if (count2==60)
//        {
//            count2=0;
//            ct2++;
//            RA2=1;
//        }  
    seg(cnt1,count);
}
