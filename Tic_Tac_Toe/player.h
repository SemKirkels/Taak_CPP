#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

class Player
{
    public:
        Player(std::string name) : name(name)   { std::cout << "Player: " << name << " created" << std::endl; }
        virtual int getSymbol() = 0;
        virtual int setSymbol() = 0;
        ~Player()                               {};

    private:
        std::string name;
        char symbol;
        int symbol_status;
};

#endif // PLAYER_H
