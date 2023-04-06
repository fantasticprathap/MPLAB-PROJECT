/*
 * File:   2 ADC.c
 * Author: Prathap
 *
 * Created on April 5, 2023, 2:10 PM
 */
#include<pic.h>
#define _XTAL_FREQ 4000000
#define RS RE0
#define E  RE1
void adc(int);
void pulse();
void LCD(int,int);
void display(int);
void voltage(int);
int high,low,DV=0;
void main()
{
    TRISA=0X03;
    PORTA=0X00;
    TRISD=0X00;
    PORTD=0X00;
    TRISE=0X00;
    PORTE=0X00;
    ANSEL=0X03;
    ANSELH=0X00;
    LCD(0X38,0);
    LCD(0X0E,0);
    
    while(1)
    {    
        adc(0x81);
        voltage(0xc0);
        adc(0x85);
        voltage(0xc8);
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
void adc (int y) 
{ 
LCD(y,0);
ADCON1=0x80;
ADCON0=y;
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
void voltage(int z)
{
    LCD(z,0);
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