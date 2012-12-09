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
        const PlayerManager &i_players
        )
{
    std::vector<int> groups; // groups player is allowed to build houses
    for(unsigned int i=0; i<m_groups.size();++i)
    {
        if(m_groups[i].m_colour!="utility"&& m_groups[i].m_colour!="station" &&
           m_groups[i].m_tiles.size() ==
                m_groups[i].getNumOfOwns(i_players.getCurrentPlayer()))
        {
            groups.push_back(i);
        }
    }
    if(groups.size()==0)
    {
        std::cout << "You are not allowed to buy houses yet\n";
        return 0;
    }
    else
    {
        std::cout << "Please choose where to build houses:\n";
        for(unsigned int i=0; i<groups.size();++i)
        {
            std::cout << "On " << m_groups[groups[i]].m_colour<< " for "
                      << m_groups[groups[i]].getHousePrice() << " each\n";
        }
        std::cout<< "Or type 'Q' if you have changed your mind\n";
        std::string answer;
        std::cin >> answer;
        if(answer!="Q")
        {

        }
        else
        {
            // Player has changed his mind
        }
    }
   return 0;
}

//-----------------------------------------------------------------------------
unsigned int GroupsManager::getNumOfStations(unsigned int i_owner) const
{
    unsigned int num = 0;
    for(unsigned int i=0; i<m_groups.size(); ++i)
    {
        if(m_groups[i].m_colour == "station")
        {
            for(unsigned int j=0; j<m_groups[i].m_tiles.size();++j)
            {
                if(m_groups[i].m_tiles[j]->getOwner()==i_owner)
                {
                    num++;
                }
            }
            break;
        }
    }
    return num;
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

