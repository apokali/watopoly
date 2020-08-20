#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>

class Player {
    std::string name, symbol;
    std::vector<std::shared_ptr<Player>> playerList;
    int balance;
    bool isInJail;
    int roundsInJail;
    int curPos;     //ws current position, starts with 0
    //std::vector<std::shared_ptr<Tile>> property;
    

    public:
    Player( std::string &name, std::string &symbol ); // constructor
    bool getIsInJail();
    void goToJail();
    int getRoundsInJail();
    void addRoundsInJail();
    void exitJail();
    std::string getName();
    std::string getSymbol();
    int getNumProperty();
    void makeMove( int dicePoint );
    ~Player();
};

#endif
