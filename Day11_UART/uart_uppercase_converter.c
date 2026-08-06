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

void UART_Tx(char ch)
{
    SBUF=ch;

    while(TI==0);

    TI=0;
}

void main()
{
    char ch;

    UART_Init();

    while(1)
    {
        ch=UART_Rx();

        if(ch>='a' && ch<='z')
            ch=ch-32;

        UART_Tx(ch);
    }
}