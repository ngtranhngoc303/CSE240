// Implements BST insertion
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
struct node* insert(struct node* root, int data, char* question, char* guess)
{
    struct node* newnode = malloc(sizeof(struct node));

    newnode->data = data;
    newnode->question = question;
    newnode->guess = guess;
    newnode->left = NULL;
    newnode->right = NULL;

    if(root == NULL)
        return newnode;
    if(data < root->data)
        root->left = insert(root->left, data, question, guess);
    else
        root->right = insert(root->right, data, question, guess);
    return root;
}