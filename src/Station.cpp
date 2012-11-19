#include "Station.h"

//-------------------------------------------------------------------------
Station::Station(
        const std::string &i_name, double i_price
        ):Property(i_name,i_price)
{
}

//-----------------------------------------------------------------------------
void Station::printExtras()const
{
}

//-------------------------------------------------------------------------
void Station::reset()
{
//    m_isPropertyMorgated = 0;
}
