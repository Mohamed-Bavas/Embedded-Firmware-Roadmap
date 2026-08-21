#include <reg51.h>
void delay()
{
    unsigned int i,j;
    for(i=0;i<300;i++)
        for(j=0;j<1275;j++);
}
void main()
{
    unsigned char pattern=0;
    while(1)
    {
        pattern = (pattern<<1)|1;
        P2 = pattern;
        delay();
        if(pattern==0xFF)
            pattern=0;
    }
}