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
    Order(const std::string &i_name, const std::string &flag);
    //-------------------------------------------------------------------------
    /// @brief default constructor
    /// @param[in] i_name: the name of the tile
    /// @param[in] i_money: money that needs to be paid
    //-------------------------------------------------------------------------
    Order(
            const std::string &i_name,
            const std::string &flag,
            unsigned int i_money
            );
    //-------------------------------------------------------------------------
    /// @brief method that prints all the information about the Order Tile
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
    void action(PlayerManager &i_players );
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~Order();

private:
    //-------------------------------------------------------------------------
    /// @brief indicates action to be perform
    //-------------------------------------------------------------------------
    std::string m_flag;
    //-------------------------------------------------------------------------
    /// @brief amount of money in case money has to be paid
    //-------------------------------------------------------------------------
    unsigned int m_money;
};

#endif // ORDER_H
