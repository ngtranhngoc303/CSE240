#include <stdio.h>

typedef struct Student{
    char letter_grade;
    int id;
} Student;

void passbyvalue( struct Student s )
{
    s.letter_grade = 'B';
    s.id = 237;
}
void passbyaddress( struct Student* s)
{
    s->letter_grade = 'A';
    s->id = 42;
}
int main()
{
    Student s1;

    passbyvalue( s1 );
    printf("letter = %c num = %d \n", s1.letter_grade, s1.id);
    passbyaddress( &s1 );
    printf("letter = %c num = %d \n", s1.letter_grade, s1.id);
    return 0;
}