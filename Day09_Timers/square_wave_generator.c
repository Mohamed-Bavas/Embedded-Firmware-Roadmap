#include <reg51.h>
sbit OUT = P1^0;
void delay()
{
    TMOD = 0x01;
    TH0 = 0xFF;
    TL0 = 0x18;
    TR0 = 1;
    while(TF0 == 0);
    TR0 = 0;
    TF0 = 0;
}
void main()
{
    while(1)
    {
        OUT = ~OUT;
        delay();
    }
}