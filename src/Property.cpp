#include "Property.h"

//-----------------------------------------------------------------------------
Property::Property(
        const std::string &i_name,
        double i_price
        ):Tile(i_name),
    m_owner(-1),
    m_price(i_price),
    m_isPropertyMorgated(0)
{
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
        std::cout << "Mortgaged:   no\n";
    }
    printExtras();
}

//-----------------------------------------------------------------------------
void Property::buyProperty(std::vector<Player *> i_players,int i_currentPlayer)
{
    if(m_owner==-1) // player is allowed to buy property
    {
        std::cout << "Do you want to buy " << m_name
                  << " £" << m_price <<"? y/n\n";
        std::string answer;
        std::cin >> answer;
        if (answer=="y")
        {
            i_players[i_currentPlayer]->addBalance(-m_price);
            m_owner = i_currentPlayer;

        }
        else
        {
            // player does not want to buy the property
        }
    }
    else
    {
        // property already owned - pay rent
    }
}

//-----------------------------------------------------------------------------
void Property::action(
        const std::vector<Player *> &i_player,
        int current_player
        )
{
    this->print();
}


//-------------------------------------------------------------------------
Property::~Property()
{}
