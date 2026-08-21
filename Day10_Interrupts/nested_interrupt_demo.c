#include <reg51.h>
sbit LED1 = P2^0;
sbit LED2 = P2^1;
void EX0_ISR(void) interrupt 0
{
    LED1 = !LED1;
}
void Timer0_ISR(void) interrupt 1
{
    LED2 = !LED2;
}
void main()
{
    TMOD = 0x01;
    TH0 = 0;
    TL0 = 0;
    PX0 = 1;
    PT0 = 0;
    EX0 = 1;
    ET0 = 1;
    EA = 1;
    TR0 = 1;
    while(1);
}