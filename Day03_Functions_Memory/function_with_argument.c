#include <stdio.h>
void add(int a, int b)
{
    printf("Sum = %d\n", a + b);
}
int main()
{
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    add(x, y);
    return 0;
}