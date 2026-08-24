#include <reg51.h>
volatile bit wdt_fed_flag;
volatile unsigned char wdt_overflow_count;
#define WDT_OVERFLOW_LIMIT 20
sbit LED_HEARTBEAT = P1^0;  
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
void WDT_Feed(void)
{
    wdt_overflow_count = 0;  
}
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 120; j++);   
}
void main(void)
{
    WDT_Init();
    while (1)
    {
        LED_HEARTBEAT = !LED_HEARTBEAT;   
        delay_ms(200);
        WDT_Feed();   
    }
}
void Timer0_ISR(void) interrupt 1
{
    TH0 = 0x3C;   
    TL0 = 0xB0;
    wdt_overflow_count++;
    if (wdt_overflow_count >= WDT_OVERFLOW_LIMIT)
    {
        ((void (*)(void))0x0000)();
    }
}