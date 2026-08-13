#include <reg51.h>
sbit ALE   = P2^0;
sbit START = P2^1;
sbit EOC   = P2^2;
sbit OE    = P2^3;
void delay(unsigned int t)
{
    unsigned int i, j;
    for (i = 0; i < t; i++)
        for (j = 0; j < 120; j++);
}
unsigned char ADC_Read(void)
{
    unsigned char value;
    P0 = 0xFF;
    ALE = 1;
    START = 1;
    delay(1);
    ALE = 0;
    START = 0;
    while (EOC == 0);
    OE = 1;
    delay(1);
    value = P0;
    OE = 0;
    return value;
}
void main(void)
{
    unsigned char pot_value;
    P0 = 0xFF;
    P1 = 0x00;
    ALE = 0;
    START = 0;
    OE = 0;
    while (1)
    {
        pot_value = ADC_Read();
        P1 = pot_value; 
        delay(100);
    }
}