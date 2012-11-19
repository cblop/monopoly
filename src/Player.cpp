#include <string>
#include <vector>
#include "Player.h"
//#include "property.h"

Player::Player(std::string name): name_(name) {
    currentTile = Tile("go");
}

/*
void Player::removeProperty(Property property)
{
    // this will be tricky, involves looking up the property somehow
    return;
}
*/
