#ifndef UTILITY_H
#define UTILITY_H
#include "Property.h"

class Utility : public Property
{
public:
    //-----------------------------------------------------------------------------
    /// @brief default constructor
    //-----------------------------------------------------------------------------
    Utility(
            const std::string &i_name,
            double i_price,
            const std::vector<double> &i_rentPrices
            );
    //-------------------------------------------------------------------------
    /// @brief method that does the action =p
    /// @param[in] i_player the player that have reached that specific tile
    //-------------------------------------------------------------------------
    void payRent(
            const std::vector<Player *> &i_player,
            int current_player
            );
    //-------------------------------------------------------------------------
    /// @brief method that resets all its values to the default ones
    //-------------------------------------------------------------------------
    void reset();
    //-------------------------------------------------------------------------
    /// @brief method that prints all the information about the properties
    //-------------------------------------------------------------------------
    void printExtras()const;

    //-----------------------------------------------------------------------------
    /// @brief default destructor
    //-----------------------------------------------------------------------------
    ~Utility();
};

#endif // UTILITY_H
