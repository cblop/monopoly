#ifndef GROUPOFPROPERTIES_H
#define GROUPOFPROPERTIES_H

#include <iostream>
#include "Tile.h"

class GroupOfProperties
{
    friend class GroupsManager;
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    /// @param[in] i_colour the colour of the property
    //-------------------------------------------------------------------------
    GroupOfProperties(const std::string &i_colour);
    //-------------------------------------------------------------------------
    /// @brief constructor
    /// @param[in] i_colour the colour of the property
    /// @param[in] i_tile first tile to be added to the group
    //-------------------------------------------------------------------------
    GroupOfProperties(const std::string &i_colour, Tile *i_tile);
    //-------------------------------------------------------------------------
    /// @brief copy constructor
    /// @param[in] i_group group to be copied
    //-------------------------------------------------------------------------
    GroupOfProperties(const GroupOfProperties& i_group);
    //-------------------------------------------------------------------------
    /// @brief method that adds a tile to the end of m_tiles
    ///        returns true if item has been added
    ///        returns false if item does not belong to that group
    /// @param[in] i_tile pointer to the tile added to the group
    /// @param[in] i_colour the colour of the tile
    //-------------------------------------------------------------------------
    bool addTile(const std::string i_colour, Tile *i_tile);
    //-------------------------------------------------------------------------
    /// @brief method that returns house price
    //-------------------------------------------------------------------------
    unsigned int getHousePrice()const;
    //-------------------------------------------------------------------------
    /// @brief returns the number of properties the given Player owns
    /// @param[in] the index of the player of our interest
    //-------------------------------------------------------------------------
    unsigned int getNumOfOwns(unsigned int i_player)const;
    //-------------------------------------------------------------------------
    /// @brief method that prints all the properties that belong to that group
    //-------------------------------------------------------------------------
    void print()const;
    //-------------------------------------------------------------------------
    /// @brief method that build a house
    //-------------------------------------------------------------------------
    bool buildHouse();
    //-------------------------------------------------------------------------
    /// @brief method that remove houses from properties
    ///        returns the amount of houses that has been sucessfully sold
    /// @param[in] i_number number of houses to be sold
    //-------------------------------------------------------------------------
    unsigned int sellHouses(unsigned int i_number);
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~GroupOfProperties();

private:
    //-------------------------------------------------------------------------
    /// @brief the colour of the property, for utilities is equal to "utility"
    ///        and for stations is equalt to "station"
    //-------------------------------------------------------------------------
    std::string m_colour;
    //-------------------------------------------------------------------------
    /// @brief pointers to the tiles that relates with each other
    //-------------------------------------------------------------------------
    std::vector<Tile *> m_tiles;
    //-------------------------------------------------------------------------
    /// @brief indicates where the next house will be build
    //-------------------------------------------------------------------------
    unsigned int m_whereToBuild;
};

#endif // PROPERTIESRELATION_H
