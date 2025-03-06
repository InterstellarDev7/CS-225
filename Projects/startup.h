#include <iostream>
#include <string>
#include <thread>  // For sleep_for
#include <chrono>  // For duration
using namespace std;

class Start {
    private:
        string lastName;
    public:
        Start(){
            cout<<"What is your last name? "<<endl;
            cin>>lastName;
        }
        void displayStart();
};

void Start::displayStart(){
    cout<<"Welcome! You have decided to play the:\n**** International Space Station Survival Game!****"<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout<<"\nYou are Commander "<<lastName<<" aboard the ISS. For the past couple months you have been"<<
    " researching on plasma propulsion systems.\nEverything was routine...until now."<<endl;
    this_thread::sleep_for(chrono::seconds(8));
    cout<<"\nSpace debris has struck the ISS causing severe damage."<<
    " The impact cut off communication from JPL, disabled power systems, and caused a small leak somewhere in the piping."
    <<"\nOxygen is slowly depleting… "<<endl;
    this_thread::sleep_for(chrono::seconds(8));
    cout<<"\nWith only 5 hours of time, you must complete your tasks. The fate of the mission, your life, and the ISS"
    <<" are in your hands. Decide wisely, time is running out."<<endl;
}
