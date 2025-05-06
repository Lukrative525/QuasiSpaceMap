#include "imageinstance.h"

ImageInstance::ImageInstance(float size_x, float size_y):
    size_x_base_property{size_x},
    size_y_base_property{size_y}
{
    setScale(1);
}

float ImageInstance::alpha()
{
    return alpha_property;
}

InstanceData ImageInstance::getData() const
{
    return {x_property, y_property, z_property, size_x_property, size_y_property, alpha_property};
}

bool ImageInstance::is_active() const
{
    return is_active_property;
}

float ImageInstance::scale() const
{
    return scale_property;
}

void ImageInstance::setAlpha(float new_value)
{
    alpha_property = new_value;
}

void ImageInstance::setIsActive(bool new_value)
{
    is_active_property = new_value;
}

void ImageInstance::setScale(float new_value)
{
    scale_property = new_value;
    size_x_property = size_x_base_property * new_value;
    size_y_property = size_y_base_property * new_value;
}

void ImageInstance::setX(float new_value)
{
    x_property = new_value;
}

void ImageInstance::setY(float new_value)
{
    y_property = new_value;
}

void ImageInstance::setZ(float new_value)
{
    z_property = new_value;
}

float ImageInstance::size_x() const
{
    return size_x_property;
}

float ImageInstance::size_y() const
{
    return size_y_property;
}

float ImageInstance::size_x_base() const
{
    return size_x_base_property;
}

float ImageInstance::size_y_base() const
{
    return size_y_base_property;
}

float ImageInstance::x() const
{
    return x_property;
}

float ImageInstance::y() const
{
    return y_property;
}

float ImageInstance::z() const
{
    return z_property;
}
