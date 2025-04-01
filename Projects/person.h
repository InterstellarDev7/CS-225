/****************************************************************************
* File:   person.h
* Author:   Devin Trujillo
* Purpose:  User Status: Health, Oxygen, and Hunger
*******************************************************************************/
#ifndef PERSON_H 
#define PERSON_H 

#include <iostream>
#include <cstring>
using namespace std;

class UserStatus {
private:
    int userHunger;
    int userOxygen;
    int userHealth;

public:
    UserStatus(int hu, int ox, int he) : userHunger(hu), userOxygen(ox), userHealth(he) {} // Constructor sets initial values

    // Getter functions
    int getUserHunger() const { return userHunger; }
    int getUserOxygen() const { return userOxygen; }
    int getUserHealth() const { return userHealth; }

    // Setter functions
    void setUserHunger(int hunger) { userHunger = hunger; }
    void setUserOxygen(int oxygen) { userOxygen = oxygen; }
    void setUserHealth(int health) { userHealth = health; }

    void displayStatus();
    bool makeChoice();
};

/*
Function: displayStatus()
This function is used to display the Game Stats for user to see
*/
void UserStatus::displayStatus() {
    cout << "***************************************" << endl;
    cout << "Game Stats: " << endl << "Hunger = " << userHunger << "\nOxygen = " << userOxygen
         << "\nHealth = " << userHealth << endl;
    cout << "***************************************" << endl;
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
    userHunger = max(0, userHunger - 5); // Max keeps stats from going below zero, decreases by 2
    userOxygen = max(0, userOxygen - 5); // Max keeps stats from going below zero, decreases by 2

    if (userOxygen == 45){
        cout<<"You have 50 percent Oxygen left! Health now drops by 10." << endl;
    } else if (userOxygen <= 45) {
        userHealth = max(0, userHealth - 10); // Max keeps stats from going below zero, decreases by 15
    }

    if (userHunger == 35) {
        cout << "You have 40 percent Hunger left! Health now drops by 10." << endl;
    } else if(userHunger <= 35){ 
        userHealth = max(0, userHealth - 10); // Max keeps stats from going below zero, decreases by 10
    }

    if (userHealth == 0) {
        cout << "Your Health is too low.\nYou can no longer move and darkness takes over..." << endl;
        return false; // No more health means no more choices can be made, game ends
    }
    cout<<"\n";
    return true; // Still some health so more choices can be made
}
#endif
