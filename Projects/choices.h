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

class Choices {
private:
    char choice;
    int level = 1;

public:
    /* Constructor */
    Choices(UserStatus &player){
        player.displayStatus();
    }

    /* Destructor */
    ~Choices(){
        cout << "You can not make any choices anymore." << endl;
    }

    /* Function to handle invalid input */
    char errorHandling(){
        cout << "Invalid choice. Please enter 'a' 'b' 'c' 'd' 'e' or 'f'." << endl;
        cin >> this->choice;
        return this->choice;
    }

    /* Overloaded ++ operator */
    Choices& operator++(){
        level++;
        return *this;
    }

    /* Function to select choices */
    void selectChoice(UserStatus &player) {
        while (player.makeChoice() && level < 5) {
            switch (level) {
                case 1:
                    cout << "Choices\n(a) Fix power\n(b) Fix communcations\n(c) Fix leak\n(d) Keep sleeping\n(e) Eat some food\n(f) Read a book\n";
                    cin >> choice;

                    if (choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd' || choice == 'e' || choice == 'f') {
                        if (choice == 'a') {
                            fixPower();
                            ++(*this);
                        } else if (choice == 'b') {
                            cout << "You can not fix communications without power yet!" << endl;
                        } else if (choice == 'c') {
                            cout << "You can not fix the leak yet!" << endl;
                        } else if (choice == 'd') {
                            sleep();
                        } else if (choice == 'e') {
                            eatFood();
                            player.setUserHunger(player.getUserHunger() + 10);
                        } else if (choice == 'f') {
                            readBook();
                        }
                    } else {
                        choice = errorHandling();
                    }
                    player.displayStatus();
                    break;

                case 2:
                    cout << "Choices\n(a) Fix communications\n(b) Fix leak\n(c) Scroll on YouTube\n(d) Listen to music\n(e) Watch a movie\n";
                    cin >> choice;

                    if (choice == 'a') {
                        cout << "You turn on the main power switch inside the ISS." << endl;
                        startCommunicationMiniGame();
                        ++(*this);
                    } else if (choice == 'b') {
                        cout << "You can not fix the leak without communications!" << endl;
                    } else if (choice == 'c') {
                        scrollYouTube();
                    } else if (choice == 'd') {
                        listenMusic();
                    } else if (choice == 'e') {
                        watchMovie();
                    } else {
                        choice = errorHandling();
                    }
                    player.displayStatus();
                    break;

                case 3:
                    cout << "Choices\n(a) Call JPL \n(b) Video call your family\n(c) Livestream on Twitch\n(d) Post a tweet\n";
                    cin >> choice;

                    if (choice == 'a') {
                        cout << "You call JPL and they give you instructions on how to fix the leak." << endl;
                        ++(*this);
                    } else if (choice == 'b') {
                        familyPicture();
                    } else if (choice == 'c') {
                        liveStream();
                    } else if (choice == 'd') {
                        tweet();
                    } else {
                        choice = errorHandling();
                    }
                    player.displayStatus();
                    break;

                case 4:
                    cout << "Choices\n(a) Fix leak\n(b) Make a TikTok\n(c) Eat a victory meal\n(d) Play around with the wrench\n";
                    cin >> choice;

                    if (choice == 'a') {
                        fixLeak();
                        cout << "You have successfully completed the game! Well done!" << endl;
                        return;
                    } else if (choice == 'b') {
                        makeTikTok();
                    } else if (choice == 'c') {
                        victoryMeal();
                        player.setUserHunger(player.getUserHunger() + 10);
                    } else if (choice == 'd') {
                        playDrums();
                    } else {
                        choice = errorHandling();
                    }
                    player.displayStatus();
                    break;
            }
        }
    }
};

#endif
