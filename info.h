#ifndef INFO_H
#define INFO_H
#include <cstddef>

enum class Type { Property, Academic, Ohter };

// Infomation for the tiles
struct Info {
    Type type;
    size_t improvement;
};

#endif
