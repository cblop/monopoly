#include <iostream>
#include <string>
#include <vector>

using namespace std;

int howManyPlayers()
{
    int numPlayers = 1;
    cout << "Enter number of players (1 - 4): ";
    cin >> numPlayers;
    while (numPlayers < 1 || numPlayers > 4) {
        cout << "Please enter a number between 1 and 4: ";
        cin >> numPlayers;
    }
    return numPlayers;
}

vector<string> getPlayerNames(int numPlayers)
{
    vector<string> playerNames;
    string currentName = "";

    for (int i=0;i<numPlayers;i++) {
        cout << "What's your name, player " << i+1 << "? ";
        cin >> currentName;
        playerNames.push_back(currentName);
    }

    return playerNames;
}

void startNewGame() {
    cout << endl;

    int numPlayers = howManyPlayers();
    cout << endl;
    vector<string> playerNames;
    playerNames = getPlayerNames(numPlayers); 
    cout << endl;

    for (int i=0;i<numPlayers;i++) {
        cout << "Player " << i+1 << ": " << playerNames[i] << endl;
    }

    cout << endl;
}
