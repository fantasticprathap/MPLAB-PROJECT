/*
 * File:   ADC USING LED AND MOTOR.c
 * Author: Prathap
 *
 * Created on April 5, 2023, 11:16 AM
 */

#include<pic.h>
#define _XTAL_FREQ 4000000
#define RS RE0
#define E  RE1
void adc();
void pulse();
void LCD(int,int);
void display(int);
void voltage();
int high,low,DV=0;
void main()
{
    TRISA=0X01;
    PORTA=0X00;
    TRISD=0X00;
    PORTD=0X00;
    TRISE=0X00;
    PORTE=0X00;
    ANSEL=0X00;
    ANSELH=0X00;
    ADCON1=0x80;
    LCD(0X38,0);
    LCD(0X0E,0);
    
    while(1)
    {    
        adc();
        voltage();
        if (DV<306)
        {
            RA1=0;
        }
        if ((DV>=307)&&(DV<=717))
        {
            RA1=1;
            __delay_ms(50);
            RA1=0;
            __delay_ms(50);
        }
        if ((DV<512)||(DV>=921))
        {
            RA2=0;
        }
        if ((DV>=512)&&(DV<921))
        {
            RA2=1;   
        }
        if (DV>921)
        {
            RA3=0;
        }
        if(DV>=921)
        {
            RA3=1;
        }
        if(DV>1020)
        {
            RA1=0;
            RA2=0;
            RA3=0;
        }
    }
}
void pulse()
{
    E=1;
    __delay_us(50);
    E=0;
    __delay_us(50);
}
void LCD(int g,int h)
{
    RS=h;
    PORTD=g;
    pulse();
}
void display(int k)
{
    int a,b,c,d;
    a=k/1000;
    b=(k%1000)/100;
    c=(k%100)/10;
    d=k%10;        
    LCD(0x30+a,1);
    LCD(0x30+b,1);
    LCD(0x30+c,1);
    LCD(0x30+d,1);
}
void adc () 
{ 
LCD(0X80,0);
ADCON0=0X81;
GO=1; 
while(GO); 
high=ADRESH; 
low=ADRESL;
if(high==0) 
{ 
DV=low; 
display(DV);
} 
if(high==1) 
{
 DV=low+256; 
 display(DV);
} 
if(high==2) 
{ 
DV=low+512; 
display(DV);
} 
if( high==3) 
{
 DV=low+768;
 display(DV);
}
} 
void voltage()
{
    LCD(0Xc0,0);
    int a,b,c,d;
    float x;
    x=(DV*5.0)/1023.0;
    d=x*100;
    a=d/100;
    b=(d%100)/10;
    c=d%10;
    LCD(0x30+a,1);
    LCD(0x2e,1);
    LCD(0x30+b,1);
    LCD(0x30+c,1);
    LCD(0x20,1);
    LCD(0x56,1);
}