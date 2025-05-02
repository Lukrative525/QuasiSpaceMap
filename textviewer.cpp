#include "textviewer.h"

TextViewer::TextViewer(QWidget *parent):
    ImageViewer{parent, number_total_images}
{
    loadAssets();

    setAttribute(Qt::WA_NativeWindow);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
}

void TextViewer::clear()
{
    text_displays[1].clearText();
    text_displays[4].clearText();
    text_displays[6].clearText();
    text_displays[7].clearText();

    update();
}

void TextViewer::setScale(int new_scale)
{
    if (images.size() < 1)
    {
        return;
    }

    if (scale != new_scale)
    {
        scale = new_scale;

        for (Image& image: images)
        {
            for (ImageInstance& instance : image.instances)
            {
                instance.setScale(scale);
            }
        }

        for (TextField& text_display : text_displays)
        {
            text_display.refreshScale();
        }

        updateGeometry();
    }
}

void TextViewer::resizeGL(int new_width, int new_height)
{
    ImageViewer::resizeGL(new_width, new_height);

    height = new_height;
    width = new_width;
}

Image* TextViewer::getTextDisplayPixelImage(int image_index)
{
    return &images[image_index];
}

void TextViewer::loadAssets()
{
    loadTextDisplays();
}

void TextViewer::loadTextDisplays()
{
    int text_display_field_width{127};

    for (int i{0}; i < number_total_images; i++)
    {
        text_displays[i].setIsTextCentered(false);
        text_displays[i].setFieldPosition(5, 1 + 10 * i);
        text_displays[i].setFieldWidth(text_display_field_width);

        addImage(":/images/white pixel.png", TextField::field_height * text_display_field_width);
        text_displays[i].setPixelImage(getTextDisplayPixelImage(i));
    }
}
