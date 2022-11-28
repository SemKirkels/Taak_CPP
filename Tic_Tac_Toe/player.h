#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

using namespace std;

class Player
{
    public:
        Player();
        void    setName(string nameInput)       { name = nameInput; }       // Setter (Abstraction)
        string  getName(void)                   { return name; }            // Getter (Abstraction)
        void    setSymbol(char symbolInput)     { symbol = symbolInput; }   // Setter (Abstraction)
        char    getSymbol(void)                 { return symbol; }          // Getter (Abstraction)
        virtual void placeSymbol(void) = 0;     // Virtual Function
        ~Player();

    private:
        string name;
        char symbol;
};

#endif // PLAYER_H
