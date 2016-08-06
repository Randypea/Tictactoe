#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe{

private:
    //char board[3][3] = {'1', '2','3','4','5','6','7','8','9'};
    //char player = 'X';


public:
    char board[3][3] = {{'1', '2','3'},{'4','5','6'},{'7','8','9'}};
    char player = 'X';

    void PrintBoard();
    bool Input();
    void SwitchPlayer();
    char WinnerFound();
    bool CheckWin(char);

};


#endif // TICTACTOE_H
