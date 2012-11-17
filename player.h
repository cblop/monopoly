
#ifndef PLAYER
#define PLAYER

// class Property;
// class Tile;

#include <string>
using std::string;

class Player
{
    string name;
    // vector<Property> properties;
    // Tile currentTile;    

public:
    // add stuff to this constructor
    Player(string);
    string getName();
    void setName(string name);
    // vector<Property> getProperties;
    


}

#endif //PLAYER
