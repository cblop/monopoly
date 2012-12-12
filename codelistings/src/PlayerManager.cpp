#include "PlayerManager.hpp"
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
unsigned int PlayerManager::getNumOfPlayers()const
{
    return m_players.size();
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

    int oldwinner = 0;
    int winner = 0;
    int windex = -1;
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');

    for (unsigned int i=0;i<m_players.size();i++) {
        std::cout << "Press ENTER to roll, " << m_players[i].m_name
                  << std::endl;
        std::cin.get();
        m_dices.roll();
        winner = m_dices.getTotal();
        std::cout << m_players[i].m_name << " rolled: " << winner
                  << std::endl <<std::endl;
        if (winner > oldwinner) windex = i;
        oldwinner = winner;
    }

    std::cout << m_players[windex].m_name << " goes first." << std::endl;

    m_currentPlayer = windex;
    std::cout << std::endl;
}

//-----------------------------------------------------------------------------
unsigned int PlayerManager::withdrawGame()
{
    const unsigned int balance = m_players[m_currentPlayer].m_balance;
    m_players[m_currentPlayer].m_balance = 0;
    return balance;
}

//-----------------------------------------------------------------------------
void PlayerManager::printWinner()const
{
    std::string winner=m_players[0].m_name;
    unsigned int maxPossesionsValue = 0;
    for(unsigned int i=0; i<m_players.size(); ++i)
    {
        if(m_players[i].m_balance>0)
        {
            const unsigned int currentPossesionValues =
                m_players[i].getPossessionsValue();
            if(maxPossesionsValue<currentPossesionValues)
            {
                maxPossesionsValue = currentPossesionValues;
                winner = m_players[i].m_name;
            }
        }
    }
    std::cout << "The winner is " << winner << " and his balance is "
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
unsigned int PlayerManager::getCurrentPlayersPosition()const
{
   return m_players[m_currentPlayer].m_position;
}

//-----------------------------------------------------------------------------
unsigned int PlayerManager::howManyPlayersAreStillOntheGame()const
{
    unsigned int num = 0;
    for(unsigned int i=0; i<m_players.size(); ++i)
    {
        if(m_players[i].m_balance>0)
        {
            num+=1;
        }
    }
    return num;
}

//-----------------------------------------------------------------------------
bool PlayerManager::isCurrentPlayerInJail()const
{
    return m_players[m_currentPlayer].m_isJailed;
}

//-----------------------------------------------------------------------------
void PlayerManager::moveToNextPlayer()
{
    m_currentPlayer = (m_currentPlayer+1)%m_players.size();
    int numOfPlayers = m_players.size();
    while(m_players[m_currentPlayer].m_balance==0)
    {
        m_currentPlayer = (m_currentPlayer+1)%m_players.size();
        numOfPlayers--;
        if(numOfPlayers==0)
        {
            break;
        }
    }
}

//-----------------------------------------------------------------------------
const std::string &PlayerManager::getName() const
{
    return m_players[m_currentPlayer].m_name;
}

//-----------------------------------------------------------------------------
unsigned int PlayerManager::getBalance()
{
    return m_players[m_currentPlayer].m_balance;
}

//-----------------------------------------------------------------------------
bool PlayerManager::takeBalance(unsigned int i_amount)
{
    if(m_players[m_currentPlayer].m_balance<i_amount )
    {
        return false;
    }
    else
    {
        m_players[m_currentPlayer].m_balance -= i_amount;
        return true;
    }
}

//-----------------------------------------------------------------------------
void PlayerManager::addBalance(unsigned int i_amount)
{
    m_players[m_currentPlayer].m_balance+=i_amount;
}

//-----------------------------------------------------------------------------
void PlayerManager::addBalance(unsigned int i_amount, unsigned int i_player)
{
    m_players[i_player].m_balance+=i_amount;
}

//-----------------------------------------------------------------------------
unsigned int PlayerManager::getPosition() const
{
    return m_players[m_currentPlayer].m_position;
}

//-----------------------------------------------------------------------------
void PlayerManager::movePositionBy(unsigned int i_amount)
{
    unsigned int oldPosition = m_players[m_currentPlayer].m_position;

    m_players[m_currentPlayer].m_position =
            (m_players[m_currentPlayer].m_position + i_amount) % 40;
    if (m_players[m_currentPlayer].m_position < oldPosition) {
        std::cout<< "You passed from GO. Get 200\n";
        m_players[m_currentPlayer].m_balance += 200;
    }
}

//-----------------------------------------------------------------------------
void PlayerManager::setPosition(unsigned int i_position)
{
    m_players[m_currentPlayer].m_position=i_position;
}

//-----------------------------------------------------------------------------
unsigned int PlayerManager::getCurrentPlayer()const
{
    return m_currentPlayer;
}

//-----------------------------------------------------------------------------
unsigned int PlayerManager::getMoneyFromEachPlayer(unsigned int i_amount)
{
    unsigned int money=0;
    for(unsigned int i=0; i<m_players.size();++i)
    {
        if(m_players[i].takeBalance(i_amount))
        {
            money+=i_amount;
        }
        else
        {
            std::cout << m_players[i].m_name <<
                      " does not have enough money to pay " << i_amount <<"\n";
        }
    }
    return money;
}

//-----------------------------------------------------------------------------
void PlayerManager::setJailed(bool jailed)
{
    m_players[m_currentPlayer].m_isJailed = jailed;
    if (jailed) {
        m_players[m_currentPlayer].m_isJailed = 4;
        m_players[m_currentPlayer].m_position = 10;
    }
}

//-------------------------------------------------------------------------
PlayerManager::~PlayerManager()
{}

