#ifndef GAME_H
#define GAME_H

class Player;
class Dice;

#include <iostream>
#include <vector>
#include "Players.h"
#include "Board.h"

class Game
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    //-------------------------------------------------------------------------
    Game();



    //-------------------------------------------------------------------------
    /// @brief method that starts a game
    //-------------------------------------------------------------------------
    void StartGame();

    //-------------------------------------------------------------------------
    /// @brief method that plays the game
    //-------------------------------------------------------------------------
    void PlayGame();

    //-------------------------------------------------------------------------
    /// @brief method that takes a turn
    //-------------------------------------------------------------------------
    void TakeTurn(Player *player);

    //-------------------------------------------------------------------------
    /// @brief method that sets up a game by asking for player names, etc
    //-------------------------------------------------------------------------

    //-------------------------------------------------------------------------
    /// @brief method that resets a game
    //-------------------------------------------------------------------------
    void reset();

    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~Game();

private:
    //-------------------------------------------------------------------------
    /// @brief the board of the game
    //-------------------------------------------------------------------------
    Board m_board;

    //-------------------------------------------------------------------------
    /// @brief method that read the name of the next tile
    //-------------------------------------------------------------------------
    std::string readTilesName(
            const std::vector<std::string> &i_words,
            unsigned int *i_p
            );
    //-------------------------------------------------------------------------
    /// @brief method that sets up the Game
    //-------------------------------------------------------------------------
    void SetupGame();


    //-------------------------------------------------------------------------
    /// @brief all the Players of the Game
    //-------------------------------------------------------------------------
    Players m_players1;

    //-------------------------------------------------------------------------
    /// @brief the game dice
    //-------------------------------------------------------------------------
    Dice* m_dice;
};

#endif // GAME
