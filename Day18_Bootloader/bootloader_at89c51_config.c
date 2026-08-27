#include <reg51.h>
sbit LED = P1^0;
void UART_Init()
{
    TMOD = 0x20;
    TH1 = 0xFD;
    SCON = 0x50;
    TR1 = 1;
}
void GPIO_Init()
{
    P1 = 0x00;
}
void Bootloader_Init()
{
    GPIO_Init();
    UART_Init();
}
void main()
{
    Bootloader_Init();
    while (1)
    {
        LED = ~LED;
    }
}