#ifndef STARSYSTEM_H
#define STARSYSTEM_H

#include <QString>

class StarSystem
{
public:
    StarSystem();
    StarSystem(QString name, float true_space_position_x, float true_space_position_y);
    QString name() const;
    float true_space_position_x() const;
    float true_space_position_y() const;

private:
    QString name_property;
    float true_space_position_x_property;
    float true_space_position_y_property;
};

#endif // STARSYSTEM_H
