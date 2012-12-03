#include <string>
#include <vector>
#include "Player.h"

//-----------------------------------------------------------------------------
Player::Player(const std::string &name)
{
    m_name = name;
    m_balance = 1500;
    m_position = 0;
}

//-----------------------------------------------------------------------------
const std::string &Player::getName() const
{
    return m_name;
}

//-----------------------------------------------------------------------------
int Player::getBalance()
{
    return m_balance;
}

//-----------------------------------------------------------------------------
void Player::addBalance(int i_amount)
{
    m_balance += i_amount;
}

//-----------------------------------------------------------------------------
bool Player::takeBalance(int i_amount)
{
    if(m_balance-i_amount <0)
    {
        return false;
    }
    else
    {
        m_balance -= i_amount;
        return true;
    }
}

//-----------------------------------------------------------------------------
int Player::getPosition()
{
    return m_position;
}

//-----------------------------------------------------------------------------
void Player::movePositionBy(int amount)
{
    int oldPosition = m_position;
    m_position = (m_position + amount) % 40;
    if (m_position < oldPosition) {
        // The player passes go
        m_balance += 200;
    }
}

//-----------------------------------------------------------------------------
void Player::setPosition(int position)
{
    m_position = position;
}

//-----------------------------------------------------------------------------
Player::~Player()
{}
