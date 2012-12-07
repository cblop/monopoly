#include "CardMovePlayerToPosition.h"

//-------------------------------------------------------------------------
CardMovePlayerToPosition::CardMovePlayerToPosition(
        unsigned int i_position
        ):m_newPosition(i_position)
{
}

//-------------------------------------------------------------------------
void CardMovePlayerToPosition::action(
        PlayerManager &i_players
        )
{
    i_players.setPosition(m_newPosition);
}

//-------------------------------------------------------------------------
CardMovePlayerToPosition::~CardMovePlayerToPosition()
{
}


