#include "CardMovePlayerBack.h"

//-------------------------------------------------------------------------
CardMovePlayerBack::CardMovePlayerBack(
        unsigned int i_position
        ):m_placesToMove(i_position)
{
}

//-------------------------------------------------------------------------
void CardMovePlayerBack::action(
        const std::vector<Player *> &i_players,
        int i_currentPlayer
        )
{
    i_players[i_currentPlayer]->movePositionBy(-m_placesToMove);
}

//-------------------------------------------------------------------------
CardMovePlayerBack::~CardMovePlayerBack()
{
}


