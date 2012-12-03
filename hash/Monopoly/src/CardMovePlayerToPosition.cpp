#include "CardMovePlayerToPosition.h"

//-------------------------------------------------------------------------
CardMovePlayerToPosition::CardMovePlayerToPosition(
        unsigned int i_position
        ):m_newPosition(i_position)
{
}

//-------------------------------------------------------------------------
void CardMovePlayerToPosition::action(
        const std::vector<Player *> &i_players,
        int currentPlayer
        )
{
    i_players[currentPlayer]->setPosition(m_newPosition);
}

//-------------------------------------------------------------------------
CardMovePlayerToPosition::~CardMovePlayerToPosition()
{
}


