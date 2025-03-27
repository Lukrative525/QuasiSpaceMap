#include <cmath>
#include <QMouseEvent>

#include "graphicsviewer.h"

GraphicsViewer::GraphicsViewer(QGraphicsScene* scene, QWidget* parent)
    : QGraphicsView(scene, parent)
{
    setCursor(Qt::BlankCursor);
    setMouseTracking(true);

    setStyleSheet("QGraphicsView{border: none; margin: 0px; padding: 0px; background-color: #000000;}");

    loadHyperSpaceMap();
    loadQuasiSpaceMaps();
    showHyperSpaceMap();

    loadCursors();
}

void GraphicsViewer::mouseMoveEvent(QMouseEvent* event)
{
    QPointF mouse_position = mapToScene(event->pos());

    int grid_index_x = calculateGridIndex(mouse_position.x());
    int grid_index_y = calculateGridIndex(mouse_position.y());

    setCursorPosition(grid_index_x, grid_index_y);
}

void GraphicsViewer::mousePressEvent(QMouseEvent* event)
{
    QPointF mouse_position = mapToScene(event->pos());

    int grid_index_x = calculateGridIndex(mouse_position.x());
    int grid_index_y = calculateGridIndex(mouse_position.y());
    boundGridIndexX(grid_index_x);
    boundGridIndexY(grid_index_y);;

    emit mousePressed(grid_index_x, grid_index_y);
}

void GraphicsViewer::showMap(QGraphicsPixmapItem* map)
{
    setAllMapsInvisible();
    map->setVisible(true);
}

void GraphicsViewer::showHyperSpaceMap()
{
    showMap(hyper_space_map);
}

void GraphicsViewer::showQuasiSpaceMap(int index)
{
    showMap(quasi_space_maps[index]);
}

void GraphicsViewer::loadCursors()
{
    cursors.reserve(4);

    QString file_name;
    file_name.reserve(64);
    QPixmap cursor_pixmap;
    for (int i{0}; i < 4; i++)
    {
        file_name = ":/cursors/cursor_" + QString::number(i) + ".png";
        cursor_pixmap.load(file_name);
        QGraphicsPixmapItem* cursor = new QGraphicsPixmapItem(cursor_pixmap);
        cursors.emplace_back(cursor);
        scene()->addItem(cursor);
    }
}

void GraphicsViewer::setCursorPosition(int grid_index_x, int grid_index_y)
{
    boundGridIndexX(grid_index_x);
    boundGridIndexY(grid_index_y);
    int pixel_coordinate_x = calculatePixelCoordinate(grid_index_x);
    int pixel_coordinate_y = calculatePixelCoordinate(grid_index_y);

    cursor_index = (grid_index_x % 2) * 1 + (grid_index_y % 2) * 2;
    selectCursor(cursor_index);
    cursors[cursor_index]->setPos(pixel_coordinate_x - 20, pixel_coordinate_y - 20);
}

void GraphicsViewer::selectCursor(int index)
{
    for (QGraphicsPixmapItem* cursor : cursors)
    {
        cursor->setVisible(false);
    }
    cursors[index]->setVisible(true);
}

void GraphicsViewer::loadHyperSpaceMap()
{
    QPixmap hyper_space_pixmap(":/images/in-game map.png");
    hyper_space_map = new QGraphicsPixmapItem(hyper_space_pixmap);
    scene()->addItem(hyper_space_map);
    setSceneRect(hyper_space_map->boundingRect());
}

void GraphicsViewer::loadQuasiSpaceMaps()
{
    quasi_space_maps.reserve(number_quasi_space_maps);

    QString file_name;
    file_name.reserve(64);
    QPixmap quasi_space_pixmap;
    for (int i{0}; i < number_quasi_space_maps; i++)
    {
        file_name = ":/images/quasi " + QString::number(i) + ".png";
        quasi_space_pixmap.load(file_name);
        QGraphicsPixmapItem* quasi_space_map = new QGraphicsPixmapItem(quasi_space_pixmap);
        quasi_space_maps.emplace_back(quasi_space_map);
        scene()->addItem(quasi_space_map);
    }
}

void GraphicsViewer::setAllMapsInvisible()
{
    hyper_space_map->setVisible(false);
    for (QGraphicsPixmapItem* quasi_space_map : quasi_space_maps)
    {
        quasi_space_map->setVisible(false);
    }
}

int GraphicsViewer::calculateGridIndex(int pixel_coordinate)
{
    int grid_index = 2 * (pixel_coordinate / 9) + 1 * ((pixel_coordinate % 9) > 4);

    return grid_index;
}

void GraphicsViewer::boundGridIndexX(int& grid_index_x)
{
    if (grid_index_x < 7)
    {
        grid_index_x = 7;
    }
    else if (grid_index_x > 248)
    {
        grid_index_x = 248;
    }
}

void GraphicsViewer::boundGridIndexY(int& grid_index_y)
{
    if (grid_index_y < 10)
    {
        grid_index_y = 10;
    }
    else if (grid_index_y > 236)
    {
        grid_index_y = 236;
    }
}

int GraphicsViewer::calculatePixelCoordinate(int grid_index)
{
    int pixel_coordinate = std::ceil(4.5 * grid_index) + 2;

    return pixel_coordinate;
}
