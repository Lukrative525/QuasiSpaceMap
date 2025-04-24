#include "starchart.h"
#include "starchartdata.h"

StarChart::StarChart()
{
    for (const StarInfo& info : star_data) {
        stars.emplace(Coordinate{info.grid_x, info.grid_y}, StarSystem{info.name, info.pos_x, info.pos_y});
    }
}

const StarSystem* StarChart::getStarSystem(Coordinate grid_position)
{
    std::unordered_map<Coordinate, StarSystem, CoordinateHash>::const_iterator iterator = stars.find(grid_position);
    if (iterator != stars.end())
    {
        return &(iterator->second);
    }

    return nullptr;
}
