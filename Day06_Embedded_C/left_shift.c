#include <stdio.h>
void main(){
     int a;
    printf("Enter number:");
    scanf("%d%",&a);
    printf("before left shift : %d\n",a);
    a=a<<1;
    printf("after lest shift : %d\n",a);
}