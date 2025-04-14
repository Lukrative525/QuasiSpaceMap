// #ifndef GRAPHICSVIEWER_H
// #define GRAPHICSVIEWER_H

// #include <QGraphicsPixmapItem>
// #include <QGraphicsView>
// #include <QMainWindow>
// #include <QTimer>

// class MainWindow;

// class GraphicsViewer : public QGraphicsView
// {
//     Q_OBJECT
// public:
//     GraphicsViewer(QGraphicsScene* scene, QWidget* parent = nullptr);
//     void showHyperSpaceMap();
//     void showMap(QGraphicsPixmapItem* map);
//     void showQuasiSpaceMap(int index);

// signals:
//     void mousePressed(int grid_index_x, int grid_index_y);

// protected:
//     void enterEvent(QEnterEvent* event) override;
//     void leaveEvent(QEvent* event) override;
//     void keyPressEvent(QKeyEvent* event) override;
//     void keyReleaseEvent(QKeyEvent* event) override;
//     void mouseMoveEvent(QMouseEvent* event) override;
//     void mousePressEvent(QMouseEvent* event) override;

// private:
//     void boundGridIndexX(int& grid_index_x);
//     void boundGridIndexY(int& grid_index_y);
//     int calculateGridIndex(int pixel_coordinate);
//     int calculatePixelCoordinate(int grid_index);
//     void handleArrowKeyPress(QKeyEvent* event);
//     void handleArrowKeyRelease(QKeyEvent* event);
//     bool isArrowKey(QKeyEvent* event);
//     void loadCursor();
//     void loadHyperSpaceMap();
//     void loadQuasiSpaceMaps();
//     void loadTimer();
//     void onTimer();
//     void resetCursorMovement();
//     void setAllMapsInvisible();
//     void setCosmeticCursorPosition(int grid_index_x, int grid_index_y);
//     void setRealCursorPosition(int grid_index_x, int grid_index_y);
//     void updateScaleFactor();

//     const static int cursor_center_offset{4};
//     const static int number_quasi_space_maps{15};
//     const static int map_height{240};
//     const static int left_grid_bound{7};
//     const static int right_grid_bound{248};
//     const static int top_grid_bound{10};
//     const static int bottom_grid_bound{236};
//     const static int frame_length{33};
//     int scale_factor{1};
//     bool is_key_left_pressed{false};
//     bool is_key_right_pressed{false};
//     bool is_key_up_pressed{false};
//     bool is_key_down_pressed{false};
//     int frames_arrow_key_held{0};
//     int frames_arrow_key_held_to_wait{4};
//     int arrow_key_moves_at_current_speed{0};
//     int arrow_key_increment{1};
//     int cursor_position_x{0};
//     int cursor_position_y{0};
//     QGraphicsPixmapItem* cursor;
//     QGraphicsPixmapItem* hyper_space_map;
//     std::vector<QGraphicsPixmapItem*> quasi_space_maps;
//     QTimer* timer;
// };

// #endif // GRAPHICSVIEWER_H



#ifndef GRAPHICSVIEWER_H
#define GRAPHICSVIEWER_H

#include "imageviewer.h"

class GraphicsViewer: public ImageViewer
{
    Q_OBJECT
public:
    explicit GraphicsViewer(QWidget* parent = nullptr);

protected:
    void mouseMoveEvent(QMouseEvent* event) override;
    void resizeGL(int new_width, int new_height) override;
    void runAfterInitializeGL() override;

private:
    int calculateGridIndex(int pixel_coordinate);
    void updateScaleFactor();

    int height;
    int scale_factor{1};
    int width;
};

#endif // GRAPHICSVIEWER_H
