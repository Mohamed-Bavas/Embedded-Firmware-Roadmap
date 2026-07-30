#include <stdio.h>
union Data
{
    int i;
    float f;
    char ch;
};
int main()
{
    union Data d;
    d.i = 100;
    printf("Integer = %d\n", d.i);
    d.f = 25.5;
    printf("Float = %.2f\n", d.f);
    d.ch = 'A';
    printf("Character = %c\n", d.ch);
    return 0;
}