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
    std::cout << "\n\n";
}

//-------------------------------------------------------------------------
void Station::resetExtras()
{
}

//-------------------------------------------------------------------------
void Station::payRent(
        Players & /*i_players*/
        )
{
    this->print();
}

//-------------------------------------------------------------------------
Station::~Station()
{}
