#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include <iomanip>

class Player;

// game
class Game {
    bool testingMode;
    int playerNum;
    std::map<std::string, std::string> playerAvailable;
    std::vector<std::shared_ptr<Player>> players;
    void printLine( std::ostream &out, std::string s, int num);

    public:
    Game();                 // constructor
    void load( std::ifstream & infile );           // load game, you probably need to overload input.
    void save( std::ofstream & outfile );          // save game
    void printPlayerOptions( std::ostream &out );   
    void addPlayer( std::string &name, std::string &symbol );        // addPlayer
    bool checkPlayerName( std::string &name, std::string &symbol ); // returns true if the player's name and symbol are valid
    void setTestingModeOn();  // set up testing mode
    bool isTestingMode();   // returns if the testing mode is on
    void run( std::istream &in, std::ostream &out);
    ~Game();
};

#endif