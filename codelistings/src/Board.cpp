#include <iostream>
#include <fstream>
#include <iterator>
#include <stdlib.h>

#include "Board.hpp"
#include "Order.hpp"
#include "Property.hpp"
#include "Station.hpp"
#include "Player.hpp"
#include "NormalProperty.hpp"
#include "Utility.hpp"
#include "GetACardTIle.hpp"

//-------------------------------------------------------------------------
Board::Board()
{
  //  CardsManager::initialiseCards();
    // Corners
    std::ifstream bvhStream("Board");
    if (!bvhStream) {
        std::cout << "File Board not found. Game will terminate\n";
        exit (EXIT_FAILURE);
    }
    std::istream_iterator<std::string> bvhIt(bvhStream);
    std::istream_iterator<std::string> sentinel;
    std::vector<std::string> words(bvhIt,sentinel);
    m_tiles.resize(40);
    unsigned int i=0 , counter = 0;
    while(i<words.size()-3)
    {
        i++;
        const char flag = words[i++][0];
        unsigned int price = 0;
        std::string name, colour;
        int housePrice;
        std::vector<unsigned int> rentPrices;
        rentPrices.resize(6);
        switch(flag)
        {
        case 'c': //Card
            name  = readTilesName(words,&i);
            m_tiles[counter] = new GetACardTIle(name,m_cards);
            break;
        case 'o': //Order tax,jail,go,go to jail
        {
            const std::string flag = words[i++];
            if(flag=="p")
            {
                const unsigned int money =atoi(words[i++].c_str());
                name = readTilesName(words,&i);
                m_tiles[counter]=new Order(name,"p",money);
            }
            else
            {
                name = readTilesName(words,&i);
                m_tiles[counter] = new Order(name,flag);
            }
            break;
        }
        case 'p': // Property
        {
            const char secondFlag = words[i++][0];
            price = atoi(words[i++].c_str());
            switch(secondFlag)
            {
            case 'n': //Normal Property
            {
                housePrice = atoi(words[i++].c_str());
                for(unsigned int k=0; k<6; ++k)
                {
                    rentPrices[k] = atoi(words[i++].c_str());
                }
                colour = words[i++];
                name = readTilesName(words,&i);
                m_tiles[counter] =
                        new NormalProperty(name,price,housePrice,rentPrices);
                m_groups.addTile(colour,m_tiles[counter]);
                m_tiles[counter]->setColour(colour);
                break;
            }
            case 's': //Station
                for(unsigned int k=0; k<4; ++k)
                {
                    rentPrices[k] = atoi(words[i++].c_str());
                }
                name = readTilesName(words,&i);
                m_tiles[counter] = new Station(name,price,rentPrices);
                m_groups.addTile("station",m_tiles[counter]);
                break;
            case 'u' : // Works - Company
                for(unsigned int k=0; k<2; ++k)
                {
                    rentPrices[k] = atoi(words[i++].c_str());
                }                
                name = readTilesName(words,&i);
                m_tiles[counter] = new Utility(name,price,rentPrices);
                m_groups.addTile("utility",m_tiles[counter]);
            break;
            default:
                break;
            }
            break;
        }
        default:
            std::cerr << "Wrong flag type.\n";
            exit(EXIT_FAILURE);
            break;
        }
        i++;
        counter++;
    }
}

//-------------------------------------------------------------------------
void Board::print(unsigned int i_tile) const
{
    m_tiles[i_tile]->print();
}

//-------------------------------------------------------------------------
void Board::action(PlayerManager &i_players)
{
    int currentTile = i_players.getPosition();
    m_tiles[currentTile]->action(i_players);
}

//-------------------------------------------------------------------------
void Board::reset()
{
    for(unsigned int i=0; i<numOfTiles; ++i)
    {
        m_tiles[i]->reset();
    }
}


//-------------------------------------------------------------------------
const std::string &Board::getTileName(unsigned int i_index) const
{
    return m_tiles[i_index]->getName();
}



//-----------------------------------------------------------------------------
std::string Board::readTilesName(
        const std::vector<std::string> &i_words, unsigned int *io_p
        )
{
    std::string name = i_words[*io_p];
    *io_p = *io_p + 1;
    while(i_words[*io_p]!=".")
    {
        name+=" " + i_words[*io_p];
        *io_p = *io_p + 1;
    }
    return name;
}

//-------------------------------------------------------------------------
void Board::buildHouses(PlayerManager &i_players)
{
    m_groups.buildHouses(i_players);
}

//-------------------------------------------------------------------------
Board::~Board()
{
   // CardsManager::destroyedAllCards();
    for (unsigned int i=0; i<numOfTiles; ++i)
    {
        delete m_tiles[i];
    }
}
