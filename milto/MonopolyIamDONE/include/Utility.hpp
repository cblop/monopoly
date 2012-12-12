#ifndef UTILITY_H
#define UTILITY_H
#include "Property.hpp"

class Utility : public Property
{
public:
    //-----------------------------------------------------------------------------
    /// @brief default constructor
    //-----------------------------------------------------------------------------
    Utility(
            const std::string &i_name,
            double i_price,
            const std::vector<unsigned int> &i_rentPrices
            );
    //-------------------------------------------------------------------------
    /// @brief method that returns the owner of the property
    //-------------------------------------------------------------------------
    unsigned int getOwner()const;
    //-------------------------------------------------------------------------
    /// @brief method that does the action =p
    /// @param[in] i_player the player that have reached that specific tile
    //-------------------------------------------------------------------------
    void payRent(PlayerManager &i_players);
    //-------------------------------------------------------------------------
    /// @brief method that resets all its values to the default ones
    //-------------------------------------------------------------------------
    void resetExtras();
    //-------------------------------------------------------------------------
    /// @brief method that prints all the information about the properties
    //-------------------------------------------------------------------------
    void printExtras()const;

    //-----------------------------------------------------------------------------
    /// @brief default destructor
    //-----------------------------------------------------------------------------
    ~Utility();

private:
    //-----------------------------------------------------------------------------
    /// @brief how many times you pay the total of the dices
    //-----------------------------------------------------------------------------
    std::vector<unsigned int> m_rentPrices;
};

#endif // UTILITY_H
