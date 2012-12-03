#include "CardReceiveMoney.h"

//-------------------------------------------------------------------------
CardReceiveMoney::CardReceiveMoney(
        unsigned int i_balance
        ):m_balanceToRemove(i_balance)
{
}

//-------------------------------------------------------------------------
void CardReceiveMoney::action(
        const std::vector<Player *> &i_players,
        int currentPlayer
        )
{
    i_players[currentPlayer]->addBalance(i_balance);
}

//-------------------------------------------------------------------------
CardMovePlayerToPosition::~CardMovePlayerToPosition()
{
}
