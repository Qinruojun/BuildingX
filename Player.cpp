#include"Player.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
player::player(const int& n,const string&usename, const string&pwd ):index(n)
{
strcpy(username,usename.c_str());
strcpy(password,pwd.c_str());
}
void player::savetoFile(){
  ofstream outfile("Playerinfo.dat",ios::binary|ios::app);
  if(!outfile){
    cerr<<"File could not open"<<endl;
    exit(EXIT_FAILURE);}

    outfile.write(reinterpret_cast<const char*>(&username),sizeof(username));
    outfile.write(reinterpret_cast<const char*>(&password),sizeof(password));
    outfile.write(reinterpret_cast<const char*>(&score),sizeof(score));
    outfile.write(reinterpret_cast<const char*>(p1),sizeof(p1));
    outfile.write(reinterpret_cast<const char*>(p2),sizeof(p2));
    outfile.write(reinterpret_cast<const char*>(p3),sizeof(p3));
    outfile.write(reinterpret_cast<const char*>(p4),sizeof(p4));
    outfile.write(reinterpret_cast<const char*>(p5),sizeof(p5));
    outfile.write(reinterpret_cast<const char*>(p6),sizeof(p6));
    outfile.write(reinterpret_cast<const char*>(p7),sizeof(p7));
}
