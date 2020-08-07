#include "player.h"

Player::Player( std::string &name, std::string &symbol )
: name{name}, symbol{symbol} { balance = 1500; }


Player::~Player() {}

