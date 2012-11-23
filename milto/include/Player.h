
#ifndef PLAYER
#define PLAYER

//class Tile;

#include <string>
#include <vector>
//#include "property.h"
//#include "Tile.h"

class Player
{
    std::string m_name;
    int currentPosition;
    int m_balance;

public:
    // constructor
    Player(const std::string &name): m_name(name) {}

    // destructor
    //~Player();

    std::string getName() { return m_name; }
    int getBalance() { return m_balance; }
    void addBalance(int amount) { m_balance += amount; }
    void removeBalance(int amount) { m_balance -= amount; }
};

#endif //PLAYER
