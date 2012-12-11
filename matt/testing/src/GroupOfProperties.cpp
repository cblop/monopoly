#include "GroupOfProperties.h"

//-----------------------------------------------------------------------------
GroupOfProperties::GroupOfProperties(
        const std::string &i_colour
        ):m_colour(i_colour),
          m_whereToBuild(0)
{
}

//-----------------------------------------------------------------------------
GroupOfProperties::GroupOfProperties(
        const std::string &i_colour,
        Tile *i_tile
        ):m_colour(i_colour),
          m_whereToBuild(0)
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


//-----------------------------------------------------------------------------
unsigned int GroupOfProperties::getHousePrice()const
{
    return m_tiles[0]->getHousePrice();
}

//-----------------------------------------------------------------------------
unsigned int GroupOfProperties::getNumOfOwns(unsigned int i_player)const
{
    unsigned int num =0;
    for(unsigned int i=0; i<m_tiles.size(); ++i)
    {
        if(m_tiles[i]->getOwner()==i_player)
        {
            num++;
        }
    }
    return num;
}

//-----------------------------------------------------------------------------
unsigned int GroupOfProperties::buildHouses(
        unsigned int i_num,
        PlayerManager &i_players
        )
{
    unsigned int numOfHousesSuccessfullyBuild = 0;

    // this line breaks everything
    const unsigned int costOfAHouse = 10;//m_tiles[0]->getHousePrice();
    if(m_colour=="station" || m_colour=="utility")
    {
        return 0; // you cannot build houses on utilities and stations
    }
    for(unsigned int i=0; i<i_num ; ++i)
    {
        if(i_players.takeBalance(costOfAHouse))
        {
            if(m_tiles[m_whereToBuild]->buildHouse())
            {
                // there is a hotel
                i_players.addBalance(costOfAHouse);
                numOfHousesSuccessfullyBuild++;
            }
            m_whereToBuild = (m_whereToBuild+1)%m_tiles.size();
        }
        else
        {
            // player does not have enough money to buy the rest of the houses
            return numOfHousesSuccessfullyBuild;
        }
    }
    return numOfHousesSuccessfullyBuild;
}


//-----------------------------------------------------------------------------
GroupOfProperties::~GroupOfProperties()
{}
