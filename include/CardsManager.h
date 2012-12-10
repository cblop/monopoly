#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Tile.h"
#include "Card.h"


class CardsManager
{
public:
    CardsManager();
    //-------------------------------------------------------------------------
    /// @brief method that does the action =p
    /// @param[in] i_players the players of the game
    //-------------------------------------------------------------------------
    void action(PlayerManager &i_players, const std::string &i_name);
    //-------------------------------------------------------------------------
    /// @brief method that prints all the information about the tile
    //-------------------------------------------------------------------------
    void print()const;

    void printAllCards()
    {
        for(unsigned int i=0; i<m_communityChest.size(); ++i)
        {
            m_communityChest[i]->print();
        }
    }
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    virtual ~CardsManager();

private:

    //-------------------------------------------------------------------------
    /// @brief method that initialises all the cards
    /// @brief it MUST BE CALLED before this class is used
    //-------------------------------------------------------------------------
    void initialiseCards();

    //-------------------------------------------------------------------------
    /// @brief all the community Chest cards
    //-------------------------------------------------------------------------
    std::vector<Card *> m_communityChest;
    //-------------------------------------------------------------------------
    /// @brief all the chance cards
    //-------------------------------------------------------------------------
    std::vector<Card *> m_chance;

};


#endif //CardMAnager
