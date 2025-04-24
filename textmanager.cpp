#include <cmath>

#include "textmanager.h"
#include "textmanagerdata.h"

TextManager::TextManager() {}

void TextManager::setPixelImage(Image* new_pixel_image)
{
    pixel_image = new_pixel_image;

    initialize();
}

void TextManager::update()
{
    placePixels();
    drawDigit(0, 0);
    drawDigit(1, 1);
    drawDigit(2, 2);
    drawDigit(3, 3);
    drawDigit(4, 4);
    drawDigit(5, 5);
    drawDigit(6, 8);
    drawDigit(7, 9);
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

void TextManager::drawDigit(int location, int digit)
{
    int pixel_start_index{location * digit_columns * digit_rows};
    int pixel_end_index{pixel_start_index + digit_columns * digit_rows};
    for (int i{pixel_start_index}; i < pixel_end_index; i++)
    {
        pixel_image->instances[i].setIsActive(digits[digit][i - pixel_start_index]);
    }
}
