#include "Game.h"
#include "Corner.h"
#include "Order.h"
#include "Property.h"
#include "Station.h"
#include "NormalProperty.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <stdlib.h>



//-----------------------------------------------------------------------------
Game::Game()
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

    m_board.resize(40);
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
            m_board[counter] = new Corner(name);
            break;
        case 'o': //Order
            name = readTilesName(words,&i);
            m_board[counter] = new Order(name);
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
                m_board[counter] =
                        new NormalProperty(name,price,housePrice,rentPrices);
                break;
            }
            case 's': //Station
                name = readTilesName(words,&i);
                m_board[counter] = new Station(name,price);
                break;
            case 'u' : // Works - Company
                name = readTilesName(words,&i);
                m_board[counter] = new Station(name,price);
            break;
            default:
                break;
            }
            m_board[counter]->print();
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

//-----------------------------------------------------------------------------
std::string Game::readTilesName(
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

//-----------------------------------------------------------------------------
void Game::StartGame()
{
    m_board[1]->action();
}

//-----------------------------------------------------------------------------
Game::~Game()
{
    for (unsigned int i=0; i<numOfTiles; ++i)
    {
        delete m_board[i];
    }
}
