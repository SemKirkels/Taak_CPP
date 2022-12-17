#include "cpu.h"

namespace TicTacToeSemKirkels
{
    CPU::CPU(TicTacToeSemKirkels::Field *field) : field(field)
    {

    }

    /*
    * Contains the logic for the cpu in a PvC game
    * On the first turn the cpu check who is the starting player.
    * If the cpu starts it plays a regular game
    * If the localplayer starts the cpu only tries to block it.
    */
    int CPU::placeSymbol()
    {
        turn++;
        checkField();

        if(turn == 1)
        {
            checkStartingPlayer();

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

    /*
    * Copies the information from the field to a new array 'grid'
    */
    void CPU::checkField()
    {
        for(int i = 0; i < 9; i++)
        {
            grid[i] = field->getSymbols(i);
        }
    }

    /*
    * Check if the field is completely empty if so a flag 'player_start' is set to false
    * Else the flag is set to true
    */
    void CPU::checkStartingPlayer()
    {
        for(int i = 0; i < 9; i++)
        {
            int empty_boxes = 0;

            if(grid[i] == ' ')
            {
                empty_boxes++;
            }

            if(empty_boxes == 8)
            {
                player_start = false;
            }
            else
            {
                player_start = true;
            }
        }
    }

    CPU::~CPU()
    {

    }
}
