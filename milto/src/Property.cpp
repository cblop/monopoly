#include "Property.h"

//-----------------------------------------------------------------------------
Property::Property(const std::string &i_name, double i_price):Tile(i_name)
{
    m_isPropertyMorgated = 0;
    m_price = i_price;
}

//-----------------------------------------------------------------------------
void Property::print()const
{
    std::cout << "-------------------------------------------------\n";
    std::cout << "Tile's name: " << m_name << "\n";
    std::cout << "Price:       " << m_price << "\n";
    if(m_isPropertyMorgated)
    {
        std::cout << "Mortgaged:   yes\n\n";
    }
    else
    {
        std::cout << "Mortgaged:   no\n\n";
    }
    printExtras();
}

//-----------------------------------------------------------------------------
void Property::action(/*const Player& i_player*/)
{

}
