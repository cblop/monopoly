#include "GroupsManager.h"


//-----------------------------------------------------------------------------
GroupsManager::GroupsManager()
{
}

//-----------------------------------------------------------------------------
void GroupsManager::addTile(
        const std::string &i_colour,
        Tile *i_tile
        )
{
    bool isTileAdded = false; //indicated whether the tile is addes to a group
    for (unsigned int i=0; i<m_groups.size(); ++i)
    {
        isTileAdded+=m_groups[i].addTile(i_colour,i_tile);
    }
    if(isTileAdded==false)
    {
        m_groups.push_back(GroupOfProperties(i_colour,i_tile));
    }
}

//-----------------------------------------------------------------------------
void GroupsManager::print()const
{
    for(unsigned int i=0; i<m_groups.size(); ++i)
    {
        std::cout << "************************************\n";
        m_groups[i].print();
    }

}

//-----------------------------------------------------------------------------
unsigned int GroupsManager::buildHouses(
        unsigned int /*i_owner*/,
        const std::string &/*i_colour*/,
        unsigned int /*i_number*/
        )
{
   return 1;
}


//-----------------------------------------------------------------------------
unsigned int GroupsManager::sellHouses(
        std::string /*i_colour*/,
        unsigned int /*i_number*/
        )
{
    return 1;
}


//-----------------------------------------------------------------------------
GroupsManager::~GroupsManager()
{}

