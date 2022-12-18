#ifndef CPU_H
#define CPU_H

#include "player.h"
#include "field.h"
#include <cstdlib>

namespace TicTacToeSemKirkels
{
    class CPU : public TicTacToeSemKirkels::Player
    {
        public:
            CPU(TicTacToeSemKirkels::Field *field);
            int placeSymbol();
            void checkField();
            void checkStartingPlayer();
            int checkPlayerCanWin();
            void getPlayerSymbol();
            ~CPU();
        protected:
            char grid[9];
            TicTacToeSemKirkels::Field *field;
        private:
            int turn = 0;
            bool player_start = false;      // Boolean 3/4
            bool player_can_win = false;    // Boolean 4/4
            char playerSymbol;
    };
}

#endif // CPU_H
