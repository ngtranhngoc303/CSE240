#include <stdio.h>
#define ROWS 3
#define COLS 3

double A [ROWS][COLS];
double B [ROWS][COLS];
double C [ROWS][ROWS];

void MM (double A[][COLS], double B[][COLS], double C[][COLS])
{
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            for (int k = 0; k < ROWS; k++)
                C[r][c] =  C[r][c] + A[r][k] * B[k][c];
}
int main(){
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
        {
            A[r][c] = r+1.0;
            B[r][r] = 2.0;
        }
    MM(A, B, C);
}