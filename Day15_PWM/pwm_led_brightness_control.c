#include <reg51.h>
sbit LED = P1^0;
#define PERIOD 100
void delay_us(unsigned int t)
{
    unsigned int i;
    for (i = 0; i < t; i++);
}
void PWM_LED(unsigned char duty,unsigned int repeat)
{
    unsigned int i;
    for (i = 0; i < repeat; i++)
    {
        LED = 1;
        delay_us(duty);
        LED = 0;
        delay_us(PERIOD-duty);
    }
}
void main(void)
{
    unsigned char brightness;
    LED = 0;
    while (1)
    {
        for(brightness=0;brightness<=100;brightness+=5)
        {
            PWM_LED(brightness,30);
        }
        for (brightness= 100;brightness>0;brightness-=5)
        {
            PWM_LED(brightness,30);
        }
    }
}