#include <stdio.h>
#define DEBUG
int main()
{
#ifdef DEBUG
    printf("Debug Mode Enabled\n");
#endif
#ifndef TEST
    printf("TEST is not defined\n");
#endif
    printf("Program Executed\n");
    return 0;
}