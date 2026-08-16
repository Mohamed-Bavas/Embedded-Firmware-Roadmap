#include <reg51.h>
sbit SERVO = P1^0;
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
void Servo_SetPulse(unsigned int pulse_us)
{
    SERVO = 1;
    delay_us(pulse_us);      
    SERVO = 0;
    delay_us(20000 - pulse_us);  
}
void Servo_SetAngle(unsigned char angle, unsigned int repeat)
{
    unsigned int pulse_width;
    unsigned int i;
    pulse_width = 1000 + ((unsigned long)angle * 1000) / 180;
    for (i = 0; i < repeat; i++)
    {
        Servo_SetPulse(pulse_width);
    }
}
void main(void)
{
    SERVO = 0;
    while (1)
    {
        Servo_SetAngle(0, 50);
        Servo_SetAngle(90, 50);  
        Servo_SetAngle(180, 50); 
        Servo_SetAngle(90, 50);  
    }
}