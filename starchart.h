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
    QString getStarSystemName(Coordinate grid_position);
    std::pair<float, float> getTrueSpaceCoordinates(Coordinate grid_position);

    std::unordered_map<Coordinate, StarSystem, CoordinateHash> stars;
};

#endif // STARCHART_H
