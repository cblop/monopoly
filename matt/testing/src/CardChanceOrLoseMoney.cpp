#include "CardChanceOrLoseMoney.h"


//-----------------------------------------------------------------------------
CardChanceOrLoseMoney::CardChanceOrLoseMoney(
        unsigned int i_balance
        ):m_balanceToRemove(i_balance)
{
}

//-----------------------------------------------------------------------------
void CardChanceOrLoseMoney::action(
        PlayerManager &i_players
        )
{
    std::cout << "Would you like to take a chance (Enter 'y') or Pay £" <<
                 m_balanceToRemove << " (Enter 'n'): " << std::endl;
    std::string decision = "";
    std::cin >> decision;
    
    if (decision == "y")
    {
    	std::cout << "[Call Chance]" << std::endl;

    }
    else if (decision == "n")
    {
        if(i_players.takeBalance(m_balanceToRemove))
        {
            std::cout<< i_players.getName() << " paid " << m_balanceToRemove << std::endl;
        }
        else
        {
            std::cout << i_players.getName()
                      << " does not have enough money to pay" << std::endl;
        }

    }
    else 
    	std::cout << "Invalid Input. Please enter y or n" << std::endl;
}

//-----------------------------------------------------------------------------
CardChanceOrLoseMoney::~CardChanceOrLoseMoney()
{
}
