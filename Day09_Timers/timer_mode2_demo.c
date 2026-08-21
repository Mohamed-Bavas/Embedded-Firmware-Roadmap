#include <reg51.h>
void main()
{
    TMOD = 0x02;
    TH0 = 0x00;
    TL0 = 0x00;
    TR0 = 1;
    while(TF0 == 0);
    P2 = 0xFF;
    TR0 = 0;
}