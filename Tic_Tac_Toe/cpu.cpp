#include "cpu.h"

CPU::CPU(Field *field) : field(field)
{

}

int CPU::placeSymbol()
{
    turn++;
    checkField();

    if(turn == 1)
    {
        if(grid[0] == ' ')
        {
            return 1;
        }
        else if(grid[2] == ' ')
        {
            return 3;
        }
        else
        {
            return (rand() % 9);
        }
    }

    if(turn == 2)
    {
        if(grid[0] == symbol)
        {
            return 9;
        }
        else if(grid[6] == ' ')
        {
            return 7;
        }
        else
        {
            return (rand() % 9);
        }
    }

    // Check for oponent win conditions

    return (rand() % 9);
}

void CPU::checkField()
{
    for(int i = 0; i < 9; i++)
    {
        grid[i] = field->getSymbols(i);
    }
}

CPU::~CPU()
{

}
