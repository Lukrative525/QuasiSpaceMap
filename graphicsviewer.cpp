#include <QMouseEvent>
#include <QTimer>

#include "coordinate.h"
#include "graphicsviewer.h"

GraphicsViewer::GraphicsViewer(QWidget *parent):
    ImageViewer{parent}
{
    setCursor(Qt::BlankCursor);
    setMouseTracking(true);

    loadAssets();

    setAttribute(Qt::WA_NativeWindow);
}

void GraphicsViewer::showHyperSpaceMap()
{
    showMap(hyper_space_index);
}

void GraphicsViewer::showMap(int map_index)
{
    setAllMapsInvisible();
    images[map_index].instances[0].setIsActive(true);

    update();
}

void GraphicsViewer::showQuasiSpaceMap(int quasi_space_index)
{
    showMap(quasi_space_index + quasi_space_start_index);
}

void GraphicsViewer::enterEvent(QEnterEvent *event)
{
    setFocus();
    ImageViewer::enterEvent(event);
}

void GraphicsViewer::keyPressEvent(QKeyEvent* event)
{
    if (event->isAutoRepeat())
    {
        return;
    }

    if (isArrowKey(event))
    {
        handleArrowKeyPress(event);
    }
    else if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
    {
        emit mousePressed(cursor_grid_position_x, cursor_grid_position_y);
    }
    else
    {
        ImageViewer::keyPressEvent(event);
    }
}

void GraphicsViewer::keyReleaseEvent(QKeyEvent* event)
{
    if (event->isAutoRepeat())
    {
        return;
    }

    if (isArrowKey(event))
    {
        handleArrowKeyRelease(event);
    }
}

void GraphicsViewer::leaveEvent(QEvent *event)
{
    clearFocus();
    QWidget::leaveEvent(event);
}

void GraphicsViewer::mouseMoveEvent(QMouseEvent* event)
{
    QPoint mouse_position = event->pos();

    int grid_position_x = calculateGridIndex(mouse_position.x());
    int grid_position_y = calculateGridIndex(mouse_position.y());

    if (grid_position_x != cursor_grid_position_x || grid_position_y != cursor_grid_position_y)
    {
        setCosmeticCursorPosition(grid_position_x, grid_position_y);
    }
}

void GraphicsViewer::mousePressEvent(QMouseEvent* event)
{
    QPoint mouse_position = event->pos();

    int grid_index_x = calculateGridIndex(mouse_position.x());
    int grid_index_y = calculateGridIndex(mouse_position.y());
    boundGridPositionX(grid_index_x);
    boundGridPositionY(grid_index_y);

    emit mousePressed(grid_index_x, grid_index_y);
}

void GraphicsViewer::resizeGL(int new_width, int new_height)
{
    ImageViewer::resizeGL(new_width, new_height);

    height = new_height;
    width = new_width;
    updateScaleFactor();
}

void GraphicsViewer::boundGridPositionX(int& grid_position_x)
{
    if (grid_position_x < left_grid_bound)
    {
        grid_position_x = left_grid_bound;
    }
    else if (grid_position_x > right_grid_bound)
    {
        grid_position_x = right_grid_bound;
    }
}

void GraphicsViewer::boundGridPositionY(int& grid_position_y)
{
    if (grid_position_y < top_grid_bound)
    {
        grid_position_y = top_grid_bound;
    }
    else if (grid_position_y > bottom_grid_bound)
    {
        grid_position_y = bottom_grid_bound;
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

void GraphicsViewer::handleArrowKeyPress(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Up)
    {
        is_key_up_pressed = true;
        cursor_grid_position_y -= 1 * (move_delay_fuse == move_delay_fuse_start_length);
    }
    else if (event->key() == Qt::Key_Down)
    {
        is_key_down_pressed = true;
        cursor_grid_position_y += 1 * (move_delay_fuse == move_delay_fuse_start_length);
    }
    else if (event->key() == Qt::Key_Left)
    {
        is_key_left_pressed = true;
        cursor_grid_position_x -= 1 * (move_delay_fuse == move_delay_fuse_start_length);
    }
    else if (event->key() == Qt::Key_Right)
    {
        is_key_right_pressed = true;
        cursor_grid_position_x += 1 * (move_delay_fuse == move_delay_fuse_start_length);
    }

    setCosmeticCursorPosition(cursor_grid_position_x, cursor_grid_position_y);
    setRealCursorPosition(cursor_grid_position_x, cursor_grid_position_y);

    move_delay_timer->start();
}

void GraphicsViewer::handleArrowKeyRelease(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Up)
    {
        is_key_up_pressed = false;
    }
    else if (event->key() == Qt::Key_Down)
    {
        is_key_down_pressed = false;
    }
    else if (event->key() == Qt::Key_Left)
    {
        is_key_left_pressed = false;
    }
    else if (event->key() == Qt::Key_Right)
    {
        is_key_right_pressed = false;
    }

    if (!is_key_up_pressed && !is_key_down_pressed && !is_key_left_pressed && !is_key_right_pressed)
    {
        resetCursorMovement();
    }
}

