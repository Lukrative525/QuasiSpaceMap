#ifndef PATHPLANNERFUNCTIONS_H
#define PATHPLANNERFUNCTIONS_H

#include <QString>
#include <vector>

namespace ppf
{
int argmin(const std::vector<int>& vector);
std::vector<int> calculateDifferenceBetween(int value, const std::vector<int>& vector);
int calculateHypotenuse(int value_1, int value_2);
std::vector<int> calculateHypotenuses(const std::vector<int>& vector_1, const std::vector<int>& vector_2);
QString formatIntAsString(int number);
}

#endif // PATHPLANNERFUNCTIONS_H
