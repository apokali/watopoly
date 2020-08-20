#ifndef RESIDENCE_H
#define RESIDENCE_H
#include "subject.h"

class Residence: public Subject {
    Info info;
    int price, improvementcost;

    public:
    Residence( const std::string &name, int price, int improvementcost );
    virtual Info getInfo() override;
};

#endif
