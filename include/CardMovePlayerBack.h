#ifndef CARDMOVEPLAYERBACK_H
#define CARDMOVEPLAYERBACK_H

#include "Card.h"

class CardMovePlayerBack :public Card
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constractor
    //-------------------------------------------------------------------------
    CardMovePlayerBack(unsigned int i_position);
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
    ~CardMovePlayerBack();

private:
    //-------------------------------------------------------------------------
    /// @brief the new position of the player
    //-------------------------------------------------------------------------
    int m_placesToMove;
};

#endif // CARDMOVEPLAYERTOBACK_H
