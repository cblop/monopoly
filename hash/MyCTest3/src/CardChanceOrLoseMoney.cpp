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
        int currentPlayer
        )
{
    std::cout << "Would you like to take a chance (y) or Pay £" << i_balance << " : " << std::endl;
    string decision = ""; 
    cin >> decision;
    
    if (decision == "y")
    {
    	std::cout << "Call Chance" << std::endl;
    }
    else if (decision == "n")
    {
    	std::cout << "Remove £" << i_balance<< " from player" << std::endl;
    }
    else 
    	std::cout << "Invalid Input. Please enter y or n" << std::endl;
}

//-------------------------------------------------------------------------
CardChanceOrLoseMoney::~CardChanceOrLoseMoney()
{
}
