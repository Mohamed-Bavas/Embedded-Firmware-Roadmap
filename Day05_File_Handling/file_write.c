#include <stdio.h>
int main(){
    FILE *fp;
    fp=fopen("file.txt","w");
    if(fp==NULL){
        printf("file not founded. \n");
        return 1;
    }
   fprintf(fp,"Welcome to Embedded Firmwar Roadmap\n");
   fprintf(fp,"File was successfully written. \n");
     fclose(fp);
     printf("program was successfuiily executed. \n");
     return 0;
}