#include <reg51.h>
sbit ALE      = P2^0;
sbit START    = P2^1;
sbit EOC      = P2^2;
sbit OE       = P2^3;
sbit ALERT    = P3^1;
#define THRESHOLD_VALUE 200 
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
    unsigned char sensor_value;
    P0 = 0xFF;
    ALE = 0;
    START = 0;
    OE = 0;
    ALERT = 0;
    while (1)
    {
        sensor_value = ADC_Read();

        if (sensor_value > THRESHOLD_VALUE)
        {
            ALERT = 1; 
        }
        else
        {
            ALERT = 0;   
        delay(150);
    }
}
		}