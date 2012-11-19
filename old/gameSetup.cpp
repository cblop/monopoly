#include <iostream>
#include <string>
#include <vector>
#include "gameSetup.h"
#include "player.h"


int howManyPlayers()
{
    int numPlayers = 2;
    std::cout << "Enter number of players (2 - 4): ";
    std::cin >> numPlayers;
    while (numPlayers < 2 || numPlayers > 4) {
        std::cout << "Please enter a number between 2 and 4: ";
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
    Player players[numPlayers];

    for (int i=0;i<numPlayers;i++) {
        players[i] = new Player(playerNames[i]);
        //std::cout << "Player " << i+1 << ": " << players[i].getName() << std::endl;
    }

    std::cout << std::endl;
}
