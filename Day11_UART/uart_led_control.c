#include <reg51.h>

void UART_Init()
{
    TMOD=0x20;
    TH1=0xFD;
    SCON=0x50;
    TR1=1;
}

char UART_Rx()
{
    while(RI==0);

    RI=0;

    return SBUF;
}

void main()
{
    char ch;

    UART_Init();

    while(1)
    {
        ch=UART_Rx();

        if(ch=='1')
            P2=0xFF;

        else if(ch=='0')
            P2=0x00;
    }
}