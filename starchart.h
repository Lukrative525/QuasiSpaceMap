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
    const StarSystem* getPortal(Coordinate grid_position);
    const StarSystem* getStarSystem(Coordinate grid_position);
    int getTrueSpaceX(int grid_position_x);
    int getTrueSpaceY(int grid_position_y);

private:
    std::unordered_map<Coordinate, StarSystem, CoordinateHash> portals;
    std::unordered_map<Coordinate, StarSystem, CoordinateHash> stars;
};

#endif // STARCHART_H
