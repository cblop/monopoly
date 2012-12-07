#include "PlayerManager.h"
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <ctime>
#include <stdlib.h>

//-----------------------------------------------------------------------------
PlayerManager::PlayerManager(
        ):m_currentPlayer(0),
          m_numOfLoosers(0)
{
    srand((unsigned)time(0));
    unsigned int numPlayers = 2;
    std::cout << "Enter number of players (2 - 6): ";
    std::cin >> numPlayers;
    while (numPlayers < 2 || numPlayers > 6) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Please enter a number between 2 and 6: ";
        std::cin >> numPlayers;
    }
    m_players.resize(numPlayers);
    setPlayers(numPlayers);
}

//-----------------------------------------------------------------------------
PlayerManager::PlayerManager(
        unsigned int i_numOfPlayers
        ):m_currentPlayer(0),
          m_numOfLoosers(0)
{
    setPlayers(i_numOfPlayers);
}

//-----------------------------------------------------------------------------
void PlayerManager::setPlayers(unsigned int i_numOfPlayers)
{
    m_players.resize(i_numOfPlayers);
    std::string currentName;
    for (unsigned int i=0;i<i_numOfPlayers;i++) {
        std::cout << "What's your name, player " << i+1 << "? ";
        std::cin >> currentName;
        m_players[i].setName(currentName);
    }
    std::cout << std::endl;

    std::cout << "Now we'll roll the dice to see who goes first"
              << std::endl;

    std::cout << std::endl;

    int oldwinner = 0;
    int winner = 0;
    int windex = -1;
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');

    for (unsigned int i=0;i<m_players.size();i++) {
        std::cout << "Press ENTER to roll, " << m_players[i].getName()
                  << std::endl;
        std::cout << std::endl;
        std::cin.get();
        m_dices.roll();
        winner = m_dices.getValue();
        std::cout << m_players[i].getName() << " rolled: " << winner
                  << std::endl <<std::endl;
        if (winner > oldwinner) windex = i;
        oldwinner = winner;
    }

    std::cout << m_players[windex].getName() << " goes first."
              << std::endl;

    m_currentPlayer = windex;
    std::cout << std::endl;
}

//-----------------------------------------------------------------------------
void PlayerManager::printWinner()const
{
    std::string winner=m_players[0].getName();
    unsigned int maxPossesionsValue = 0;
    for(unsigned int i=0; i<m_players.size(); ++i)
    {
        if(m_players[i].isPlayerStillOnTheGame())
        {
            const unsigned int currentPossesionValues =
                m_players[i].getPossessionsValue();
            if(maxPossesionsValue<currentPossesionValues)
            {
                maxPossesionsValue = currentPossesionValues;
                winner = m_players[i].getName();
            }
        }
    }
    std::cout << "The winner is " << winner << " and his possesions worth "
              << maxPossesionsValue << "\n";
}

//-----------------------------------------------------------------------------
void PlayerManager::resetAllPlayers()
{
    for(unsigned int i=0; i<m_players.size(); ++i)
    {
        m_players[i].reset();
    }
}

//-----------------------------------------------------------------------------
void PlayerManager::moveCurrentPlayer()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "Press ENTER to roll, " <<
                 m_players[m_currentPlayer].getName() << std::endl;
    std::cout << std::endl;
    std::cin.get();
    m_dices.roll();
    std::cout << m_dices.getValue() << std::endl;
    m_players[m_currentPlayer].movePositionBy(m_dices.getValue());
}

//-----------------------------------------------------------------------------
unsigned int PlayerManager::getCurrentPlayersPosition()const
{
   return m_players[m_currentPlayer].getPosition();
}

//-----------------------------------------------------------------------------
unsigned int PlayerManager::howManyPlayersAreStillOntheGame()const
{
    unsigned int num = 0;
    for(unsigned int i=0; i<m_players.size(); ++i)
    {
        num+=m_players[i].isPlayerStillOnTheGame();
    }
    return num;
}

//-----------------------------------------------------------------------------
void PlayerManager::moveToNextPlayer()
{
    m_currentPlayer = (m_currentPlayer+1)%m_players.size();
    while(!m_players[m_currentPlayer].isPlayerStillOnTheGame())
    {
        m_currentPlayer = (m_currentPlayer+1)%m_players.size();
    }
}

//-----------------------------------------------------------------------------
const std::string &PlayerManager::getName() const
{
    return m_players[m_currentPlayer].getName();
}

//-----------------------------------------------------------------------------
unsigned int PlayerManager::getBalance()
{
    return m_players[m_currentPlayer].getBalance();
}

//-----------------------------------------------------------------------------
bool PlayerManager::takeBalance(unsigned int i_amount)
{
    return m_players[m_currentPlayer].takeBalance(i_amount);
}

//-----------------------------------------------------------------------------
void PlayerManager::addBalance(unsigned int i_amount)
{
    m_players[m_currentPlayer].addBalance(i_amount);
}

//-----------------------------------------------------------------------------
void PlayerManager::addBalance(unsigned int i_amount, unsigned int i_player)
{
    m_players[i_player].addBalance(i_amount);
}

//-----------------------------------------------------------------------------
unsigned int PlayerManager::getPosition() const
{
    return m_players[m_currentPlayer].getPosition();
}

//-----------------------------------------------------------------------------
void PlayerManager::movePositionBy(unsigned int i_amount)
{
    m_players[m_currentPlayer].movePositionBy(i_amount);
}

//-----------------------------------------------------------------------------
void PlayerManager::setPosition(unsigned int i_position)
{
    m_players[m_currentPlayer].setPosition(i_position);
}

//-----------------------------------------------------------------------------
unsigned int PlayerManager::getCurrentPlayer()const
{
    return m_currentPlayer;
}

//-----------------------------------------------------------------------------
void PlayerManager::setJailed(bool jailed)
{
    m_players[m_currentPlayer].setJailed(jailed);
}

//-------------------------------------------------------------------------
PlayerManager::~PlayerManager()
{}

