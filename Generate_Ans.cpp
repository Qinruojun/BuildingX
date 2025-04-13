//因为一个grid选择不同的起点可以有size*size个不同的运行盘面，所以另外开了一个类来储存
#include<cstdlib>
#include<ctime>
#include<vector>
#include"Ant.h"
using namespace std;
class Pro_Grid{
public:
    void SetPro(std::vector<vector<char>>);
private:
    vector<vector<char>> progrid;
    

void Setpro(vector<vector<char>>grid){
    int Size=grid.size();
    progrid.assign(Size,vector<char>(Size));
    int pos=rand()%(Size*Size);//初始化蚂蚁一开始所在的位置
    int head=rand()%4;//初始化蚂蚁的朝向,生成0到3的随机数
   

    Ant ant (pos/Size,pos%Size,head);
    

}

};