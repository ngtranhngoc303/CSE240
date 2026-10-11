#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

int main()
{
    slist scores = {NULL, NULL};
insertHead( &scores, 7);
insertHead( &scores, 3);
insertHead( &scores, 2);
printList(&scores);
    return 0;
}