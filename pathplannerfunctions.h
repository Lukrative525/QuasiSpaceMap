#ifndef PATHPLANNERFUNCTIONS_H
#define PATHPLANNERFUNCTIONS_H

#include <vector>

namespace ppf
{
void calculateGameUnitsFromGridIndicesX(const int& grid_index_x, float& game_units_x);
void calculateGameUnitsFromGridIndicesY(const int& grid_index_y, float& game_units_y);
std::vector<float> calculateDifferenceBetween(const float& value, const std::vector<float>& vector);
float calculateHypotenuse(const float& value_1, const float& value_2);
std::vector<float> calculateHypotenuses(const std::vector<float>& vector_1, const std::vector<float>& vector_2);
int argmin(std::vector<float>);
}

#endif // PATHPLANNERFUNCTIONS_H
