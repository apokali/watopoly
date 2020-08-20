#include "die.h"

int Die::roll() {
    int result = 1 + (rand() % 6);
    return result;
}

Die::~Die() {}
