#include <reg51.h>
volatile unsigned char wwdg_style_overflow_count;
#define WWDG_WINDOW_MIN   10   
#define WWDG_WINDOW_MAX   20   
sbit LED_FAULT = P1^1;
void WWDG_Style_Init(void)
{
    TMOD &= 0xF0;
    TMOD |= 0x01;  
    TH0 = 0x3C;
    TL0 = 0xB0;
    wwdg_style_overflow_count = 0;
    ET0 = 1;
    EA  = 1;
    TR0 = 1;
}
bit WWDG_Style_Refresh(void)
{
    if (wwdg_style_overflow_count < WWDG_WINDOW_MIN)
    {
        LED_FAULT = 1;
        ((void (*)(void))0x0000)();
        return 0;
    }
    wwdg_style_overflow_count = 0;
    return 1;
}
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 120; j++);
}
void main(void)
{
    WWDG_Style_Init();
    LED_FAULT = 0;
    while (1)
    {
        delay_ms(700);  
        WWDG_Style_Refresh();
    }
}
void Timer0_ISR(void) interrupt 1
{
    TH0 = 0x3C;
    TL0 = 0xB0;
    wwdg_style_overflow_count++;
    if (wwdg_style_overflow_count >= WWDG_WINDOW_MAX)
    {
        LED_FAULT = 1;
        ((void (*)(void))0x0000)();
    }
}