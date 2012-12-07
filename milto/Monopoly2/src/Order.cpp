#include "Order.h"

//-----------------------------------------------------------------------------
Order::Order(
        const std::string &i_name,
        const std::string &flag
        ):Tile(i_name),
          m_flag(flag),
          m_money(0)
{
}

//-----------------------------------------------------------------------------
Order::Order(
            const std::string &i_name,
            const std::string &flag,
            unsigned int i_money
            ):Tile(i_name),
              m_flag(flag),
              m_money(i_money)
{
}

//-----------------------------------------------------------------------------
void Order::print()const
{
    std::cout << "-------------------------------------------------\n";
    std::cout << "Tile's name: " << m_name << "\n\n";
    if( m_flag == "p")
    {
        std::cout << "Amount to be paid: " << m_money << "\n";
    }
    std::cout << "-------------------------------------------------\n";
}

//-----------------------------------------------------------------------------
void Order::action(
        PlayerManager & i_players
        )
{
    std::cout << "Action of Order : " << m_flag << "\n";
    if(m_flag=="p") // pay money
    {
        std::cout << i_players.getName() << "has to pay " << m_money << "\n";
        i_players.takeBalance(m_money);
    }
    else if(m_flag=="j") // go to jail
    {
        i_players.setJailed(true);
    }
    else if (m_flag == "f") // free parking, go, or visiting jail
    {
    }
    else
    {
        //wrong flag
    }
}

//-------------------------------------------------------------------------
void Order::reset()
{
}

//-------------------------------------------------------------------------
Order::~Order()
{}
