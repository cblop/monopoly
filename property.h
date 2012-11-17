
#ifndef PROPERTY
#define PROPERTY

#include <string>
#include "player.h"

class Player;

class Property
{
    std::string name;
    int price;
    int numHouses;
    Player owner;

public:
    // constructor
    Property(std::string, int);
    // destructor
    ~Property();

    std::string getName();
    void setName(std::string);
    int getPrice();
    void setPrice(int);
    int getNumHouses();
    void setNumHouses();
    Player getOwner();
    void setOwner(Player);

}

#endif //PROPERTY
