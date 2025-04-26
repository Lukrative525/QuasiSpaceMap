#include "starchart.h"
#include "starchartdata.h"

StarChart::StarChart()
{
    for (const StarInfo& info : portal_entrance_data) {
        portal_entrances.emplace(Coordinate{info.grid_x, info.grid_y}, StarSystem{info.name, info.pos_x, info.pos_y});
    }

    for (const StarInfo& info : portal_exit_data) {
        portal_exits.emplace(Coordinate{info.grid_x, info.grid_y}, StarSystem{info.name, info.pos_x, info.pos_y});
    }

    for (const StarInfo& info : star_data) {
        stars.emplace(Coordinate{info.grid_x, info.grid_y}, StarSystem{info.name, info.pos_x, info.pos_y});
    }
}

const StarSystem* StarChart::getPortalEntrance(Coordinate grid_position)
{
    std::unordered_map<Coordinate, StarSystem, CoordinateHash>::const_iterator iterator = portal_entrances.find(grid_position);
    if (iterator != portal_entrances.end())
    {
        return &(iterator->second);
    }

    return nullptr;
}

const StarSystem* StarChart::getPortalExit(Coordinate grid_position)
{
    std::unordered_map<Coordinate, StarSystem, CoordinateHash>::const_iterator iterator = portal_exits.find(grid_position);
    if (iterator != portal_exits.end())
    {
        return &(iterator->second);
    }

    return nullptr;
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

int StarChart::getTrueSpaceX(int grid_position_x)
{
    int true_space_x = (grid_position_x - 120) * 10041 / 242 + 4999;

    return true_space_x;
}

int StarChart::getTrueSpaceY(int grid_position_y)
{
    int true_space_y = (113 - grid_position_y) * 10001 / 227 + 4999;

    return true_space_y;
}
