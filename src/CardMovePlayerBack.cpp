#include "CardMovePlayerBack.h"

//-------------------------------------------------------------------------
CardMovePlayerBack::CardMovePlayerBack(
        unsigned int i_position
        ):m_placesToMove(i_position)
{
}

//-------------------------------------------------------------------------
void CardMovePlayerBack::action(
        Players &i_players
        )
{
    i_players.movePositionBy(-m_placesToMove);
}

//-------------------------------------------------------------------------
CardMovePlayerBack::~CardMovePlayerBack()
{
}


