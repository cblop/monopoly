#include "CardTakeMoney.h"

//-------------------------------------------------------------------------
CardTakeMoney::CardTakeMoney(
        unsigned int i_balance
        ):m_balanceToRemove(i_balance)
{
}

//-------------------------------------------------------------------------
void CardTakeMoney::action(
        PlayerManager &i_players
        )
{
    if(i_players.takeBalance(m_balanceToRemove))
    {
        std::cout << "Player " << i_players.getName() << " paid "
                  << m_balanceToRemove << "\n";
    }
    else
    {
        std::cout << "Player " << i_players.getName()
                  << "does not have enough money to pay\n";
    }
}

//-------------------------------------------------------------------------
CardTakeMoney::~CardTakeMoney()
{
}
