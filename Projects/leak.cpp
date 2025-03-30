/******************************************************************************
* File: leak.cpp
* Author: Hyeonjin Park
* Purpose: Fixing Leak
*******************************************************************************/
#include <choices.h>
#include <person.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <limits>

using namespace std;

void fixLeak() {
    // user chose to fix leak first
    cout << "You decided to fix the leak." << endl;
    cout << "As you find the leak, you realized that you don't have tools to fix the leak." << endl;
    cout << "You need to communicate with the station to get some advice..." << endl;
    cout << "Go to fix the communication and come back!" << endl;
    
    /*redirect to fix comms first
    fixCommunication();
    */
    
    // return to fixing the leak -> mini game
    cout << "\n\nNow communication is fixed." << endl;
    cout << "You contacted the station and got advice on how to fix the leak." << endl;
    cout << "To fix the leak, you need to complete the mini game!" << endl;
    cout << "Let's start the game!" << endl;
    cout << "*********Welcome to Rock, Scissors, Paper*********" << endl;
    cout << "To fix the leak, you must win a game." << endl;
    
    string threeChoice[3] = {"rock", "scissors", "paper"};
    string userC;
    string computerC;
    
    srand(time(0));
    
    while (true) {
        try {
            cout << "Enter your choice => ";
            cin >> userC;
            
            const string ERROR = "ERROR: Invalid option. Try again...";

	        // If user input wrong option, user can input again until it's valid
	        if (userC != "rock" && userC != "scissors" && userC != "paper") {
	            throw ERROR;
	        }
        
            // random choice between rock, scissors, and paper
            int randomChoice = rand() % 3;
        
            computerC = threeChoice[randomChoice];
            cout << "Program choice => " << computerC << endl;
        
            /* if user and computer are tie, try again
            if user wins, complete fixing leak
            if user lose, try again
	        */

            if (userC == computerC) {
                cout << "Tie!" << endl;
            } else if ((userC == "rock" && computerC == "scissors") ||
                    (userC == "scissors" && computerC == "paper") ||
                    (userC == "paper" && computerC == "rock")) {
                cout << "You won! Great job!" << endl;
	        cout << "You fixed the leak." << endl;
                return;
            } else {
                cout << "You lost! Try one more time..." << endl;
            }
            

        } catch (const string& error) {
            cout << error << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue; // prompt user to try again.
        }
    }
}

int main() {
    fixLeak();
    return 0;
}
    
