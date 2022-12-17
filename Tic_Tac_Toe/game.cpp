#include "game.h"

namespace TicTacToeSemKirkels
{
    Game::Game() // Game constructor
    {
        std::cout << std::endl;
        std::cout << "Starting the game!" << std::endl << std::endl;
    }
    
    /*
     * Function asks the user to select the gamemode
     * @param gameMode: Saves the user input. Gamemode can be 1 -> PvP or 2 -> PvC. Program will exit(-1) when other
     * @return gameMode: Gamemode is returned
     */
    int Game::selectGameMode()
    {
        int gameMode = 0;
    
        while(1)
        {
            std::cout << "Select a gamemode:" << std::endl;
            std::cout << "1. Player VS Player" << std::endl;
            std::cout << "2. Player VS CPU" << std::endl;
            std::cin >> gameMode;
    
            player_1 = new LocalPlayer();
    
            if(gameMode == 1)
            {
                std::cout << "You selected Player VS Player" << std::endl << std::endl;
                player_2 = new LocalPlayer();
                break;
            }
            else if(gameMode == 2)
            {
                std::cout << "You selected Player VS CPU" << std::endl << std::endl;
                player_2 = new CPU(&field);
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
    
    /*
     * Function asks the users for their player name and sets it depending on the player
     * @param tempName: Saves the user input.
     * @return: None
     */
    void Game::setNames_PvP()
    {
        string tempName;
    
        std::cout << "Player 1 set your name: ";
        std::cin >> tempName;
        player_1->setName(tempName); // Encapsulation
    
        std::cout << "Player 2 set your name: ";
        std::cin >> tempName;
        player_2->setName(tempName); // Encapsulation
    
        std::cout << "Name player 1: " << player_1->getName() << std::endl;              // Encapsulation
        std::cout << "Name player 2: " << player_2->getName() << std::endl << std::endl; // Encapsulation
    }
    
    /*
     * Function asks the user for their player name and sets it than it auto sets the name CPU for the AI
     * @param tempName: Saves the user input.
     * @return: None
     */
    void Game::setNames_PvC()
    {
        string tempName; // Object Composition
    
        std::cout << "Player 1 set your name: ";
        std::cin >> tempName;
        player_1->setName(tempName);
    
        player_2->setName("CPU");
    
        std::cout << "Name player 1: " << player_1->getName() << std::endl;  // Encapsulation
        std::cout << "Name cpu: " << player_2->getName() << std::endl;            // Encapsulation
    }
    
    /*
     * Function asks the users for their symbols.
     * @param tempSymbol Saves the user input.
     * @return: None
     */
    void Game::setSymbol_PvP()
    {
        srand((unsigned) time(NULL));
    
        std::cout << "Lets toss a coin" << std::endl;
    
        int random = (rand() % 10); // A random number selects which player may start selecting the symbol
        if((random % 2) != 0)
        {
            char tempSymbol;
    
            std::cout << player_1->getName() << " starts"<< std::endl;           // Encapsulation
            std::cout << player_1->getName() << " set your symbol [x / o]: ";    // Encapsulation
            cin >> tempSymbol;
            player_1->setSymbol(tempSymbol);
    
            if(tempSymbol == 'x')
            {
                player_2->setSymbol('o');
            }
            else if(tempSymbol == 'o')
            {
                player_2->setSymbol('x');
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
    
            std::cout << player_2->getName() << " starts"<< std::endl;
            std::cout << player_2->getName() << " set your symbol [x / o]: ";
            cin >> tempSymbol;
            player_2->setSymbol(tempSymbol);
    
            if(tempSymbol == 'x')
            {
                player_1->setSymbol('o');
            }
            else if(tempSymbol == 'o')
            {
                player_1->setSymbol('x');
            }
            else
            {
                std::cout << "Invalid input!" << std::endl;
                exit(-1);
            }
        }
    
        std::cout << "Symbol " << player_1->getName() << ": " << player_1->getSymbol() << std::endl;
        std::cout << "Symbol " << player_2->getName() << ": " << player_2->getSymbol() << std::endl;
    }
    
    /*
     * Function asks the user for their symbol than sets the remaining symbol for the CPU.
     * @param tempSymbol Saves the user input.
     * @return: None
     */
    void Game::setSymbol_PvC()
    {
        char tempSymbol;
    
        std::cout << player_1->getName() << " set your symbol [x / o]: ";
        cin >> tempSymbol;
        player_1->setSymbol(tempSymbol);
    
        if(tempSymbol == 'x')
        {
            player_2->setSymbol('o');
        }
        else if(tempSymbol == 'o')
        {
            player_2->setSymbol('x');
        }
        else
        {
            std::cout << "Invalid input!" << std::endl;
            exit(-1);
        }
    
        std::cout << "Symbol " << player_1->getName() << ": " << player_1->getSymbol() << std::endl;
        std::cout << "Symbol " << player_2->getName() << ": " << player_2->getSymbol() << std::endl;
    }
    
    void Game::turnPlayer_1()
    {
        while(1) // Player_1 turn
        {
            int temp;
    
            std::cout << player_1->getName() << " Place your symbol: ";
            temp = player_1->placeSymbol() - 1;
    
            if(field.getSymbols(temp) == ' ')
            {
               field.setSymbols(temp, player_1);
               break;
            }
        }
    }
    
    void Game::turnPlayer_2()
    {
        while(1) // Player_2 turn
        {
            int temp;
    
            std::cout << player_2->getName() << " Place your symbol: ";
    
            temp = player_2->placeSymbol() - 1;
            if(field.getSymbols(temp) == ' ')
            {
               field.setSymbols(temp, player_2);
               break;
            }
        }
    }
    
    /*
     * Function runs the game and calls each function depending on the game phase.
     * @param field: This object encapsulates all paramiters of the field.
     * @param gameMode: stores the game mode (1 PvP or 2 PvC)
     * @param player_start: can be 1 or 2 and determens the starting player
     * @return: None
     */
    void Game::runGame()
    {
        srand(time(NULL));
    
        int gameMode = 0;
        int moves = 0;
        int player_start = ((rand() % 2) + 1);
    
        gameMode = selectGameMode();
    
        if(gameMode == 1)
        {
            setNames_PvP();
            setSymbol_PvP();
        }
    
        if(gameMode == 2)
        {
            setNames_PvC();
            setSymbol_PvC();
        }
    
        field.drawFieldOptions(); // Draw the field options
    
        while(moves < 9)
        {
            if(player_start == 1)
            {
                turnPlayer_1();
                moves++;
    
                field.drawField(); // Draw the field
    
                if(field.checkWin(player_1, player_2) == 1) // Check for win
                {
                    std::cout << player_1->getName() << " Wins!" << std::endl;
                    break;
                }
    
                if(moves == 9)
                {
                    break;
                }
    
                turnPlayer_2();
                moves++;
    
                field.drawField(); // Draw the field
    
                if(field.checkWin(player_1, player_2) == 2) // Check for win
                {
                    std::cout << player_2->getName() << " Wins!" << std::endl;
                    break;
                }
            }
    
            if(player_start == 2)
            {
                turnPlayer_2();
                moves++;
    
                field.drawField(); // Draw the field
    
                if(field.checkWin(player_1, player_2) == 2) // Check for win
                {
                    std::cout << player_2->getName() << " Wins!" << std::endl;
                    break;
                }
    
                if(moves == 9)
                {
                    break;
                }
    
                turnPlayer_1();
                moves++;
    
                field.drawField(); // Draw the field
    
                if(field.checkWin(player_1, player_2) == 1) // Check for win
                {
                    std::cout << player_1->getName() << " Wins!" << std::endl;
                    break;
                }
            }
        }
    
        if(field.checkWin(player_1, player_2) == 0)
        {
            std::cout << "Draw" << std::endl;
        }
    
        delete player_1;
        delete player_2;
    }
    
    Game::~Game()
    {
        std::cout << "Game Ended!" << std::endl;
    }
}
