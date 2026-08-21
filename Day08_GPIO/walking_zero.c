#include <reg51.h>
void delay()
{
    unsigned int i,j;
    for(i=0;i<300;i++)
        for(j=0;j<1275;j++);
}
void main()
{
    unsigned char i;
    while(1)
    {
        for(i=0;i<8;i++)
        {
            P2 = ~(1<<i);
            delay();
        }
    }
}