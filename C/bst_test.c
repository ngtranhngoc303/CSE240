#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;

// struct node* insert(struct node* root, int data)
// {
//     // Create new node
//     struct node* temp = malloc(sizeof(struct node));
//     temp->data = data;
//     temp->left = temp->right = NULL;

//     // If tree is empty
//     if (root == NULL)
//     {
//         return temp;
//     }

//     // Search for new node's parrent
//     struct node* current = root;
//     struct node* parent = root;
//     while(current != NULL)
//     {
//         printf("%d\n", current->data);
//         parent = current;
//         if (data < current->data)
//             current = current->left;
//         else
//             current = current->right;
//     }
//     if(data < parent->data)
//         parent->left = temp;
//     else    
//         parent->right = temp;
//     return root;
// }
struct node* insert(struct node* node, int data) // Recursive
{
    // Create new node
    if(node == NULL)
    {
        struct node* temp = malloc(sizeof(struct node));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    else{
        if(data < node->data)
            node->left = insert(node->left, data);
        else    
            node->right = insert(node->right, data);
        return node;
    }
}
// struct node* search(struct node* root, int data)
// {
//     struct node* current = root;
//     while(current != NULL && data != current->data)
//     {
//         if(data < current->data)
//             current = current->left;
//         else
//             current = current->right;
//     }
//     return current;
// }
struct node* search(struct node* root, int key) //recursive
{
   if(root == NULL || root->data == key)
    return root;
   if (root->data < key)
    return search(root->right, key);
   else
    return search(root->left, key);
}
struct node* find_minimum(struct node *root)
{
    if(root == NULL || root->left == NULL)
        return root;
    else
        return find_minimum(root->left);
    return root;
}
void printInorder(struct node* node)
{
    if(node != NULL)
    {
        printInorder(node->left);
        printf("%d", node->data);
        printInorder(node->right);
    }
}
int main()
{
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 70);
    insert(root, 40);
    if (search(root, 40) == NULL)
        printf("%d not found\n", 40);
    else
        printf("%d found\n", 40);
    return 0;
    printf("%d is the mminimum", find_minimum(root)->data);
}
