/*
 * File:   NAME DISPALY USING POINTER.c
 * Author: Prathap
 *
 * Created on March 11, 2023, 10:30 AM
 */

#include<pic.h>
#define _XTAL_FREQ 400000
void lcd(int);
void display(char*);
void pulse();
void main()
{
    TRISC=0X00;
    TRISD=0X00;
    PORTC=0X00;
    PORTD=0X00;
    lcd(0x38);
    lcd(0x0e);
    while(1)
    {
        int i=0;
        for (i=0;i<=15;i++)
        {
            lcd(0x80+i);
            display("prathap");
            lcd(0xcf-i);
            display("leo");
            lcd(0x01);
        }        
    }
}
void pulse()
{
    RC2=1;
    __delay_ms(500);
    RC2=0;
    __delay_ms(500);
}
void lcd(int a)
{
    RC0=0;
    RC1=0;
    PORTD=a;
    pulse();
}
void display(char *p)
{
    RC1=0;
    RC0=1;
    for ( ;*p!='\0';p++)
    { 
       PORTD=*p;
       pulse();
    }
}
