#include <reg51.h>
sbit FAULT_TRIGGER = P3^2;   
sbit LED_HANG_INDICATOR = P1^2;
volatile unsigned char wdt_overflow_count;
volatile bit fault_triggered;
#define WDT_OVERFLOW_LIMIT 20
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
    IT0 = 1;   
    EX0 = 1;    
}
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 120; j++);
}
void Run_Normal_Operation(void)
{
    static unsigned char pattern = 0x01;
    P2 = pattern;                
    pattern = (pattern << 1) | (pattern >> 7);
    delay_ms(200);
    wdt_overflow_count = 0;       
}
void main(void)
{
    WDT_Init();
    LED_HANG_INDICATOR = 0;
    while (1)
    {
        if (fault_triggered)
        {
            LED_HANG_INDICATOR = 1;
            while (1)
            {
            }
        }

        Run_Normal_Operation();
    }
}
void INT0_ISR(void) interrupt 0
{
    fault_triggered = 1;
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