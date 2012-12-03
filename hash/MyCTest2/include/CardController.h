#ifndef CARDCONTROLLER
#define CARDCONTROLLER

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Tile.h"
#include <vector>

class CardController : public Tile
{
	public:
		CardController(const std::string &i_name);
		
		virtual void action(const std::vector<Player *> &i_player,int current_player)=0;
		
		void reset();
		void print()const;
		

		void selectCard(int cardTypeFlag);

        	~CardController();

	private:

		void BinaryChoice(int moneyToRemove);
		void GetOutOfJailFree();
		void GetMoney(int moneyToAdd);
		void StreetRepairs(int house, int hotel);
		void GoToJail();
		void LoseMoney(int moneyToRemove);
		void MovePlayerToPosition(int boardPosition);
		void MovePlayerBack(int spacesToMove);

};


#endif //CardCONTROLLER
