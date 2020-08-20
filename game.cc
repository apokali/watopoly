#include "game.h"

Game::Game() {
    //board = std::make_unqiue<Board>();          //initialize board
    testingMode=false;
    playerNum = 0;
    die_model = std::make_shared<Die>();

    // options of palyers available
    playerAvailable["Goose"] = "G";
    playerAvailable["GRT Bus"] = "B";
    playerAvailable["Tim Hortons Doughnut"] = "D";
    playerAvailable["Professor"] = "P";
    playerAvailable["Student"] = "S";
    playerAvailable["Money"] = "$";
    playerAvailable["Laptop"] = "L";
    playerAvailable["Pink tie"] = "T";
}

void Game::prompt( const std::string &message, const std::string &name) {
    int size = message.size() + name.size() + 4;
    printLine( std::cout, "-", size , true);
    std::cout << "|" << name << ": " << message << "|" << std::endl;
    printLine( std::cout, "-", size , true);
}

void Game::printPlayerOptions( std::ostream &out ) {
    out << "Please choose players from the list" << std::endl;
    printLine( out, "-", 35 , true);
    out << std::setw(20) << "Name" <<"  "<< std::setw(5) << "Symbol" << std::endl;
    printLine( out, "-", 35 , true);
    for ( auto p: playerAvailable ) {
        out << std::setw(20) << p.first  << std::setw(5) << p.second << std::endl;
    }
    printLine( out, "-", 35 , true);
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

// void load(std::ifstream &infile) {
//     std::string www;
//     infile >> www;
// }

void Game::checkDouble( int &numDoubles, int &rollsAvailable, int &die1, int &die2 ) {
    if ( die1 == die2 )  {
        ++numDoubles;
        ++rollsAvailable;
    } // if doubles
}

bool Game::roll( std::istringstream &ss, int &die1, int &die2 ) {
    if ( testingMode ) {  // if testingModeOn
        if ( !ss.eof() ) {
            //out << line << "you are here\n"  ; 
            if ( !( ss >> die1 && ss >> die2 ) || die1 < 0 || die2 < 0) {
                return false;
            } else return true;

        } else {        // dice by generation
            die1 = die_model->roll();
            die2 = die_model->roll();
            return true;
        } 
    } else {  // if tesingModeOff
        if ( !ss.eof() ) {
            return false;
        }
        else {
            die1 = die_model->roll();
            die2 = die_model->roll();
            return true;
        }
    } // if-then-else, after rolling the dice
}

void Game::run( std::istream &in, std::ostream &out ) {
    while ( true ) {
        if ( players.size() == 1 ) {
            out << players[0]->getName() << " is the winner!" << std::endl;
            break;
        }
        for ( auto p : players ) {
            prompt( "It is your turn!", p->getName());
            std::string line;
            // runtime parameters for a round
            int numDoubles = 0;
            int rollsAvailable = 1;
            int die1, die2;

            while ( true ) {
                // prompting user to type in commands
                prompt( "What you do you want to do next?", p->getName());
                out <<"Available commands are: ";
                if ( rollsAvailable != 0  ) out << "roll ";
                if ( rollsAvailable == 0 || p->getIsInJail() ) out << "next ";
                if ( p->getIsInJail() && p->getRoundsInJail() != 0 ) out << "usecups " << "paymoney";
                //if ( p->getNumProperty() != 0 ) out<< "trade ";
                // check monopoly
                out << "assets all save" << std::endl;
                
                // reading commandlines
                while ( !(std::getline(in, line)) ) {out << "Invalid command!" << std::endl;} // while
                std::istringstream ss{line};
                std::string command;
                ss >> command;
                
                // =====ROLL=====
                if ( command == "roll" ) {
                    if ( rollsAvailable == 0 ) {
                        prompt( "You cannot roll again!", p->getName());
                    } else {
                        if ( roll( ss, die1, die2 ) ) {
                            --rollsAvailable;
                            checkDouble( numDoubles,rollsAvailable,die1,die2 );
                            out <<  p->getName() << ": You rolled " << die1 << " and "<< die2 << std::endl;
                            if ( numDoubles == 1 && p->getIsInJail() ) {
                                rollsAvailable = 0;   // after jail, you cannot roll again
                                p->exitJail();
                                p->makeMove(die1+die2);
                                out << " and you are now on: " <<std::endl;// unfinished
                            } else if ( numDoubles == 3 && !p->getIsInJail() ) {
                                rollsAvailable = 0;
                                p->goToJail();
                            } // if roll three doubles in a row
                            else {
                                p->makeMove(die1+die2);
                                out << " and you are now on: " <<std::endl;// unfinished
                            }
                        } else {
                            std::cout << "Invalid! roll" << std::endl;
                        }
                    } // else roll the dice and move
                } 
                
                // =====NEXT=====
                else if ( command == "next" ) {
                    if ( rollsAvailable != 0 ) { // only if your not in jail
                        prompt( "You cannot end your turn!", p->getName());
                    } else { 
                        if ( p->getRoundsInJail() != 3 ) p->addRoundsInJail();
                        break; // if a player can end turn, then break the loop
                    }
                } else if ( command == "trade" ) {
                    // if ( p->getNumProperty() == 0 ) {
                    //     out <<  p->getName() << ": You have nothing to trade!" << std::endl;
                    // } else {
                    //     //
                    // }
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
                } else if ( command == "usecups") {
                    // do
                } else if ( command == "paymoney") {
                    // do
                } else {
                    out << "Invalid command!" << std::endl;
                }
            } //while
        } //for 
    }//while
} 

Game::~Game() {}
