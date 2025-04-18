#ifndef COORDINATE_H
#define COORDINATE_H

#include <cstddef>

class Coordinate
{
public:
    Coordinate(int grid_position_x, int grid_position_y);
    int x() const;
    int y() const;
    std::size_t getHash() const;
    bool operator==(const Coordinate& other) const;

private:
    int grid_position_x;
    int grid_position_y;
};

#endif // COORDINATE_H
