/*
 * This program implements Conway's Game of Life.
 * It takes the initial live cell positions from the user,
 * displays the initial board, and generates the next
 * six generations according to the Game of Life rules.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM_ROWS 5
#define NUM_COLS 5

typedef enum {F = 0, T = 1} Bool;
// Get the initial positions of the live cells from user input.
int GetInitialState(int init_state[])
{
    char input[100];
    int count = 0;

    printf("Enter the offsets for the live cells:\n");
    scanf(" %[^\n]", input);

    char *token = strtok(input, ",");

    while (token != NULL)
    {
        init_state[count] = atoi(token);
        count++;

        token = strtok(NULL, ",");
    }
    return count;
}
// Set up the initial 5x5 board using the live cell offsets.
void SetInitialState(char board[][NUM_COLS], int init_state[], int num_alive)
{
    for (int r = 0 ; r < NUM_ROWS; r++)
    {
        for (int c = 0; c < NUM_COLS; c++){
            board[r][c] = ' ';
        }
    }

    for (int i = 0; i < num_alive; i++)
    {
        int offset = init_state[i];
        int r = offset / NUM_COLS;
        int c = offset % NUM_COLS;

        board[r][c] = '*';
    }
}
// Count the number of live neighbors around a cell.
int CountLiveNeighbors(char board[][NUM_COLS], int r, int c)
{
    int count = 0;
    for (int dr = -1; dr <= 1; dr++)
    {
        for (int dc = -1; dc <= 1; dc++)
        {
            if(dr == 0 && dc == 0)
                continue;
            
            int nr = r + dr;
            int nc = c + dc;

            if(nr >= 0 && nr < NUM_ROWS && nc >= 0 && nc < NUM_COLS)
            {
                if (board[nr][nc] == '*')
                {
                    count++;
                }
            }
        }
    }
    return count;
}
// Generate the next generation of the Game of Life board.
void NextGeneration(char board1[][NUM_COLS])
{
    char board2[NUM_ROWS][NUM_COLS];

    for (int r = 0; r < NUM_ROWS; r++)
    {
        for (int c = 0; c < NUM_COLS; c++)
        {
            int neighbors = CountLiveNeighbors(board1, r, c);

            if (board1[r][c] == '*')
            {
                if (neighbors == 2 || neighbors == 3)
                    board2[r][c] = '*';
                else
                    board2[r][c] = ' ';
            }
            else
            {
                if (neighbors == 3)
                    board2[r][c] = '*';
                else
                    board2[r][c] = ' ';
            }
        }
    }
    for (int r = 0; r < NUM_ROWS; r++)
    {
        for (int c = 0; c < NUM_COLS; c++)
        {
            board1[r][c] = board2[r][c];
        }
    }
}
// Print the current Game of Life board.
void PrintBoard(char board[][NUM_COLS])
{
    for (int r = 0; r < NUM_ROWS; r++)
    {
        for (int c = 0; c < NUM_COLS; c++)
        {
            printf("%c", board[r][c]);
        }
        printf("\n");
    }
}
// Run the Game of Life and display generations 0 through 6.
void PlayGameOfLife()
{
    char choice;
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    scanf(" %c", &choice);

    while (choice != 'q')
    {
        char board[NUM_ROWS][NUM_COLS];
        int init_state[NUM_ROWS * NUM_COLS];

        int num_alive = GetInitialState(init_state);

        SetInitialState(board, init_state, num_alive);

        printf("generation = 0: \n");
        PrintBoard(board);

        for (int generation = 1; generation <= 6; generation++)
        {
            NextGeneration(board);

            printf("generation = %d:\n", generation);
            PrintBoard(board);
        }

        printf("Good life!\n");
        printf("Press 'q' to quit or any other key to continue:\n");
        scanf(" %c", &choice);
    }
    printf("Bye Bye!\n");
}
// Start the Game of Life program.
int main()
{
    PlayGameOfLife();
    return 0;
}