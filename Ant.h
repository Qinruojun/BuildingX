#ifndef ANT_H
#define ANT_H
#include<iostream>
#include<vector>
using namespace std;
const enum Direction{Up,Down,Left,Right};
const  Direction Dire[4]={Up,Left,Right,Down};
class Ant{
    public:
    Ant(int x,int y,int h):x(x),y(y){Setheading(h);};
    void Setheading(int);//既包括heading，也包括tailheading,即既包括头朝向，也包括尾朝向

    void random_position(const int &);
    void random_towards();

    void Moveforward();
    void TurnLeft();
    void TurnRight();
    void Movebackward();//主要是为了推出倒推游戏的答案,就是尾部前进一格

    void Move_straight(vector<vector<char>>,int, vector<vector<char>>&);//游戏模式为正推时得到答案的函数,同时也是自主生成题目的函数
    void Move_back(vector<vector<char>> , int,vector<vector<char>>&);//游戏模式为倒推时得到答案的函数

    private:
        unsigned int x;
        unsigned int y;//蚂蚁的初始位置的横纵坐标
        Direction heading;
        Direction tailheading;//蚂蚁的尾部的朝向，与头部的方向刚好相反：Up——Down Left——Right 
};
#endif