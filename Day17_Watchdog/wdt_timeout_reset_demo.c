#include <reg51.h>
volatile unsigned char wdt_overflow_count;
volatile unsigned char loop_counter;
#define WDT_OVERFLOW_LIMIT 20
sbit LED_FAULT   = P1^1;   
sbit RESET_DRIVE = P3^7;   
void WDT_Init(void)
{
    TMOD &= 0xF0;
    TMOD |= 0x01;
    TH0 = 0x3C;
    TL0 = 0xB0;
    wdt_overflow_count = 0;
    ET0 = 1;
    EA  = 1;
    TR0 = 1;
}
void Software_Reset(void)
{
    LED_FAULT = 1;              
    ((void (*)(void))0x0000)();
}
void main(void)
{
    WDT_Init();
    LED_FAULT = 0;
    loop_counter = 0;
    while (1)
    {
        loop_counter++;
        if (loop_counter < 5)
        {
            wdt_overflow_count = 0;   
        }
    }
}
void Timer0_ISR(void) interrupt 1
{
    TH0 = 0x3C;
    TL0 = 0xB0;
    wdt_overflow_count++;
    if (wdt_overflow_count >= WDT_OVERFLOW_LIMIT)
    {
        Software_Reset();
    }
}