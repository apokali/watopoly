#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include "player.h"
#include "game.h"

int main ( int argc, char *argv[] ) {
    srand((unsigned) time(0));
    std::cin.exceptions(std::ios::eofbit);
    //std::ifstream intfile{"..."};
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
                    std::cerr << "Invalid: <Number>" << std::endl;
                    std::cin.ignore();
                    std::cin.clear();
                } else {
                    std::cin.ignore();
                    std::cin.clear();
                    break;
                }
            } // while
            
            // =================read player names==================
            int i = 1;
            while ( i <= numPlayer ) {
                std::string line;
                game->printPlayerOptions(std::cout);
                while ( true ) {
                    std::cout << "Enter Player" << i << std::endl;
                    if ( !std::getline(std::cin, line) ) break;
                    std::string name, symbol;
                    std::istringstream ss{line};
                    std::getline(ss, name, ',');
                    std::getline(ss, symbol, ',');
                    if ( game->checkPlayerName(name, symbol) ) {   
                        game->addPlayer(name, symbol); break;
                    } else {
                        std::cerr << "Invalid: <Name>,<Symbol> " << std::endl;
                    }
                } //while
                ++i; // update the player number  
            } // while
        
        // when 3 arguments
        } else if ( argc == 3 ) {
            std::string arg1(argv[1]);
            if ( arg1 == "-load" ) {
                std::string arg2( argv[2] );
                std::ifstream infile{ arg2 }; 
                if ( infile.fail() ) {
                    std::cerr << "Invalid: -load <filename>. Cannot read files." << std::endl;
                    return 1;
                } else {
                    //game->load( infile );
                }
            } else {
                std::cerr << "Invalid: -load <filename> " << std::endl;
                return 1;
            }
        
        // when 4 arguments
        } else if ( argc == 4 ) {
            std::string arg1(argv[1]);
            if ( arg1 == "-load" ) {
                std::string arg2( argv[2] );
                std::ifstream infile{ arg2 };
                if ( infile.fail() ) {
                    std::cerr << "Invalid: -load <filename>. Cannot read files." << std::endl;
                    return 1;
                } else {
                    //game->load( infile );
                    std::string arg3( argv[3] );
                    if ( arg3 != "-testing" ) {
                        std::cerr << "Invalid: -load <filename> -testing." << std::endl;
                        return 1;
                    } else {
                        game->setTestingModeOn(); // turn on tesing mode
                    }
                }
            } else if (arg1 == "-testing" ) {
                game->setTestingModeOn(); 
                std::string arg2( argv[2] );
                std::ifstream infile{ arg2 };
                if ( infile.fail() ) {
                    std::cerr << "Invalid: -load <filename>. Cannot read files." << std::endl;
                    return 1;
                } else {
                    //game->load( infile );
                }
            } else {
                std::cerr << "Invalid commands." << std::endl;
                return 1;
            }
        } else {
            std::cerr << "Invalid commands." << std::endl;
            return 1;
        }

        //=================== run the game ==================
        // maybe need another method to decide the order of players
        game->run( std::cin, std::cout );

    } catch (std::ios::failure) {
        std::cerr << "Quit" << std::endl;
    }
    
}
