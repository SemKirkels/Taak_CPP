#include "localplayer.h"

namespace TicTacToeSemKirkels
{
    /*
     * LocalPlayer Constructor
     */
    LocalPlayer::LocalPlayer()
    {

    }

    /*
     * This function asks for user input and returns the value of the user so that it can be placed on the field.
     * @param location: The user input is saved in this variable it contains the location on the grid where the player symbol must be placed.
     * @return location: Returns the location on the field where the symbol must be placed.
     */
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

    /*
    * LocalPlayer Destructor
    */
    LocalPlayer::~LocalPlayer()
    {

    }
}
