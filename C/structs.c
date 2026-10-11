#include <stdio.h>
#include <string.h>
// typedef struct 
// {
//     char first_name[30];
//     char last_name[31];
//     int final_grade;

// }student;
struct student
{
    int x;
    char g;
};

int main()
{
    struct student s1;
    // strcpy(s1.first_name, "Jack");
    // strcpy(s1.last_name, "Black");
    // s1.final_grade = 88;
    // printf("name: %s %s\n", s1.first_name, s1.last_name);
    // printf("grade: %d\n", s1.final_grade);
    printf("sizeof(s1) = %lu\n", sizeof(s1));
}