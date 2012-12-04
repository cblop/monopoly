#include "CardChanceOrLoseMoney.h"

//-------------------------------------------------------------------------
CardChanceOrLoseMoney::CardChanceOrLoseMoney(
        unsigned int i_balance
        ):m_balanceToRemove(i_balance)
{
}

//-------------------------------------------------------------------------
void CardChanceOrLoseMoney::action(
        const std::vector<Player *> &i_players,
        int i_currentPlayer
        )
{
    std::cout << "Would you like to take a chance (y) or Pay £" << m_balanceToRemove << " : " << std::endl;
    std::string decision = "";
    std::cin >> decision;
    
    if (decision == "y")
    {
    	std::cout << "Call Chance" << std::endl;
    }
    else if (decision == "n")
    {
        std::cout << "Remove £" << m_balanceToRemove<< " from player" << std::endl;
    }
    else 
    	std::cout << "Invalid Input. Please enter y or n" << std::endl;
}

//-------------------------------------------------------------------------
CardChanceOrLoseMoney::~CardChanceOrLoseMoney()
{
}
