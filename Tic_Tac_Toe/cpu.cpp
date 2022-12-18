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
        int position = checkPlayerCanWin();

        if(turn == 1)
        {
            checkStartingPlayer();
            getPlayerSymbol();

            if(player_start == false) // Cpu starts in offensive mode
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
            else // Cpu starts in defensive mode
            {
                if(position == 10) // if there is no win condition for player use default strategy
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
                else
                {
                    return position;
                }
            }
        }

        if(turn == 2)
        {
            if(player_start == false) // Cpu starts in offensive mode
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
            else // Cpu starts in defensive mode
            {
                if(position == 10) // if there is no win condition for player use default strategy
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
                else
                {
                    return position;
                }
            }
        }

        if(turn == 3)
        {
            if(player_start == false) // Cpu starts in offensive mode
            {
                if(grid[0] == symbol && grid[8] == symbol)
                {
                    if(grid[4] == ' ')
                    {
                        return 5;
                    }
                    else
                    {
                        return 7;
                    }
                }
            }
            else // Cpu starts in defensive mode
            {
                if(position == 10) // if there is no win condition for player use default strategy
                {
                    if(grid[0] == symbol && grid[8] == symbol)
                    {
                        if(grid[4] == ' ')
                        {
                            return 5;
                        }
                        else
                        {
                            return 7;
                        }
                    }
                }
                else
                {
                    return position;
                }
            }
        }

        if(turn == 4)
        {
            if(player_start == false) // Cpu starts in offensive mode
            {
                if(grid[4] == ' ')
                {
                    return 5;
                }
                else if(grid[3] == ' ')
                {
                    return 4;
                }
                else if(grid[7] == ' ')
                {
                    return 8;
                }
                else
                {
                    return 6;
                }
            }
            else // Cpu starts in defensive mode
            {
                if(position == 10) // if there is no win condition for player use default strategy
                {
                    if(grid[4] == ' ')
                    {
                        return 5;
                    }
                    else if(grid[3] == ' ')
                    {
                        return 4;
                    }
                    else if(grid[7] == ' ')
                    {
                        return 8;
                    }
                    else
                    {
                        return 6;
                    }
                }
                else
                {
                    return position;
                }
            }
        }

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
        int empty_boxes = 0;

        for(int i = 0; i < 9; i++)
        {

            if(grid[i] == ' ')
            {
                empty_boxes++;
            }
        }

        if(empty_boxes == 9)
        {
            player_start = false;
        }
        else
        {
            player_start = true;
        }
    }

    /*
     * This function checks if the opponent can win and returns the value that CPU has to use to block the win
     */
    int CPU::checkPlayerCanWin()
    {
        /*
         * This for loop check horizontal win opportunities for player_1
         * it first checks horizontal row 1 than row 2 and finally row 3
         * the first if statment checks for:
         *      x|x|.
         * the second if statement checks for:
         *      .|x|x
         * the third if statement checks for:
         *      x|.|x
         */
        for(int i = 0; i < 9; i += 3)
        {
            if(grid[i] == playerSymbol && grid[i + 1] == playerSymbol)
            {
                return i + 3;
            }
            else if(grid[i + 1] == playerSymbol && grid[i + 2] == playerSymbol)
            {
                return i + 1;
            }
            else if(grid[i] == playerSymbol && grid[i + 2] == playerSymbol)
            {
                return i + 2;
            }
            else
            {
                player_can_win = false;
            }
        }

        /*
         * This for loop check the vertical win opportunities for player_1
         * if first check col 1 than col 2 and finally col 3
         * the first if statment checks for:
         * x|.|.
         * x|.|.
         * .|.|.
         * the second if statment checks for:
         * .|.|.
         * x|.|.
         * x|.|.
         * the second if statment checks for:
         * x|.|.
         * .|.|.
         * x|.|.
         */
        for(int i = 0; i < 3; i++)
        {
            if(grid[i] == playerSymbol && grid[i + 3] == playerSymbol)
            {
                return i + 7;
            }
            else if(grid[i + 3] == playerSymbol && grid[i + 6] == playerSymbol)
            {
                return i + 1;
            }
            else if(grid[i] == playerSymbol && grid[i + 6] == playerSymbol)
            {
                return i + 4;
            }
            else
            {
                player_can_win = false;
            }
        }


        /*
         * This if statement check for diagonal win opportunities for player_1
         * the first if statment checks for;
         * x|.|.
         * .|x|.
         * .|.|.
         * the second if statment checks for;
         * .|.|.
         * .|x|.
         * .|.|x
         * the third if statment checks for;
         * x|.|.
         * .|.|.
         * .|.|x
         */
        if(grid[0] == playerSymbol && grid[4] == playerSymbol)
        {
            return 9;
        }
        else if(grid[4] == playerSymbol && grid[8] == playerSymbol)
        {
            return 1;
        }
        else if(grid[0] == playerSymbol && grid[8] == playerSymbol)
        {
            return 5;
        }
        else
        {
            player_can_win = false;
        }

        /*
         * This if statement check for diagonal win opportunities for player_1
         * the first if statment checks for;
         * .|.|x
         * .|x|.
         * .|.|.
         * the second if statment checks for;
         * .|.|.
         * .|x|.
         * x|.|.
         * the third if statment checks for;
         * .|.|x
         * .|.|.
         * x|.|.
         */
        if(grid[2] == playerSymbol && grid[4] == playerSymbol)
        {
            return 7;
        }
        else if(grid[4] == playerSymbol && grid[6] == playerSymbol)
        {
            return 3;
        }
        else if(grid[2] == playerSymbol && grid[6] == playerSymbol)
        {
            return 5;
        }
        else
        {
            player_can_win = false;
        }

        if(player_can_win == false)
        {
            return 10; // return 10 means that there is no win condition for the player
        }

        return (rand() % 9);
    }

    /*
     * Gets the symbol of the oponent and writes it to playerSymbol.
     */
    void CPU::getPlayerSymbol()
    {
        if(symbol == 'x')
        {
            playerSymbol = 'o';
        }
        else
        {
            playerSymbol = 'x';
        }
    }

    CPU::~CPU()
    {

    }
}
