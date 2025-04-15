// #include <cmath>
// #include <QApplication>
// #include <QMouseEvent>
// #include <QScreen>

// #include "graphicsviewer.h"

// GraphicsViewer::GraphicsViewer(QGraphicsScene* scene, QWidget* parent)
//     : QGraphicsView(scene, parent)
// {
//     setCursor(Qt::BlankCursor);
//     setMouseTracking(true);
//     setStyleSheet("QGraphicsView{border: none;}");
//     setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//     setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//     updateScaleFactor();

//     loadCursor();
//     loadHyperSpaceMap();
//     loadQuasiSpaceMaps();
//     loadTimer();

//     showHyperSpaceMap();
// }

// void GraphicsViewer::showHyperSpaceMap()
// {
//     showMap(hyper_space_map);
// }

// void GraphicsViewer::showMap(QGraphicsPixmapItem* map)
// {
//     setAllMapsInvisible();
//     map->setVisible(true);
// }

// void GraphicsViewer::showQuasiSpaceMap(int index)
// {
//     showMap(quasi_space_maps[index]);
// }

// void GraphicsViewer::enterEvent(QEnterEvent *event)
// {
//     setFocus();
//     QGraphicsView::enterEvent(event);
// }

// void GraphicsViewer::leaveEvent(QEvent *event)
// {
//     clearFocus();
//     QWidget::leaveEvent(event);
// }

// void GraphicsViewer::keyPressEvent(QKeyEvent* event)
// {
//     if (event->isAutoRepeat())
//     {
//         return;
//     }

//     if (isArrowKey(event))
//     {
//         handleArrowKeyPress(event);
//     }
//     else if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
//     {
//         emit mousePressed(cursor_position_x, cursor_position_y);
//     }
//     else
//     {
//         QGraphicsView::keyPressEvent(event);
//     }
// }

// void GraphicsViewer::keyReleaseEvent(QKeyEvent* event)
// {
//     if (event->isAutoRepeat())
//     {
//         return;
//     }

//     if (isArrowKey(event))
//     {
//         handleArrowKeyRelease(event);
//     }
// }

// void GraphicsViewer::mouseMoveEvent(QMouseEvent* event)
// {
//     QPointF mouse_position = mapToScene(event->pos());

//     int grid_index_x = calculateGridIndex(mouse_position.x());
//     int grid_index_y = calculateGridIndex(mouse_position.y());

//     setCosmeticCursorPosition(grid_index_x, grid_index_y);
// }

// void GraphicsViewer::mousePressEvent(QMouseEvent* event)
// {
//     QPointF mouse_position = mapToScene(event->pos());

//     int grid_index_x = calculateGridIndex(mouse_position.x());
//     int grid_index_y = calculateGridIndex(mouse_position.y());
//     boundGridIndexX(grid_index_x);
//     boundGridIndexY(grid_index_y);

//     emit mousePressed(grid_index_x, grid_index_y);
// }

// void GraphicsViewer::boundGridIndexX(int& grid_index_x)
// {
//     if (grid_index_x < left_grid_bound)
//     {
//         grid_index_x = left_grid_bound;
//     }
//     else if (grid_index_x > right_grid_bound)
//     {
//         grid_index_x = right_grid_bound;
//     }
// }

// void GraphicsViewer::boundGridIndexY(int& grid_index_y)
// {
//     if (grid_index_y < top_grid_bound)
//     {
//         grid_index_y = top_grid_bound;
//     }
//     else if (grid_index_y > bottom_grid_bound)
//     {
//         grid_index_y = bottom_grid_bound;
//     }
// }

// int GraphicsViewer::calculateGridIndex(int pixel_coordinate)
// {
//     int grid_index = std::floor(pixel_coordinate / scale_factor);

//     return grid_index;
// }

// int GraphicsViewer::calculatePixelCoordinate(int grid_index)
// {
//     int pixel_coordinate = grid_index * scale_factor;

//     return pixel_coordinate;
// }

