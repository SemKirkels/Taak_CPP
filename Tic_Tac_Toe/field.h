#ifndef FIELD_H
#define FIELD_H

#include "player.h"
#include <iostream>

using namespace std;

namespace TicTacToeSemKirkels
{
    class Field
    {
        public:
            Field();
            void drawFieldOptions();
            void drawField();
            char getSymbols(int position)                           { return symbols[position]; }
            void setSymbols(int position, Player *playerObject)     { symbols[position] = playerObject->getSymbol(); }
            int checkWin(Player *player_1, Player *player_2);
            ~Field();
        protected:
            char symbols[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
            bool win_player_1 = false; // Boolean 1/4
            bool win_player_2 = false; // Boolena 2/4
    };
}

#endif // FIELD_H
