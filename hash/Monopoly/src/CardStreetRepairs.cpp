#include "CardStreetRepairs.h"

//-------------------------------------------------------------------------
CardStreetRepairs::CardStreetRepairs(
        const unsigned int i_houseRepair,
        const unsigned int i_hotelRepair
        ):m_houseRepair(i_houseRepair),
          m_hotelRepair(i_hotelRepair)
{
}

//-------------------------------------------------------------------------
void  CardStreetRepairs::action(
        const std::vector<Player *> &i_players,
        int currentPlayer
        )
{
    //pay some money
}


//-------------------------------------------------------------------------
CardStreetRepairs::~CardStreetRepairs()
{}
