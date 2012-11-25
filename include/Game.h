#ifndef GAME_H
#define GAME_H

class Player;
class Dice;

#include <iostream>
#include <vector>
#include "Tile.h"

class Game
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    //-------------------------------------------------------------------------
    Game();

    void print(){
        for(unsigned int i=0; i<m_board.size();++i)
        {
            m_board[i]->print();
        }
    }

    //-------------------------------------------------------------------------
    /// @brief method that starts a game
    //-------------------------------------------------------------------------
    void StartGame();

    //-------------------------------------------------------------------------
    /// @brief method that sets up a game by asking for player names, etc
    //-------------------------------------------------------------------------
    void SetupGame();

    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~Game();

private:
    //-------------------------------------------------------------------------
    /// @brief method that resets a game
    //-------------------------------------------------------------------------

    //-------------------------------------------------------------------------
    /// @brief method that read the name of the next tile
    //-------------------------------------------------------------------------
    std::string readTilesName(
            const std::vector<std::string> &i_words,
            unsigned int *i_p
            );

    //-------------------------------------------------------------------------
    static const unsigned int numOfTiles = 40;
    //-------------------------------------------------------------------------
    /// @brief all the tiles of the board in the correct order
    //-------------------------------------------------------------------------
    std::vector<Tile *> m_board;
    //-------------------------------------------------------------------------
    /// @brief all the players for the game
    //-------------------------------------------------------------------------
    std::vector<Player *> m_players;

    //-------------------------------------------------------------------------
    /// @brief the game dice
    //-------------------------------------------------------------------------
    Dice* m_dice;
};

#endif // GAME
