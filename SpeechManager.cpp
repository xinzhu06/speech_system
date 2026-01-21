#include "SpeechManager.h"
using namespace std;

//构造 
    SpeechManager::SpeechManager(/* args */)
    {
        //初始化选手
        this->initSpeaker();

        //创建选手
        this->createSpeaker();

        //获取往届记录
        this->loadRecord();
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
        system("cls");
        cout << "Welcome to use it next time" << endl;
        exit(0);
    }

//初始化参赛选手
    void SpeechManager::initSpeaker()
    {
        this->v1.clear();
        this->v2.clear();
        this->victory.clear();
        this->m_speaker.clear();
        this->index = 1;
    }

//创建成员
    void SpeechManager::createSpeaker()
    {
        string nameSeed = "ABCDEFGHIJKL";

        for(int i = 0;i < nameSeed.size();i++)
        {        
            Speaker sp;
            sp.m_name = "Contestant";
            sp.m_name += nameSeed[i];
            for(int j = 0 ; j < 2; j++)
            {
                sp.m_score[j] = 0;
            }
            //创建选手编号
            this->v1.push_back(i + 10001);
            //选手对应的编号
            this->m_speaker.insert(make_pair(i + 10001,sp));
        }
    }

//开始比赛
    void SpeechManager::startSpeech()
    {
        //第一轮比赛
        //1.抽签
        this->speechDraw();
        //2.比赛
        this->speechContest();
        //3.显示晋级结果
        this->showScore();
        //第二轮比赛
        this->index++;
        //1.抽签
        this->speechDraw();
        //2.比赛
        this->speechContest();
        //3.显示晋级结果
        this->showScore();
        //4.保存分数到文件中
        this->saveRecord();
        cout << "game over" << endl;
        system("pause");
        system("cls");
        }  
//抽签
    void SpeechManager::speechDraw()
    {
        srand(time(NULL));
        cout << "The contestants in the " << this->index << " round are drawing lots." << endl;
        cout << "The lottery results are as follows" << endl;
        if(this->index == 1)
        {
            random_shuffle(v1.begin(),v1.end());
            for(auto const&s:v1)
            {
                cout << s << " " ;
            }
            cout << endl;
        }else{
            random_shuffle(v2.begin(),v2.end());
            for(auto const&s:v2)
            {
                cout << s << " " ;
            }
            cout << endl;
        }
        system("pause");

    }

//比赛
    void SpeechManager::speechContest()
    {
        //临时分组
        multimap<double,int,greater<double>>groupScore;
        int num = 0;
        cout << " --------------" << "now " << this->index << "-----------------" << endl;
        vector<int>v_Src;
        if(this->index == 1)
        {
            v_Src = v1;
        }else{
            v_Src = v2;
        }
        //遍历参赛选手
        for(auto const&s:v_Src)
        {
            num++;
            //评委打分
            deque<int>d;
            for (int i = 0; i < 10; i++)
            {
                double score = rand()%401+600 / 10.f;
                d.push_back(score);
            }
            sort(d.begin(),d.end(),greater<double>());
            d.pop_back();
            d.pop_front();
            double sum = accumulate(d.begin(),d.end(),0.0f);
            double average = sum / d.size();
            this->m_speaker[s].m_score[this->index-1] = average;
            //分组
            groupScore.insert(make_pair(average,s));
            if(num % 6 == 0)
            {
                cout << "The " << num/6 << " team result follow----------------" << endl;
                for(auto const&f:groupScore)
                {
                    cout << "ID:" << f.second << " name:" << this->m_speaker[f.second].m_name << " score:" << f.first << endl;
                }
                //取前三名
                int count = 0;
                for(auto const&g:groupScore)
                {
                    if(count >= 3)break;
                    if(this->index == 1)
                    {
                        v2.push_back(g.second);
                    }else{
                        victory.push_back(g.second);
                    }
                    count++;
                }
                groupScore.clear();
            }
        }
        system("pause");
    }

//显示晋级选手
    void SpeechManager::showScore()
    {
        cout << "--------" << "show enter next" << "--------" << endl;
        vector<int>v;
        if(this->index == 1)
        {
            v = v2;
        }else{
            v = victory;
        }
        for(auto const&s:v)
        {
            cout << "ID:" << s << " name:" << this->m_speaker[s].m_name << " score:" << this->m_speaker[s].m_score[this->index-1] << endl;
        }
        system("pause");
        system("cls");
        this->showMenu();
    }

//保存记录
    void SpeechManager::saveRecord()
    {
        ofstream ofs;
        ofs.open("speech.csv",ios::out | ios::app);
        
        //将每个人的数据写入文件中
        for(auto &s:victory)
        {
            ofs << s << "," << this->m_speaker[s].m_score[1] << ",";
        }
        ofs << endl;

        //关闭
        ofs.close();
        cout << "save over";
    }

    //读取记录
    void SpeechManager::loadRecord()
    {
        ifstream ifs("speech.csv",ios::in);
        
        if(!ifs.is_open())
        {
            this->fileIsEmpt = true;
            cout << "wen jian bu cun zai" << endl;
            ifs.close();
            return;
        }

        char ch;
        cin >> ch;
        if(ifs.eof())
        {
            cout << "wen jian wei kong " << endl;
            this->fileIsEmpt = true;
            ifs.close();
            return;
        }

        this->fileIsEmpt = false;

        ifs.putback(ch);//将上面读取的字符放回来

        string data;

        while (ifs >> data)
        {
            cout << data << endl;
        }

        ifs.close();
    }


//析构
    SpeechManager::~SpeechManager()
    {

    }