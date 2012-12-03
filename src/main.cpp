#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Game.h"
#include "Card.h"
#include <ncurses.h>


int main(int/* argc*/, char **/*argv[]*/)
{
    srand((unsigned)time(0));
    initscr();
    //noecho();
    //Card::initialiseCards();
    Game b;
    b.StartGame();
    b.PlayGame();
    endwin();
    return 0;
}
