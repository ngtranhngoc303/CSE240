/*
 * This program implements the Twenty Questions game using
 * a binary search tree.
 *
 * The game asks the user a series of yes/no questions and
 * uses the answers to navigate through the tree until it
 * reaches a guess.
 */
#include <stdio.h>
#include "bst.h"

// Creates and initializes the game tree with questions and guesses.
struct node* create_game_tree()
{
    struct node* root = NULL;
    root = insert(root, 100, "Does it grow underground?", "");
    insert(root, 50, "Is it long in shape?", "");
    insert(root, 25, "Is it orange in color?", "");
    insert(root, 15, "", "It's a carrot!");
    insert(root, 35, "", "It's a parsnip!");
    insert(root, 75, "Is it red in color?", "");
    insert(root, 65, "", "It's a radish!");
    insert(root, 85, "", "It's a potato!");
    insert(root, 150, "Does it grow on a tree?", "");
    insert(root, 125, "Is it red in color?", "");
    insert(root, 115, "", "It's an apple!");
    insert(root, 135, "", "It's a peach!");
    insert(root, 175, "Is it red in color?", "");
    insert(root, 165, "", "It's a tomato!");
    insert(root, 185, "", "It's a pea!");

    return root;
}

// Run the Twenty Questions game
int main()
{
    struct node* game_tree = create_game_tree();
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    
    char choice;
    scanf(" %c", &choice);

    // Continue playing until the user enters 'q'.
    while(choice != 'q')
    {
        printf("You think of a fruit or vegetable and I will try to guess it!\n");

        struct node* current = game_tree;

        while(current->question[0] != '\0')
        {
            printf("%s\n", current->question);

            char answer;
            printf("y/n: ");
            scanf(" %c", &answer);

            if(answer == 'y')
                current = current->left;
            else
                current = current->right;
        }
        printf("%s\n", current->guess);
        printf("y/n: ");

        char answer;
        scanf(" %c", &answer);

        if(answer == 'y')
            printf("I win!\n");
        else
            printf("You win!\n");

        printf("Press 'q' to quit or any other key to continue:\n");
        scanf(" %c", &choice);
    }
    printf("Bye Bye!\n");
    return 0;
}