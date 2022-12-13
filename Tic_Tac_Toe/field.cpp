#include "field.h"

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
            status = 1;
        }

        if(player_2->getSymbol() == symbols[i] && player_2->getSymbol() == symbols[i + 1] && player_2->getSymbol() == symbols[i + 2])
        {
            status = 2;
        }
    }

    // Check Vertical
    for(int i = 0; i < 3; i++)
    {
        if(player_1->getSymbol() == symbols[i] && player_1->getSymbol() == symbols[i + 3] && player_1->getSymbol() == symbols[i + 6])
        {
            status = 1;
        }

        if(player_2->getSymbol() == symbols[i] && player_2->getSymbol() == symbols[i + 3] && player_2->getSymbol() == symbols[i + 6])
        {
            status = 2;
        }
    }

    // Check Diagonal
    for(int i = 0; i < 3; i += 2)
    {
        if(i == 0) // Diagonal 1
        {
            if(player_1->getSymbol() == symbols[i] && player_1->getSymbol() == symbols[i + 4] && player_1->getSymbol() == symbols[i + 8])
            {
                status = 1;
            }

            if(player_2->getSymbol() == symbols[i] && player_2->getSymbol() == symbols[i + 4] && player_2->getSymbol() == symbols[i + 8])
            {
                status = 2;
            }
        }
        else if(i == 2) // Diagonal 2
        {
            if(player_1->getSymbol() == symbols[i] && player_1->getSymbol() == symbols[i + 2] && player_1->getSymbol() == symbols[i + 4])
            {
                status = 1;
            }

            if(player_2->getSymbol() == symbols[i] && player_2->getSymbol() == symbols[i + 2] && player_2->getSymbol() == symbols[i + 4])
            {
                status = 2;
            }
        }
        else
        {
            std::cout << "Error!" << std::endl;
        }
    }

    return status;
}

Field::~Field()
{

}
