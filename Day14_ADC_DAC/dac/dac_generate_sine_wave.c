#include <reg51.h>
unsigned char code sine_table[36] = {
    127, 149, 170, 190, 208, 223, 235, 244, 250, 253,
    253, 250, 244, 235, 223, 208, 190, 170, 149, 127,
    105, 84,  64,  46,  31,  19,  10,  4,   1,   1,
    4,   10,  19,  31,  46,  64
};
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
    unsigned char i;
    P1 = 0x00;
    while (1)
    {
        for (i = 0; i < 36; i++)
        {
            DAC_Write(sine_table[i]);
            delay(20);  
        }
    }
}