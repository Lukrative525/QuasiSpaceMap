#include "coordinatehash.h"

CoordinateHash::CoordinateHash() {}

std::size_t CoordinateHash::operator()(const Coordinate& coordinate) const {
    return coordinate.getHash();
}
