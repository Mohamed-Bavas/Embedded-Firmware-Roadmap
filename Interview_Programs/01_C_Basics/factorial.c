#include <stdio.h>
int main()
{
    int num, i;
    unsigned long long fact = 1;
    printf("Enter a number: ");
    scanf("%d", &num);
    if(num < 0)
    {
        printf("Factorial not possible");
        return 0;
    }
    for(i = 1; i <= num; i++)
        fact = fact * i;
    printf("Factorial = %llu", fact);
    return 0;
}