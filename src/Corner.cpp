#include "Corner.h"

//-----------------------------------------------------------------------------
Corner::Corner(const std::string &i_name):Tile(i_name)
{
}

//-----------------------------------------------------------------------------
void Corner::print()const
{
    std::cout << "-------------------------------------------------\n";
    std::cout << "Tile's name: " << m_name << "\n\n";
}

//-----------------------------------------------------------------------------
void Corner::action(Players &/*i_players*/)
{
    this->print();
}

//-------------------------------------------------------------------------
void Corner::reset()
{

}

//-------------------------------------------------------------------------
Corner::~Corner()
{}
