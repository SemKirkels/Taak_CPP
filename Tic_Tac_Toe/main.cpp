#include <iostream>

#include "game.h"
#include "cpu.h"
#include "localPlayer.h"

using namespace std;

int main()
{
    int gameMode = 0;
    Game newGame;

    gameMode = newGame.selectGameMode();

    if(gameMode == 1)
    {
        newGame.setNames_PvP();
        newGame.setSymbol_PvP();

    }

    if(gameMode == 2)
    {
        newGame.setNames_PvC();
        newGame.setSymbol_PvC();
    }

    return 0;
}
