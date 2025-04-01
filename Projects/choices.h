#ifndef CHOICES_H 
#define CHOICES_H 

#include <iostream>
#include <fstream>
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
        /* Constructor */
        Choices(UserStatus &player){
            player.displayStatus(); // Displays initial status values
        }

        /* Destructor */
        ~Choices(){
            cout << "You can not make any choices anymore." << endl;
        }

        /* Function to write a congratulations certificate to a file */
        void writeCertificate(){
            ofstream outFile("Congratulations_Certificate.txt"); // Create and open a file
            if(outFile.is_open()){
                outFile << "***************************************\n";
                outFile << "          CONGRATULATIONS!             \n";
                outFile << "***************************************\n";
                outFile << "You have successfully completed the game!\n";
                outFile << "Your hard work and determination have\n";
                outFile << "saved the ISS and its crew. Great job!\n";
                outFile << "***************************************\n";
                outFile << "          CERTIFICATE OF SUCCESS       \n";
                outFile << "***************************************\n";
                outFile.close(); // Close the file
                cout << "Congratulations! A certificate has been written to 'Congratulations_Certificate.txt'.\n";
            } else {
                cout << "Error: Unable to write the certificate to a file.\n";
            }
        }
        
        char errorHandling(){
            cout << "Invalid choice. Please enter 'a' 'b' 'c' 'd' 'e' or 'f'." << endl; // Error message and reprompt
            cin >> this->choice; // Take user input
            return this->choice; // Return the user's corrected input
        }

        /* Overloaded ++ operator */
        Choices& operator++(){
            level++; // Increment level
            return *this;
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
                                ++(*this); // Increment level
                            }
                            else if(choice == 'b'){ // If the choice is to fix communications
                                cout << "You can not fix communications without power yet!" << endl;
                            }
                            else if(choice == 'c'){ // If the choice is to fix leak
                                cout << "You can not fix the leak yet!" << endl;
                            }
                            else if(choice == 'd'){ // If the choice is to sleep
                                sleep(); // Call sleep function
                            }
                            else if(choice == 'e'){ // If the choice is to eat food
                                eatFood(); // Call eat food function
                                player.setUserHunger(player.getUserHunger() + 10);  // Increase hunger by 10
                            }
                            else if(choice == 'f'){ // If the choice is to read a book
                                readBook(); // Call read book function
                            }
                        }
                        else{ //Error handling
                            choice = errorHandling();
                        }
                        player.displayStatus();
                        break;
                    
                    case 2: // After fixing power
                        cout << "Choices\n(a) Fix communications\n(b) Fix leak\n(c) Scroll on YouTube\n(d) Listen to music\n(e) Watch a movie\n";
                        cin >> choice;

                        if(choice == 'a'){ 
                            cout << "You turn on the main power switch inside the ISS." << endl;
                            startCommunicationMiniGame(); // Call communications mini game
                            ++(*this); // Increment level
                        }
                        else if(choice == 'b'){ 
                            cout << "You can not fix the leak without communications!" << endl;
                        }
                        else if(choice == 'c'){ 
                            scrollYouTube(); 
                        }
                        else if(choice == 'd'){ 
                            listenMusic(); 
                        }
                        else if(choice == 'e'){ 
                            watchMovie(); 
                        }
                        else{ 
                            choice = errorHandling();
                        }
                        player.displayStatus();
                        break;
                    
                    case 3: // After fixing communications
                        cout << "Choices\n(a) Call JPL \n(b) Video call your family\n(c) Livestream on Twitch\n(d) Post a tweet\n";
                        cin >> choice;

                        if(choice == 'a'){ 
                            cout << "You call JPL and they give you instructions on how to fix the leak." << endl;
                            ++(*this); 
                        }
                        else if(choice == 'b'){ 
                            familyPicture(); 
                        }
                        else if(choice == 'c'){ 
                            liveStream(); 
                        }
                        else if(choice == 'd'){ 
                            tweet(); 
                        }
                        else{
                            choice = errorHandling();
                        }
                        player.displayStatus();
                        break;
                    
                    case 4: // Before fixing leak
                        cout << "Choices\n(a) Fix leak\n(b) Make a TikTok\n(c) Eat a victory meal\n(d) Play around with the wrench\n";
                        cin >> choice;

                        if(choice == 'a'){ 
                            fixLeak(); // Call leak mini game
                            writeCertificate(); // Write the congratulations certificate
                            cout << "You have successfully completed the game! Well done!" << endl;
                            return; // END GAME
                        }
                        else if(choice == 'b'){ 
                            makeTikTok(); 
                        }
                        else if(choice == 'c'){ 
                            victoryMeal(); 
                            player.setUserHunger(player.getUserHunger() + 10); 
                        }
                        else if(choice == 'd'){ 
                            playDrums(); 
                        }
                        else{
                            choice = errorHandling();
                        }
                        player.displayStatus();
                        break;   
                }
            }
        }
};

#endif
