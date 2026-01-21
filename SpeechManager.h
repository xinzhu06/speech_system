#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <deque>
#include <functional>
#include <numeric>
#include <fstream>
#include "Speaker.h"
using namespace std;

class SpeechManager
{

public:
//构造
    SpeechManager();

//菜单
    void showMenu();

//退出系统
    void exitSystem();

//第一轮
    vector<int>v1;

//第二轮
    vector<int>v2;

//前三
    vector<int>victory;

//存放编号以及对应的选手
    map<int,Speaker>m_speaker;

//比赛的轮数
    int index;

//初始化
    void initSpeaker();

//创建成员
    void createSpeaker();

//开始比赛
    void startSpeech();

//抽签
    void speechDraw();

//比赛
    void speechContest();

//显示晋级选手
    void showScore();

//保存记录
    void saveRecord();

//读取记录
    void loadRecord();

//显示往届记录
    void showRecord();

//清空记录
    void clearRecord();

//判断文件是否为空
    bool fileIsEmpt;

//存放往届记录的容器
    map<int,vector<string>>m_Record;

//析构
    ~SpeechManager();

};

