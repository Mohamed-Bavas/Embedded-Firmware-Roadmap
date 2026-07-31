#include <stdio.h>
int main()
{
    FILE *fp;
    char str[100];
    fp = fopen("string.txt", "w");
    fputs("Embedded Firmware Engineer", fp);
    fclose(fp);
    fp = fopen("string.txt", "r");
    fgets(str, sizeof(str), fp);
    printf("%s", str);
    fclose(fp);
    return 0;
}