#include "player.h"

Player::Player( std::string &name, std::string &symbol )
: name{name}, symbol{symbol} { balance = 1500; }

std::string Player::getName() { return name; }

std::string Player::getSymbol() { return symbol; }


Player::~Player() {}

