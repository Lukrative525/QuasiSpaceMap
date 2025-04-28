#include <cmath>

#include "textmanager.h"
#include "textmanagerdata.h"

TextManager::TextManager() {}

void TextManager::clearText()
{
    if (!isTextCleared)
    {
        for (int i{0}; i < letter_pixels; i++)
        {
            pixel_image->instances[i + digit_pixels].setIsActive(false);
        }
    }

    isTextCleared = true;
}

void TextManager::drawText(std::string_view text)
{
    int total_width{0};
    int letter_index;

    for (char character: text)
    {
        letter_index = getLetterIndex(character);
        total_width += letters[letter_index].width;
    }
    total_width += (text.length() - 1);

    int current_location{(letter_columns - total_width) / 2};

    for (char character: text)
    {
        letter_index = getLetterIndex(character);
        drawLetter(current_location, letter_index);
        current_location += letters[letter_index].width + 1;
    }

    isTextCleared = false;
}

int TextManager::getRequiredNumberPixels()
{
    return digit_pixels + letter_pixels;
}

void TextManager::refreshScale()
{
    placePixels();
}

void TextManager::setPixelImage(Image* new_pixel_image)
{
    pixel_image = new_pixel_image;

    initialize();
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

void TextManager::drawLetter(int location, int letter)
{
    int letter_width = letters[letter].width;

    int instance_index;
    int column;
    int row;

    for (int i{0}; i < letter_width * letter_rows; i++)
    {
        column = i % letter_width;
        row = static_cast<int>(std::floor(i / letter_width));
        instance_index = digit_pixels + location + column + row * letter_columns;
        pixel_image->instances[instance_index].setIsActive(letters[letter].pixels[i]);
    }
}

Digits TextManager::extractDigits(int value)
{
    int hundreds = value / 1000;
    int tens = (value / 100) % 10;
    int ones = (value / 10) % 10;
    int tenths = value % 10;

    return {hundreds, tens, ones, tenths};
}

int TextManager::getLetterIndex(char character)
{
    int character_index = static_cast<int>(character);

    if (character_index >= 65 && character_index < 91)
    {
        return character_index - 65;
    }
    else if (character_index >= 97 && character_index < 132)
    {
        return character_index - 71;
    }
    else
    {
        return 52;
    }
}

void TextManager::initialize()
{
    while (pixel_image->instances.size() < digit_pixels + letter_pixels)
    {
        pixel_image->addInstance();
        pixel_image->instances.back().setIsActive(false);
    }
}

void TextManager::placePixels()
{
    int scale = static_cast<int>(pixel_image->instances.front().scale());
    for (int i{0}; i < digit_pixels; i++)
    {
        pixel_image->instances[i].setX(scale * (digit_grid_positions_x[static_cast<int>(std::floor(i / (digit_columns * digit_rows)))] + i % digit_columns));
        pixel_image->instances[i].setY(scale * (digit_grid_position_y + static_cast<int>(std::floor((i % (digit_columns * digit_rows)) / digit_columns))));
    }
    for (int i{0}; i < letter_pixels; i++)
    {
        pixel_image->instances[i + digit_pixels].setX(scale * (letter_grid_position_x + i % letter_columns));
        pixel_image->instances[i + digit_pixels].setY(scale * (letter_grid_position_y + static_cast<int>(std::floor(i / letter_columns))));
    }
}


