#ifndef CARDTAKEMONEY_H
#define CARDTAKEMONEY_H

#include "Card.h"

class CardTakeMoney :public Card
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    //-------------------------------------------------------------------------
    CardTakeMoney(unsigned int i_balance);
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
    ~CardTakeMoney();

private:
    //-------------------------------------------------------------------------
    /// @brief the new position of the player
    //-------------------------------------------------------------------------
    int m_balanceToRemove;
};

#endif // CARDTAKEMONEY_H
