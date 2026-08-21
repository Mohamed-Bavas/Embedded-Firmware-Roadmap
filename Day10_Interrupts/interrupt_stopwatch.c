#include <reg51.h>
unsigned int count = 0;
void Timer0_ISR(void) interrupt 1
{
    TH0 = 0x3C;
    TL0 = 0xB0;
    count++;
    P2 = count;
}
void main()
{
    TMOD = 0x01;
    TH0 = 0x3C;
    TL0 = 0xB0;
    ET0 = 1;
    EA = 1;
    TR0 = 1;
    while(1);
}