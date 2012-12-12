#include "CardReceiveMoney.hpp"

//-------------------------------------------------------------------------
CardReceiveMoney::CardReceiveMoney(
        unsigned int i_balance
        ):m_balanceToAdd(i_balance)
{
}

//-------------------------------------------------------------------------
void CardReceiveMoney::action(
        PlayerManager &i_players
        )
{
    i_players.addBalance(m_balanceToAdd);
    std::cout << "Player " << i_players.getName() << " gets " << m_balanceToAdd << "\n";
}

//-------------------------------------------------------------------------
CardReceiveMoney::~CardReceiveMoney()
{
}
