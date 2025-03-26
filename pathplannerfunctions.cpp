#include <cmath>

#include "pathplannerfunctions.h"

namespace ppf
{
    void calculateGameUnitsFromGridIndicesX(const int& grid_index_x, float& game_units_x)
    {
        game_units_x = (grid_index_x - 7.0) * 995.8 / 240 + 2.0;
    }

    void calculateGameUnitsFromGridIndicesY(const int& grid_index_y, float& game_units_y)
    {
        game_units_y = std::roundl((236.0 - grid_index_y) * 995.6 / 226 + 2.1);
    }

    std::vector<float> calculateDifferenceBetween(const float& value, const std::vector<float>& vector)
    {
        std::vector<float> difference(vector.size(), 0.0);

        for (int i{0}; i < vector.size(); i++)
        {
            difference[i] = value - vector[i];
        }

        return difference;
    }

    float calculateHypotenuse(const float& value_1, const float& value_2)
    {
        float hypotenuse = std::sqrt(std::pow(value_1, 2) + std::pow(value_2, 2));

        return hypotenuse;
    }

    std::vector<float> calculateHypotenuses(const std::vector<float>& vector_1, const std::vector<float>& vector_2)
    {
        int smallest_size{0};
        if (vector_1.size() <= vector_2.size())
        {
            smallest_size = vector_1.size();
        }
        else
        {
            smallest_size = vector_2.size();
        }

        std::vector<float> hypotenuses(smallest_size, 0.0);

        for (int i{0}; i < smallest_size; i++)
        {
            hypotenuses[i] = calculateHypotenuse(vector_1[i], vector_2[i]);
        }

        return hypotenuses;
    }

    int argmin(std::vector<float> vector)
    {
        int argmin = std::distance(vector.begin(), std::min_element(vector.begin(), vector.end()));

        return argmin;
    }
}
