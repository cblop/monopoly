#ifndef CARDTYPE_H
#define CARDTYPE_H
#include <iostream>
#include <vector>
#include "Player.h"

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
    virtual void action(
            const std::vector<Player *> &i_players,
            int currentPlayer
            )=0;

    //-------------------------------------------------------------------------
    void print()const;

    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~Card();

private:
    //-------------------------------------------------------------------------
    /// @brief the message written on the Card
    //-------------------------------------------------------------------------
    std::string m_message;



};

#endif // CARDTYPE_H
