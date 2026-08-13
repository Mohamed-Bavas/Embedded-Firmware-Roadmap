#include <reg51.h>
void delay(unsigned int t)
{
    unsigned int i;
    for (i = 0; i < t; i++);
}
void DAC_Write(unsigned char value)
{
    P1 = value;
}
void main(void)
{
    unsigned int i;
    P1 = 0x00;
    while (1)
    {
        for (i = 0; i <= 255; i++)
        {
            DAC_Write((unsigned char)i);
            delay(10);      
        }
    }
}