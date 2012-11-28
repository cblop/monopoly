#ifndef ORDER_H
#define ORDER_H

#include "Tile.h"

class Order: public Tile
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    /// @param[in] i_name: the name of the tile
    //-------------------------------------------------------------------------
    Order(const std::string &i_name);
    //-------------------------------------------------------------------------
    /// @brief method that prints all the information about the Order Tile
    //-------------------------------------------------------------------------
    void print()const;
    //-------------------------------------------------------------------------
    /// @brief method that does the action =p
    /// @param[in] i_player the player that have reached that specific tile
    //-------------------------------------------------------------------------
    void action(
            const std::vector<Player *> &i_player,
            int current_player
            );
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~Order();
};

#endif // ORDER_H
