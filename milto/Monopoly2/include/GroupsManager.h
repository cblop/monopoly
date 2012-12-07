#ifndef GROUPSMANAGER_H
#define GROUPSMANAGER_H

#include <iostream>
#include <vector>
#include "GroupOfProperties.h"

class GroupsManager
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    //-------------------------------------------------------------------------
    GroupsManager();
    //-------------------------------------------------------------------------
    /// @brief method that adds a tile to the relations class
    /// @param[in] i_colour the colour of the tile
    /// @param[in] i_position the positiong of the tile on the board;
    //-------------------------------------------------------------------------
    void addTile(const std::string &i_colour,Tile *i_tile);
    //-------------------------------------------------------------------------
    /// @brief method that builds houses to a group of properties
    //-------------------------------------------------------------------------
    unsigned int buildHouses(
            unsigned int i_owner,
            const std::string &i_colour,
            unsigned int i_number
            );
    //-------------------------------------------------------------------------
    /// @brief method that prints all the tiles in groups
    //-------------------------------------------------------------------------
    void print()const;
    //-------------------------------------------------------------------------
    /// @brief method that sells houses from a group of properties
    ///        returns amount of money that the player gets
    //-------------------------------------------------------------------------
    unsigned int sellHouses(std::string i_colour, unsigned int i_number);
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~GroupsManager();

private:
    //-------------------------------------------------------------------------
    /// @brief method that checks whether the given owner has permission to
    ///        build or sell houses to that group of properties
    /// @brief returns the index of the group or -1 if the owner is not allowed
    /// @param[in] i_owner the owner that wants to build houses
    /// @param[in] i_colour the colour of the group that the owner wants to
    ///                     build houses on or to sell houses
    //-------------------------------------------------------------------------
    unsigned int allowedToBuildOrSellHouses(
            unsigned int i_owner,
            const std::string &i_colour
            );
    //-------------------------------------------------------------------------
    /// @brief all the groups of properties ie, stations and blue properties
    //-------------------------------------------------------------------------
    std::vector<GroupOfProperties> m_groups;

};

#endif // PROPERTIESRELATIONS_H
