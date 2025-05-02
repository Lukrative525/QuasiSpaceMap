#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include "image.h"

class TextField
{
public:
    explicit TextField();
    void clearText();
    void drawText(std::string_view text);
    void refreshScale();
    void setIsTextCentered(bool new_is_text_centered);
    void setFieldPosition(int new_field_position_x, int new_field_position_y);
    void setFieldWidth(int new_field_width);
    void setPixelImage(Image* new_pixel_image);

    static constexpr int field_height{8};

private:
    void drawCharacter(int location, int character);
    int getCharacterIndex(char character);
    void placePixels();

    bool is_pixel_image_set{false};
    bool is_text_centered{false};
    bool is_text_cleared{true};

    Image* pixel_image{nullptr};

    int field_position_x{0};
    int field_position_y{0};
    int field_width{0};
};

#endif // TEXTFIELD_H
