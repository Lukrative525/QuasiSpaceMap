#include "starchart.h"

StarChart::StarChart() {}

float StarChart::getTrueSpaceCoordinateX(int grid_position_x)
{
    return static_cast<float>(grid_position_x);
}

float StarChart::getTrueSpaceCoordinateY(int grid_position_y)
{
    return static_cast<float>(grid_position_y);
}
