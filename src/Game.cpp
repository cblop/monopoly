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
        winner = m_dice->getValue();
        std::cout << m_players[i]->getName() << " rolled: " << winner << std::endl <<std::endl;
        if (winner > oldwinner) windex = i;
        oldwinner = winner;
    }

    std::cout << m_players[windex]->getName() << " goes first." << std::endl;

    m_currentPlayer = windex;
    std::cout << std::endl;

}

//-----------------------------------------------------------------------------
Game::~Game()
{

}
