#include <stdio.h>
struct student{
    int id;
    float marks;
};
void main(){
    FILE *fp;
    struct student s1={100,95.5},s2;
    fp=fopen("student.data","w");
    fwrite(&s1,sizeof(s1),1,fp);
    fclose(fp);
    fp=fopen("student.data","r");
    fread(&s2,sizeof(s2),1,fp);
    printf("ID=%d\n",s2.id);
    printf("Marks=%.2f\n",s2.marks);
}