#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Game.h"
#include "GroupsManager.h"
#include "Tile.h"
#include "Station.h"
#include "NormalProperty.h"


int main(int/* argc*/, char **/*argv[]*/)
{
//    PropertiesRelations p;
    std::cout << "Start Program\n";
//    std::vector<unsigned int> prices;
//    prices.resize(6);
//    std::string name = "STationn";
//    Tile *tile = new Station(name,200,prices);
//    GroupsManager::addTile("blue", tile);

//    unsigned int colour = tile->getColour();
    //srand((unsigned)time(0));
    Game b;
    b.PlayGame();
    std::cout << "End of Program\n";
    return 0;
}
