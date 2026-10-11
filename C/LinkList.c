
#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node* next;
};
struct singlylinkedlist
{
struct node* head;
struct node* tail;
};
typedef struct singlylinkedlist slist;
void insertHead(slist* list, int data)
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
void printList(slist* list){
    //---- traverse and print data
struct node* tmp = list->head;
while(tmp != NULL)
{
printf("%d->",tmp->data);
tmp = tmp->next;
}
printf("NULL\n");
}
int main()
{
    slist scores = {NULL, NULL};
insertHead( &scores, 7);
insertHead( &scores, 3);
insertHead( &scores, 2);
printList(&scores);
    return 0;
}