#include "NormalProperty.h"

//-------------------------------------------------------------------------
NormalProperty::NormalProperty(
        const std::string &i_name,
        double i_price,
        double i_housePrice,
        const std::vector<double> &i_rentPrices
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
        const std::vector<Player *> &i_player,
        int current_player
        )
{
    this->print();
    if (m_owner == -1) {
        this->buyProperty(i_player,current_player);
    }
    else {
        i_player[current_player]->takeBalance(m_rentPrices[m_numOfHouse]);
        i_player[m_owner]->addBalance(m_rentPrices[m_numOfHouse]);
        std::cout << "Rent paid: " << m_rentPrices[m_numOfHouse] << std::endl;
    }
}


//-------------------------------------------------------------------------
void NormalProperty::reset()
{

}

//-------------------------------------------------------------------------
NormalProperty::~NormalProperty()
{}
