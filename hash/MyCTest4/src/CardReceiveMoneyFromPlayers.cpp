#include "CardReceiveMoneyFromPlayers.h"

//-------------------------------------------------------------------------
CardReceiveMoneyFromPlayers::CardReceiveMoneyFromPlayers(
        unsigned int i_balance
        ):m_balanceToAdd(i_balance)
{
}

//-------------------------------------------------------------------------
void CardReceiveMoneyFromPlayers::action(
        const std::vector<Player *> &i_players,
        int currentPlayer
        )
{
    i_players[currentPlayer]->addBalance(m_balanceToAdd * (i_players.size() -1));
    
    for (unsigned int i = 0; i < i_players.size() ; i++)
    {
        if (i != currentPlayer)
        {
            //Remove the ammount of m_balanceToAdd from the other players
        }
    }
}

//-------------------------------------------------------------------------
CardReceiveMoneyFromPlayers::~CardReceiveMoneyFromPlayers()
{
}
