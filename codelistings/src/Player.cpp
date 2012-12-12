#include <string>
#include <vector>
#include "Player.hpp"
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

bool Player::takeBalance(unsigned int i_amount)
{
    {
        if(m_balance<i_amount)
        {
            return false;
        }
        else
        {
            m_balance -= i_amount;
            return true;
        }
    }
}

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
