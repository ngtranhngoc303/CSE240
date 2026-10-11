#include <stdio.h>
#include <stdlib.h>
struct person
{
    char fname[20];
    char lname[20];
    int id;
};
int main()
{
    FILE *fp = fopen("file2.txt", "wb");
    if(fp == NULL)
    {
        printf("error opening file\n");
        exit(1);
    }

    struct person s1 = {"Jack", "Black", 5};

    size_t num = fwrite(&s1, sizeof(struct person), 1, fp);
    if(num == 1)
        printf("struct written successfully, size is %ld\n", num);
    else
        printf("Error Writting to File!\n");
    fclose(fp);
    return 0;
}