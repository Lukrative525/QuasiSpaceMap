#include "pathplannerfunctions.h"

namespace ppf
{
    int calculateHypotenuse(int value_1, int value_2)
    {
        int hypotenuse = sqrt(value_1 * value_1 + value_2 * value_2);

        return hypotenuse;
    }

    QString formatIntAsString(int number)
    {
        int whole_part = number / 10;
        int decimal_part = number % 10;

        QString formatted_int = QString::asprintf("%d.%d", whole_part, decimal_part);

        return formatted_int;
    }

    int sqrt(int value)
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
}
