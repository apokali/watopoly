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

void Game::printLine( std::ostream &out, std::string s, int num) {
    for ( int i = 0; i < num; ++ i ) {
        out << s;
    }
    out << std::endl;
}

void Game::printPlayerOptions( std::ostream &out ) {
    out << "Please choose players from the list" << std::endl;
    printLine( out, "-", 35 );
    out << std::setw(20) << "Name" <<"  "<< std::setw(5) << "Symbol" << std::endl;
    printLine( out, "-", 35 );
    for ( auto p: playerAvailable ) {
        out << std::setw(20) << p.first  << std::setw(5) << p.second << std::endl;
    }
    printLine( out, "-", 35 );
}

bool Game::checkPlayerName( std::string &name, std::string &symbol ) {
    if ( (playerAvailable.count(name)) == 1 && (playerAvailable[name] == symbol) ) return true;
    else return false;
}

void Game::addPlayer( std::string &name, std::string &symbol ) {
    players.emplace_back(std::make_shared<Player>(name, symbol));
    playerAvailable.erase(name);        // erase the player occupied
    ++playerNum;
}

void Game::setTestingModeOn() {
    testingMode = true;
}


void Game::run( std::istream &in, std::ostream &out ) {
    while ( true ) {
        if ( players.size() == 1 ) {
            out << players[0]->getName() << " is the winner!" << std::endl;
            break;
        }
        for ( auto p : players ) {
            out << p->getName() << ": It is your turn!" << std::endl;
            std::string command;
            while ( !(in >> command) ) {
                if ( command == "roll") {
                    // do something
                } else if ( command == "next" ) {
                    // do something
                    break;
                } else if ( command == "trade" ) {
                    // do something
                } else if ( command == "imporve" ) {
                    // do something
                } else if ( command == "mortage" ) {
                    // do
                } else if ( command == "unmortage" ) {
                    // do
                } else if ( command == "bankrupt" ) {
                    // do
                } else if ( command == "assets" ) {
                    // do
                } else if ( command == "all") {
                    // do
                } else if ( command == "save" ) {
                    // do
                } else {
                    out << "Invalid command!" << std::endl;
                }
            } //while
        } //for 
    }//while
} 

Game::~Game() {}
