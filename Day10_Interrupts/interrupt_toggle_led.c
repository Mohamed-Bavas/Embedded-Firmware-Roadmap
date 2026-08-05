#include <reg51.h>

sbit LED = P2^7;

void Timer0_ISR(void) interrupt 1
{
    TH0 = 0;
    TL0 = 0;

    LED = !LED;
}

void main()
{
    TMOD = 0x01;

    ET0 = 1;
    EA = 1;

    TR0 = 1;

    while(1);
}