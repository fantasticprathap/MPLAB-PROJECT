/*
 * File:   TIMER 1 AND TIMER 2.c
 * Author: Prathap
 *
 * Created on March 28, 2023, 6:36 PM
 */

#include<pic.h>
#define _XTAL_FREQ 4000000
#define RS  RC5
#define RW  RC6
#define E   RC7
void pulse();
void LCD(int,int);
void display(int);
void display1();
void timer1();
int ct=0;
int cc[ ]={ 0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67 };
int count1,count2=0;
void seg(int c,int s)
{
    int x,y,z,a,b,d;
    x=c/100;
    y=(c%100)/10;
    z=c%10;
    a=s/100;
    b=(s%100)/10;
    d=s%10;
    RA3=1;RA4=1;RA5=1;RA6=1;RA7=1;RA2=0;
    PORTB=cc[x];
    __delay_ms(10);
    RA2=1;RA4=1;RA5=1;RA6=1;RA7=1;RA3=0;
    PORTB=cc[y];
    __delay_ms(10);
    RA3=1;RA2=1;RA5=1;RA6=1;RA7=1;RA4=0;
    PORTB=cc[z];
    __delay_ms(10);
    RA3=1;RA4=1;RA2=1;RA6=1;RA7=1;RA5=0;
    PORTB=cc[a];
    __delay_ms(10);
    RA3=1;RA4=1;RA5=1;RA2=1;RA7=1;RA6=0;
    PORTB=cc[b];
    __delay_ms(10);
    RA3=1;RA4=1;RA5=1;RA6=1;RA2=1;RA7=0;
    PORTB=cc[d];
    __delay_ms(10);
}
void main()
{
    TRISC=0X00;
    PORTC=0X00;
    TRISD=0X00;
    PORTD=0X00;
    TRISA=0X00;
    PORTA=0X00;
    TRISB=0X00;
    PORTB=0X00;
    ANSEL=0X00;
    ANSELH=0X00;
    TMR1=55536;
    T1CON=0X11;
    TMR2=156;
    T2CON=0X27;
    LCD(0X02,0);
    LCD(0X28,0);
    LCD(0X0E,0);
    while(1)
    {
        timer1();
    }
}
void pulse()
{
    E=1;
    __delay_ms(0);
    E=0;
    __delay_ms(0);
}
void LCD(int g,int h)
{
    RS=h;
    RW=0;                                                       
    PORTD=(g&0xf0)>>4;
    pulse();
    PORTD=(g&0x0f);
    pulse();
}
void timer1( )
{
    int cnt,cnt1=0;
    while(1)
    {
        if(TMR1IF==1)
        {
            cnt++;
            LCD(0x80,0);
            display(cnt);        
            TMR1IF=0;
            TMR1=55536;
        }
        if(cnt==50)
        {
            LCD(0x87,0);
            count1++;
            display(count1);
            cnt=0;
        }
        if (count1==60)
            {
                
                ct++;
                LCD(0xc4,0);
                display(ct);
                count2=0;
            }
        if(ct==60)
        {
            ct=0;
        }
        if (TMR2IF==1)
        {
            cnt1++;
            TMR2IF=0;
            TMR2=156;
            RD4=1;
        }
        if(cnt1==125)
        {
            RD4=0;
            count2++;
            cnt1=0;   
        }
        seg(cnt1,count2);
    }
}
void display(int k)
{
    int a,b,c;
    a=k/100;
    b=(k%100)/10;
    c=k%10;
    LCD(0x30+a,1);
    LCD(0x30+b,1);
    LCD(0x30+c,1);
}



