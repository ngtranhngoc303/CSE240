/*
 * This program allows players to play a guessing game,
 * records each player's name and number of guesses,
 * keeps the top 5 leaders, and saves the leaders to a text file.
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Represents a single player with their name and guess count.
class Player
{
    public:
        Player() : name(""), num_guesses(0) {};
        Player(string nm, int ng): name(nm), num_guesses(ng){};
        string GetName() const { return name; }
        int GetNumGuesses() const { return num_guesses; }
        void SetName(const string& nm) { name = nm; }
        void SetNumGuesses(int ng) { num_guesses = ng; }
    private:
        string name;
        int num_guesses;
};

// Manages the top 5 players list and file I/O operations.
class LeaderBoard
{
    public:
        LeaderBoard()
        {
            for (int i = 0; i < NUM_LEADERS; i++)
                leaders[i] = Player("",0);
        }
        
        // Inserts a player into the leaderboard in ascending order of guesses.
        void InsertPlayer(Player player)
        {
            int position = 0;

            while (position < NUM_LEADERS && !leaders[position].GetName().empty() && leaders[position].GetNumGuesses() <= player.GetNumGuesses())
                position++;

            if (position < NUM_LEADERS)
            {
                for (int i = NUM_LEADERS - 1; i > position; i--){
                    leaders[i] = leaders[i - 1];
                }
                leaders[position] = player;
            }
        }

        // Reads existing leaders from a text file into leaders array.
        void ReadLeaders(const char* filename)
        {
            FILE *fp = fopen(filename, "r");

            if ( fp == NULL ) return;

            char tempName[30];
            int tempGuess;

            for (int i = 0; i < NUM_LEADERS; i++)
            {
                if (fscanf(fp, "%29s %d", tempName, &tempGuess) == 2)
                {
                    leaders[i] = Player(tempName,tempGuess);
                }
                else
                    break;  
            }
            fclose(fp);
        }

        // Saves the current top 5 leaders to file.
        void WriteLeaders(const char* filename)
        {
            FILE *fp = fopen(filename, "w");

            if ( fp == NULL ) return;

            for (int i = 0; i < NUM_LEADERS; i++)
                {
                    if (!leaders[i].GetName().empty())
                    {
                        fprintf(fp,"%s %d\n", leaders[i].GetName().c_str(), leaders[i].GetNumGuesses());
                    }
                }
            fclose(fp);
        }

        // Display top 5 players.
        void DisplayLeaders() const
        {
            cout << "Current leaders:\n";
            for (int i = 0; i < 5; i++)
            {
                if (!leaders[i].GetName().empty())
                {
                    cout << leaders[i].GetName() << " made " << leaders[i].GetNumGuesses() << " guesses\n";
                }
            }
        }
    private:
        static const int NUM_LEADERS = 5;
        Player leaders[NUM_LEADERS];
};

// Gets the number of guesses from the user.
int GetGuess()
{
    int guess;
    cin >> guess;
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

    cout << squareRoot << " is the square root of what number? Guess a value between 10 and 100: ";

    bool done = false;
    int guessCount = 0;
    while (!done)
    {
        int guess = GetGuess();
        guessCount++;

        if (guess < numberToGuess)
            cout << "Too low, guess again: Guess a value between 10 and 100: ";
        else if (guess > numberToGuess)
            cout << "Too high, guess again: Guess a value between 10 and 100: ";
        else
            done = true;
    }
    cout << "You got it, baby!\n";
    cout << "You made " << guessCount  << " guesses.\n" ;

    return guessCount;
}


/*
 * Initializes the game and reads existing leaders.
 * Allows players to play the guessing game.
 * Updates the leaders list.
 */
int main()
{
    srand((unsigned int) time (NULL)); // Seed rand with current time.

    LeaderBoard leaderboard;
    leaderboard.ReadLeaders("leaderboard.txt");
    cout<<"Welcome! Press 'q' to quit or any other key to continue:\n";
    
    char c;
    bool game_over = false;

    while(!game_over)
    {
        cin >> c;
        if (c == 'q')
        {
            game_over = true;
            leaderboard.WriteLeaders("leaderboard.txt");
            cout << "Bye Bye!\n";
        }
        else
        {
            Player currentPlayer;
            string tempName;

            cout << "Please enter your name to start: ";
            cin >> tempName;
            currentPlayer.SetName(tempName);

            int guesses = PlayGuessingGame();
            currentPlayer.SetNumGuesses(guesses);

            leaderboard.InsertPlayer(currentPlayer);
            leaderboard.DisplayLeaders();

            cout << "Press 'q' to quit or any other key to continue:\n";
        }
    }
    return 0;
}