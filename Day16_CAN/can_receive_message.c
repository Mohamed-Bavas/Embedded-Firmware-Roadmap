#include <reg51.h>
sbit CS   = P1^3;
sbit SCK  = P1^0;
sbit MOSI = P1^1;
sbit MISO = P1^2;
#define CANSTAT    0x0E
#define CANCTRL    0x0F
#define CNF3       0x28
#define CNF2       0x29
#define CNF1       0x2A
#define CANINTE    0x2B
#define CANINTF    0x2C
#define RXB0CTRL   0x60
#define RXB0SIDH   0x61
#define RXB0SIDL   0x62
#define RXB0EID8   0x63
#define RXB0EID0   0x64
#define RXB0DLC    0x65
#define RXB0D0     0x66
#define RXB0D1     0x67
#define RXB0D2     0x68
#define RXB0D3     0x69
#define RXB0D4     0x6A
#define RXB0D5     0x6B
#define RXB0D6     0x6C
#define RXB0D7     0x6D
#define MCP_RESET  0xC0
#define MCP_READ   0x03
#define MCP_WRITE  0x02
#define MCP_BITMOD 0x05
void Delay_ms(unsigned int ms)
{
    unsigned int i;
    unsigned int j;
    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 120; j++);
    }
}
void SPI_Init(void)
{
    CS   = 1;
    SCK  = 0;
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
void MCP_Reset(void)
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
    dat = SPI_Transfer(0x00);
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
void CAN_Init(void)
{
    SPI_Init();
    MCP_Reset();
    MCP_WriteReg(CNF1, 0x01);
    MCP_WriteReg(CNF2, 0xF1);
    MCP_WriteReg(CNF3, 0x05);
    MCP_WriteReg(RXB0CTRL, 0x60);
    MCP_WriteReg(CANINTE, 0x01);
    MCP_WriteReg(CANCTRL, 0x00);
    Delay_ms(10);
}
unsigned char CAN_ReceiveMessage(unsigned int *id,
                                 unsigned char *dat)
{
    unsigned char len;
    unsigned char i;
    unsigned char sidh;
    unsigned char sidl;
    if ((MCP_ReadReg(CANINTF) & 0x01) == 0)
    {
        return 0;
    }
    sidh = MCP_ReadReg(RXB0SIDH);
    sidl = MCP_ReadReg(RXB0SIDL);
    *id = ((unsigned int)sidh << 3);
    *id = *id | ((unsigned int)sidl >> 5);
    len = MCP_ReadReg(RXB0DLC) & 0x0F;
    if (len > 8)
    {
        len = 8;
    }
    for (i = 0; i < len; i++)
    {
        dat[i] = MCP_ReadReg(RXB0D0 + i);
    }
    MCP_BitModify(CANINTF,
                  0x01,
                  0x00);
    return len;
}
void main(void)
{
    unsigned int rx_id;
    unsigned char rx_data[8];
    unsigned char rx_len;
    CAN_Init();
    while (1)
    {
        rx_len = CAN_ReceiveMessage(&rx_id,
                                    rx_data);
        if (rx_len > 0)
        {
            P2 = rx_data[0];
        }
    }
}