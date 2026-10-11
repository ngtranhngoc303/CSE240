// This file defines the singly linked list structure and declares the functions used to manipulate the list.
#ifndef slist_h
#define slist_h
#include <stdio.h>

// Represents a node in the singly linked list.
struct node
{
    char* data;
    struct node* next;
};

// Represents a singly linked list with pointers to its first and last nodes.
typedef struct singlylinkedlist
{
    struct node* head;
    struct node* tail;
} SList;
// The Deque uses the same structure as the singly linked list.
typedef SList Deque;
// Functions used to manipulate the singly linked list.
void insertHead(SList* list, char* data);
char* removeHead(SList* list);
void insertTail(SList* list, char* data);
char* removeTail(SList* list);
#endif