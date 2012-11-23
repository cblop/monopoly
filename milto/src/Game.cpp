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
//        const int position = (int)atoi(words[i++].c_str());
        i++;
        const char flag = words[i++][0];
        int price = 0;
        if(flag == 'n' || flag == 's' || flag == 'w')
        {
            // it is a property and the price should have been defined
            price = atoi(words[i++].c_str());
        }
        const std::string name = readTilesName(words,&i);
        switch(flag)
        {
        case 'c': //Corner
            m_board[counter] = new Corner(name);
            break;
        case 'o': //Order
            m_board[counter] = new Order(name);
            break;
        case 'n': //Normal Property
            m_board[counter] = new NormalProperty(name,price);
            break;
        case 's': //Station
            m_board[counter] = new Station(name,price);
            break;
        case 'w' : // Works - Company
            m_board[counter] = new Station(name,price);
            break;

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
