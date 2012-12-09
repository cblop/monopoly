#ifndef INCLUDETILE_H
#define INCLUDETILE_H

#include <iostream>
#include <vector>
#include "PlayerManager.h"

//-----------------------------------------------------------------------------
class Tile
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    //-------------------------------------------------------------------------
    Tile(const std::string &i_name);
    //-------------------------------------------------------------------------
    /// @brief method that does the action =p
    /// @param[in] i_player the player that have reached that specific tile
    //-------------------------------------------------------------------------
    virtual void action(PlayerManager &i_players)=0;
    //-------------------------------------------------------------------------
    /// @brief method that sets the colour of the tile
    //-------------------------------------------------------------------------
    void setColour(const std::string &i_colour);
    //-------------------------------------------------------------------------
    /// @brief method that gets the colour of the tile
    //-------------------------------------------------------------------------
    const std::string &getColour()const;
    //-------------------------------------------------------------------------
    /// @brief method that resets all its values to the default ones
    //-------------------------------------------------------------------------
    virtual void reset()=0;
    //-------------------------------------------------------------------------
    /// @brief method that returns the owner of a property
    //-------------------------------------------------------------------------
    virtual unsigned int getOwner()const;
    //-------------------------------------------------------------------------
    /// @brief method that returns house price
    //-------------------------------------------------------------------------
    virtual unsigned int getHousePrice()const;
    //-------------------------------------------------------------------------
    /// @brief returns the number of houses a property has
    //-------------------------------------------------------------------------
    virtual unsigned int getNumOfHouses()const;
    //-------------------------------------------------------------------------
    /// @brief method that builds a house to a property
    //-------------------------------------------------------------------------
    virtual bool buildHouse();
    //-------------------------------------------------------------------------
    /// @brief method that prints all the information about the tile
    //-------------------------------------------------------------------------
    virtual void print()const;
    //-------------------------------------------------------------------------
    /// @brief method that returns the name of the property
    //-------------------------------------------------------------------------
    const std::string &getName()const;
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    virtual ~Tile();

protected:
    //-------------------------------------------------------------------------
    /// @brief the colour of the tile represented by numbers.
    //-------------------------------------------------------------------------
    std::string m_colour;
    //-------------------------------------------------------------------------
    /// @brief the name of the tile i.e Piccadilly, Jail and Chance
    //-------------------------------------------------------------------------
    std::string m_name;
};

#endif // INCLUDETILE_H
