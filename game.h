#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <vector>
#include <map>
#include <memory>

class Player;

// exception
class PlayerNameException{};

// game
class Game {
    bool testingMode;
    int playerNum;
    std::map<std::string, std::string> playerAvailable;
    std::vector<std::shared_ptr<Player>> players;

    public:
    Game();                 // constructor
    void load();            // load game, you probably need to overload input.
    void save();            // save game
    void run();             // run game
    void addPlayer( std::string &name, std::string &symbol);        // addPlayer
    bool checkPlayerName( std::string &name, std::string &symbol ); // returns true if the player's name and symbol are valid
    void setTestingModeOn();  // set up testing mode
    bool isTestingMode();   // returns if the testing mode is on
    void printPlayerAvailable();
    ~Game();
};

#endif