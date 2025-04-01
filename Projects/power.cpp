/******************************************************************************
* File: power.cpp
* Author: Hyeonjin Park
* Purpose: Fixing power
*******************************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <string>
#include "power.h"
using namespace std;

void fixPower(){

	srand(time(0));

	cout << "You decided to fix the power." << endl;
	cout << "To fix the power, you need to complete the mini game! ";
	cout << "Let's start the game!" << endl << endl;

	/*
	To fix the power, user has to complete the mini game
	If user fail, program asks if user wants to try again
	*/
	while(true){
		try{
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
			const string MSG1 = "ERROR: Invalid input. Please type again...";
			const string MSG2 = "ERROR: Please Type (y / n)..." ;

			// start gussing game loop
			while(attempt < maxAttempts){
				cout << "\nYou have " << (maxAttempts - attempt) << " attempts.\n";
				cout << "Enter your guess: ";


				// check invalid input
				if(!(cin >> userInput)){
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << MSG1 << endl;
					continue; // just ask for input again

				}
				attempt++;

				if(userInput < randomNumber){
					cout << "\nLow!! Please try again!\n";
				}
				else if(userInput > randomNumber){
					cout << "\nHigh!! Please try again!\n";
				}
				else{
					cout << "Congratulations! You guessed the number in " << attempt << " attempts!" << endl;
					cout << "Power restored successfully!\n";
					cout << "      *****    " << endl;
					cout << "    *       *  " << endl;
					cout << "   *  POWER  * " << endl;
					cout << "   *   ON    * " << endl;
					cout << "    *       *  " << endl;
					cout << "      *****    " << endl;
					cout<<"\n";
					return;
				}
			}

			cout << "You've used all your attempts... Power restoration failed...\n";
			cout << "Oxygen is slowly depleting...\n";
			cout << "You still need to fix the power." << endl;
			//Ask user if they want to retry
			char choice;
			while(true){
				try{
					cout << "Do you want to try again (y / n)? ";

					if(!(cin >> choice)){
						cin.clear();
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						throw MSG2;
					}
					
				    choice = tolower(choice);
				    
					if(choice == 'n'){
						cout << "Are you sure? If the power still remains off, you will eventually run out of oxygen and die.\n";
						cout << "Think carefully and choose again. (y / n) ";

						if(!(cin >> choice)){
							cin.clear();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							throw MSG2;
						}
						choice = tolower(choice);
						if(choice == 'n'){
							cout << "You decided not to fix the power. Oxygen is slowly depleting...\n";
							return;
							// return to choice selection -> add later
						}
					}
					else if(choice == 'Y' || choice == 'y'){
						cout << "Great! Start the game again....." << endl << endl;
						break;
					}
					else{
						throw MSG2;
					}

				}
				catch (const string& msg){
					cout << msg << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue; //prommpt user again
				}
			}
		}
		catch (const string& msg){
			cout << msg << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	}
}