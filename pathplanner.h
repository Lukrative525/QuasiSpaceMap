#ifndef PATHPLANNER_H
#define PATHPLANNER_H

#include <vector>
#include <QObject>
#include <QPointF>

class PathPlanner : public QObject
{
    Q_OBJECT
public:
    PathPlanner(QObject* parent = nullptr);
    void determineBestPath();
    void queueMousePressCoordinates(int grid_index_x, int grid_index_y);
    const static int number_quasi_space_maps{15};
    int number_queued_coordinates{0};
    int origin_x_grid;
    int origin_y_grid;
    int destination_x_grid;
    int destination_y_grid;
    float origin_x_game;
    float origin_y_game;
    float destination_x_game;
    float destination_y_game;

signals:
    void requestPrint(QString message);
    void requestResetMap();
    void requestUpdateMap(int portal_index);

private:
    std::vector<float> portal_output_x;
    std::vector<float> portal_output_y;
    std::vector<float> portal_coodinates_x;
    std::vector<float> portal_coodinates_y;
};

#endif // PATHPLANNER_H
