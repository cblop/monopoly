#include "Station.h"
#include <vector>

//-------------------------------------------------------------------------
Station::Station(
        const std::string &i_name,
        double i_price,
        const std::vector<double> &i_rentPrices
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
    std::cout << "\n";
}

//-------------------------------------------------------------------------
void Station::reset()
{
//    m_isPropertyMorgated = 0;
}

//-------------------------------------------------------------------------
void Station::action(
        const std::vector<Player *> &i_player,
        int current_player
        )
{
    this->print();
}

//-------------------------------------------------------------------------
Station::~Station()
{}
