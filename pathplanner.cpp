#include <QDebug>
#include <QString>

#include "pathplanner.h"
#include "pathplannerfunctions.h"

PathPlanner::PathPlanner(QObject* parent):
    QObject(parent),
    portal_output_x{4091, 3184, 9211, 5673, 1910, 8607, 50, 6117, 5658, 2302, 112, 7752, 368, 9735, 5850},
    portal_output_y{7748, 4906, 6104, 1207, 926, 151, 1647, 4131, 9712, 3988, 9409, 8906, 6332, 3153, 6213},
    portal_coodinates_x{476, 502, 468, 516, 506, 458, 492, 476, 448, 466, 520, 530, 544, 488, 520},
    portal_coodinates_y{458, 460, 464, 466, 474, 492, 492, 496, 504, 514, 514, 528, 532, 538, 540}
{
}

void PathPlanner::determineBestPath()
{
    std::vector<int> distances_with_portal_x = ppf::calculateDifferenceBetween(destination_true_space_position_x, portal_output_x);
    std::vector<int> distances_with_portal_y = ppf::calculateDifferenceBetween(destination_true_space_position_y, portal_output_y);
    std::vector<int> distances_with_portal = ppf::calculateHypotenuses(distances_with_portal_x, distances_with_portal_y);

    int shortest_index = ppf::argmin(distances_with_portal);
    std::vector<int> portal_coodinates{portal_coodinates_x[shortest_index], portal_coodinates_y[shortest_index]};

    int distance_no_portal = ppf::calculateHypotenuse((origin_true_space_position_x - destination_true_space_position_x), (origin_true_space_position_y - destination_true_space_position_y));
    int distance_with_portal = ppf::calculateHypotenuse((portal_output_x[shortest_index] - destination_true_space_position_x), (portal_output_y[shortest_index] - destination_true_space_position_y));

    int fuel_no_portal = (distance_no_portal + 5) / 10;
    int fuel_with_portal = (distance_with_portal + 5) / 10 + 100;

    int best_choice = ppf::argmin(std::vector<int>{fuel_no_portal, fuel_with_portal});

    if (best_choice == 0)
    {
        emit requestPrint("Direct route: " + ppf::formatIntAsString(fuel_no_portal) + " units fuel");
    }
    else if (best_choice == 1)
    {
        emit requestUpdateMap(shortest_index);
        emit requestPrint("Portal route: " + ppf::formatIntAsString(fuel_with_portal) + " units fuel");
        emit requestPrint("Direct route: " + ppf::formatIntAsString(fuel_no_portal) + " units fuel");
    }
}

void PathPlanner::queueMousePressCoordinates(int true_space_position_x, int true_space_position_y)
{
    if (number_queued_coordinates == 0)
    {
        origin_true_space_position_x = true_space_position_x;
        origin_true_space_position_y = true_space_position_y;
        QString message = ppf::formatIntAsString(origin_true_space_position_x) + ", " + ppf::formatIntAsString(origin_true_space_position_y) + "\n\nDestination:";
        emit requestPrint(message);
        number_queued_coordinates = 1;
    }
    else if (number_queued_coordinates == 1)
    {
        destination_true_space_position_x = true_space_position_x;
        destination_true_space_position_y = true_space_position_y;
        QString message = ppf::formatIntAsString(destination_true_space_position_x) + ", " + ppf::formatIntAsString(destination_true_space_position_y) + "\n";
        emit requestPrint(message);
        number_queued_coordinates = 2;

        determineBestPath();
    }
    else
    {
        emit requestResetMap();
        emit requestPrint("Origin:");
        number_queued_coordinates = 0;
    }
}
