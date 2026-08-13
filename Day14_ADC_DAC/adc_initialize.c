#include <reg51.h>
sbit ALE   = P2^0;
sbit START = P2^1;
sbit EOC   = P2^2;
sbit OE    = P2^3;
void ADC_Init(void)
{
    P0 = 0xFF;    
    ALE = 0;
    START = 0;
    OE = 0;
    EOC = 1;        
}
void main(void)
{
    ADC_Init();
    while (1)
    {
    }
}
