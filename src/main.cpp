#include <iostream>
#include "Game.h"
#include "Card.h"


int main(int/* argc*/, char **/*argv[]*/)
{
    Card::initialiseCards();
    Game b;
    b.StartGame();
    return 0;
}
