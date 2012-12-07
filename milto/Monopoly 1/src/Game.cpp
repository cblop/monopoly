#include "Game.h"
#include "Dice.h"
#include <string>
#include <vector>
#include <climits>
#include <ctime>
#include <stdlib.h>


//-----------------------------------------------------------------------------
Game::Game()
{
    std::cout << "GAME CONSTRUCTOR!\n";
    m_dice = new Dice();
    SetupGame();
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
    std::cout << "GAME SETUP!!\n";
   }

//-----------------------------------------------------------------------------
void Game::PlayGame()
{
    std::cout << "\nNow we will start the game.\n" << std::endl;

 //   while(m_players1.howManyPlayersAreStillOntheGame()>1)
    {
      std::cout << std::endl;
      std::cout << m_players1.getName() << " has " << m_players1.getBalance() << std::endl;
      m_board.action(m_players1);
      m_players1.moveToNextPlayer();
      std::cout<<"Player 2:\n";
      m_players1.movePositionBy(2);
      m_board.action(m_players1);

//      m_players1.
    }

    m_players1.printWinner();

}

//-----------------------------------------------------------------------------
Game::~Game()
{
}
