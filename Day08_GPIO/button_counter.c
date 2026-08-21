#include <reg51.h>
sbit SW = P1^0;
void delay()
{
    unsigned int i,j;
    for(i=0;i<10;i++)
        for(j=0;j<100;j++);
}
void main()
{
    unsigned char count = 0;
    P2 = 0x00;
    while(1)
    {
        if(SW == 0)
        {
           delay();
            if(SW == 0)
            {
                count++;
                P2 = count;
                while(SW == 0);   
                delay();
            }
        }
    }
}