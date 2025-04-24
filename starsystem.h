#ifndef STARSYSTEM_H
#define STARSYSTEM_H

#include <QString>

class StarSystem
{
public:
    StarSystem();
    StarSystem(std::string_view name, float true_space_position_x, float true_space_position_y);
    std::string_view name() const;
    float true_space_position_x() const;
    float true_space_position_y() const;

private:
    std::string_view name_property;
    float true_space_position_x_property;
    float true_space_position_y_property;
};

#endif // STARSYSTEM_H
