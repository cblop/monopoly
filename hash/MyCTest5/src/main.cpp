#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Game.h"
#include "CardsManager.h"


int main(int/* argc*/, char **/*argv[]*/)
{
    srand((unsigned)time(0));
    //CardsManager::initialiseCards();
    Game b;
    b.StartGame();
    b.PlayGame();

    return 0;
}
