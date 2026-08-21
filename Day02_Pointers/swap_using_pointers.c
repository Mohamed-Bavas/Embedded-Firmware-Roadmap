#include <stdio.h>
void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int a = 10, b = 20;
    printf("Before Swap\n");
    printf("a=%d b=%d\n", a, b);
    swap(&a, &b);
    printf("After Swap\n");
    printf("a=%d b=%d\n", a, b);
    return 0;
}