#include "GroupOfProperties.h"

//-----------------------------------------------------------------------------
GroupOfProperties::GroupOfProperties(
        const std::string &i_colour
        ):m_colour(i_colour)
{
}

//-----------------------------------------------------------------------------
GroupOfProperties::GroupOfProperties(
        const std::string &i_colour,
        Tile *i_tile
        ):m_colour(i_colour)
{
    m_tiles.push_back(i_tile);
}

//-----------------------------------------------------------------------------
GroupOfProperties::GroupOfProperties(const GroupOfProperties &i_group)
{
    m_colour=i_group.m_colour;
    for(unsigned int i=0; i<i_group.m_tiles.size();++i)
    {
        m_tiles.push_back(i_group.m_tiles[i]);
    }

}

//-----------------------------------------------------------------------------
void GroupOfProperties::print()const
{
    std::cout<<"The following tiles belong to group: " << m_colour << "\n";
    for(unsigned int i=0; i<m_tiles.size(); ++i)
    {
        m_tiles[i]->print();
    }
}

//-----------------------------------------------------------------------------
bool GroupOfProperties::addTile(const std::string i_colour, Tile *i_tile)
{
    if(i_colour==m_colour)
    {
        m_tiles.push_back(i_tile);
        return true;
    }
    else
    {
        return false;
    }
}

//-----------------------------------------------------------------------------
unsigned int GroupOfProperties::buildHouses(unsigned int i_number)
{
    if(m_colour=="station" || m_colour=="utility")
    {
        return 0; // you cannot build houses on utilities and stations
    }
    return i_number;
}


//-----------------------------------------------------------------------------
GroupOfProperties::~GroupOfProperties()
{}
