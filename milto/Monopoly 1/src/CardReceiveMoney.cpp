#include "CardReceiveMoney.h"

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
    std::cout << "Player " << i_players.getName()
              << " gets " << m_balanceToAdd << "\n";
    i_players.addBalance(m_balanceToAdd);
}

//-------------------------------------------------------------------------
CardReceiveMoney::~CardReceiveMoney()
{
}
