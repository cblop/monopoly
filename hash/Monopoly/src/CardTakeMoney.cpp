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
    //i_players[currentPlayer]->addBalance(i_balance);
    std::cout << "Remove £" << m_balanceToRemove<< " from player" << std::endl;
}

//-------------------------------------------------------------------------
CardTakeMoney::~CardTakeMoney()
{
}
