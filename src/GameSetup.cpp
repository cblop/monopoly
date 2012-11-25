#include <iostream>
#include <climits>
#include <ctime>
#include <string>
#include <vector>
#include <cstdlib>
#include "GameSetup.h"
#include "Player.h"


int howManyPlayers()
{
    int numPlayers = 2;
    std::cout << "Enter number of players (2 - 6): ";
    std::cin >> numPlayers;
    while (numPlayers < 2 || numPlayers > 6) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Please enter a number between 2 and 6: ";
        std::cin >> numPlayers;
    }
    return numPlayers;
}

std::vector<std::string> getPlayerNames(int numPlayers)
{
    std::vector<std::string> playerNames;
    std::string currentName = "";

    for (int i=0;i<numPlayers;i++) {
        std::cout << "What's your name, player " << i+1 << "? ";
        std::cin >> currentName;
        playerNames.push_back(currentName);
    }

    return playerNames;
}

void startNewGame() {
    std::cout << std::endl;

    int numPlayers = howManyPlayers();
    std::cout << std::endl;
    std::vector<std::string> playerNames;
    playerNames = getPlayerNames(numPlayers); 
    std::cout << std::endl;
    std::vector<Player> players;

    for (int i=0;i<numPlayers;i++) {
        players.push_back(Player(playerNames[i]));
        std::cout << "Player " << i+1 << ": " << players[i].getName() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Now we'll roll the dice to see who goes first" << std::endl;

    std::cout << std::endl;

    srand((unsigned)time(0));

    int oldwinner = 0;
    int winner = 0;
    int windex = -1;
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    for (int i=0;i<numPlayers;i++) {
        std::cout << "Press ENTER to roll, " << players[i].getName() << std::endl;
        std::cout << std::endl;
        std::cin.get();
        winner = (rand() % 12) + 1;
        std::cout << players[i].getName() << " rolled: " << winner << std::endl <<std::endl;
        if (winner > oldwinner) windex = i;
        oldwinner = winner;
    }

    std::cout << players[windex].getName() << " goes first." << std::endl;

    std::cout << std::endl;

}
