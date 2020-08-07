#include "game.h"

Game::Game() {
    testingMode=false;
    playerNum =0;

    playerAvailable["Goose"] = "G";
    playerAvailable["GRT Bus"] = "B";
    playerAvailable["Tim Hortons Doughnut"] = "D";
    playerAvailable["Professor"] = "P";
    playerAvailable["Student"] = "S";
    playerAvailable["Money"] = "$";
    playerAvailable["Laptop"] = "L";
    playerAvailable["Pink tie"] = "T";
}

bool Game::checkPlayerName( std::string &name, std::string &symbol ) {
    if ( (playerAvailable.count(name)) == 1 && (playerAvailable[name] == symbol) ) return true;
    else return false;
}

void Game::addPlayer( std::string &name, std::string &symbol) {
    players.emplace_back(std::make_shared<Player>(name, symbol));
    playerAvailable.erase(name);        // erase the player occupied
    ++playerNum;
}

void Game::setTestingModeOn() {
    testingMode = true;
}


Game::~Game() {}
