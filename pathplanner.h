#ifndef PATHPLANNER_H
#define PATHPLANNER_H

#include <QObject>
#include <QPointF>

class PathPlanner : public QObject
{
    Q_OBJECT
public:
    PathPlanner(QObject* parent = nullptr);
    void queueMousePressCoordinates(int grid_index_x, int grid_index_y);

    static constexpr int number_quasi_space_maps{15};
    int number_queued_coordinates{0};
    int origin_true_space_position_x;
    int origin_true_space_position_y;
    int destination_true_space_position_x;
    int destination_true_space_position_y;

signals:
    void requestPrint(std::string_view message, int line);
    void requestResetMap();
    void requestUpdateMap(int portal_index);

private:
    int argmin(const std::array<int, number_quasi_space_maps>& array);
    std::array<int, number_quasi_space_maps> calculateDifferences(int value, const std::array<int, number_quasi_space_maps>& array);
    std::array<int, number_quasi_space_maps> calculateHypotenuses(const std::array<int, number_quasi_space_maps>& array_1, const std::array<int, number_quasi_space_maps>& array_2);
    void determineBestPath();

    static constexpr std::array<int, number_quasi_space_maps> portal_output_x{4091, 3184, 9211, 5673, 1910, 8607, 50, 6117, 5658, 2302, 112, 7752, 368, 9735, 5850};
    static constexpr std::array<int, number_quasi_space_maps> portal_output_y{7748, 4906, 6104, 1207, 926, 151, 1647, 4131, 9712, 3988, 9409, 8906, 6332, 3153, 6213};
    static constexpr std::array<int, number_quasi_space_maps> portal_coodinates_x{476, 502, 468, 516, 506, 458, 492, 476, 448, 466, 520, 530, 544, 488, 520};
    static constexpr std::array<int, number_quasi_space_maps> portal_coodinates_y{458, 460, 464, 466, 474, 492, 492, 496, 504, 514, 514, 528, 532, 538, 540};
};

#endif // PATHPLANNER_H
