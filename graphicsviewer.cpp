#include <QMouseEvent>
#include <QTimer>

#include "coordinate.h"
#include "graphicsviewer.h"
#include "pathplannerfunctions.h"

GraphicsViewer::GraphicsViewer(QWidget *parent):
    ImageViewer{parent, number_total_images}
{
    setCursor(Qt::BlankCursor);
    setMouseTracking(true);

    loadAssets();

    setAttribute(Qt::WA_NativeWindow);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
}

void GraphicsViewer::showHyperSpaceMap()
{
    showMap(hyper_space_index);
    images[portals_index].instances[0].setIsActive(true);
}

void GraphicsViewer::showMap(int map_index)
{
    name_display.clearText();
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
        emit mousePressed(true_space_position_x, true_space_position_y);
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
    else
    {
        ImageViewer::keyReleaseEvent(event);
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

    grid_position_x = boundGridPositionX(grid_position_x);
    grid_position_y = boundGridPositionY(grid_position_y);

    if (grid_position_x != cursor_grid_position_x || grid_position_y != cursor_grid_position_y)
    {
        cursor_grid_position_x = grid_position_x;
        cursor_grid_position_y = grid_position_y;

        setCosmeticCursorPosition(cursor_grid_position_x, cursor_grid_position_y);
        setTrueSpacePosition(cursor_grid_position_x, cursor_grid_position_y);

        update();
    }
}

void GraphicsViewer::mousePressEvent(QMouseEvent* event)
{
    emit mousePressed(true_space_position_x, true_space_position_y);
}

void GraphicsViewer::resizeGL(int new_width, int new_height)
{
    ImageViewer::resizeGL(new_width, new_height);

    height = new_height;
    width = new_width;
    updateScale();
}

int GraphicsViewer::boundGridPositionX(int grid_position_x)
{
    if (grid_position_x < left_grid_bound)
    {
        return left_grid_bound;
    }
    else if (grid_position_x > right_grid_bound)
    {
        return right_grid_bound;
    }

    return grid_position_x;
}

int GraphicsViewer::boundGridPositionY(int grid_position_y)
{
    if (grid_position_y < top_grid_bound)
    {
        return top_grid_bound;
    }
    else if (grid_position_y > bottom_grid_bound)
    {
        return bottom_grid_bound;
    }

    return grid_position_y;
}

int GraphicsViewer::calculateGridIndex(int pixel_coordinate)
{
    int grid_position = std::floor(pixel_coordinate / scale);

    return grid_position;
}

int GraphicsViewer::calculatePixelCoordinate(int grid_position)
{
    int pixel_coordinate = grid_position * scale;

    return pixel_coordinate;
}

Image* GraphicsViewer::getCoordinateDisplayPixelImage()
{
    return &images[coordinate_display_image_index];
}

Image* GraphicsViewer::getNameDisplayPixelImage()
{
    return &images[name_display_image_index];
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

    cursor_grid_position_x = boundGridPositionX(cursor_grid_position_x);
    cursor_grid_position_y = boundGridPositionY(cursor_grid_position_y);

    setCosmeticCursorPosition(cursor_grid_position_x, cursor_grid_position_y);
    setRealCursorPosition(cursor_grid_position_x, cursor_grid_position_y);
    setTrueSpacePosition(cursor_grid_position_x, cursor_grid_position_y);

    update();

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
    loadPortals();
    loadCursor();
    loadBorder();
    loadCoordinateDisplay();
    loadNameDisplay();

    loadTimer();
}

void GraphicsViewer::loadBorder()
{
    border_index = images.size();
    addImage(":/images/border.png", 1);
}

void GraphicsViewer::loadCoordinateDisplay()
{
    int coordinate_display_field_width{53};

    coordinate_display.setIsTextCentered(false);
    coordinate_display.setFieldPosition(194, 1);
    coordinate_display.setFieldWidth(coordinate_display_field_width);

    coordinate_display_image_index = images.size();
    addImage(":/images/purple pixel.png", coordinate_display.field_height * coordinate_display_field_width);
    coordinate_display.setPixelImage(getCoordinateDisplayPixelImage());
}

void GraphicsViewer::loadCursor()
{
    cursor_index = images.size();
    addImage(":/images/cursor.png", 1);
}

void GraphicsViewer::loadHyperSpaceMap()
{
    hyper_space_index = images.size();
    addImage(":/images/in-game map.png", 1);
}

void GraphicsViewer::loadNameDisplay()
{
    int name_display_field_width{171};

    name_display.setIsTextCentered(true);
    name_display.setFieldPosition(8, 1);
    name_display.setFieldWidth(name_display_field_width);

    name_display_image_index = images.size();
    addImage(":/images/purple pixel.png", name_display.field_height * name_display_field_width);
    name_display.setPixelImage(getNameDisplayPixelImage());
}

void GraphicsViewer::loadPortals()
{
    portals_index = images.size();
    addImage(":/images/portals.png", 1);
}

void GraphicsViewer::loadQuasiSpaceMaps()
{
    quasi_space_start_index = images.size();

    QString file_name;
    file_name.reserve(64);

    for (int i{0}; i < number_quasi_space_maps; i++)
    {
        file_name = ":/images/quasi " + QString::number(i) + ".png";
        addImage(file_name, 1);
        images.back().instances[0].setIsActive(false);
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

        cursor_grid_position_x = boundGridPositionX(cursor_grid_position_x);
        cursor_grid_position_y = boundGridPositionY(cursor_grid_position_y);

        setCosmeticCursorPosition(cursor_grid_position_x, cursor_grid_position_y);
        setRealCursorPosition(cursor_grid_position_x, cursor_grid_position_y);
        setTrueSpacePosition(cursor_grid_position_x, cursor_grid_position_y);

        update();
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
    images[portals_index].instances[0].setIsActive(false);
}

void GraphicsViewer::setCosmeticCursorPosition(int grid_position_x, int grid_position_y)
{
    int pixel_coordinate_x = calculatePixelCoordinate(grid_position_x);
    int pixel_coordinate_y = calculatePixelCoordinate(grid_position_y);

    images[cursor_index].instances[0].setX(pixel_coordinate_x - (cursor_center_offset * scale));
    images[cursor_index].instances[0].setY(pixel_coordinate_y - (cursor_center_offset * scale));
}

void GraphicsViewer::setRealCursorPosition(int grid_position_x, int grid_position_y)
{
    if (this->hasFocus())
    {
        QPoint scene_position(calculatePixelCoordinate(cursor_grid_position_x), calculatePixelCoordinate(cursor_grid_position_y));
        QPoint global_position = mapToGlobal(scene_position);
        QCursor::setPos(global_position);
    }
}

void GraphicsViewer::setTrueSpacePosition(int grid_position_x, int grid_position_y)
{
    coordinate_display.clearText();
    name_display.clearText();

    if (images[hyper_space_index].instances[0].is_active())
    {
        const StarSystem* star_system = star_chart.getStarSystem(Coordinate(grid_position_x, grid_position_y));
        const StarSystem* portal_exit = star_chart.getPortalExit(Coordinate(grid_position_x, grid_position_y));
        if (star_system != nullptr)
        {
            true_space_position_x = star_system->true_space_position_x();
            true_space_position_y = star_system->true_space_position_y();
            name_display.drawText(star_system->name());
        }
        else if (portal_exit != nullptr)
        {
            true_space_position_x = portal_exit->true_space_position_x();
            true_space_position_y = portal_exit->true_space_position_y();
            name_display.drawText(portal_exit->name());
        }
        else
        {
            true_space_position_x = star_chart.getTrueSpaceX(grid_position_x - left_grid_bound);
            true_space_position_y = star_chart.getTrueSpaceY(grid_position_y - top_grid_bound);
        }
    }
    else
    {
        const StarSystem* portal_entrance = star_chart.getPortalEntrance(Coordinate(grid_position_x, grid_position_y));
        if (portal_entrance != nullptr)
        {
            true_space_position_x = portal_entrance->true_space_position_x();
            true_space_position_y = portal_entrance->true_space_position_y();
            name_display.drawText(portal_entrance->name());
        }
        else
        {
            true_space_position_x = star_chart.getTrueSpaceX(grid_position_x - left_grid_bound);
            true_space_position_y = star_chart.getTrueSpaceY(grid_position_y - top_grid_bound);
        }
    }

    Digits true_space_digits_x = ppf::extractDigits(true_space_position_x);
    Digits true_space_digits_y = ppf::extractDigits(true_space_position_y);

    coordinate_display.drawText(ppf::formatDigits(true_space_digits_x) + " : " + ppf::formatDigits(true_space_digits_y));
}

void GraphicsViewer::updateScale()
{
    if (images.size() < 1)
    {
        return;
    }

    int new_scale = std::max(1, static_cast<int>(std::floor(height / images[hyper_space_index].instances[0].size_y_base())));

    if (scale != new_scale)
    {
        scale = new_scale;

        for (Image& image: images)
        {
            for (ImageInstance& instance : image.instances)
            {
                instance.setScale(scale);
            }
        }

        coordinate_display.refreshScale();
        name_display.refreshScale();

        setCosmeticCursorPosition(cursor_grid_position_x, cursor_grid_position_y);
        setRealCursorPosition(cursor_grid_position_x, cursor_grid_position_y);
        setTrueSpacePosition(cursor_grid_position_x, cursor_grid_position_y);

        emit scaleChanged(scale);

        updateGeometry();
    }
}
