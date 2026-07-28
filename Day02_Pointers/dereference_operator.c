#include <stdio.h>
int main()
{
    int a = 25;
    int *ptr = &a;
    printf("Value using variable : %d\n", a);
    printf("Value using pointer  : %d\n", *ptr);
    return 0;
}