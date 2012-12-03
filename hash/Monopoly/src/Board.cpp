#include "Board.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <stdlib.h>

#include "Corner.h"
#include "Order.h"
#include "Property.h"
#include "Station.h"
#include "Player.h"
#include "NormalProperty.h"
#include "Utility.h"

//-------------------------------------------------------------------------
Board::Board()
{
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
        int price = 0;
        std::string name;
        double housePrice;
        std::vector<double> rentPrices;
        rentPrices.resize(6);
        switch(flag)
        {
        case 'c': //Corner
            name  = readTilesName(words,&i);
            m_tiles[counter] = new Corner(name);
            break;
        case 'o': //Order
            name = readTilesName(words,&i);
            m_tiles[counter] = new Order(name);
            break;
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
                name = readTilesName(words,&i);
                m_tiles[counter] =
                        new NormalProperty(name,price,housePrice,rentPrices);
                break;
            }
            case 's': //Station
                for(unsigned int k=0; k<4; ++k)
                {
                    rentPrices[k] = atoi(words[i++].c_str());
                }
                name = readTilesName(words,&i);
                m_tiles[counter] = new Station(name,price,rentPrices);
                break;
            case 'u' : // Works - Company
                for(unsigned int k=0; k<2; ++k)
                {
                    rentPrices[k] = atoi(words[i++].c_str());
                }
                name = readTilesName(words,&i);
                m_tiles[counter] = new Utility(name,price,rentPrices);
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
void Board::action(
        const std::vector<Player *> &i_players,
        int i_currentPlayer
        )
{
    int currentTile = i_players[i_currentPlayer]->getPosition();
    m_tiles[currentTile]->action(i_players,i_currentPlayer);
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
Board::~Board()
{
    for (unsigned int i=0; i<numOfTiles; ++i)
    {
        delete m_tiles[i];
    }
}
