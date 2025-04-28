#ifndef TEXTMANAGER_H
#define TEXTMANAGER_H

#include <array>

#include "image.h"

struct Digits
{
    int hundreds;
    int tens;
    int ones;
    int tenths;
};

class TextManager
{
public:
    explicit TextManager();
    void clearText();
    void drawText(std::string_view text);
    void refreshScale();
    void setPixelImage(Image* new_pixel_image);
    void updateCoordinates(int x, int y);

private:
    void drawDigit(int location, int digit);
    void drawLetter(int location, int letter);
    Digits extractDigits(int value);
    int getLetterIndex(char character);
    void initialize();
    void placePixels();

    bool isTextCleared{true};

    Image* pixel_image{nullptr};

    static constexpr int number_digits{8};

    static constexpr std::array<int, number_digits> digit_grid_positions_x{194, 199, 204, 211, 226, 231, 236, 243};
    static constexpr int digit_grid_position_y{3};

    static constexpr int digit_columns{4};
    static constexpr int digit_rows{5};
    static constexpr int digit_pixels = number_digits * digit_columns * digit_rows;

    static constexpr int letter_grid_position_x{8};
    static constexpr int letter_grid_position_y{1};

    static constexpr int letter_columns{171};
    static constexpr int letter_rows{8};

    static constexpr int letter_pixels = letter_columns * letter_rows;
};

#endif // TEXTMANAGER_H
