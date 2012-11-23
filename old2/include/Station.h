#ifndef STATION_H
#define STATION_H

#include "Property.h"

class Station : public Property
{
public:
    //-------------------------------------------------------------------------
    /// @bried default constructor
    /// @param[in] i_name: the name of the tile
    /// @param[in] i_price: the price of the property
    //-------------------------------------------------------------------------
    Station(const std::string &i_name, double i_price);
    //-------------------------------------------------------------------------
    /// @brief method that prints all the information about the Station
    //-------------------------------------------------------------------------
    void printExtras()const;
    //-------------------------------------------------------------------------
    /// @brief method that resets the values of a property
    ///        in case the game is reset
    //-------------------------------------------------------------------------
    void reset();
};

#endif // STATION_H
