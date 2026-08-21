#include <reg51.h>
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
        P2 = 0xAA;
        delay();
        P2 = 0x55;
        delay();
    }
}