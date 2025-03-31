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
    

    return 0;
}
