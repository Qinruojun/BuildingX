#ifndef PLAYER_H
#define PLAYER_h
#include<iostream>
using namespace std;
class player{
    
    public:
    player(const int &,const string&,const string&);
    void setscore();
    // bool varify();
    void savetoFile();
    static player loaddata(const int key);
    private:
    int key;//代表这是第几个注册的玩家，用于文件指针的确定
    char username[16] ;
    char password[20];
    int score=0;//每通过一个就可以加特定的分数
    int p1=0;
    int p2=0;
    int p3=0;
    int p4=0;
    int p5=0;
    int p6=0;
    int p7=0;//不同关卡的文件指针，也就是通关到了哪一个题目

};
#endif
