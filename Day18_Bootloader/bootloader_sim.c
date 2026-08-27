#include <stdio.h>
void Flash_Erase()
{
    printf("Flash Erase Started\n");
    printf("Flash Erase Completed\n");
}
void Flash_Write()
{
    printf("Flash Write Started\n");
    printf("Firmware Write Completed\n");
}
int CRC_Verify()
{
    printf("CRC Validation Started\n");
    printf("CRC Validation Successful\n");
    return 1;
}
void Jump_To_Application()
{
    printf("Jumping to Application\n");
    printf("Application Started\n");
}
int main()
{
    printf("===== BOOTLOADER START =====\n");
    Flash_Erase();
    Flash_Write();
    if (CRC_Verify())
    {
        Jump_To_Application();
    }
    else
    {
        printf("CRC Validation Failed\n");
    }
    printf("===== BOOTLOADER END =====\n");
    return 0;
}