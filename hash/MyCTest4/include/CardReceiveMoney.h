#ifndef CARDRECEIVEMONEY_H
#define CARDRECEIVEMONEY_H

#include "Card.h"

class CardReceiveMoney :public Card
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    //-------------------------------------------------------------------------
    CardReceiveMoney(unsigned int i_balance);
    //-------------------------------------------------------------------------
    /// @brief method that performs the action associated with that card
    //-------------------------------------------------------------------------
    void action(
            const std::vector<Player *> &i_players,
            int currentPlayer
            );
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~CardReceiveMoney();

private:
    //-------------------------------------------------------------------------
    /// @brief the new position of the player
    //-------------------------------------------------------------------------
    int m_balanceToAdd;
};

#endif // CARDRECEIVEMONEY_H
