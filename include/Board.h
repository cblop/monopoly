#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "Tile.h"

class Board
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    //-------------------------------------------------------------------------
    Board();

    void print(){
        for(unsigned int i=0; i<m_board.size();++i)
        {
            m_board[i]->print();
        }
    }

    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~Board();

private:
    //-------------------------------------------------------------------------
    /// @brief method that read the name of the next tile
    //-------------------------------------------------------------------------
    std::string readTilesName(
            const std::vector<std::string> &i_words, unsigned int *i_p
            );

    //-------------------------------------------------------------------------
    static const unsigned int numOfTiles = 40;
    //-------------------------------------------------------------------------
    /// @brief all the tiles of the board in the correct order
    //-------------------------------------------------------------------------
    std::vector<Tile *> m_board;
};

#endif // BOARD_H
