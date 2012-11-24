
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
    //std::vector<Property> properties_;
    // Tile currentTile;    
    int m_balance;
    // maybe add an icon?

public:
    // constructor
    //Player(std::string);
    Player(std::string name);
    // destructor
    //~Player();

    std::string getName() { return m_name; }
    int getBalance() { return m_balance; }
    void addBalance(int amount) { m_balance += amount; }
    void removeBalance(int amount) { m_balance -= amount; }
    //std::vector<Property> getProperties() { return properties_; }
    //void addProperty(Property property) { properties_.push_back(property); }
    //void removeProperty(Property property);
    
};

#endif //PLAYER
