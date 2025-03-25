/******************************************************************************
* File: power.cpp
* Author: Hyeonjin Park
* Purpose: Fixing power
*******************************************************************************/
#include "Choices.h"
#include "Person.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void fixPower() {

    srand(time(0));

    /* 
    To fix the power, user has to complete the mini game
    If user fail, program asks if user wants to try again
    */
    
    while (true) {
        cout << "You decided to fix the power." << endl;
        cout << "To fix the power, you need to complete the mini game! ";
        cout << "Let's start the game!" << endl << endl;
    
	// Start the mini game to fix the power
        cout << "*********Welcome to Guess the Number*********" << endl;
        cout << "The program will randomly select a number between 1 and 50!\n";
        cout << "You will input your guess.\n";
        cout << "BUT you only have 10 attempts.\n";
        cout << "Good Luck >.<" << endl;
        cout << "*********************************************" << endl << endl;
    	
	//generate the random number between 1 and 50
        int randomNumber = rand() % 50 + 1;
        int attempt = 0;
        int userInput;
        const int maxAttempts = 10;
    
        while (attempt < maxAttempts) {
            cout << "You have " << (maxAttempts - attempt) << " attempts.\n";
            cout << "Enter your guess: ";
            cin >> userInput;
            attempt++;
        
            if (userInput < randomNumber) {
                cout << "Low!! Please try again!\n";
            } else if (userInput > randomNumber) {
                cout << "High!! Please try again!\n";
            } else {
                cout << "Congratulations! You guessed the number in " << attempt << " attempts!" << endl;
                cout << "Power restored successfully!\n";
                return;
            }
        }
        
        cout << "You've used all your attempts... Power restoration failed...\n";
        cout << "Oxygen is slowly depleting...\n";
        

	//Ask user if they want to retry
        char choice;
        while(true) {
            cout << "You still need to fix the power. Do you want to try again? (y / n)";
            cin >> choice;
            if (choice == 'N' || choice == 'n') {
                cout << "Are you sure? If the power still remains off, you will eventually run out of oxygen and die.\n";
                cout << "Think carefully and choose again. (y / n)";
                cin >> choice;
		if (choice == 'N' || choice == 'n') {
		    cout << "You decided not to fix the power. Oxygen is slowly depleting...\n";
		    return;
		}
            } else if (choice == 'Y' || choice == 'y') {
                cout << "Great! Start the game again....." << endl << endl;
                break;
            } else {
                cout << "Invalid input. Please re-enter y or n.\n";
            }
        }   
    }
}

