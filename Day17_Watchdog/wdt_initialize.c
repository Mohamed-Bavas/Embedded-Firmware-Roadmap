#include <reg51.h>
volatile bit wdt_fed_flag;
#define WDT_OVERFLOW_LIMIT   20
unsigned char wdt_overflow_count;
void WDT_Init(void)
{
    TMOD &= 0xF0;        
    TMOD |= 0x01;      
    TH0 = 0x3C;           
    TL0 = 0xB0;
    wdt_overflow_count = 0;
    wdt_fed_flag = 0;
    ET0 = 1;            
    EA  = 1;            
    TR0 = 1;             
}
void main(void)
{
    WDT_Init();
    while (1)
    {
    }
}