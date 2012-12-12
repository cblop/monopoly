#include "CardMovePlayerBack.hpp"

//-------------------------------------------------------------------------
CardMovePlayerBack::CardMovePlayerBack(
        unsigned int i_position
        ):m_placesToMove(i_position)
{
}

//-------------------------------------------------------------------------
void CardMovePlayerBack::action(
        PlayerManager &i_players
        )
{
	i_players.movePositionBy(-m_placesToMove);
	std::cout<< "Move " << i_players.getName() << " back " << m_placesToMove << " spaces." << std::endl; 
}

//-------------------------------------------------------------------------
CardMovePlayerBack::~CardMovePlayerBack()
{
}


