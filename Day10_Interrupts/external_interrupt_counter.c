#include <reg51.h>
unsigned char count = 0;
void EX0_ISR(void) interrupt 0
{
    count++;
    P2 = count;
}
void main()
{
    P2 = 0;
    IT0 = 1;
    EX0 = 1;
    EA = 1;
    while(1);
}