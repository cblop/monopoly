#ifndef PROPERTY_H
#define PROPERTY_H

#include "Tile.h"

class Property: public Tile
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    /// @param[in] i_name: the name of the tile
    /// @param[in] i_price: the price of the property
    //-------------------------------------------------------------------------
    Property(const std::string &i_name, double i_price);
    //-------------------------------------------------------------------------
    /// @brief method that prints all the information about the Property
    //-------------------------------------------------------------------------
    void print()const;
    //-------------------------------------------------------------------------
    /// @brief method that does the action =p
    /// @param[in] i_player the player that have reached that specific tile
    //-------------------------------------------------------------------------
    void action(/*const Player& i_: Property(
                        i_name,i_price
                        ){}player*/);
private:
    //-------------------------------------------------------------------------
    /// @brief method that prints any extra a property may have, ie: houses
    //-------------------------------------------------------------------------
    virtual void printExtras()const=0;

protected:
    //-----------------------------------------------------------------------------
    /// @brief the price of the property
    //-----------------------------------------------------------------------------
    double m_price;
    //-----------------------------------------------------------------------------
    /// @brief indicated whether the property is morgated or not, 1 for morgated
    //-----------------------------------------------------------------------------
    bool m_isPropertyMorgated;
    //-----------------------------------------------------------------------------


};

#endif // PROPERTY_H
