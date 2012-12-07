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


class CardsManager : public Tile
{
	public:
        CardsManager(const std::string &i_name);
        //-------------------------------------------------------------------------
        /// @brief method that does the action =p
        /// @param[in] i_players the players of the game
        //-------------------------------------------------------------------------
        void action(PlayerManager &i_players);
        //-------------------------------------------------------------------------
        /// @brief method that resets all its values to the default ones
        //-------------------------------------------------------------------------
        void reset();
        //-------------------------------------------------------------------------
        /// @brief method that prints all the information about the tile
        //-------------------------------------------------------------------------
        void print()const;

        static void printAllCards()
        {
            for(unsigned int i=0; i<m_communityChest.size(); ++i)
            {
                m_communityChest[i]->print();
            }
        }

        //-------------------------------------------------------------------------
        /// @brief method that initialises all the cards
        /// @brief it MUST BE CALLED before this class is used
        //-------------------------------------------------------------------------
        static void initialiseCards();
        //-------------------------------------------------------------------------
        /// @brief method that destroyes all the cards
        /// @brief should be called to free memory before program terminates
        //-------------------------------------------------------------------------
        static void destroyedAllCards();

        ~CardsManager();

	private:


        static std::vector<Card *> m_communityChest;
        static std::vector<Card *> m_chance;

};


#endif //CardMAnager
