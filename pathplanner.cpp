#include <QDebug>
#include <QString>

#include "pathplanner.h"
#include "pathplannerfunctions.h"

PathPlanner::PathPlanner(QObject* parent):
    QObject(parent),
    portal_output_x{352, 5850, 7752, 112, 9735, 50, 1910, 5673, 3184, 6117, 2302, 5658, 8607, 9211, 4091},
    portal_output_y{6320, 6213, 8906, 9409, 3153, 1647, 926, 1207, 4906, 4131, 3988, 9712, 151, 6104, 7748},
    portal_coodinates_x{544, 520, 530, 520, 488, 492, 506, 516, 502, 476, 466, 448, 458, 468, 476},
    portal_coodinates_y{532, 540, 528, 514, 538, 492, 474, 466, 460, 496, 514, 504, 492, 464, 458}
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
    int distance_with_portal_no_spawner = distance_with_portal + ppf::calculateHypotenuse((origin_true_space_position_x - 438), (origin_true_space_position_y - 6372));

    int fuel_no_portal = distance_no_portal / 10;
    int fuel_with_portal = distance_with_portal / 10 + 10;
    int fuel_with_portal_no_spawner = distance_with_portal_no_spawner / 10;

    int best_choice = ppf::argmin(std::vector<int>{fuel_no_portal, fuel_with_portal, fuel_with_portal_no_spawner});

    if (fuel_no_portal == fuel_with_portal && fuel_no_portal == fuel_with_portal_no_spawner)
    {
        emit requestUpdateMap(shortest_index);
        QString message = "Take any route for " + QString::number(fuel_no_portal, 'f', 1) + " units fuel"
            + "\nNatural portal located at (43.8, 637.2), open from 17th through 19th";
        emit requestPrint(message);
    }
    else if (best_choice == 0)
    {
        QString message = "Take the direct route for " + QString::number(fuel_no_portal, 'f', 1) + " units fuel";
        emit requestPrint(message);
    }
    else if (best_choice == 1)
    {
        emit requestUpdateMap(shortest_index);
        QString message = "Take the portal route for " + QString::number(fuel_with_portal, 'f', 1) + " units fuel";
        emit requestPrint(message);
    }
    else if (best_choice == 2)
    {
        emit requestUpdateMap(shortest_index);
        QString message = "If permissible, take the natural portal for " + QString::number(fuel_with_portal_no_spawner, 'f', 1) + " units fuel"
            + "\nOtherwise, take the portal route for " + QString::number(fuel_with_portal, 'f', 1) + " units fuel"
            + "\nNatural portal located at (43.8, 637.2), open from 17th through 19th";
        emit requestPrint(message);
    }
}

void PathPlanner::queueMousePressCoordinates(int true_space_position_x, int true_space_position_y)
{
    if (number_queued_coordinates == 0)
    {
        origin_true_space_position_x = true_space_position_x;
        origin_true_space_position_y = true_space_position_y;
        QString message = QString::number(origin_true_space_position_x, 'f', 1) + ", " + QString::number(origin_true_space_position_y, 'f', 1) + "\n\nDestination:";
        emit requestPrint(message);
        number_queued_coordinates = 1;
    }
    else if (number_queued_coordinates == 1)
    {
        destination_true_space_position_x = true_space_position_x;
        destination_true_space_position_y = true_space_position_y;
        QString message = QString::number(destination_true_space_position_x, 'f', 1) + ", " + QString::number(destination_true_space_position_y, 'f', 1) + "\n";
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
