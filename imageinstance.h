#ifndef IMAGEINSTANCE_H
#define IMAGEINSTANCE_H

struct InstanceData
{
    float x, y, z;
    float size_x, size_y;
};

class ImageInstance
{
public:
    ImageInstance(float size_x, float size_y);
    InstanceData getData() const;
    bool is_active() const;
    float scale() const;
    void setIsActive(bool new_value);
    void setScale(float new_value);
    void setX(float new_value);
    void setY(float new_value);
    void setZ(float new_value);
    float size_x() const;
    float size_y() const;
    float size_x_base() const;
    float size_y_base() const;
    float x() const;
    float y() const;
    float z() const;

private:
    bool is_active_property{true};
    float scale_property{1};
    float size_x_base_property;
    float size_x_property{0};
    float size_y_base_property;
    float size_y_property{0};
    float x_property{0};
    float y_property{0};
    float z_property{0};
};

#endif // IMAGEINSTANCE_H
