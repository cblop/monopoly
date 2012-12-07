#include "NormalProperty.h"

//-------------------------------------------------------------------------
NormalProperty::NormalProperty(
        const std::string &i_name,
        unsigned int i_price,
        unsigned int i_housePrice,
        const std::vector<unsigned int> &i_rentPrices
        ):Property(i_name,i_price),
          m_housePrice(i_housePrice)
{
    m_rentPrices.resize(6);
    for(unsigned int i=0; i<6; ++i)
    {
        m_rentPrices[i] = i_rentPrices[i];
    }
}

//-------------------------------------------------------------------------
void NormalProperty::printExtras()const
{
    std::cout << "House Price: " << m_housePrice << "\n";
    std::cout << "Rent Prices: ";
    for(unsigned int i=0; i<6; ++i)
    {
        std::cout << m_rentPrices[i] << " ";
    }
    std::cout << "\n\n";
}

//-------------------------------------------------------------------------

void NormalProperty::payRent(
        PlayerManager &i_players
        )
{
    if(i_players.takeBalance(m_rentPrices[m_numOfHouse]))
    {
        i_players.addBalance(m_rentPrices[m_numOfHouse],m_owner);
        std::cout << "Rent paid: " << m_rentPrices[m_numOfHouse] << std::endl;
    }
    else
    {
        std::cout << "Player does not have enough money to pay\n";
    }
}


//-------------------------------------------------------------------------
void NormalProperty::resetExtras()
{
    m_numOfHouse = 0;
}

//-------------------------------------------------------------------------
NormalProperty::~NormalProperty()
{}