// void GraphicsViewer::handleArrowKeyPress(QKeyEvent* event)
// {
//     if (event->key() == Qt::Key_Up)
//     {
//         is_key_up_pressed = true;
//         cursor_position_y -= 1;
//     }
//     else if (event->key() == Qt::Key_Down)
//     {
//         is_key_down_pressed = true;
//         cursor_position_y += 1;
//     }
//     else if (event->key() == Qt::Key_Left)
//     {
//         is_key_left_pressed = true;
//         cursor_position_x -= 1;
//     }
//     else if (event->key() == Qt::Key_Right)
//     {
//         is_key_right_pressed = true;
//         cursor_position_x += 1;
//     }

//     setRealCursorPosition(cursor_position_x, cursor_position_y);

//     timer->start();
// }

// void GraphicsViewer::handleArrowKeyRelease(QKeyEvent* event)
// {
//     if (event->key() == Qt::Key_Up)
//     {
//         is_key_up_pressed = false;
//     }
//     else if (event->key() == Qt::Key_Down)
//     {
//         is_key_down_pressed = false;
//     }
//     else if (event->key() == Qt::Key_Left)
//     {
//         is_key_left_pressed = false;
//     }
//     else if (event->key() == Qt::Key_Right)
//     {
//         is_key_right_pressed = false;
//     }

//     if (!is_key_up_pressed && !is_key_down_pressed && !is_key_left_pressed && !is_key_right_pressed)
//     {
//         resetCursorMovement();
//     }
// }

// bool GraphicsViewer::isArrowKey(QKeyEvent* event)
// {
//     if (event->key() == Qt::Key_Up)
//     {
//         return true;
//     }
//     else if (event->key() == Qt::Key_Down)
//     {
//         return true;
//     }
//     else if (event->key() == Qt::Key_Left)
//     {
//         return true;
//     }
//     else if (event->key() == Qt::Key_Right)
//     {
//         return true;
//     }

//     return false;
// }

// void GraphicsViewer::loadCursor()
// {
//     QPixmap cursor_pixmap(":/images/cursor.png");
//     cursor = new QGraphicsPixmapItem(cursor_pixmap);
//     cursor->setScale(scale_factor);
//     cursor->setZValue(2);
//     scene()->addItem(cursor);
// }

// void GraphicsViewer::loadHyperSpaceMap()
// {
//     QPixmap hyper_space_pixmap(":/images/in-game map.png");
//     hyper_space_map = new QGraphicsPixmapItem(hyper_space_pixmap);
//     hyper_space_map->setScale(scale_factor);
//     hyper_space_map->setZValue(0);
//     scene()->addItem(hyper_space_map);
//     setSceneRect(hyper_space_map->mapRectToScene(hyper_space_map->boundingRect()));
//     setMaximumHeight(sceneRect().height());
//     setMaximumWidth(sceneRect().width());
// }

// void GraphicsViewer::loadQuasiSpaceMaps()
// {
//     quasi_space_maps.reserve(number_quasi_space_maps);

//     QString file_name;
//     file_name.reserve(64);
//     QPixmap quasi_space_pixmap;
//     for (int i{0}; i < number_quasi_space_maps; i++)
//     {
//         file_name = ":/images/quasi " + QString::number(i) + ".png";
//         quasi_space_pixmap.load(file_name);
//         QGraphicsPixmapItem* quasi_space_map = new QGraphicsPixmapItem(quasi_space_pixmap);
//         quasi_space_map->setScale(scale_factor);
//         quasi_space_map->setZValue(1);
//         quasi_space_maps.emplace_back(quasi_space_map);
//         scene()->addItem(quasi_space_map);
//     }
// }

// void GraphicsViewer::loadTimer()
// {
//     timer = new QTimer();
//     timer->setInterval(33);
//     connect(timer, &QTimer::timeout, this, &GraphicsViewer::onTimer);
// }

// void GraphicsViewer::onTimer()
// {
//     if (frames_arrow_key_held < 36)
//     {
//         frames_arrow_key_held += 1;
//     }

