#ifndef CORNER_H
#define CORNER_H

#include "Tile.h"
#include <iostream>

class Corner: public Tile
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    /// @param[in] i_name: the name of the tile
    //-------------------------------------------------------------------------
    Corner(const std::string &i_name);
    //-------------------------------------------------------------------------
    /// @brief method that prints all the information about the Corner
    //-------------------------------------------------------------------------
    void print()const;
    //-------------------------------------------------------------------------
    /// @brief method that resets all its values to the default ones
    //-------------------------------------------------------------------------
    void reset();
    //-------------------------------------------------------------------------
    /// @brief method that does the action =p
    /// @param[in] i_player the player that have reached that specific tile
    //-------------------------------------------------------------------------
    void action(Players &i_player);
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~Corner();

};

#endif // CORNER_H
