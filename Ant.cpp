/************************************
 * 蚂蚁的类的初始化
 * 默认的方向：      Up
 *                  |
 *           Left————————Right
 *                  |
 *                 Down
 */
#include<iostream>
using namespace std;
#include"Ant.h"

void Ant::random_position(const int& size){
    srand(static_cast<unsigned int>(time(0)));
    int pos=rand()%(size*size);//初始化蚂蚁一开始所在的位置
x=pos/size;//行数
y=pos%size-1;//列数
}
void Ant::Setheading(int h){
    heading=Dire[h];
    tailheading=Dire[3-h];
}
void Ant::random_towards(){
    srand(static_cast<unsigned int>(time(0)));
    int turn=rand()%4;
   Setheading(turn);
};
void Ant::Moveforward(){
   switch(heading)
   {case Up:
    {
    y--;break;}
    case Down:{
        y++;
        break;
    }
    case Left:{
        x--;
        break;
    }
    case Right:{
        x++;
        break;
    }
}}
void Ant::TurnRight(){
  switch(heading){
    case Up:{
        heading=Right;
        tailheading=Left;
        break;
    }
    case Down:{
        heading=Left;
        tailheading=Right;
        break;
    }
    case Left:{
        heading=Up;
        tailheading=Down;
        break;
    }
    case Right:{
        heading=Down;
        tailheading =Up;
        break;
    }
  }
}
void Ant::TurnLeft(){
    TurnRight();
   Direction temp=heading;
    heading=tailheading;
    tailheading=temp;
}
void Ant::Movebackward(){
      switch(tailheading)
   {case Up:
    {
    y--;break;}
    case Down:{
        y++;
        break;
    }
    case Left:{
        x--;
        break;
    }
    case Right:{
        x++;
        break;
    }
}
}


void Ant::Move_straight(vector<vector<char>> map,int step){
    while(step--){
    if (map[x][y]=='#')//蚂蚁当前处在黑格时
    {
        map[x][y]='@';//黑格变为白格
        TurnLeft();//左转
        Moveforward();//向前一步
    }
    else if(map[x][y]=='@'){
        map[x][y]='#';//白格变黑格
        TurnRight();//右转
        Moveforward();//向前一步
    }
}}
void Ant::Move_back(vector<vector<char>> map,int step){
    Movebackward();
   while(step--){
    if(map[x][y]=='#'){
        map[x][y]='@';//黑格变为白格
        TurnRight();//根据尾巴的方向向左转就相当于根据头的方向向右转
        Movebackward();
    }
    else if(map[x][y]=='@'){
        map[x][y]='#';//白格变黑格
        TurnLeft();//右转
        Movebackward();//向前一步
    }
   }
}

