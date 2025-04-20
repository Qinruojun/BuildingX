#include"Grid.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
string Origin_Grid::creat_ans_filename(){
  string filename="C:/Users/adven/BuildingX/Lanton's_Ant/backmode_PRO_level"+to_string(level)+".dat";
  return filename;
}
string Origin_Grid::creat_pro_filename(){
 string filename="C:/Users/adven/BuildingX/Lanton's_Ant/straightmode_ANS_level"+to_string(level)+".dat";
}
void Origin_Grid::load_ans(){
ofstream outfile(creat_pro_filename(),ios::out|ios::binary);

}
void Origin_Grid::load_pro(){
ifstream outfile(creat_ans_filename(),ios::out|ios::binary);

}
