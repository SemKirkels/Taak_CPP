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
            char grid[9];                                       // Saves the contents of the field.
            TicTacToeSemKirkels::Field *field;
        private:
            int turn = 0;                                       // Counts the turn
            bool player_start = false;      // Boolean 3/4      // Saves if the human player is starting
            bool player_can_win = false;    // Boolean 4/4      // Saves if the human player has a win opportunity
            char playerSymbol;                                  // Saves the symbol of the opponent
    };
}

#endif // CPU_H
