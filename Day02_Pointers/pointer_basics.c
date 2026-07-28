#include <stdio.h>
int main(){
    int a;
    printf("Enter a=\n");
    scanf("%d",&a);
    int *ptr;
    ptr=&a;
    printf("Value of a=%d\n",a);
    printf("Address of a=%p\n",(void *)&a);
    printf("Value pointed by ptr=%d\n",*ptr);
    printf("Address pointed by ptr=%p\n",(void *)ptr);
}