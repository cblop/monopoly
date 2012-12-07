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
    std::cout << "GAME CONSTRUCTOR!\n";
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
    std::cout << "GAME SETUP!!\n";
   }

//-----------------------------------------------------------------------------
void Game::PlayGame()
{
    std::cout << "\nNow we will start the game.\n" << std::endl;
    unsigned int numOfContinuousDoubles=0;
    while(m_players.howManyPlayersAreStillOntheGame()>1)
    {
        if(m_players.isCurrentPlayerInJail())
        {
            std::cout << "Player "<< m_players.getName() << "is in Jail!\n";
            std::cout << "Do you want to pay 50 and go? (y/n)";
            std::string yesOrNo;
            std::cin >> yesOrNo;
            if(yesOrNo=="y")
            {
                if(!m_players.takeBalance(50))
                {
                    std::cout<< "You do not have enough money to pay!\n";
                }
            }
        }else
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "   ***  Player: " << m_players.getName()
                      << ",  Balance = " << m_players.getBalance() << "  ***\n";
            std::cout << "Press ENTER to roll, " << std::endl;
            std::cin.get();
            m_dices.roll();
            m_dices.print();
            m_players.movePositionBy(m_dices.getTotal());
            std::cout << "You have reach the following Tile:\n";
            m_board.print(m_players.getCurrentPlayersPosition());
            if(m_dices.isDouble())
            {
                if(numOfContinuousDoubles==3)
                {
                    m_players.setJailed(true);
                }
                numOfContinuousDoubles++;
                m_board.action(m_players);
            }
            else
            {
                m_board.action(m_players);
                m_players.moveToNextPlayer();
            }
        }
    }
    m_players.printWinner();
}

//-----------------------------------------------------------------------------
Game::~Game()
{
}
