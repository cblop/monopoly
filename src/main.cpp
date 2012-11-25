#include <iostream>
#include "Game.h"
#include "GameSetup.h"

int main(int/* argc*/, char **/*argv[]*/)
{
    Game b;
    b.StartGame();
    b.print();
    startNewGame();
    return 0;
}
