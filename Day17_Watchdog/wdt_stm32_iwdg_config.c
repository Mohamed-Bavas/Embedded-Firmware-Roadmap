#include <reg51.h>
volatile unsigned char iwdg_style_overflow_count;
#define IWDG_STYLE_TIMEOUT_OVERFLOWS   40   
sbit LED_FAULT = P1^1;
void IWDG_Style_Init(void)
{
    TMOD &= 0x0F;        
    TMOD |= 0x10;         
    TH1 = 0x3C;           
    TL1 = 0xB0;
    iwdg_style_overflow_count = 0;
    ET1 = 1;               
    EA  = 1;
    TR1 = 1;                
}
void IWDG_Style_Refresh(void)
{
    iwdg_style_overflow_count = 0;   
}
void main(void)
{
    IWDG_Style_Init();
    LED_FAULT = 0;
    while (1)
    {
        IWDG_Style_Refresh();   
    }
}
void Timer1_ISR(void) interrupt 3
{
    TH1 = 0x3C;
    TL1 = 0xB0;
    iwdg_style_overflow_count++;
    if (iwdg_style_overflow_count >= IWDG_STYLE_TIMEOUT_OVERFLOWS)
    {
        LED_FAULT = 1;
        ((void (*)(void))0x0000)();
    }
}