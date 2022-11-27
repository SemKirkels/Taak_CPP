#include "game.h"

Game::Game()
{
    std::cout << std::endl;
    std::cout << "Starting the game!" << std::endl << std::endl;
}

int Game::selectGameMode()
{
    int gameMode = 0;

    while(1)
    {
        std::cout << "Select a gamemode:" << std::endl;
        std::cout << "1. Player VS Player" << std::endl;
        std::cout << "2. Player VS CPU" << std::endl;
        std::cin >> gameMode;

        if(gameMode == 1)
        {
            std::cout << "You selected Player VS Player" << std::endl << std::endl;
            break;
        }
        else if(gameMode == 2)
        {
            std::cout << "You selected Player VS CPU" << std::endl << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid input" << std::endl;
            exit(-1);
        }
    }

    return gameMode;
}

void Game::setNames_PvP()
{
    string tempName;

    std::cout << "Player 1 set your name: ";
    std::cin >> tempName;
    player_1.setName(tempName);

    std::cout << "Player 2 set your name: ";
    std::cin >> tempName;
    player_2.setName(tempName);

    std::cout << "Name player 1: " << player_1.getName() << std::endl;
    std::cout << "Name player 2: " << player_2.getName() << std::endl << std::endl;
}

void Game::setNames_PvC()
{
    string tempName;

    std::cout << "Player 1 set your name: ";
    std::cin >> tempName;
    player_1.setName(tempName);

    cpu.setName("CPU");

    std::cout << "Name player 1: " << player_1.getName() << std::endl;
    std::cout << "Name cpu: " << cpu.getName() << std::endl;
}

void Game::setSymbol_PvP()
{
    srand((unsigned) time(NULL));

    std::cout << "Lets toss a coin" << std::endl;

    int random = (rand() % 10); // A random number selects which player may start selecting the symbol
    if((random % 2) != 0)
    {
        char tempSymbol;

        std::cout << player_1.getName() << " starts"<< std::endl;
        std::cout << player_1.getName() << " set your symbol [x / o]: ";
        cin >> tempSymbol;
        player_1.setSymbol(tempSymbol);

        if(tempSymbol == 'x')
        {
            player_2.setSymbol('o');
        }
        else if(tempSymbol == 'o')
        {
            player_2.setSymbol('x');
        }
        else
        {
            std::cout << "Invalid input!" << std::endl;
            exit(-1);
        }

    }
    else
    {
        char tempSymbol;

        std::cout << player_2.getName() << " starts"<< std::endl;
        std::cout << player_2.getName() << " set your symbol [x / o]: ";
        cin >> tempSymbol;
        player_2.setSymbol(tempSymbol);

        if(tempSymbol == 'x')
        {
            player_1.setSymbol('o');
        }
        else if(tempSymbol == 'o')
        {
            player_1.setSymbol('x');
        }
        else
        {
            std::cout << "Invalid input!" << std::endl;
            exit(-1);
        }

    }

    std::cout << "Symbol " << player_1.getName() << ": " << player_1.getSymbol() << std::endl;
    std::cout << "Symbol " << player_2.getName() << ": " << player_2.getSymbol() << std::endl;
}

void Game::setSymbol_PvC()
{
    char tempSymbol;

    std::cout << player_1.getName() << " set your symbol [x / o]: ";
    cin >> tempSymbol;
    player_1.setSymbol(tempSymbol);

    if(tempSymbol == 'x')
    {
        cpu.setSymbol('o');
    }
    else if(tempSymbol == 'o')
    {
        cpu.setSymbol('x');
    }
    else
    {
        std::cout << "Invalid input!" << std::endl;
        exit(-1);
    }

    std::cout << "Symbol " << player_1.getName() << ": " << player_1.getSymbol() << std::endl;
    std::cout << "Symbol " << cpu.getName() << ": " << cpu.getSymbol() << std::endl;
}

int Game::checkWinP1()
{
    int winStatus = 0;

    return winStatus;
}

int Game::checkWinP2()
{
    int winStatus = 0;

    return winStatus;
}

int Game::checkWinCPU()
{
    int winStatus = 0;

    return winStatus;
}

Game::~Game()
{
    std::cout << "Game Ended!" << std::endl;
}
