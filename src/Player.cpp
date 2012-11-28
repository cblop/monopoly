#include <string>
#include <vector>
#include "Player.h"

//-----------------------------------------------------------------------------
Player::Player(const std::string &name): m_name(name), m_balance(100)
{
    m_name = name;
    m_balance = 1500;
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
void Player::addBalance(int amount)
{
    m_balance += amount;
}

//-----------------------------------------------------------------------------
int Player::getPosition()
{
    return m_position;
}

//-----------------------------------------------------------------------------
void Player::movePositionBy(int amount)
{
    m_position += amount;
}

//-----------------------------------------------------------------------------
void Player::setPosition(int position)
{
    m_position = position;
}

//-----------------------------------------------------------------------------
Player::~Player()
{}
