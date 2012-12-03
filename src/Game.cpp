#include "Game.h"
#include "Dice.h"
#include <string>
#include <vector>
#include <climits>
#include <ctime>
#include <stdlib.h>



//-----------------------------------------------------------------------------
Game::Game()
{



    m_dice = new Dice();

    SetupGame();
}

//-----------------------------------------------------------------------------
void Game::reset()
{

}


//-----------------------------------------------------------------------------
void Game::StartGame()
{
    //m_board[1]->action(m_players,m_currentPlayer);
}

//-----------------------------------------------------------------------------
void Game::SetupGame()
{
    int numPlayers = 2;
    std::vector<std::string> playerNames;
    std::string currentName = "";
    //std::vector<Player> players;

    std::cout << "Enter number of players (2 - 6): ";
    std::cin >> numPlayers;
    while (numPlayers < 2 || numPlayers > 6) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Please enter a number between 2 and 6: ";
        std::cin >> numPlayers;
    }

    m_players.resize(numPlayers);

    for (int i=0;i<numPlayers;i++) {
        std::cout << "What's your name, player " << i+1 << "? ";
        std::cin >> currentName;
        playerNames.push_back(currentName);
    }

    std::cout << std::endl << std::endl;


    for (int i=0;i<numPlayers;i++) {
        m_players[i] = new Player(playerNames[i]);
        std::cout << "Player " << i+1 << ": " << m_players[i]->getName() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Now we'll roll the dice to see who goes first" << std::endl;

    std::cout << std::endl;

    srand((unsigned)time(0));

    int oldwinner = 0;
    int winner = 0;
    int windex = -1;
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');

    for (int i=0;i<numPlayers;i++) {
        std::cout << "Press ENTER to roll, " << m_players[i]->getName() << std::endl;
        std::cout << std::endl;
        std::cin.get();
        m_dice->roll();
        winner = m_dice->getTotal();
        std::cout << m_players[i]->getName() << " rolled: " << winner << std::endl <<std::endl;
        if (winner > oldwinner) windex = i;
        oldwinner = winner;
    }

    std::cout << m_players[windex]->getName() << " goes first." << std::endl;

    m_currentPlayer = windex;
    std::cout << std::endl;

}

//-----------------------------------------------------------------------------
void Game::PlayGame()
{
    std::cout << "\nNow we will start the game.\n" << std::endl;
    int numLosers = 0;

    while (numLosers < (int)m_players.size() - 1) {
        numLosers = 0;
        for (int i=0;i<(int)m_players.size();i++) {
            m_currentPlayer = i;
            std::cout << std::endl;
            std::cout << m_players[i]->getName() << " has " << m_players[i]->getBalance() << std::endl;
            if (m_players[i]->getBalance() > 0) {
                TakeTurn(m_players[i]);
            }
            else {
                std::cout << m_players[i]->getName() << " has no money." << std::endl;
                numLosers++;
            }

        }
    }

    std::cout << "Final scores:" << std::endl;

    for (int i=0;i<(int)m_players.size(); i++) {
        std::cout << m_players[i]->getName() << ": " << m_players[i]->getBalance() << std::endl; 

    }
}

//-----------------------------------------------------------------------------
void Game::TakeTurn(Player *player)
{
    bool repeat = true;

    while (repeat) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Press ENTER to roll, " << player->getName() << std::endl;
        std::cout << std::endl;
        std::cin.get();
        m_dice->roll();
        std::cout << m_dice->getValues()[0] << ", " << m_dice->getValues()[1] << std::endl;

        player->movePositionBy(m_dice->getTotal());
        std::cout << player->getName() << " is now at:" << m_board.getTileName(player->getPosition()) << std::endl;

        m_board.action(m_players, m_currentPlayer); 

        if (m_dice->isDouble()) {
            std::cout << "You rolled a double! Go again." << std::endl;
        }
        else {
            repeat = false;
        }
    } 

}

//-----------------------------------------------------------------------------
Game::~Game()
{

}
