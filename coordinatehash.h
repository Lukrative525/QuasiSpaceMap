#ifndef COORDINATEHASH_H
#define COORDINATEHASH_H

#include <cstddef>

#include "coordinate.h"

class CoordinateHash {
public:
    CoordinateHash();
    std::size_t operator()(const Coordinate& coordinate) const;
};

#endif // COORDINATEHASH_H
