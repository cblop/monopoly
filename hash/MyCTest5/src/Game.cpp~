#include "Game.h"
#include "Dice.h"
#include <string>
#include <vector>
#include <climits>
#include <ctime>
#include <stdlib.h>
#include "CardsManager.h"


//-----------------------------------------------------------------------------
Game::Game()
{
    std::cout << "GAME CONSTRUCTOR!\n";
    m_dice = new Dice();
    SetupGame();
    std::cout<<"Before Cards are initialised!!\n";
    CardsManager::initialiseCards();
    std::cout << "Cards are initialised!\n";
    //CardsManager::printAllCards();
    std::cout << "Cards are printed!=) YUPI\n";
    std::cout << "END OF GAME SET UP\n";
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
    std::cout << "GAME SETUP!!\n";
    int numPlayers = 2;
    std::vector<std::string> playerNames;
    std::string currentName = "";
    //std::vector<Player> players;


    m_players.resize(2);
    playerNames.push_back("Player1");
    playerNames.push_back("Player2");
    

    std::cout << std::endl << std::endl;


    for (int i=0;i<numPlayers;i++) {
        m_players[i] = new Player(playerNames[i]);
        std::cout << "Player " << i+1 << ": " << m_players[i]->getName() << std::endl;
    }


    srand((unsigned)time(0));


    std::cout << m_players[0]->getName() << " goes first." << std::endl;

    m_currentPlayer = 0;
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

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "Press ENTER to roll, " << player->getName() << std::endl;
    std::cout << std::endl;
    
    //player->takeBalance(10*m_dice->getValue());
    
    player->movePositionBy(2);
    std::cout << player->getName() << " is now at:" << m_board.getTileName(player->getPosition()) << std::endl;

    m_board.action(m_players, m_currentPlayer);

}

//-----------------------------------------------------------------------------
Game::~Game()
{
    CardsManager::destroyedAllCards();
}
