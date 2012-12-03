#ifndef PROPERTIESRELATIONS_H
#define PROPERTIESRELATIONS_H

#include <iostream>
#include <vector>

class PropertiesRelations
{
public:
    //-----------------------------------------------------------------------------

    //-----------------------------------------------------------------------------
    //PropertiesRelations();
    //-----------------------------------------------------------------------------

    //-----------------------------------------------------------------------------
    void addTile();

    //-----------------------------------------------------------------------------
    static void freeMemory();


private:
    //-----------------------------------------------------------------------------
    /// @brief method that returns the position of the given colour and adds it to
    /// the end of the list if it does not exist
    /// @param[in] i_colour: the colour
    //-----------------------------------------------------------------------------
    int getColoursPosition(const std::string i_colour);
    //-----------------------------------------------------------------------------

    //-----------------------------------------------------------------------------
    static std::vector<std::vector<int> *> m_relations;
    //-----------------------------------------------------------------------------
    /// @brief an array that give the names of the colours
    //-----------------------------------------------------------------------------
    static std::vector<std::string> m_colours;

};

#endif // PROPERTIESRELATIONS_H
