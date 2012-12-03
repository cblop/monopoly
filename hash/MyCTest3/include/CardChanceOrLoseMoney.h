#ifndef CARDCHANCEORLOSEMONEY_H
#define CARDCHANCEORLOSEMONEY_H

#include "Card.h"

class CardChanceOrLoseMoney :public Card
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    //-------------------------------------------------------------------------
    CardChanceOrLoseMoney(unsigned int i_balance);
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
    ~CardChanceOrLoseMoney();

private:
    //-------------------------------------------------------------------------
    /// @brief the new position of the player
    //-------------------------------------------------------------------------
    int m_balanceToAdd;
};

#endif // CARDCARDCHANCEORLOSEMONEY_H
