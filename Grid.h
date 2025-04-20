#ifndef GRID_H
#define GRID_H
#include"Ant.h"
class Grid{
protected:
    int level;
    vector<vector<int>>grid;
};
class Origin_Grid:public Grid{
    public:
        void Generate_Pro();
        void load_pro();
        void load_ans();
        string creat_ans_filename();
        string creat_pro_filename();

    private:
    Ant start_ant;//蚂蚁在这个初始盘面的初始位置

};

class Final_Grid:public Grid{
public:void Generate_Ans();
private:
    Ant final_ant;
};
#endif
