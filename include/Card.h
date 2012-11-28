#ifndef CARD
#define CARD

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Tile.h"
#include "CardType.h"

class Card : public Tile
{
	public:
        Card(int cardTypeFlag, const std::string &i_name);
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

        static void initialiseCards();

        ~Card();

	private:


       static std::vector<CardType> m_communityChest;

		void BinaryChoice(int moneyToRemove);
		void GetOutOfJailFree();
		void GetMoney(int moneyToAdd);
		void StreetRepairs(int house, int hotel);
		void GoToJail();
		void LoseMoney(int moneyToRemove);
		void MovePlayerToPosition(int boardPosition);
		void MovePlayerBack(int spacesToMove);

        // std::vector<>
};


#endif //Card
