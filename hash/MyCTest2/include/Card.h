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
#include <vector>

class Card : public Tile
//class Card
{
	public:
		Card(const std::string &i_name);
        	//Card();

		
		
		virtual void action(const std::vector<Player *> &i_player,int current_player)=0;
		
		void reset();
		void print()const;
		

		void selectCard(int cardTypeFlag);

        	~Card();

	private:
        //static std::vector<std::string> communityChestCards;

		void BinaryChoice(int moneyToRemove);
		void GetOutOfJailFree();
		void GetMoney(int moneyToAdd);
		void StreetRepairs(int house, int hotel);
		void GoToJail();
		void LoseMoney(int moneyToRemove);
		void MovePlayerToPosition(int boardPosition);
		void MovePlayerBack(int spacesToMove);

};


#endif //Card
