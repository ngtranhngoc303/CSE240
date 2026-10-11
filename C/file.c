#include <stdio.h>
#include <stdlib.h>
int main()
{
    char filename[] = "file2.txt";
    FILE *fp = NULL;

    // fp = fopen( filename, "w" );
    // if( fp == NULL )
    // {
    //     fprintf( stderr, "Cannot open %s.\n", filename );
    //     exit(1);
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     fprintf( fp, "%d Hello file!\n", i);
    // }
    // fclose( fp );

    fp = fopen( filename, "r" );
    if( fp == NULL )
    {
        fprintf( stderr, "Cannot open %s.\n", filename );
        exit(1);
    }
    // char c;
    // while ( (c = fgetc(fp)) != EOF)
    //     printf("%c", c);
    // printf("\n");
    int idx;
    char line[80];
    while (fscanf(fp, "%d %s %s", &idx, line, line) == 3)
        printf("%d\n", idx);
    fclose( fp );
    return 0;
}