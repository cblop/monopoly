#include "Utility.h"
#include "Dice.h"

//-----------------------------------------------------------------------------
Utility::Utility(
        const std::string &i_name,
        double i_price,
        const std::vector<unsigned int> &i_rentPrices
        ):Property(i_name,i_price)
{
    m_rentPrices.resize(2);
    for(unsigned int i=0; i<2; ++i)
    {
        m_rentPrices[0] = i_rentPrices[0];
        m_rentPrices[1] = i_rentPrices[1];
    }
}

//-----------------------------------------------------------------------------
void Utility::payRent(
        PlayerManager & i_players
        )
{
    Dice dice;
    dice.roll();
    const unsigned int amountTobePaid = dice.getTotal() *m_rentPrices[0];
    if(i_players.takeBalance(amountTobePaid))
    {
        std::cout << "You have paid " << amountTobePaid << " rent.\n";
        i_players.addBalance(amountTobePaid,m_owner);
    }
    else
    {
        std::cout << "You do not have enough money to pay!\n";
        i_players.withdrawGame();
    }
}

//-----------------------------------------------------------------------------
unsigned int Utility::getOwner()const
{
    return m_owner;
}

//-----------------------------------------------------------------------------
void Utility::printExtras()const
{
    std::cout << "-------------------------------------------------\n";
}

//-----------------------------------------------------------------------------
void Utility::resetExtras()
{
}

//-----------------------------------------------------------------------------
Utility::~Utility()
{}
