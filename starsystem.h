#ifndef STARSYSTEM_H
#define STARSYSTEM_H

#include <QString>

class StarSystem
{
public:
    StarSystem();
    StarSystem(std::string_view name, int true_space_position_x, int true_space_position_y);
    std::string_view name() const;
    int true_space_position_x() const;
    int true_space_position_y() const;

private:
    std::string_view name_property;
    int true_space_position_x_property;
    int true_space_position_y_property;
};

#endif // STARSYSTEM_H
