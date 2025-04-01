/******************************************************************************
* File: leak.cpp
* Author: Hyeonjin Park
* Purpose: Fixing Leak
*******************************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <limits>
#include "leak.h"
using namespace std;

void fixLeak(){
    cout << "To fix the leak, you need to complete the mini game!" << endl;
    cout << "Let's start the game!" << endl;
    cout << "*********Welcome to Rock, Scissors, Paper*********" << endl;
    cout << "To fix the leak, you must win a game." << endl;
    cout << "**************************************************\n" << endl;
    string threeChoice[3] = {"rock", "scissors", "paper"};
    string userC;
    string computerC;
    
    srand(time(0));
    
    while (true){
        try{
            cout << "Enter your choice ('rock', 'scissors', or 'paper') => ";
            cin >> userC;
            
            const string ERROR = "ERROR: Invalid option. Try again...\n";

            // If user input wrong option, user can input again until it's valid
            if(userC != "rock" && userC != "scissors" && userC != "paper"){
                throw ERROR;
            }
    
            // random choice between rock, scissors, and paper
            int randomChoice = rand() % 3;
    
            computerC = threeChoice[randomChoice];
            cout << "Program choice => " << computerC <<endl<<endl;
    
            // if user and computer are tie, try again
            if(userC == computerC){
                cout << "Tie!" << endl;
            }
            else if((userC == "rock" && computerC == "scissors") ||
                    (userC == "scissors" && computerC == "paper") ||
                    (userC == "paper" && computerC == "rock")){
                cout << "You won! Great job!" << endl;
                cout << "You fixed the leak!" << endl;
                cout << "      *****    " << endl;
				cout << "    *       *  " << endl;
				cout << "   *  LEAK   * " << endl;
				cout << "   *  SEALED * " << endl;
				cout << "    *       *  " << endl;
				cout << "      *****    " << endl;
				cout<<"\n";
                return;
            }
            else{
                cout << "You lost! Try one more time..." << endl;
            }
        }
        catch(const string& error){
            cout << error << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
