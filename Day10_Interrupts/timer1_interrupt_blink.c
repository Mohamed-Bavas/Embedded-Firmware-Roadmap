#include <reg51.h>
sbit LED = P2^0;
void Timer1_ISR(void) interrupt 3
{
    TH0 = 0x3C;
    TL0 = 0xB0;

    LED = !LED;
}
void main()
{   
    TMOD = 0x10;
    TH1 = 0xFC;
    TL1 = 0x67;
    ET1 = 1;
    EA = 1;
    TR1 = 1;
    while(1);
}