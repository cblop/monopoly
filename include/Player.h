#ifndef PLAYER
#define PLAYER

#include <string>
#include <vector>

class Player
{
    std::string m_name;
    int m_balance;
    int m_position;

public:
    // constructor
    Player(std::string name);

    std::string getName();
    int getBalance();
    void addBalance(int amount);
    void removeBalance(int amount);
    int getPosition();
    void movePositionBy(int amount);
    void setPosition(int position);
    
};

#endif //PLAYER
