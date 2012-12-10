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
        PlayerManager &i_players
        )
{
    int numberOfHouses = 0;
    int numberOfHotels = 0;
    
    //Calculate How Many Houses and Hotels There Are
    
    i_players.takeBalance((numberOfHouses * m_houseRepair)
                        + (numberOfHotels * m_hotelRepair));
}


//-------------------------------------------------------------------------
CardStreetRepairs::~CardStreetRepairs()
{}
