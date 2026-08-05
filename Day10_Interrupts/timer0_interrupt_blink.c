#include <reg51.h>
sbit LED = P2^0;
void Timer0_ISR(void) interrupt 1
{
    TH0 = 0x3C;
    TL0 = 0xB0;

    LED = !LED;
}
void main()
{   
    TMOD = 0x01;

    TH0 = 0xFC;
    TL0 = 0x67;

    ET0 = 1;
    EA = 1;

    TR0 = 1;

    while(1);
}