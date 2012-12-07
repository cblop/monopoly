#include "Utility.h"

//-----------------------------------------------------------------------------
Utility::Utility(
        const std::string &i_name,
        double i_price,
        const std::vector<unsigned int> &/*i_rentPrices*/
        ):Property(i_name,i_price)
{

}

//-----------------------------------------------------------------------------
void Utility::payRent(
        PlayerManager & /*i_players*/
        )
{

}

//-----------------------------------------------------------------------------
void Utility::printExtras()const
{

}

//-----------------------------------------------------------------------------
void Utility::resetExtras()
{

}

//-----------------------------------------------------------------------------
Utility::~Utility()
{}
