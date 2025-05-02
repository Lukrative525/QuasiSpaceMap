#include "textfieldfunctions.h"

Digits tff::extractDigits(int value)
{
    int hundreds = value / 1000;
    int tens = (value / 100) % 10;
    int ones = (value / 10) % 10;
    int tenths = value % 10;

    return {hundreds, tens, ones, tenths};
}

std::string tff::formatDigits(Digits digits)
{
    std::string formatted_digits =
        std::to_string(digits.hundreds) +
        std::to_string(digits.tens) +
        std::to_string(digits.ones) +
        "." +
        std::to_string(digits.tenths);

    return formatted_digits;
}
