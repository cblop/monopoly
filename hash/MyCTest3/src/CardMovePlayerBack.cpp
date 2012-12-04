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
        int currentPlayer
        )
{
    i_players[currentPlayer]->setPosition(i_players[currenPlayer]->movePositionBy(-1 * (i_position)));
}

//-------------------------------------------------------------------------
CardMovePlayerBack::~CardMovePlayerBack()
{
}


