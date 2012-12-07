#include "CardTakeMoney.h"

//-------------------------------------------------------------------------
CardTakeMoney::CardTakeMoney(
        unsigned int i_balance
        ):m_balanceToRemove(i_balance)
{
}

//-------------------------------------------------------------------------
void CardTakeMoney::action(
        const std::vector<Player *> &i_players,
        int currentPlayer
        )
{
    i_players[currentPlayer]->takeBalance(m_balanceToRemove);
}

//-------------------------------------------------------------------------
CardTakeMoney::~CardTakeMoney()
{
}
