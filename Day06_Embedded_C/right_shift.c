#include <stdio.h>
void main(){
    int a;
    printf("Enter number:");
    scanf("%d",&a);
    printf("before right shift : %d\n",a);
    a=a>>1;
    printf("after right shift : %d\n",a);
}