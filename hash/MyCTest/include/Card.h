#ifndef CARD
#define CARD

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Player.h"


class Card
{
	public:
		Card(int cardTypeFlag);
		
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


#endif //Card
