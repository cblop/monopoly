#ifndef CARDTYPE_H
#define CARDTYPE_H
#include <iostream>
#include <vector>
#include "PlayerManager.h"

class Card
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    //-------------------------------------------------------------------------
    Card();
    //-------------------------------------------------------------------------
    /// @brief method that performs the action associated with that card
    //-------------------------------------------------------------------------
    virtual void action(PlayerManager &i_players)=0;
    //-------------------------------------------------------------------------
    /// @brief method that prints the card
    //-------------------------------------------------------------------------
    void print()const;
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    virtual ~Card();

};

#endif // CARDTYPE_H
