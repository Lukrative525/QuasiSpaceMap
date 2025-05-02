#ifndef PATHPLANNERFUNCTIONS_H
#define PATHPLANNERFUNCTIONS_H

#include <string>

struct Digits
{
    int hundreds;
    int tens;
    int ones;
    int tenths;
};

namespace ppf
{
    int calculateHypotenuse(int value_1, int value_2);
    Digits extractDigits(int value);
    std::string formatDigits(Digits digits);
    std::string formatDigitsNoLeadingZeros(Digits digits);
    int sqrt(int value);
}

#endif // PATHPLANNERFUNCTIONS_H
