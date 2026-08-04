#include <reg51.h>

void main()
{
    TMOD = 0x01;

    TH0 = 0;
    TL0 = 0;

    TR0 = 1;

    while(TF0 == 0);

    P2 = 0xFF;

    TR0 = 0;
}