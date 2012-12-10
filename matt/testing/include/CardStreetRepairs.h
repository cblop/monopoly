#ifndef CARDSTREETREPAIRS_H
#define CARDSTREETREPAIRS_H

#include "Card.h"
#include <iostream>
#include <vector>

class CardStreetRepairs : public Card
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    //-------------------------------------------------------------------------
    CardStreetRepairs(
            const unsigned int i_houseRepair,
            const unsigned int i_hotelRepair
            );
    //-------------------------------------------------------------------------
    /// @brief the action that will be performed
    //-------------------------------------------------------------------------
    void action(PlayerManager &i_players);
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~CardStreetRepairs();

private:
    //-------------------------------------------------------------------------
    /// @brief price to repair a house
    //-------------------------------------------------------------------------
    unsigned int m_houseRepair;
    //-------------------------------------------------------------------------
    /// @brief price to repair a hotel
    //-------------------------------------------------------------------------
    unsigned int m_hotelRepair;

};

#endif // STREETREPAIRS_H
