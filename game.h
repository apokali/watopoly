#ifndef GAME_H
#define GAME_H

#include "player.h"
//#include "board.h"
#include "util.h"
#include "die.h"
#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include <iomanip>
#include <sstream>

class Game {
    bool testingMode;
    int playerNum;
    //std::shared_ptr<Board> board;                                   // Board
    std::unique_ptr<Die> die_model;
    std::map<std::string, std::string> playerAvailable;
    std::vector<std::unique_ptr<Player>> players;
    void prompt( const std::string &message, const std::string &name );
    void checkDouble( int &numDoubles, int &rollsAvailable, int &die1, int &die2 );
    bool roll( std::istringstream &ss, int &die1, int &die2 );      // returns true if successfully rolled
    void displayCommand( const int &rollsAvailable, std::unique_ptr<Player> &p );
    void makeMove( std::unique_ptr<Player> &p, const int &numDoubles, int &rollsAvailable, int &die1, int &die2 );

    public:
    Game();               // constructor
    //void load(std::ifstream&);          // load game
    void save();          // save game
    void printPlayerOptions( std::ostream &out );   
    void addPlayer( std::string &name, std::string &symbol );        // addPlayer
    bool checkPlayerName( std::string &name, std::string &symbol ); // returns true if the player's name and symbol are valid
    void setTestingModeOn();  // set up testing mode
    void run( std::istream &in, std::ostream &out );
    ~Game();
};

#endif
