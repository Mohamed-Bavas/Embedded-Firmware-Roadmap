#include <reg51.h>
sbit SCK = P1^0;
sbit SI  = P1^1;  
sbit SO  = P1^2;   
sbit CS  = P1^3;
#define MCP_RESET       0xC0
#define MCP_READ        0x03
#define MCP_WRITE       0x02
#define MCP_RTS         0x80    
#define MCP_BIT_MODIFY  0x05
#define CANSTAT  0x0E
#define CANCTRL  0x0F
#define CNF1     0x2A
#define CNF2     0x29
#define CNF3     0x28
#define CANINTE  0x2B
#define CANINTF  0x2C
#define TXB0CTRL 0x30
#define TXB0SIDH 0x31
#define TXB0SIDL 0x32
#define TXB0DLC  0x35
#define TXB0D0   0x36
#define MODE_NORMAL  0x00
void Delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 120; j++);  
}
unsigned char SPI_Transfer(unsigned char dat)
{
    unsigned char i, received = 0;
    for (i = 0; i < 8; i++)
    {
        SI = (dat & 0x80) ? 1 : 0;
        dat <<= 1;
        SCK = 1;
        received <<= 1;
        if (SO) received |= 0x01;
        SCK = 0;
    }
    return received;
}
void MCP_WriteReg(unsigned char addr, unsigned char value)
{
    CS = 0;
    SPI_Transfer(MCP_WRITE);
    SPI_Transfer(addr);
    SPI_Transfer(value);
    CS = 1;
}
unsigned char MCP_ReadReg(unsigned char addr)
{
    unsigned char value;
    CS = 0;
    SPI_Transfer(MCP_READ);
    SPI_Transfer(addr);
    value = SPI_Transfer(0xFF);  
    CS = 1;
    return value;
}
void MCP_BitModify(unsigned char addr, unsigned char mask, unsigned char value)
{
    CS = 0;
    SPI_Transfer(MCP_BIT_MODIFY);
    SPI_Transfer(addr);
    SPI_Transfer(mask);
    SPI_Transfer(value);
    CS = 1;
}
void MCP_Reset()
{
    CS = 0;
    SPI_Transfer(MCP_RESET);
    CS = 1;
    Delay_ms(10);   
}
void CAN_Init()
{
    SCK = 0;
    CS  = 1;     
    MCP_Reset();                  
    MCP_WriteReg(CNF1, 0x00);
    MCP_WriteReg(CNF2, 0x90);
    MCP_WriteReg(CNF3, 0x02);
    MCP_WriteReg(CANINTE, 0x03);   
    MCP_WriteReg(CANINTF, 0x00);   
    MCP_BitModify(CANCTRL, 0xE0, MODE_NORMAL);
    while ((MCP_ReadReg(CANSTAT) & 0xE0) != MODE_NORMAL);
}
void CAN_SendMessage(unsigned int id, unsigned char *dat, unsigned char len)
{
    unsigned char i;
    MCP_WriteReg(TXB0SIDH, (unsigned char)(id >> 3));
    MCP_WriteReg(TXB0SIDL, (unsigned char)((id & 0x07) << 5));
    MCP_WriteReg(TXB0DLC, len & 0x0F);
    for (i = 0; i < len; i++)
        MCP_WriteReg(TXB0D0 + i, dat[i]);
    CS = 0;
    SPI_Transfer(MCP_RTS | 0x01);
    CS = 1;
    while (MCP_ReadReg(TXB0CTRL) & 0x08);
    MCP_BitModify(CANINTF, 0x04, 0x00);
}
void main()
{
    unsigned char message[8] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};
    CAN_Init();
    while (1)
    {
        CAN_SendMessage(0x123, message, 8);   
        Delay_ms(500);
    }
}