#include "image.h"

Image::Image(QString file_path):
    image_data{file_path},
    file_path{file_path}
{
    instances.reserve(100);
    image_data = image_data.convertToFormat(QImage::Format_RGBA8888);
    height = image_data.height();
    width = image_data.width();
    addInstance();
}

void Image::addInstance()
{
    instances.emplace_back(width, height);
}