//     if (frames_arrow_key_held % frames_arrow_key_held_to_wait == 0)
//     {
//         cursor_position_x += arrow_key_increment * (is_key_right_pressed - is_key_left_pressed);
//         cursor_position_y += arrow_key_increment * (is_key_down_pressed - is_key_up_pressed);
//         setCosmeticCursorPosition(cursor_position_x, cursor_position_y);
//         setRealCursorPosition(cursor_position_x, cursor_position_y);

//         if (arrow_key_moves_at_current_speed < 3)
//         {
//             arrow_key_moves_at_current_speed += 1;
//         }
//         else
//         {
//             if (frames_arrow_key_held_to_wait > 1)
//             {
//                 frames_arrow_key_held_to_wait -= 1;
//             }
//             else
//             {
//                 arrow_key_increment = 2;
//             }
//             arrow_key_moves_at_current_speed = 0;
//         }
//     }
// }

// void GraphicsViewer::resetCursorMovement()
// {
//     timer->stop();
//     frames_arrow_key_held = 0;
//     frames_arrow_key_held_to_wait = 4;
//     arrow_key_moves_at_current_speed = 0;
//     arrow_key_increment = 1;
// }

// void GraphicsViewer::setAllMapsInvisible()
// {
//     hyper_space_map->setVisible(false);
//     for (QGraphicsPixmapItem* quasi_space_map : quasi_space_maps)
//     {
//         quasi_space_map->setVisible(false);
//     }
// }

// void GraphicsViewer::setCosmeticCursorPosition(int grid_index_x, int grid_index_y)
// {
//     boundGridIndexX(grid_index_x);
//     boundGridIndexY(grid_index_y);
//     cursor_position_x = grid_index_x;
//     cursor_position_y = grid_index_y;
//     int pixel_coordinate_x = calculatePixelCoordinate(grid_index_x);
//     int pixel_coordinate_y = calculatePixelCoordinate(grid_index_y);

//     cursor->setPos(pixel_coordinate_x - (cursor_center_offset * scale_factor), pixel_coordinate_y - (cursor_center_offset * scale_factor));
// }

// void GraphicsViewer::setRealCursorPosition(int grid_index_x, int grid_index_y)
// {
//     if (this->hasFocus())
//     {
//         boundGridIndexX(grid_index_x);
//         boundGridIndexY(grid_index_y);
//         cursor_position_x = grid_index_x;
//         cursor_position_y = grid_index_y;
//         QPointF scene_position(calculatePixelCoordinate(cursor_position_x), calculatePixelCoordinate(cursor_position_y));
//         QPoint viewport_position = mapFromScene(scene_position);
//         QPoint global_position = viewport()->mapToGlobal(viewport_position);
//         QCursor::setPos(global_position);
//     }
//     else
//     {
//         is_key_up_pressed = false;
//         is_key_down_pressed = false;
//         is_key_left_pressed = false;
//         is_key_right_pressed = false;
//         resetCursorMovement();
//     }
// }

// void GraphicsViewer::updateScaleFactor()
// {
//     QScreen* screen = QApplication::primaryScreen();

//     scale_factor = std::floor(screen->geometry().height() / map_height);
// }



#include <QCursor>
#include <QMouseEvent>

#include "graphicsviewer.h"

GraphicsViewer::GraphicsViewer(QWidget *parent):
    ImageViewer{parent}
{
    setCursor(Qt::BlankCursor);
    setMouseTracking(true);

    loadAssets();
}

void GraphicsViewer::showHyperSpaceMap()
{
    showMap(0);
}

void GraphicsViewer::showMap(int image_index)
{
    setAllMapsInvisible();
    images[image_index].instances[0].setIsActive(true);

    update();
}

void GraphicsViewer::showQuasiSpaceMap(int quasi_space_index)
{
    showMap(quasi_space_index + 1);
}

