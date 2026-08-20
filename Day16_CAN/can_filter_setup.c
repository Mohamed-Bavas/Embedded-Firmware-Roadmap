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
#define RXM0SIDH   0x20
#define RXM0SIDL   0x21
#define RXM0EID8   0x22
#define RXM0EID0   0x23
#define RXF0SIDH   0x00
#define RXF0SIDL   0x01
#define RXF0EID8   0x02
#define RXF0EID0   0x03
#define MCP_RESET  0xC0
#define MCP_READ   0x03
#define MCP_WRITE  0x02
#define MCP_BITMOD 0x05
#define MODE_NORMAL 0x00
#define MODE_CONFIG 0x80
void Delay_ms(unsigned int ms)
{
    unsigned int i;
    unsigned int j;
    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 120; j++)
        {
            ;
        }
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
        dat<<= 1;
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
    MCP_BitModify(CANCTRL,
                  0xE0,
                  MODE_CONFIG);
    Delay_ms(5);
}
void CAN_ConfigureFilter(unsigned int filter_id,
                         unsigned int mask)
{
    MCP_BitModify(CANCTRL,
                  0xE0,
                  MODE_CONFIG);
    while ((MCP_ReadReg(CANSTAT) & 0xE0) != MODE_CONFIG);
    MCP_WriteReg(
        RXM0SIDH,
        (unsigned char)(mask >> 3)
    );
    MCP_WriteReg(
        RXM0SIDL,
        (unsigned char)((mask & 0x07) << 5)
    );
    MCP_WriteReg(RXM0EID8, 0x00);
    MCP_WriteReg(RXM0EID0, 0x00);
    MCP_WriteReg(
        RXF0SIDH,
        (unsigned char)(filter_id >> 3)
    );
    MCP_WriteReg(
        RXF0SIDL,
        (unsigned char)((filter_id & 0x07) << 5)
    );
    MCP_WriteReg(RXF0EID8, 0x00);
    MCP_WriteReg(RXF0EID0, 0x00);
    MCP_WriteReg(RXB0CTRL, 0x00);
    MCP_WriteReg(CANINTE, 0x01);
    MCP_BitModify(
        CANCTRL,
        0xE0,
        MODE_NORMAL
    );
    while ((MCP_ReadReg(CANSTAT) & 0xE0) != MODE_NORMAL);
 
}
void main(void)
{
    SPI_Init();
    MCP_Reset();
    CAN_Init();
    CAN_ConfigureFilter(
        0x123,
        0x7FF
    );
    while (1)
    {
    }
}