#include <stdio.h>
int add(int,int);
void main(){
    int x,y;
    printf("Enetr two numbers: ");
    scanf("%d %d",&x,&y);
    int result=add(x,y);
    printf("addition = %d",result);
}
int add(int a,int b){
    return a+b;
}