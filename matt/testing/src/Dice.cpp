#include <stdlib.h>
#include <iostream>
#include "Dice.h"


//-----------------------------------------------------------------------------
Dice::Dice()
{
    m_values.resize(2);
    roll();
}

//-----------------------------------------------------------------------------
void Dice::roll()
{
    m_values[0] = (rand() % 6) + 1;
    m_values[1] = (rand() % 6) + 1;
}

//-----------------------------------------------------------------------------
const std::vector<unsigned int> &Dice::getValues()const
{
    return m_values;
}

//-----------------------------------------------------------------------------
unsigned int Dice::getTotal()const
{
    //return (m_values[0] + m_values[1]);
    int total = 1;
    std::cout << "Enter value: ";
    std:: cin >> total;
    return total;
}

//-----------------------------------------------------------------------------
void Dice::print()const
{
    std::cout << "Dice : " << m_values[0] << " " << m_values[1] << "\n";
}

//-----------------------------------------------------------------------------
bool Dice::isDouble() const
{
    return (m_values[0] == m_values[1]);
}


//-----------------------------------------------------------------------------
Dice::~Dice()
{}
