#include <reg51.h>
sbit CS   = P1^3;
sbit SCK  = P1^0;
sbit MOSI = P1^1;
sbit MISO = P1^2;
sbit ERROR_LED = P2^0;
#define CANSTAT    0x0E
#define CANCTRL    0x0F
#define CNF3       0x28
#define CNF2       0x29
#define CNF1       0x2A
#define CANINTE    0x2B
#define CANINTF    0x2C
#define EFLG       0x2D
#define TEC        0x1C
#define REC        0x1D
#define EFLG_RX0OVR  0x40
#define EFLG_RX1OVR  0x80
#define EFLG_TXBO    0x20
#define EFLG_TXEP    0x10
#define EFLG_RXEP    0x08
#define EFLG_TXWAR   0x04
#define EFLG_RXWAR   0x02
#define MCP_RESET    0xC0
#define MCP_READ     0x03
#define MCP_WRITE    0x02
#define MCP_BITMOD   0x05
void Delay_ms(unsigned int ms)
{
    unsigned int i;
    unsigned int j;
    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 120; j++);
    }
}
void SPI_Init()
{
    CS = 1;
    SCK = 0;
    MOSI = 0;
}
unsigned char SPI_Transfer(unsigned char dat)
{
    unsigned char i;
    unsigned char received;
    received = 0;
    for (i = 0; i < 8; i++)
    {
        if (dat & 0x80)
            MOSI = 1;
        else
            MOSI = 0;
        SCK = 1;
        received <<= 1;
        if (MISO)
            received |= 1;
        SCK = 0;
        dat <<= 1;
    }
    return received;
}
void MCP_Reset()
{
    CS = 0;
    SPI_Transfer(MCP_RESET);
    CS = 1;
    Delay_ms(10);
}
void MCP_WriteReg(unsigned char address,
                  unsigned char dat)
{
    CS = 0;
    SPI_Transfer(MCP_WRITE);
    SPI_Transfer(address);
    SPI_Transfer(dat);
    CS = 1;
}
unsigned char MCP_ReadReg(unsigned char address)
{
    unsigned char dat;
    CS = 0;
    SPI_Transfer(MCP_READ);
    SPI_Transfer(address);
    dat= SPI_Transfer(0x00);
    CS = 1;
    return dat;
}
void MCP_BitModify(unsigned char address,
                   unsigned char mask,
                   unsigned char dat)
{
    CS = 0;
    SPI_Transfer(MCP_BITMOD);
    SPI_Transfer(address);
    SPI_Transfer(mask);
    SPI_Transfer(dat);
    CS = 1;
}
void CAN_Init()
{
    SPI_Init();
    MCP_Reset();
    MCP_WriteReg(CNF1, 0x01);
    MCP_WriteReg(CNF2, 0xF1);
    MCP_WriteReg(CNF3, 0x05);
    MCP_WriteReg(CANCTRL, 0x00);
    ERROR_LED = 0;
    Delay_ms(10);
}
void CAN_CheckErrors()
{
    unsigned char eflg;
    unsigned char tec;
    unsigned char rec;
    eflg = MCP_ReadReg(EFLG);
    tec = MCP_ReadReg(TEC);
    rec = MCP_ReadReg(REC);
    if (eflg & EFLG_TXBO)
    {
        ERROR_LED = 1;
        MCP_Reset();
        CAN_Init();
    }
    else if ((eflg & (EFLG_TXEP | EFLG_RXEP)) ||
             (tec > 127) ||
             (rec > 127))
    {
        ERROR_LED = 1;
    }
    else if (eflg & (EFLG_TXWAR | EFLG_RXWAR))
    {
        ERROR_LED = 1;
    }
    else
    {
        ERROR_LED = 0;
    }
    if (eflg & (EFLG_RX0OVR | EFLG_RX1OVR))
    {
        MCP_BitModify(
            EFLG,
            EFLG_RX0OVR | EFLG_RX1OVR,
            0x00
        );
    }
}
void main()
{
    CAN_Init();
    while (1)
    {
        CAN_CheckErrors();
        Delay_ms(200);
    }
}