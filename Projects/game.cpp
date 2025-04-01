#include <iostream>
#include "startup.h"
#include "choices.h"
#include "person.h"
using namespace std;

int main(){
    /*Startup.h*/
    Start s;
    s.displayStart();
    
    /*person.h*/ 
    UserStatus player(100, 100, 100); // Sets initial status values

    /*choices.h*/
    Choices playerChoices(player);  // Pass the player to the Choices constructor
    playerChoices.selectChoice(player);  // Calls the game loop for selecting actions
    
    return 0;
}