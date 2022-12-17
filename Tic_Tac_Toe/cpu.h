#ifndef CPU_H
#define CPU_H

#include "player.h"
#include "field.h"
#include <cstdlib>

class CPU : public Player
{
    public:
        CPU(Field *field);
        int placeSymbol();
        void checkField();
        ~CPU();
    protected:
        char grid[9];
        Field *field;
    private:
        int turn = 0;
};

#endif // CPU_H
