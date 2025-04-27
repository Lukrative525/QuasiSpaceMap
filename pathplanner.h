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
    int origin_true_space_position_x;
    int origin_true_space_position_y;
    int destination_true_space_position_x;
    int destination_true_space_position_y;

signals:
    void requestPrint(QString message);
    void requestResetMap();
    void requestUpdateMap(int portal_index);

private:
    std::vector<int> portal_output_x;
    std::vector<int> portal_output_y;
    std::vector<int> portal_coodinates_x;
    std::vector<int> portal_coodinates_y;
};

#endif // PATHPLANNER_H
