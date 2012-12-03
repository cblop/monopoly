#ifndef STATION_H
#define STATION_H

#include "Property.h"
#include "Player.h"
#include <vector>

class Station : public Property
{
public:
    //-------------------------------------------------------------------------
    /// @bried default constructor
    /// @param[in] i_name: the name of the tile
    /// @param[in] i_price: the price of the property
    //-------------------------------------------------------------------------
    Station(const std::string &i_name,
            double i_price,
            const std::vector<double> &i_rentPrices);
    //-------------------------------------------------------------------------
    /// @brief method that prints all the information about the Station
    //-------------------------------------------------------------------------
    void printExtras()const;
    //-------------------------------------------------------------------------
    /// @brief method that resets the values of a property
    ///        in case the game is reset
    //-------------------------------------------------------------------------
    void reset();
    //-------------------------------------------------------------------------
    /// @brief method that does the action =p
    /// @param[in] i_player the player that have reached that specific tile
    //-------------------------------------------------------------------------
    void payRent(
            const std::vector<Player *> &i_player,
            int current_player
            );
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~Station();

private:
    std::vector<double> m_rentPrices;
};

#endif // STATION_H
