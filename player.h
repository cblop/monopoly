
#ifndef PLAYER
#define PLAYER

// class Property;
// class Tile;

#include <string>
#include <vector>
#include "property.h"
#include "tile.h"

using std::string;
using std::vector;

class Player
{
    string name;
    vector<Property> properties;
    Tile currentTile;    
    // maybe add an icon?

public:
    // constructor
    Player(string);
    string getName();
    void setName(string name);
    vector<Property> getProperties;
    


}

#endif //PLAYER
