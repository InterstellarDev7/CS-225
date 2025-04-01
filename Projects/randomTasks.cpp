/****************************************************************************
* File:   randomTasks.cpp
* Author:   Dhanush Balusa
* Purpose:  Functions for random tasks in the game.
*******************************************************************************/
#include <iostream>
#include "randomTasks.h"
using namespace std;

/* Functions to waste time during the beginning */

    // Player continues to sleep
    void sleep(){
        cout << "You decide to go back to sleep and wasted 4 hours." << endl;
        cout << "But hey! At least you're feeling well rested..." << endl;
    }

    // Player eats food
    void eatFood(){
        cout << "Because of stress, you decide to eat 15 astronaut icecream :)" << endl;
    }

    // Player reads a book
    void readBook(){
        cout << "You decide to read a book about space. Great!" << endl;
        cout << "You are now an expert in astrophysics but have room for improvement with time management." << endl;
    }

/* Functions to waste time after restoring power */

    // Player scrolls on YouTube
    void scrollYouTube(){
        cout << "You are scrolling on YouTube. You see a video of a hamster playing the piano." << endl;
        cout << "You smile and keep scrolling for the next 4 hours. Instant gratification to the rescue..." << endl;
    }

    // Player listens to music
    void listenMusic(){
        cout << "You decide to listen to music. You are now dancing to Gangam Style." << endl;
        cout << "Would've been great if the cameras were recording right now, JPL would be falling off their chairs in ammusement..." << endl;
    }

    // Player watches a movie
    void watchMovie(){
        cout << "You decide to watch a movie. You are now watching The Martian." << endl;
        cout << "You are now feeling inspired and motivated to survive..." << endl;
    }

/* Functions to waste time after restoring communications*/

    // Creates a picture of a 4 person family and a dog using asky art (with *s)
    void familyPicture()
    {
        cout << "You video called your family: " << endl;
        cout << "     o     o     o     o    /\\_/\\ " << endl;
        cout << "    /|\\   /|\\   /|\\   /|\\  ( o.o )" << endl;
        cout << "    / \\   / \\   / \\   / \\   > ^ < " << endl;
        cout << "    Dad   Mom  Brother Sister   Cat" << endl;
        cout << "You feel better after seeing your family." << endl;
        cout << "But did you forget that you need to survive in order to go back home..." << endl;
    }

    // Player livestreams on Twitch
    void liveStream(){
        cout << "You decide to livestream Among Us on Twitch." << endl;
        cout << "You are now feeling like a pro gamer but you're still stuck in space..." << endl;
    }

    // Player tweets about the situation
    void tweet(){
        cout << "You decide to tweet about the situation. You are now trending on Twitter." << endl;
        cout << "You feel like a celebrity but hopefully you don't end up like Sunita Williams and Butch Wilmore..." << endl;
    }

/* Functions to waste time while fixing the oxygen leak */

    // Player makes a TikTok
    void makeTikTok(){
        cout << "You decide to make a TikTok. You are now dancing to \"It's the Final Countdown." << endl;
        cout << "You are now feeling like a TikTok star but do you need to be reminded that you are still stuck in space..." << endl;
    }

    // Player eats a victory meal
    void victoryMeal(){
        cout << "You decide to eat something special to celebrate your victory" << endl;
        cout << "You ate a 5-star meal in space. Too bad you might not make it back to Earth to tell the tale..." << endl;
    }

    // Player pretends to play drums with with the wrench and accidentally hits the oxygen tank
    void playDrums(){
        cout << "You feel like the main character as you were so close to fixing the oxygen leak." << endl;
        cout << "So you decided to play imaginary drums with the wrench and accidentally hit the oxygen tank..." << endl;
    }
