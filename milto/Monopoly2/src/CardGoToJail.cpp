#include "CardGoToJail.h"

//-------------------------------------------------------------------------
CardGoToJail::CardGoToJail()
{
}

//-------------------------------------------------------------------------
void CardGoToJail::action(
        PlayerManager &i_players
        )
{
    i_players.setJailed(true);
}

//-------------------------------------------------------------------------
CardGoToJail::~CardGoToJail()
{
}
