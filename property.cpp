#include <vector>
#include <iostream>
#include "property.h"

Property::Property(std::string name, int price, int *rentValues): name_(name), price_(price), numHouses_(0)
{
    for (int i=0; i<5; i++) {
        rentValues_[i] = rentValues[i];
    }

    owner_ = Player::Player("none");

}

void Property::buyHouse()
{
    if (numHouses_ < 5) {
        numHouses_ += 1;
    }
    else {
        // display something
        std::cout << "You already have a hotel!" << std::endl;
    }
}

void Property::sellHouse()
{
    if (numHouses_ > 0) {
        numHouses_ -= 1;
    }
    else {
        // display something
        std::cout << "You have no houses to sell" << std::endl;
    }
}
