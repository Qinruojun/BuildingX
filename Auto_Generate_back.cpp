
/*因为使用生成随机数的方法来生成最终盘面可能会得到一个无解的盘面，所以通过生成随机数
的方法生成蚂蚁的初始盘面和蚂蚁的起点，再用正推函数推指定步数就可以得到最终的盘面，最终盘面作为题面，初始盘面作为答案*/
#include<cstdlib>
#include<iostream>
#include<ctime>
#include"Grid.h"
#include<vector>
#include"Ant.h"
#include<fstream>
using namespace std;
const int step[8]={0,10,30,50,100,150,200,250};//代表的是步数的大小
const int width[8]={0,10,10,15,20,25,30,40};
void Origin_Grid::Generate_Pro(){
  srand(static_cast<unsigned int>(time(0)));
  int size=width[level];
   grid.assign(size,vector<int>(size));
   int count=0;
   while(count<size*size){
        
            int num=rand();
            while(num){
            if(num & 1==1){
                 grid[count/size][count%size]=1;//用1映射到#号代表黑色
        
                 }
                else  
                     grid[count/size][count%size]=0;//用0映射到@ 符号代表白色
            count++;
            num/=2;}
   }}

