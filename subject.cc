#include "subject.h"


Subject::Subject( const std::string &name ): name{name} {}

std::string Subject::getName() const { return name; }

Subject::~Subject() {}
