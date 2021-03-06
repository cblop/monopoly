#ifndef PLAYERS_H
#define PLAYERS_H

#include "Player.h"
#include "Dice.h"

class Players
{
public:
    //-------------------------------------------------------------------------
    /// @brief default constructor
    //-------------------------------------------------------------------------
    Players();
    //-------------------------------------------------------------------------
    /// @brief constructor
    /// @param[in] i_numOfPlayers: how many players are playing
    //-------------------------------------------------------------------------
    Players(unsigned int i_numOfPlayers);
    //-------------------------------------------------------------------------
    /// @brief the current player is moved to is new position by rolling
    ///        the dices,
    //-------------------------------------------------------------------------
    void moveCurrentPlayer();
    //-------------------------------------------------------------------------
    /// @brief method that returns the position on the board of
    ///        the current player
    //-------------------------------------------------------------------------
    unsigned int getCurrentPlayersPosition()const;
    //-------------------------------------------------------------------------
    /// @brief method that returns number of players that are still on the game
    //-------------------------------------------------------------------------
    unsigned int howManyPlayersAreStillOntheGame()const;
    //-------------------------------------------------------------------------
    /// @brief set the number of Players and there game
    /// @param[in] i_numOfPlayers: how many players are playing
    //-------------------------------------------------------------------------
    void setPlayers(unsigned int i_numOfPlayers);
    //-------------------------------------------------------------------------
    /// @brief method that prints all players that are still on the game
    ///        starting with the person that owns mos
    //-------------------------------------------------------------------------
    void printWinner()const;
    //-------------------------------------------------------------------------
    /// @brief reset Players
    //-------------------------------------------------------------------------
    void resetAllPlayers();
    //-------------------------------------------------------------------------
    /// @brief method that changes the current player to the next player
    //-------------------------------------------------------------------------
    void moveToNextPlayer();
    //-----------------------------------------------------------------------------
    /// @brief method that returns the Balance of the Player
    //-----------------------------------------------------------------------------
    unsigned int getBalance();
    //-----------------------------------------------------------------------------
    /// @brief method that takes an amount of money from the balance of the Player
    //-----------------------------------------------------------------------------
    bool takeBalance(unsigned int i_amount);
    //-----------------------------------------------------------------------------
    /// @brief method that adds an amount of money to the balance of the Player
    //-----------------------------------------------------------------------------
    void addBalance(unsigned int i_amount);
    //-----------------------------------------------------------------------------
    /// @brief method that adds an amount of money to a specific Player
    /// @param[in] i_amount: amount to be added
    /// @param[in] i_player: the player that gets the money
    //-----------------------------------------------------------------------------
    void addBalance(unsigned int i_amount, unsigned int i_player);
    //-----------------------------------------------------------------------------
    /// @brief method that returns the current position of the current Player
    //-----------------------------------------------------------------------------
    unsigned int getPosition() const;
    //-----------------------------------------------------------------------------
    /// @brief method that moves the current player to a new position
    /// @param[in] i_amount how many tiles the current Player will be moved
    //-----------------------------------------------------------------------------
    void movePositionBy(unsigned int i_amount);
    //-----------------------------------------------------------------------------
    /// @brief method that sets the positions of the current player
    /// @param[in] i_position the new Position of the current Player
    //-----------------------------------------------------------------------------
    void setPosition(unsigned int i_position);
    //-----------------------------------------------------------------------------
    /// @brief method that sends the current player to jail
    //-----------------------------------------------------------------------------
    void setJailed(bool jailed);
    //-----------------------------------------------------------------------------
    /// @brief method that returns the current player
    //-----------------------------------------------------------------------------
    unsigned int getCurrentPlayer()const;
    //-----------------------------------------------------------------------------
    /// @brief method that returns the name of the current Player
    //-----------------------------------------------------------------------------
    const std::string &getName()const;
    //-------------------------------------------------------------------------
    /// @brief default destructor
    //-------------------------------------------------------------------------
    ~Players();

private:
    //-------------------------------------------------------------------------
    /// @brief all the Players of the game
    //-------------------------------------------------------------------------
    std::vector<Player> m_players;
    //-------------------------------------------------------------------------
    /// @brief the number of the current Player
    //-------------------------------------------------------------------------
    unsigned int m_currentPlayer;
    //-------------------------------------------------------------------------
    /// @brief num of players that have lost the game
    //-------------------------------------------------------------------------
    unsigned int m_numOfLoosers;
    //-------------------------------------------------------------------------
    /// @brief the dices
    //-------------------------------------------------------------------------
    Dice m_dices;
};

#endif // PLAYERS_H
