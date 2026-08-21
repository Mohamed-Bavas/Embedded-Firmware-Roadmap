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
        P2 = 0x00;
        delay();
        P2 = 0xFF;
        delay();
        P2 = 0xAA;
        delay();
        P2 = 0x55;
        delay();
    }
}