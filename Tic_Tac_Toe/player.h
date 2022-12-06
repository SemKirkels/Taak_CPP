#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

class Player
{
    public:
        Player();
        void    setName(string nameInput)       { name = nameInput; }       // Setter
        string  getName(void)                   { return name; }            // Getter
        void    setSymbol(char symbolInput)     { symbol = symbolInput; }   // Setter
        char    getSymbol(void)                 { return symbol; }          // Getter
        virtual void placeSymbol(void) = 0;     // Virtual Function
        ~Player();

    private:
        string name;
        char symbol;
};

#endif // PLAYER_H
