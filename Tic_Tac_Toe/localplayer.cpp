#include "localplayer.h"

namespace TicTacToeSemKirkels
{
    LocalPlayer::LocalPlayer()
    {

    }

    int LocalPlayer::placeSymbol()
    {
        int location;

        while(1)
        {
            cin >> location;
            if(location > 0 && location < 10)
            {
                return location;
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(1);
                std::cout << "Invalid Input" << std::endl;
            }
        }
    }

    LocalPlayer::~LocalPlayer()
    {

    }
}
