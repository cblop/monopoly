#ifndef PROPERTY_H
#define PROPERTY_H

#include "Tile.h"

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
    /// @brief method that does the action =p
    /// @param[in] i_player the player that have reached that specific tile
    //-------------------------------------------------------------------------
    virtual void action(
            const std::vector<Player *> &i_player,
            int current_player
            )=0;
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    virtual ~Property();

private:
    //-------------------------------------------------------------------------
    /// @brief method that prints any extra a property may have, ie: houses
    //-------------------------------------------------------------------------
    virtual void printExtras()const=0;

protected:

    //-------------------------------------------------------------------------
    /// @brief method to buy property
    //-------------------------------------------------------------------------
    void buyProperty(std::vector<Player *> i_players, int i_currentPlayer);

    //-----------------------------------------------------------------------------
    /// @brief the owner of the the property, equals to -1 if it is not owned
    //-----------------------------------------------------------------------------
    int m_owner;
    //-----------------------------------------------------------------------------
    /// @brief the price of the property
    //-----------------------------------------------------------------------------
<<<<<<< HEAD
    int m_price;
=======
    const double m_price;
>>>>>>> d82e9ec9635f7059b71b04b048333385d411cfb6
    //-----------------------------------------------------------------------------
    /// @brief indicated whether the property is morgated or not, 1 for morgated
    //-----------------------------------------------------------------------------
    bool m_isPropertyMorgated;
    //-----------------------------------------------------------------------------


};

#endif // PROPERTY_H
