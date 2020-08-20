#ifndef GYM_H
#define GYM_H
#include "subject.h"

class Gym: public Subject {
    Info info;
    int price, improvementcost;

    public:
    Gym( const std::string &name, int price, int improvementcost );
    virtual Info getInfo() override;
};

#endif
