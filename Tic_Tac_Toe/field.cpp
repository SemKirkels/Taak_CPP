#include "field.h"

namespace TicTacToeSemKirkels
{
    Field::Field()
    {

    }

    void Field::drawFieldOptions()
    {
        std::cout << std::endl;
        std::cout << '1' << "|" << '2' << "|" << '3' << std::endl;
        std::cout << "-|-|-" << std::endl;
        std::cout << '4' << "|" << '5' << "|" << '6' << std::endl;
        std::cout << "-|-|-" << std::endl;
        std::cout << '7' << "|" << '8' << "|" << '9' << std::endl;
        std::cout << std::endl;
    }

    void Field::drawField()
    {
        std::cout << std::endl;
        std::cout << symbols[0] << "|" << symbols[1] << "|" << symbols[2] << std::endl;
        std::cout << "-|-|-" << std::endl;
        std::cout << symbols[3] << "|" << symbols[4] << "|" << symbols[5] << std::endl;
        std::cout << "-|-|-" << std::endl;
        std::cout << symbols[6] << "|" << symbols[7] << "|" << symbols[8] << std::endl;
    }

    int Field::checkWin(Player *player_1, Player *player_2)
    {
        // Check Horizontal
        for(int i = 0; i < 9; i += 3)
        {
            if(player_1->getSymbol() == symbols[i] && player_1->getSymbol() == symbols[i + 1] && player_1->getSymbol() == symbols[i + 2])
            {
                win_player_1 = true;
            }

            if(player_2->getSymbol() == symbols[i] && player_2->getSymbol() == symbols[i + 1] && player_2->getSymbol() == symbols[i + 2])
            {
                win_player_2 = true;
            }
        }

        // Check Vertical
        for(int i = 0; i < 3; i++)
        {
            if(player_1->getSymbol() == symbols[i] && player_1->getSymbol() == symbols[i + 3] && player_1->getSymbol() == symbols[i + 6])
            {
                win_player_1 = true;
            }

            if(player_2->getSymbol() == symbols[i] && player_2->getSymbol() == symbols[i + 3] && player_2->getSymbol() == symbols[i + 6])
            {
                win_player_2 = true;
            }
        }

        // Check Diagonal
        if(player_1->getSymbol() == symbols[0] && player_1->getSymbol() == symbols[4] && player_1->getSymbol() == symbols[8]) // Diagonal 1 Player 1
        {
            win_player_1 = true;
        }

        if(player_2->getSymbol() == symbols[0] && player_2->getSymbol() == symbols[4] && player_2->getSymbol() == symbols[8]) // Diagonal 1 Player 2
        {
            win_player_2 = true;
        }

        if(player_1->getSymbol() == symbols[6] && player_1->getSymbol() == symbols[4] && player_1->getSymbol() == symbols[2]) // Diagonal 2 Player 1
        {
            win_player_1 = true;
        }

        if(player_2->getSymbol() == symbols[6] && player_2->getSymbol() == symbols[4] && player_2->getSymbol() == symbols[2]) // Diagonal 2 Player 2
        {
            win_player_2 = true;
        }

        // Check win if and which player has won
        if(win_player_1 == true && win_player_2 == false)
        {
            return 1;
        }
        else if(win_player_2 == true && win_player_1 == false)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }

    Field::~Field()
    {

    }
}
