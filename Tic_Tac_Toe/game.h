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
        int checkWinP1();
        int checkWinP2();
        int checkWinCPU();
        ~Game();
    protected:
        LocalPlayer player_1, player_2; // Object Composition
        CPU cpu;                        // Object Composition
    private:
        int locations[3][3];
        //  locations[x][y]
};

/*
 * locations:
 *              [0x]   [1x]   [2x]
 *          [0y]
 *
 *          [1y]
 *
 *          [2y]
 *
 *          When a location in the array is equal to 1 player 1 has put their symbol on that location
 *          When a location in the array is equal to 2 player 2 has put their symbol on that location
 *          When a location in the array is equal to 3 the cpu has put their symbol on that location
 */

/*
 * checkWin:
 *              [0x]   [1x]   [2x]
 *          [0y]
 *
 *          [1y]
 *
 *          [2y]
 *
 *          Example:
 *          Player 1 wins when:
 *
 *          statement 1: locations[0][0] == 1 && locations[1][0] == 1 && locations[2][0] == 1
 *          statement 2: locations[0][1] == 1 && locations[1][1] == 1 && locations[2][1] == 1
 *          statement 3: locations[0][2] == 1 && locations[1][2] == 1 && locations[2][2] == 1
 *          statement 4: locations[0][0] == 1 && locations[0][1] == 1 && locations[0][2] == 1
 *          statement 5: locations[1][0] == 1 && locations[1][1] == 1 && locations[1][2] == 1
 *          statement 6: locations[2][0] == 1 && locations[2][1] == 1 && locations[2][2] == 1
 *          statement 7: locations[0][0] == 1 && locations[1][1] == 1 && locations[2][2] == 1
 *          statement 8: locations[0][2] == 1 && locations[1][1] == 1 && locations[2][0] == 1
 */

#endif // GAME_H
