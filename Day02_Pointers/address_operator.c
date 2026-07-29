#include <stdio.h>
int main()
{
    int a = 50;
    printf("Value = %d\n", a);
    printf("Address = %p\n", (void *)&a);
    return 0;
}