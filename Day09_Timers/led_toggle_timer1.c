#include <reg51.h>

sbit LED = P2^1;

void delay()
{
    TMOD = 0x10;

    TH1 = 0x3C;
    TL1 = 0xB0;

    TR1 = 1;

    while(TF1 == 0);

    TR1 = 0;
    TF1 = 0;
}

void main()
{
    while(1)
    {
        LED = !LED;
        delay();
    }
}