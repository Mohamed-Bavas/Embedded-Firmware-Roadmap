#include <reg51.h>
sbit LED = P2^0;
void EX0_ISR(void) interrupt 0
{
    LED = !LED;
}
void main()
{
    LED = 0;
    IT0 = 1;
    EX0 = 1;
    EA = 1;
    while(1);
}