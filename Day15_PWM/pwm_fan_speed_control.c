#include <reg51.h>
sbit FAN_PWM = P1^0;
sbit BTN_UP  = P3^0;
sbit BTN_DOWN = P3^1;
#define PERIOD 100
void delay_us(unsigned int t)
{
    unsigned int i;
    for (i = 0; i < t; i++);
}
void delay_ms(unsigned int t)
{
    unsigned int i;
    for (i = 0; i < t; i++)
        delay_us(1000);
}
void Fan_Run(unsigned char duty, unsigned int cycles)
{
    unsigned int i;

    for (i = 0; i < cycles; i++)
    {
        if (duty > 0)
        {
            FAN_PWM = 1;
            delay_us(duty);
        }
        FAN_PWM = 0;
        delay_us(PERIOD - duty);
    }
}
void main(void)
{
    unsigned char speed_level = 0;   
    unsigned char duty_values[4] = {0, 40, 70, 100};
    FAN_PWM = 0;
    BTN_UP = 1;
    BTN_DOWN = 1;
    while (1)
    {
        if (BTN_UP == 0)
        {
            delay_ms(20);
            if (BTN_UP == 0 && speed_level < 3)
            {
                speed_level++;
                while (BTN_UP == 0);   
            }
        }
        if (BTN_DOWN == 0)
        {
            delay_ms(20);
            if (BTN_DOWN == 0 && speed_level > 0)
            {
                speed_level--;
                while (BTN_DOWN == 0);
            }
        }
        Fan_Run(duty_values[speed_level], 5); 
    }
}