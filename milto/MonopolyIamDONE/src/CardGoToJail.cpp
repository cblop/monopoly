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
	std::cout<< i_players.getName() << " IS GOING TO JAIL!!" << std::endl;
}

//-------------------------------------------------------------------------
CardGoToJail::~CardGoToJail()
{
}
