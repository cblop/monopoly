#include "CardGetOutOfJail.h"

//-------------------------------------------------------------------------
CardGetOutOfJail::CardGetOutOfJail()
{
}

//-------------------------------------------------------------------------
void CardGetOutOfJail::action(
        const std::vector<Player *> &i_players,
        int currentPlayer
        )
{
    i_players[currentPlayer]->setJailed(false);
}

//-------------------------------------------------------------------------
CardGoToJail::~CardGetOutOfJail()
{
}
