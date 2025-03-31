#include <iostream>
#include "startup.h"
#include "person.h"
using namespace std;

int main(){
/*Startup.h*/
    Start s;
    s.displayStart();
    
/*person.h*/ /* This would be in choices.h*/
    UserStatus player(100, 100, 100); //Sets initial status values
    player.displayStatus(); //Displays initial status values
    
    char choice; // Char for user choice option
    while (true) { // While a user still has health
        cout << "choice a/b/c: "; //Prompt choice to choose
        cin >> choice; //Take user input

        if (choice == 'a' || choice == 'b'|| choice =='c') { // If a choice is chosen
            if (!player.makeChoice()) { //Once user runs out of health
                cout << "Game Over! \nThank you for Playing!" << endl; //End message
                break; //Stop code 
            }
        } else { //Error handling
            cout << "Invalid choice. Please enter 'a' 'b' or 'c'." << endl; //Error message and reprompt
        }
    }

    return 0;
}
