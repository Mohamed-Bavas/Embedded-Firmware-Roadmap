#include <reg51.h>
sbit ALE   = P2^0;
sbit START = P2^1;
sbit EOC   = P2^2;
sbit OE    = P2^3;
sbit PWM_PIN = P1^0;
void delay_us(unsigned int t)
{
    unsigned int i;
    for (i = 0; i < t; i++);
}
unsigned char ADC_Read(void)
{
    unsigned char value;
    P0 = 0xFF;
    ALE = 1;
    START = 1;
    delay_us(10);
    ALE = 0;
    START = 0;
    while (EOC == 0);
    OE = 1;
    delay_us(10);
    value = P0;
    OE = 0;
    return value;
}
void PWM_Output(unsigned char duty, unsigned int cycles)
{
    unsigned int i;
    for (i = 0; i < cycles; i++)
    {
        if (duty > 0)
        {
            PWM_PIN = 1;
            delay_us(duty);
        }
        PWM_PIN = 0;
        delay_us(100 - duty);
    }
}
void main(void)
{
    unsigned char adc_value;
    unsigned char duty_cycle;
    P0 = 0xFF;
    ALE = 0;
    START = 0;
    OE = 0;
    PWM_PIN = 0;
    while (1)
    {
        adc_value = ADC_Read();     
        duty_cycle = (unsigned char)((unsigned int)adc_value * 100 / 255);
        PWM_Output(duty_cycle, 20); 
    }
}