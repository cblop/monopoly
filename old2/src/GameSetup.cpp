#include <iostream>
#include <string>
#include <vector>
#include "GameSetup.h"
#include "Player.h"


int howManyPlayers()
{
    int numPlayers = 2;
    std::cout << "Enter number of players (2 - 6): ";
    std::cin >> numPlayers;
    while (numPlayers < 2 || numPlayers > 6) {
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

    std::cout << "Now we'll roll the dice to see who goes first" << std::endl
        << "Press space to roll." << std::endl;

    std::cout << std::endl;

    int oldwinner = 0;
    int winner = 0;
    int windex = -1;
    for (int i=0;i<numPlayers;i++) {
        std::cout << players[i].getName() << ": ";
        std::cin >> winner;
        if (winner > oldwinner) windex = i;
    }

    std::cout << players[windex].getName() << " goes first." << std::endl;
}
