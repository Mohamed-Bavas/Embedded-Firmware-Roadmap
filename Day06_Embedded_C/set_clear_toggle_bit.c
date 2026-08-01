#include <stdio.h>
int main() {
    unsigned char num = 10;
    printf("Original = %d\n", num);
    num |=(1 << 2);
    printf("Set Bit2 = %d\n", num);
    num &= ~(1 << 1);
    printf("Clear Bit1 = %d\n", num);
    num ^=(1 << 3);
    printf("Toggle Bit3 = %d\n", num);
    return 0;
}