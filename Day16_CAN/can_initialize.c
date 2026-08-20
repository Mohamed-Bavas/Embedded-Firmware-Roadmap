#include "mcp2515.h"
void CAN_Init()
{
    SPI_Init();
    MCP_Reset();
    MCP_WriteReg(CNF1, 0x00);
    MCP_WriteReg(CNF2, 0x90);
    MCP_WriteReg(CNF3, 0x02);
    MCP_WriteReg(CANINTE, 0x03);
    MCP_WriteReg(CANINTF, 0x00);
    MCP_BitModify(CANCTRL, 0xE0, MODE_NORMAL);
    while ((MCP_ReadReg(CANSTAT) & 0xE0) != MODE_NORMAL);
}
void main()
{
    CAN_Init();
    while (1);
}