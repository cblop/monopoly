#include "Game.h"
#include "Dice.h"
#include <string>
#include <vector>
#include <climits>
#include <ctime>
#include <stdlib.h>


//-----------------------------------------------------------------------------
Game::Game()
{}

//-----------------------------------------------------------------------------
void Game::reset()
{

}

//-----------------------------------------------------------------------------
void Game::PlayGame()
{
    std::cout << "\nNow we will start the game.\n" << std::endl;
    unsigned int numOfContinuousDoubles = 0;
    std::vector<unsigned int >numOfTimesRollDicesInJail;
    numOfTimesRollDicesInJail.resize(m_players.getNumOfPlayers());
    for(unsigned int i=0; i<numOfTimesRollDicesInJail.size();++i)
    {
        numOfTimesRollDicesInJail[i]=0;
    }
    while(m_players.howManyPlayersAreStillOntheGame()>1)
    {
        if(m_players.isCurrentPlayerInJail())
        {
            if(numOfTimesRollDicesInJail[m_players.getCurrentPlayer()]!=3)
            {
                std::cout << "\nPlayer "<< m_players.getName() << " is in Jail!\n";
                std::cout << "Do you want to pay 50 and go? (y/n)";
                std::string yesOrNo;
                std::cin >> yesOrNo;
                if(yesOrNo=="y")
                {
                    numOfTimesRollDicesInJail[m_players.getCurrentPlayer()]=0;
                    if(!m_players.takeBalance(50))
                    {
                        std::cout<< "You do not have enough money to pay!\n";
                        std::cout<< "Press 'R' to roll the dices!\n";
                        while (yesOrNo!= "R")
                        {
                            std::cin >> yesOrNo;
                        }
                        numOfTimesRollDicesInJail[m_players.getCurrentPlayer()]++;
                        m_dices.roll();
                        m_dices.print();
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
                }else
                {
                    std::cout<< "Press 'R' to roll the dices!\n";
                    while (yesOrNo!= "R")
                    {
                        std::cin >> yesOrNo;
                    }
                    numOfTimesRollDicesInJail[m_players.getCurrentPlayer()]++;
                    m_dices.roll();
                    m_dices.print();
                    if(m_dices.isDouble())
                    {
                        m_players.movePositionBy(m_dices.getTotal());
                        m_board.action(m_players);
                    }
                }
                m_players.moveToNextPlayer();
            }
            else
            {
                numOfTimesRollDicesInJail[m_players.getCurrentPlayer()]=0;
                std::cout << "You have to pay 50 and get out of Jail!\n";
                if(!m_players.takeBalance(50))
                {
                    std::cout << "You do not have enough money to pay!\n";
                    m_players.withdrawGame();
                    m_players.moveToNextPlayer();
                }
                else
                {
                    m_players.setJailed(false);
                    std::cout<< "Press 'R' to roll the dices!\n";
                    std::string answer="";
                    while (answer!= "R")
                    {
                        std::cin >> answer;
                    }
                    takeTurn();
                    m_players.moveToNextPlayer();
                }
            }
        }else
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::string answer;
            std::cout << "\n   ***  Player: " << m_players.getName()
                      << ",  Balance = " << m_players.getBalance() <<"  ***\n";

           std::cout  << "Press B to build houses, R to roll and play, or "
                      << " W to Withdraw the game \n";
           while(answer!="R"&& answer!="B" && answer!="W")
           {
               std::cin >> answer;
           }

            if(answer == "R")
            {
                takeTurn();
            }
            else if(answer == "W")
            {
                m_players.withdrawGame();
            }
            else  // buy houses
            {
                m_board.buildHouses(m_players);
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
                    numOfContinuousDoubles = 0;
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
