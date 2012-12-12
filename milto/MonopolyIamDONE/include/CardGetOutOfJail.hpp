#ifndef CARDGETOUTOFJAIL_H
#define CARDGETOUTOFJAIL_H

#include "Card.hpp"

class CardGetOutOfJail :public Card
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    //-------------------------------------------------------------------------
    CardGetOutOfJail();
    //-------------------------------------------------------------------------
    /// @brief method that performs the action associated with that card
    //-------------------------------------------------------------------------
    void action(PlayerManager &i_players);
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~CardGetOutOfJail();


};

#endif // CARDGETOUTOFJAIL_H
