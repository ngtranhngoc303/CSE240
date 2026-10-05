/*
 * This program allows players to play a guessing game,
 * records each player's name and number of guesses,
 * keeps the top 5 leaders, and saves the leaders to a text file when the user quits.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Stores the player's name and the number of guesses.
typedef struct
{
    char name[30];
    int guess;
} Player;
typedef enum {F = 0, T = 1} Bool;

// Gets a guess from the user and returns it.
int GetGuess()
{
    int guess;
    scanf("%d", &guess);
    return guess;
}

/*
 * Generates a random number between 10 and 100.
 * Asks the player to guess the number using its square root.
 * Counts and returns the number of guesses.
 */
int PlayGuessingGame()
{
    // Generate a random number between 10 and 100 and find its square root.
    int numberToGuess = rand() % 91 + 10;
    double squareRoot = sqrt(numberToGuess);

    printf("%.8f is the square root of what number? Guess a value between 10 and 100: ", squareRoot);

    Bool done = F;
    int guessCount = 0;
    while (!done)
    {
        int guess = GetGuess();
        guessCount++;

        if (guess < numberToGuess)
            printf("Too low, guess again: Guess a value between 10 and 100: ");
        else if (guess > numberToGuess)
            printf("Too high, guess again: Guess a value between 10 and 100: ");
        else
            done = T;
    }
    printf("You got it, baby!\n");
    printf("You made %d guesses.\n", guessCount);

    return guessCount;
}

/*
 * Adds the current player to the leaders list in order from the fewest guesses to the most guesses.
 * Keeps only the top 5 players.
 */
void AddPlayer(Player leaders[], Player currentPlayer)
{
    int position = 0;

    while (position < 5 && leaders[position].name[0] != '\0' && leaders[position].guess <= currentPlayer.guess){
        position++;
    }

    if (position < 5)
    {
        for (int i = 4; i > position; i--){
            leaders[i] = leaders[i - 1];
        }
        leaders[position] = currentPlayer;
    }
}

// Reads the existing leaders from leaders.txt and stores them in the leaders array.
void ReadLeaders(Player leaders[])
{
    FILE *fp = fopen("leaders.txt", "r");

    if ( fp == NULL )
    {
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        if (fscanf(fp, "%29s %d", leaders[i].name, &leaders[i].guess) != 2)
            break;  
    }
    fclose(fp);
}

// Writes the current top 5 leaders to leaders.txt.
void WriteLeaders(Player leaders[])
{
    FILE *fp = fopen("leaders.txt", "w");

    if ( fp == NULL )
    {
        return;
    }
     for (int i = 0; i < 5; i++)
        {
            if (leaders[i].name[0] != '\0')
            {
                fprintf(fp,"%s %d\n", leaders[i].name, leaders[i].guess);
            }
        }
    fclose(fp);
}
/*
 * Initializes the game and reads existing leaders.
 * Allows players to play the guessing game.
 * Updates the leaders list and saves it when the user quits.
 */
int main()
{
    srand((unsigned int) time (NULL)); // Seed rand with current time.

    char choice;
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    
    Player leaders[5] = {
        {"", 0},
        {"", 0},
        {"", 0},
        {"", 0},
        {"", 0}
    };
    ReadLeaders(leaders);
    while(1)
    {
        if (scanf(" %c", &choice) != 1)
        {
            break;
        }
        if (choice == 'q')
        {
            WriteLeaders(leaders);
            break;
        }

        Player currentPlayer;

        printf("Please enter your name to start: ");
        scanf("%29s", currentPlayer.name);

        currentPlayer.guess = PlayGuessingGame();

        AddPlayer(leaders, currentPlayer);
        
        printf("Current leaders:\n");

        for (int i = 0; i < 5; i++)
        {
            if (leaders[i].name[0] != '\0')
            {
                printf("%s made %d guesses\n", leaders[i].name, leaders[i].guess);
            }
        }
        printf("Press 'q' to quit or any other key to continue:\n");
    }
        printf("Bye Bye!\n");
        return 0;
}