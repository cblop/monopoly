#ifndef CARDGOTOJAIL_H
#define CARDGOTOJAIL_H

#include "Card.h"

class CardGoToJail :public Card
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    //-------------------------------------------------------------------------
    CardGoToJail();
    //-------------------------------------------------------------------------
    /// @brief method that performs the action associated with that card
    //-------------------------------------------------------------------------
    void action(PlayerManager &i_players);
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~CardGoToJail();


};

#endif // CARDGOTOJAIL_H
