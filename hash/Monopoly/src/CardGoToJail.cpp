#include "CardGoToJail.h"

//-------------------------------------------------------------------------
CardGoToJail::CardGoToJail()
{
}

//-------------------------------------------------------------------------
void CardGoToJail::action(
        const std::vector<Player *> &i_players,
        int currentPlayer
        )
{
    i_players[currentPlayer]->setJailed(true);
}

//-------------------------------------------------------------------------
CardGoToJail::~CardGoToJail()
{
}
