#ifndef FIELD_H
#define FIELD_H

#include "player.h"
#include <iostream>

using namespace std;

class Field
{
    public:
        Field();
        void drawFieldOptions();
        void drawField();
        char getSymbols(int position)                           { return symbols[position]; }
        void setSymbols(int position, Player *playerObject)     { symbols[position] = playerObject->getSymbol(); }
        int checkWin(Player *player_1, Player *player_2);
        int getStatus()                                         { return status; }
        void setStatus(int input)                               { status = input; }
        ~Field();
    protected:
        char symbols[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        int status = 0;
};

#endif // FIELD_H
