/*
 * File:   countwise forward and reverse.c
 * Author: Prathap
 *
 * Created on March 16, 2023, 11:42 AM
 */
#include<pic.h>
#define _XTAL_FREQ 400000
#define forward_button RC0
#define reverse_button RC1
int i,j;
int flag=0;
int cc[ ]={ 0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67 };
void display(int);
void forward(int,int);
void reverse(int,int);
void main()
{
    TRISC=0X03;
    TRISD=0X00;
    PORTC=0X00;
    PORTD=0X00;
    if ((forward_button==0)&&(reverse_button==0)&&(flag==0))
    {
        PORTD=0x00;
    }
    while(1)
    {
        if ((forward_button==1)&&(reverse_button==0)&&(flag==0))
        {
            forward(0,99);
        }
        if ((reverse_button==1)&&(forward_button==0)&&(flag==0))
        {
            reverse(99,0);
        }
        if (flag==1)
        {
            reverse(i,0);
            i=99;
        }
        if (flag==2)
        {
            forward(j,99);
            j=0;
        }
        if (flag==3)
        {
            display(i);
            flag=1;
        }
        if(flag==4)
        {
            display(j);
            flag=2;
        }
    }
}

void forward(int a,int b)
    {
            for (i=a;i<=b;i++)
            {
                display(i);
                if((reverse_button==1)&&(forward_button==1))
                {
                    flag=3;
                    break;
                }
                if((reverse_button==1)&&(forward_button==0))
                {
                    flag=1;
                    break;
                }
            }
    }

void reverse(int c,int d)
{
            for (j=c;j>=d;j--)
            {
                display(j);
                if((reverse_button==1)&&(forward_button==1))
                {
                    flag=4;
                    break;
                }
                if((forward_button==1)&&(reverse_button==0))
                {
                    flag=2;
                    break;
                }
            }
}

void display(int k)
{
        RC7=1;RC6=0;
        PORTD=cc[k/10];
        __delay_ms(500);
        RC6=1;RC7=0;
        PORTD=cc[k%10];
        __delay_ms(500);
}
