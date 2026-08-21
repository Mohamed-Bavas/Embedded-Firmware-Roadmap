#include <reg51.h>
void delay()
{
    unsigned int i,j;
    for(i=0;i<300;i++)
        for(j=0;j<1275;j++);
}
void main()
{
    while(1)
    {
        P0 = 0x55;
        delay();
        P1 = 0xAA;
        delay();
        P2 = 0x0F;
        delay();
        P3 = 0xF0;
        delay();
    }
}