#include <reg51.h>
void DAC_Init(void)
{
    P1 = 0x00;   
}

void DAC_Write(unsigned char value)
{
    P1 = value; 
}
void main(void)
{
    DAC_Init();

    while (1)
    {
    }
}