#include <cmath>

#include "textmanager.h"
#include "textmanagerdata.h"

TextManager::TextManager() {}

void TextManager::setPixelImage(Image* new_pixel_image)
{
    pixel_image = new_pixel_image;

    initialize();
}

void TextManager::refreshScale()
{
    placePixels();
}

void TextManager::updateCoordinates(int x, int y)
{
    Digits x_digits = extractDigits(x);
    Digits y_digits = extractDigits(y);
    drawDigit(0, x_digits.hundreds);
    drawDigit(1, x_digits.tens);
    drawDigit(2, x_digits.ones);
    drawDigit(3, x_digits.tenths);
    drawDigit(4, y_digits.hundreds);
    drawDigit(5, y_digits.tens);
    drawDigit(6, y_digits.ones);
    drawDigit(7, y_digits.tenths);
}

void TextManager::drawDigit(int location, int digit)
{
    int pixel_start_index{location * digit_columns * digit_rows};
    int pixel_end_index{pixel_start_index + digit_columns * digit_rows};
    for (int i{pixel_start_index}; i < pixel_end_index; i++)
    {
        pixel_image->instances[i].setIsActive(digits[digit][i - pixel_start_index]);
    }
}

Digits TextManager::extractDigits(int value)
{
    if (value < 0)
    {
        return {0, 0, 0, 0};
    }
    else if (value > 9999)
    {
        return {9, 9, 9, 9};
    }

    int hundreds = value / 1000;
    int tens = (value / 100) % 10;
    int ones = (value / 10) % 10;
    int tenths = value % 10;

    return {hundreds, tens, ones, tenths};
}

void TextManager::initialize()
{
    while (pixel_image->instances.size() < digit_pixels)
    {
        pixel_image->addInstance();
        pixel_image->instances.back().setIsActive(false);
    }
}

void TextManager::placePixels()
{
    int scale = static_cast<int>(pixel_image->instances.front().scale());
    for (int i{0}; i < pixel_image->instances.size(); i++)
    {
        pixel_image->instances[i].setX(scale * (digit_grid_positions_x[static_cast<int>(std::floor(i / (digit_columns * digit_rows)))] + i % digit_columns));
        pixel_image->instances[i].setY(scale * (digit_grid_position_y + static_cast<int>(std::floor((i % (digit_columns * digit_rows)) / digit_columns))));
    }
}


