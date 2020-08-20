#include "player.h"

Player::Player( const std::string &name, const std::string &symbol )
: name{name}, symbol{symbol} { 
    balance = 1500;
    isInJail = false;
    roundsInJail = 0;
    curPos = 0; 
}

std::string Player::getName() const { return name; }

std::string Player::getSymbol() const { return symbol; }

bool Player::getIsInJail() { return isInJail; }

int Player::getRoundsInJail() const { return roundsInJail; }

void Player::addRoundsInJail() {
    ++roundsInJail;
}
void Player::exitJail() {
    roundsInJail = 0;
    isInJail = false;
}

void Player::goToJail() { 
    isInJail = true; 
    curPos = 10;
}

//int Player::getNumProperty() { return property.size(); }

void Player::makeMove( int dicePoint ) {
    if ( ( dicePoint + curPos ) > 39 ) {
        curPos = dicePoint + curPos - 39;
    } else {
        curPos += dicePoint;
    }
}

Player::~Player() {}
