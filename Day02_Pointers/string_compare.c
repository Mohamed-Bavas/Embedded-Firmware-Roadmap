#include <stdio.h>
int main()
{
    char str1[] = "Hello";
    char str2[] = "Hello";
    int i = 0;
    int flag = 1;
    while(str1[i] != '\0' || str2[i] != '\0')
    {
        if(str1[i] != str2[i])
        {
            flag = 0;
            break;
        }
        i++;
    }
    if(flag)
        printf("Strings are Equal\n");
    else
        printf("Strings are Not Equal\n");
    return 0;
}