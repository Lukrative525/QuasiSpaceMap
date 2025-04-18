#include <functional>

#include "coordinate.h"

Coordinate::Coordinate(int grid_position_x, int grid_position_y):
    grid_position_x{grid_position_x},
    grid_position_y{grid_position_y}
{
}

int Coordinate::x() const
{
    return grid_position_x;
}

int Coordinate::y() const
{
    return grid_position_y;
}

std::size_t Coordinate::getHash() const
{
    std::size_t x_hash = std::hash<int>()(grid_position_x);
    std::size_t y_hash = std::hash<int>()(grid_position_y);

    return x_hash ^ (y_hash << 1);
}

bool Coordinate::operator==(const Coordinate& other) const
{
    return grid_position_x == other.grid_position_x && grid_position_y == other.grid_position_y;
}
