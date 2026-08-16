#include <reg51.h>
sbit MOTOR_PWM = P1^0;
sbit MOTOR_DIR = P1^1;
#define PERIOD 100
void delay_us(unsigned int t)
{
    unsigned int i;
    for (i = 0; i < t; i++);
}
void Motor_SetSpeed(unsigned char speed_percent, unsigned int cycles)
{
    unsigned int i;

    for (i = 0; i < cycles; i++)
    {
        MOTOR_PWM = 1;
        delay_us(speed_percent);
        MOTOR_PWM = 0;
        delay_us(PERIOD - speed_percent);
    }
}
void main(void)
{
    MOTOR_PWM = 0;
    MOTOR_DIR = 1;  
    while (1)
    {
        Motor_SetSpeed(30, 100);   
        Motor_SetSpeed(60, 100);   
        Motor_SetSpeed(100, 100);  
        Motor_SetSpeed(60, 100);   
        Motor_SetSpeed(30, 100);   
    }
}