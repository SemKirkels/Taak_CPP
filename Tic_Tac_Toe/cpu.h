#ifndef CPU_H
#define CPU_H

#include "player.h"
#include "field.h"
#include <cstdlib>

class CPU : public TicTacToeSemKirkels::Player
{
    public:
    CPU(TicTacToeSemKirkels::Field *field);
        int placeSymbol();
        void checkField();
        void checkStartingPlayer();
        ~CPU();
    protected:
        char grid[9];
        TicTacToeSemKirkels::Field *field;
    private:
        int turn = 0;
        bool player_start = false;
};

#endif // CPU_H
