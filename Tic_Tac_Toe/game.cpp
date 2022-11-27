#include "game.h"

Game::Game()
{
    std::cout << "Starting the game!" << std::endl;
}

int Game::selectGameMode()
{
    int gameMode = 0;

    while(1)
    {
        std::cout << "Select a gamemode:" << std::endl;
        std::cout << "1. Player VS Player" << std::endl;
        std::cout << "2. Player VS CPU:" << std::endl;
        std::cin >> gameMode;

        if(gameMode == 1)
        {
            std::cout << "You selected Player VS Player" << std::endl;
            break;
        }
        else if(gameMode == 2)
        {
            std::cout << "You selected Player VS CPU" << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid input" << std::endl;
        }
    }

    return gameMode;
}

void Game::setNames_PvP(LocalPlayer player_1, LocalPlayer player_2)
{
    string tempName;

    std::cout << "Player 1 set your name: ";
    std::cin >> tempName;
    player_1.setName(tempName);

    std::cout << "Player 2 set your name: ";
    std::cin >> tempName;
    player_2.setName(tempName);
}

void Game::setNames_PvC(LocalPlayer player_1, CPU cpu)
{
    string tempName;

    std::cout << "Player 1 set your name: ";
    std::cin >> tempName;
    player_1.setName(tempName);

    cpu.setName("CPU");
}

Game::~Game()
{
    std::cout << "Game Ended!" << std::endl;
}
