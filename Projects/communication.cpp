/****************************************************************************
* File:   communication.cpp
* Author:   Devin Trujillo
* Purpose:  mini game to fix comms problem
* resources: YouTube (Kenny Yip Coding)
*******************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
//#include "choices.h"
//#include "person.h"
using namespace std;

class fixComms{
    private:
        char board[3][3]; //creates a 3x3 array
        char player = 'X'; //sets player symbol
        char computer = 'O'; //sets computer symbol
    public:
        fixComms();
        void resetBoard();
        void gameBoard();
        bool playerMove(int move, char sym);
        bool checkWin(char sym);
        bool checkTie();
        void computerMove();
        void playTicTacToe();
    
};

fixComms::fixComms(){
    cout << "***********************************************************************************************************" << endl;
    cout << "Your challenge to fix Communications is to play a game of Tic-Tac-Toe against the ISS computer and WIN." << endl;
    cout << "***********************************************************************************************************" << endl;
    resetBoard(); // Initialize board
}

/*
This function resets the board, filling the board from 1-9 into each box
*/
void fixComms::resetBoard() {
    int num = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '0' + num++; // Fill board with numbers 1-9
        }
    }
}

/*
This function sets up the game board, applying an array value to a corresponding "box"
*/
void fixComms::gameBoard() {
    cout << "   |   |   " << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl; //Putting array values on board
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl; //Putting array values on board
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl; //Putting array values on board
    cout << "   |   |   " << endl;
}

/*
This function handles a player's move in the game by placing their symbol (X or O) 
in the specified position if it's valid.
*/
bool fixComms::playerMove(int move, char sym) {
    int row = (move-1) / 3;
    int col = (move-1) % 3;
    
    if (board[row][col] != 'X' && board[row][col] != 'O'){
        board[row][col] = sym;
        return true;
    }
    return false;
}

/*
This function checks rows/columns/diagonals for three symbols in a row/column/diagonal.
This then will equal a win for either computer or player, returning true. If there are none, then
function returns false = no wins.
*/
bool fixComms::checkWin(char sym) {
    for (int i = 0; i < 3; i++){ // This for loop checks for three of the player/computer symbols in a row or column or diagonal
        if ((board[i][0] == sym && board[i][1] == sym && board[i][2] == sym) || //Checking rows
            (board[0][i] == sym && board[1][i] == sym && board[2][i] == sym)) { //Checking columns
        
        return true; //Player/Computer wins
        }
    }
    
    if ((board[0][0] == sym && board[1][1] == sym && board[2][2] == sym) || //Checking diagonals
        (board[0][2] == sym && board[1][1] == sym && board[2][0] == sym)) { //Checking diagonals
        
        return true; //Player/Computer wins
    }
    
    return false; // There are no three in a row/column/diagonal, game continues or ends
}

/*
This function goes through all the rows and columns checking to make sure there are no empty spaces, 
if there are not and there are no wins then the game has come to a tie.
*/
bool fixComms::checkTie() {
    for (int i = 0; i < 3; i++) { //Going through each row
        for (int j = 0; j < 3; j++) { //Going through each column
            if (board[i][j] != 'X' && board[i][j] != 'O') { //Checks if there is empty spaces
                return false; // If any empty space exists game continues
            }
        }
    }
    return true; // No empty spaces left and no wins (player or computer), then a draw
}

/*
The "computer" keeps generating a random number until it has not chose a spot the player
has already picked. Ensuring the computer places an O in an empty space.
*/
void fixComms::computerMove() {
    srand(time(0));
    int move;
    do {
        move = rand() % 9 + 1;
    } while (!playerMove(move, computer));
}


/*
This function runs the game, taking player moves and checking for wins or ties, then taking in computer
moves and checking for wins or ties. The function continues to run until there are no more empty spaces or until
there is a win.
*/
void fixComms::playTicTacToe(){
    while (true) { // Keeps playing until player wins
        resetBoard(); // Reset the board for a new game
        int playMoves; // Tracks player move choices

        while (true) { //Keeps playing as long as there are empty spaces
            gameBoard();
            cout << "Enter your move (A single number (1-9)): ";
            cin >> playMoves; //Player input

            while (!playerMove(playMoves, player)) { //For if the player chooses a spot that is not empty
                cout << "Invalid move! Try again: ";
                cin >> playMoves; //Player input
            }

            if (checkWin(player)) { //Checking player move for a win
                gameBoard();
                cout << "You Have Succeeded in Restoring the Communications!" << endl;
                return; //Game ends when player wins
            }

            if (checkTie()) { //Checking for no empty spaces and restarts when neither computer or player wins
                gameBoard();
                cout << "DRAW! Restarting the game..." << endl;
                break; //Restarts game
            }

            cout << "Computer's turn..." << endl;
            computerMove(); //Computer makes move

            if (checkWin(computer)) { //Checking computer moves for a win and then restarts if one is found
                gameBoard();
                cout << "The computer WINS! Restarting the game..." << endl;
                break; //Restarts game 
            }

            if (checkTie()) { //Checking for no empty spaces and restarts when neither computer or player wins 
                gameBoard();
                cout << "DRAW! Restarting the game..." << endl;
                break; //Restarts game
            }
        }
    }
}

int main(){ 
    fixComms fc;
    fc.playTicTacToe();

    return 0;
}
