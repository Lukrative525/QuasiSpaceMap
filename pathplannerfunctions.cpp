#include <cmath>

#include "pathplannerfunctions.h"

namespace ppf
{
    std::vector<int> calculateDifferenceBetween(int value, const std::vector<int>& vector)
    {
        std::vector<int> difference(vector.size(), 0);

        for (int i{0}; i < vector.size(); i++)
        {
            difference[i] = value - vector[i];
        }

        return difference;
    }

    int calculateHypotenuse(int value_1, int value_2)
    {
        int hypotenuse = std::sqrt(std::pow(value_1, 2) + std::pow(value_2, 2));

        return hypotenuse;
    }

    std::vector<int> calculateHypotenuses(const std::vector<int>& vector_1, const std::vector<int>& vector_2)
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

        std::vector<int> hypotenuses(smallest_size, 0.0);

        for (int i{0}; i < smallest_size; i++)
        {
            hypotenuses[i] = calculateHypotenuse(vector_1[i], vector_2[i]);
        }

        return hypotenuses;
    }

    int argmin(const std::vector<int>& vector)
    {
        int argmin = std::distance(vector.begin(), std::min_element(vector.begin(), vector.end()));

        return argmin;
    }
}
