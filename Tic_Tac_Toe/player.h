#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

class Player
{
    public:
        Player();
        void    setName(string nameInput)       { name = nameInput; }
        string  getName(void)                   { return name; }
        void    setSymbol(char symbolInput)     { symbol = symbolInput; }
        char    getSymbol(void)                 { return symbol; }
        virtual void placeSymbol(void) = 0;
        ~Player();

    private:
        string name;
        char symbol;
};

#endif // PLAYER_H
