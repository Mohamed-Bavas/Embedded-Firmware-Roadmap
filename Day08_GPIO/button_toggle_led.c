#include <reg51.h>
sbit SW = P1^0;
sbit LED = P2^0;
void delay()
{
    unsigned int i,j;
    for(i=0;i<10;i++)
        for(j=0;j<100;j++);
}
void main()
{
    LED = 0;
    while(1)
    {
        if(SW==0)
        {
            delay();
            if(SW==0)
            {
                LED = !LED;
                while(SW==0);
            }
        }
    }
}