/****************************************************************************
* File:   person.h
* Author:   Devin Trujillo
* Purpose:  User Status: Health, Oxygen, and Hunger
*******************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

class UserStatus{
    private:
        int userHunger;
        int userOxygen;
        int userHealth;
    public:
        UserStatus(int hu, int ox, int he):userHunger(hu), userOxygen(ox), userHealth(he){} //Constructor Sets initial values
        void displayStatus();
        bool makeChoice();
};

/*
Function: displayStatus()
This function is used to display the Game Stats for user to see
*/
void UserStatus::displayStatus(){
    cout<<"***************************************"<<endl;
    cout<<"Game Stats: "<<endl<<"Hunger = "<<userHunger<<"\nOxygen = "<<userOxygen
    <<"\nHealth = "<<userHealth<<endl;
    cout<<"***************************************"<<endl;
}

/*
Function: makeChoice() 
If user still has health (return true), This function decreases the Oxygen and Hunger Stats for 
each choice the user makes.
Once Oxygen reaches or gets below 50, Health decreases by 15
Once Hunger reaches or gets below 30, Hunger decreases by 10
Once Health reaches zero (return false), game ends and user "dies".
*/
bool UserStatus::makeChoice() {
    userHunger = max(0, userHunger - 2); // Max keeps stats from going below zero, decreases by 2
    userOxygen = max(0, userOxygen - 2); // Max keeps stats from going below zero, decreases by 2

    if (userOxygen <= 50 ) {
        userHealth = max(0, userHealth - 15); // Max keeps stats from going below zero, decreases by 15
        cout << "You have less than 50 percent Oxygen left! Health now drops by 15." << endl;
    } 
    
    if (userHunger <= 30 ) {
        userHealth = max(0, userHealth - 10); // Max keeps stats from going below zero, decreases by 10
        cout << "You have less than 40 percent Hunger left! Health now drops by 10." << endl;
    }
    
    if (userHealth == 0) {
        displayStatus();
        cout << "You have run out of health :(" << endl;
        return false; //No more health means no more choices can be made, game ends
    }

    cout << "Stats updated." << endl;
    displayStatus();
    return true; //Still some health so more choices can be made
}


