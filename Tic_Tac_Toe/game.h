#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string.h>
#include "cpu.h"
#include "localplayer.h"
#include <cstdlib>

using namespace std;

class Game
{
    public:
        Game();
        int selectGameMode();       // Asks the player if they wish to play vs cpu of vs another player
        void setNames_PvP();
        void setNames_PvC();
        void setSymbol_PvP();
        void setSymbol_PvC();
        ~Game();
    protected:
        LocalPlayer player_1, player_2;
        CPU cpu;
};

#endif // GAME_H
