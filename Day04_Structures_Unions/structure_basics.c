#include <stdio.h>
struct student {
    int id;
    char name[50];
    float marks;
};
int main() {
    struct student s1;
    printf("Enter Student ID: ");
    scanf("%d", &s1.id);
    printf("Enter Student Name: ");
    scanf(" %49[^\n]", s1.name);
    printf("Enter Student Marks: ");
    scanf("%f", &s1.marks);
    printf("\nStudent Details:\n");
    printf("Student ID    : %d\n", s1.id);
    printf("Student Name  : %s\n", s1.name);
    printf("Student Marks : %.2f\n", s1.marks);
    return 0;
}