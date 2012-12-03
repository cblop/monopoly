#ifndef DICE
#define DICE

class Dice
{
    int m_values[2];

public:
    // constructor
    Dice();

    int *getValues();
    int getTotal();
    bool isDouble();
    void roll();

    ~Dice();
    
};

#endif //PLAYER
