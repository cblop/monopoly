#include "CardReceiveMoney.h"

//-------------------------------------------------------------------------
CardReceiveMoney::CardReceiveMoney(
        unsigned int i_balance
        ):m_balanceToAdd(i_balance)
{
}

//-------------------------------------------------------------------------
void CardReceiveMoney::action(
        const std::vector<Player *> &i_players,
        int currentPlayer
        )
{
    i_players[currentPlayer]->addBalance(m_balanceToAdd);
}

//-------------------------------------------------------------------------
CardReceiveMoney::~CardReceiveMoney()
{
}
