
#ifndef PROPERTY
#define PROPERTY

#include <string>
#include "player.h"

using std::string;

class Player;

class Property
{
    string name;
    int price;
    int numHouses;
    Player owner;

public:
    // constructor
    Property(string, int);
    // destructor
    ~Property();

    string getName();
    void setName(string);
    int getPrice();
    void setPrice(int);
    int getNumHouses();
    void setNumHouses();
    Player getOwner();
    void setOwner(Player);

}

#endif //PROPERTY
