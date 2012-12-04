#include "Utility.h"

//-----------------------------------------------------------------------------
Utility::Utility(
        const std::string &i_name,
        double i_price,
        const std::vector<double> &i_rentPrices
        ):Property(i_name,i_price)
{

}

//-----------------------------------------------------------------------------
void Utility::payRent(
        const std::vector<Player *> &i_player,
        int current_player
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
