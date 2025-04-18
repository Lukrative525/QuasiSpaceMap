#include "starchart.h"
#include "starchartdata.h"

StarChart::StarChart()
{
    for (const StarInfo& info : getStarData()) {
        stars.emplace(Coordinate{info.grid_x, info.grid_y}, StarSystem{info.name, info.pos_x, info.pos_y});
    }
}

QString StarChart::getStarSystemName(Coordinate grid_position)
{
    if (stars.find(grid_position) != stars.end())
    {
        StarSystem system = stars.at(grid_position);

        return system.name();
    }

    return QString{};
}

std::pair<float, float> StarChart::getTrueSpaceCoordinates(Coordinate grid_position)
{
    std::pair<float, float> true_space_coordinates{0, 0};

    return true_space_coordinates;
}
