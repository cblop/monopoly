#include "Order.h"

//-----------------------------------------------------------------------------
Order::Order(const std::string &i_name):Tile(i_name)
{
}

//-----------------------------------------------------------------------------
void Order::print()const
{
    std::cout << "-------------------------------------------------\n";
    std::cout << "Tile's name: " << m_name << "\n\n";
}

//-----------------------------------------------------------------------------
void Order::action(
        const std::vector<Player *> &i_player,
        int current_player
        )
{

}

//-------------------------------------------------------------------------
Order::~Order()
{}