bool GraphicsViewer::isArrowKey(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Up)
    {
        return true;
    }
    else if (event->key() == Qt::Key_Down)
    {
        return true;
    }
    else if (event->key() == Qt::Key_Left)
    {
        return true;
    }
    else if (event->key() == Qt::Key_Right)
    {
        return true;
    }

    return false;
}

void GraphicsViewer::loadAssets()
{
    loadHyperSpaceMap();
    loadQuasiSpaceMaps();
    loadCursor();
    addToQueuedActions([this]() {addImage(":/images/pixel.png");});

    loadTimer();
}

void GraphicsViewer::loadCursor()
{
    addToQueuedActions([this]() {cursor_index = images.size();});
    addToQueuedActions([this]() {addImage(":/images/cursor.png");});
}

void GraphicsViewer::loadHyperSpaceMap()
{
    addToQueuedActions([this]() {hyper_space_index = images.size();});
    addToQueuedActions([this]() {addImage(":/images/in-game map.png");});
}

void GraphicsViewer::loadQuasiSpaceMaps()
{
    addToQueuedActions([this]() {quasi_space_start_index = images.size();});

    QString file_name;
    file_name.reserve(64);

    for (int i{0}; i < number_quasi_space_maps; i++)
    {
        file_name = ":/images/quasi " + QString::number(i) + ".png";
        addToQueuedActions([this, file_name]() {addImage(file_name);});
        addToQueuedActions([this]() {images.back().instances[0].setIsActive(false);});
    }
}

void GraphicsViewer::loadTimer()
{
    move_delay_timer = new QTimer();
    resetCursorMovement();
    connect(move_delay_timer, &QTimer::timeout, this, &GraphicsViewer::onTimer);
}

void GraphicsViewer::onTimer()
{
    if (move_delay_fuse > -4)
    {
        move_delay_fuse -= 1;
    }

    if (move_delay_length == 0 || move_delay_fuse % move_delay_length == 0)
    {
        cursor_grid_position_x += move_speed * (is_key_right_pressed - is_key_left_pressed);
        cursor_grid_position_y += move_speed * (is_key_down_pressed - is_key_up_pressed);
        setCosmeticCursorPosition(cursor_grid_position_x, cursor_grid_position_y);
        setRealCursorPosition(cursor_grid_position_x, cursor_grid_position_y);
    }

    if (move_delay_fuse == 0)
    {
        move_delay_length -= 1;
        move_delay_fuse = move_delay_length * 4;
    }
    else if (move_delay_fuse == -4)
    {
        move_speed = 2;
    }
}

void GraphicsViewer::resetCursorMovement()
{
    move_delay_timer->stop();
    move_delay_timer->setInterval(32);
    move_delay_length = 3;
    move_delay_fuse_start_length = 12;
    move_delay_fuse = move_delay_fuse_start_length;
    move_speed = 1;
}

void GraphicsViewer::setAllMapsInvisible()
{
    images[hyper_space_index].instances[0].setIsActive(false);
    for (int index{quasi_space_start_index}; index < quasi_space_start_index + number_quasi_space_maps; index++)
    {
        images[index].instances[0].setIsActive(false);
    }
}

void GraphicsViewer::setCosmeticCursorPosition(int grid_position_x, int grid_position_y)
{
    boundGridPositionX(grid_position_x);
    boundGridPositionY(grid_position_y);

    if (images[hyper_space_index].instances[0].is_active())
    {
        QString star_system_name = starchart.getStarSystemName(Coordinate(grid_position_x, grid_position_y));
        if (!star_system_name.isEmpty())
        {
            qDebug() << star_system_name;
        }
    }

    cursor_grid_position_x = grid_position_x;
    cursor_grid_position_y = grid_position_y;
    int pixel_coordinate_x = calculatePixelCoordinate(grid_position_x);
    int pixel_coordinate_y = calculatePixelCoordinate(grid_position_y);

    images[cursor_index].instances[0].setX(pixel_coordinate_x - (cursor_center_offset * scale_factor));
    images[cursor_index].instances[0].setY(pixel_coordinate_y - (cursor_center_offset * scale_factor));

    update();
}

void GraphicsViewer::setRealCursorPosition(int grid_position_x, int grid_position_y)
{
    if (this->hasFocus())
    {
        boundGridPositionX(grid_position_x);
        boundGridPositionY(grid_position_y);
        cursor_grid_position_x = grid_position_x;
        cursor_grid_position_y = grid_position_y;
        QPoint scene_position(calculatePixelCoordinate(cursor_grid_position_x), calculatePixelCoordinate(cursor_grid_position_y));
        QPoint global_position = mapToGlobal(scene_position);
        QCursor::setPos(global_position);
    }
}

void GraphicsViewer::updateScaleFactor()
{
    if (images.size() < 1)
    {
        return;
    }

    int new_scale_factor = std::max(1, static_cast<int>(std::floor(height / images[hyper_space_index].instances[0].size_y_base())));

    if (scale_factor != new_scale_factor)
    {
        scale_factor = new_scale_factor;

        for (Image& image: images)
        {
            for (ImageInstance& instance : image.instances)
            {
                instance.setScale(scale_factor);
            }
        }

        setCosmeticCursorPosition(cursor_grid_position_x, cursor_grid_position_y);

        updateGeometry();
    }
}
