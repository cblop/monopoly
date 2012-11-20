
#ifndef PROPERTY
#define PROPERTY

class Player;

#include <string>
//#include "player.h"

class Property
{
    std::string name_;
    int price_;
    int rentValues_[5];
    int numHouses_;
    bool mortgaged_;
    Player owner_;

public:
    // constructor
    Property(std::string, int, int *);

    // destructor
    //~Property();

    std::string getName() { return name_; }
    int getPrice() { return price_; }
    int getRent() { return rentValues_[numHouses_]; }
    int getNumHouses() { return numHouses_; }
    void setMortgaged(bool value) { mortgaged_ = value; }
    Player getOwner() { return owner_; }
    void setOwner(Player newOwner) { owner_ = newOwner; }
    void buyHouse();
    void sellHouse();

};

#endif //PROPERTY
