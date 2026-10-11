/*
 * This program implements a Deque using a singly linked list.
 * It reads names from an input file and allows the user to
 * navigate through the names forwards and backwards.
 *
 * Commands:
 *   f - move forwards
 *   b - move backwards
 *   q - quit the program
 */
#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
#define MAX_NAME_LEN 100
typedef enum { F = 0, T = 1 } Bool;

// Adds a name to the back of the Deque.
void push_back(Deque* q, char* data)
{
    insertTail(q, data);
}

// Adds a name to the front of the Deque.
void push_front(Deque* q, char* data)
{
    insertHead(q, data);
}

// Removes and returns the name at the back of the Deque.
char* pop_back(Deque* q)
{
    return removeTail(q);
}

// Removes and returns the name at the front of the Deque.
char* pop_front(Deque * q)
{
    return removeHead(q);
}

// Reads the names from the input file, stores them in the Deque, and allows the user to navigate through the names.
int main(int argc, char * argv[])
{
    // Initialize an empty Deque.
    Deque q = {NULL, NULL};

    // Open the input file containing the names.
    FILE *fp = fopen(argv[1], "r");

    // Read each name from the file and add it to the back of the Deque.
    Bool done = F;
    while (!done)
    {
    char* name = malloc(MAX_NAME_LEN);
    if (fscanf(fp, "%s", name) == 1)
    push_back(&q, name);
    else
    done = T;
    }

    // Start at the tail so that the first forward command displays the first name.
    struct node* current = q.tail;

    char input;

    printf("To scroll through the names type\n");
    printf("f: forwards, b: backwards, q: quit\n");

    // Continuously process the user's navigation commands.
    while(1)
    {
        scanf(" %c", &input);
        // Move forward to the next name.
        // If the current name is the last one, wrap around to the first name.
        if(input == 'f')
        {
            if(current->next != NULL)
                current = current->next;
            else
                current = q.head;
            printf("%s\n", current->data);
        }

        // Move backward to the previous name.
        // Since this is a singly linked list, find the node
        // whose next pointer points to the current node.
        else if(input == 'b')
        {
            printf("%s\n", current->data);
            if (current == q.head)
            {
                current = q.tail;
            }
            else{
                struct node * temp = q.head;

                while(temp->next != current)
                {
                    temp = temp->next;
                }
                current = temp;
            }
        }
        // Quit the program.
        else if(input == 'q')
        {
            printf("Bye!\n");
            break;
        }
    }
}