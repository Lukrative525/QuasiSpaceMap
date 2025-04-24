#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H

#include <array>

#include "image.h"

class TextManager
{
public:
    explicit TextManager();
    void setPixelImage(Image* new_pixel_image);
    void update();

private:
    void initialize();
    void placePixels();

    Image* pixel_image{nullptr};

    const std::array<int, 8> digit_grid_positions_x{194, 199, 204, 211, 226, 231, 236, 243};
    const int digit_grid_position_y{3};

    const int digit_columns{4};
    const int digit_rows{5};
    const int number_digit_pixels{160};
};

#endif // TEXTMANAGER_H
