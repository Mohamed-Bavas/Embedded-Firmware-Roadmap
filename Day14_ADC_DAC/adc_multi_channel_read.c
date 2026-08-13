#include <reg51.h>
sbit ALE   = P2^0;
sbit START = P2^1;
sbit EOC   = P2^2;
sbit OE    = P2^3;
sbit ADD_A = P2^4;
sbit ADD_B = P2^5;
sbit ADD_C = P2^6;
void delay(unsigned int t)
{
    unsigned int i, j;
    for (i = 0; i < t; i++)
        for (j = 0; j < 120; j++);
}
void Select_Channel(unsigned char ch)
{
    ADD_A = ch & 0x01;
    ADD_B = (ch >> 1) & 0x01;
    ADD_C = (ch >> 2) & 0x01;
}
unsigned char ADC_Read(unsigned char channel)
{
    unsigned char value;
    Select_Channel(channel);
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
    unsigned char ch0, ch1, ch2, ch3;
    P0 = 0xFF;
    ALE = 0;
    START = 0;
    OE = 0;
    while (1)
    {
        ch0 = ADC_Read(0);  
        delay(50);
        ch1 = ADC_Read(1);   
        delay(50);
        ch2 = ADC_Read(2);   
        delay(50);
        ch3 = ADC_Read(3);   
        delay(50);

    }
}