#include <stdio.h>
int main()
{
    int a[100], n, key, i, found = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter search element: ");
    scanf("%d", &key);
    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            printf("Found at position %d", i + 1);
            found = 1;
            break;
        }
    }
    if(!found)
        printf("Not Found");
    return 0;
}