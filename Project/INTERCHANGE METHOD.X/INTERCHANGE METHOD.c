/*
 * File:   INTERCHANGE METHOD.c
 * Author: Prathap
 *
 * Created on March 20, 2023, 10:34 AM
 */
#include<pic.h>
#define _XTAL_FREQ 400000
#define first_button RC0
#define second_button RC1
#define third_button RC2
int a=1;
int b=0;
void display(int);
void swap();
void main()
{
    TRISC=0X07;
    PORTC=0X00;
    while(1)
    {
        if(first_button==1)
        {
            display(a);
        }
        if(second_button==1)
        {
            display(b);
        }
        if(third_button==1)
        {
            swap();
            while(third_button==1);
        }
    }
}
void display(int a)
{
    RC7=a;
}
void swap()
{
    int x;
    x=a;
    a=b;
    b=x;
}