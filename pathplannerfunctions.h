#ifndef PATHPLANNERFUNCTIONS_H
#define PATHPLANNERFUNCTIONS_H

#include <vector>

namespace ppf
{
float calculateGameUnitsFromGridIndicesX(int grid_index_x);
float calculateGameUnitsFromGridIndicesY(int grid_index_y);
std::vector<float> calculateDifferenceBetween(float value, const std::vector<float>& vector);
float calculateHypotenuse(float value_1, float value_2);
std::vector<float> calculateHypotenuses(const std::vector<float>& vector_1, const std::vector<float>& vector_2);
int argmin(const std::vector<float>& vector);
}

#endif // PATHPLANNERFUNCTIONS_H
