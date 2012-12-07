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
                    std::cout<< "Press 'R' to roll the dices!\n";
                    m_dices.roll();
                    if(m_dices.isDouble())
                    {
                        m_players.movePositionBy(m_dices.getTotal());
                        m_board.action(m_players);
                    }
                }
                else
                {
                    m_players.setJailed(false);
                    takeTurn();
                }
            }
        }else
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::string answer;
            std::cout << "   ***  Player: " << m_players.getName()
                      << ",  Balance = " << m_players.getBalance() << "  ***\n";
            if(numOfContinuousDoubles==0)
            {
               std::cout  << "Press 1 to buy houses or R to roll and play\n";
               while(answer!="R"&& answer!="1")
               {
                   std::cin >> answer;
               }
            }
            else
            {
                std::cout << "Press R to roll and play\n";
                while(answer!="R")
                {
                    std::cin >> answer;
                }
            }
            if(answer == "R")
            {
                takeTurn();
            }
            else
            {
                ///buy houses
                std::cout << "Press R to roll and play\n";
                while(answer!="R")
                {
                    std::cin >> answer;
                }
                takeTurn();
            }
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
void Game::takeTurn()
{
    m_dices.roll();
    m_dices.print();
    m_players.movePositionBy(m_dices.getTotal());
    std::cout << "You have reach the following Tile:\n";
    m_board.print(m_players.getCurrentPlayersPosition());
}

//-----------------------------------------------------------------------------
Game::~Game()
{
}
