#include <reg51.h>
#include <absacc.h>   
#define RESET_MARKER_ADDR   0x0000       
#define MARKER_WATCHDOG      0xA5
#define MARKER_NONE          0x00
sbit LED_FAULT_INDICATOR = P1^1;
volatile unsigned char wdt_overflow_count;
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
}
void Check_Reset_Cause(void)
{
    unsigned char cause = XBYTE[RESET_MARKER_ADDR];
    if (cause == MARKER_WATCHDOG)
    {
        LED_FAULT_INDICATOR = 1;
    }
    else
    {
        LED_FAULT_INDICATOR = 0;   
    }
    XBYTE[RESET_MARKER_ADDR] = MARKER_NONE;
}
void main(void)
{
    Check_Reset_Cause();   
    WDT_Init();
    while (1)
    {
    }
}
void Timer0_ISR(void) interrupt 1
{
    TH0 = 0x3C;
    TL0 = 0xB0;
    wdt_overflow_count++;
    if (wdt_overflow_count >= WDT_OVERFLOW_LIMIT)
    {
        XBYTE[RESET_MARKER_ADDR] = MARKER_WATCHDOG;   
        ((void (*)(void))0x0000)();
    }
}