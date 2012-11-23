#ifndef NORMALPROPERTY_H
#define NORMALPROPERTY_H

#include "Property.h"
#include <vector>

class NormalProperty: public Property
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    //-------------------------------------------------------------------------
    NormalProperty(const std::string &i_name, double i_price);
    //-------------------------------------------------------------------------
    /// @brief method that prints all the information about the properties
    //-------------------------------------------------------------------------
    void printExtras()const;

private:
    //-------------------------------------------------------------------------
    /// @brief the number of houses the propertry has (0-5)
    //-------------------------------------------------------------------------
    unsigned short int m_numOfHouse;
    //-------------------------------------------------------------------------
    /// @brief the prices of the property with houses
    //-------------------------------------------------------------------------
//    const std::vector<unsigned int> m_prices;
    //-------------------------------------------------------------------------
    /// @brief how much does a house cost
    //-------------------------------------------------------------------------
    double m_houseCost;

};

#endif // NORMALPROPERTY_H
