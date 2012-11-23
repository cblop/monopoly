
#ifndef PLAYER
#define PLAYER

#include <string>
#include <vector>

class Player
{
    std::string name_;
    int balance_;

public:
    // constructor
    //Player(std::string);
    Player(std::string name);
    // destructor
    //~Player();

    std::string getName() { return name_; }
    int getBalance() { return balance_; }
    void addBalance(int amount) { balance_ += amount; }
    void removeBalance(int amount) { balance_ -= amount; }
    
};

#endif //PLAYER
