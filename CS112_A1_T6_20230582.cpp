// Purpose: . A board of 7 columns x 6 rows is displayed 
// Players choose a symbol, either X or O. In their turn, they drop the symbol from top of the
// board until it settles in the bottom empty cell. The first player to connect 4 symbols
// horizontally, vertically or diagonally wins.
// Game: 1 ( connect4 game)
// Author: Yousef Tamer Zaki Mohamed
// ID: 20230582
// Version: V3
// Date: 2/3/2024
#include <iostream>
#include <string>
using namespace std;

// Global variables for the game board and player symbols
string board[7][7];
string p1, p2;

// Function to initialize the game board
void create_board()
{
    // Set the top row with column numbers
    for (int j = 0; j < 7; j++)
    {
        board[0][j] = " " + to_string(1 + j) + " ";
    }

    // Initialize the rest of the board with empty cells
    for (int i = 1; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            board[i][j] = "▒▒▒";
        }
    }
}

// Function to print the game board
void print_board(string board[7][7])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl
             << endl;
    }
}

// Function to prompt players to choose X or O
void X_OR_O()
{
    cout << "Player1: Please choose X or O" << endl;
    cin >> p1;
    while (p1 != "X" and p1 != "O" and p1 != "x" and p1 != "o")
    {
        cout << "Player1: Please choose X or O" << endl;
        cin >> p1;
    }
    if (p1 == "X")
    {
        p1 = " X ";
        p2 = " O ";
    }
    else if (p1 == "x")
    {
        p1 = " X ";
        p2 = " O ";
    }
    if (p1 == " O ")
    {
        p2 = " X ";
    }
    else if (p1 == "o")
    {
        p1 = " O ";
        p2 = " X ";
    }
}

// Function to check if a player has won
bool check_winner(string XO)
{
    // Check horizontally
    for (int i = 1; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == XO && board[i][j + 1] == XO &&
                board[i][j + 2] == XO && board[i][j + 3] == XO)
            {
                return true;
            }
        }
    }

    // Check vertically
    for (int j = 0; j < 7; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (board[i][j] == XO && board[i + 1][j] == XO &&
                board[i + 2][j] == XO && board[i + 3][j] == XO)
            {
                return true;
            }
        }
    }

    // Check diagonally (both directions)
    for (int i = 1; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if ((board[i][j] == XO && board[i + 1][j + 1] == XO &&
                 board[i + 2][j + 2] == XO && board[i + 3][j + 3] == XO) ||
                (board[i][j + 3] == XO && board[i + 1][j + 2] == XO &&
                 board[i + 2][j + 1] == XO && board[i + 3][j] == XO))
            {
                return true;
            }
        }
    }

    return false;
}

// Function to check if the game is a tie
bool check_tie()
{
    for (int i = 1; i < 7; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            if (board[i][j] == "▒▒▒")
            {
                return false;
            }
        }
    }
    return true;
}

// Function to handle the game flow
void game_play()
{
    while (true)
    {
        int x, y;
        int user_choice2;
        cout << "Player1: Please choose  choose a column from 1 to 7" << endl;
        cin >> user_choice2;
        while (user_choice2 < 1 or user_choice2 > 7)
        {
            cout << "Player1: Please choose  choose a column from 1 to 7" << endl;
            cin >> user_choice2;
        }
        while (board[1][user_choice2 - 1] == " X " or board[1][user_choice2 - 1] == " O ")
        {
            cout << "Player1: Please choose another column " << endl;
            cin >> user_choice2;
        }
        y = 6;
        for (int x = 6; x > 0; x--)
        {
            if (board[x][user_choice2 - 1] == " X " or board[x][user_choice2 - 1] == " O ")
            {
                y--;
            }
            else
                break;
        }
        board[y][user_choice2 - 1] = p1;

        print_board(board);

        if (check_winner(p1))
        {
            cout << "Player1 wins!" << endl;
            break;
        }
        if (check_tie())
        {
            cout << "Draw" << endl;
            break;
        }

        cout << "Player2: Please choose  choose a column from 1 to 7" << endl;
        cin >> user_choice2;
        while (user_choice2 < 1 or user_choice2 > 7)
        {
            cout << "Player2: Please choose  choose a column from 1 to 7" << endl;
            cin >> user_choice2;
        }
        while (board[1][user_choice2 - 1] == " X " or board[1][user_choice2 - 1] == " O ")
        {
            cout << "Player2: Please choose another column " << endl;
            cin >> user_choice2;
        }
        y = 6;
        for (int x = 6; x > 0; x--)
        {
            if (board[x][user_choice2 - 1] == " X " or board[x][user_choice2 - 1] == " O ")
            {
                y--;
            }
            else
                break;
        }
        board[y][user_choice2 - 1] = p2;
        print_board(board);
        if (check_winner(p2))
        {
            cout << "Player2 wins!" << endl;
            break;
        }
        if (check_tie())
        {
            cout << "Draw" << endl;
            break;
        }
    }
}

// Main function
int main()
{
    cout << "Welcome to Connect 4 game" << endl;
    while (true)
    {
        int user_choice1;
        cout << "1-Start" << endl
             << "2-End" << endl;
        cout << "Please choose 1 or 2 " << endl;
        cin >> user_choice1;

        // Validate the menu choice
        while (user_choice1 != 1 and user_choice1 != 2)
        {
            cout << "Choose only 1 or 2" << endl;
            cin >> user_choice1;
        }

        if (user_choice1 == 2)
        {
            break; // End the game loop
        }
        else if (user_choice1 == 1)
        {
            create_board();   // Initialize the game board
            print_board(board); // Display the initial game board
            X_OR_O();        // Set player symbols
            game_play();      // Start the game
        }
    }
    return 0;
}
