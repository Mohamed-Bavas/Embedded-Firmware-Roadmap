#include <reg51.h>
void UART_Init()
{
    TMOD=0x20;
    TH1=0xFD;
    SCON=0x50;
    TR1=1;
}
void UART_Tx(char ch)
{
    SBUF=ch;
    while(TI==0);
    TI=0;
}
char UART_Rx()
{
    while(RI==0);
    RI=0;
    return SBUF;
}
void UART_String(char *s)
{
    while(*s)
        UART_Tx(*s++);
}
void main()
{
    char ch;
    UART_Init();
    UART_String("\r\nMenu\r\n");
    UART_String("1. LED ON\r\n");
    UART_String("2. LED OFF\r\n");
    while(1)
    {
        ch=UART_Rx();
        switch(ch)
        {
            case '1':
                P2=0xFF;
                UART_String("LED ON\r\n");
                break;
            case '2':
                P2=0x00;
                UART_String("LED OFF\r\n");
                break;
            default:
                UART_String("Invalid Option\r\n");
        }
    }
}