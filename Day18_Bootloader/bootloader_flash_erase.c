#include <reg51.h>
#define FLASH_SIZE 1024
unsigned char  xdata flash_memory[FLASH_SIZE];
void Flash_Erase()
{
    unsigned int i;
    for (i = 0; i < FLASH_SIZE; i++)
    {
        flash_memory[i] = 0xFF;
    }
}
void main()
{
    Flash_Erase();
    while (1);
}