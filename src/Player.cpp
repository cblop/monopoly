#include <string>
#include <vector>
#include "Player.h"

Player::Player(std::string name): m_name(name), m_balance(100)
{
    m_name = name;
    m_balance = 1500;
}

std::string Player::getName()
{
    return m_name;
}

int Player::getBalance()
{
    return m_balance;
}

void Player::addBalance(int amount)
{
    m_balance += amount;
}

void Player::removeBalance(int amount)
{
    m_balance -= amount;
}

