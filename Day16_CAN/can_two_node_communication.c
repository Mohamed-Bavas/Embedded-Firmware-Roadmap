#include <reg51.h>
#define NODE_A 1
sbit CS   = P1^3;
sbit SCK  = P1^0;
sbit MOSI = P1^1;
sbit MISO = P1^2;
sbit SWITCH_IN  = P3^0;
sbit STATUS_LED = P2^0;
#define CANCTRL    0x0F
#define CANSTAT    0x0E
#define CNF1       0x2A
#define CNF2       0x29
#define CNF3       0x28
#define CANINTF    0x2C
#define TXB0CTRL   0x30
#define TXB0SIDH   0x31
#define TXB0SIDL   0x32
#define TXB0DLC    0x35
#define TXB0D0     0x36
#define RXB0CTRL   0x60
#define RXB0SIDH   0x61
#define RXB0SIDL   0x62
#define RXB0DLC    0x65
#define RXB0D0     0x66
#define MCP_RESET  0xC0
#define MCP_READ   0x03
#define MCP_WRITE  0x02
#define MCP_BITMOD 0x05
#define MCP_RTS    0x80
#define MODE_NORMAL 0x00
#define MODE_CONFIG 0x80
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
        if (dat& 0x80)
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
    MCP_WriteReg(RXB0CTRL, 0x60);
    MCP_WriteReg(CANCTRL, MODE_NORMAL);
    Delay_ms(10);
}
void CAN_SendMessage(unsigned int id,
                     unsigned char *dat,
                     unsigned char len)
{
    unsigned char i;
    if (len > 8)
        len = 8;
    while (MCP_ReadReg(TXB0CTRL) & 0x08);
    MCP_WriteReg(TXB0SIDH, (unsigned char)(id >> 3));
    MCP_WriteReg(
        TXB0SIDL,
        (unsigned char)((id & 0x07) << 5)
    );
    MCP_WriteReg(TXB0DLC, len);
    for (i = 0; i < len; i++)
    {
        MCP_WriteReg(TXB0D0 + i, dat[i]);
    }
    CS = 0;
    SPI_Transfer(MCP_RTS | 0x01);
    CS = 1;
    while (MCP_ReadReg(TXB0CTRL) & 0x08);
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
        len = 8;
    for (i = 0; i < len; i++)
    {
        dat[i] = MCP_ReadReg(RXB0D0 + i);
    }
    MCP_BitModify(CANINTF, 0x01, 0x00);
    return len;
}
void main()
{
    unsigned char tx_buf[1];
    unsigned char rx_buf[8];
    unsigned int rx_id;
    unsigned char rx_len;
    CAN_Init();
#if NODE_A
    while (1)
    {
        tx_buf[0] = SWITCH_IN;
        CAN_SendMessage(0x100, tx_buf, 1);
        rx_len = CAN_ReceiveMessage(&rx_id, rx_buf);
        if ((rx_len > 0) && (rx_id == 0x200))
        {
            STATUS_LED = rx_buf[0];
        }
        Delay_ms(200);
    }
#else
    while (1)
    {
        rx_len = CAN_ReceiveMessage(&rx_id, rx_buf);
        if ((rx_len > 0) && (rx_id == 0x100))
        {
            STATUS_LED = rx_buf[0];
            tx_buf[0] = 0xAA;
            CAN_SendMessage(0x200, tx_buf, 1);
        }
    }
#endif
}