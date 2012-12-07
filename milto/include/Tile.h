#ifndef INCLUDETILE_H
#define INCLUDETILE_H

#include <iostream>
#include <vector>
#include "Players.h"

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
    virtual void action(Players &i_players)=0;
    //-------------------------------------------------------------------------
    /// @brief method that sets the colour of the tile
    //-------------------------------------------------------------------------
    void setColour(const unsigned int i_colour);
    //-------------------------------------------------------------------------
    /// @brief method that gets the colour of the tile
    //-------------------------------------------------------------------------
    unsigned int getColour()const;
    //-------------------------------------------------------------------------
    /// @brief method that resets all its values to the default ones
    //-------------------------------------------------------------------------
    virtual void reset()=0;
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
    unsigned int m_colour;
    //-------------------------------------------------------------------------
    /// @brief the name of the tile i.e Piccadilly, Jail and Chance
    //-------------------------------------------------------------------------
    std::string m_name;
};

#endif // INCLUDETILE_H
