#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>


//#include "Player.h"

using namespace std;

//forward declaration
void BinaryChoice(int moneyToRemove);
void GetOutOfJailFree();
void GetMoney(int moneyToAdd);
void StreetRepairs(int house, int hotel);
void GoToJail();
void LoseMoney(int moneyToRemove);
void MovePlayer(int boardPosition);

int main()
{
	srand(time(NULL));
	string line;
	cout << endl;
	cout << "Do It\n";
	
	ifstream myfile("CommunityChest");
	
	int random = rand() % 17 + 1;
	int matchCase =16; 
	int count = 0;
	
	matchCase = random;
	
	/*Player *p = new Player("Hashim");
	p.addBalance(100);
	p.getBalance();
	cout << p.getBalance() << endl;*/
	
		
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			if (count == matchCase)
			{
				cout << count <<endl;
				istringstream iss(line);
				string sub;
				iss >> sub;
				cout << line << endl;
				
				cout << "CARD TYPE ==> ";
				if (sub == "b")
				{
					int moneyToRemove;
					iss >> sub;
					istringstream(sub) >> moneyToRemove;
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
					istringstream(sub) >> moneyToAdd;
					GetMoney(moneyToAdd);
				}

				else if (sub == "h")
				{
					int house, hotel;
					iss >> sub;
					istringstream(sub) >> house;
					iss >> sub;
					istringstream(sub) >> hotel;
					StreetRepairs(house, hotel);
				}

				else if (sub == "j")
					GoToJail();

				else if (sub == "l")
				{
					int moneyToRemove;
					iss >> sub;
					istringstream(sub) >> moneyToRemove;
					LoseMoney(moneyToRemove);
				}
				
				else if (sub == "m")
				{
					int boardPosition;
					iss >> sub;
					istringstream(sub) >> boardPosition;
					MovePlayer(boardPosition);
				}

			
				break; //break out of while loop

			}
			count++;
		}
		myfile.close();
	}
	else
		cout << "NOOOOOOOOOOOOOOOOOOO" << endl;
		

	cout << endl;
	return 0;
}


//METHODS............................................................................

void BinaryChoice(int moneyToRemove)
{
	cout << "Binary Choice" <<endl;
	cout << "Pay £" << moneyToRemove << "(0) or Take A Chance (1);" <<endl;
	int doChance;
	cin >> doChance;
	if (doChance == 0)
		cout << "[Take £" << moneyToRemove << " From Player]" << endl;
	else if (doChance == 1)
		cout << "[Call 'Chance']" << endl;
}

void GetOutOfJailFree()
{
	cout << "Get Out of Jail FREE" <<endl;
	cout << "[Set some flag in Player]" <<endl;
}

void GetMoney(int moneyToAdd)
{
	cout << "Get Money" <<endl;
	cout << "[Player recieves £" << moneyToAdd << "]" << endl;
}

void StreetRepairs(int house, int hotel)
{
	cout << "Assessed for Street Repairs" <<endl;
	cout << "[Player has to pay £" << house << "for each house and £" <<hotel << "]" << endl;
}

void GoToJail()
{
	cout << "GO TO JAIL!" <<endl;
}

void LoseMoney(int moneyToRemove)
{
	cout << "Lose Money" <<endl;
	cout << "[Take £" << moneyToRemove << " From Player]" << endl;
}

void MovePlayer(int boardPosition)
{
	cout << "Move to Something" <<endl;
	cout << "[Move Player to Board Position" << boardPosition << "]" << endl;
}
