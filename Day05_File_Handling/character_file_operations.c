#include <stdio.h>
int main()
{
    FILE *fp;
    char ch;
    fp = fopen("char.txt", "w");
    fputc('A', fp);
    fputc('B', fp);
    fputc('C', fp);
    fclose(fp);
    fp = fopen("char.txt", "r");
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c ", ch);
    }
    fclose(fp);
    return 0;
}