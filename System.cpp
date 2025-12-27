#include <iostream>
#include "SpeechManager.h"
using namespace std;

int main()
{        
    SpeechManager sm;
    int choice = 0;
    while (true)
    {
        sm.showMenu();
        cout << "Please enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            sm.startSpeech();
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 0:
            sm.exitSystem();
            break;
        
        default:
            system("cls");
            break;
        }
    }
}