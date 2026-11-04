#include <stdio.h>
int main(){
    int num;
    printf("Enter a number:");
    scanf("%d",&num);
    if(num%2==0){
        printf("%d is a Even Number",num);
    }  else{
        printf("%d is a Odd Number",num);
    }
}