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
#include <algorithm> // For handling case-insensitive input
#include "leak.h"

using namespace std;

void fixLeak() {
    cout << "To fix the leak, you need to complete the mini-game!" << endl;
    cout << "Let's start the game!" << endl;
    cout << "********* Welcome to Rock, Scissors, Paper *********" << endl;
    cout << "To fix the leak, you must win a game." << endl;
    cout << "**************************************************\n" << endl;

    string choices[3] = {"rock", "scissors", "paper"};
    string userChoice, computerChoice;

    srand(time(0));

    while (true) {
        try {
            cout << "Enter your choice ('rock', 'scissors', or 'paper'): ";
            cin >> userChoice;

            // Convert user input to lowercase for case-insensitivity
            transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::tolower);

            // If user input wrong option, user can input again until it's valid
            if (userChoice != "rock" && userChoice != "scissors" && userChoice != "paper") {
                throw invalid_argument("ERROR: Invalid option. Please enter 'rock', 'scissors', or 'paper'.\n");
            }

            // if user and computer are tie, try again
            int randomChoice = rand() % 3;
            computerChoice = choices[randomChoice];
            cout << "Computer choice => " << computerChoice << endl << endl;

            // Check result
            if (userChoice == computerChoice) {
                cout << "Tie! Try again." << endl;
            } else if ((userChoice == "rock" && computerChoice == "scissors") ||
                       (userChoice == "scissors" && computerChoice == "paper") ||
                       (userChoice == "paper" && computerChoice == "rock")) {
                cout << "You won! Great job!" << endl;
                cout << "You fixed the leak!" << endl;
                cout << "      *****    " << endl;
                cout << "    *       *  " << endl;
                cout << "   *  LEAK   * " << endl;
                cout << "   *  SEALED * " << endl;
                cout << "    *       *  " << endl;
                cout << "      *****    " << endl;
                cout << "\n";
                return;  // Exit function after winning
            } else {
                cout << "You lost! Try again..." << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what(); 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
