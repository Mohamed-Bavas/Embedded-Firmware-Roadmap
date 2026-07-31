#include <stdio.h>
int main()
{
    FILE *fp;
    char ch;
    fp = fopen("sample.txt", "r");
    if (fp == NULL)
    {
        printf("File not found.\n");
        return 1;
    }
    while (fscanf(fp, "%c", &ch) == 1)
    {
        printf("%c", ch);
    }
    fclose(fp);
    return 0;
}