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
    std::cout<< "Move " << i_players.getName() << " to " << i_players.getPosition() << " position." << std::endl;
}

//-------------------------------------------------------------------------
CardMovePlayerToPosition::~CardMovePlayerToPosition()
{
}


