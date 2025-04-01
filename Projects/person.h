#ifndef PERSON_H 
#define PERSON_H 

#include <iostream>
#include <cstring>
using namespace std;

// Base class Player to manage health
class Player{
protected:
    int health; // Shared variable for all players

public:
    Player(int h) : health(h) {} // Constructor to initialize health

    // Getter and setter for health
    int getHealth() const { return health; }
    void setHealth(int h) { health = max(0, h); } // Ensure health is not negative
};

// GameStats class to manage hunger and oxygen
class GameStats{
private:
    int hunger;
    int oxygen;

public:
    GameStats(int hu, int ox) : hunger(hu), oxygen(ox) {}

    // Getters
    int getHunger() const { return hunger; }
    int getOxygen() const { return oxygen; }

    // Setters
    void setHunger(int hu) { hunger = max(0, hu); }
    void setOxygen(int ox) { oxygen = max(0, ox); }
};

// UserStatus inherits from Player and contains GameStats
class UserStatus : public Player{
private:
    GameStats stats; // UserStatus has a GameStats object

public:
    UserStatus(int hu, int ox, int he) : Player(he), stats(hu, ox) {}

    // Getter functions for accessing stats
    int getUserHunger() const { return stats.getHunger(); }
    int getUserOxygen() const { return stats.getOxygen(); }
    int getUserHealth() const { return getHealth(); } 

    // Setter functions for modifying stats
    void setUserHunger(int hu) { stats.setHunger(hu); }
    void setUserOxygen(int ox) { stats.setOxygen(ox); }
    void setUserHealth(int he) { setHealth(he); }

    void displayStatus();
    bool makeChoice();
};

/*
Function: displayStatus()
Displays the user's stats.
*/
void UserStatus::displayStatus(){
    cout << "***************************************" << endl;
    cout << "Game Stats: " << endl 
         << "Hunger = " << getUserHunger() 
         << "\nOxygen = " << getUserOxygen()
         << "\nHealth = " << getUserHealth() << endl;
    cout << "***************************************" << endl;
}

/*
Function: makeChoice() 
Updates hunger, oxygen, and health as choices are made.
*/
bool UserStatus::makeChoice() {
    setUserHunger(getUserHunger() - 5);
    setUserOxygen(getUserOxygen() - 5);

    if(getUserOxygen() == 45){
        cout << "You have 50 percent Oxygen left! Health now drops by 10." << endl;
    }
    else if(getUserOxygen() <= 45){
        setUserHealth(getUserHealth() - 10);
    }

    if(getUserHunger() == 35){
        cout << "You have 40 percent Hunger left! Health now drops by 10." << endl;
    }
    else if(getUserHunger() <= 35){
        setUserHealth(getUserHealth() - 10);
    }

    if(getUserHealth() == 0){
        cout << "Your Health is too low. Darkness takes over...." << endl;
        return false;
    }
    cout << "\n";
    return true;
}

#endif