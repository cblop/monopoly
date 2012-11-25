
#ifndef PLAYER
#define PLAYER

#include <string>
#include <vector>

class Player
{
    std::string m_name;
    int m_balance;

public:
    // constructor
    Player(std::string name);

    std::string getName();
    int getBalance();
    void addBalance(int amount);
    void removeBalance(int amount);
    
};

#endif //PLAYER
