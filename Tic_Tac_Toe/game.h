#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string.h>
#include "cpu.h"
#include "localplayer.h"
#include "field.h"
#include <cstdlib>

using namespace std;

class Game
{
    public:
        Game();
        int selectGameMode();       // Asks the player if they wish to play vs cpu of vs another player
        void setNames_PvP();        // Asks and sets the name for the players in PvP
        void setNames_PvC();        // Asks and sets the name in PvC
        void setSymbol_PvP();       // Asks and sets the symbols for each player in PvP
        void setSymbol_PvC();       // Asks and sets the symbol for the player in PvC
        void runGame();             // Runs the game and calls each function
        ~Game();
    protected:
        Player *player_1, *player_2; // Object Composition
};

#endif // GAME_H
