#include "textmanager.h"

TextManager::TextManager():
    pixel_image{nullptr}
{
}

TextManager::TextManager(Image* pixel_image):
    pixel_image{pixel_image}
{
    initialize();
}

void TextManager::setPixelImage(Image* new_pixel_image)
{
    pixel_image = new_pixel_image;

    initialize();
}

void TextManager::update()
{
    updateStaticSymbols();
}

void TextManager::initialize()
{
    while (pixel_image->instances.size() < 4)
    {
        pixel_image->addInstance();
    }
}

void TextManager::updateStaticSymbols()
{
    int scale = pixel_image->instances.front().scale();
    pixel_image->instances[0].setX(209 * scale);
    pixel_image->instances[0].setY(7 * scale);
    pixel_image->instances[1].setX(220 * scale);
    pixel_image->instances[1].setY(4 * scale);
    pixel_image->instances[2].setX(220 * scale);
    pixel_image->instances[2].setY(6 * scale);
    pixel_image->instances[3].setX(241 * scale);
    pixel_image->instances[3].setY(7 * scale);
}
