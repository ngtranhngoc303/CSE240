#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char GetPlayerMove(){
    char move;
    while (1){
        printf("Enter your move (r for rock, p for paper, s for scissors): ");
        if (scanf(" %c", &move) == 1){
            if (move == 'r' || move == 'p' || move == 's'){
                return move;
            }
        }
        while (getchar() != '\n');
        printf("Invalid move. ");
        
    }
}

char GetComputerMove(){
    int random_val = rand() % 3;
    if(random_val == 0) return 'r';
    if(random_val == 1) return 'p';
    return 's';

}

void PlayRockPaperScissorsGame(){
    char player = GetPlayerMove();
    char computer = GetComputerMove();

    printf("Computer's move: %c\n", computer);

    if(player == computer) {
        printf("It's a tie!\n");
    }
    else if((player == 'r' && computer == 's')||
            (player == 'p' && computer == 'r')||
            (player == 's' && computer == 'p')){
            printf("You win!\n");
    }
    else {
        printf("Computer wins!\n");
    }
}
int main(){
        srand((unsigned int)time(NULL));

        char choice;
        printf("Welcome to Rock, Paper, Scissors! Press 'q' to quit or any other key to continue:\n");
        
        while(1){
            if (scanf(" %c", &choice) != 1){
                break;
            }
            if (choice == 'q'){
                break;
            }
            PlayRockPaperScissorsGame();
            printf("Press 'q' to quit or any other key to continue:\n");
        }
        printf("Bye Bye!\n");
        return 0;
}