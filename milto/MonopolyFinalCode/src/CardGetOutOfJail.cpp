#include "CardGetOutOfJail.hpp"

//-------------------------------------------------------------------------
CardGetOutOfJail::CardGetOutOfJail()
{
}

//-------------------------------------------------------------------------
void CardGetOutOfJail::action(PlayerManager &i_players)
{
    i_players.setJailed(false);
    std::cout<< i_players.getName() << " Gets a Get Out of Jail Card " << std::endl;
}

//-------------------------------------------------------------------------
CardGetOutOfJail::~CardGetOutOfJail()
{
}
