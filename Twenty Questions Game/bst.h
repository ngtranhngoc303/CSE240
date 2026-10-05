// Defines the node structure and insert function for the binary search tree.
#ifndef bst_h
#define bst_h
#include <stdio.h>
struct node
{
    int data;
    char* question;
    char* guess;
    struct node* left;
    struct node* right;
};
struct node* insert(struct node* root, int data, char* question, char* guess);
#endif