#include <reg51.h>
sbit PWM_PIN = P1^0;
void delay_us(unsigned int t)
{
    unsigned int i;
    for (i = 0; i < t; i++);
}
void main(void)
{
    PWM_PIN = 0;
    while (1)
    {
        PWM_PIN = 1;      
        delay_us(100);
        PWM_PIN = 0;      
        delay_us(100);
    }
}