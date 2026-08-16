#include <reg51.h>
sbit PWM_PIN = P1^0;
void PWM_Init(void)
{
    PWM_PIN = 0;   
}
void main(void)
{
    PWM_Init();

    while (1)
    {
    }
}