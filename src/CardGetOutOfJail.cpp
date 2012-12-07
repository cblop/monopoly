#include "CardGetOutOfJail.h"

//-------------------------------------------------------------------------
CardGetOutOfJail::CardGetOutOfJail()
{
}

//-------------------------------------------------------------------------
void CardGetOutOfJail::action(Players &i_players)
{
    i_players.setJailed(false);
}

//-------------------------------------------------------------------------
CardGetOutOfJail::~CardGetOutOfJail()
{
}
