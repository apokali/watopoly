#include "gym.h"

Gym::Gym( const std::string &name, int price, int improvementcost )
:Subject{name}, price{price}, improvementcost{improvementcost} {
    info.type = Type::Property;
    info.improvement = 0; 
}

Info Gym::getInfo() { return info; }

