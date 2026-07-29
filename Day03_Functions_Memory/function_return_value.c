#include <stdio.h>
int mul(int a,int b){
    return a*b;
}
void main(){
    int x,y;
    printf("Enter two numbers: ");
    scanf("%d %d",&x,&y);
    int result = mul(x,y);
    printf("Multiplication = %d",result);
}