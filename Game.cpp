//Game 类，用于控制游戏的进行，共有7个关卡，分别是10，30，50，100，150，200，250
#include"Game.h"
#include<fstream>
 #include<Windows.h>
 #include<stdexcept>
 #include<conio.h>
 #include<fstream>
#include<iostream>
#include"Player.h"
#include<string>
using namespace std;
// void setCursorPosition(int x,int y){
//         COORD coord={(SHORT)x,(SHORT)y};
//         SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
//     }//将光标位置设置到x,y
// void Game::Load_game(){
//     ifstream profile("C:/Users/adven/BuildingX/Lanton's_Ant/PRO.data",ios::in);//我设置的题面文件存储路径
    



// }
// void Game::play(){
// //要将光标初始位置设置到蚂蚁的初始位置

// }
int Game::get_key(){
    fstream file("Playercount.dat",ios::binary|ios::in);
    file.seekg(0);
    int index;
    file>>index;
    return index;
}

void update_key(){
  fstream file("Playercount.dat",ios::binary|ios::out|ios::in);
   file.seekg(0);
    int index;
    file>>index;
    file.seekp(0);
    file<<(index+1);
}

bool Game::valify_key(const int& key){
   
    if(key>get_key())
    {return false;}
    return true;
}
void Game::valifyUsername(const std::string& usname){
 if(usname.size()>16){
            throw invalid_argument("The username should be no more than 16 characters");
        }
else if(usname.empty()){
    throw invalid_argument("Username cannot be empty, please try again:");
}
}
void Game::valifyPwd(const std::string & pass){
    if(pass.size()>20){
        throw invalid_argument("The password should be no more than 20 charaters");
    }
    else if(pass.empty()){
        throw invalid_argument("Password should not be empty,please try again:");
    }
}
bool Game::valify_account(const int& key,const string& pass,const string & username){
    fstream file("Playerinfo.dat",ios::binary|ios::in);
    file.seekg(sizeof((key-1)*sizeof(player)),ios::beg);
    string pwd,name;
    file>>name>>pwd;
    if(name==username&&pass==pwd){
        return true;
    }
    return false;

}
void Game::log_in(){
    std::cout<<"choice:"<<endl;
    std::cout<<"-----1.Register--------"<<endl;
    std::cout<<"-----1.sign in--------"<<endl;
    int choice;
    cin>>choice;
    switch(choice){
        
        case(1):{//注册
        std::cout<<"Please set your username,no more than 16 char"<<endl;
        string usname;string name;
        while(true){
            try{
        getline(cin,usname);//用户名可能包含空格
        usname.erase(0,usname.find_first_not_of("\t\n\r"))
       ;
       usname.erase(usname.find_last_not_of("\t\n\t"+1));
       valifyUsername(usname);
        name=usname;//得到的合法的用户名
            break;}
        catch(invalid_argument&e){
            cerr<<e.what()<<endl;
        }
        string pwd;
        string pass;
        while(true){
            try{ 
                getline(cin,pass);
                pass.erase(0,pass.find_first_not_of("\t\n\r"));
                pass.erase(pass.find_last_not_of("\t\n\t"+1));
                valifyPwd(pass);
                pwd=pass;
            }
            catch (invalid_argument&e){
                cerr<<e.what()<<endl;
            }
        }
        int cnt=get_key();
        update_key();//用户注册要更新用户的数量
        player newplayer(cnt+1,name,pass);
        std::cout<<"Please remember your key:"<<cnt<<endl;
        player_key=cnt+1;
    break;
        }}
        case(2):{//登录
    std::cout<<"Please enter your key:"<<endl;
    int key;
    while(true){
    cin>>key;
    if(valify_key(key)){
    player_key=key;
    break;}
    else{
        std::cout<<"Your key is wrong ,please try again:"<<endl;
    }}
    std::cout<<"Please enter your username and password:"<<endl;string name,pwd;
    while(true){
        cin>>name>>pwd;
        if(valify_account(key,pwd,name))
        {std::cout<<"You have sign in sucessfully!"<<endl;
        break;}
        else {
            std::cout<<"Your username or password must be false,please try again"<<endl;
        }
        
    }


        }
    }
}
void Game::load_game(){
    std::cout<<"请选择游戏模式: 1.正推 2.逆推"<<endl;
    int choice ;
    switch(choice){
        case(1):{
            std::cout<<"请选择你要玩的关卡:1-7"<<endl;
            int c;
            while(true){
            cin>>c;
            if(c>=1&&c<=7)
            break;
            else {
                std::cout<<"只能选择1-7的关卡,请重新输入:"<<endl;
            }
            }
            break;
        }

        case(2):{
            break;
        }
    }
}