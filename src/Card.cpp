#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Card.h"

Card::Card(int cardTypeFlag, const std::string &i_name):Tile(i_name)
{
	srand(time(NULL));
	std::string line;
	std::string fileName;
	std::cout << std::endl;
    int lineCount=1;
	

	if (cardTypeFlag == 0)
	{
		std::cout << "COMMUNITY CHEST!!" << std::endl;	
		lineCount = 17;
		fileName = "CommunityChest";
		
	}
	else if (cardTypeFlag == 1)
	{
		std::cout << "CHANCE!!" << std::endl;
		lineCount = 15;
		fileName = "Chance";
	}
	else
	{
		std::cout << "1) NOOOOOOOOOOOOOOOOOOO. It is WRONG!!! 0 or 1" << std::endl;
	}
	
	std::ifstream myfile (fileName.c_str());
	int random = rand() % lineCount + 1;
	int matchCase =0; 
	int count = 0;
	
	matchCase = random;
	
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			if (count == matchCase)
			{
				std::cout << count << std::endl;
				std::istringstream iss(line);
				std::string sub;
				iss >> sub;
				std::cout << line << std::endl;
				
				std::cout << "CARD TYPE ==> ";
				if (sub == "b")
				{
					int moneyToRemove;
					iss >> sub;
					std::istringstream(sub) >> moneyToRemove;
					BinaryChoice(moneyToRemove);
				}

				else if (sub == "f")
				{
					GetOutOfJailFree();
				}

				else if (sub == "g")
				{
					int moneyToAdd;
					iss >> sub;
					std::istringstream(sub) >> moneyToAdd;
					GetMoney(moneyToAdd);
				}

				else if (sub == "h")
				{
					int house, hotel;
					iss >> sub;
					std::istringstream(sub) >> house;
					iss >> sub;
					std::istringstream(sub) >> hotel;
					StreetRepairs(house, hotel);
				}

				else if (sub == "j")
					GoToJail();

				else if (sub == "l")
				{
					int moneyToRemove;
					iss >> sub;
					std::istringstream(sub) >> moneyToRemove;
					LoseMoney(moneyToRemove);
				}
				
				else if (sub == "m")
				{
					int boardPosition;
					iss >> sub;
					std::istringstream(sub) >> boardPosition;
					MovePlayerToPosition(boardPosition);
				}
				
				else if (sub == "mb")
				{
					int spacesToMove;
					iss >> sub;
					std::istringstream(sub) >> spacesToMove;
					MovePlayerBack(spacesToMove);
				}

			
				break; //break out of while loop

			}
			count++;
		}
		myfile.close();
	}
	else
		std::cout << "2) NOOOOOOOOOOOOOOOOOOO. It is WRONG!!! Cannot open file" << std::endl;
		

	std::cout << std::endl;
}

//-------------------------------------------------------------------------
void Card::action(
        const std::vector<Player *> &i_players,
        int current_player
        )
{
    i_players[current_player]->addBalance(100.0);
}

//-------------------------------------------------------------------------
void Card::reset()
{

}

//-------------------------------------------------------------------------
void Card::print()const
{
    std::cout << "-------------------------------------------------\n";
    std::cout << "On a card." << std::endl;
}



//The stuff and shit --------------------------------------------------------------------------------
void Card::BinaryChoice(int moneyToRemove)
{
	std::cout << "Binary Choice" << std::endl;
	std::cout << "Pay £" << moneyToRemove << "(0) or Take A Chance (1);" << std::endl;
	int doChance;
	std::cin >> doChance;
	if (doChance == 0)
		std::cout << "[Take £" << moneyToRemove << " From Player]" << std::endl;
	else if (doChance == 1)
		std::cout << "[Call 'Chance']" << std::endl;
}

void Card::GetOutOfJailFree()
{
	std::cout << "Get Out of Jail FREE" <<std::endl;
	std::cout << "[Set some flag in Player]" <<std::endl;
}

void Card::GetMoney(int moneyToAdd)
{
	std::cout << "Get Money" <<std::endl;
	std::cout << "[Player recieves £" << moneyToAdd << "]" << std::endl;

}

void Card::StreetRepairs(int house, int hotel)
{
	std::cout << "Assessed for Street Repairs" << std::endl;
	std::cout << "[Player has to pay £" << house << "for each house and £" <<hotel << "]" << std::endl;
}

void Card::GoToJail()
{
	std::cout << "GO TO JAIL!" << std::endl;
}

void Card::LoseMoney(int moneyToRemove)
{
	std::cout << "Lose Money" << std::endl;
	std::cout << "[Take £" << moneyToRemove << " From Player]" << std::endl;
}


void Card::MovePlayerToPosition(int boardPosition)
{
	std::cout << "Move to Something" << std::endl;
	std::cout << "[Move Player to Board Position " << boardPosition << "]" << std::endl;
}

void Card::MovePlayerBack(int spacesToMove)
{
	std::cout << "Move to Something" << std::endl;
	std::cout << "[Move Player back " << spacesToMove << "]" << std::endl;
}

void Card::initialiseCards()
{

    std::cout << "INITIALISING CARDS\n";
}

Card::~Card()
{}
