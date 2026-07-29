#include <stdio.h>          
int global = 100;
void display()
{
    int local = 50;

    printf("Global Variable = %d\n", global);
    printf("Local Variable = %d\n", local);
}
int main()
{
    display();
    printf("Global Variable in main = %d\n", global);
    return 0;
}