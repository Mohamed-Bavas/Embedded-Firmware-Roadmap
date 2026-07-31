#include <stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("sample.txt", "a");
    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }
    fprintf(fp, "\nAppending new line.");
    fclose(fp);
    printf("Data appended successfully.\n");
    return 0;
}