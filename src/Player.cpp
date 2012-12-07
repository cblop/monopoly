#include <string>
#include <vector>
#include "Player.h"

//-----------------------------------------------------------------------------
Player::Player(
        ):m_balance(1500),
          m_position(0),
          m_isJailed(false)
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
unsigned int Player::isPlayerStillOnTheGame()const
{
    if(m_balance>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
unsigned int Player::getPosition()const
{
    return m_position;
}

//-----------------------------------------------------------------------------
void Player::movePositionBy(int amount)
{
    unsigned int oldPosition = m_position;
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
unsigned int Player::getPossessionsValue()const
{
    return m_balance;
}

//-----------------------------------------------------------------------------
void Player::setJailed(bool jailed)
{
    m_isJailed = jailed;
    if (jailed) {
        m_position = 10;
    }

}

//-----------------------------------------------------------------------------
Player::~Player()
{}
