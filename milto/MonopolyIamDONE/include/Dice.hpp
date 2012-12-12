#ifndef DICE_H
#define DICE_H

#include <vector>

class Dice
{

public:
    //-----------------------------------------------------------------------------
    // constructor
    //-----------------------------------------------------------------------------
    Dice();
    //-----------------------------------------------------------------------------
    /// @brief method that returns the values of the dices
    //-----------------------------------------------------------------------------
    const std::vector<unsigned int> &getValues()const;
    //-----------------------------------------------------------------------------
    /// @brief method that returns the total sum of the values of the dices
    //-----------------------------------------------------------------------------
    unsigned int getTotal()const;
    //-----------------------------------------------------------------------------
    /// @brief method that prints the values of the dices
    //-----------------------------------------------------------------------------
    void print()const;
    //-----------------------------------------------------------------------------
    /// @brief returns true is the dices have the same number, otherwise false
    //-----------------------------------------------------------------------------
    bool isDouble()const;
    //-----------------------------------------------------------------------------
    /// @brief roll the dices
    //-----------------------------------------------------------------------------
    void roll();
    //-----------------------------------------------------------------------------
    /// @brief default destructor
    //-----------------------------------------------------------------------------
    ~Dice();

private:
    //-----------------------------------------------------------------------------
    /// @brief the values of the dices
    //-----------------------------------------------------------------------------
    std::vector<unsigned int> m_values;
};

#endif //DICE
