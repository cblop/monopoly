#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Player.h"

#include "CardsManager.h"
#include "CardMovePlayerToPosition.h"
#include "CardStreetRepairs.h"
#include "CardReceiveMoney.h"
#include "CardChanceOrLoseMoney.h"
#include "CardGoToJail.h"
#include "CardGetOutOfJail.h"
#include "CardTakeMoney.h"
#include "CardMovePlayerBack.h"

std::vector<Card *> CardsManager::m_communityChest;

CardsManager::CardsManager(int cardTypeFlag, const std::string &i_name):Tile(i_name)
{

}


void CardsManager::initialiseCards()
{

    std::vector<std::string> communityChestCards;
    std::vector<std::string> chanceCards;
    std::cout << "INITIALISING CARDS" <<std::endl;
    std::string line;
    std::ifstream myfile1 ("CommunityChest");
    if (myfile1.is_open())
    {
        while (!myfile1.eof())
        {
            getline(myfile1, line);

                    communityChestCards.push_back(line);
        }
    }
    myfile1.close();

    std::ifstream myfile2 ("Chance");
    if (myfile2.is_open())
    {
        while (!myfile2.eof())
        {
            getline(myfile2, line);
                    chanceCards.push_back(line);
        }
    }
    myfile2.close();


    for(unsigned int i=0; i<communityChestCards.size(); ++i)
    {

        std::cout << "Community Chest" << std::endl;
        
        
        line = communityChestCards[i];
        std::istringstream iss(line);
        std::string sub;
        
        //First Sub-String of line is always flag
        iss >> sub; 
        std::cout << line << std::endl;


        if (sub == "b") //Binary choice (e.g pay £10 or take a chance)
        {
            int moneyToRemove;
            iss >> sub;
            std::istringstream(sub) >> moneyToRemove;
            m_communityChest[i] = new CardChanceOrLoseMoney(moneyToRemove);
        }

        else if (sub == "f") //Get out of Jail Free
        {
        m_communityChest[i] = new CardGetOutOfJail();
        }

        else if (sub == "g") //Player RECIEVES money
        {
            int moneyToAdd;
            iss >> sub;
            std::istringstream(sub) >> moneyToAdd;
            m_communityChest[i] = new CardReceiveMoney(moneyToAdd);
        }

        else if (sub == "h") //Player has to perform repairs on property
        {
            int house, hotel;
            iss >> sub;
            std::istringstream(sub) >> house;
            iss >> sub;
            std::istringstream(sub) >> hotel;
            m_communityChest[i] = new CardStreetRepairs(house, hotel);

        }

        else if (sub == "j") //Go To Jail
        {
	    m_communityChest[i] = new CardGoToJail();
        }
        
        else if (sub == "l") //Take money from player
        {
            int moneyToRemove;
            iss >> sub;
            std::istringstream(sub) >> moneyToRemove;
            m_communityChest[i] = new CardTakeMoney(moneyToRemove);
        }

        else if (sub == "m") //Move player TO SPECIFIED position
        {
            int boardPosition;
            iss >> sub;
            std::istringstream(sub) >> boardPosition;
            m_communityChest[i] = new CardMovePlayerToPosition(boardPosition);
        }

        else if (sub == "mb") //Move player back certain amount of spaces
                              // from current position
        {
            int spacesToMove;
            iss >> sub;
            std::istringstream(sub) >> spacesToMove;
            m_communityChest[i] = new CardMovePlayerBack(spacesToMove);
        }
     }
    std::cout << "END Of initialising cards\n";
}

void CardsManager::destroyedAllCards()
{
    for(unsigned int i=0; i<m_communityChest.size();++i)
    {
        delete m_communityChest[i];
    }
}

//-------------------------------------------------------------------------
void CardsManager::reset()
{

}

//-------------------------------------------------------------------------
void CardsManager::print()const
{
    std::cout << "-------------------------------------------------\n";
    std::cout << "On a card." << std::endl;
}
CardsManager::~CardsManager()
{
}
