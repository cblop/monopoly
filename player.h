
#ifndef PLAYER
#define PLAYER

// class Property;
// class Tile;

#include <string>
#include <vector>
#include "property.h"
#include "tile.h"

class Player
{
    std::string name;
    std::vector<Property> properties;
    Tile currentTile;    
    // maybe add an icon?

public:
    // constructor
    Player(std::string);
    // destructor
    ~Player();

    std::string getName();
    void setName(std::string name);
    std::vector<Property> getProperties;
    


}

#endif //PLAYER
