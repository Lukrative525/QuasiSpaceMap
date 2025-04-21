#include "image.h"

Image::Image(const QString& file_path):
    Image(file_path, 1)
{
}

Image::Image(const QString& file_path, int reserved_instances):
    image_data{file_path},
    file_path{file_path}
{
    instances.reserve(reserved_instances);
    image_data = image_data.convertToFormat(QImage::Format_RGBA8888);
    height = image_data.height();
    width = image_data.width();
    addInstance();
}

void Image::addInstance()
{
    instances.emplace_back(width, height);
}
