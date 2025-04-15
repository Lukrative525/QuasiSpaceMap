#include <QDebug>
#include <QString>

#include "pathplanner.h"
#include "pathplannerfunctions.h"

PathPlanner::PathPlanner(QObject* parent)
    : QObject(parent)
    , portal_output_x{35.2, 585, 775.2, 11.2, 973.5, 5, 191, 567.3, 318.4, 611.7, 230.2, 565.8, 860.7, 921.1, 409.1}
    , portal_output_y{632, 621.3, 890.6, 940.9, 315.3, 164.7, 92.6, 120.7, 490.6, 413.1, 398.8, 971.2, 15.1, 610.4, 774.8}
    , portal_coodinates_x{544, 520, 530, 520, 488, 492, 506, 516, 502, 476, 466, 448, 458, 468, 476}
    , portal_coodinates_y{532, 540, 528, 514, 538, 492, 474, 466, 460, 496, 514, 504, 492, 464, 458}
{
}

void PathPlanner::determineBestPath()
{
    std::vector<float> distances_with_portal_x = ppf::calculateDifferenceBetween(destination_x_game, portal_output_x);
    std::vector<float> distances_with_portal_y = ppf::calculateDifferenceBetween(destination_y_game, portal_output_y);
    std::vector<float> distances_with_portal = ppf::calculateHypotenuses(distances_with_portal_x, distances_with_portal_y);

    int shortest_index = ppf::argmin(distances_with_portal);
    std::vector<float> portal_coodinates{portal_coodinates_x[shortest_index], portal_coodinates_y[shortest_index]};

    float distance_no_portal = ppf::calculateHypotenuse((origin_x_game - destination_x_game), (origin_y_game - destination_y_game));
    float distance_with_portal = ppf::calculateHypotenuse((portal_output_x[shortest_index] - destination_x_game), (portal_output_y[shortest_index] - destination_y_game));
    float distance_with_portal_no_spawner = distance_with_portal + ppf::calculateHypotenuse((origin_x_game - 43.8), (origin_y_game - 637.2));

    float fuel_no_portal = distance_no_portal / 10.0;
    float fuel_with_portal = distance_with_portal / 10.0 + 10.0;
    float fuel_with_portal_no_spawner = distance_with_portal_no_spawner / 10.0;

    int best_choice = ppf::argmin(std::vector<float>{fuel_no_portal, fuel_with_portal, fuel_with_portal_no_spawner});

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

void PathPlanner::queueMousePressCoordinates(int grid_index_x, int grid_index_y)
{
    if (number_queued_coordinates == 0)
    {
        origin_x_grid = grid_index_x;
        origin_y_grid = grid_index_y;
        ppf::calculateGameUnitsFromGridIndicesX(origin_x_grid, origin_x_game);
        ppf::calculateGameUnitsFromGridIndicesY(origin_y_grid, origin_y_game);
        QString message = QString::number(origin_x_game, 'f', 1) + ", " + QString::number(origin_y_game, 'f', 1) + "\n\nDestination:";
        emit requestPrint(message);
        number_queued_coordinates = 1;
    }
    else if (number_queued_coordinates == 1)
    {
        destination_x_grid = grid_index_x;
        destination_y_grid = grid_index_y;
        ppf::calculateGameUnitsFromGridIndicesX(destination_x_grid, destination_x_game);
        ppf::calculateGameUnitsFromGridIndicesY(destination_y_grid, destination_y_game);
        QString message = QString::number(destination_x_game, 'f', 1) + ", " + QString::number(destination_y_game, 'f', 1) + "\n";
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
