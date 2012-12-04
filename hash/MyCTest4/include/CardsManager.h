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
        CardsManager(int cardTypeFlag, const std::string &i_name);
        //-------------------------------------------------------------------------
        /// @brief method that does the action =p
        /// @param[in] i_player the player that have reached that specific tile
        //-------------------------------------------------------------------------
        void action(
                const std::vector<Player *> &i_player,
                int current_player
                )=0;
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
        
        static void loadCards(std::vector<std::string> stringVector, std::vector<Card *> cardVector);


};


#endif //CardMAnager
