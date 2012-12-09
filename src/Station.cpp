#include "Station.h"
#include <vector>

//-------------------------------------------------------------------------
Station::Station(
        const std::string &i_name,
        double i_price,
        const std::vector<unsigned int> &i_rentPrices
        ):Property(i_name,i_price)
{
    m_rentPrices.resize(4);
    for(unsigned int i=0; i<4; ++i)
    {
        m_rentPrices[i] = i_rentPrices[i];
    }
}

//-----------------------------------------------------------------------------
void Station::printExtras()const
{
    std::cout << "RENT PRICES: ";
    for(unsigned int i=0; i<m_rentPrices.size(); ++i)
    {
        std::cout << m_rentPrices[i] << " ";
    }
    std::cout << "\n-------------------------------------------------\n";
    std::cout << "\n";
}

//-------------------------------------------------------------------------
void Station::resetExtras()
{

}

//-------------------------------------------------------------------------
unsigned int Station::getOwner()const
{
    return m_owner;
}

//-------------------------------------------------------------------------
void Station::payRent(
        PlayerManager & i_players
        )
{
    unsigned int rent = 0;
    std::cout << "You have to pay " << rent << " for Rent\n";
    if(i_players.takeBalance(rent))
    {
        i_players.addBalance(rent,m_owner);
    }
    else
    {
        std::cout << "Player do not have enough money to pay";
        rent = i_players.quitGame();
        i_players.addBalance(rent);
    }
}

//-------------------------------------------------------------------------
Station::~Station()
{}
