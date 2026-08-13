#include <reg51.h>
void delay()
{
    unsigned int i,j;
    for(i = 0; i <200; i++)
    {
			for(j=0;j<1000;j++);
    }
}
void main()
{
    while(1)
    {
        P1 =0xAA;    
        delay();
        P1 =0x55;    
        delay();
    }
}