#include "Game.h"
#include "Dice.h"
#include <string>
#include <vector>
#include <climits>
#include <ctime>
#include <stdlib.h>
#include <ncurses.h>
#include "CardsManager.h"


//-----------------------------------------------------------------------------
Game::Game()
{
    m_dice = new Dice();
    SetupGame();
    CardsManager::initialiseCards();
//    CardsManager::printAllCards();
}

//-----------------------------------------------------------------------------
void Game::PrintScreen(std::string message)
{
    const char *cmessage = message.c_str();
    printw(cmessage);
    refresh();

}

//-----------------------------------------------------------------------------
void Game::ClearScreen()
{
    erase();
    int x,y;
    getmaxyx(stdscr,y,x);
    move(500, 500);
}

std::string Game::ReadInput()
{
    char str[64];
    getstr(str);
    std::string inString(str);
    return inString;
}

//-----------------------------------------------------------------------------
void Game::reset()
{

}


//-----------------------------------------------------------------------------
void Game::StartGame()
{
    //m_board[1]->action(m_players,m_currentPlayer);
}

//-----------------------------------------------------------------------------
void Game::SetupGame()
{
    ClearScreen();
    PrintScreen("Oo      oO  .oOOOo.  o.     O  .oOOOo.  OooOOo.   .oOOOo.   o      o       O \n");
    PrintScreen("O O    o o .O     o. Oo     o .O     o. O     `O .O     o. O       O       o \n");
    PrintScreen("o  o  O  O O       o O O    O O       o o      O O       o o       `o     O' \n");
    PrintScreen("O   Oo   O o       O O  o   o o       O O     .o o       O o         O   o   \n");
    PrintScreen("O        o O       o O   o  O O       o oOooOO'  O       o O          `O'    \n");
    PrintScreen("o        O o       O o    O O o       O o        o       O O           o     \n");
    PrintScreen("o        O `o     O' o     Oo `o     O' O        `o     O' o     .     O     \n");
    PrintScreen("O        o  `OoooO'  O     `o  `OoooO'  o'        `OoooO'  OOoOooO     O     \n");

    PrintScreen("\n\n          Welcome to Monopoly! Press any key to start.");
    getch();
    int numPlayers = 2;
    std::vector<std::string> playerNames;
    std::string currentName = "";
    //std::vector<Player> players;

    ClearScreen();
    PrintScreen("Enter number of players (2 - 6): ");
    numPlayers = atoi(ReadInput().c_str());
    while (numPlayers < 2 || numPlayers > 6) {
        PrintScreen("Please enter a number between 2 and 6: ");
        refresh();
        numPlayers = atoi(ReadInput().c_str());
    }

    m_players.resize(numPlayers);

    for (int i=0;i<numPlayers;i++) {
        ClearScreen();
        printw("What's your name, player %d? ", i+1);
        refresh();
        currentName = ReadInput();
        playerNames.push_back(currentName);
    }

    ClearScreen();
    for (int i=0;i<numPlayers;i++) {
        m_players[i] = new Player(playerNames[i]);
        printw("Player %d: %s\n", i+1, m_players[i]->getName().c_str());
    }

    srand((unsigned)time(0));

    int oldwinner = 0;
    int winner = 0;
    int windex = -1;

    printw("\nNow we'll roll the dice to see who goes first.\n");
    for (int i=0;i<numPlayers;i++) {
        printw("\nPress ENTER to roll, %s.\n", m_players[i]->getName().c_str());
        refresh();
        getch();
        m_dice->roll();
        winner = m_dice->getTotal();
        printw("%s rolled: %d\n", m_players[i]->getName().c_str(), winner);
        refresh();
        if (winner > oldwinner) windex = i;
        oldwinner = winner;
    }

    printw("\n%s goes first.\n", m_players[windex]->getName().c_str());
    refresh();

    m_currentPlayer = windex;
    std::cout << std::endl;

}

//-----------------------------------------------------------------------------
void Game::PlayGame()
{
    printw("\nPress any key to start the game.\n");
    refresh();
    getch();

    ClearScreen();
    int numLosers = 0;

    while (numLosers < (int)m_players.size() - 1) {
        numLosers = 0;
        for (int i=0;i<(int)m_players.size();i++) {
            m_currentPlayer = i;
            printw("%s has £%d\n", m_players[i]->getName().c_str(), m_players[i]->getBalance());
            refresh();
            if (m_players[i]->getBalance() > 0) {
                TakeTurn(m_players[i]);
            }
            else {
                printw("%s has no money.\n", m_players[i]->getName().c_str());
                refresh();
                numLosers++;
            }

        }
    }

    printw("Final scores:\n");

    for (int i=0;i<(int)m_players.size(); i++) {
        printw("%s: %d", m_players[i]->getName().c_str(), m_players[i]->getBalance()); 

    }
}

//-----------------------------------------------------------------------------
void Game::TakeTurn(Player *player)
{
    bool repeat = true;
    int doubleCount = 0;

    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
    std::cout << "Press ENTER to roll, " << player->getName() << std::endl;
    std::cout << std::endl;
    std::cin.get();
    m_dice->roll();
    std::cout << m_dice->getTotal() << std::endl;

    //player->takeBalance(10*m_dice->getTotal());
    
    player->movePositionBy(m_dice->getTotal());
    std::cout << player->getName() << " is now at:" << m_board.getTileName(player->getPosition()) << std::endl;

    if (m_dice->isDouble()) {
        if (doubleCount < 3) {
            std::cout << "You rolled a double! Go again." << std::endl;
            doubleCount ++;
        }
        else {
            std::cout << "You rolled three doubles in a row! Go to jail!" << std::endl;
            player->setJailed(true);
        }
    }
    else {
        repeat = false;
    }
    m_board.action(m_players, m_currentPlayer);

}

//-----------------------------------------------------------------------------
Game::~Game()
{
    CardsManager::destroyedAllCards();
}
