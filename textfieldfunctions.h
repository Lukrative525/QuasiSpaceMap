#ifndef TEXTFIELDFUNCTIONS_H
#define TEXTFIELDFUNCTIONS_H

#include <string>

struct Digits
{
    int hundreds;
    int tens;
    int ones;
    int tenths;
};

namespace tff
{
    Digits extractDigits(int value);
    std::string formatDigits(Digits digits);
};

#endif // TEXTFIELDFUNCTIONS_H
