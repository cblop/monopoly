#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include "Player.h"
#include <vector>

class Board
{
public:
    //-------------------------------------------------------------------------
    /// @brief default contstructor
    //-------------------------------------------------------------------------
    Board();
    //-------------------------------------------------------------------------
    /// @brief method that prints the board
    //-------------------------------------------------------------------------
    void print(){
        for(unsigned int i=0; i<m_tiles.size();++i)
        {
            m_tiles[i]->print();
        }
    }
    //-------------------------------------------------------------------------
    /// @brief method that resets the board
    //-------------------------------------------------------------------------
    void reset();
    //-------------------------------------------------------------------------
    /// @brief method that perfoms an action
    //-------------------------------------------------------------------------
    void action(
            int i_currentTile,
            const std::vector<Player *> &i_players,
            int i_currentPlayer
            );
    //-------------------------------------------------------------------------
    /// default destructor
    //-------------------------------------------------------------------------
    ~Board();


private:
    //-------------------------------------------------------------------------
    /// @brief method that read the name of the next tile
    //-------------------------------------------------------------------------
    std::string readTilesName(
            const std::vector<std::string> &i_words,
            unsigned int *i_p
            );
    //-------------------------------------------------------------------------
    /// @brief the number of tiles
    //-------------------------------------------------------------------------
    static const unsigned int numOfTiles = 40;
    //-------------------------------------------------------------------------
    /// @brief all the tiles of the board in the correct order
    //-------------------------------------------------------------------------
    std::vector<Tile *> m_tiles;
};

#endif // BOARD_H
