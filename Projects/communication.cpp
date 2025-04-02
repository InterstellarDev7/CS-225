/****************************************************************************
* File:   communication.cpp
* Author:   Devin Trujillo
* Purpose:  mini game to fix comms problem
* resources: Youtube (Kenny Yip Coding)
*******************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>  // Added for numeric_limits
#include "communication.h"

using namespace std;

FixComms::FixComms(){
    cout << "You decided to fix communications." << endl;
    cout << "To fix communications, you need to complete the mini-game! " << endl;
    cout << "Let's start the game!\n" << endl;
    cout << "********* Welcome to Tic-Tac-Toe *********" << endl;
    cout << "Your challenge to fix communications is to play a game\nof Tic-Tac-Toe against the ISS computer and WIN." << endl;
    cout << "****************************************" << endl << endl;
    resetBoard();  // Initialize board
}

/*
This function resets the board, filling the board from 1-9 into each box.
*/
void FixComms::resetBoard(){
    int num = 1;
    for(int i = 0; i < 3; i++){//Loop through rows
        for(int j = 0; j < 3; j++){//Loop through columns
            board[i][j] = '0' + num++; //Fill board with numbers 1-9
        }
    }
}

/*
This function displays the game board.
*/
void FixComms::gameBoard(){
    cout << "\nBoard Updated...\n";
    cout << "   |   |   " << endl;
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "   |   |   \n" << endl;
}

/*
This function handles a player's move in the game by placing their symbol (X or O) 
in the specified position if it's valid.
*/
bool FixComms::playerMove(int move, char sym){
    int row = (move - 1) / 3;//Calculate row index (1-3 = row 0, 4-6 = row 1, 7-9 = row 2 )
    int col = (move - 1) % 3;//Calculate column index

    if(board[row][col] != 'X' && board[row][col] != 'O'){//Check if cell is free
        board[row][col] = sym;//Place the player's symbol
        return true;
    }
    return false;//Input invalid if cell is occupied
}

/*
This function checks, rows/columns/diagonals for three symbols in a row/column/diagonal.
This then will equal a win for either computer or player, returning true. If there are none then
function returns false = no wins.
*/
bool FixComms::checkWin(char sym){
    for(int i = 0; i < 3; i++){
        if((board[i][0] == sym && board[i][1] == sym && board[i][2] == sym) ||  //Rows
            (board[0][i] == sym && board[1][i] == sym && board[2][i] == sym)){  //Columns
            return true;
        }
    }

    //Diagonals
    if((board[0][0] == sym && board[1][1] == sym && board[2][2] == sym) ||
        (board[0][2] == sym && board[1][1] == sym && board[2][0] == sym)){
        return true;
    }

    return false;//There are no three in a row/column/diagonal, game continues or ends
}

/*
This function goes through all the rows and columns checking to make sure there are no empty spaces, 
if there are not and there are no wins then the game has come to a tie.
*/
bool FixComms::checkTie(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != 'X' && board[i][j] != 'O'){
                return false;//If any empty space exists game continues
            }
        }
    }
    return true;// No empty spaces left and no wins, then a draw
}

/*
The "computer" keeps generating a random number until it has not chose a spot the player
has already picked. Ensuring the computer places an O in an empty space.
*/
void FixComms::computerMove(){
    srand(time(0));
    int move;
    do{
        move = rand() % 9 + 1;
    }
    while(!playerMove(move, computer));//Keeps trying until a valid move is found
}

/*
This function runs the game, taking player moves and checking for wins or ties, then taking in computer
moves and checking for wins or ties. The function continues to run until there are no more empty spaces or until
there is a win.
*/
void FixComms::playTicTacToe(){
    while (true) { //Keeps playing until player wins
        resetBoard();//Reset the board

        while(true){ 
            gameBoard(); //Display board

            int playMoves; //Tracks player move choices
            cout << "Enter your move (1-9): ";
            while(true){
                if(!(cin >> playMoves)){ //Check if input is not an integer
                    cout << "Invalid input!\nEnter your move (1-9): ";
                    cin.clear();  // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore invalid input
                }
                else if(playMoves < 1 || playMoves > 9){
                    cout << "Invalid choice!\nEnter your move (1-9): ";
                }
                else{
                    break;  // Valid input, break loop
                }
            }

            while(!playerMove(playMoves, player)){  // If the spot is taken
                cout << "Invalid move! That space is already occupied. Try again: ";
                while(true){
                    if(!(cin >> playMoves)){
                        cout << "Invalid input!\nEnter your move (1-9): ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignore invalid input
                    }
                    else if(playMoves < 1 || playMoves > 9){
                        cout << "Invalid choice!\nEnter your move (1-9): ";
                    }
                    else{
                        break;
                    }
                }
            }

            gameBoard();  // Show updated board after player's move

            if(checkWin(player)){
                cout << "Communications restored successfully!" << endl;
                cout << "      ******    " << endl;
                cout << "    *        *  " << endl;
                cout << "   *  COMMS   * " << endl;
                cout << "   * RESTORED * " << endl;
                cout << "    *        *  " << endl;
                cout << "      ******    " << endl;
                cout << "\n";
                return;  // End game
            }

            if(checkTie()){
                cout << "DRAW! Restarting the game..." << endl;
                break;
            }

            cout << "Computer's turn..." << endl;
            computerMove();
            gameBoard();  // Show board after computer's move

            if(checkWin(computer)){
                cout << "The computer WINS! Restarting the game..." << endl;
                break;
            }

            if(checkTie()){
                cout << "DRAW! Restarting the game..." << endl;
                break;
            }
        }
    }
}

void startCommunicationMiniGame(){
    FixComms comms;
    comms.playTicTacToe();
}
