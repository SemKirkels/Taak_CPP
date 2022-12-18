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
            void drawFieldOptions();        // Draws the field filled with the options where the players can place their characters
            void drawField();               // Draws the actual field
            char getSymbols(int position)                           { return symbols[position]; }
            void setSymbols(int position, Player *playerObject)     { symbols[position] = playerObject->getSymbol(); }
            int checkWin(Player *player_1, Player *player_2);       // Checks if a player can win and returns either 0, 1, or 2 depending if the game is draw, won by p_1 or won by p_2
            ~Field();
        protected:
            char symbols[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};        // Stores the content of the field
            bool win_player_1 = false; // Boolean 1/4                               // Stores info if player_1 won
            bool win_player_2 = false; // Boolena 2/4                               // Stores info if player_2 won
    };
}

#endif // FIELD_H
