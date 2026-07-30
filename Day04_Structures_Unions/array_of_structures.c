#include <stdio.h>
struct Student
{
    int id;
    char name[20];
    float marks;
};
int main()
{
    struct Student s[3];
    int i;
    for(i = 0; i < 3; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &s[i].id);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }
    printf("\nStudent Details\n");
    for(i = 0; i < 3; i++)
    {
        printf("\nID: %d\n", s[i].id);
        printf("Name: %s\n", s[i].name);
        printf("Marks: %.2f\n", s[i].marks);
    }
    return 0;
}