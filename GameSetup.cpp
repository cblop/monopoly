#include <iostream>
#include <string>
#include <vector>

using namespace std;

int howManyPlayers()
{
    int playerNum = 1;
    cout << "Enter number of players (1 - 4): ";
    cin >> playerNum;
    while (playerNum < 1 || playerNum > 4) {
        cout << "Please enter a number between 1 and 4: ";
        cin >> playerNum;
    }
    return playerNum;
}

vector<string> getPlayerNames(int numberOfPlayers)
{
    vector<string> playerNames;
    string currentName = "";

    for (int i=0;i<numberOfPlayers;i++) {
        cout << "What's your name, player " << i+1 << "? ";
        cin >> currentName;
        playerNames.push_back(currentName);
    }

    return playerNames;
}

void startNewGame() {
    cout << endl;

    int playerNum = howManyPlayers();
    cout << endl;
    vector<string> playerNames;
    playerNames = getPlayerNames(playerNum); 
    cout << endl;

    for (int i=0;i<playerNum;i++) {
        cout << "Player " << i+1 << ": " << playerNames[i] << endl;
    }

    cout << endl;
}
