#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H

#include "image.h"

class TextManager
{
public:
    explicit TextManager();
    explicit TextManager(Image* pixel_image);
    void setPixelImage(Image* pixel_image);
    void update();

private:
    void initialize();

    Image* pixel_image;
};

#endif // TEXTMANAGER_H
