#include "Game.h"
#include "Corner.h"
#include "Order.h"
#include "Property.h"
#include "Station.h"
#include "Player.h"
#include "Dice.h"
#include "NormalProperty.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <climits>
#include <ctime>
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
                m_board[counter] = new Station(name,price,rentPrices);
                break;
            case 'u' : // Works - Company
                name = readTilesName(words,&i);
                m_board[counter] = new Station(name,price,rentPrices);
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


    m_dice = new Dice();

    SetupGame();
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
    m_board[1]->action(m_players,m_currentPlayer);
}

//-----------------------------------------------------------------------------
void Game::SetupGame()
{
    int numPlayers = 2;
    std::vector<std::string> playerNames;
    std::string currentName = "";
    //std::vector<Player> players;

    std::cout << "Enter number of players (2 - 6): ";
    std::cin >> numPlayers;
    while (numPlayers < 2 || numPlayers > 6) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Please enter a number between 2 and 6: ";
        std::cin >> numPlayers;
    }

    m_players.resize(numPlayers);

    for (int i=0;i<numPlayers;i++) {
        std::cout << "What's your name, player " << i+1 << "? ";
        std::cin >> currentName;
        playerNames.push_back(currentName);
    }

    std::cout << std::endl << std::endl;


    for (int i=0;i<numPlayers;i++) {
        m_players[i] = new Player(playerNames[i]);
        std::cout << "Player " << i+1 << ": " << m_players[i]->getName() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Now we'll roll the dice to see who goes first" << std::endl;

    std::cout << std::endl;

    srand((unsigned)time(0));

    int oldwinner = 0;
    int winner = 0;
    int windex = -1;
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');

    for (int i=0;i<numPlayers;i++) {
        std::cout << "Press ENTER to roll, " << m_players[i]->getName() << std::endl;
        std::cout << std::endl;
        std::cin.get();
        m_dice->roll();
        winner = m_dice->getValue();
        std::cout << m_players[i]->getName() << " rolled: " << winner << std::endl <<std::endl;
        if (winner > oldwinner) windex = i;
        oldwinner = winner;
    }

    std::cout << m_players[windex]->getName() << " goes first." << std::endl;

    m_currentPlayer = windex;
    std::cout << std::endl;

}

//-----------------------------------------------------------------------------
Game::~Game()
{
    for (unsigned int i=0; i<numOfTiles; ++i)
    {
        delete m_board[i];
    }
}
