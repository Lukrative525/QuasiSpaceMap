#ifndef STARCHARTDATA_H
#define STARCHARTDATA_H

#include <array>
#include <QString>

struct StarInfo {
    QString name;
    int grid_x;
    int grid_y;
    float pos_x;
    float pos_y;
};

constexpr int star_count = 503;
const std::array<StarInfo, star_count>& getStarData();

#endif // STARCHARTDATA_H
