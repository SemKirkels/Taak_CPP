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
        LocalPlayer player_1, player_2;

        newGame.setNames_PvP(player_1, player_2);
        std::cout << player_1.getName() << std::endl;
        std::cout << player_2.getName() << std::endl;
    }

    if(gameMode == 2)
    {
        LocalPlayer player_1;
        CPU cpu;

        newGame.setNames_PvC(player_1, cpu);
        std::cout << player_1.getName() << std::endl;
        std::cout << cpu.getName() << std::endl;
    }

    return 0;
}
