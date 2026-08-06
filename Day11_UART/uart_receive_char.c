#include <reg51.h>
char UART_Rx()
{
    while(RI==0);

    RI=0;

    return SBUF;
}
void UART_Init()
{
    TMOD=0x20;
    TH1=0xFD;
    SCON=0x50;
    TR1=1;
}
void main()
{
    char ch;
    UART_Init();
    while(1)
    {
        ch=UART_Rx();
        P2=ch;
    }
}