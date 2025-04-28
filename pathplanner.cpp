#include <QDebug>
#include <QString>

#include "pathplanner.h"
#include "pathplannerfunctions.h"

PathPlanner::PathPlanner(QObject* parent):
    QObject(parent)
{
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

int PathPlanner::argmin(const std::array<int, number_quasi_space_maps>& array)
{
    int argmin = std::distance(array.begin(), std::min_element(array.begin(), array.end()));

    return argmin;
}

std::array<int, PathPlanner::number_quasi_space_maps> PathPlanner::calculateDifferences(int value, const std::array<int, number_quasi_space_maps>& array)
{
    std::array<int, number_quasi_space_maps> difference{0};

    for (int i{0}; i < array.size(); i++)
    {
        difference[i] = value - array[i];
    }

    return difference;
}

std::array<int, PathPlanner::number_quasi_space_maps> PathPlanner::calculateHypotenuses(const std::array<int, number_quasi_space_maps>& array_1, const std::array<int, number_quasi_space_maps>& array_2)
{
    std::array<int, number_quasi_space_maps> hypotenuses{0};

    for (int i{0}; i < number_quasi_space_maps; i++)
    {
        hypotenuses[i] = ppf::calculateHypotenuse(array_1[i], array_2[i]);
    }

    return hypotenuses;
}

void PathPlanner::determineBestPath()
{
    std::array<int, number_quasi_space_maps> distances_with_portal_x = calculateDifferences(destination_true_space_position_x, portal_output_x);
    std::array<int, number_quasi_space_maps> distances_with_portal_y = calculateDifferences(destination_true_space_position_y, portal_output_y);
    std::array<int, number_quasi_space_maps> distances_with_portal = calculateHypotenuses(distances_with_portal_x, distances_with_portal_y);

    int shortest_index = argmin(distances_with_portal);

    int distance_no_portal = ppf::calculateHypotenuse((origin_true_space_position_x - destination_true_space_position_x), (origin_true_space_position_y - destination_true_space_position_y));
    int distance_with_portal = ppf::calculateHypotenuse((portal_output_x[shortest_index] - destination_true_space_position_x), (portal_output_y[shortest_index] - destination_true_space_position_y));

    int fuel_no_portal = (distance_no_portal + 5) / 10;
    int fuel_with_portal = (distance_with_portal + 5) / 10 + 100;

    int best_choice = 1 * (fuel_with_portal < fuel_no_portal);

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
