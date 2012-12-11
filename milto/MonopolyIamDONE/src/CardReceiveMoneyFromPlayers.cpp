#include "CardReceiveMoneyFromPlayers.h"

//-----------------------------------------------------------------------------
CardReceiveMoneyFromPlayers::CardReceiveMoneyFromPlayers(
        unsigned int i_balance
        ):m_balanceToAdd(i_balance)
{
}

//-----------------------------------------------------------------------------
void CardReceiveMoneyFromPlayers::action(
        PlayerManager &i_players
        )
{
	//Uses method in PlayerManager 
    i_players.takeBalance(i_players.getMoneyFromEachPlayer(m_balanceToAdd));
}

//-----------------------------------------------------------------------------
CardReceiveMoneyFromPlayers::~CardReceiveMoneyFromPlayers()
{
}
