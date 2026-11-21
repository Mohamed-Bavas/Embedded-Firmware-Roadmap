#include <stdio.h>
int main()
{
    int a[100], n, i;
    int sum = 0, expected;
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 0; i < n - 1; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    expected = n * (n + 1) / 2;
    printf("Missing Number = %d", expected - sum);
    return 0;
}