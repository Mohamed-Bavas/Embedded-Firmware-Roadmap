#include <stdio.h>
int main() {
    unsigned char num = 10;

    if (num & (1 << 3))
        printf("Bit 3 is SET\n");
    else
        printf("Bit 3 is CLEAR");

    return 0;
}