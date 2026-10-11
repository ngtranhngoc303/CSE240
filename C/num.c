#include <stdio.h>
#define NUM_SCORES 5

void set_scores(int scores[], int val)
{
    for (int i = 0; i < NUM_SCORES; i++)
    scores[i] = val;
}
int main(){
    int scores[NUM_SCORES];
    set_scores(scores, 100);
    for (int i = 0; i < NUM_SCORES; i++)
    printf("score[%d] = %d \n", i, scores[i]);
return 0; 
}