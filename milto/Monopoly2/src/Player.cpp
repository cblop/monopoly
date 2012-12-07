#include <string>
#include <vector>
#include "Player.h"
#include <iostream>

//-----------------------------------------------------------------------------
Player::Player(
        ):m_balance(1500),
          m_position(0),
          m_isJailed(0),
    m_numOfGetOutOfJailCards(0)
{}

//-----------------------------------------------------------------------------
Player::Player(
            const std::string &name
            ): m_name(name),
               m_balance(1500),
               m_position(0),
               m_isJailed(false)
{}

//-----------------------------------------------------------------------------
void Player::setName(const std::string &i_name)
{
    m_name=i_name;
}

//-----------------------------------------------------------------------------
void Player::reset()
{
    m_balance = 1500;
    m_position = 0;
    m_isJailed = false;
}

//-----------------------------------------------------------------------------
unsigned int Player::getPossessionsValue()const
{
    return m_balance;
}

//-----------------------------------------------------------------------------
Player::~Player()
{}
