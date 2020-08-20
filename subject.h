#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>
#include "info.h"

struct Info;

class Subject {
    std::string name;

    public:
    Subject( const std::string & );
    std::string getName() const;
    virtual Info getInfo() = 0;
    virtual ~Subject();

};

#endif
