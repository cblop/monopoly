#ifndef BOARD_H
#define BOARD_H

#include "Tile.hpp"
#include "Player.hpp"
#include "GroupsManager.hpp"
#include "CardsManager.hpp"
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
    /// @brief method that prints a specific tile
    /// @param[in] i_tile tile to be printed
    //-------------------------------------------------------------------------
    void print(unsigned int i_tile)const;
    //-------------------------------------------------------------------------
    /// @brief method that resets the board
    //-------------------------------------------------------------------------
    void reset();
    //-------------------------------------------------------------------------
    /// @brief method that perfoms an action
    //-------------------------------------------------------------------------
    void action( PlayerManager &i_players);
    //-------------------------------------------------------------------------
    /// @brief method that allows the current Player to buy houses
    //-------------------------------------------------------------------------
    void buildHouses(PlayerManager &i_players);
    //-------------------------------------------------------------------------
    /// @brief method that returns the name of the tile
    //-------------------------------------------------------------------------
    const std::string &getTileName(unsigned int i_index)const;
    //-------------------------------------------------------------------------
    /// default destructor
    //-------------------------------------------------------------------------
    ~Board();


private:
    //-------------------------------------------------------------------------
    /// @brief how the tiles relates to each other, separated in groups
    //-------------------------------------------------------------------------
    GroupsManager m_groups;
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
    /// @brief the cards, community chest and chance
    //-------------------------------------------------------------------------
    CardsManager m_cards;
    //-------------------------------------------------------------------------
    /// @brief all the tiles of the board in the correct order
    //-------------------------------------------------------------------------
    std::vector<Tile *> m_tiles;
};

#endif // BOARD_H
