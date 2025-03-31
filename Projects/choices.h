#include <iostream>
#include <person.h>

#include <power.cpp>
#include <communication.cpp>
#include <leak.cpp>
#include <randomTasks.cpp>
using namespace std;

class Choices{
    private:
        char choice; // Char for user choice option
        int level = 1; // Level of the game
    public:
        char errorHandling(){
            cout << "Invalid choice. Please enter 'a' 'b' 'c' 'd' 'e' or 'f'." << endl; //Error message and reprompt
            cin >> choice; //Take user input
        }
    /* Function to display and choose a choice */
    void selectChoice(UserStatus &player){ // Function to select a choice
        while(player.makeChoice() || level < 6){ // While a user still has health or the game is not over
            switch(level){
                case 1: // Beginning of the game
                    cout << "Choices\n(a) Fix power\n(b) Fix communcations\n(c) Fix leak\n(d) Keep sleeping\n(e) Eat some food\n(f) Read a book\n"; // Prompt choice to choose
                    cin >> choice; // Take user input

                    if(choice == 'a' || choice == 'b'|| choice == 'c' || choice == 'd' || choice == 'e' || choice == 'f'){ // If a choice is chosen
                        if(choice == 'a'){ // If the choice is to fix power
                            cout << "You decided to fix power. You will now have to successfully complete the challenge to fix power." << endl;
                            fixPower(); // Call power mini game
                            cout << "You fixed the power. You are now a certified electrician." << endl;
                            player.userHunger -= 10; // Decrease hunger by 10
                            player.userOxygen -= 10; // Decrease oxygen by 10
                            player.userHealth -= 10; // Decrease health by 10
                            level = 2; // Increment level
                        }
                        else if(choice == 'b'){ // If the choice is to fix communications
                            cout << "You can not fix communications without power yet!" << endl;
                            player.userHunger -= 10;
                            player.userOxygen -= 10;
                            player.userHealth -= 10;
                        }
                        else if(choice == 'c'){ // If the choice is to fix leak
                            cout << "You can not fix the leak yet!" << endl;
                            player.userHunger -= 10;
                            player.userOxygen -= 10;
                            player.userHealth -= 10;
                        }
                        else if(choice == 'd'){ // If the choice is to sleep
                            sleep(); // Call sleep function
                            player.userHunger -= 20;
                            player.userOxygen -= 5;
                            player.userHealth += 5;
                        }
                        else if(choice == 'e'){ // If the choice is to eat food
                            eatFood(); // Call eat food function
                            player.userHunger += 10;
                            player.userOxygen -= 20;
                            player.userHealth += 5;
                        }
                        else if(choice == 'f'){ // If the choice is to read a book
                            readBook(); // Call read book function
                            player.userHunger -= 20;
                            player.userOxygen -= 20;
                            player.userHealth -= 20;
                        }
                    }
                    else{ //Error handling
                        errorHandling();
                    }
                case 2: //After fixing power
                    cout << "Choices\n(a) Fix communcations\n(b) Fix leak\n(c) Scroll on YouTube\n(d) Listen to music\n(e) Watch a movie\n";
                    cin >> choice;

                    if(choice == 'a' || choice == 'b'|| choice == 'c' || choice == 'd' || choice == 'e'){
                        if(choice == 'a'){ // If the choice is to fix communications
                            fixComms comms;
                            cout << "You decided to fix communications. You turn on the main power switch inside the ISS. You will now have to successfully complete the challenge to fix communications." << endl;
                            comms.playTicTacToe(); // Call communications mini game
                            cout << "You fixed the communications. You are now a certified computer engineer." << endl;
                            player.userHunger -= 10;
                            player.userOxygen -= 10;
                            player.userHealth -= 10;
                            level = 3; // Increment level
                        }
                        else if(choice == 'b'){ // If the choice is to fix leak
                            cout << "You can not fix the leak without communications!" << endl;
                            player.userHunger -= 10;
                            player.userOxygen -= 10;
                            player.userHealth -= 10;
                        }
                        else if(choice == 'c'){ // If the choice is to scroll on YouTube
                            scrollYouTube(); // Call scroll YouTube function
                            player.userHunger -= 20;
                            player.userOxygen -= 20;
                            player.userHealth -= 20;
                        }
                        else if(choice == 'd'){ // If the choice is to listen to music
                            listenMusic(); // Call listen music function
                            player.userHunger -= 20;
                            player.userOxygen -= 20;
                            player.userHealth -= 20;
                        }
                        else if(choice == 'e'){ // If the choice is to watch a movie
                            watchMovie(); // Call watch movie function
                            player.userHunger -= 20;
                            player.userOxygen -= 20;
                            player.userHealth -= 20;
                        }
                    }
                    else{ // Error handling
                        errorHandling();
                    }
                case 3: // After fixing communications
                    cout << "Choices\n(a) Fix leak\n(b) Video call your family\n(c) Livestream on Twitch\n(d) Post a tweet";
                    cin >> choice;

                    if(choice == 'a' || choice == 'b'|| choice == 'c' || choice == 'd'){
                        if(choice == 'a'){ // If the choice is to fix leak
                            cout << "You decided to fix the leak. JPL will give you the instructions on how to fix the leak. But first, you have to successfully complete the challenge to fix the leak." << endl;
                            fixLeak(); // Call leak mini game
                            cout << "You fixed the leak. You are now a certified plumber." << endl;
                            player.userHunger -= 10;
                            player.userOxygen -= 10;
                            player.userHealth -= 10;
                            level = 4; // Increment level
                        }
                        else if(choice == 'b'){ // If the choice is to video call family
                            videoCallFamily(); // Call video call family function
                            player.userHunger -= 20;
                            player.userOxygen -= 20;
                            player.userHealth -= 20;
                        }
                        else if(choice == 'c'){ // If the choice is to livestream on Twitch
                            livestream(); // Call livestream function
                            player.userHunger -= 20;
                            player.userOxygen -= 20;
                            player.userHealth -= 20;
                        }
                        else if(choice == 'd'){ // If the choice is to post a tweet
                            tweet(); // Call tweet function
                        }
                    }
                    else{
                        errorHandling();
                    }
                case 5: // Before fixing leak
                    cout << "Choices\n(a) Fix leak\n(b) Make a TikTok\n(c) Eat a victory meal\n(d) Play around with the wrench\n";
                    cin >> choice;

                    if(choice == 'a' || choice == 'b'|| choice == 'c' || choice == 'd'){
                        if(choice == 'a'){ // If the choice is to fix leak
                            cout << "You decided to fix the leak. JPL will give you the instructions on how to fix the leak. But first, you have to successfully complete the challenge to fix the leak." << endl;
                            fixLeak(); // Call leak mini game
                            cout << "You fixed the leak. You are now a certified plumber." << endl;
                            level = 6; // Increment level
                        }
                        else if(choice == 'b'){ // If the choice is to make a TikTok
                            makeTikTok(); // Call make TikTok function
                            player.userHunger -= 20;
                            player.userOxygen -= 20;
                            player.userHealth -= 20;
                        }
                        else if(choice == 'c'){ // If the choice is to eat a victory meal
                            victoryMeal(); // Call eat victory meal function
                            player.userHunger += 20;
                            player.userOxygen -= 20;
                            player.userHealth -= 20;
                        }
                        else if(choice == 'd'){ // If the choice is to play around with the wrench
                            playWithWrench(); // Call play with wrench function
                            player.userHunger -= 20;
                            player.userOxygen -= 30;
                            player.userHealth -= 20;
                        }
                    }
                    else{
                        errorHandling();
                    }
            } // End of switch statement
        } // End of while loop
    } // End of selectChoice() function
}; // End of class