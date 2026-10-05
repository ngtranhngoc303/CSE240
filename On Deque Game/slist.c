// This file implements singly linked list operations used by the Deque program.
#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

// Insert a new node at the beginning of the list.
void insertHead(SList* list, char* data)
{
    //---- create new node
    struct node* newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = list->head;
    //---- adjust pointers
    list->head = newnode;
    if (list->tail == NULL)
        list->tail = newnode;
}

// Remove the first node and return its data.
char* removeHead(SList* list)
{
    if(list->head == NULL)
        return NULL;

    struct node* temp = list->head;
    char* data = temp->data;

    list->head = temp->next;
    
    if(list->head == NULL)
        list->tail = NULL;

    free(temp);
    return data;
}

// Insert a new node at the end of the list.
void insertTail(SList* list, char* data)
{
    //---- create new node
    struct node* newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(list->tail == NULL)
    {
        list->head = newnode;
        list->tail = newnode;
    }
    else
    {
        list->tail->next = newnode;
        list->tail = newnode;
    }
    
}

// Remove the last node and return its data.
char* removeTail(SList* list)
{
    if(list->tail == NULL)
        return NULL;
    if(list->head->next == NULL)
    {
        char* data = list->head->data;
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        return data;
    }

    struct node* temp = list->head;

    while(temp->next->next != NULL){
        temp = temp->next;
    }
    char* data = temp->next->data;

    free(temp->next);
    temp->next = NULL;
    list->tail = temp;

    return data;
}