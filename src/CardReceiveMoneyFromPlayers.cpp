#include "CardReceiveMoneyFromPlayers.h"

//-------------------------------------------------------------------------
CardReceiveMoneyFromPlayers::CardReceiveMoneyFromPlayers(
        unsigned int i_balance
        ):m_balanceToAdd(i_balance)
{
}

//-------------------------------------------------------------------------
void CardReceiveMoneyFromPlayers::action(
        Players &i_players
        )
{
//    i_players[currentPlayer]->addBalance(m_balanceToAdd * (i_players.size() -1));
    
//    for (unsigned int i = 0; i < i_players.size() ; i++)
//    {
//        if (i != currentPlayer)
//        {
//            i_players[i]->takeBalance(m_balanceToAdd);
//        }
//    }
}

//-------------------------------------------------------------------------
CardReceiveMoneyFromPlayers::~CardReceiveMoneyFromPlayers()
{
}
