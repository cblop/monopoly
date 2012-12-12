#include "GetACardTIle.hpp"

//-------------------------------------------------------------------------
GetACardTIle::GetACardTIle(
        const std::string &m_name,
        CardsManager &i_cardDesks
        ):Tile(m_name),
          m_cardDecks(i_cardDesks)
{
}

//-------------------------------------------------------------------------
void GetACardTIle::action(PlayerManager &i_players)
{
    m_cardDecks.action(i_players,m_name);
}

//-------------------------------------------------------------------------
void GetACardTIle::reset()
{
}
