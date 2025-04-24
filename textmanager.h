#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H

#include "image.h"

class TextManager
{
public:
    explicit TextManager();
    explicit TextManager(Image* pixel_image);
    void setPixelImage(Image* new_pixel_image);
    void update();

private:
    void initialize();
    void updateStaticSymbols();

    Image* pixel_image{nullptr};
};

#endif // TEXTMANAGER_H
