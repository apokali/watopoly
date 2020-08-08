#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
    std::string name, symbol;
    int balance;
    

    public:
    Player( std::string &name, std::string &symbol ); // constructor
    std::string getName();
    std::string getSymbol();
    ~Player();
};

#endif
