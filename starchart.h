#ifndef STARCHART_H
#define STARCHART_H

#include <unordered_map>

#include "coordinate.h"
#include "coordinatehash.h"
#include "starsystem.h"

class StarChart
{
public:
    StarChart();
    const StarSystem* getStarSystem(Coordinate grid_position);

private:
    std::unordered_map<Coordinate, StarSystem, CoordinateHash> stars;
};

#endif // STARCHART_H
