#include <cmath>

#include "textmanager.h"

TextManager::TextManager() {}

void TextManager::setPixelImage(Image* new_pixel_image)
{
    pixel_image = new_pixel_image;

    initialize();
}

void TextManager::update()
{
    placePixels();
    for (int i{0}; i < pixel_image->instances.size(); i++)
    {
        pixel_image->instances[i].setIsActive(true);
    }
}

void TextManager::initialize()
{
    while (pixel_image->instances.size() < number_digit_pixels)
    {
        pixel_image->addInstance();
    }
}

void TextManager::placePixels()
{
    int scale = static_cast<int>(pixel_image->instances.front().scale());
    for (int i{0}; i < pixel_image->instances.size(); i++)
    {
        pixel_image->instances[i].setY(scale * (digit_grid_position_y + i % digit_rows));
        pixel_image->instances[i].setX(scale * (digit_grid_positions_x[static_cast<int>(std::floor(i / (digit_columns * digit_rows)))] + i % digit_columns));
    }
}
