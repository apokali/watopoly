#include "academic.h"


Academic::Academic( const std::string &name, int price, int improvementcost, std::vector<int> rent )
:Subject{name}, price{price}, improvementcost{improvementcost}, rent{rent} {
    info.type = Type::Academic;
    info.improvement = 0; 
}


Info Academic::getInfo() { return info; }

