#ifndef ACADEMIC_H
#define ACADEMIC_H
#include <string>
#include <vector>
#include "info.h"
#include "subject.h"

class Academic: public Subject {
    Info info;
    int price, improvementcost;
    std::vector<int> rent;

    public:
    Academic( const std::string &name, int price, int improvementcost, std::vector<int> rent );
    virtual Info getInfo() override;
};

#endif
