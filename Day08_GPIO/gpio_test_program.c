#include <reg51.h>

sbit SW = P1^0;
sbit LED = P2^0;

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
        if(SW==0)
        {
            LED=1;
            P2=0xFF;
        }
        else
        {
            LED=0;
            P2=0x00;
        }

        delay();
    }
}