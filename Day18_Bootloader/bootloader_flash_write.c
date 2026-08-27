#include <reg51.h>
#define FLASH_SIZE 1024
unsigned char xdata flash_memory[FLASH_SIZE];
void Flash_Write(unsigned int address, unsigned char dat)
{
    if (address < FLASH_SIZE)
    {
        flash_memory[address] = dat;
    }
}
void main(void)
{
    Flash_Write(0, 0x55);
    Flash_Write(1, 0xAA);
    Flash_Write(2, 0x12);
    while (1);
}