#ifndef PROPERTY_H
#define PROPERTY_H

#include "Tile.hpp"

class Property: public Tile
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    /// @param[in] i_name: the name of the tile
    /// param[in] i_price: the price of the property
    //-------------------------------------------------------------------------
    Property(const std::string &i_name, double i_price);
    //-------------------------------------------------------------------------
    /// @brief method that prints all the information about the Property
    //-------------------------------------------------------------------------
    void print()const;
    //-------------------------------------------------------------------------
    /// @brief method that resets all the values of the Tile
    //-------------------------------------------------------------------------
    void reset();
    //-------------------------------------------------------------------------
    /// @brief method that returns the owner of the property
    //-------------------------------------------------------------------------
    virtual unsigned int getOwner()const=0;
    //-------------------------------------------------------------------------
    /// @brief method that does the action =p
    /// @param[in] i_player the player that have reached that specific tile
    //-------------------------------------------------------------------------
    virtual void action(PlayerManager &i_players);
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    virtual ~Property();

private:
    //-------------------------------------------------------------------------
    /// @brief method that resets the values of any extra members of property
    //-------------------------------------------------------------------------
    virtual void resetExtras()=0;
    //-------------------------------------------------------------------------
    /// @brief method that prints any extra a property may have, ie: houses
    //-------------------------------------------------------------------------
    virtual void printExtras()const=0;
    //-------------------------------------------------------------------------
    /// @brief method that the current player pays rent to the owner
    //-------------------------------------------------------------------------
    virtual void payRent(PlayerManager &i_players)=0;

protected:
    //-------------------------------------------------------------------------
    /// @brief method to buy property
    //-------------------------------------------------------------------------
    void buyProperty(PlayerManager &i_players);
    //-------------------------------------------------------------------------
    /// @brief the owner of the the property, equals to -1 if it is not owned
    //-------------------------------------------------------------------------
    int m_owner;
    //-------------------------------------------------------------------------
    /// @brief the price of the property
    //-------------------------------------------------------------------------
    const int m_price;
    //-------------------------------------------------------------------------
    /// @brief indicated whether the property is morgated or not,1 for morgated
    //-------------------------------------------------------------------------
    bool m_isPropertyMortgaged;
    //-------------------------------------------------------------------------


};

#endif // PROPERTY_H
