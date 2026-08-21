#include <reg51.h>
sbit LED = P2^0;
void delay()
{
    TMOD = 0x01;
    TH0 = 0x3C;
    TL0 = 0xB0;
    TR0 = 1;
    while(TF0 == 0);
    TR0 = 0;
    TF0 = 0;
}
void main()
{
    while(1)
    {
        LED = ~LED;
        delay();
    }
}