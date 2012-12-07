#include "CardGoToJail.h"

//-------------------------------------------------------------------------
CardGoToJail::CardGoToJail()
{
}

//-------------------------------------------------------------------------
void CardGoToJail::action(
        Players &i_players
        )
{
    i_players.setJailed(true);
}

//-------------------------------------------------------------------------
CardGoToJail::~CardGoToJail()
{
}
