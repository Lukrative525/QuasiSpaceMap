#include <cmath>
#include <QDebug>

#include "imageinstance.h"
#include "textfield.h"
#include "textfielddata.h"

TextField::TextField() {}

void TextField::clearText()
{
    if (is_text_cleared)
    {
        return;
    }

    for (ImageInstance& instance : pixel_image->instances)
    {
        instance.setIsActive(false);
    }

    is_text_cleared = true;
}

void TextField::drawText(std::string_view text)
{
    if (!is_text_cleared)
    {
        return;
    }

    int total_width{0};
    int character_index;

    for (char character: text)
    {
        character_index = getCharacterIndex(character);
        total_width += characters[character_index].width;
    }
    total_width += (text.length() - 1);

    int cursor_location;
    if (is_text_centered)
    {
        cursor_location = (field_width - total_width) / 2;
    }
    else
    {
        cursor_location = 0;
    }

    for (char character: text)
    {
        character_index = getCharacterIndex(character);
        drawCharacter(cursor_location, character_index);
        cursor_location += characters[character_index].width + 1;
    }

    is_text_cleared = false;
}

void TextField::refreshScale()
{
    placePixels();
}

void TextField::setIsTextCentered(bool new_is_text_centered)
{
    is_text_centered = new_is_text_centered;
}

void TextField::setFieldPosition(int new_field_position_x, int new_field_position_y)
{
    field_position_x = new_field_position_x;
    field_position_y = new_field_position_y;
}

void TextField::setFieldWidth(int new_field_width)
{
    field_width = new_field_width;
}

void TextField::setPixelImage(Image* new_pixel_image)
{
    pixel_image = new_pixel_image;

    while (pixel_image->instances.size() < field_width * field_height)
    {
        pixel_image->addInstance();
    }

    for (ImageInstance& instance : pixel_image->instances)
    {
        instance.setIsActive(false);
    }

    is_pixel_image_set = true;
}

void TextField::drawCharacter(int location, int character)
{
    if (!is_pixel_image_set)
    {
        return;
    }

    int character_width = characters[character].width;

    int instance_index;
    int column;
    int row;

    for (int i{0}; i < character_width * field_height; i++)
    {
        column = i % character_width;
        row = static_cast<int>(std::floor(i / character_width));
        instance_index = location + column + row * field_width;
        pixel_image->instances[instance_index].setIsActive(characters[character].pixels[i]);
    }
}

int TextField::getCharacterIndex(char character)
{
    int character_index = static_cast<int>(character);

    return character_index - 32;
}

void TextField::placePixels()
{
    if (!is_pixel_image_set)
    {
        return;
    }

    int scale = static_cast<int>(pixel_image->instances.front().scale());

    for (int i{0}; i < pixel_image->instances.size(); i++)
    {
        pixel_image->instances[i].setX(scale * (field_position_x + i % field_width));
        pixel_image->instances[i].setY(scale * (field_position_y + static_cast<int>(std::floor(i / field_width))));
    }
}
