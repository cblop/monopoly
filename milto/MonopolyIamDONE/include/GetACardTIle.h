#ifndef GETACARDTILE_H
#define GETACARDTILE_H

#include "CardsManager.h"
#include "Tile.h"

class GetACardTIle  : public Tile
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    //-------------------------------------------------------------------------
    GetACardTIle(
            const std::string &m_name,
            CardsManager & i_cardDesks
            );
    //-------------------------------------------------------------------------
    /// @brief method that does the action =p
    /// @param[in] i_players the players of the game
    //-------------------------------------------------------------------------
    void action(PlayerManager &i_players);
    //-------------------------------------------------------------------------
    /// @brief method that resets all its values to the default ones
    //-------------------------------------------------------------------------
    void reset();

private:
    //-------------------------------------------------------------------------
    /// @brief the card decks
    //-------------------------------------------------------------------------
    CardsManager &m_cardDecks;
};

#endif // GETACARDTILE_H
