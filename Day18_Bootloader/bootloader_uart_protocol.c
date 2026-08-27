#include <reg51.h>
#define CMD_ERASE  0x01
#define CMD_WRITE  0x02
#define CMD_VERIFY 0x03
#define CMD_JUMP  0x04
void UART_Init()
{
    TMOD = 0x20;
    TH1 = 0xFD;
    SCON = 0x50;
    TR1 = 1;
}
unsigned char UART_Read()
{
    unsigned char dat;
    while (RI == 0);
    RI = 0;
    dat = SBUF;
    return dat;
}
void UART_Write(unsigned char dat)
{
    SBUF = dat;
    while (TI == 0);
    TI = 0;
}
void Bootloader_Process()
{
    unsigned char command;
    command = UART_Read();
    switch (command)
    {
        case CMD_ERASE:
            UART_Write(0xAA);
            break;
        case CMD_WRITE:
            UART_Write(0xBB);
            break;
        case CMD_VERIFY:
            UART_Write(0xCC);
            break;
        case CMD_JUMP:
            UART_Write(0xDD);
            break;
        default:
            UART_Write(0xFF);
            break;
    }
}
void main()
{
    UART_Init();
    while (1)
    {
        Bootloader_Process();
    }
}