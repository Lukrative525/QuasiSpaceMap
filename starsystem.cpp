#include "starsystem.h"

StarSystem::StarSystem():
    name_property{""},
    true_space_position_x_property{0},
    true_space_position_y_property{0}
{
}

StarSystem::StarSystem(std::string_view name, int true_space_position_x, int true_space_position_y):
    name_property{name},
    true_space_position_x_property{true_space_position_x},
    true_space_position_y_property{true_space_position_y}
{
}

std::string_view StarSystem::name() const
{
    return name_property;
}

int StarSystem::true_space_position_x() const
{
    return true_space_position_x_property;
}

int StarSystem::true_space_position_y() const
{
    return true_space_position_y_property;
}
