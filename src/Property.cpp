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
    char response;
    std::cout << "Would you like to buy this property? (y/n): ";
    std::cin >> response;
    while ((response != 'y') && (response != 'n')){
            std::cout << std::endl << "Please type 'y' or 'n': ";
            std::cin >> response;
            std::cout << response;
    }

    if (response == 'y') {
        if(i_players[i_currentPlayer]->takeBalance(m_price))
        {
            std::cout<<"Money makes the world go round!!!\n";
            m_owner = i_currentPlayer;
        }
        else
        {
            std::cout<< "Player does not have enough money!\n";
        }
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
