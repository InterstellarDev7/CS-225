#ifndef COMMUNICATION_H
#define COMMUNICATION_H

class FixComms{
    private:
        char board[3][3]; //creates a 3x3 array
        char player = 'X'; //sets player symbol
        char computer = 'O'; //sets computer symbol
    public:
        FixComms(); //Constructor
        void resetBoard(); //Function
        void gameBoard(); //Function
        bool playerMove(int move, char sym); //Function
        bool checkWin(char sym); //Function
        bool checkTie(); //Function
        void computerMove(); //Function
        void playTicTacToe(); //Function
};

void startCommunicationMiniGame();// Function to start the mini-game

#endif