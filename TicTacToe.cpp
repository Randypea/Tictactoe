#include <iostream>
#include "TicTacToe.h"

using namespace std;

void TicTacToe::PrintBoard() //A function for printing out the tic tac toe board
{   cout << endl;

    for (int i = 0; i <3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool TicTacToe::Input() //A function for input
{
    int input;
    cout << player << "\'s turn." << endl;
    cout << "Choose a position from 1 to 9 that is not already X or O: ";
    cin >> input;

    int r; int c;

    if (input == 1) { r = 0; c = 0;}
    if (input == 2) { r = 0; c = 1;}
    if (input == 3) { r = 0; c = 2;}
    if (input == 4) { r = 1; c = 0;}
    if (input == 5) { r = 1; c = 1;}
    if (input == 6) { r = 1; c = 2;}
    if (input == 7) { r = 2; c = 0;}
    if (input == 8) { r = 2; c = 1;}
    if (input == 9) { r = 2; c = 2;}

    if(board[r][c] == 'X' || board[r][c] == 'O')
    {
        cout << "Place already taken/ Choose again please." << endl;
        SwitchPlayer(); //Call SwitchPlayer to force this user to input again. It will be called twice.
        return false;
    }
    else
    {
        board[r][c] = player;
        return true;
    }

    return true;
}

void TicTacToe::SwitchPlayer()
{
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}

bool TicTacToe::CheckWin(char p){

    //Check all three rows
    if(board[0][0] == p && board[0][1] == p && board[0][2] == p) return true;
    if(board[1][0] == p && board[1][1] == p && board[1][2] == p) return true;
    if(board[2][0] == p && board[2][1] == p && board[2][2] == p) return true;

    //Check all three columns
    if(board[0][0] == p && board[1][0] == p && board[2][0] == p) return true;
    if(board[0][1] == p && board[1][1] == p && board[2][1] == p) return true;
    if(board[0][2] == p && board[1][2] == p && board[2][2] == p) return true;

    //Check two diagonals
    if(board[0][0] == p && board[1][1] == p && board[2][2] == p) return true;
    if(board[2][0] == p && board[1][1] == p && board[0][2] == p) return true;

    return false;

}

char TicTacToe::WinnerFound()
{
    if (CheckWin('X'))  return 'X';
    if (CheckWin('O'))  return 'O';
    return 'N'; //No Winner Yet
}
