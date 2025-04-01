#ifndef CHOICES_H
#define CHOICES_H

#include <iostream>
#include <fstream>
#include "power.h"
#include "communication.h"
#include "leak.h"
#include "randomTasks.h"
#include "person.h" // Include person.h to use UserStatus
using namespace std;

class Choices {
private:
    char choice; // Char for user choice option
    int level = 1; // Level of the game
    UserStatus &player; // Store reference to UserStatus object

    // Error handling function (fixes the missing function issue)
    char errorHandling(){
        cout << "Invalid input! Please enter a valid choice.\n";
        char newChoice;
        cin >> newChoice;
        return newChoice;
    }

public:
    /* Constructor initializes user status */
    Choices(UserStatus &playerRef) : player(playerRef){
        player.displayStatus(); // Displays initial status values
    }

    // Destructor
    ~Choices(){
        cout << "You can no longer make choices..." << endl;
    }

    /* Function to write a congratulations certificate */
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
            cout << "Congratulations! A certificate has been written to 'Congratulations_Certificate.txt' file.\n";
        }
        else{
            cout << "Error writing to file!" << endl;
        }
    }

    /* Overloaded ++ operator */
    void operator++(){
        level++; // Increment level
    }

    /* Function to display and choose a choice */
    void selectChoice(){ // No need to pass player since it's stored
        while(player.makeChoice() && level < 5){ // While user has health or game is not over
            switch(level){
                case 1: // Beginning of the game
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << "Choices\n(a) Fix power\n(b) Fix communications\n(c) Fix leak\n(d) Keep sleeping\n(e) Eat some food\n(f) Read a book\n";
                    cin >> choice;

                    if(choice == 'a'){
                        fixPower();
                        level++;
                    }
                    else if(choice == 'b'){
                        cout << "You cannot fix communications without power yet!" << endl;
                    }
                    else if(choice == 'c'){
                        cout << "You cannot fix the leak yet!" << endl;
                    }
                    else if(choice == 'd'){
                        sleep();
                    }
                    else if(choice == 'e'){
                        eatFood();
                        player.setUserHunger(player.getUserHunger() + 10);  // Increase hunger by 10
                    }
                    else if(choice == 'f'){
                        readBook();
                    }
                    else{
                        choice = errorHandling();
                    }
                    this_thread::sleep_for(chrono::seconds(8));
                    player.displayStatus();
                    break;

                case 2: // After fixing power
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << "Choices\n(a) Fix communications\n(b) Fix leak\n(c) Scroll on YouTube\n(d) Listen to music\n(e) Watch a movie\n";
                    cin >> choice;

                    if(choice == 'a'){
                        cout << "You turn on the main power switch inside the ISS." << endl;
                        startCommunicationMiniGame();
                        level++;
                    }
                    else if(choice == 'b'){
                        cout << "You cannot fix the leak without communications!" << endl;
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
                    this_thread::sleep_for(chrono::seconds(8));
                    player.displayStatus();
                    break;

                case 3: // After fixing communications
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << "Choices\n(a) Call JPL\n(b) Video call your family\n(c) Livestream on Twitch\n(d) Post a tweet\n";
                    cin >> choice;

                    if(choice == 'a'){
                        cout << "You call JPL and they give you instructions on how to fix the leak." << endl;
                        level++;
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
                    this_thread::sleep_for(chrono::seconds(8));
                    player.displayStatus();
                    break;

                case 4: // Before fixing leak
                    this_thread::sleep_for(chrono::seconds(2));
                    cout << "Choices\n(a) Fix leak\n(b) Make a TikTok\n(c) Eat a victory meal\n(d) Play around with the wrench\n";
                    cin >> choice;

                    if(choice == 'a'){
                        fixLeak();
                        writeCertificate();
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
                    this_thread::sleep_for(chrono::seconds(8));
                    player.displayStatus();
                    break;
            } // End of switch statement
        } // End of while loop
    } // End of selectChoice() function
}; // End of class

#endif