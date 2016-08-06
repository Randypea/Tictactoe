#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main()
{
    TicTacToe game;

    cout << endl;
    cout << "Welcome to Tic Tac Toe!" << endl << endl;
    int validEntries = 0; //This is used to decide if a draw happened.
                          //If there are 9 valid entries without a winner, it's a draw.

    while(1)
    {
        game.PrintBoard();
        if(game.Input())
        {
            validEntries++;
        }
        if(validEntries == 9)
        {
            cout << "It's a draw." << endl;
            break;
        }

        //Check if there's a winner
        char winner=game.WinnerFound();
        if (winner != 'N')  //If true, X or O won
        {
            game.PrintBoard();
            cout << endl;
            cout << winner << " wins!" << endl;
            break;
        }
        cout << "Valid entries: " << validEntries << endl;
        game.SwitchPlayer();
    }

    cout << endl;
    cout << "Thanks for playing!" << endl << endl;
}
