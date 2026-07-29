#include <stdio.h>
void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("Inside Function:\n");
    printf("a = %d b = %d\n", a, b);
}
int main()
{
    int x = 10, y = 20;
    printf("Before Function:\n");
    printf("x = %d y = %d\n", x, y);
    swap(x, y);
    printf("After Function:\n");
    printf("x = %d y = %d\n", x, y);
    return 0;
}