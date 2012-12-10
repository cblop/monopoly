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
#include "CardReceiveMoneyFromPlayers.h"

std::vector<std::string> communityChestCards;
std::vector<std::string> chanceCards;

CardsManager::CardsManager()
{
    initialiseCards();
}

void CardsManager::action(PlayerManager &i_players, const std::string &i_name)
{
    if(i_name=="CHANCE")
    {
        const unsigned int random = 14;//rand() % m_chance.size();
        m_chance[random]->action(i_players);
        std::cout << chanceCards[random] << std::endl;
    }
    else if(i_name == "COMMUNITY CHEST")
    {
        unsigned int random = std::rand() % m_communityChest.size();
        m_communityChest[random]->action(i_players);
        std::cout << communityChestCards[random] << std::endl;
    }
    else
    {
        std::cout << "This is not a card type!" << std::endl;
    }
}

void CardsManager::initialiseCards()
{
    std::string line;
    std::ifstream myfile1 ("CommunityChest");
    if (myfile1.is_open())
    {
        getline(myfile1, line);
        do
        {
            communityChestCards.push_back(line);
            getline(myfile1, line);
        }
        while (!myfile1.eof());
    }
    myfile1.close();

    std::ifstream myfile2 ("Chance");
    if (myfile2.is_open())
    {
        getline(myfile1, line);
        do
        {
            chanceCards.push_back(line);
            getline(myfile2, line);
        }
        while (!myfile2.eof());

    }
    myfile2.close();



    m_communityChest.resize(communityChestCards.size());
    for(unsigned int i=0; i<communityChestCards.size(); ++i)
    {

        line = communityChestCards[i];
        std::istringstream iss(line);
        std::string sub;

        //First Sub-String of line is always flag
        iss >> sub;

        if (sub == "b") //Binary choice (e.g pay £10 or take a chance)
        {
            int moneyToRemove;
            iss >> sub;
            std::istringstream(sub) >> moneyToRemove;
            m_communityChest[i]= new CardChanceOrLoseMoney(moneyToRemove);
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

        else if (sub == "gp") //Receive money from EACH player
        {
            int moneyToAdd;
            iss >> sub;
            std::istringstream(sub) >> moneyToAdd;
            m_communityChest[i] = new CardReceiveMoneyFromPlayers(moneyToAdd);
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
     
    m_chance.resize(chanceCards.size());

    for(unsigned int i=0; i<chanceCards.size(); ++i)
    {
        line = chanceCards[i];
        std::istringstream iss(line);
        std::string sub;

        //First Sub-String of line is always flag
        iss >> sub;

        if (sub == "b") //Binary choice (e.g pay £10 or take a chance)
        {
            int moneyToRemove;
            iss >> sub;
            std::istringstream(sub) >> moneyToRemove;
            m_chance[i]= new CardChanceOrLoseMoney(moneyToRemove);
        }

        else if (sub == "f") //Get out of Jail Free
        {
        	m_chance[i] = new CardGetOutOfJail();
        }

        else if (sub == "g") //Player RECIEVES money
        {
            int moneyToAdd;
            iss >> sub;
            std::istringstream(sub) >> moneyToAdd;
            m_chance[i] = new CardReceiveMoney(moneyToAdd);
        }

        else if (sub == "gp") //Receive money from EACH player
        {
            int moneyToAdd;
            iss >> sub;
            std::istringstream(sub) >> moneyToAdd;
            m_chance[i] = new CardReceiveMoneyFromPlayers(moneyToAdd);
        }

        else if (sub == "h") //Player has to perform repairs on property
        {
            int house, hotel;
            iss >> sub;
            std::istringstream(sub) >> house;
            iss >> sub;
            std::istringstream(sub) >> hotel;
            m_chance[i] = new CardStreetRepairs(house, hotel);
        }

        else if (sub == "j") //Go To Jail
        {
        	m_chance[i] = new CardGoToJail();
        }

        else if (sub == "l") //Take money from player
        {
            int moneyToRemove;
            iss >> sub;
            std::istringstream(sub) >> moneyToRemove;
            m_chance[i] = new CardTakeMoney(moneyToRemove);
        }

        else if (sub == "m") //Move player TO SPECIFIED position
        {
            int boardPosition;
            iss >> sub;
            std::istringstream(sub) >> boardPosition;
            m_chance[i] = new CardMovePlayerToPosition(boardPosition);
        }

        else if (sub == "mb") //Move player back certain amount of spaces
                              // from current position
        {
            int spacesToMove;
            iss >> sub;
            std::istringstream(sub) >> spacesToMove;
            m_chance[i] = new CardMovePlayerBack(spacesToMove);
        }
     }
}


//-------------------------------------------------------------------------
void CardsManager::print()const
{
    std::cout << "-------------------------------------------------\n";
    std::cout << "On a card." << std::endl;
}

//-------------------------------------------------------------------------
CardsManager::~CardsManager()
{
    for(unsigned int i=0; i<m_communityChest.size();++i)
    {
        delete m_communityChest[i];
    }
    for(unsigned int i=0; i<m_chance.size();++i)
    {
        delete m_chance[i];
    }
}
