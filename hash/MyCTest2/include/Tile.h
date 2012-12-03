#ifndef INCLUDETILE_H
#define INCLUDETILE_H

#include <iostream>
#include <vector>
#include "Player.h"

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
    virtual void action(const std::vector<Player *> &i_player, int current_player)=0;
    //-------------------------------------------------------------------------
    /// @brief method that resets all its values to the default ones
    //-------------------------------------------------------------------------
    virtual void reset();
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
    /// @brief the name of the tile i.e Piccadilly, Jail and Chance
    //-------------------------------------------------------------------------
    std::string m_name;
    //-------------------------------------------------------------------------
    /// @brief the tile's index
    //-------------------------------------------------------------------------
    int index;
};

#endif // INCLUDETILE_H
