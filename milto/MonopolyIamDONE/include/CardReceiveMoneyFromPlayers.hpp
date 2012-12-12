#ifndef CARDRECEIVEMONEYFROMPLAYERS_H
#define CARDRECEIVEMONEYFROMPLAYERS_H

#include "Card.hpp"

class CardReceiveMoneyFromPlayers :public Card
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    //-------------------------------------------------------------------------
    CardReceiveMoneyFromPlayers(unsigned int i_balance);
    //-------------------------------------------------------------------------
    /// @brief method that performs the action associated with that card
    //-------------------------------------------------------------------------
    void action(PlayerManager &i_players);
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~CardReceiveMoneyFromPlayers();

private:
    //-------------------------------------------------------------------------
    /// @brief the new position of the player
    //-------------------------------------------------------------------------
    int m_balanceToAdd;
};

#endif // CARDRECEIVEMONEYFROMPLAYERS_H
