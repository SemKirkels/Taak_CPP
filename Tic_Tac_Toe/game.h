#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string.h>
#include "cpu.h"
#include "localplayer.h"

using namespace std;

class Game
{
    public:
        Game();
        int selectGameMode();       // Asks the player if they wish to play vs cpu of vs another player
        void setNames_PvP(LocalPlayer player_1, LocalPlayer player_2);
        void setNames_PvC(LocalPlayer player_1, CPU cpu);
        ~Game();
};

#endif // GAME_H
