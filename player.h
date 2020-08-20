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
    Player( const std::string &name, const std::string &symbol ); // constructor
    bool getIsInJail();
    void goToJail();
    int getRoundsInJail() const;
    void addRoundsInJail();
    void exitJail();
    std::string getName() const;
    std::string getSymbol() const;
    int getNumProperty() const;
    void makeMove( int dicePoint );
    ~Player();
};

#endif