void GraphicsViewer::mouseMoveEvent(QMouseEvent* event)
{
    QPoint mouse_position = event->pos();

    int grid_index_x = calculateGridIndex(mouse_position.x());
    int grid_index_y = calculateGridIndex(mouse_position.y());

    setCosmeticCursorPosition(grid_index_x, grid_index_y);
}

void GraphicsViewer::mousePressEvent(QMouseEvent* event)
{
    QPoint mouse_position = event->pos();

    int grid_index_x = calculateGridIndex(mouse_position.x());
    int grid_index_y = calculateGridIndex(mouse_position.y());
    boundGridIndexX(grid_index_x);
    boundGridIndexY(grid_index_y);

    emit mousePressed(grid_index_x, grid_index_y);
}

void GraphicsViewer::resizeGL(int new_width, int new_height)
{
    ImageViewer::resizeGL(new_width, new_height);
    height = new_height;
    width = new_width;

    updateScaleFactor();
}

void GraphicsViewer::boundGridIndexX(int& grid_index_x)
{
    if (grid_index_x < left_grid_bound)
    {
        grid_index_x = left_grid_bound;
    }
    else if (grid_index_x > right_grid_bound)
    {
        grid_index_x = right_grid_bound;
    }
}

void GraphicsViewer::boundGridIndexY(int& grid_index_y)
{
    if (grid_index_y < top_grid_bound)
    {
        grid_index_y = top_grid_bound;
    }
    else if (grid_index_y > bottom_grid_bound)
    {
        grid_index_y = bottom_grid_bound;
    }
}

int GraphicsViewer::calculateGridIndex(int pixel_coordinate)
{
    int grid_index = std::floor(pixel_coordinate / scale_factor);

    return grid_index;
}

int GraphicsViewer::calculatePixelCoordinate(int grid_index)
{
    int pixel_coordinate = grid_index * scale_factor;

    return pixel_coordinate;
}

void GraphicsViewer::loadAssets()
{
    loadHyperSpaceMap();
    loadQuasiSpaceMaps();
    loadCursor();
}

void GraphicsViewer::loadCursor()
{
    addToQueuedActions([this]() {addImage(":/images/cursor.png");});
}

void GraphicsViewer::loadHyperSpaceMap()
{
    addToQueuedActions([this]() {addImage(":/images/in-game map.png");});
}

void GraphicsViewer::loadQuasiSpaceMaps()
{
    QString file_name;
    file_name.reserve(64);

    for (int i{0}; i < number_quasi_space_maps; i++)
    {
        file_name = ":/images/quasi " + QString::number(i) + ".png";
        addToQueuedActions([this, file_name]() {addImage(file_name);});
        addToQueuedActions([this]() {images.back().instances[0].setIsActive(false);});
    }
}

void GraphicsViewer::setAllMapsInvisible()
{
    for (int index{0}; index < number_quasi_space_maps + 1; index++)
    {
        images[index].instances[0].setIsActive(false);
    }
}

void GraphicsViewer::setCosmeticCursorPosition(int grid_index_x, int grid_index_y)
{
    boundGridIndexX(grid_index_x);
    boundGridIndexY(grid_index_y);
    cursor_position_x = grid_index_x;
    cursor_position_y = grid_index_y;
    int pixel_coordinate_x = calculatePixelCoordinate(grid_index_x);
    int pixel_coordinate_y = calculatePixelCoordinate(grid_index_y);

    images.back().instances[0].setX(pixel_coordinate_x - (cursor_center_offset * scale_factor));
    images.back().instances[0].setY(pixel_coordinate_y - (cursor_center_offset * scale_factor));

    update();
}

void GraphicsViewer::updateScaleFactor()
{
    if (images.size() < 1)
    {
        return;
    }

    int new_scale_factor = std::max(1, static_cast<int>(std::floor(height / images[1].instances[0].size_y_base())));

    if (scale_factor != new_scale_factor)
    {
        scale_factor = new_scale_factor;

        for (Image& image : images)
        {
            for (ImageInstance& instance : image.instances)
            {
                instance.setScale(scale_factor);
            }
        }

        updateGeometry();
    }
}
