#include "pathplannerfunctions.h"

int ppf::calculateHypotenuse(int value_1, int value_2)
{
    int hypotenuse = sqrt(value_1 * value_1 + value_2 * value_2);

    return hypotenuse;
}

Digits ppf::extractDigits(int value)
{
    int hundreds = value / 1000;
    int tens = (value / 100) % 10;
    int ones = (value / 10) % 10;
    int tenths = value % 10;

    return {hundreds, tens, ones, tenths};
}

std::string ppf::formatDigits(Digits digits)
{
    std::string formatted_digits =
        std::to_string(digits.hundreds) +
        std::to_string(digits.tens) +
        std::to_string(digits.ones) +
        "." +
        std::to_string(digits.tenths);

    return formatted_digits;
}

std::string ppf::formatDigitsNoLeadingZeros(Digits digits)
{
    std::string formatted_digits = formatDigits(digits);

    if (digits.hundreds == 0)
    {
        formatted_digits = formatted_digits.substr(1, 4);

        if (digits.tens == 0)
        {
            formatted_digits = formatted_digits.substr(1, 3);
        }
    }

    return formatted_digits;
}

int ppf::sqrt(int value)
{
    int result = 0;
    int highest_power_of_four = 1 << 30;

    while (highest_power_of_four > value)
        highest_power_of_four >>= 2;

    while (highest_power_of_four != 0)
    {
        if (value >= result + highest_power_of_four)
        {
            value -= result + highest_power_of_four;
            result = (result >> 1) + highest_power_of_four;
        }
        else
        {
            result >>= 1;
        }

        highest_power_of_four >>= 2;
    }

    return result;
}
