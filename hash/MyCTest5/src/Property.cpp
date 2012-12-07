#include "Property.h"

//-----------------------------------------------------------------------------
Property::Property(
        const std::string &i_name,
        double i_price
        ):Tile(i_name),
    m_owner(-1),
    m_price(i_price),
    m_isPropertyMortgaged(0)
{
}

//-----------------------------------------------------------------------------
void Property::print()const
{
    std::cout << "-------------------------------------------------\n";
    std::cout << "Tile's name: "  << m_name   << "\n"
              << "Tile's colour: "<< m_colour << "\n"
              << "Price:       "  << m_price  << "\n";
    if(m_isPropertyMortgaged)
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
void Property::buyProperty(PlayerManager &i_players)
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
        if(i_players.takeBalance(m_price))
        {
            m_owner = i_players.getCurrentPlayer();
        }
        else
        {
            std::cout<< "Player does not have enough money!\n";
        }
    }
}

//-----------------------------------------------------------------------------
void Property::reset()
{
    m_owner = -1;
    m_isPropertyMortgaged = 0;
    this->resetExtras();
}

//-----------------------------------------------------------------------------
void Property::action(PlayerManager &i_players)
{
    this->print();
    if (m_owner == -1)
    {
        this->buyProperty(i_players);
    }
    else
    {
        this->payRent(i_players);
    }
}


//-------------------------------------------------------------------------
Property::~Property()
{}
