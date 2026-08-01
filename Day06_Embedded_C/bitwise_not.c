#include <stdio.h>
void main(){
    int a,b;
    printf("Enter two numbers:");
    scanf("%d%d",&a,&b);
    printf("Bitwise NOT of %d,%d is %d,%d\n",a,b,~a,~b);
}