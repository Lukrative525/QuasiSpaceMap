#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <QString>
#include <vector>

#include "imageinstance.h"

class Image
{
public:
    Image(const QString& file_path);
    Image(const QString& file_path, int reserved_instances);
    void addInstance();

    QString file_path;
    int height{0};
    QImage image_data;
    uint instance_vertex_buffer{0};
    std::vector<ImageInstance> instances;
    uint texture{0};
    uint vertex_array{0};
    int width{0};
};

#endif // IMAGE_H
