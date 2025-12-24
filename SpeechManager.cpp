#include "SpeechManager.h"
using namespace std;

//构造 
    SpeechManager::SpeechManager(/* args */)
    {
        
    }

//菜单
    void SpeechManager::showMenu()
    {
        cout << "-------------------------------------------------------------------" << endl;
        cout << "          " << "1.Start the speech contest" << endl;
        cout << "          " << "2.View past competition records" << endl;
        cout << "          " << "3.Clear match history" << endl;
        cout << "          " << "0.Exit the competition program" << endl;

    }

//退出系统
    void SpeechManager::exitSystem()
    {
        cout << "Welcome to use it next time" << endl;
        system("cls");
        exit(0);
    }

//析构
    SpeechManager::~SpeechManager()
    {

    }