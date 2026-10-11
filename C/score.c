#include <stdio.h>
#include <stdlib.h>

void set_score(int scores[], int num_score, int val)
{
    for(int i = 0; i < num_score; i++){
        scores[i] = val;
    }
}

int main ()
{
    int num_score;
    printf("Enter the number of data items: \n");
    scanf(" %d", &num_score);

    // int scores[nums_score];
    int* scores = (int*)malloc(num_score*sizeof(int));
    if (scores == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        return -1;
    }
    set_score(scores, num_score, 100);

    for(int i = 0; i < num_score; i++)
        printf("scores[%d] = %d\n", i, scores[i]);
    free(scores);
    return 0;
}
// could be on the exam