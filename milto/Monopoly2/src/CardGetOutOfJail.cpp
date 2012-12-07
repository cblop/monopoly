#include "CardGetOutOfJail.h"

//-------------------------------------------------------------------------
CardGetOutOfJail::CardGetOutOfJail()
{
}

//-------------------------------------------------------------------------
void CardGetOutOfJail::action(PlayerManager &i_players)
{
    i_players.setJailed(false);
}

//-------------------------------------------------------------------------
CardGetOutOfJail::~CardGetOutOfJail()
{
}
