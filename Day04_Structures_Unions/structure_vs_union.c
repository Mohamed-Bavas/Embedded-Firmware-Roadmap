#include <stdio.h>
struct Test
{
    int a;
    float b;
    char c;
};
union Test2
{
    int a;
    float b;
    char c;
};
int main()
{ 
    printf("Size of Structure = %lu bytes\n", sizeof(struct Test));
    printf("Size of Union = %lu bytes\n", sizeof(union Test2));
    return 0;
}