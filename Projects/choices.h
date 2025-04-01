#ifndef CHOICES_H 
#define CHOICES_H 

#include <iostream>
#include "person.h"
#include "power.h"
#include "communication.h"
#include "leak.h"
#include "randomTasks.h"
using namespace std;

class Choices{
    private:
        char choice; // Char for user choice option
        int level = 1; // Level of the game
    public:
         /*person.h*/
        Choices(UserStatus &player){
            player.displayStatus(); // Displays initial status values
        }

        // Choices destructor
        ~Choices(){
            cout << "You can not make any choices anymore." << endl;
        }
        
        char errorHandling(){
            cout << "Invalid choice. Please enter 'a' 'b' 'c' 'd' 'e' or 'f'." << endl; //Error message and reprompt
            cin >> choice; //Take user input
            return choice; // Return the user's corrected input
        }

        /* Overloaded ++ operator */
        void operator ++ () {
            level++; // Increment level
        }
        
        /* Function to display and choose a choice */
        void selectChoice(UserStatus &player){ // Function to select a choice
            while(player.makeChoice() && level < 5){ // While a user still has health or the game is not over
                switch(level){
                    case 1: // Beginning of the game
                        cout << "Choices\n(a) Fix power\n(b) Fix communcations\n(c) Fix leak\n(d) Keep sleeping\n(e) Eat some food\n(f) Read a book\n"; // Prompt choice to choose
                        cin >> choice; // Take user input

                        if(choice == 'a' || choice == 'b'|| choice == 'c' || choice == 'd' || choice == 'e' || choice == 'f'){ // If a choice is chosen
                            if(choice == 'a'){ // If the choice is to fix power
                                fixPower(); // Call power mini game
                                level++; // Increment level
                            } else if(choice == 'b'){ // If the choice is to fix communications
                                cout << "You can not fix communications without power yet!" << endl;
                            } else if(choice == 'c'){ // If the choice is to fix leak
                                cout << "You can not fix the leak yet!" << endl;
                            } else if(choice == 'd'){ // If the choice is to sleep
                                sleep(); // Call sleep function
                            } else if(choice == 'e'){ // If the choice is to eat food
                                eatFood(); // Call eat food function
                                player.setUserHunger(player.getUserHunger() + 10);  // Increase hunger by 10
                            } else if(choice == 'f'){ // If the choice is to read a book
                                readBook(); // Call read book function
                            }
                        } else{ //Error handling
                            choice = errorHandling();
                        }
                        player.displayStatus();
                        break;
                        
                    case 2: //After fixing power
                        cout << "Choices\n(a) Fix communcations\n(b) Fix leak\n(c) Scroll on YouTube\n(d) Listen to music\n(e) Watch a movie\n";
                        cin >> choice;

                        if(choice == 'a' || choice == 'b'|| choice == 'c' || choice == 'd' || choice == 'e'){
                            if(choice == 'a'){ // If the choice is to fix communications
                                cout << "You turn on the main power switch inside the ISS." << endl;
                                startCommunicationMiniGame();// Call communications mini game
                                level++;; // Increment level
                            } else if(choice == 'b'){ // If the choice is to fix leak
                                cout << "You can not fix the leak without communications!" << endl;
                            } else if(choice == 'c'){ // If the choice is to scroll on YouTube
                                scrollYouTube(); // Call scroll YouTube function
                            } else if(choice == 'd'){ // If the choice is to listen to music
                                listenMusic(); // Call listen music function
                            } else if(choice == 'e'){ // If the choice is to watch a movie
                                watchMovie(); // Call watch movie function
                            }
                        }else{ // Error handling
                            choice = errorHandling();
                        }
                        player.displayStatus();
                        break;
                        
                    case 3: // After fixing communications
                        cout << "Choices\n(a) Call JPL \n(b) Video call your family\n(c) Livestream on Twitch\n(d) Post a tweet\n";
                        cin >> choice;

                        if(choice == 'a' || choice == 'b'|| choice == 'c' || choice == 'd'){
                            if(choice == 'a'){ // If the choice is to fix leak
                                cout<<"You call JPL and they give you instructions on how to fix the leak."<<endl;
                                level++;; // Increment level
                            } else if(choice == 'b'){ // If the choice is to video call family
                                familyPicture(); // Call video call family function
                            } else if(choice == 'c'){ // If the choice is to livestream on Twitch
                                liveStream(); // Call livestream function
                            } else if(choice == 'd'){ // If the choice is to post a tweet
                                tweet(); // Call tweet function
                            }
                        }else{
                            choice = errorHandling();
                        }
                        player.displayStatus();
                        break;
                        
                    case 4: // Before fixing leak
                        cout << "Choices\n(a) Fix leak\n(b) Make a TikTok\n(c) Eat a victory meal\n(d) Play around with the wrench\n";
                        cin >> choice;

                        if(choice == 'a' || choice == 'b'|| choice == 'c' || choice == 'd'){
                            if(choice == 'a'){ // If the choice is to fix leak
                                fixLeak(); // Call leak mini game
                                return; // END GAME
                            } else if(choice == 'b'){ // If the choice is to make a TikTok
                                makeTikTok(); // Call make TikTok function
                            } else if(choice == 'c'){ // If the choice is to eat a victory meal
                                victoryMeal(); // Call eat victory meal function
                                player.setUserHunger(player.getUserHunger() + 10);  // Increase hunger by 10
                            } else if(choice == 'd'){ // If the choice is to play around with the wrench
                                playDrums(); // Call play with wrench function
                            }
                        }else{
                            choice = errorHandling();
                        }
                        player.displayStatus();
                        break;
                        
                } // End of switch statement
            } // End of while loop
        } // End of selectChoice() function
}; // End of class

#endif
