#include "CardReceiveMoney.h"

//-------------------------------------------------------------------------
CardReceiveMoney::CardReceiveMoney(
        unsigned int i_balance
        ):m_balanceToAdd(i_balance)
{
}

//-------------------------------------------------------------------------
void CardReceiveMoney::action(
        Players &i_players
        )
{
    i_players.addBalance(m_balanceToAdd);
}

//-------------------------------------------------------------------------
CardReceiveMoney::~CardReceiveMoney()
{
}
