#include <stdio.h>
int global = 100;      
void demo()
{
    auto int a = 10;        
    static int b = 0;      
    register int c = 20;    

    b++;

    printf("Auto     = %d\n", a);
    printf("Static   = %d\n", b);
    printf("Register = %d\n", c);
    printf("Global   = %d\n\n", global);
}

int main()
{
    demo();
    demo();
    demo();
    return 0;
}