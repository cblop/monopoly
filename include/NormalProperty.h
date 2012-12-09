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
                   unsigned int i_price,
                   unsigned int i_housePrice,
                   const std::vector<unsigned int> &i_rentPrices
                   );
    //-------------------------------------------------------------------------
    /// @brief method that prints all the information about the properties
    //-------------------------------------------------------------------------
    void printExtras()const;
    //-------------------------------------------------------------------------
    /// @brief method that returns the owner of the property
    //-------------------------------------------------------------------------
    unsigned int getOwner()const;
    //-------------------------------------------------------------------------
    /// @brief method that returns how much it cost to build a house
    //-------------------------------------------------------------------------
    unsigned int getHousePrice()const;
    //-------------------------------------------------------------------------
    /// @brief method that resets all its values to the default ones
    //-------------------------------------------------------------------------
    void resetExtras();
    //-------------------------------------------------------------------------
    /// @brief method that builds a house to a property
    //-------------------------------------------------------------------------
    bool buildHouse();
    //-------------------------------------------------------------------------
    /// @brief returns the number of houses a property has
    //-------------------------------------------------------------------------
    unsigned int getNumOfHouses()const;
    //-------------------------------------------------------------------------
    /// @brief method that does the action =p
    /// @param[in] i_player the player that have reached that specific tile
    //-------------------------------------------------------------------------
    void payRent(PlayerManager &i_players);
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~NormalProperty();

private:
    //-------------------------------------------------------------------------
    /// @brief how much does a house cost
    //-------------------------------------------------------------------------
    double m_housePrice;
    //-------------------------------------------------------------------------
    /// @brief the number of houses the propertry has (0-5)
    //-------------------------------------------------------------------------
    unsigned short int m_numOfHouses;
    //-------------------------------------------------------------------------
    /// @brief the prices of renting a the property depending
    //-------------------------------------------------------------------------
    std::vector<unsigned int> m_rentPrices;


};

#endif // NORMALPROPERTY_H
