#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include "player.h"
#include "game.h"

class Game;

int main ( int argc, char *argv[] ) {
    //std::ios::failbit
    std::cin.exceptions(std::ios::eofbit);
    //std::ifstream infile{"..."};
    //std::ofstream outfile{"..."};
    auto game = std::make_unique<Game>();

    try {
        // ===============handles command line arguments=============
        if ( argc <= 2 ) {
            if ( argc == 2 ) {
                std::string arg1(argv[1]);
                if ( arg1 == "-load") {
                    std::cerr << "ERROR: "<< argv[1] << " missing input file name" << std::endl;
                    return 1;
                }
                if ( arg1 != "-testing" ) {
                    std::cerr << "ERROR: invalid command: " << argv[1] << std::endl;
                    return 1;
                }
                game->setTestingModeOn(); // turn on tesing mode
            } // if argc==2
            
            // =================read number of players================
            int numPlayer;
            while ( true ) {
                std::cout << "Enter Number of players: ";
                if ( !(std::cin >> numPlayer) ) {
                    std::cerr << "Invalid number of players" << std::endl;
                    if ( std::cin.eof() ) break;
                    std::cin.clear();
                    std::cin.ignore();
                } else {
                    std::cin.clear();
                    std::cin.ignore();
                    break;
                }
            } // while
            
            // =================read player names==================
            int i = 1;
            while ( i <= numPlayer ) {
                std::string line;
                while ( true ) {
                    game->printPlayerOptions(std::cout);
                    std::cout << "Enter Name of Player" << i << std::endl;
                    if ( !std::getline(std::cin, line) ) break;
                    std::string name, symbol;
                    std::istringstream ss{line};
                    std::getline(ss, name, ',');
                    std::getline(ss, symbol, ',');
                    if ( game->checkPlayerName(name, symbol) ) {   
                        game->addPlayer(name, symbol); break;
                    } else {
                        std::cerr << "Invalid Player Name or Char! " << std::endl;
                    }
                } //while
                ++i; // update the player number  
            } // while
        }// if argc<=2

        //=================== run the game ==================
        game->run( std::cin, std::cout );
        
    } catch (std::ios::failure) {
        std::cerr << "Quit" << std::endl;
    }
    
}