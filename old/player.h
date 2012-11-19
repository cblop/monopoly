
#ifndef PLAYER
#define PLAYER

//class Tile;
class Property;

#include <string>
#include <vector>
//#include "property.h"
//#include "tile.h"

class Player
{
    std::string name_;
    std::vector<Property> properties_;
    //Tile currentTile;    
    int balance_;
    // maybe add an icon?

public:
    // constructor
    //Player(std::string);
    Player(std::string name);
    // destructor
    //~Player();

    std::string getName() { return name_; }
    int getBalance() { return balance_; }
    void addBalance(int amount) { balance_ += amount; }
    void removeBalance(int amount) { balance_ -= amount; }
    //std::vector<Property> getProperties() { return properties_; }
    //void addProperty(Property property) { properties_.push_back(property); }
    void removeProperty(Property property);
    
};

#endif //PLAYER
