#ifndef CARDMOVEPLAYERTOPOSITION_H
#define CARDMOVEPLAYERTOPOSITION_H

#include "Card.h"

class CardMovePlayerToPosition :public Card
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constractor
    //-------------------------------------------------------------------------
    CardMovePlayerToPosition(unsigned int i_position);
    //-------------------------------------------------------------------------
    /// @brief method that performs the action associated with that card
    //-------------------------------------------------------------------------
    void action(PlayerManager &i_players);
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~CardMovePlayerToPosition();

private:
    //-------------------------------------------------------------------------
    /// @brief the new position of the player
    //-------------------------------------------------------------------------
    int m_newPosition;
};

#endif // CARDMOVEPLAYERTOPOSITION_H
