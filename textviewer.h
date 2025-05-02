#ifndef TEXTVIEWER_H
#define TEXTVIEWER_H

#include <array>
#include <QObject>

#include "imageviewer.h"
#include "textfield.h"

class TextViewer: public ImageViewer
{
    Q_OBJECT
public:
    explicit TextViewer(QWidget* parent = nullptr);
    void clear();
    void setScale(int new_scale);

    const static int number_total_images{8};
    std::array<TextField, number_total_images> text_displays;

protected:
    void resizeGL(int new_width, int new_height) override;

private:
    Image* getTextDisplayPixelImage(int image_index);
    void loadAssets();
    void loadTextDisplays();

    int height;
    int width;

    int scale{1};
};

#endif // TEXTVIEWER_H
