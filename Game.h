#ifndef GAME_H
#define GAME_H
#include<iostream>
class Game{
public:
    void valifyUsername(const string&);
    void valifyPwd(const string&);
    void log_in();
    int get_key();
    void update_key();
    bool valify_key(const int &);
    // void store_game();
    bool valify_account(const int &,const string&, const string&);
    void load_game();
    void display_game();
    void play();
private:
int player_key;


};
#endif