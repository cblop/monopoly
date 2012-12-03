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
    NormalProperty(const std::string &i_name,
                   double i_price,
                   double i_housePrice,
                   const std::vector<double> &i_rentPrices
                   );
    //-------------------------------------------------------------------------
    /// @brief method that prints all the information about the properties
    //-------------------------------------------------------------------------
    void printExtras()const;
    //-------------------------------------------------------------------------
    /// @brief method that resets all its values to the default ones
    //-------------------------------------------------------------------------
    void resetExtras();
    //-------------------------------------------------------------------------
    /// @brief method that does the action =p
    /// @param[in] i_player the player that have reached that specific tile
    //-------------------------------------------------------------------------
    void payRent(
            const std::vector<Player *> &i_player,
            int current_player
            );
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~NormalProperty();

private:
    //-------------------------------------------------------------------------
    /// @brief the number of houses the propertry has (0-5)
    //-------------------------------------------------------------------------
    unsigned short int m_numOfHouse;
    //-------------------------------------------------------------------------
    /// @brief the prices of renting a the property depending
    //-------------------------------------------------------------------------
    std::vector<unsigned int> m_rentPrices;
    //-------------------------------------------------------------------------
    /// @brief how much does a house cost
    //-------------------------------------------------------------------------
    double m_housePrice;

};

#endif // NORMALPROPERTY_H
